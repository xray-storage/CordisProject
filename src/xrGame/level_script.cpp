////////////////////////////////////////////////////////////////////////////
//	Module 		: level_script.cpp
//	Created 	: 28.06.2004
//  Modified 	: 28.06.2004
//	Author		: Dmitriy Iassenev
//	Description : Level script export
////////////////////////////////////////////////////////////////////////////

#include "pch_script.h"
#include "Level.h"
#include "Actor.h"
#include "script_game_object.h"
#include "script_game_object_impl.h"
#include "xrAICore/Navigation/PatrolPath/patrol_path_storage.h"
#include "xrServer.h"
#include "client_spawn_manager.h"
#include "xrEngine/IGame_Persistent.h"
#include "game_cl_base.h"
#include "UIGameCustom.h"
#include "ui/UIDialogWnd.h"
#include "date_time.h"
#include "ai_space.h"
#include "xrAICore/Navigation/level_graph.h"
#include "PHCommander.h"
#include "PHScriptCall.h"
#include "xrScriptEngine/script_engine.hpp"
#include "game_cl_single.h"
#include "game_sv_single.h"
#include "map_manager.h"
#include "map_spot.h"
#include "map_location.h"
#include "physics_world_scripted.h"
#include "alife_simulator.h"
#include "alife_time_manager.h"
#include "ui/UIGameTutorial.h"
#include "string_table.h"
#include "ui/UIInventoryUtilities.h"
#include "alife_object_registry.h"
#include "xrServer_Objects_ALife_Monsters.h"
#include "xrScriptEngine/ScriptExporter.hpp"
#include "HUDManager.h"
#include "raypick.h"
#include "xrCDB/xr_collide_defs.h"
#ifdef NAMESPACE_LEVEL_EXPORTS
#include "xrNetServer/NET_Messages.h"
#endif
using namespace luabind;
using namespace luabind::policy;

LPCSTR command_line() { return Core.Params; }
bool IsDynamicMusic() { return !!psActorFlags.test(AF_DYNAMIC_MUSIC); }
#ifdef DEBUG
void check_object(CScriptGameObject* object)
{
    try
    {
        Msg("check_object %s", object->Name());
    }
    catch (...)
    {
        object = object;
    }
}

CScriptGameObject* tpfGetActor()
{
    static bool first_time = true;
    if (first_time)
        GEnv.ScriptEngine->script_log(LuaMessageType::Error, "Do not use level.actor function!");
    first_time = false;

    CActor* l_tpActor = smart_cast<CActor*>(Level().CurrentEntity());
    if (l_tpActor)
        return (smart_cast<CGameObject*>(l_tpActor)->lua_game_object());
    else
        return (0);
}

CScriptGameObject* get_object_by_name(LPCSTR caObjectName)
{
    static bool first_time = true;
    if (first_time)
        GEnv.ScriptEngine->script_log(LuaMessageType::Error, "Do not use level.object function!");
    first_time = false;

    CGameObject* l_tpGameObject = smart_cast<CGameObject*>(Level().Objects.FindObjectByName(caObjectName));
    if (l_tpGameObject)
        return (l_tpGameObject->lua_game_object());
    else
        return (0);
}
#endif








void set_game_difficulty(ESingleGameDifficulty dif)
{
    g_SingleGameDifficulty = dif;
    game_cl_Single* game = smart_cast<game_cl_Single*>(Level().game);
    VERIFY(game);
    game->OnDifficultyChanged();
}

float high_cover_in_direction(u32 level_vertex_id, const Fvector& direction)
{
    float y, p;
    direction.getHP(y, p);
    return (ai().level_graph().high_cover_in_direction(y, level_vertex_id));
}

float low_cover_in_direction(u32 level_vertex_id, const Fvector& direction)
{
    float y, p;
    direction.getHP(y, p);
    return (ai().level_graph().low_cover_in_direction(y, level_vertex_id));
}














void prefetch_sound(LPCSTR name) { Level().PrefetchSound(name); }
CClientSpawnManager& get_client_spawn_manager() { return (Level().client_spawn_manager()); }

void start_stop_menu(CUIDialogWnd* pDialog, bool bDoHideIndicators)
{
    if (pDialog->IsShown())
        pDialog->HideDialog();
    else
        pDialog->ShowDialog(bDoHideIndicators);
}

void add_dialog_to_render(CUIDialogWnd* pDialog) { CurrentGameUI()->AddDialogToRender(pDialog); }
void remove_dialog_to_render(CUIDialogWnd* pDialog) { CurrentGameUI()->RemoveDialogToRender(pDialog); }

CUIDialogWnd* main_input_receiver()
{
    return HUD().GetGameUI()->TopInputReceiver();
}

void hide_indicators()
{
    if (CurrentGameUI())
    {
        CurrentGameUI()->HideShownDialogs();
        CurrentGameUI()->ShowGameIndicators(false);
        CurrentGameUI()->ShowCrosshair(false);
    }
    psActorFlags.set(AF_GODMODE_RT, TRUE);
}

/*
void add_call(const luabind::functor<bool>& condition, const luabind::functor<void>& action)
{
    luabind::functor<bool> _condition = condition;
    luabind::functor<void> _action = action;
    CPHScriptCondition* c = new CPHScriptCondition(_condition);
    CPHScriptAction* a = new CPHScriptAction(_action);
    Level().ph_commander_scripts().add_call(c, a);
}

void remove_call(const luabind::functor<bool>& condition, const luabind::functor<void>& action)
{
    CPHScriptCondition c(condition);
    CPHScriptAction a(action);
    Level().ph_commander_scripts().remove_call(&c, &a);
}*/

/*
void add_call(const luabind::object& lua_object, LPCSTR condition, LPCSTR action)
{
    luabind::functor<bool> _condition = object_cast<luabind::functor<bool>>(lua_object[condition]);
    luabind::functor<void> _action = object_cast<luabind::functor<void>>(lua_object[action]);
    CPHScriptObjectConditionN* c = new CPHScriptObjectConditionN(lua_object, _condition);
    CPHScriptObjectActionN* a = new CPHScriptObjectActionN(lua_object, _action);
    Level().ph_commander_scripts().add_call_unique(c, c, a, a);
}

void remove_call(const luabind::object& lua_object, LPCSTR condition, LPCSTR action)
{
    CPHScriptObjectCondition c(lua_object, condition);
    CPHScriptObjectAction a(lua_object, action);
    Level().ph_commander_scripts().remove_call(&c, &a);
}

void add_call(
    const luabind::object& lua_object, const luabind::functor<bool>& condition, const luabind::functor<void>& action)
{
    CPHScriptObjectConditionN* c = new CPHScriptObjectConditionN(lua_object, condition);
    CPHScriptObjectActionN* a = new CPHScriptObjectActionN(lua_object, action);
    Level().ph_commander_scripts().add_call(c, a);
}

void remove_call(
    const luabind::object& lua_object, const luabind::functor<bool>& condition, const luabind::functor<void>& action)
{
    CPHScriptObjectConditionN c(lua_object, condition);
    CPHScriptObjectActionN a(lua_object, action);
    Level().ph_commander_scripts().remove_call(&c, &a);
}*/

void remove_calls_for_object(const luabind::object& lua_object)
{
    CPHSriptReqObjComparer c(lua_object);
    Level().ph_commander_scripts().remove_calls(&c);
}

cphysics_world_scripted* physics_world_scripted()
{
    return get_script_wrapper<cphysics_world_scripted>(*physics_world());
}
CEnvironment* environment() { return (g_pGamePersistent->pEnvironment); }
CEnvDescriptor* current_environment(CEnvironment* self) { return (self->CurrentEnv); }



Fbox get_bounding_volume() { return Level().ObjectSpace.GetBoundingVolume(); }
void iterate_sounds(LPCSTR prefix, u32 max_count, const CScriptCallbackEx<void>& callback)
{
    for (int j = 0, N = _GetItemCount(prefix); j < N; ++j)
    {
        string_path fn, s;
        LPSTR S = (LPSTR)&s;
        _GetItem(prefix, j, s);
        // Lord - [Script] Re-write
//         if (FS.exist(fn, "$game_sounds$", S, ".ogg"))
//             callback(prefix);

        for (u32 i = 0; i < max_count; ++i)
        {
            string_path name;
            xr_sprintf(name, "%s%d", S, i);
            // Lord - [Script] Re-write
//             if (FS.exist(fn, "$game_sounds$", name, ".ogg"))
//                 callback(name);
        }
    }
}

void iterate_sounds1(LPCSTR prefix, u32 max_count, luabind::functor<void> functor)
{
    // Lord - [Script] Re-write?
//     CScriptCallbackEx<void> temp;
//     temp.set(functor);
//     iterate_sounds(prefix, max_count, temp);
}

void iterate_sounds2(LPCSTR prefix, u32 max_count, luabind::object object, luabind::functor<void> functor)
{
    // Lord - [Script] Re-write?
//     CScriptCallbackEx<void> temp;
//     temp.set(functor, object);
//     iterate_sounds(prefix, max_count, temp);
}

#include "ActorEffector.h"



#include "actor_statistic_mgr.h"
void add_actor_points(LPCSTR sect, LPCSTR detail_key, int cnt, int pts)
{
    return Actor()->StatisticMgr().AddPoints(sect, detail_key, cnt, pts);
}

void add_actor_points_str(LPCSTR sect, LPCSTR detail_key, LPCSTR str_value)
{
    return Actor()->StatisticMgr().AddPoints(sect, detail_key, str_value);
}

int get_actor_points(LPCSTR sect) { return Actor()->StatisticMgr().GetSectionPoints(sect); }
#include "ActorEffector.h"
#include "PostprocessAnimator.h"





#include "relation_registry.h"

int g_community_goodwill(LPCSTR _community, int _entity_id)
{
    CHARACTER_COMMUNITY c;
    c.set(_community);

    return RELATION_REGISTRY().GetCommunityGoodwill(c.index(), u16(_entity_id));
}

void g_set_community_goodwill(LPCSTR _community, int _entity_id, int val)
{
    CHARACTER_COMMUNITY c;
    c.set(_community);
    RELATION_REGISTRY().SetCommunityGoodwill(c.index(), u16(_entity_id), val);
}

void g_change_community_goodwill(LPCSTR _community, int _entity_id, int val)
{
    CHARACTER_COMMUNITY c;
    c.set(_community);
    RELATION_REGISTRY().ChangeCommunityGoodwill(c.index(), u16(_entity_id), val);
}

int g_get_community_relation(LPCSTR comm_from, LPCSTR comm_to)
{
    CHARACTER_COMMUNITY community_from;
    community_from.set(comm_from);
    CHARACTER_COMMUNITY community_to;
    community_to.set(comm_to);

    return RELATION_REGISTRY().GetCommunityRelation(community_from.index(), community_to.index());
}

void g_set_community_relation(LPCSTR comm_from, LPCSTR comm_to, int value)
{
    CHARACTER_COMMUNITY community_from;
    community_from.set(comm_from);
    CHARACTER_COMMUNITY community_to;
    community_to.set(comm_to);

    RELATION_REGISTRY().SetCommunityRelation(community_from.index(), community_to.index(), value);
}


u32 render_get_dx_level() { return GEnv.Render->get_dx_level(); }
CUISequencer* g_tutorial = NULL;
CUISequencer* g_tutorial2 = NULL;

void start_tutorial(LPCSTR name)
{
    if (g_tutorial)
    {
        VERIFY(!g_tutorial2);
        g_tutorial2 = g_tutorial;
    };

    g_tutorial = new CUISequencer();
    g_tutorial->Start(name);
    if (g_tutorial2)
        g_tutorial->m_pStoredInputReceiver = g_tutorial2->m_pStoredInputReceiver;
}

void stop_tutorial()
{
    if (g_tutorial)
        g_tutorial->Stop();
}

//Alundaio: namespace level exports extension
#ifdef NAMESPACE_LEVEL_EXPORTS
//ability to update level netpacket
void g_send(NET_Packet& P, bool bReliable = false, bool bSequential = true, bool bHighPriority = false, bool bSendImmediately = false)
{
    Level().Send(P, net_flags(bReliable, bSequential, bHighPriority, bSendImmediately));
}

//can spawn entities like bolts, phantoms, ammo, etc. which normally crash when using alife():create()
void spawn_section(pcstr sSection, Fvector3 vPosition, u32 LevelVertexID, u16 ParentID, bool bReturnItem = false)
{
    Level().spawn_item(sSection, vPosition, LevelVertexID, ParentID, bReturnItem);
}

//ability to get the target game_object at crosshair
CScriptGameObject* g_get_target_obj()
{
    collide::rq_result& RQ = HUD().GetCurrentRayQuery();
    if (RQ.O)
    {
        CGameObject* game_object = static_cast<CGameObject*>(RQ.O);
        if (game_object)
            return game_object->lua_game_object();
    }
    return nullptr;
}

float g_get_target_dist()
{
    collide::rq_result& RQ = HUD().GetCurrentRayQuery();
    if (RQ.range)
        return RQ.range;
    return 0.f;
}

u32 g_get_target_element()
{
	collide::rq_result& RQ = HUD().GetCurrentRayQuery();
	if (RQ.element)
		return RQ.element;

	return 0;
}

u8 get_active_cam()
{
    CActor* actor = smart_cast<CActor*>(Level().CurrentViewEntity());
    if (actor)
        return (u8)actor->active_cam();

    return 255;
}

void set_active_cam(u8 mode)
{
    CActor* actor = smart_cast<CActor*>(Level().CurrentViewEntity());
    if (actor && mode <= eacMaxCam)
        actor->cam_Set((EActorCameras)mode);
}
#endif
//-Alundaio

// KD: raypick	
bool ray_pick(const Fvector& start, const Fvector& dir, float range,
              collide::rq_target tgt, script_rq_result& script_R,
              CScriptGameObject* ignore_object)
{
    collide::rq_result R;
    IGameObject* ignore = nullptr;
    if (ignore_object)
        ignore = smart_cast<IGameObject*>(&(ignore_object->object()));
    if (Level().ObjectSpace.RayPick(start, dir, range, tgt, R, ignore))
    {
        script_R.set(R);
        return true;
    }
    return false;
}

// XXX nitrocaster: one can export enum like class, without defining dummy type
template<typename T>
struct EnumCallbackType {};

// IC static void CLevel_Export(lua_State* luaState)
// {
//     class_<CEnvDescriptor>("CEnvDescriptor")
//         .def_readonly("fog_density", &CEnvDescriptor::fog_density)
//         .def_readonly("far_plane", &CEnvDescriptor::far_plane),
// 
//         class_<CEnvironment>("CEnvironment").def("current", current_environment);
// 
//     module(luaState, "level")[
//         //Alundaio: Extend level namespace exports
// #ifdef NAMESPACE_LEVEL_EXPORTS
//         def("send", &g_send) , //allow the ability to send netpacket to level
//         //def("ray_pick",g_ray_pick),
//         def("get_target_obj", &g_get_target_obj), //intentionally named to what is in xray extensions
//         def("get_target_dist", &g_get_target_dist),
//         def("get_target_element", &g_get_target_element), //Can get bone cursor is targeting
//         def("spawn_item", &spawn_section),
//         def("get_active_cam", &get_active_cam),
//         def("set_active_cam", &set_active_cam),
// #endif
//         //Alundaio: END
//         // obsolete\deprecated
//         def("object_by_id", get_object_by_id),
// #ifdef DEBUG
//         def("debug_object", get_object_by_name), def("debug_actor", tpfGetActor), def("check_object", check_object),
// #endif
// 
//         def("get_weather", get_weather), def("set_weather", set_weather), def("set_weather_fx", set_weather_fx),
//         def("start_weather_fx_from_time", start_weather_fx_from_time), def("is_wfx_playing", is_wfx_playing),
//         def("get_wfx_time", get_wfx_time), def("stop_weather_fx", stop_weather_fx),
// 
//         def("environment", environment),
// 
//         def("set_time_factor", set_time_factor), def("get_time_factor", get_time_factor),
// 
//         def("set_game_difficulty", set_game_difficulty), def("get_game_difficulty", get_game_difficulty),
// 
//         def("get_time_days", get_time_days), def("get_time_hours", get_time_hours),
//         def("get_time_minutes", get_time_minutes), def("change_game_time", change_game_time),
// 
//         def("high_cover_in_direction", high_cover_in_direction), def("low_cover_in_direction", low_cover_in_direction),
//         def("vertex_in_direction", vertex_in_direction), def("rain_factor", rain_factor),
//         def("patrol_path_exists", patrol_path_exists), def("vertex_position", vertex_position), def("name", get_name),
//         def("prefetch_sound", prefetch_sound),
// 
//         def("client_spawn_manager", get_client_spawn_manager),
// 
//         def("map_add_object_spot_ser", map_add_object_spot_ser), def("map_add_object_spot", map_add_object_spot),
//         //-		def("map_add_object_spot_complex",		map_add_object_spot_complex),
//         def("map_remove_object_spot", map_remove_object_spot), def("map_has_object_spot", map_has_object_spot),
//         def("map_change_spot_hint", map_change_spot_hint),
// 
//         def("start_stop_menu", start_stop_menu),
//         def("add_dialog_to_render", add_dialog_to_render),
//         def("remove_dialog_to_render", remove_dialog_to_render),
//         def("main_input_receiver", main_input_receiver),
//         def("hide_indicators", hide_indicators),
//         def("hide_indicators_safe", hide_indicators_safe),
// 
//         def("show_indicators", show_indicators), def("show_weapon", show_weapon),
//         def("add_call", ((void (*)(const luabind::functor<bool>&, const luabind::functor<void>&)) & add_call)),
//         def("add_call",
//             ((void (*)(const luabind::object&, const luabind::functor<bool>&, const luabind::functor<void>&)) &
//                 add_call)),
//         def("add_call", ((void (*)(const luabind::object&, LPCSTR, LPCSTR)) & add_call)),
//         def("remove_call", ((void (*)(const luabind::functor<bool>&, const luabind::functor<void>&)) & remove_call)),
//         def("remove_call",
//             ((void (*)(const luabind::object&, const luabind::functor<bool>&, const luabind::functor<void>&)) &
//                 remove_call)),
//         def("remove_call", ((void (*)(const luabind::object&, LPCSTR, LPCSTR)) & remove_call)),
//         def("remove_calls_for_object", remove_calls_for_object), def("present", is_level_present),
//         def("disable_input", disable_input), def("enable_input", enable_input), def("spawn_phantom", spawn_phantom),
// 
//         def("get_bounding_volume", get_bounding_volume),
// 
//         def("iterate_sounds", &iterate_sounds1), def("iterate_sounds", &iterate_sounds2),
//         def("physics_world", &physics_world_scripted), def("get_snd_volume", &get_snd_volume),
//         def("set_snd_volume", &set_snd_volume), def("add_cam_effector", &add_cam_effector),
//         def("add_cam_effector2", &add_cam_effector2), def("remove_cam_effector", &remove_cam_effector),
//         def("add_pp_effector", &add_pp_effector), def("set_pp_effector_factor", &set_pp_effector_factor),
//         def("set_pp_effector_factor", &set_pp_effector_factor2), def("remove_pp_effector", &remove_pp_effector),
// 
//         def("add_complex_effector", &add_complex_effector), def("remove_complex_effector", &remove_complex_effector),
// 
//         def("vertex_id", &vertex_id),
// 
//         def("game_id", &GameID),
//         def("ray_pick", &ray_pick)],
// 
//         module(luaState, "actor_stats")[def("add_points", &add_actor_points),
//             def("add_points_str", &add_actor_points_str), def("get_points", &get_actor_points)];
// 
//     module(luaState)
//     [
//         class_<CRayPick>("ray_pick")
//         .def(constructor<>())
//         .def(constructor<Fvector&, Fvector&, float, collide::rq_target, CScriptGameObject*>())
//         .def("set_position", &CRayPick::set_position)
//         .def("set_direction", &CRayPick::set_direction)
//         .def("set_range", &CRayPick::set_range)
//         .def("set_flags", &CRayPick::set_flags)
//         .def("set_ignore_object", &CRayPick::set_ignore_object)
//         .def("query", &CRayPick::query)
//         .def("get_result", &CRayPick::get_result)
//         .def("get_object", &CRayPick::get_object)
//         .def("get_distance", &CRayPick::get_distance)
//         .def("get_element", &CRayPick::get_element),
//         class_<script_rq_result>("rq_result")
//         .def_readonly("object", &script_rq_result::O)
//         .def_readonly("range", &script_rq_result::range)
//         .def_readonly("element", &script_rq_result::element)
//         .def(constructor<>()),
//         class_<EnumCallbackType<collide::rq_target>>("rq_target")
//         .enum_("targets")
//         [
//             value("rqtNone", int(collide::rqtNone)),
//             value("rqtObject", int(collide::rqtObject)),
//             value("rqtStatic", int(collide::rqtStatic)),
//             value("rqtShape", int(collide::rqtShape)),
//             value("rqtObstacle", int(collide::rqtObstacle)),
//             value("rqtBoth", int(collide::rqtBoth)),
//             value("rqtDyn", int(collide::rqtDyn))
//         ]
//     ];
// 
//     module(luaState)[def("command_line", &command_line),
//         def("IsGameTypeSingle", (bool (*)())&IsGameTypeSingle),
//         def("IsDynamicMusic", &IsDynamicMusic), def("render_get_dx_level", &render_get_dx_level),
//         def("IsImportantSave", &IsImportantSave)];
// 
//     module(luaState, "relation_registry")[def("community_goodwill", &g_community_goodwill),
//         def("set_community_goodwill", &g_set_community_goodwill),
//         def("change_community_goodwill", &g_change_community_goodwill),
// 
//         def("community_relation", &g_get_community_relation), def("set_community_relation", &g_set_community_relation),
//         def("get_general_goodwill_between", &g_get_general_goodwill_between)];
//     module(
//         luaState, "game")[class_<xrTime>("CTime")
//                               .enum_("date_format")[value("DateToDay", int(InventoryUtilities::edpDateToDay)),
//                                   value("DateToMonth", int(InventoryUtilities::edpDateToMonth)),
//                                   value("DateToYear", int(InventoryUtilities::edpDateToYear))]
//                               .enum_("time_format")[value("TimeToHours", int(InventoryUtilities::etpTimeToHours)),
//                                   value("TimeToMinutes", int(InventoryUtilities::etpTimeToMinutes)),
//                                   value("TimeToSeconds", int(InventoryUtilities::etpTimeToSeconds)),
//                                   value("TimeToMilisecs", int(InventoryUtilities::etpTimeToMilisecs))]
//                               .def(constructor<>())
//                               .def(constructor<const xrTime&>())
//                               .def(const_self < xrTime())
//                               .def(const_self <= xrTime())
//                               .def(const_self > xrTime())
//                               .def(const_self >= xrTime())
//                               .def(const_self == xrTime())
//                               .def(self + xrTime())
//                               .def(self - xrTime())
// 
//                               .def("diffSec", &xrTime::diffSec_script)
//                               .def("add", &xrTime::add_script)
//                               .def("sub", &xrTime::sub_script)
// 
//                               .def("setHMS", &xrTime::setHMS)
//                               .def("setHMSms", &xrTime::setHMSms)
//                               .def("set", &xrTime::set)
//                               .def("get", &xrTime::get, policy_list<out_value<2>, out_value<3>, out_value<4>,
//                                                             out_value<5>, out_value<6>, out_value<7>, out_value<8>>())
//                               .def("dateToString", &xrTime::dateToString)
//                               .def("timeToString", &xrTime::timeToString),
//         // declarations
//         def("time", get_time), def("get_game_time", get_time_struct),
//         //		def("get_surge_time",	Game::get_surge_time),
//         //		def("get_object_by_name",Game::get_object_by_name),
// 
//         def("start_tutorial", &start_tutorial), def("stop_tutorial", &stop_tutorial),
//         def("has_active_tutorial", &has_active_tutotial), def("translate_string", &translate_string)
// 
//     ];
// 
// };
// 
// SCRIPT_EXPORT_FUNC(CLevel, (), CLevel_Export);
