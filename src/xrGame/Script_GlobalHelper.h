#pragma once

#include "object_factory.h"
#include "Script_XR_Patrol.h"
#include "Script_SmartTerrainControl.h"
#include "Script_ISchemeEntity.h"
#include "Script_ISchemeMonster.h"
#include "Script_ISchemeStalker.h"
#include "Script_MobStateManager.h"
#include "Script_SchemeMobWalker.h"
#include "Script_SchemeMobRemark.h"
#include "Script_SchemeMobJump.h"
#include "Script_SchemeMobHome.h"
#include "Script_SchemeMobDeath.h"
#include "Script_SchemeMobCombat.h"
#include "Script_SchemeMobCamp.h"
#include "Script_HelicopterLook.h"
#include "Script_HelicopterFly.h"
#include "Script_HelicopterFire.h"
#include "Script_SchemeHelicopterMove.h"

// @ PRIVATE PREPROCESSOR!
#define _REGISTER_FULL_FUNCTION_XR_CONDITION(function_name, function)                                       \
    this->m_registered_functions_xr_conditions[#function_name "_client"] = function##_client;               \
    this->m_registered_functions_xr_conditions[#function_name "_client_server"] = function##_client_server; \
    this->m_registered_functions_xr_conditions[#function_name "_server"] = function##_server;

// @ PRIVATE PREPROCESSOR!
#define _REGISTER_FUNCTION_DIALOG_MANAGER(function_name, function) \
    this->m_registered_functions_dialog_manager[#function_name] = function;

namespace Cordis
{
namespace Scripts
{
// Lord: удалить все '// return;'
// @ Сюда не добавлять сущности которые могут относится к CScriptGameObject, CSE_ALife, ибо всё это должно находится в
// DataBase
// @ Не захломлять Deallocate методы!!!!!!! И соответственно минимизировать количество сущностей которые будут это
// контролировать!
struct Script_GlobalHelper
{
private:
    Script_GlobalHelper(void)
    {
// @ Здесь инициализация всех "локальных" карт которые находятся в каждом скрипте
// @ Инициаилизируется на запуске самого интро
#pragma region Cordis Usable Clsid
        this->m_stalker_classes[Globals::get_script_clsid(CLSID_SE_ACTOR)] = true;
        this->m_stalker_classes[Globals::get_script_clsid(CLSID_SE_STALKER)] = true;

        Msg("[Scripts/Script_GlobalHelper/ctor()] registered stalker clsid classes!");

        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_BLOODSUCKER)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_BOAR)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_DOG)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_FLESH)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_DOG_PSEUDO)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_DOG_PSY)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_DOG_PSY_PHANTOM)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_DOG)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_BURER)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_CHIMERA)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_CAT)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_CONTROLLER)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_IZLOM)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_POLTERGEIST)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_PSEUDO_GIGANT)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_ZOMBI)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_SNORK)] = true;
        this->m_monster_classes[Globals::get_script_clsid(CLSID_SE_MONSTER_TUSHKANO)] = true;

        Msg("[Scripts/Script_GlobalHelper/ctor()] registered monster clsid classes!");

        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_VINTOREZ)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_AK74)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_LR300)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_HPSA)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_PM)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_SHOTGUN)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_SHOTGUN_AUTOMATIC)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_BM16)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_SVD)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_SVU)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_RG6)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_RPG7)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_VAL)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_WALTHER)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_USP45)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_GROZA)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_KNIFE)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_WEAPON_GRENADE_LAUNCHER)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_GRENADE_F1)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_SE_GRENADE_RGD)] = true;
        this->m_weapon_classes[Globals::get_script_clsid(CLSID_OBJECT_G_FAKE)] = true;

        Msg("[Scripts/Script_GlobalHelper/ctor()] registered weapon clsid classes!");

        this->m_artefact_classes[Globals::get_script_clsid(CLSID_SE_ARTEFACT)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_BAST)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_BLACK_GRAVI)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_BLACKDROPS)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_ELECTRIC_BALL)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_DUMMY)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_FADED_BALL)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_GALANTINE)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_GRAVI)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_MERCURY_BALL)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_NEEDLES)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_RUSTY_HAIR)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_THORN)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_AF_ZUDA)] = true;
        this->m_artefact_classes[Globals::get_script_clsid(CLSID_ARTEFACT)] = true;

        Msg("[Scripts/Script_GlobalHelper/ctor()] registered artefact clsid classes!");

#pragma endregion

#pragma region Cordis XR_PATROL Initializing
        std::pair<Fvector, float> xr_patrol_formations_data;
        xr_patrol_formations_data.first = Fvector().set(0.3f, 0.0f, -1.0f);
        xr_patrol_formations_data.second = 1.2f;
        /*        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_BACK] = xr_vector<std::pair<Fvector,
         * float>>();*/
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_BACK].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(-0.3f, 0.0f, -1.0f);
        xr_patrol_formations_data.second = 2.4f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_BACK].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(0.3f, 0.0f, -1.0f);
        xr_patrol_formations_data.second = 3.6f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_BACK].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(-0.3f, 0.0f, -1.0f);
        xr_patrol_formations_data.second = 4.8f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_BACK].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(0.3f, 0.0f, -1.0f);
        xr_patrol_formations_data.second = 6.0f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_BACK].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(-0.3f, 0.0f, -1.0f);
        xr_patrol_formations_data.second = 7.2f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_BACK].push_back(xr_patrol_formations_data);

        xr_patrol_formations_data.first = Fvector().set(-1.0f, 0.0f, 0.0f);
        xr_patrol_formations_data.second = 2.0f;
        /*        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_LINE] = xr_vector<std::pair<Fvector,
         * float>>();*/
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_LINE].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(-1.0f, 0.0f, 0.0f);
        xr_patrol_formations_data.second = 4.0f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_LINE].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(-1.0f, 0.0f, 0.0f);
        xr_patrol_formations_data.second = 6.0f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_LINE].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(1.0f, 0.0f, 0.0f);
        xr_patrol_formations_data.second = 2.0f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_LINE].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(1.0f, 0.0f, 0.0f);
        xr_patrol_formations_data.second = 4.0f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_LINE].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(1.0f, 0.0f, 0.0f);
        xr_patrol_formations_data.second = 6.0f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_LINE].push_back(xr_patrol_formations_data);

        xr_patrol_formations_data.first = Fvector().set(0.44721359f, 0.0f, -0.89442718f);
        xr_patrol_formations_data.second = 2.2360680f;
        /*        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_AROUND] = xr_vector<std::pair<Fvector,
         * float>>();*/

        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_AROUND].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(-0.44721359f, 0.0f, -0.89442718f);
        xr_patrol_formations_data.second = 2.2360680f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_AROUND].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(1.0f, 0.0f, 0.0f);
        xr_patrol_formations_data.second = 2.0f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_AROUND].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(-1.0f, 0.0f, 0.0f);
        xr_patrol_formations_data.second = 2.0f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_AROUND].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(0.44721359f, 0.0f, -0.89442718f);
        xr_patrol_formations_data.second = 2.2360680f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_AROUND].push_back(xr_patrol_formations_data);
        xr_patrol_formations_data.first = Fvector().set(-0.44721359f, 0.0f, -0.89442718f);
        xr_patrol_formations_data.second = 2.2360680f;
        XR_PATROL::getFormations()[XR_PATROL::XR_PATROL_FORMATION_INDEX_AROUND].push_back(xr_patrol_formations_data);
#pragma endregion

#pragma region Cordis SmartCovers Initialzing

#pragma region Cordis Combat Prone Smart Cover
        SmartCoverData combat_prone_smartcover;
        SmartCoverLoopholeData combat_prone_loophole;

#pragma region Cordis Loophole
        combat_prone_loophole.m_id = "prone";
        combat_prone_loophole.m_is_usable = true;
        combat_prone_loophole.m_is_exitable = true;
        combat_prone_loophole.m_is_enterable = true;
        combat_prone_loophole.m_fieldofview = 60.0f;
        combat_prone_loophole.m_fieldofview_danger = 90.0f;
        combat_prone_loophole.m_range = 70.0f;
        combat_prone_loophole.m_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        combat_prone_loophole.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_prone_loophole.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        combat_prone_loophole.m_enter_direction = Fvector().set(-1.0f, 0.0f, 0.0f);

        SmartCoverLoopholeData::SmartCoverActionsData combat_prone_action1;
        combat_prone_action1.m_id = "idle";
        combat_prone_action1.register_animation("idle", "loophole_9_idle_0");

        combat_prone_loophole.register_action(combat_prone_action1);

        SmartCoverLoopholeData::SmartCoverActionsData combat_prone_action2;
        combat_prone_action2.m_id = "lookout";
        combat_prone_action2.register_animation("idle", "loophole_9_look_idle_0");

        combat_prone_loophole.register_action(combat_prone_action2);

        SmartCoverLoopholeData::SmartCoverActionsData combat_prone_action3;
        combat_prone_action3.m_id = "fire";
        combat_prone_action3.register_animation("idle", "loophole_9_attack_idle_0");
        combat_prone_action3.register_animation("shoot", "loophole_9_attack_shoot_0");
        combat_prone_action3.register_animation("shoot", "loophole_9_attack_shoot_1");

        combat_prone_loophole.register_action(combat_prone_action3);

        SmartCoverLoopholeData::SmartCoverActionsData combat_prone_action4;
        combat_prone_action4.m_id = "fire_no_lookout";
        combat_prone_action4.register_animation("idle", "loophole_9_attack_idle_0");
        combat_prone_action4.register_animation("shoot", "loophole_9_attack_shoot_0");
        combat_prone_action4.register_animation("shoot", "loophole_9_attack_shoot_1");

        combat_prone_loophole.register_action(combat_prone_action4);

        SmartCoverLoopholeData::SmartCoverActionsData combat_prone_action5;
        combat_prone_action5.m_id = "reload";
        combat_prone_action5.register_animation("idle", "loophole_9_reload_0");

        combat_prone_loophole.register_action(combat_prone_action5);

        SmartCoverLoopholeData::SmartCoverTransitionsData combat_prone_transition1;
        combat_prone_transition1.m_action_from = "idle";
        combat_prone_transition1.m_action_to = "lookout";
        combat_prone_transition1.m_weight = 1.2f;
        combat_prone_transition1.m_animations.push_back("loophole_9_look_in_0");

        combat_prone_loophole.register_transition(combat_prone_transition1);

        SmartCoverLoopholeData::SmartCoverTransitionsData combat_prone_transition2;
        combat_prone_transition2.m_action_from = "lookout";
        combat_prone_transition2.m_action_to = "idle";
        combat_prone_transition2.m_animations.push_back("loophole_9_look_out_0");
        combat_prone_transition2.m_weight = 1.2f;

        combat_prone_loophole.register_transition(combat_prone_transition2);

        SmartCoverLoopholeData::SmartCoverTransitionsData combat_prone_transition3;
        combat_prone_transition3.m_action_from = "idle";
        combat_prone_transition3.m_action_to = "fire";
        combat_prone_transition3.m_weight = 1.2f;
        combat_prone_transition3.m_animations.push_back("loophole_9_attack_in_0");

        combat_prone_loophole.register_transition(combat_prone_transition3);

        SmartCoverLoopholeData::SmartCoverTransitionsData combat_prone_transition4;
        combat_prone_transition4.m_action_from = "fire";
        combat_prone_transition4.m_action_to = "idle";
        combat_prone_transition4.m_weight = 1.2f;
        combat_prone_transition4.m_animations.push_back("loophole_9_attack_out_0");

        combat_prone_loophole.register_transition(combat_prone_transition4);

        SmartCoverLoopholeData::SmartCoverTransitionsData combat_prone_transition5;
        combat_prone_transition5.m_action_from = "idle";
        combat_prone_transition5.m_action_to = "fire_no_lookout";
        combat_prone_transition5.m_weight = 1.2f;
        combat_prone_transition5.m_animations.push_back("loophole_9_attack_in_0");

        combat_prone_loophole.register_transition(combat_prone_transition5);

        SmartCoverLoopholeData::SmartCoverTransitionsData combat_prone_transition6;
        combat_prone_transition6.m_action_from = "fire_no_lookout";
        combat_prone_transition6.m_action_to = "idle";
        combat_prone_transition6.m_weight = 1.2f;
        combat_prone_transition6.m_animations.push_back("loophole_9_attack_out_0");

        combat_prone_loophole.register_transition(combat_prone_transition6);
#pragma endregion Cordis Loophole

#pragma region Cordis Transition
        SmartCoverData::SmartCoverTransitionsData combat_prone_smartcover_transition1;
        combat_prone_smartcover_transition1.m_vertex0 = "";
        combat_prone_smartcover_transition1.m_vertex1 = "prone";
        combat_prone_smartcover_transition1.m_weight = 1.0f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_prone_smartcover_transition1_action1;
        combat_prone_smartcover_transition1_action1.m_action.m_animation = "loophole_9_in_front_0";
        combat_prone_smartcover_transition1_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_prone_smartcover_transition1_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_prone_smartcover_transition1_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_prone_smartcover_transition1_action1.m_precondition_functor = "true";
        combat_prone_smartcover_transition1_action1.m_preconditions_params = "";

        combat_prone_smartcover_transition1.m_actions.push_back(combat_prone_smartcover_transition1_action1);

        SmartCoverData::SmartCoverTransitionsData combat_prone_smartcover_transition2;
        combat_prone_smartcover_transition2.m_vertex0 = "";
        combat_prone_smartcover_transition2.m_vertex1 = "prone";
        combat_prone_smartcover_transition2.m_weight = 1.1f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_prone_smartcover_transition2_action1;
        combat_prone_smartcover_transition2_action1.m_action.m_animation = "loophole_9_jump_1";
        combat_prone_smartcover_transition2_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_prone_smartcover_transition2_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_prone_smartcover_transition2_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_prone_smartcover_transition2_action1.m_precondition_functor = "true";
        combat_prone_smartcover_transition2_action1.m_preconditions_params = "";

        combat_prone_smartcover_transition2.m_actions.push_back(combat_prone_smartcover_transition2_action1);

#pragma endregion Cordis Transition

        combat_prone_smartcover.setNeedWeapon(true);
        combat_prone_smartcover.register_loophole(combat_prone_loophole);
        combat_prone_smartcover.register_transition(combat_prone_smartcover_transition1);
        combat_prone_smartcover.register_transition(combat_prone_smartcover_transition2);
        this->m_registered_smartcovers["combat_prone"] = combat_prone_smartcover;
#pragma endregion Cordis Combat Prone Smart Cover

#pragma region Cordis Combat Front Smart Cover
        SmartCoverData combat_front_smartcover;

#pragma region Cordis Loophole
        SmartCoverLoopholeData combat_front_loophole_crouch_front_left;
        combat_front_loophole_crouch_front_left.m_id = "crouch_front_left";
        combat_front_loophole_crouch_front_left.m_is_usable = true;
        combat_front_loophole_crouch_front_left.m_is_exitable = true;
        combat_front_loophole_crouch_front_left.m_is_enterable = true;
        combat_front_loophole_crouch_front_left.m_fieldofview = 70.0f;
        combat_front_loophole_crouch_front_left.m_fieldofview_danger = 90.0f;
        combat_front_loophole_crouch_front_left.m_range = 70.0f;
        combat_front_loophole_crouch_front_left.m_fieldofview_direction = Fvector().set(-1.0f, 0.0f, -0.7f);
        combat_front_loophole_crouch_front_left.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_loophole_crouch_front_left.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, -1.0f);
        combat_front_loophole_crouch_front_left.m_enter_direction = Fvector().set(0.0f, 0.0f, 0.0f);

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_left_action;
            combat_front_loophole_crouch_front_left_action.m_id = "idle";
            combat_front_loophole_crouch_front_left_action.register_animation(
                "idle", "loophole_crouch_front_left_idle_0");

            combat_front_loophole_crouch_front_left.register_action(combat_front_loophole_crouch_front_left_action);
        } // 1

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_left_action;
            combat_front_loophole_crouch_front_left_action.m_id = "lookout";
            combat_front_loophole_crouch_front_left_action.register_animation(
                "idle", "loophole_crouch_front_left_look_idle_0");

            combat_front_loophole_crouch_front_left.register_action(combat_front_loophole_crouch_front_left_action);
        } // 2

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_left_action;
            combat_front_loophole_crouch_front_left_action.m_id = "fire";
            combat_front_loophole_crouch_front_left_action.register_animation(
                "idle", "loophole_crouch_front_left_attack_idle_0");
            combat_front_loophole_crouch_front_left_action.register_animation(
                "shoot", "loophole_crouch_front_left_attack_shoot_0");
            combat_front_loophole_crouch_front_left_action.register_animation(
                "shoot", "loophole_crouch_front_left_attack_shoot_1");

            combat_front_loophole_crouch_front_left.register_action(combat_front_loophole_crouch_front_left_action);
        } // 3

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_left_action;
            combat_front_loophole_crouch_front_left_action.m_id = "fire_no_lookout";
            combat_front_loophole_crouch_front_left_action.register_animation(
                "idle", "loophole_crouch_front_left_attack_idle_0");
            combat_front_loophole_crouch_front_left_action.register_animation(
                "shoot", "loophole_crouch_front_left_attack_idle_0");

            combat_front_loophole_crouch_front_left.register_action(combat_front_loophole_crouch_front_left_action);
        } // 4

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_left_action;
            combat_front_loophole_crouch_front_left_action.m_id = "reload";
            combat_front_loophole_crouch_front_left_action.register_animation(
                "idle", "loophole_crouch_front_left_reload_0");

            combat_front_loophole_crouch_front_left.register_action(combat_front_loophole_crouch_front_left_action);
        } // 5

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_left_transition;
            combat_front_loophole_crouch_front_left_transition.m_action_from = "idle";
            combat_front_loophole_crouch_front_left_transition.m_action_to = "lookout";
            combat_front_loophole_crouch_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_left_transition.m_animations.push_back(
                "loophole_crouch_front_left_look_in_0");

            combat_front_loophole_crouch_front_left.register_transition(
                combat_front_loophole_crouch_front_left_transition);
        } // 11

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_left_transition;
            combat_front_loophole_crouch_front_left_transition.m_action_from = "lookout";
            combat_front_loophole_crouch_front_left_transition.m_action_to = "idle";
            combat_front_loophole_crouch_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_left_transition.m_animations.push_back(
                "loophole_crouch_front_left_look_out_0");

            combat_front_loophole_crouch_front_left.register_transition(
                combat_front_loophole_crouch_front_left_transition);
        } // 12

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_left_transition;
            combat_front_loophole_crouch_front_left_transition.m_action_from = "idle";
            combat_front_loophole_crouch_front_left_transition.m_action_to = "fire";
            combat_front_loophole_crouch_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_left_transition.m_animations.push_back(
                "loophole_crouch_front_left_attack_in_0");

            combat_front_loophole_crouch_front_left.register_transition(
                combat_front_loophole_crouch_front_left_transition);
        } // 13

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_left_transition;
            combat_front_loophole_crouch_front_left_transition.m_action_from = "fire";
            combat_front_loophole_crouch_front_left_transition.m_action_to = "idle";
            combat_front_loophole_crouch_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_left_transition.m_animations.push_back(
                "loophole_crouch_front_left_attack_out_0");

            combat_front_loophole_crouch_front_left.register_transition(
                combat_front_loophole_crouch_front_left_transition);
        } // 14

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_left_transition;
            combat_front_loophole_crouch_front_left_transition.m_action_from = "idle";
            combat_front_loophole_crouch_front_left_transition.m_action_to = "fire_no_lookout";
            combat_front_loophole_crouch_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_left_transition.m_animations.push_back(
                "loophole_crouch_front_left_attack_in_0");

            combat_front_loophole_crouch_front_left.register_transition(
                combat_front_loophole_crouch_front_left_transition);
        } // 15

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_left_transition;
            combat_front_loophole_crouch_front_left_transition.m_action_from = "fire_no_lookout";
            combat_front_loophole_crouch_front_left_transition.m_action_to = "idle";
            combat_front_loophole_crouch_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_left_transition.m_animations.push_back(
                "loophole_crouch_front_left_attack_out_0");

            combat_front_loophole_crouch_front_left.register_transition(
                combat_front_loophole_crouch_front_left_transition);
        } // 16
#pragma endregion Cordis Loophole

#pragma region Cordis Loophole
        SmartCoverLoopholeData combat_front_loophole_crouch_front_right;
        combat_front_loophole_crouch_front_right.m_id = "crouch_front_right";
        combat_front_loophole_crouch_front_right.m_is_usable = true;
        combat_front_loophole_crouch_front_right.m_is_exitable = true;
        combat_front_loophole_crouch_front_right.m_is_enterable = true;
        combat_front_loophole_crouch_front_right.m_fieldofview = 70.0f;
        combat_front_loophole_crouch_front_right.m_fieldofview_danger = 90.0f;
        combat_front_loophole_crouch_front_right.m_range = 70.0f;
        combat_front_loophole_crouch_front_right.m_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.7f);
        combat_front_loophole_crouch_front_right.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_loophole_crouch_front_right.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 1.0f);
        combat_front_loophole_crouch_front_right.m_enter_direction = Fvector().set(-1.0f, 0.0f, 0.0f);

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_right_action;
            combat_front_loophole_crouch_front_right_action.m_id = "idle";
            combat_front_loophole_crouch_front_right_action.register_animation(
                "idle", "loophole_crouch_front_right_idle_0");

            combat_front_loophole_crouch_front_right.register_action(combat_front_loophole_crouch_front_right_action);
        } // 1

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_right_action;
            combat_front_loophole_crouch_front_right_action.m_id = "lookout";
            combat_front_loophole_crouch_front_right_action.register_animation(
                "idle", "loophole_crouch_front_right_look_idle_0");

            combat_front_loophole_crouch_front_right.register_action(combat_front_loophole_crouch_front_right_action);
        } // 2

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_right_action;
            combat_front_loophole_crouch_front_right_action.m_id = "fire";
            combat_front_loophole_crouch_front_right_action.register_animation(
                "idle", "loophole_crouch_front_right_attack_idle_0");
            combat_front_loophole_crouch_front_right_action.register_animation(
                "shoot", "loophole_crouch_front_right_attack_shoot_0");
            combat_front_loophole_crouch_front_right_action.register_animation(
                "shoot", "loophole_crouch_front_right_attack_shoot_1");

            combat_front_loophole_crouch_front_right.register_action(combat_front_loophole_crouch_front_right_action);
        } // 3

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_right_action;
            combat_front_loophole_crouch_front_right_action.m_id = "fire_no_lookout";
            combat_front_loophole_crouch_front_right_action.register_animation(
                "idle", "loophole_crouch_front_right_attack_idle_0");
            combat_front_loophole_crouch_front_right_action.register_animation(
                "shoot", "loophole_crouch_front_right_attack_shoot_0");
            combat_front_loophole_crouch_front_right_action.register_animation(
                "shoot", "loophole_crouch_front_right_attack_shoot_1");

            combat_front_loophole_crouch_front_right.register_action(combat_front_loophole_crouch_front_right_action);
        } // 4

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_right_action;
            combat_front_loophole_crouch_front_right_action.m_id = "reload";
            combat_front_loophole_crouch_front_right_action.register_animation(
                "idle", "loophole_crouch_front_right_reload_0");

            combat_front_loophole_crouch_front_right.register_action(combat_front_loophole_crouch_front_right_action);
        } // 5

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_right_transition;
            combat_front_loophole_crouch_front_right_transition.m_action_from = "idle";
            combat_front_loophole_crouch_front_right_transition.m_action_to = "lookout";
            combat_front_loophole_crouch_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_right_transition.m_animations.push_back(
                "loophole_crouch_front_right_look_in_0");

            combat_front_loophole_crouch_front_right.register_transition(
                combat_front_loophole_crouch_front_right_transition);
        } // 11

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_right_transition;
            combat_front_loophole_crouch_front_right_transition.m_action_from = "lookout";
            combat_front_loophole_crouch_front_right_transition.m_action_to = "idle";
            combat_front_loophole_crouch_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_right_transition.m_animations.push_back(
                "loophole_crouch_front_right_look_out_0");

            combat_front_loophole_crouch_front_right.register_transition(
                combat_front_loophole_crouch_front_right_transition);
        } // 12

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_right_transition;
            combat_front_loophole_crouch_front_right_transition.m_action_from = "idle";
            combat_front_loophole_crouch_front_right_transition.m_action_to = "fire";
            combat_front_loophole_crouch_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_right_transition.m_animations.push_back(
                "loophole_crouch_front_right_attack_in_0");

            combat_front_loophole_crouch_front_right.register_transition(
                combat_front_loophole_crouch_front_right_transition);
        } // 13

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_right_transition;
            combat_front_loophole_crouch_front_right_transition.m_action_from = "fire";
            combat_front_loophole_crouch_front_right_transition.m_action_to = "idle";
            combat_front_loophole_crouch_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_right_transition.m_animations.push_back(
                "loophole_crouch_front_right_attack_out_0");

            combat_front_loophole_crouch_front_right.register_transition(
                combat_front_loophole_crouch_front_right_transition);
        } // 14

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_right_transition;
            combat_front_loophole_crouch_front_right_transition.m_action_from = "idle";
            combat_front_loophole_crouch_front_right_transition.m_action_to = "fire_no_lookout";
            combat_front_loophole_crouch_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_right_transition.m_animations.push_back(
                "loophole_crouch_front_right_attack_in_0");

            combat_front_loophole_crouch_front_right.register_transition(
                combat_front_loophole_crouch_front_right_transition);
        } // 15

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_right_transition;
            combat_front_loophole_crouch_front_right_transition.m_action_from = "fire_no_lookout";
            combat_front_loophole_crouch_front_right_transition.m_action_to = "idle";
            combat_front_loophole_crouch_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_right_transition.m_animations.push_back(
                "loophole_crouch_front_right_attack_out_0");

            combat_front_loophole_crouch_front_right.register_transition(
                combat_front_loophole_crouch_front_right_transition);
        } // 16
#pragma endregion Cordis Loophole

#pragma region Cordis Loophole
        SmartCoverLoopholeData combat_front_loophole_crouch_front;
        combat_front_loophole_crouch_front.m_id = "crouch_front";
        combat_front_loophole_crouch_front.m_is_usable = true;
        combat_front_loophole_crouch_front.m_is_exitable = true;
        combat_front_loophole_crouch_front.m_is_enterable = true;
        combat_front_loophole_crouch_front.m_fieldofview = 70.0f;
        combat_front_loophole_crouch_front.m_fieldofview_danger = 110.0f;
        combat_front_loophole_crouch_front.m_range = 70.0f;
        combat_front_loophole_crouch_front.m_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        combat_front_loophole_crouch_front.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_loophole_crouch_front.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        combat_front_loophole_crouch_front.m_enter_direction = Fvector().set(-1.0f, 0.0f, 0.0f);

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_action;
            combat_front_loophole_crouch_front_action.m_id = "idle";
            combat_front_loophole_crouch_front_action.register_animation("idle", "loophole_crouch_front_idle_0");

            combat_front_loophole_crouch_front.register_action(combat_front_loophole_crouch_front_action);
        } // 1

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_action;
            combat_front_loophole_crouch_front_action.m_id = "lookout";
            combat_front_loophole_crouch_front_action.register_animation("idle", "loophole_crouch_front_look_idle_0");

            combat_front_loophole_crouch_front.register_action(combat_front_loophole_crouch_front_action);
        } // 2

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_action;
            combat_front_loophole_crouch_front_action.m_id = "fire";
            combat_front_loophole_crouch_front_action.register_animation("idle", "loophole_crouch_front_attack_idle_0");
            combat_front_loophole_crouch_front_action.register_animation(
                "shoot", "loophole_crouch_front_attack_shoot_0");
            combat_front_loophole_crouch_front_action.register_animation(
                "shoot", "loophole_crouch_front_attack_shoot_1");

            combat_front_loophole_crouch_front.register_action(combat_front_loophole_crouch_front_action);
        } // 3

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_action;
            combat_front_loophole_crouch_front_action.m_id = "fire_no_lookout";
            combat_front_loophole_crouch_front_action.register_animation("idle", "loophole_crouch_front_attack_idle_0");
            combat_front_loophole_crouch_front_action.register_animation(
                "shoot", "loophole_crouch_front_attack_shoot_0");
            combat_front_loophole_crouch_front_action.register_animation(
                "shoot", "loophole_crouch_front_attack_shoot_1");

            combat_front_loophole_crouch_front.register_action(combat_front_loophole_crouch_front_action);
        } // 4

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_crouch_front_action;
            combat_front_loophole_crouch_front_action.m_id = "reload";
            combat_front_loophole_crouch_front_action.register_animation("idle", "loophole_crouch_front_reload_0");

            combat_front_loophole_crouch_front.register_action(combat_front_loophole_crouch_front_action);
        } // 5

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_transition;
            combat_front_loophole_crouch_front_transition.m_action_from = "idle";
            combat_front_loophole_crouch_front_transition.m_action_to = "lookout";
            combat_front_loophole_crouch_front_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_transition.m_animations.push_back("loophole_crouch_front_look_in_0");

            combat_front_loophole_crouch_front.register_transition(combat_front_loophole_crouch_front_transition);
        } // 11

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_transition;
            combat_front_loophole_crouch_front_transition.m_action_from = "lookout";
            combat_front_loophole_crouch_front_transition.m_action_to = "idle";
            combat_front_loophole_crouch_front_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_transition.m_animations.push_back("loophole_crouch_front_look_out_0");

            combat_front_loophole_crouch_front.register_transition(combat_front_loophole_crouch_front_transition);
        } // 12

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_transition;
            combat_front_loophole_crouch_front_transition.m_action_from = "idle";
            combat_front_loophole_crouch_front_transition.m_action_to = "fire";
            combat_front_loophole_crouch_front_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_transition.m_animations.push_back("loophole_crouch_front_attack_in_0");

            combat_front_loophole_crouch_front.register_transition(combat_front_loophole_crouch_front_transition);
        } // 13

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_transition;
            combat_front_loophole_crouch_front_transition.m_action_from = "fire";
            combat_front_loophole_crouch_front_transition.m_action_to = "idle";
            combat_front_loophole_crouch_front_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_transition.m_animations.push_back("loophole_crouch_front_attack_out_0");

            combat_front_loophole_crouch_front.register_transition(combat_front_loophole_crouch_front_transition);
        } // 14

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_transition;
            combat_front_loophole_crouch_front_transition.m_action_from = "idle";
            combat_front_loophole_crouch_front_transition.m_action_to = "fire_no_lookout";
            combat_front_loophole_crouch_front_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_transition.m_animations.push_back("loophole_crouch_front_attack_in_0");

            combat_front_loophole_crouch_front.register_transition(combat_front_loophole_crouch_front_transition);
        } // 15

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_crouch_front_transition;
            combat_front_loophole_crouch_front_transition.m_action_from = "fire_no_lookout";
            combat_front_loophole_crouch_front_transition.m_action_to = "idle";
            combat_front_loophole_crouch_front_transition.m_weight = 1.2f;
            combat_front_loophole_crouch_front_transition.m_animations.push_back("loophole_crouch_front_attack_out_0");

            combat_front_loophole_crouch_front.register_transition(combat_front_loophole_crouch_front_transition);
        } // 16
#pragma endregion Cordis Loophole

#pragma region Cordis Loophole
        SmartCoverLoopholeData combat_front_loophole_stand_front_left;
        combat_front_loophole_stand_front_left.m_id = "stand_front_left";
        combat_front_loophole_stand_front_left.m_is_usable = true;
        combat_front_loophole_stand_front_left.m_is_exitable = true;
        combat_front_loophole_stand_front_left.m_is_enterable = true;
        combat_front_loophole_stand_front_left.m_fieldofview = 60.0f;
        combat_front_loophole_stand_front_left.m_fieldofview_danger = 90.0f;
        combat_front_loophole_stand_front_left.m_range = 50.0f;
        combat_front_loophole_stand_front_left.m_fieldofview_direction = Fvector().set(-1.0f, 0.0f, -0.7f);
        combat_front_loophole_stand_front_left.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_loophole_stand_front_left.m_danger_fieldofview_direction = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_loophole_stand_front_left.m_enter_direction = Fvector().set(-1.0f, 0.0f, 0.0f);

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_left_action;
            combat_front_loophole_stand_front_left_action.m_id = "idle";
            combat_front_loophole_stand_front_left_action.register_animation("idle", "loophole_stand_back_idle_0");

            combat_front_loophole_stand_front_left.register_action(combat_front_loophole_stand_front_left_action);
        } // 1

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_left_action;
            combat_front_loophole_stand_front_left_action.m_id = "lookout";
            combat_front_loophole_stand_front_left_action.register_animation("idle", "loophole_stand_back_idle_0");

            combat_front_loophole_stand_front_left.register_action(combat_front_loophole_stand_front_left_action);
        } // 2

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_left_action;
            combat_front_loophole_stand_front_left_action.m_id = "fire";
            combat_front_loophole_stand_front_left_action.register_animation(
                "idle", "loophole_stand_back_attack_idle_0");
            combat_front_loophole_stand_front_left_action.register_animation(
                "shoot", "loophole_stand_back_attack_shoot_0");
            combat_front_loophole_stand_front_left_action.register_animation(
                "shoot", "loophole_stand_back_attack_shoot_1");

            combat_front_loophole_stand_front_left.register_action(combat_front_loophole_stand_front_left_action);
        } // 3

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_left_action;
            combat_front_loophole_stand_front_left_action.m_id = "fire_no_lookout";
            combat_front_loophole_stand_front_left_action.register_animation("idle", "loophole_stand_back_idle_0");
            combat_front_loophole_stand_front_left_action.register_animation(
                "shoot", "loophole_stand_back_attack_shoot_0");
            combat_front_loophole_stand_front_left_action.register_animation(
                "shoot", "loophole_stand_back_attack_shoot_1");

            combat_front_loophole_stand_front_left.register_action(combat_front_loophole_stand_front_left_action);
        } // 4

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_left_action;
            combat_front_loophole_stand_front_left_action.m_id = "reload";
            combat_front_loophole_stand_front_left_action.register_animation("idle", "loophole_stand_back_reload_0");

            combat_front_loophole_stand_front_left.register_action(combat_front_loophole_stand_front_left_action);
        } // 5

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_left_transition;
            combat_front_loophole_stand_front_left_transition.m_action_from = "idle";
            combat_front_loophole_stand_front_left_transition.m_action_to = "lookout";
            combat_front_loophole_stand_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_left_transition.m_animations.push_back("loophole_stand_back_idle_0");

            combat_front_loophole_stand_front_left.register_transition(
                combat_front_loophole_stand_front_left_transition);
        } // 11

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_left_transition;
            combat_front_loophole_stand_front_left_transition.m_action_from = "lookout";
            combat_front_loophole_stand_front_left_transition.m_action_to = "idle";
            combat_front_loophole_stand_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_left_transition.m_animations.push_back("loophole_stand_back_idle_0");

            combat_front_loophole_stand_front_left.register_transition(
                combat_front_loophole_stand_front_left_transition);
        } // 12

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_left_transition;
            combat_front_loophole_stand_front_left_transition.m_action_from = "idle";
            combat_front_loophole_stand_front_left_transition.m_action_to = "fire";
            combat_front_loophole_stand_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_left_transition.m_animations.push_back("loophole_stand_back_attack_in_0");

            combat_front_loophole_stand_front_left.register_transition(
                combat_front_loophole_stand_front_left_transition);
        } // 13

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_left_transition;
            combat_front_loophole_stand_front_left_transition.m_action_from = "fire";
            combat_front_loophole_stand_front_left_transition.m_action_to = "idle";
            combat_front_loophole_stand_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_left_transition.m_animations.push_back(
                "loophole_stand_back_attack_out_0");

            combat_front_loophole_stand_front_left.register_transition(
                combat_front_loophole_stand_front_left_transition);
        } // 14

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_left_transition;
            combat_front_loophole_stand_front_left_transition.m_action_from = "idle";
            combat_front_loophole_stand_front_left_transition.m_action_to = "fire_no_lookout";
            combat_front_loophole_stand_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_left_transition.m_animations.push_back("loophole_stand_back_attack_in_0");

            combat_front_loophole_stand_front_left.register_transition(
                combat_front_loophole_stand_front_left_transition);
        } // 15

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_left_transition;
            combat_front_loophole_stand_front_left_transition.m_action_from = "fire_no_lookout";
            combat_front_loophole_stand_front_left_transition.m_action_to = "idle";
            combat_front_loophole_stand_front_left_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_left_transition.m_animations.push_back(
                "loophole_stand_back_attack_out_0");

            combat_front_loophole_stand_front_left.register_transition(
                combat_front_loophole_stand_front_left_transition);
        } // 16
#pragma endregion Cordis Loophole

#pragma region Cordis Loophole
        SmartCoverLoopholeData combat_front_loophole_stand_front_right;
        combat_front_loophole_stand_front_right.m_id = "stand_front_right";
        combat_front_loophole_stand_front_right.m_is_usable = true;
        combat_front_loophole_stand_front_right.m_is_exitable = true;
        combat_front_loophole_stand_front_right.m_is_enterable = true;
        combat_front_loophole_stand_front_right.m_fieldofview = 60.0f;
        combat_front_loophole_stand_front_right.m_fieldofview_danger = 90.0f;
        combat_front_loophole_stand_front_right.m_range = 50.0f;
        combat_front_loophole_stand_front_right.m_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.7f);
        combat_front_loophole_stand_front_right.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_loophole_stand_front_right.m_danger_fieldofview_direction = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_loophole_stand_front_right.m_enter_direction = Fvector().set(-1.0f, 0.0f, 0.0f);

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_right_action;
            combat_front_loophole_stand_front_right_action.m_id = "idle";
            combat_front_loophole_stand_front_right_action.register_animation("idle", "loophole_stand_back_idle_0");

            combat_front_loophole_stand_front_right.register_action(combat_front_loophole_stand_front_right_action);
        } // 1

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_right_action;
            combat_front_loophole_stand_front_right_action.m_id = "lookout";
            combat_front_loophole_stand_front_right_action.register_animation("idle", "loophole_stand_back_idle_0");

            combat_front_loophole_stand_front_right.register_action(combat_front_loophole_stand_front_right_action);
        } // 2

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_right_action;
            combat_front_loophole_stand_front_right_action.m_id = "fire";
            combat_front_loophole_stand_front_right_action.register_animation(
                "idle", "loophole_stand_back_attack_idle_0");
            combat_front_loophole_stand_front_right_action.register_animation(
                "shoot", "loophole_stand_back_attack_shoot_0");
            combat_front_loophole_stand_front_right_action.register_animation(
                "shoot", "loophole_stand_back_attack_shoot_1");

            combat_front_loophole_stand_front_right.register_action(combat_front_loophole_stand_front_right_action);
        } // 3

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_right_action;
            combat_front_loophole_stand_front_right_action.m_id = "fire_no_lookout";
            combat_front_loophole_stand_front_right_action.register_animation(
                "idle", "loophole_stand_back_attack_idle_0");
            combat_front_loophole_stand_front_right_action.register_animation(
                "shoot", "loophole_stand_back_attack_shoot_0");
            combat_front_loophole_stand_front_right_action.register_animation(
                "shoot", "loophole_stand_back_attack_shoot_1");

            combat_front_loophole_stand_front_right.register_action(combat_front_loophole_stand_front_right_action);
        } // 4

        {
            SmartCoverLoopholeData::SmartCoverActionsData combat_front_loophole_stand_front_right_action;
            combat_front_loophole_stand_front_right_action.m_id = "reload";
            combat_front_loophole_stand_front_right_action.register_animation("idle", "loophole_stand_back_reload_0");

            combat_front_loophole_stand_front_right.register_action(combat_front_loophole_stand_front_right_action);
        } // 5

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_right_transition;
            combat_front_loophole_stand_front_right_transition.m_action_from = "idle";
            combat_front_loophole_stand_front_right_transition.m_action_to = "lookout";
            combat_front_loophole_stand_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_right_transition.m_animations.push_back("loophole_stand_back_idle_0");

            combat_front_loophole_stand_front_right.register_transition(
                combat_front_loophole_stand_front_right_transition);
        } // 11

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_right_transition;
            combat_front_loophole_stand_front_right_transition.m_action_from = "lookout";
            combat_front_loophole_stand_front_right_transition.m_action_to = "idle";
            combat_front_loophole_stand_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_right_transition.m_animations.push_back("loophole_stand_back_idle_0");

            combat_front_loophole_stand_front_right.register_transition(
                combat_front_loophole_stand_front_right_transition);
        } // 12

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_right_transition;
            combat_front_loophole_stand_front_right_transition.m_action_from = "idle";
            combat_front_loophole_stand_front_right_transition.m_action_to = "fire";
            combat_front_loophole_stand_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_right_transition.m_animations.push_back(
                "loophole_stand_back_attack_in_0");

            combat_front_loophole_stand_front_right.register_transition(
                combat_front_loophole_stand_front_right_transition);
        } // 13

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_right_transition;
            combat_front_loophole_stand_front_right_transition.m_action_from = "fire";
            combat_front_loophole_stand_front_right_transition.m_action_to = "idle";
            combat_front_loophole_stand_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_right_transition.m_animations.push_back(
                "loophole_stand_back_attack_out_0");

            combat_front_loophole_stand_front_right.register_transition(
                combat_front_loophole_stand_front_right_transition);
        } // 14

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_right_transition;
            combat_front_loophole_stand_front_right_transition.m_action_from = "idle";
            combat_front_loophole_stand_front_right_transition.m_action_to = "fire_no_lookout";
            combat_front_loophole_stand_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_right_transition.m_animations.push_back(
                "loophole_stand_back_attack_in_0");

            combat_front_loophole_stand_front_right.register_transition(
                combat_front_loophole_stand_front_right_transition);
        } // 15

        {
            SmartCoverLoopholeData::SmartCoverTransitionsData combat_front_loophole_stand_front_right_transition;
            combat_front_loophole_stand_front_right_transition.m_action_from = "fire_no_lookout";
            combat_front_loophole_stand_front_right_transition.m_action_to = "idle";
            combat_front_loophole_stand_front_right_transition.m_weight = 1.2f;
            combat_front_loophole_stand_front_right_transition.m_animations.push_back(
                "loophole_stand_back_attack_out_0");

            combat_front_loophole_stand_front_right.register_transition(
                combat_front_loophole_stand_front_right_transition);
        } // 16

#pragma endregion Cordis Loophole

#pragma region Cordis Transition
        SmartCoverData::SmartCoverTransitionsData combat_front_transition1;
        combat_front_transition1.m_vertex0 = "";
        combat_front_transition1.m_vertex1 = "crouch_front_left";
        combat_front_transition1.m_weight = 1.0f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition1_action1;
        combat_front_transition1_action1.m_action.m_animation = "loophole_crouch_in_front_left_0";
        combat_front_transition1_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition1_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition1_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition1_action1.m_precondition_functor = "true";
        combat_front_transition1_action1.m_preconditions_params = "";

        combat_front_transition1.m_actions.push_back(combat_front_transition1_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition2;
        combat_front_transition2.m_vertex0 = "";
        combat_front_transition2.m_vertex1 = "crouch_front";
        combat_front_transition2.m_weight = 1.0f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition2_action1;
        combat_front_transition2_action1.m_action.m_animation = "loophole_crouch_in_front_0";
        combat_front_transition2_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition2_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition2_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition2_action1.m_precondition_functor = "true";
        combat_front_transition2_action1.m_preconditions_params = "";

        combat_front_transition2.m_actions.push_back(combat_front_transition2_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition3;
        combat_front_transition3.m_vertex0 = "";
        combat_front_transition3.m_vertex1 = "crouch_front_right";
        combat_front_transition3.m_weight = 1.0f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition3_action1;
        combat_front_transition3_action1.m_action.m_animation = "loophole_crouch_in_front_right_0";
        combat_front_transition3_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition3_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition3_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition3_action1.m_precondition_functor = "true";
        combat_front_transition3_action1.m_preconditions_params = "";

        combat_front_transition3.m_actions.push_back(combat_front_transition3_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition4;
        combat_front_transition4.m_vertex0 = "";
        combat_front_transition4.m_vertex1 = "stand_front_left";
        combat_front_transition4.m_weight = 1.0f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition4_action1;
        combat_front_transition4_action1.m_action.m_animation = "loophole_stand_in_front_left_0";
        combat_front_transition4_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition4_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition4_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition4_action1.m_precondition_functor = "true";
        combat_front_transition4_action1.m_preconditions_params = "";

        combat_front_transition4.m_actions.push_back(combat_front_transition4_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition5;
        combat_front_transition5.m_vertex0 = "";
        combat_front_transition5.m_vertex1 = "stand_front_right";
        combat_front_transition5.m_weight = 1.0f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition5_action1;
        combat_front_transition5_action1.m_action.m_animation = "loophole_stand_in_front_right_0";
        combat_front_transition5_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition5_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition5_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition5_action1.m_precondition_functor = "true";
        combat_front_transition5_action1.m_preconditions_params = "";

        combat_front_transition5.m_actions.push_back(combat_front_transition5_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition6;
        combat_front_transition6.m_vertex0 = "crouch_front";
        combat_front_transition6.m_vertex1 = "crouch_front_left";
        combat_front_transition6.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition6_action1;
        combat_front_transition6_action1.m_action.m_animation = "crouch_front_to_crouch_front_left";
        combat_front_transition6_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition6_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition6_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition6_action1.m_precondition_functor = "true";
        combat_front_transition6_action1.m_preconditions_params = "";

        combat_front_transition6.m_actions.push_back(combat_front_transition6_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition7;
        combat_front_transition7.m_vertex0 = "crouch_front";
        combat_front_transition7.m_vertex1 = "crouch_front_right";
        combat_front_transition7.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition7_action1;
        combat_front_transition7_action1.m_action.m_animation = "crouch_front_to_crouch_front_right";
        combat_front_transition7_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition7_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition7_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition7_action1.m_precondition_functor = "true";
        combat_front_transition7_action1.m_preconditions_params = "";

        combat_front_transition7.m_actions.push_back(combat_front_transition7_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition8;
        combat_front_transition8.m_vertex0 = "crouch_front";
        combat_front_transition8.m_vertex1 = "stand_front_left";
        combat_front_transition8.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition8_action1;
        combat_front_transition8_action1.m_action.m_animation = "crouch_front_to_stand_front_left";
        combat_front_transition8_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition8_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition8_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition8_action1.m_precondition_functor = "true";
        combat_front_transition8_action1.m_preconditions_params = "";

        combat_front_transition8.m_actions.push_back(combat_front_transition8_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition9;
        combat_front_transition9.m_vertex0 = "crouch_front";
        combat_front_transition9.m_vertex1 = "stand_front_right";
        combat_front_transition9.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition9_action1;
        combat_front_transition9_action1.m_action.m_animation = "crouch_front_to_stand_front_right";
        combat_front_transition9_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition9_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition9_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition9_action1.m_precondition_functor = "true";
        combat_front_transition9_action1.m_preconditions_params = "";

        combat_front_transition9.m_actions.push_back(combat_front_transition9_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition10;
        combat_front_transition10.m_vertex0 = "crouch_front_right";
        combat_front_transition10.m_vertex1 = "crouch_front";
        combat_front_transition10.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition10_action1;
        combat_front_transition10_action1.m_action.m_animation = "crouch_front_right_to_crouch_front";
        combat_front_transition10_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition10_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition10_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition10_action1.m_precondition_functor = "true";
        combat_front_transition10_action1.m_preconditions_params = "";

        combat_front_transition10.m_actions.push_back(combat_front_transition10_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition11;
        combat_front_transition11.m_vertex0 = "crouch_front_right";
        combat_front_transition11.m_vertex1 = "crouch_front_left";
        combat_front_transition11.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition11_action1;
        combat_front_transition11_action1.m_action.m_animation = "crouch_front_right_to_crouch_front_left";
        combat_front_transition11_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition11_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition11_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition11_action1.m_precondition_functor = "true";
        combat_front_transition11_action1.m_preconditions_params = "";

        combat_front_transition11.m_actions.push_back(combat_front_transition11_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition12;
        combat_front_transition12.m_vertex0 = "crouch_front_right";
        combat_front_transition12.m_vertex1 = "stand_front_left";
        combat_front_transition12.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition12_action1;
        combat_front_transition12_action1.m_action.m_animation = "crouch_front_right_to_stand_front_left";
        combat_front_transition12_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition12_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition12_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition12_action1.m_precondition_functor = "true";
        combat_front_transition12_action1.m_preconditions_params = "";

        combat_front_transition12.m_actions.push_back(combat_front_transition12_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition13;
        combat_front_transition13.m_vertex0 = "crouch_front_right";
        combat_front_transition13.m_vertex1 = "stand_front_right";
        combat_front_transition13.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition13_action1;
        combat_front_transition13_action1.m_action.m_animation = "crouch_front_right_to_stand_front_right";
        combat_front_transition13_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition13_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition13_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition13_action1.m_precondition_functor = "true";
        combat_front_transition13_action1.m_preconditions_params = "";

        combat_front_transition13.m_actions.push_back(combat_front_transition13_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition14;
        combat_front_transition14.m_vertex0 = "crouch_front_left";
        combat_front_transition14.m_vertex1 = "crouch_front";
        combat_front_transition14.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition14_action1;
        combat_front_transition14_action1.m_action.m_animation = "crouch_front_left_to_crouch_front";
        combat_front_transition14_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition14_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition14_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition14_action1.m_precondition_functor = "true";
        combat_front_transition14_action1.m_preconditions_params = "";

        combat_front_transition14.m_actions.push_back(combat_front_transition14_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition15;
        combat_front_transition15.m_vertex0 = "crouch_front_left";
        combat_front_transition15.m_vertex1 = "crouch_front_right";
        combat_front_transition15.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition15_action1;
        combat_front_transition15_action1.m_action.m_animation = "crouch_front_left_to_crouch_front_right";
        combat_front_transition15_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition15_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition15_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition15_action1.m_precondition_functor = "true";
        combat_front_transition15_action1.m_preconditions_params = "";

        combat_front_transition15.m_actions.push_back(combat_front_transition15_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition16;
        combat_front_transition16.m_vertex0 = "crouch_front_left";
        combat_front_transition16.m_vertex1 = "stand_front_left";
        combat_front_transition16.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition16_action1;
        combat_front_transition16_action1.m_action.m_animation = "crouch_front_left_to_stand_front_left";
        combat_front_transition16_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition16_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition16_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition16_action1.m_precondition_functor = "true";
        combat_front_transition16_action1.m_preconditions_params = "";

        combat_front_transition16.m_actions.push_back(combat_front_transition16_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition17;
        combat_front_transition17.m_vertex0 = "crouch_front_left";
        combat_front_transition17.m_vertex1 = "stand_front_right";
        combat_front_transition17.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition17_action1;
        combat_front_transition17_action1.m_action.m_animation = "crouch_front_left_to_stand_front_right";
        combat_front_transition17_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition17_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition17_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition17_action1.m_precondition_functor = "true";
        combat_front_transition17_action1.m_preconditions_params = "";

        combat_front_transition17.m_actions.push_back(combat_front_transition17_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition18;
        combat_front_transition18.m_vertex0 = "stand_front_left";
        combat_front_transition18.m_vertex1 = "crouch_front";
        combat_front_transition18.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition18_action1;
        combat_front_transition18_action1.m_action.m_animation = "stand_front_left_to_crouch_front";
        combat_front_transition18_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition18_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition18_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition18_action1.m_precondition_functor = "true";
        combat_front_transition18_action1.m_preconditions_params = "";

        combat_front_transition18.m_actions.push_back(combat_front_transition18_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition19;
        combat_front_transition19.m_vertex0 = "stand_front_left";
        combat_front_transition19.m_vertex1 = "crouch_front_left";
        combat_front_transition19.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition19_action1;
        combat_front_transition19_action1.m_action.m_animation = "stand_front_left_to_crouch_front_left";
        combat_front_transition19_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition19_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition19_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition19_action1.m_precondition_functor = "true";
        combat_front_transition19_action1.m_preconditions_params = "";

        combat_front_transition19.m_actions.push_back(combat_front_transition19_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition20;
        combat_front_transition20.m_vertex0 = "stand_front_left";
        combat_front_transition20.m_vertex1 = "crouch_front_right";
        combat_front_transition20.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition20_action1;
        combat_front_transition20_action1.m_action.m_animation = "stand_front_left_to_crouch_front_right";
        combat_front_transition20_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition20_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition20_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition20_action1.m_precondition_functor = "true";
        combat_front_transition20_action1.m_preconditions_params = "";

        combat_front_transition20.m_actions.push_back(combat_front_transition20_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition21;
        combat_front_transition21.m_vertex0 = "stand_front_left";
        combat_front_transition21.m_vertex1 = "stand_front_right";
        combat_front_transition21.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition21_action1;
        combat_front_transition21_action1.m_action.m_animation = "stand_front_left_to_stand_front_right";
        combat_front_transition21_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition21_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition21_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition21_action1.m_precondition_functor = "true";
        combat_front_transition21_action1.m_preconditions_params = "";

        combat_front_transition21.m_actions.push_back(combat_front_transition21_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition22;
        combat_front_transition22.m_vertex0 = "stand_front_right";
        combat_front_transition22.m_vertex1 = "crouch_front";
        combat_front_transition22.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition22_action1;
        combat_front_transition22_action1.m_action.m_animation = "stand_front_right_to_crouch_front";
        combat_front_transition22_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition22_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition22_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition22_action1.m_precondition_functor = "true";
        combat_front_transition22_action1.m_preconditions_params = "";

        combat_front_transition22.m_actions.push_back(combat_front_transition22_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition23;
        combat_front_transition23.m_vertex0 = "stand_front_right";
        combat_front_transition23.m_vertex1 = "crouch_front_left";
        combat_front_transition23.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition23_action1;
        combat_front_transition23_action1.m_action.m_animation = "stand_front_right_to_crouch_front_left";
        combat_front_transition23_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition23_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition23_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition23_action1.m_precondition_functor = "true";
        combat_front_transition23_action1.m_preconditions_params = "";

        combat_front_transition23.m_actions.push_back(combat_front_transition23_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition24;
        combat_front_transition24.m_vertex0 = "stand_front_right";
        combat_front_transition24.m_vertex1 = "crouch_front_right";
        combat_front_transition24.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition24_action1;
        combat_front_transition24_action1.m_action.m_animation = "stand_front_right_to_crouch_front_right";
        combat_front_transition24_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition24_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition24_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition24_action1.m_precondition_functor = "true";
        combat_front_transition24_action1.m_preconditions_params = "";

        combat_front_transition24.m_actions.push_back(combat_front_transition24_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition25;
        combat_front_transition25.m_vertex0 = "stand_front_right";
        combat_front_transition25.m_vertex1 = "stand_front_left";
        combat_front_transition25.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition25_action1;
        combat_front_transition25_action1.m_action.m_animation = "stand_front_right_to_stand_front_left";
        combat_front_transition25_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition25_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition25_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition25_action1.m_precondition_functor = "true";
        combat_front_transition25_action1.m_preconditions_params = "";

        combat_front_transition25.m_actions.push_back(combat_front_transition25_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition26;
        combat_front_transition26.m_vertex0 = "crouch_front_left";
        combat_front_transition26.m_vertex1 = "";
        combat_front_transition26.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition26_action1;
        combat_front_transition26_action1.m_action.m_animation = "";
        combat_front_transition26_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition26_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition26_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition26_action1.m_precondition_functor = "true";
        combat_front_transition26_action1.m_preconditions_params = "";

        combat_front_transition26.m_actions.push_back(combat_front_transition26_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition27;
        combat_front_transition27.m_vertex0 = "crouch_front";
        combat_front_transition27.m_vertex1 = "";
        combat_front_transition27.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition27_action1;
        combat_front_transition27_action1.m_action.m_animation = "";
        combat_front_transition27_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition27_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition27_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition27_action1.m_precondition_functor = "true";
        combat_front_transition27_action1.m_preconditions_params = "";

        combat_front_transition27.m_actions.push_back(combat_front_transition27_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition28;
        combat_front_transition28.m_vertex0 = "crouch_front_right";
        combat_front_transition28.m_vertex1 = "";
        combat_front_transition28.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition28_action1;
        combat_front_transition28_action1.m_action.m_animation = "";
        combat_front_transition28_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition28_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition28_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition28_action1.m_precondition_functor = "true";
        combat_front_transition28_action1.m_preconditions_params = "";

        combat_front_transition28.m_actions.push_back(combat_front_transition28_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition29;
        combat_front_transition29.m_vertex0 = "stand_front_left";
        combat_front_transition29.m_vertex1 = "";
        combat_front_transition29.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition29_action1;
        combat_front_transition29_action1.m_action.m_animation = "";
        combat_front_transition29_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition29_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition29_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition29_action1.m_precondition_functor = "true";
        combat_front_transition29_action1.m_preconditions_params = "";

        combat_front_transition29.m_actions.push_back(combat_front_transition29_action1);

        SmartCoverData::SmartCoverTransitionsData combat_front_transition30;
        combat_front_transition30.m_vertex0 = "stand_front_right";
        combat_front_transition30.m_vertex1 = "";
        combat_front_transition30.m_weight = 1.1f;
        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData combat_front_transition30_action1;
        combat_front_transition30_action1.m_action.m_animation = "";
        combat_front_transition30_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        combat_front_transition30_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        combat_front_transition30_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        combat_front_transition30_action1.m_precondition_functor = "true";
        combat_front_transition30_action1.m_preconditions_params = "";

        combat_front_transition30.m_actions.push_back(combat_front_transition30_action1);
#pragma endregion

        combat_front_smartcover.setNeedWeapon(true);
        combat_front_smartcover.register_loophole(combat_front_loophole_crouch_front_left);
        combat_front_smartcover.register_loophole(combat_front_loophole_crouch_front);
        combat_front_smartcover.register_loophole(combat_front_loophole_crouch_front_right);
        combat_front_smartcover.register_loophole(combat_front_loophole_stand_front_left);
        combat_front_smartcover.register_loophole(combat_front_loophole_stand_front_right);
        combat_front_smartcover.register_transition(combat_front_transition1);
        combat_front_smartcover.register_transition(combat_front_transition2);
        combat_front_smartcover.register_transition(combat_front_transition3);
        combat_front_smartcover.register_transition(combat_front_transition4);
        combat_front_smartcover.register_transition(combat_front_transition5);
        combat_front_smartcover.register_transition(combat_front_transition6);
        combat_front_smartcover.register_transition(combat_front_transition7);
        combat_front_smartcover.register_transition(combat_front_transition8);
        combat_front_smartcover.register_transition(combat_front_transition9);
        combat_front_smartcover.register_transition(combat_front_transition10);
        combat_front_smartcover.register_transition(combat_front_transition11);
        combat_front_smartcover.register_transition(combat_front_transition12);
        combat_front_smartcover.register_transition(combat_front_transition13);
        combat_front_smartcover.register_transition(combat_front_transition14);
        combat_front_smartcover.register_transition(combat_front_transition15);
        combat_front_smartcover.register_transition(combat_front_transition16);
        combat_front_smartcover.register_transition(combat_front_transition17);
        combat_front_smartcover.register_transition(combat_front_transition18);
        combat_front_smartcover.register_transition(combat_front_transition19);
        combat_front_smartcover.register_transition(combat_front_transition20);
        combat_front_smartcover.register_transition(combat_front_transition21);
        combat_front_smartcover.register_transition(combat_front_transition22);
        combat_front_smartcover.register_transition(combat_front_transition23);
        combat_front_smartcover.register_transition(combat_front_transition24);
        combat_front_smartcover.register_transition(combat_front_transition25);
        combat_front_smartcover.register_transition(combat_front_transition26);
        combat_front_smartcover.register_transition(combat_front_transition27);
        combat_front_smartcover.register_transition(combat_front_transition28);
        combat_front_smartcover.register_transition(combat_front_transition29);
        combat_front_smartcover.register_transition(combat_front_transition30);
        this->m_registered_smartcovers["combat_front"] = combat_front_smartcover;
#pragma endregion Cordis Combat Front Smart Cover

#pragma region Cordis Animpoint Stay Wall Smart Cover Initialization
        SmartCoverData animpoint_stay_wall_smartcover;
        SmartCoverLoopholeData animpoint_stay_wall_loophole;

#pragma region Cordis Loophole
        animpoint_stay_wall_loophole.m_id = "animpoint_stay_wall";
        animpoint_stay_wall_loophole.m_is_usable = true;
        animpoint_stay_wall_loophole.m_is_exitable = false;
        animpoint_stay_wall_loophole.m_is_enterable = false;
        animpoint_stay_wall_loophole.m_fieldofview = 45.0f;
        animpoint_stay_wall_loophole.m_fieldofview_danger = 45.0f;
        animpoint_stay_wall_loophole.m_range = 70.0f;
        animpoint_stay_wall_loophole.m_fieldofview_direction = Fvector().set(0.0f, 0.0f, -1.0f);
        animpoint_stay_wall_loophole.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_stay_wall_loophole.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        animpoint_stay_wall_loophole.m_enter_direction = Fvector().set(0.0f, 0.0f, -1.0f);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_wall_loophole_action1;
        animpoint_stay_wall_loophole_action1.m_id = "idle";
        animpoint_stay_wall_loophole_action1.register_animation("idle", "animpoint_stay_wall_idle_1");

        animpoint_stay_wall_loophole.register_action(animpoint_stay_wall_loophole_action1);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_wall_loophole_action2;
        animpoint_stay_wall_loophole_action2.m_id = "lookout";
        animpoint_stay_wall_loophole_action2.register_animation("idle", "animpoint_stay_wall_idle_1");

        animpoint_stay_wall_loophole.register_action(animpoint_stay_wall_loophole_action2);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_wall_loophole_action3;
        animpoint_stay_wall_loophole_action3.m_id = "fire";
        animpoint_stay_wall_loophole_action3.register_animation("idle", "animpoint_stay_wall_idle_1");
        animpoint_stay_wall_loophole_action3.register_animation("shoot", "animpoint_stay_wall_idle_1");

        animpoint_stay_wall_loophole.register_action(animpoint_stay_wall_loophole_action3);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_wall_loophole_action4;
        animpoint_stay_wall_loophole_action4.m_id = "fire_no_lookout";
        animpoint_stay_wall_loophole_action4.register_animation("idle", "animpoint_stay_wall_idle_1");
        animpoint_stay_wall_loophole_action4.register_animation("shoot", "animpoint_stay_wall_idle_1");

        animpoint_stay_wall_loophole.register_action(animpoint_stay_wall_loophole_action4);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_wall_loophole_action5;
        animpoint_stay_wall_loophole_action5.m_id = "reload";
        animpoint_stay_wall_loophole_action5.register_animation("idle", "animpoint_stay_wall_idle_1");

        animpoint_stay_wall_loophole.register_action(animpoint_stay_wall_loophole_action5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_wall_loophole_transition1;
        animpoint_stay_wall_loophole_transition1.m_action_from = "idle";
        animpoint_stay_wall_loophole_transition1.m_action_to = "lookout";
        animpoint_stay_wall_loophole_transition1.m_animations.push_back("animpoint_stay_wall_in_1");
        animpoint_stay_wall_loophole_transition1.m_weight = 1.2f;

        animpoint_stay_wall_loophole.register_transition(animpoint_stay_wall_loophole_transition1);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_wall_loophole_transition2;
        animpoint_stay_wall_loophole_transition2.m_action_from = "lookout";
        animpoint_stay_wall_loophole_transition2.m_action_to = "idle";
        animpoint_stay_wall_loophole_transition2.m_animations.push_back("animpoint_stay_wall_in_1");
        animpoint_stay_wall_loophole_transition2.m_weight = 1.2f;

        animpoint_stay_wall_loophole.register_transition(animpoint_stay_wall_loophole_transition2);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_wall_loophole_transition3;
        animpoint_stay_wall_loophole_transition3.m_action_from = "idle";
        animpoint_stay_wall_loophole_transition3.m_action_to = "fire";
        animpoint_stay_wall_loophole_transition3.m_animations.push_back("animpoint_stay_wall_in_1");
        animpoint_stay_wall_loophole_transition3.m_weight = 1.2f;

        animpoint_stay_wall_loophole.register_transition(animpoint_stay_wall_loophole_transition3);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_wall_loophole_transition4;
        animpoint_stay_wall_loophole_transition4.m_action_from = "fire";
        animpoint_stay_wall_loophole_transition4.m_action_to = "idle";
        animpoint_stay_wall_loophole_transition4.m_animations.push_back("animpoint_stay_wall_in_1");
        animpoint_stay_wall_loophole_transition4.m_weight = 1.2f;

        animpoint_stay_wall_loophole.register_transition(animpoint_stay_wall_loophole_transition4);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_wall_loophole_transition5;
        animpoint_stay_wall_loophole_transition5.m_action_from = "idle";
        animpoint_stay_wall_loophole_transition5.m_action_to = "fire_no_lookout";
        animpoint_stay_wall_loophole_transition5.m_animations.push_back("animpoint_stay_wall_in_1");
        animpoint_stay_wall_loophole_transition5.m_weight = 1.2f;

        animpoint_stay_wall_loophole.register_transition(animpoint_stay_wall_loophole_transition5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_wall_loophole_transition6;
        animpoint_stay_wall_loophole_transition6.m_action_from = "fire_no_lookout";
        animpoint_stay_wall_loophole_transition6.m_action_to = "idle";
        animpoint_stay_wall_loophole_transition6.m_animations.push_back("animpoint_stay_wall_in_1");
        animpoint_stay_wall_loophole_transition6.m_weight = 1.2f;

        animpoint_stay_wall_loophole.register_transition(animpoint_stay_wall_loophole_transition6);

#pragma endregion

#pragma region Cordis Transition
        SmartCoverData::SmartCoverTransitionsData animpoint_stay_wall_transition;
        animpoint_stay_wall_transition.m_vertex0 = "";
        animpoint_stay_wall_transition.m_vertex1 = "animpoint_stay_wall";
        animpoint_stay_wall_transition.m_weight = 1.0f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_stay_wall_transition_action1;
        animpoint_stay_wall_transition_action1.m_action.m_animation = "animpoint_stay_wall_in_1";
        animpoint_stay_wall_transition_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_stay_wall_transition_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        animpoint_stay_wall_transition_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_stay_wall_transition_action1.m_precondition_functor = "true";
        animpoint_stay_wall_transition_action1.m_preconditions_params = "";

        animpoint_stay_wall_transition.m_actions.push_back(animpoint_stay_wall_transition_action1);

        /*
                SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_stay_wall_transition_action2;
                animpoint_stay_wall_transition_action2.m_action.m_animation = "animpoint_stay_wall_out_1";
                animpoint_stay_wall_transition_action2.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
                animpoint_stay_wall_transition_action2.m_action.m_body_state = MonsterSpace::eBodyStateStand;
                animpoint_stay_wall_transition_action2.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
                animpoint_stay_wall_transition_action2.m_precondition_functor = "true";
                animpoint_stay_wall_transition_action2.m_preconditions_params = "";

                animpoint_stay_wall_transition.m_actions.push_back(animpoint_stay_wall_transition_action2);
                */

        SmartCoverData::SmartCoverTransitionsData animpoint_stay_wall_transition1;
        animpoint_stay_wall_transition1.m_vertex0 = "animpoint_stay_wall";
        animpoint_stay_wall_transition1.m_vertex1 = "";
        animpoint_stay_wall_transition1.m_weight = 1.1f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_stay_wall_transition1_action1;
        animpoint_stay_wall_transition1_action1.m_action.m_animation = "animpoint_stay_wall_out_1";
        animpoint_stay_wall_transition1_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_stay_wall_transition1_action1.m_action.m_body_state = MonsterSpace::eBodyStateStand;
        animpoint_stay_wall_transition1_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_stay_wall_transition1_action1.m_precondition_functor = "true";
        animpoint_stay_wall_transition1_action1.m_preconditions_params = "";

        animpoint_stay_wall_transition1.m_actions.push_back(animpoint_stay_wall_transition1_action1);
#pragma endregion

        animpoint_stay_wall_smartcover.setNeedWeapon(false);
        animpoint_stay_wall_smartcover.register_loophole(animpoint_stay_wall_loophole);
        animpoint_stay_wall_smartcover.register_transition(animpoint_stay_wall_transition);
        animpoint_stay_wall_smartcover.register_transition(animpoint_stay_wall_transition1);
        this->m_registered_smartcovers["animpoint_stay_wall"] = animpoint_stay_wall_smartcover;
#pragma endregion

#pragma region Cordis Animpoint Stay Table Smart Cover
        SmartCoverData animpoint_stay_table_smartcover;
        SmartCoverLoopholeData animpoint_stay_table_loophole;

#pragma region Cordis Loophole
        animpoint_stay_table_loophole.m_id = "animpoint_stay_table";
        animpoint_stay_table_loophole.m_is_usable = true;
        animpoint_stay_table_loophole.m_is_exitable = true;
        animpoint_stay_table_loophole.m_is_enterable = true;
        animpoint_stay_table_loophole.m_fieldofview = 45.0f;
        animpoint_stay_table_loophole.m_fieldofview_danger = 45.0f;
        animpoint_stay_table_loophole.m_range = 70.0f;
        animpoint_stay_table_loophole.m_fieldofview_direction = Fvector().set(0.0f, 0.0f, -1.0f);
        animpoint_stay_table_loophole.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_stay_table_loophole.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        animpoint_stay_table_loophole.m_enter_direction = Fvector().set(0.0f, 0.0f, -1.0f);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_table_loophole_action1;
        animpoint_stay_table_loophole_action1.m_id = "idle";
        animpoint_stay_table_loophole_action1.register_animation("idle", "animpoint_stay_table_idle_1");

        animpoint_stay_table_loophole.register_action(animpoint_stay_table_loophole_action1);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_table_loophole_action2;
        animpoint_stay_table_loophole_action2.m_id = "lookout";
        animpoint_stay_table_loophole_action2.register_animation("idle", "animpoint_stay_table_idle_1");

        animpoint_stay_table_loophole.register_action(animpoint_stay_table_loophole_action2);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_table_loophole_action3;
        animpoint_stay_table_loophole_action3.m_id = "fire";
        animpoint_stay_table_loophole_action3.register_animation("idle", "animpoint_stay_table_idle_1");
        animpoint_stay_table_loophole_action3.register_animation("shoot", "animpoint_stay_table_idle_1");

        animpoint_stay_table_loophole.register_action(animpoint_stay_table_loophole_action3);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_table_loophole_action4;
        animpoint_stay_table_loophole_action4.m_id = "fire_no_lookout";
        animpoint_stay_table_loophole_action4.register_animation("idle", "animpoint_stay_table_idle_1");
        animpoint_stay_table_loophole_action4.register_animation("shoot", "animpoint_stay_table_idle_1");

        animpoint_stay_table_loophole.register_action(animpoint_stay_table_loophole_action4);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_stay_table_loophole_action5;
        animpoint_stay_table_loophole_action5.m_id = "reload";
        animpoint_stay_table_loophole_action5.register_animation("idle", "animpoint_stay_table_idle_1");

        animpoint_stay_table_loophole.register_action(animpoint_stay_table_loophole_action5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_table_loophole_transition1;
        animpoint_stay_table_loophole_transition1.m_action_from = "idle";
        animpoint_stay_table_loophole_transition1.m_action_to = "lookout";
        animpoint_stay_table_loophole_transition1.m_animations.push_back("animpoint_stay_table_in_1");
        animpoint_stay_table_loophole_transition1.m_weight = 1.2f;

        animpoint_stay_table_loophole.register_transition(animpoint_stay_table_loophole_transition1);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_table_loophole_transition2;
        animpoint_stay_table_loophole_transition2.m_action_from = "lookout";
        animpoint_stay_table_loophole_transition2.m_action_to = "idle";
        animpoint_stay_table_loophole_transition2.m_animations.push_back("animpoint_stay_table_in_1");
        animpoint_stay_table_loophole_transition2.m_weight = 1.2f;

        animpoint_stay_table_loophole.register_transition(animpoint_stay_table_loophole_transition2);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_table_loophole_transition3;
        animpoint_stay_table_loophole_transition3.m_action_from = "idle";
        animpoint_stay_table_loophole_transition3.m_action_to = "fire";
        animpoint_stay_table_loophole_transition3.m_animations.push_back("animpoint_stay_table_in_1");
        animpoint_stay_table_loophole_transition3.m_weight = 1.2f;

        animpoint_stay_table_loophole.register_transition(animpoint_stay_table_loophole_transition3);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_table_loophole_transition4;
        animpoint_stay_table_loophole_transition4.m_action_from = "fire";
        animpoint_stay_table_loophole_transition4.m_action_to = "idle";
        animpoint_stay_table_loophole_transition4.m_animations.push_back("animpoint_stay_table_in_1");
        animpoint_stay_table_loophole_transition4.m_weight = 1.2f;

        animpoint_stay_table_loophole.register_transition(animpoint_stay_table_loophole_transition4);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_table_loophole_transition5;
        animpoint_stay_table_loophole_transition5.m_action_from = "idle";
        animpoint_stay_table_loophole_transition5.m_action_to = "fire_no_lookout";
        animpoint_stay_table_loophole_transition5.m_animations.push_back("animpoint_stay_table_in_1");
        animpoint_stay_table_loophole_transition5.m_weight = 1.2f;

        animpoint_stay_table_loophole.register_transition(animpoint_stay_table_loophole_transition5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_stay_table_loophole_transition6;
        animpoint_stay_table_loophole_transition6.m_action_from = "fire_no_lookout";
        animpoint_stay_table_loophole_transition6.m_action_to = "idle";
        animpoint_stay_table_loophole_transition6.m_animations.push_back("animpoint_stay_table_in_1");
        animpoint_stay_table_loophole_transition6.m_weight = 1.2f;

        animpoint_stay_table_loophole.register_transition(animpoint_stay_table_loophole_transition6);
#pragma endregion

#pragma region Cordis Transition
        SmartCoverData::SmartCoverTransitionsData animpoint_stay_table_transition;
        animpoint_stay_table_transition.m_vertex0 = "";
        animpoint_stay_table_transition.m_vertex1 = "animpoint_stay_table";
        animpoint_stay_table_transition.m_weight = 1.0f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_stay_table_transition_action1;
        animpoint_stay_table_transition_action1.m_action.m_animation = "animpoint_stay_table_in_1";
        animpoint_stay_table_transition_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_stay_table_transition_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        animpoint_stay_table_transition_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_stay_table_transition_action1.m_precondition_functor = "true";
        animpoint_stay_table_transition_action1.m_preconditions_params = "";

        animpoint_stay_table_transition.m_actions.push_back(animpoint_stay_table_transition_action1);

        SmartCoverData::SmartCoverTransitionsData animpoint_stay_table_transition1;
        animpoint_stay_table_transition1.m_vertex0 = "animpoint_stay_table";
        animpoint_stay_table_transition1.m_vertex1 = "";
        animpoint_stay_table_transition1.m_weight = 1.1f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_stay_table_transition1_action1;
        animpoint_stay_table_transition1_action1.m_action.m_animation = "animpoint_stay_table_out_1";
        animpoint_stay_table_transition1_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_stay_table_transition1_action1.m_action.m_body_state = MonsterSpace::eBodyStateStand;
        animpoint_stay_table_transition1_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_stay_table_transition1_action1.m_precondition_functor = "true";
        animpoint_stay_table_transition1_action1.m_preconditions_params = "";

        animpoint_stay_table_transition1.m_actions.push_back(animpoint_stay_table_transition1_action1);
#pragma endregion

        animpoint_stay_table_smartcover.setNeedWeapon(false);
        animpoint_stay_table_smartcover.register_loophole(animpoint_stay_table_loophole);
        animpoint_stay_table_smartcover.register_transition(animpoint_stay_table_transition);
        animpoint_stay_table_smartcover.register_transition(animpoint_stay_table_transition1);
        this->m_registered_smartcovers["animpoint_stay_table"] = animpoint_stay_table_smartcover;
#pragma endregion

#pragma region Cordis Animpoint Sit High Smart Cover
        SmartCoverData animpoint_sit_high_smartcover;
        SmartCoverLoopholeData animpoint_sit_high_loophole;

#pragma region Cordis Loophole
        animpoint_sit_high_loophole.m_id = "animpoint_sit_high";
        animpoint_sit_high_loophole.m_is_usable = true;
        animpoint_sit_high_loophole.m_is_exitable = false;
        animpoint_sit_high_loophole.m_is_enterable = false;
        animpoint_sit_high_loophole.m_fieldofview = 45.0f;
        animpoint_sit_high_loophole.m_fieldofview_danger = 45.0f;
        animpoint_sit_high_loophole.m_range = 70.0f;
        animpoint_sit_high_loophole.m_fieldofview_direction = Fvector().set(0.0f, 0.0f, -1.0f);
        animpoint_sit_high_loophole.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_sit_high_loophole.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        animpoint_sit_high_loophole.m_enter_direction = Fvector().set(0.0f, 0.0f, -1.0f);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_high_loophole_action1;
        animpoint_sit_high_loophole_action1.m_id = "idle";
        animpoint_sit_high_loophole_action1.register_animation("idle", "animpoint_sit_high_idle_1");

        animpoint_sit_high_loophole.register_action(animpoint_sit_high_loophole_action1);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_high_loophole_action2;
        animpoint_sit_high_loophole_action2.m_id = "lookout";
        animpoint_sit_high_loophole_action2.register_animation("idle", "animpoint_sit_high_idle_1");

        animpoint_sit_high_loophole.register_action(animpoint_sit_high_loophole_action2);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_high_loophole_action3;
        animpoint_sit_high_loophole_action3.m_id = "fire";
        animpoint_sit_high_loophole_action3.register_animation("idle", "animpoint_sit_high_idle_1");
        animpoint_sit_high_loophole_action3.register_animation("shoot", "animpoint_sit_high_idle_1");

        animpoint_sit_high_loophole.register_action(animpoint_sit_high_loophole_action3);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_high_loophole_action4;
        animpoint_sit_high_loophole_action4.m_id = "fire_no_lookout";
        animpoint_sit_high_loophole_action4.register_animation("idle", "animpoint_sit_high_idle_1");
        animpoint_sit_high_loophole_action4.register_animation("shoot", "animpoint_sit_high_idle_1");

        animpoint_sit_high_loophole.register_action(animpoint_sit_high_loophole_action4);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_high_loophole_action5;
        animpoint_sit_high_loophole_action5.m_id = "reload";
        animpoint_sit_high_loophole_action5.register_animation("idle", "animpoint_sit_high_idle_1");

        animpoint_sit_high_loophole.register_action(animpoint_sit_high_loophole_action5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_high_loophole_transition1;
        animpoint_sit_high_loophole_transition1.m_action_from = "idle";
        animpoint_sit_high_loophole_transition1.m_action_to = "lookout";
        animpoint_sit_high_loophole_transition1.m_animations.push_back("animpoint_sit_high_in_1");
        animpoint_sit_high_loophole_transition1.m_weight = 1.2f;

        animpoint_sit_high_loophole.register_transition(animpoint_sit_high_loophole_transition1);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_high_loophole_transition2;
        animpoint_sit_high_loophole_transition2.m_action_from = "lookout";
        animpoint_sit_high_loophole_transition2.m_action_to = "idle";
        animpoint_sit_high_loophole_transition2.m_animations.push_back("animpoint_sit_high_in_1");
        animpoint_sit_high_loophole_transition2.m_weight = 1.2f;

        animpoint_sit_high_loophole.register_transition(animpoint_sit_high_loophole_transition2);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_high_loophole_transition3;
        animpoint_sit_high_loophole_transition3.m_action_from = "idle";
        animpoint_sit_high_loophole_transition3.m_action_to = "fire";
        animpoint_sit_high_loophole_transition3.m_animations.push_back("animpoint_sit_high_in_1");
        animpoint_sit_high_loophole_transition3.m_weight = 1.2f;

        animpoint_sit_high_loophole.register_transition(animpoint_sit_high_loophole_transition3);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_high_loophole_transition4;
        animpoint_sit_high_loophole_transition4.m_action_from = "fire";
        animpoint_sit_high_loophole_transition4.m_action_to = "idle";
        animpoint_sit_high_loophole_transition4.m_animations.push_back("animpoint_sit_high_in_1");
        animpoint_sit_high_loophole_transition4.m_weight = 1.2f;

        animpoint_sit_high_loophole.register_transition(animpoint_sit_high_loophole_transition4);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_high_loophole_transition5;
        animpoint_sit_high_loophole_transition5.m_action_from = "idle";
        animpoint_sit_high_loophole_transition5.m_action_to = "fire_no_lookout";
        animpoint_sit_high_loophole_transition5.m_animations.push_back("animpoint_sit_high_in_1");
        animpoint_sit_high_loophole_transition5.m_weight = 1.2f;

        animpoint_sit_high_loophole.register_transition(animpoint_sit_high_loophole_transition5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_high_loophole_transition6;
        animpoint_sit_high_loophole_transition6.m_action_from = "fire_no_lookout";
        animpoint_sit_high_loophole_transition6.m_action_to = "idle";
        animpoint_sit_high_loophole_transition6.m_animations.push_back("animpoint_sit_high_in_1");
        animpoint_sit_high_loophole_transition6.m_weight = 1.2f;

        animpoint_sit_high_loophole.register_transition(animpoint_sit_high_loophole_transition6);
#pragma endregion

#pragma region Cordis Transition
        SmartCoverData::SmartCoverTransitionsData animpoint_sit_high_transition;
        animpoint_sit_high_transition.m_vertex0 = "";
        animpoint_sit_high_transition.m_vertex1 = "animpoint_sit_high";
        animpoint_sit_high_transition.m_weight = 1.0f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_sit_high_transition_action1;
        animpoint_sit_high_transition_action1.m_action.m_animation = "animpoint_sit_high_in_1";
        animpoint_sit_high_transition_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_sit_high_transition_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        animpoint_sit_high_transition_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_sit_high_transition_action1.m_precondition_functor = "true";
        animpoint_sit_high_transition_action1.m_preconditions_params = "";

        animpoint_sit_high_transition.m_actions.push_back(animpoint_sit_high_transition_action1);

        SmartCoverData::SmartCoverTransitionsData animpoint_sit_high_transition1;
        animpoint_sit_high_transition1.m_vertex0 = "animpoint_sit_high";
        animpoint_sit_high_transition1.m_vertex1 = "";
        animpoint_sit_high_transition1.m_weight = 1.1f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_sit_high_transition1_action1;
        animpoint_sit_high_transition1_action1.m_action.m_animation = "animpoint_sit_high_out_1";
        animpoint_sit_high_transition1_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_sit_high_transition1_action1.m_action.m_body_state = MonsterSpace::eBodyStateStand;
        animpoint_sit_high_transition1_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_sit_high_transition1_action1.m_precondition_functor = "true";
        animpoint_sit_high_transition1_action1.m_preconditions_params = "";

        animpoint_sit_high_transition1.m_actions.push_back(animpoint_sit_high_transition1_action1);
#pragma endregion

        animpoint_sit_high_smartcover.setNeedWeapon(false);
        animpoint_sit_high_smartcover.register_loophole(animpoint_sit_high_loophole);
        animpoint_sit_high_smartcover.register_transition(animpoint_sit_high_transition);
        animpoint_sit_high_smartcover.register_transition(animpoint_sit_high_transition1);
        this->m_registered_smartcovers["animpoint_sit_high"] = animpoint_sit_high_smartcover;
#pragma endregion

#pragma region Cordis Animpoint Sit Normal
        SmartCoverData animpoint_sit_normal_smartcover;
        SmartCoverLoopholeData animpoint_sit_normal_loophole;

#pragma region Cordis Loophole
        animpoint_sit_normal_loophole.m_id = "animpoint_sit_normal";
        animpoint_sit_normal_loophole.m_is_usable = true;
        animpoint_sit_normal_loophole.m_is_exitable = false;
        animpoint_sit_normal_loophole.m_is_enterable = false;
        animpoint_sit_normal_loophole.m_fieldofview = 45.0f;
        animpoint_sit_normal_loophole.m_fieldofview_danger = 45.0f;
        animpoint_sit_normal_loophole.m_range = 70.0f;
        animpoint_sit_normal_loophole.m_fieldofview_direction = Fvector().set(0.0f, 0.0f, -1.0f);
        animpoint_sit_normal_loophole.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_sit_normal_loophole.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        animpoint_sit_normal_loophole.m_enter_direction = Fvector().set(0.0f, 0.0f, -1.0f);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_normal_loophole_action1;
        animpoint_sit_normal_loophole_action1.m_id = "idle";
        animpoint_sit_normal_loophole_action1.register_animation("idle", "animpoint_sit_normal_idle_1");

        animpoint_sit_normal_loophole.register_action(animpoint_sit_normal_loophole_action1);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_normal_loophole_action2;
        animpoint_sit_normal_loophole_action2.m_id = "lookout";
        animpoint_sit_normal_loophole_action2.register_animation("idle", "animpoint_sit_normal_idle_1");

        animpoint_sit_normal_loophole.register_action(animpoint_sit_normal_loophole_action2);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_normal_loophole_action3;
        animpoint_sit_normal_loophole_action3.m_id = "fire";
        animpoint_sit_normal_loophole_action3.register_animation("idle", "animpoint_sit_normal_idle_1");
        animpoint_sit_normal_loophole_action3.register_animation("shoot", "animpoint_sit_normal_idle_1");

        animpoint_sit_normal_loophole.register_action(animpoint_sit_normal_loophole_action3);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_normal_loophole_action4;
        animpoint_sit_normal_loophole_action4.m_id = "fire_no_lookout";
        animpoint_sit_normal_loophole_action4.register_animation("idle", "animpoint_sit_normal_idle_1");
        animpoint_sit_normal_loophole_action4.register_animation("shoot", "animpoint_sit_normal_idle_1");

        animpoint_sit_normal_loophole.register_action(animpoint_sit_normal_loophole_action4);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_normal_loophole_action5;
        animpoint_sit_normal_loophole_action5.m_id = "reload";
        animpoint_sit_normal_loophole_action5.register_animation("idle", "animpoint_sit_normal_idle_1");

        animpoint_sit_normal_loophole.register_action(animpoint_sit_normal_loophole_action5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_normal_loophole_transition1;
        animpoint_sit_normal_loophole_transition1.m_action_from = "idle";
        animpoint_sit_normal_loophole_transition1.m_action_to = "lookout";
        animpoint_sit_normal_loophole_transition1.m_animations.push_back("animpoint_sit_normal_in_1");
        animpoint_sit_normal_loophole_transition1.m_weight = 1.2f;

        animpoint_sit_normal_loophole.register_transition(animpoint_sit_normal_loophole_transition1);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_normal_loophole_transition2;
        animpoint_sit_normal_loophole_transition2.m_action_from = "lookout";
        animpoint_sit_normal_loophole_transition2.m_action_to = "idle";
        animpoint_sit_normal_loophole_transition2.m_animations.push_back("animpoint_sit_normal_in_1");
        animpoint_sit_normal_loophole_transition2.m_weight = 1.2f;

        animpoint_sit_normal_loophole.register_transition(animpoint_sit_normal_loophole_transition2);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_normal_loophole_transition3;
        animpoint_sit_normal_loophole_transition3.m_action_from = "idle";
        animpoint_sit_normal_loophole_transition3.m_action_to = "fire";
        animpoint_sit_normal_loophole_transition3.m_animations.push_back("animpoint_sit_normal_in_1");
        animpoint_sit_normal_loophole_transition3.m_weight = 1.2f;

        animpoint_sit_normal_loophole.register_transition(animpoint_sit_normal_loophole_transition3);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_normal_loophole_transition4;
        animpoint_sit_normal_loophole_transition4.m_action_from = "fire";
        animpoint_sit_normal_loophole_transition4.m_action_to = "idle";
        animpoint_sit_normal_loophole_transition4.m_animations.push_back("animpoint_sit_normal_in_1");
        animpoint_sit_normal_loophole_transition4.m_weight = 1.2f;

        animpoint_sit_normal_loophole.register_transition(animpoint_sit_normal_loophole_transition4);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_normal_loophole_transition5;
        animpoint_sit_normal_loophole_transition5.m_action_from = "idle";
        animpoint_sit_normal_loophole_transition5.m_action_to = "fire_no_lookout";
        animpoint_sit_normal_loophole_transition5.m_animations.push_back("animpoint_sit_normal_in_1");
        animpoint_sit_normal_loophole_transition5.m_weight = 1.2f;

        animpoint_sit_normal_loophole.register_transition(animpoint_sit_normal_loophole_transition5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_normal_loophole_transition6;
        animpoint_sit_normal_loophole_transition6.m_action_from = "fire_no_lookout";
        animpoint_sit_normal_loophole_transition6.m_action_to = "idle";
        animpoint_sit_normal_loophole_transition6.m_animations.push_back("animpoint_sit_normal_in_1");
        animpoint_sit_normal_loophole_transition6.m_weight = 1.2f;

        animpoint_sit_normal_loophole.register_transition(animpoint_sit_normal_loophole_transition6);
#pragma endregion

#pragma region Cordis Transition
        SmartCoverData::SmartCoverTransitionsData animpoint_sit_normal_transition;
        animpoint_sit_normal_transition.m_vertex0 = "";
        animpoint_sit_normal_transition.m_vertex1 = "animpoint_sit_normal";
        animpoint_sit_normal_transition.m_weight = 1.0f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_sit_normal_transition_action1;
        animpoint_sit_normal_transition_action1.m_action.m_animation = "animpoint_sit_normal_in_1";
        animpoint_sit_normal_transition_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_sit_normal_transition_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        animpoint_sit_normal_transition_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_sit_normal_transition_action1.m_precondition_functor = "true";
        animpoint_sit_normal_transition_action1.m_preconditions_params = "";

        animpoint_sit_normal_transition.m_actions.push_back(animpoint_sit_normal_transition_action1);

        SmartCoverData::SmartCoverTransitionsData animpoint_sit_normal_transition1;
        animpoint_sit_normal_transition1.m_vertex0 = "animpoint_sit_normal";
        animpoint_sit_normal_transition1.m_vertex1 = "";
        animpoint_sit_normal_transition1.m_weight = 1.1f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_sit_normal_transition1_action1;
        animpoint_sit_normal_transition1_action1.m_action.m_animation = "animpoint_sit_normal_out_1";
        animpoint_sit_normal_transition1_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_sit_normal_transition1_action1.m_action.m_body_state = MonsterSpace::eBodyStateStand;
        animpoint_sit_normal_transition1_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_sit_normal_transition1_action1.m_precondition_functor = "true";
        animpoint_sit_normal_transition1_action1.m_preconditions_params = "";

        animpoint_sit_normal_transition1.m_actions.push_back(animpoint_sit_normal_transition1_action1);
#pragma endregion

        animpoint_sit_normal_smartcover.setNeedWeapon(false);
        animpoint_sit_normal_smartcover.register_loophole(animpoint_sit_normal_loophole);
        animpoint_sit_normal_smartcover.register_transition(animpoint_sit_normal_transition);
        animpoint_sit_normal_smartcover.register_transition(animpoint_sit_normal_transition1);
        this->m_registered_smartcovers["animpoint_sit_normal"] = animpoint_sit_normal_smartcover;
#pragma endregion

#pragma region Cordis Animpoint Sit Low
        SmartCoverData animpoint_sit_low_smartcover;
        SmartCoverLoopholeData animpoint_sit_low_loophole;

#pragma region Cordis Loophole
        animpoint_sit_low_loophole.m_id = "animpoint_sit_low";
        animpoint_sit_low_loophole.m_is_usable = true;
        animpoint_sit_low_loophole.m_is_exitable = false;
        animpoint_sit_low_loophole.m_is_enterable = false;
        animpoint_sit_low_loophole.m_fieldofview = 45.0f;
        animpoint_sit_low_loophole.m_fieldofview_danger = 45.0f;
        animpoint_sit_low_loophole.m_range = 70.0f;
        animpoint_sit_low_loophole.m_fieldofview_direction = Fvector().set(0.0f, 0.0f, -1.0f);
        animpoint_sit_low_loophole.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_sit_low_loophole.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        animpoint_sit_low_loophole.m_enter_direction = Fvector().set(0.0f, 0.0f, -1.0f);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_low_loophole_action1;
        animpoint_sit_low_loophole_action1.m_id = "idle";
        animpoint_sit_low_loophole_action1.register_animation("idle", "animpoint_sit_low_idle_1");

        animpoint_sit_low_loophole.register_action(animpoint_sit_low_loophole_action1);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_low_loophole_action2;
        animpoint_sit_low_loophole_action2.m_id = "lookout";
        animpoint_sit_low_loophole_action2.register_animation("idle", "animpoint_sit_low_in_1");

        animpoint_sit_low_loophole.register_action(animpoint_sit_low_loophole_action2);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_low_loophole_action3;
        animpoint_sit_low_loophole_action3.m_id = "fire";
        animpoint_sit_low_loophole_action3.register_animation("idle", "animpoint_sit_low_in_1");
        animpoint_sit_low_loophole_action3.register_animation("shoot", "animpoint_sit_low_in_1");

        animpoint_sit_low_loophole.register_action(animpoint_sit_low_loophole_action3);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_low_loophole_action4;
        animpoint_sit_low_loophole_action4.m_id = "fire_no_lookout";
        animpoint_sit_low_loophole_action4.register_animation("idle", "animpoint_sit_low_in_1");
        animpoint_sit_low_loophole_action4.register_animation("shoot", "animpoint_sit_low_in_1");

        animpoint_sit_low_loophole.register_action(animpoint_sit_low_loophole_action4);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_sit_low_loophole_action5;
        animpoint_sit_low_loophole_action5.m_id = "reload";
        animpoint_sit_low_loophole_action5.register_animation("idle", "animpoint_sit_low_in_1");

        animpoint_sit_low_loophole.register_action(animpoint_sit_low_loophole_action5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_low_loophole_transition1;
        animpoint_sit_low_loophole_transition1.m_action_from = "idle";
        animpoint_sit_low_loophole_transition1.m_action_to = "lookout";
        animpoint_sit_low_loophole_transition1.m_animations.push_back("animpoint_sit_low_in_1");
        animpoint_sit_low_loophole_transition1.m_weight = 1.2f;

        animpoint_sit_low_loophole.register_transition(animpoint_sit_low_loophole_transition1);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_low_loophole_transition2;
        animpoint_sit_low_loophole_transition2.m_action_from = "lookout";
        animpoint_sit_low_loophole_transition2.m_action_to = "idle";
        animpoint_sit_low_loophole_transition2.m_animations.push_back("animpoint_sit_low_in_1");
        animpoint_sit_low_loophole_transition2.m_weight = 1.2f;

        animpoint_sit_low_loophole.register_transition(animpoint_sit_low_loophole_transition2);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_low_loophole_transition3;
        animpoint_sit_low_loophole_transition3.m_action_from = "idle";
        animpoint_sit_low_loophole_transition3.m_action_to = "fire";
        animpoint_sit_low_loophole_transition3.m_animations.push_back("animpoint_sit_low_in_1");
        animpoint_sit_low_loophole_transition3.m_weight = 1.2f;

        animpoint_sit_low_loophole.register_transition(animpoint_sit_low_loophole_transition3);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_low_loophole_transition4;
        animpoint_sit_low_loophole_transition4.m_action_from = "fire";
        animpoint_sit_low_loophole_transition4.m_action_to = "idle";
        animpoint_sit_low_loophole_transition4.m_animations.push_back("animpoint_sit_low_in_1");
        animpoint_sit_low_loophole_transition4.m_weight = 1.2f;

        animpoint_sit_low_loophole.register_transition(animpoint_sit_low_loophole_transition4);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_low_loophole_transition5;
        animpoint_sit_low_loophole_transition5.m_action_from = "idle";
        animpoint_sit_low_loophole_transition5.m_action_to = "fire_no_lookout";
        animpoint_sit_low_loophole_transition5.m_animations.push_back("animpoint_sit_low_in_1");
        animpoint_sit_low_loophole_transition5.m_weight = 1.2f;

        animpoint_sit_low_loophole.register_transition(animpoint_sit_low_loophole_transition5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_sit_low_loophole_transition6;
        animpoint_sit_low_loophole_transition6.m_action_from = "fire_no_lookout";
        animpoint_sit_low_loophole_transition6.m_action_to = "idle";
        animpoint_sit_low_loophole_transition6.m_animations.push_back("animpoint_sit_low_in_1");
        animpoint_sit_low_loophole_transition6.m_weight = 1.2f;

        animpoint_sit_low_loophole.register_transition(animpoint_sit_low_loophole_transition6);
#pragma endregion

#pragma region Cordis Transition
        SmartCoverData::SmartCoverTransitionsData animpoint_sit_low_transition;
        animpoint_sit_low_transition.m_vertex0 = "";
        animpoint_sit_low_transition.m_vertex1 = "animpoint_sit_low";
        animpoint_sit_low_transition.m_weight = 1.0f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_sit_low_transition_action1;
        animpoint_sit_low_transition_action1.m_action.m_animation = "animpoint_sit_low_in_1";
        animpoint_sit_low_transition_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_sit_low_transition_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        animpoint_sit_low_transition_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_sit_low_transition_action1.m_precondition_functor = "true";
        animpoint_sit_low_transition_action1.m_preconditions_params = "";

        animpoint_sit_low_transition.m_actions.push_back(animpoint_sit_low_transition_action1);

        SmartCoverData::SmartCoverTransitionsData animpoint_sit_low_transition1;
        animpoint_sit_low_transition1.m_vertex0 = "animpoint_sit_low";
        animpoint_sit_low_transition1.m_vertex1 = "";
        animpoint_sit_low_transition1.m_weight = 1.1f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_sit_low_transition1_action1;
        animpoint_sit_low_transition1_action1.m_action.m_animation = "animpoint_sit_low_out_1";
        animpoint_sit_low_transition1_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_sit_low_transition1_action1.m_action.m_body_state = MonsterSpace::eBodyStateStand;
        animpoint_sit_low_transition1_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_sit_low_transition1_action1.m_precondition_functor = "true";
        animpoint_sit_low_transition1_action1.m_preconditions_params = "";

        animpoint_sit_low_transition1.m_actions.push_back(animpoint_sit_low_transition1_action1);
#pragma endregion

        animpoint_sit_low_smartcover.setNeedWeapon(false);
        animpoint_sit_low_smartcover.register_loophole(animpoint_sit_low_loophole);
        animpoint_sit_low_smartcover.register_transition(animpoint_sit_low_transition);
        animpoint_sit_low_smartcover.register_transition(animpoint_sit_low_transition1);
        this->m_registered_smartcovers["animpoint_sit_low"] = animpoint_sit_low_smartcover;
#pragma endregion

#pragma region Cordis Animpoint Pri A15
        SmartCoverData animpoint_pri_a15_smartcover;
        SmartCoverLoopholeData animpoint_pri_a15_loophole;

#pragma region Cordis Loophole
        animpoint_pri_a15_loophole.m_id = "animpoint_pri_a15";
        animpoint_pri_a15_loophole.m_is_usable = true;
        animpoint_pri_a15_loophole.m_is_exitable = false;
        animpoint_pri_a15_loophole.m_is_enterable = false;
        animpoint_pri_a15_loophole.m_fieldofview = 45.0f;
        animpoint_pri_a15_loophole.m_fieldofview_danger = 45.0f;
        animpoint_pri_a15_loophole.m_range = 70.0f;
        animpoint_pri_a15_loophole.m_fieldofview_direction = Fvector().set(0.0f, 0.0f, -1.0f);
        animpoint_pri_a15_loophole.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_pri_a15_loophole.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        animpoint_pri_a15_loophole.m_enter_direction = Fvector().set(0.0f, 0.0f, -1.0f);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_pri_a15_loophole_action1;
        animpoint_pri_a15_loophole_action1.m_id = "idle";
        animpoint_pri_a15_loophole_action1.register_animation("idle", "idle_0_idle_0");

        animpoint_pri_a15_loophole.register_action(animpoint_pri_a15_loophole_action1);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_pri_a15_loophole_action2;
        animpoint_pri_a15_loophole_action2.m_id = "lookout";
        animpoint_pri_a15_loophole_action2.register_animation("idle", "idle_0_idle_0");

        animpoint_pri_a15_loophole.register_action(animpoint_pri_a15_loophole_action2);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_pri_a15_loophole_action3;
        animpoint_pri_a15_loophole_action3.m_id = "fire";
        animpoint_pri_a15_loophole_action3.register_animation("idle", "idle_0_idle_0");
        animpoint_pri_a15_loophole_action3.register_animation("shoot", "idle_0_idle_0");

        animpoint_pri_a15_loophole.register_action(animpoint_pri_a15_loophole_action3);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_pri_a15_loophole_action4;
        animpoint_pri_a15_loophole_action4.m_id = "fire_no_lookout";
        animpoint_pri_a15_loophole_action4.register_animation("idle", "idle_0_idle_0");
        animpoint_pri_a15_loophole_action4.register_animation("shoot", "idle_0_idle_0");

        animpoint_pri_a15_loophole.register_action(animpoint_pri_a15_loophole_action4);

        SmartCoverLoopholeData::SmartCoverActionsData animpoint_pri_a15_loophole_action5;
        animpoint_pri_a15_loophole_action5.m_id = "reload";
        animpoint_pri_a15_loophole_action5.register_animation("idle", "idle_0_idle_0");

        animpoint_pri_a15_loophole.register_action(animpoint_pri_a15_loophole_action5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_pri_a15_loophole_transition1;
        animpoint_pri_a15_loophole_transition1.m_action_from = "idle";
        animpoint_pri_a15_loophole_transition1.m_action_to = "lookout";
        animpoint_pri_a15_loophole_transition1.m_animations.push_back("idle_0_idle_0");
        animpoint_pri_a15_loophole_transition1.m_weight = 1.2f;

        animpoint_pri_a15_loophole.register_transition(animpoint_pri_a15_loophole_transition1);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_pri_a15_loophole_transition2;
        animpoint_pri_a15_loophole_transition2.m_action_from = "lookout";
        animpoint_pri_a15_loophole_transition2.m_action_to = "idle";
        animpoint_pri_a15_loophole_transition2.m_animations.push_back("idle_0_idle_0");
        animpoint_pri_a15_loophole_transition2.m_weight = 1.2f;

        animpoint_pri_a15_loophole.register_transition(animpoint_pri_a15_loophole_transition2);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_pri_a15_loophole_transition3;
        animpoint_pri_a15_loophole_transition3.m_action_from = "idle";
        animpoint_pri_a15_loophole_transition3.m_action_to = "fire";
        animpoint_pri_a15_loophole_transition3.m_animations.push_back("idle_0_idle_0");
        animpoint_pri_a15_loophole_transition3.m_weight = 1.2f;

        animpoint_pri_a15_loophole.register_transition(animpoint_pri_a15_loophole_transition3);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_pri_a15_loophole_transition4;
        animpoint_pri_a15_loophole_transition4.m_action_from = "fire";
        animpoint_pri_a15_loophole_transition4.m_action_to = "idle";
        animpoint_pri_a15_loophole_transition4.m_animations.push_back("idle_0_idle_0");
        animpoint_pri_a15_loophole_transition4.m_weight = 1.2f;

        animpoint_pri_a15_loophole.register_transition(animpoint_pri_a15_loophole_transition4);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_pri_a15_loophole_transition5;
        animpoint_pri_a15_loophole_transition5.m_action_from = "idle";
        animpoint_pri_a15_loophole_transition5.m_action_to = "fire_no_lookout";
        animpoint_pri_a15_loophole_transition5.m_animations.push_back("idle_0_idle_0");
        animpoint_pri_a15_loophole_transition5.m_weight = 1.2f;

        animpoint_pri_a15_loophole.register_transition(animpoint_pri_a15_loophole_transition5);

        SmartCoverLoopholeData::SmartCoverTransitionsData animpoint_pri_a15_loophole_transition6;
        animpoint_pri_a15_loophole_transition6.m_action_from = "fire_no_lookout";
        animpoint_pri_a15_loophole_transition6.m_action_to = "idle";
        animpoint_pri_a15_loophole_transition6.m_animations.push_back("idle_0_idle_0");
        animpoint_pri_a15_loophole_transition6.m_weight = 1.2f;

        animpoint_pri_a15_loophole.register_transition(animpoint_pri_a15_loophole_transition6);
#pragma endregion

#pragma region Cordis Transition
        SmartCoverData::SmartCoverTransitionsData animpoint_pri_a15_transition;
        animpoint_pri_a15_transition.m_vertex0 = "";
        animpoint_pri_a15_transition.m_vertex1 = "animpoint_pri_a15";
        animpoint_pri_a15_transition.m_weight = 1.0f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_pri_a15_transition_action1;
        animpoint_pri_a15_transition_action1.m_action.m_animation = "idle_0_idle_0";
        animpoint_pri_a15_transition_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_pri_a15_transition_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        animpoint_pri_a15_transition_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_pri_a15_transition_action1.m_precondition_functor = "true";
        animpoint_pri_a15_transition_action1.m_preconditions_params = "";

        animpoint_pri_a15_transition.m_actions.push_back(animpoint_pri_a15_transition_action1);

        SmartCoverData::SmartCoverTransitionsData animpoint_pri_a15_transition1;
        animpoint_pri_a15_transition1.m_vertex0 = "animpoint_pri_a15";
        animpoint_pri_a15_transition1.m_vertex1 = "";
        animpoint_pri_a15_transition1.m_weight = 1.1f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData animpoint_pri_a15_transition1_action1;
        animpoint_pri_a15_transition1_action1.m_action.m_animation = "idle_0_idle_0";
        animpoint_pri_a15_transition1_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        animpoint_pri_a15_transition1_action1.m_action.m_body_state = MonsterSpace::eBodyStateStand;
        animpoint_pri_a15_transition1_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        animpoint_pri_a15_transition1_action1.m_precondition_functor = "true";
        animpoint_pri_a15_transition1_action1.m_preconditions_params = "";

        animpoint_pri_a15_transition1.m_actions.push_back(animpoint_pri_a15_transition1_action1);
#pragma endregion

        animpoint_pri_a15_smartcover.setNeedWeapon(false);
        animpoint_pri_a15_smartcover.register_loophole(animpoint_pri_a15_loophole);
        animpoint_pri_a15_smartcover.register_transition(animpoint_pri_a15_transition);
        animpoint_pri_a15_smartcover.register_transition(animpoint_pri_a15_transition1);
        this->m_registered_smartcovers["animpoint_pri_a15"] = animpoint_pri_a15_smartcover;
#pragma endregion

#pragma region Cordis Anim Pri a15
        SmartCoverData anim_pri_a15_smartcover;
        SmartCoverLoopholeData anim_pri_a15_loophole;

#pragma region Cordis Loophole
        anim_pri_a15_loophole.m_id = "anim_pri_a15";
        anim_pri_a15_loophole.m_is_usable = true;
        anim_pri_a15_loophole.m_is_exitable = false;
        anim_pri_a15_loophole.m_is_enterable = false;
        anim_pri_a15_loophole.m_fieldofview = 45.0f;
        anim_pri_a15_loophole.m_fieldofview_danger = 45.0f;
        anim_pri_a15_loophole.m_range = 70.0f;
        anim_pri_a15_loophole.m_fieldofview_direction = Fvector().set(0.0f, 0.0f, -1.0f);
        anim_pri_a15_loophole.m_fieldofview_position = Fvector().set(0.0f, 0.0f, 0.0f);
        anim_pri_a15_loophole.m_danger_fieldofview_direction = Fvector().set(-1.0f, 0.0f, 0.0f);
        anim_pri_a15_loophole.m_enter_direction = Fvector().set(0.0f, 0.0f, -1.0f);

        SmartCoverLoopholeData::SmartCoverActionsData anim_pri_a15_loophole_action1;
        anim_pri_a15_loophole_action1.m_id = "idle";
        anim_pri_a15_loophole_action1.register_animation("idle", "pri_a22_colonel_lean_on_tabl_in");

        anim_pri_a15_loophole.register_action(anim_pri_a15_loophole_action1);

        SmartCoverLoopholeData::SmartCoverActionsData anim_pri_a15_loophole_action2;
        anim_pri_a15_loophole_action2.m_id = "lookout";
        anim_pri_a15_loophole_action2.register_animation("idle", "pri_a22_colonel_lean_on_tabl_in");

        anim_pri_a15_loophole.register_action(anim_pri_a15_loophole_action2);

        SmartCoverLoopholeData::SmartCoverActionsData anim_pri_a15_loophole_action3;
        anim_pri_a15_loophole_action3.m_id = "fire";
        anim_pri_a15_loophole_action3.register_animation("idle", "pri_a22_colonel_lean_on_tabl_in");
        anim_pri_a15_loophole_action3.register_animation("shoot", "pri_a22_colonel_lean_on_tabl_in");

        anim_pri_a15_loophole.register_action(anim_pri_a15_loophole_action3);

        SmartCoverLoopholeData::SmartCoverActionsData anim_pri_a15_loophole_action4;
        anim_pri_a15_loophole_action4.m_id = "fire_no_lookout";
        anim_pri_a15_loophole_action4.register_animation("idle", "pri_a22_colonel_lean_on_tabl_in");
        anim_pri_a15_loophole_action4.register_animation("shoot", "pri_a22_colonel_lean_on_tabl_in");

        anim_pri_a15_loophole.register_action(anim_pri_a15_loophole_action4);

        SmartCoverLoopholeData::SmartCoverActionsData anim_pri_a15_loophole_action5;
        anim_pri_a15_loophole_action5.m_id = "reload";
        anim_pri_a15_loophole_action5.register_animation("idle", "pri_a22_colonel_lean_on_tabl_in");

        anim_pri_a15_loophole.register_action(anim_pri_a15_loophole_action5);

        SmartCoverLoopholeData::SmartCoverTransitionsData anim_pri_a15_loophole_transition1;
        anim_pri_a15_loophole_transition1.m_action_from = "idle";
        anim_pri_a15_loophole_transition1.m_action_to = "lookout";
        anim_pri_a15_loophole_transition1.m_animations.push_back("pri_a22_colonel_lean_on_tabl_in");
        anim_pri_a15_loophole_transition1.m_weight = 1.2f;

        anim_pri_a15_loophole.register_transition(anim_pri_a15_loophole_transition1);

        SmartCoverLoopholeData::SmartCoverTransitionsData anim_pri_a15_loophole_transition2;
        anim_pri_a15_loophole_transition2.m_action_from = "lookout";
        anim_pri_a15_loophole_transition2.m_action_to = "idle";
        anim_pri_a15_loophole_transition2.m_animations.push_back("pri_a22_colonel_lean_on_tabl_in");
        anim_pri_a15_loophole_transition2.m_weight = 1.2f;

        anim_pri_a15_loophole.register_transition(anim_pri_a15_loophole_transition2);

        SmartCoverLoopholeData::SmartCoverTransitionsData anim_pri_a15_loophole_transition3;
        anim_pri_a15_loophole_transition3.m_action_from = "idle";
        anim_pri_a15_loophole_transition3.m_action_to = "fire";
        anim_pri_a15_loophole_transition3.m_animations.push_back("pri_a22_colonel_lean_on_tabl_in");
        anim_pri_a15_loophole_transition3.m_weight = 1.2f;

        anim_pri_a15_loophole.register_transition(anim_pri_a15_loophole_transition3);

        SmartCoverLoopholeData::SmartCoverTransitionsData anim_pri_a15_loophole_transition4;
        anim_pri_a15_loophole_transition4.m_action_from = "fire";
        anim_pri_a15_loophole_transition4.m_action_to = "idle";
        anim_pri_a15_loophole_transition4.m_animations.push_back("pri_a22_colonel_lean_on_tabl_in");
        anim_pri_a15_loophole_transition4.m_weight = 1.2f;

        anim_pri_a15_loophole.register_transition(anim_pri_a15_loophole_transition4);

        SmartCoverLoopholeData::SmartCoverTransitionsData anim_pri_a15_loophole_transition5;
        anim_pri_a15_loophole_transition5.m_action_from = "idle";
        anim_pri_a15_loophole_transition5.m_action_to = "fire_no_lookout";
        anim_pri_a15_loophole_transition5.m_animations.push_back("pri_a22_colonel_lean_on_tabl_in");
        anim_pri_a15_loophole_transition5.m_weight = 1.2f;

        anim_pri_a15_loophole.register_transition(anim_pri_a15_loophole_transition5);

        SmartCoverLoopholeData::SmartCoverTransitionsData anim_pri_a15_loophole_transition6;
        anim_pri_a15_loophole_transition6.m_action_from = "fire_no_lookout";
        anim_pri_a15_loophole_transition6.m_action_to = "idle";
        anim_pri_a15_loophole_transition6.m_animations.push_back("pri_a22_colonel_lean_on_tabl_in");
        anim_pri_a15_loophole_transition6.m_weight = 1.2f;

        anim_pri_a15_loophole.register_transition(anim_pri_a15_loophole_transition6);
#pragma endregion

#pragma region Cordis Transition
        SmartCoverData::SmartCoverTransitionsData anim_pri_a15_transition;
        anim_pri_a15_transition.m_vertex0 = "";
        anim_pri_a15_transition.m_vertex1 = "anim_pri_a15";
        anim_pri_a15_transition.m_weight = 1.0f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData anim_pri_a15_transition_action1;
        anim_pri_a15_transition_action1.m_action.m_animation = "pri_a22_colonel_lean_on_tabl_in";
        anim_pri_a15_transition_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        anim_pri_a15_transition_action1.m_action.m_body_state = MonsterSpace::eBodyStateCrouch;
        anim_pri_a15_transition_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        anim_pri_a15_transition_action1.m_precondition_functor = "true";
        anim_pri_a15_transition_action1.m_preconditions_params = "";

        anim_pri_a15_transition.m_actions.push_back(anim_pri_a15_transition_action1);

        SmartCoverData::SmartCoverTransitionsData anim_pri_a15_transition1;
        anim_pri_a15_transition1.m_vertex0 = "anim_pri_a15";
        anim_pri_a15_transition1.m_vertex1 = "";
        anim_pri_a15_transition1.m_weight = 1.1f;

        SmartCoverData::SmartCoverTransitionsData::SmartCoverActionsData anim_pri_a15_transition1_action1;
        anim_pri_a15_transition1_action1.m_action.m_animation = "pri_a22_colonel_lean_on_tabl_in";
        anim_pri_a15_transition1_action1.m_action.m_position = Fvector().set(0.0f, 0.0f, 0.0f);
        anim_pri_a15_transition1_action1.m_action.m_body_state = MonsterSpace::eBodyStateStand;
        anim_pri_a15_transition1_action1.m_action.m_movement_type = MonsterSpace::eMovementTypeRun;
        anim_pri_a15_transition1_action1.m_precondition_functor = "true";
        anim_pri_a15_transition1_action1.m_preconditions_params = "";

        anim_pri_a15_transition1.m_actions.push_back(anim_pri_a15_transition1_action1);
#pragma endregion

        anim_pri_a15_smartcover.setNeedWeapon(false);
        anim_pri_a15_smartcover.register_loophole(anim_pri_a15_loophole);
        anim_pri_a15_smartcover.register_transition(anim_pri_a15_transition);
        anim_pri_a15_smartcover.register_transition(anim_pri_a15_transition1);
        this->m_registered_smartcovers["anim_pri_a15"] = anim_pri_a15_smartcover;
#pragma endregion

#pragma endregion

#pragma region Cordis Animpoint System Table initialization
        // @ Eatable
        this->setRegisteredEatableVisuals("stalker_hero_1", true);
        this->setRegisteredEatableVisuals("stalker_hero_novice_1", true);
        this->setRegisteredEatableVisuals("stalker_hero_stalker_1", true);
        this->setRegisteredEatableVisuals("stalker_hero_dolg_1", true);
        this->setRegisteredEatableVisuals("stalker_hero_dolg_2", true);
        this->setRegisteredEatableVisuals("stalker_hero_freedom_1", true);
        this->setRegisteredEatableVisuals("stalker_hero_freedom_2", true);
        this->setRegisteredEatableVisuals("stalker_hero_specops", true);
        this->setRegisteredEatableVisuals("stalker_hero_military", true);
        this->setRegisteredEatableVisuals("stalker_hero_neutral_nauchniy", true);
        this->setRegisteredEatableVisuals("stalker_hero_cs_heavy", true);
        this->setRegisteredEatableVisuals("stalker_hero_exo", true);
        this->setRegisteredEatableVisuals("stalker_bandit_3", true);
        this->setRegisteredEatableVisuals("stalker_bandit_3_face_1", true);
        this->setRegisteredEatableVisuals("stalker_bandit_3_mask", true);
        this->setRegisteredEatableVisuals("stalker_bandit_4", true);
        this->setRegisteredEatableVisuals("stalker_dolg_2_face_1", true);
        this->setRegisteredEatableVisuals("stalker_dolg_1_face_1", true);
        this->setRegisteredEatableVisuals("stalker_dolg_3_face_1", true);
        this->setRegisteredEatableVisuals("stalker_freedom_1_face_1", true);
        this->setRegisteredEatableVisuals("stalker_freedom_2_face_1", true);
        this->setRegisteredEatableVisuals("stalker_freedom_2_face_2", true);
        this->setRegisteredEatableVisuals("stalker_freedom_3", true);
        this->setRegisteredEatableVisuals("stalker_freedom_3_face_1", true);
        this->setRegisteredEatableVisuals("stalker_monolith_1_face_1", true);
        this->setRegisteredEatableVisuals("stalker_nebo_2_face_1", true);
        this->setRegisteredEatableVisuals("stalker_neutral_1_face_1", true);
        this->setRegisteredEatableVisuals("stalker_neutral_1_face_2", true);
        this->setRegisteredEatableVisuals("stalker_neutral_1_face_3", true);
        this->setRegisteredEatableVisuals("stalker_bandit_3_face_3", true);
        this->setRegisteredEatableVisuals("stalker_neutral_2_face_1", true);
        this->setRegisteredEatableVisuals("stalker_neutral_2_face_2", true);
        this->setRegisteredEatableVisuals("stalker_neutral_2_face_3", true);
        this->setRegisteredEatableVisuals("stalker_neutral_2_face_4", true);
        this->setRegisteredEatableVisuals("stalker_neutral_2_face_5", true);
        this->setRegisteredEatableVisuals("stalker_neutral_2_face_6", true);
        this->setRegisteredEatableVisuals("stalker_neutral_2_face_7", true);
        this->setRegisteredEatableVisuals("stalker_bandit_3_face_2", true);
        this->setRegisteredEatableVisuals("stalker_neutral_3_face_1", true);
        this->setRegisteredEatableVisuals("stalker_neutral_nauchniy_face_1", true);
        this->setRegisteredEatableVisuals("stalker_neutral_nauchniy_face_3", true);
        this->setRegisteredEatableVisuals("stalker_soldier_1", true);
        this->setRegisteredEatableVisuals("stalker_soldier_1_face_1", true);
        this->setRegisteredEatableVisuals("stalker_solider_2", true);
        this->setRegisteredEatableVisuals("stalker_solider_2_face_1", true);
        this->setRegisteredEatableVisuals("stalker_solider_3_face_1", true);
        this->setRegisteredEatableVisuals("stalker_solider_ecolog_face_1", true);
        this->setRegisteredEatableVisuals("stalker_ucheniy_1_face_1", true);
        this->setRegisteredEatableVisuals("stalker_ucheniy_1_face_2", true);
        this->setRegisteredEatableVisuals("stalker_zombied_1", true);
        this->setRegisteredEatableVisuals("stalker_zombied_3", true);
        this->setRegisteredEatableVisuals("stalker_neutral_nauchniy_face_2", true);

        // @ Harmonica
        this->setRegisteredHarmonicaVisuals("stalker_hero_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_novice_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_stalker_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_dolg_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_dolg_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_freedom_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_freedom_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_specops", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_military", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_neutral_nauchniy", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_cs_heavy", true);
        this->setRegisteredHarmonicaVisuals("stalker_hero_exo", true);
        this->setRegisteredHarmonicaVisuals("stalker_bandit_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_bandit_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_bandit_3", true);
        this->setRegisteredHarmonicaVisuals("stalker_bandit_3_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_bandit_3_mask", true);
        this->setRegisteredHarmonicaVisuals("stalker_bandit_4", true);
        this->setRegisteredHarmonicaVisuals("stalker_dolg_2_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_dolg_1_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_dolg_2_mask", true);
        this->setRegisteredHarmonicaVisuals("stalker_dolg_3_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_freedom_1_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_freedom_2_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_freedom_2_face_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_freedom_2_mask", true);
        this->setRegisteredHarmonicaVisuals("stalker_freedom_3", true);
        this->setRegisteredHarmonicaVisuals("stalker_freedom_3_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_monolith_1_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_nebo_2_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_1_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_1_face_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_1_face_3", true);
        this->setRegisteredHarmonicaVisuals("stalker_bandit_3_face_3", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_2_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_2_face_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_2_face_3", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_2_face_4", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_2_face_5", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_2_face_6", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_2_face_7", true);
        this->setRegisteredHarmonicaVisuals("stalker_bandit_3_face_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_2_mask", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_3_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_nauchniy_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_nauchniy_face_3", true);
        this->setRegisteredHarmonicaVisuals("stalker_soldier_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_soldier_1_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_solider_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_solider_2_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_solider_3_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_solider_ecolog_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_ucheniy_1_face_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_ucheniy_1_face_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_zombied_1", true);
        this->setRegisteredHarmonicaVisuals("stalker_zombied_2", true);
        this->setRegisteredHarmonicaVisuals("stalker_zombied_3", true);
        this->setRegisteredHarmonicaVisuals("stalker_zombied_4", true);
        this->setRegisteredHarmonicaVisuals("stalker_neutral_nauchniy_face_2", true);

        this->m_animpoint_table["animpoint_stay_wall"].push_back(
            {Globals::predicate_const_true, "animpoint_stay_wall"});
        this->m_animpoint_table["animpoint_stay_wall"].push_back(
            {Globals::predicate_animpoint_bread, "predicate_animpoint_bread"});
        this->m_animpoint_table["animpoint_stay_wall"].push_back(
            {Globals::predicate_animpoint_kolbasa, "animpoint_stay_wall_eat_kolbasa"});
        this->m_animpoint_table["animpoint_stay_wall"].push_back(
            {Globals::predicate_animpoint_vodka, "animpoint_stay_wall_drink_vodka"});
        this->m_animpoint_table["animpoint_stay_wall"].push_back(
            {Globals::predicate_animpoint_energy, "animpoint_stay_wall_drink_energy"});
        this->m_animpoint_table["animpoint_stay_wall"].push_back(
            {Globals::predicate_animpoint_weapon, "animpoint_stay_wall_weapon"});

        this->m_animpoint_table["animpoint_stay_table"].push_back(
            {Globals::predicate_const_true, "animpoint_stay_table"});
        this->m_animpoint_table["animpoint_stay_table"].push_back(
            {Globals::predicate_animpoint_bread, "animpoint_stay_table_eat_bread"});
        this->m_animpoint_table["animpoint_stay_table"].push_back(
            {Globals::predicate_animpoint_kolbasa, "animpoint_stay_table_eat_kolbasa"});
        this->m_animpoint_table["animpoint_stay_table"].push_back(
            {Globals::predicate_animpoint_vodka, "animpoint_stay_table_drink_vodka"});
        this->m_animpoint_table["animpoint_stay_table"].push_back(
            {Globals::predicate_animpoint_energy, "animpoint_stay_table_drink_energy"});
        this->m_animpoint_table["animpoint_stay_table"].push_back(
            {Globals::predicate_animpoint_weapon, "animpoint_stay_table_weapon"});

        this->m_animpoint_table["animpoint_sit_high"].push_back({Globals::predicate_const_true, "animpoint_sit_high"});
        this->m_animpoint_table["animpoint_sit_high"].push_back(
            {Globals::predicate_animpoint_bread, "animpoint_sit_high_eat_bread"});
        this->m_animpoint_table["animpoint_sit_high"].push_back(
            {Globals::predicate_animpoint_kolbasa, "animpoint_sit_high_eat_kolbasa"});
        this->m_animpoint_table["animpoint_sit_high"].push_back(
            {Globals::predicate_animpoint_vodka, "animpoint_sit_high_drink_vodka"});
        this->m_animpoint_table["animpoint_sit_high"].push_back(
            {Globals::predicate_animpoint_energy, "animpoint_sit_high_drink_energy"});
        this->m_animpoint_table["animpoint_sit_high"].push_back(
            {Globals::predicate_animpoint_harmonica, "animpoint_sit_high_harmonica"});

        this->m_animpoint_table["animpoint_sit_normal"].push_back(
            {Globals::predicate_const_true, "animpoint_sit_normal"});
        this->m_animpoint_table["animpoint_sit_normal"].push_back(
            {Globals::predicate_animpoint_bread, "animpoint_sit_normal_eat_bread"});
        this->m_animpoint_table["animpoint_sit_normal"].push_back(
            {Globals::predicate_animpoint_kolbasa, "animpoint_sit_normal_eat_kolbasa"});
        this->m_animpoint_table["animpoint_sit_normal"].push_back(
            {Globals::predicate_animpoint_vodka, "animpoint_sit_normal_drink_vodka"});
        this->m_animpoint_table["animpoint_sit_normal"].push_back(
            {Globals::predicate_animpoint_energy, "animpoint_sit_normal_drink_energy"});
        this->m_animpoint_table["animpoint_sit_normal"].push_back(
            {Globals::predicate_animpoint_guitar, "animpoint_sit_normal_guitar"});

        this->m_animpoint_table["animpoint_sit_low"].push_back({Globals::predicate_const_true, "animpoint_sit_low"});
        this->m_animpoint_table["animpoint_sit_low"].push_back(
            {Globals::predicate_animpoint_bread, "animpoint_sit_low_eat_bread"});
        this->m_animpoint_table["animpoint_sit_low"].push_back(
            {Globals::predicate_animpoint_kolbasa, "animpoint_sit_low_eat_kolbasa"});
        this->m_animpoint_table["animpoint_sit_low"].push_back(
            {Globals::predicate_animpoint_vodka, "animpoint_sit_low_drink_vodka"});
        this->m_animpoint_table["animpoint_sit_low"].push_back(
            {Globals::predicate_animpoint_energy, "animpoint_sit_low_drink_energy"});
        this->m_animpoint_table["animpoint_sit_low"].push_back(
            {Globals::predicate_animpoint_guitar, "animpoint_sit_low_guitar"});
        this->m_animpoint_table["animpoint_sit_low"].push_back(
            {Globals::predicate_animpoint_harmonica, "animpoint_sit_low_harmonica"});

        this->m_animpoint_table["walker_camp"].push_back({Globals::predicate_animpoint_guitar, "play_guitar"});
        this->m_animpoint_table["walker_camp"].push_back({Globals::predicate_animpoint_harmonica, "play_harmonica"});
#pragma endregion

#pragma region Cordis Jobs Types Initializing
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameWalker] =
            Globals::GulagGenerator::kGulagJobPath;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameCamper] =
            Globals::GulagGenerator::kGulagJobPath;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNamePatrol] =
            Globals::GulagGenerator::kGulagJobPath;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameAnimpoint] =
            Globals::GulagGenerator::kGulagJobSmartCover;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameSmartCover] =
            Globals::GulagGenerator::kGulagJobSmartCover;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameRemark] =
            Globals::GulagGenerator::kGulagJobPoint;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameCover] =
            Globals::GulagGenerator::kGulagJobPoint;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameSleeper] =
            Globals::GulagGenerator::kGulagJobPath;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameMobWalker] =
            Globals::GulagGenerator::kGulagJobPath;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameMobHome] =
            Globals::GulagGenerator::kGulagJobPath;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameMobJump] =
            Globals::GulagGenerator::kGulagJobPoint;
        this->m_job_type_by_scheme[Globals::GulagGenerator::kGulagJobNameCompanion] =
            Globals::GulagGenerator::kGulagJobPoint;
#pragma endregion

#pragma region Cordis State Library initialization
        xr_map<xr_string, StateLibData> state_library;
        StateLibData state_lib_data = StateLibData(Globals::kUnsignedInt32Undefined, Globals::kUnsignedInt32Undefined,
            Globals::kUnsignedInt32Undefined, Globals::kUnsignedInt32Undefined, Globals::kStringUndefined,
            Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["idle"] = state_lib_data;
        state_lib_data = StateLibData(Globals::kUnsignedInt32Undefined, Globals::kUnsignedInt32Undefined,
            Globals::kUnsignedInt32Undefined, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["smartcover"] = state_lib_data;
        state_lib_data =
            StateLibData(MonsterSpace::eMovementTypeWalk, MonsterSpace::eMentalStateFree, MonsterSpace::eBodyStateStand,
                Globals::kUnsignedInt32Undefined, "none", Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["walk"] = state_lib_data;
        state_lib_data =
            StateLibData(MonsterSpace::eMovementTypeWalk, MonsterSpace::eMentalStateFree, MonsterSpace::eBodyStateStand,
                Globals::kUnsignedInt32Undefined, "none", Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["walk_noweap"] = state_lib_data;
        state_lib_data =
            StateLibData(MonsterSpace::eMovementTypeRun, MonsterSpace::eMentalStateFree, MonsterSpace::eBodyStateStand,
                Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["run"] = state_lib_data;
        state_lib_data =
            StateLibData(MonsterSpace::eMovementTypeRun, MonsterSpace::eMentalStatePanic, MonsterSpace::eBodyStateStand,
                Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["sprint"] = state_lib_data;
        state_lib_data =
            StateLibData(MonsterSpace::eMovementTypeWalk, MonsterSpace::eMentalStateFree, MonsterSpace::eBodyStateStand,
                Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["patrol"] = state_lib_data;
        state_lib_data =
            StateLibData(MonsterSpace::eMovementTypeWalk, MonsterSpace::eMentalStateFree, MonsterSpace::eBodyStateStand,
                Globals::kUnsignedInt32Undefined, "fire", Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["patrol_fire"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeWalk, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined, false, 0, true);
        state_library["raid"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeWalk, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "fire", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["raid_fire"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeWalk, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["sneak"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeRun, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["sneak_run"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeWalk, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["sneak_no_wpn"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeRun, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["assault"] = state_lib_data;
        state_lib_data =
            StateLibData(MonsterSpace::eMovementTypeRun, MonsterSpace::eMentalStateFree, MonsterSpace::eBodyStateStand,
                Globals::kUnsignedInt32Undefined, "fire", Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["assault_fire"] = state_lib_data;
        state_lib_data =
            StateLibData(MonsterSpace::eMovementTypeRun, MonsterSpace::eMentalStateFree, MonsterSpace::eBodyStateStand,
                Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined, Globals::kStringUndefined);
        state_library["rush"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "idle");
        state_library["wait"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "none", Globals::kStringUndefined, "idle");
        state_library["wait_trade"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["wait_na"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "idle");
        state_library["guard"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["guard_chasovoy"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["guard_na"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "fire", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["guard_fire"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined, true, 0, false);
        state_library["threat"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "bloodsucker_search");
        state_library["threat_danger"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "give_orders");
        state_library["give_orders"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["threat_heli"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined, true);
        state_library["threat_na"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "fire", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["threat_fire"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "sniper_fire", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["threat_sniper_fire"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "hide");
        state_library["hide"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["hide_na"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "fire", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["hide_fire"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "sniper_fire", Globals::kStringUndefined,
            Globals::kStringUndefined);
        state_library["hide_sniper_fire"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, Globals::kStringUndefined,
            Globals::kStringUndefined, "caution");
        state_library["caution"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "choosing");
        state_library["choose"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "press");
        state_library["press"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "warding");
        state_library["ward"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "none", Globals::kStringUndefined,
            "ward_short");
        state_library["ward_short"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "none", Globals::kStringUndefined,
            "warding");
        state_library["ward_noweap"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "none", Globals::kStringUndefined,
            "warding_short");
        state_library["ward_noweap_short"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "none", Globals::kStringUndefined,
            "fold_arms");
        state_library["fold_arms"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, Globals::kStringUndefined,
            Globals::kStringUndefined, "poisk");
        state_library["search"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "stoop_no_weap");
        state_library["stoop_no_weap"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "salut");
        state_library["salut"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "salut_free");
        state_library["salut_free"] = state_lib_data;
        state_lib_data = StateLibData(Globals::kUnsignedInt32Undefined, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "prisoner");
        state_library["prisoner"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "hide");
        state_library["hide_no_wpn"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", "sit",
            Globals::kStringUndefined);
        state_library["sit"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", "sit_knee",
            Globals::kStringUndefined);
        state_library["sit_knee"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", "sit_ass",
            Globals::kStringUndefined);
        state_library["sit_ass"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", "sit_knee", "play_guitar");
        state_library["play_guitar"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", "sit_ass", "play_harmonica");
        state_library["play_harmonica"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "sleeping");
        state_library["sleep"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "hello");
        state_library["hello"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "hello");
        state_library["hello_wpn"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "refuse");
        state_library["refuse"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "claim");
        state_library["claim"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "backoff");
        state_library["backoff"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "backoff");
        state_library["backoff2"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, Globals::kStringUndefined,
            Globals::kStringUndefined, "punch");
        state_library["punch"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "search_corpse");
        state_library["search_corpse"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "help_wounded");
        state_library["help_wounded"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "dynamite");
        state_library["dynamite"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "binocular");
        state_library["binocular"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "cr_raciya");
        state_library["hide_rac"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "raciya");
        state_library["wait_rac"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "none", Globals::kStringUndefined,
            "raciya");
        state_library["wait_rac_noweap"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "raciya_stc");
        state_library["wait_rac_stc"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "unstrapped", Globals::kStringUndefined,
            "raciya");
        state_library["guard_rac"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "probe_stand");
        state_library["probe_stand"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "probe_stand_detector_advanced");
        state_library["probe_stand_detector_advanced"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "probe_stand_detector_elite");
        state_library["probe_stand_detector_elite"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "probe_way");
        state_library["probe_way"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "probe_way_detector_advanced");
        state_library["probe_way_detector_advanced"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "probe_way_detector_elite");
        state_library["probe_way_detector_elite"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "probe_crouch");
        state_library["probe_crouch"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "probe_crouch_detector_advanced");
        state_library["probe_crouch_detector_advanced"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "probe_crouch_detector_elite");
        state_library["probe_crouch_detector_elite"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "scaner_stand");
        state_library["scaner_stand"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "scaner_way");
        state_library["scaner_way"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "scaner_crouch");
        state_library["scaner_crouch"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "hands_up");
        state_library["hands_up"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, SightManager::eSightTypeCurrentDirection, "strapped",
            Globals::kStringUndefined, "wounded");
        state_library["wounded"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, SightManager::eSightTypeCurrentDirection, "drop", Globals::kStringUndefined,
            "wounded_heavy_1");
        state_library["wounded_heavy"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, SightManager::eSightTypeCurrentDirection, "drop", Globals::kStringUndefined,
            "wounded_heavy_2");
        state_library["wounded_heavy_2"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, SightManager::eSightTypeCurrentDirection, "drop", Globals::kStringUndefined,
            "wounded_heavy_3");
        state_library["wounded_heavy_3"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, SightManager::eSightTypeCurrentDirection, "drop", Globals::kStringUndefined,
            "wounded_zombie");
        state_library["wounded_zombie"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "trans_0");
        state_library["trans_0"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "trans_1");
        state_library["trans_1"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "trans_zombied");
        state_library["trans_zombied"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "talk_default");
        state_library["talk_default"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "drop", Globals::kStringUndefined,
            "psy_armed");
        state_library["psy_pain"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "psy_armed");
        state_library["psy_armed"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateCrouch, Globals::kUnsignedInt32Undefined, "fire", Globals::kStringUndefined,
            "psy_shoot", false, 1);
        state_library["psy_shoot"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateCrouch, SightManager::eSightTypeCurrentDirection, "drop", Globals::kStringUndefined,
            "wounded_heavy_1");
        state_library["lay_on_bed"] = state_lib_data;

#pragma region Cordis State Library Animpoint stuff
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_wall", "animpoint_stay_wall");
        state_library["animpoint_stay_wall"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_table", "animpoint_stay_table");
        state_library["animpoint_stay_table"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_high",
            "animpoint_sit_high");
        state_library["animpoint_sit_high"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_sit_normal", "animpoint_sit_normal");
        state_library["animpoint_sit_normal"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_low",
            "animpoint_sit_low");
        state_library["animpoint_sit_low"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_wall", "animpoint_stay_wall_eat_bread");
        state_library["animpoint_stay_wall_eat_bread"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_wall", "animpoint_stay_wall_eat_kolbasa");
        state_library["animpoint_stay_wall_eat_kolbasa"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_table", "animpoint_stay_table_eat_bread");
        state_library["animpoint_stay_table_eat_bread"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_table", "animpoint_stay_table_eat_kolbasa");
        state_library["animpoint_stay_table_eat_kolbasa"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_high",
            "animpoint_sit_high_eat_bread");
        state_library["animpoint_sit_high_eat_bread"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_high",
            "animpoint_sit_high_eat_kolbasa");
        state_library["animpoint_sit_high_eat_kolbasa"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_sit_normal", "animpoint_sit_normal_eat_bread");
        state_library["animpoint_sit_normal_eat_bread"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_sit_normal", "animpoint_sit_normal_eat_kolbasa");
        state_library["animpoint_sit_normal_eat_kolbasa"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_low",
            "animpoint_sit_low_eat_bread");
        state_library["animpoint_sit_low_eat_bread"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_low",
            "animpoint_sit_low_eat_kolbasa");
        state_library["animpoint_sit_low_eat_kolbasa"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_wall", "animpoint_stay_wall_drink_vodka");
        state_library["animpoint_stay_wall_drink_vodka"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_wall", "animpoint_stay_wall_drink_energy");
        state_library["animpoint_stay_wall_drink_energy"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_table", "animpoint_stay_table_drink_vodka");
        state_library["animpoint_stay_table_drink_vodka"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_table", "animpoint_stay_table_drink_energy");
        state_library["animpoint_stay_table_drink_energy"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_high",
            "animpoint_sit_high_drink_vodka");
        state_library["animpoint_sit_high_drink_vodka"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_high",
            "animpoint_sit_high_drink_energy");
        state_library["animpoint_sit_high_drink_energy"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_sit_normal", "animpoint_sit_normal_drink_vodka");
        state_library["animpoint_sit_normal_drink_vodka"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_low",
            "animpoint_sit_low_drink_vodka");
        state_library["animpoint_sit_low_drink_vodka"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_low",
            "animpoint_sit_low_drink_energy");
        state_library["animpoint_sit_low_drink_energy"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_wall", "animpoint_stay_wall_guitar");
        state_library["animpoint_stay_wall_guitar"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_table", "animpoint_stay_table_guitar");
        state_library["animpoint_stay_table_guitar"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_high",
            "animpoint_sit_high_guitar");
        state_library["animpoint_sit_high_guitar"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_sit_normal", "animpoint_sit_normal_guitar");
        state_library["animpoint_sit_normal_guitar"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_low",
            "animpoint_sit_low_guitar");
        state_library["animpoint_sit_low_guitar"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_wall", "animpoint_stay_wall_harmonica");
        state_library["animpoint_stay_wall_harmonica"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_table", "animpoint_stay_table_harmonica");
        state_library["animpoint_stay_table_harmonica"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_high",
            "animpoint_sit_high_harmonica");
        state_library["animpoint_sit_high_harmonica"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_sit_normal", "animpoint_sit_normal_harmonica");
        state_library["animpoint_sit_normal_harmonica"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_low",
            "animpoint_sit_low_harmonica");
        state_library["animpoint_sit_low_harmonica"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            "animpoint_stay_wall_weapon", Globals::kStringUndefined);
        state_library["animpoint_stay_wall_weapon"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            "animpoint_stay_table_weapon", Globals::kStringUndefined);
        state_library["animpoint_stay_table_weapon"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            "animpoint_sit_high_weapon", Globals::kStringUndefined);
        state_library["animpoint_sit_high_weapon"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            "animpoint_sit_normal_weapon", Globals::kStringUndefined);
        state_library["animpoint_sit_normal_weapon"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            "animpoint_sit_low_weapon", Globals::kStringUndefined);
        state_library["animpoint_sit_low_weapon"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_wall", Globals::kStringUndefined);
        state_library["animpoint_stay_wall_no_rnd"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_stay_table", Globals::kStringUndefined);
        state_library["animpoint_stay_table_no_rnd"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_high",
            Globals::kStringUndefined);
        state_library["animpoint_sit_high_no_rnd"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "animpoint_sit_normal", Globals::kStringUndefined);
        state_library["animpoint_sit_normal_no_rnd"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_low",
            Globals::kStringUndefined);
        state_library["animpoint_sit_low_no_rnd"] = state_lib_data;
#pragma endregion

#pragma region Cordis State Library Manager Scenario
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "zat_b14_give_artefact_idle");
        state_library["zat_b14_give_artefact_idle"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, Globals::kUnsignedInt32Undefined, "strapped", Globals::kStringUndefined,
            "zat_b14_give_artefact_act");
        state_library["zat_b14_give_artefact_act"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "zat_b14_stay_wall");
        state_library["zat_b14_stay_wall"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "zat_b38_stalker_break_lock");
        state_library["zat_b38_stalker_break_lock"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "zat_b38_stalker_turn_on_lift");
        state_library["zat_b38_stalker_turn_on_lift"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "zat_b38_stalker_jump_tonnel");
        state_library["zat_b38_stalker_jump_tonnel"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "zat_b38_stalker_alert");
        state_library["zat_b38_stalker_alert"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "zat_b20_noah_jump");
        state_library["zat_b20_noah_jump"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "pri_a17_ice_climb");
        state_library["pri_a17_ice_climb"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a17_fall_down");
        state_library["pri_a17_fall_down"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a17_pray_in");
        state_library["pri_a17_pray_in"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a17_pray");
        state_library["pri_a17_pray"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "zat_b22_medic_turn_idle");
        state_library["zat_b22_medic_turn_idle"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "zat_b22_medic_turn_out");
        state_library["zat_b22_medic_turn_out"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "fire",
            Globals::kStringUndefined, "zat_b22_medic_suicide");
        state_library["zat_b22_medic_suicide"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none", "zat_b3_tech_idle",
            "zat_b3_tech_drunk");
        state_library["zat_b3_tech_drunk"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none", "zat_b3_tech_idle",
            "zat_b3_tech_drink");
        state_library["zat_b3_tech_drink"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none", "zat_b3_tech_idle",
            "zat_b3_tech_idle_1");
        state_library["zat_b3_tech_idle"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none", "zat_b3_tech_idle",
            Globals::kStringUndefined);
        state_library["zat_b3_tech_idle_short"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none", "zat_b3_tech_idle",
            "zat_b3_tech_surprise");
        state_library["zat_b3_tech_surprise"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "give_orders");
        state_library["give_orders"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "bloodsucker_search");
        state_library["bloodsucker_search"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateDanger,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "fire",
            Globals::kStringUndefined, "bloodsucker_panic");
        state_library["bloodsucker_panic"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "fire",
            Globals::kStringUndefined, "suicide_animation");
        state_library["suicide_animation"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "jup_b10_drunk_ravings");
        state_library["jup_b10_drunk_ravings"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "pas_b400_vano_probe");
        state_library["pas_b400_vano_probe"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped", "animpoint_sit_high",
            "pri_a28_kirillov_sit_high_radio");
        state_library["pri_a28_kirillov_sit_high_radio"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a18_inspert_monolit_actor");
        state_library["pri_a18_inspert_monolit_actor"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            "pri_a20_colonel_radio", Globals::kStringUndefined);
        state_library["pri_a20_colonel_radio"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "fire", "pri_a21_sentry_madness",
            Globals::kStringUndefined);
        state_library["pri_a21_sentry_madness"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "fire",
            "pri_a21_sentry_madness_idle", "pri_a21_sentry_madness_suicide");
        state_library["pri_a21_sentry_madness_suicide"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            "pri_a22_colonel_lean_on_table", Globals::kStringUndefined);
        state_library["pri_a22_colonel_lean_on_table"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a28_army_trance_out");
        state_library["pri_a28_army_trance_out"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "zat_b106_wounded_idle");
        state_library["zat_b106_wounded_idle"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "zat_b38_cop_dead");
        state_library["zat_b38_cop_dead"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            "jup_b15_zulus_sit_idle_short", "jup_b15_zulus_sit_drink");
        state_library["jup_b15_zulus_sit_drink"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            "jup_b15_zulus_sit_idle_short", "jup_b15_zulus_sit_idle");
        state_library["jup_b15_zulus_sit_idle"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            "jup_b15_zulus_sit_idle_short", Globals::kStringUndefined);
        state_library["jup_b15_zulus_sit_idle_short"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "jup_b15_zulus_sit_out");
        state_library["jup_b15_zulus_sit_out"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_actor_one");
        state_library["jup_b219_actor_one"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_actor_one_vano");
        state_library["jup_b219_actor_one_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_actor_one_monolith");
        state_library["jup_b219_actor_one_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_actor_one_soldier");
        state_library["jup_b219_actor_one_soldier"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_actor_all");
        state_library["jup_b219_actor_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_actor_soldier_vano");
        state_library["jup_b219_actor_soldier_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_actor_soldier_monolith");
        state_library["jup_b219_actor_soldier_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_actor_vano_monolith");
        state_library["jup_b219_actor_vano_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_zulus_one");
        state_library["jup_b219_zulus_one"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_zulus_one_vano");
        state_library["jup_b219_zulus_one_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_zulus_one_monolith");
        state_library["jup_b219_zulus_one_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_zulus_one_soldier");
        state_library["jup_b219_zulus_one_soldier"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_zulus_all");
        state_library["jup_b219_zulus_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_zulus_soldier_vano");
        state_library["jup_b219_zulus_soldier_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_zulus_soldier_monolith");
        state_library["jup_b219_zulus_soldier_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_zulus_vano_monolith");
        state_library["jup_b219_zulus_vano_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_soldier_one");
        state_library["jup_b219_soldier_one"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_soldier_all");
        state_library["jup_b219_soldier_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_soldier_soldier_vano");
        state_library["jup_b219_soldier_soldier_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_soldier_soldier_monolith");
        state_library["jup_b219_soldier_soldier_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_monolith_one");
        state_library["jup_b219_monolith_one"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_monolith_all");
        state_library["jup_b219_monolith_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_monolith_soldier_monolith");
        state_library["jup_b219_monolith_soldier_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_monolith_vano_monolith");
        state_library["jup_b219_monolith_vano_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_vano_one");
        state_library["jup_b219_vano_one"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_vano_all");
        state_library["jup_b219_vano_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_vano_soldier_vano");
        state_library["jup_b219_vano_soldier_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_b219_vano_vano_monolith");
        state_library["jup_b219_vano_vano_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "jup_b219_azot_one");
        state_library["jup_b219_azot_one"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "jup_b219_azot_one_vano");
        state_library["jup_b219_azot_one_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "jup_b219_azot_one_monolith");
        state_library["jup_b219_azot_one_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "jup_b219_azot_one_soldier");
        state_library["jup_b219_azot_one_soldier"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "jup_b219_azot_soldier_vano");
        state_library["jup_b219_azot_soldier_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "jup_b219_azot_soldier_monolith");
        state_library["jup_b219_azot_soldier_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "jup_b219_azot_vano_monolith");
        state_library["jup_b219_azot_vano_monolith"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "jup_b219_azot_all");
        state_library["jup_b219_azot_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "zat_b100_heli_2_serch");
        state_library["zat_b100_heli_2_serch"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "zat_b101_heli_5_serch");
        state_library["zat_b101_heli_5_serch"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "jup_b217_guide_stand");
        state_library["jup_b217_guide_stand"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "jup_b217_nitro_stand");
        state_library["jup_b217_nitro_stand"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "jup_b41_novikov_stand");
        state_library["jup_b41_novikov_stand"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_b305_actor");
        state_library["pri_b305_actor"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_a9_cam1_actor");
        state_library["jup_a9_cam1_actor"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_a9_cam2_actor");
        state_library["jup_a9_cam2_actor"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "jup_a9_cam3_actor");
        state_library["jup_a9_cam3_actor"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "jup_b217_nitro_straight");
        state_library["jup_b217_nitro_straight"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "pri_a25_psy_medic_idle");
        state_library["pri_a25_psy_medic_idle"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "pri_a25_psy_medic_out");
        state_library["pri_a25_psy_medic_out"] = state_lib_data;
#pragma endregion

#pragma region Cordis State Library PriA15
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_idle_none");
        state_library["pri_a15_idle_none"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "strapped",
            Globals::kStringUndefined, "pri_a15_idle_none");
        state_library["pri_a15_idle_strap"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_idle_unstrap");
        state_library["pri_a15_idle_unstrap"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_vano_all");
        state_library["pri_a15_vano_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_vano_1_sokolov");
        state_library["pri_a15_vano_1_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_vano_1_zulus");
        state_library["pri_a15_vano_1_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_vano_1_wanderer");
        state_library["pri_a15_vano_1_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_vano_2_sokolov_zulus");
        state_library["pri_a15_vano_2_sokolov_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_vano_2_sokolov_wanderer");
        state_library["pri_a15_vano_2_sokolov_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_vano_2_zulus_wanderer");
        state_library["pri_a15_vano_2_zulus_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_vano_3_vano_alive");
        state_library["pri_a15_vano_3_vano_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_sokolov_all");
        state_library["pri_a15_sokolov_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_sokolov_1_vano");
        state_library["pri_a15_sokolov_1_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_sokolov_1_zulus");
        state_library["pri_a15_sokolov_1_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_sokolov_1_wanderer");
        state_library["pri_a15_sokolov_1_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_sokolov_2_vano_zulus");
        state_library["pri_a15_sokolov_2_vano_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_sokolov_2_vano_wanderer");
        state_library["pri_a15_sokolov_2_vano_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_sokolov_2_zulus_wanderer");
        state_library["pri_a15_sokolov_2_zulus_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_sokolov_3_sokolov_alive");
        state_library["pri_a15_sokolov_3_sokolov_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_zulus_all");
        state_library["pri_a15_zulus_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_zulus_1_vano");
        state_library["pri_a15_zulus_1_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_zulus_1_sokolov");
        state_library["pri_a15_zulus_1_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_zulus_1_wanderer");
        state_library["pri_a15_zulus_1_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_zulus_2_vano_sokolov");
        state_library["pri_a15_zulus_2_vano_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_zulus_2_vano_wanderer");
        state_library["pri_a15_zulus_2_vano_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_zulus_2_sokolov_wanderer");
        state_library["pri_a15_zulus_2_sokolov_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_zulus_3_zulus_alive");
        state_library["pri_a15_zulus_3_zulus_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_wanderer_all");
        state_library["pri_a15_wanderer_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_wanderer_1_vano");
        state_library["pri_a15_wanderer_1_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_wanderer_1_sokolov");
        state_library["pri_a15_wanderer_1_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_wanderer_1_zulus");
        state_library["pri_a15_wanderer_1_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_wanderer_2_vano_sokolov");
        state_library["pri_a15_wanderer_2_vano_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_wanderer_2_vano_zulus");
        state_library["pri_a15_wanderer_2_vano_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_wanderer_2_sokolov_zulus");
        state_library["pri_a15_wanderer_2_sokolov_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_wanderer_3_wanderer_alive");
        state_library["pri_a15_wanderer_3_wanderer_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_all");
        state_library["pri_a15_actor_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_1_vano");
        state_library["pri_a15_actor_1_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_1_sokolov");
        state_library["pri_a15_actor_1_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_1_zulus");
        state_library["pri_a15_actor_1_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_1_wanderer");
        state_library["pri_a15_actor_1_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_2_vano_sokolov");
        state_library["pri_a15_actor_2_vano_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_2_vano_zulus");
        state_library["pri_a15_actor_2_vano_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_2_vano_wanderer");
        state_library["pri_a15_actor_2_vano_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_2_sokolov_zulus");
        state_library["pri_a15_actor_2_sokolov_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_2_sokolov_wanderer");
        state_library["pri_a15_actor_2_sokolov_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_2_zulus_wanderer");
        state_library["pri_a15_actor_2_zulus_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_3_vano_alive");
        state_library["pri_a15_actor_3_vano_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_3_sokolov_alive");
        state_library["pri_a15_actor_3_sokolov_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_3_zulus_alive");
        state_library["pri_a15_actor_3_zulus_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_3_wanderer_alive");
        state_library["pri_a15_actor_3_wanderer_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "none",
            Globals::kStringUndefined, "pri_a15_actor_all_dead");
        state_library["pri_a15_actor_all_dead"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_all");
        state_library["pri_a15_military_tarasov_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_1_vano");
        state_library["pri_a15_military_tarasov_1_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_1_sokolov");
        state_library["pri_a15_military_tarasov_1_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_1_zulus");
        state_library["pri_a15_military_tarasov_1_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_1_wanderer");
        state_library["pri_a15_military_tarasov_1_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_2_vano_sokolov");
        state_library["pri_a15_military_tarasov_2_vano_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_2_vano_zulus");
        state_library["pri_a15_military_tarasov_2_vano_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_2_vano_wanderer");
        state_library["pri_a15_military_tarasov_2_vano_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_2_sokolov_zulus");
        state_library["pri_a15_military_tarasov_2_sokolov_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_2_sokolov_wanderer");
        state_library["pri_a15_military_tarasov_2_sokolov_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_2_zulus_wanderer");
        state_library["pri_a15_military_tarasov_2_zulus_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_3_vano_alive");
        state_library["pri_a15_military_tarasov_3_vano_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_3_sokolov_alive");
        state_library["pri_a15_military_tarasov_3_sokolov_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_3_zulus_alive");
        state_library["pri_a15_military_tarasov_3_zulus_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_3_wanderer_alive");
        state_library["pri_a15_military_tarasov_3_wanderer_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_tarasov_all_dead");
        state_library["pri_a15_military_tarasov_all_dead"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_all");
        state_library["pri_a15_military_2_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_1_vano");
        state_library["pri_a15_military_2_1_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_1_sokolov");
        state_library["pri_a15_military_2_1_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_1_zulus");
        state_library["pri_a15_military_2_1_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_1_wanderer");
        state_library["pri_a15_military_2_1_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_2_vano_sokolov");
        state_library["pri_a15_military_2_2_vano_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_2_vano_zulus");
        state_library["pri_a15_military_2_2_vano_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_2_vano_wanderer");
        state_library["pri_a15_military_2_2_vano_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_2_sokolov_zulus");
        state_library["pri_a15_military_2_2_sokolov_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_2_sokolov_wanderer");
        state_library["pri_a15_military_2_2_sokolov_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_2_zulus_wanderer");
        state_library["pri_a15_military_2_2_zulus_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_3_vano_alive");
        state_library["pri_a15_military_2_3_vano_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_3_sokolov_alive");
        state_library["pri_a15_military_2_3_sokolov_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_3_zulus_alive");
        state_library["pri_a15_military_2_3_zulus_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_3_wanderer_alive");
        state_library["pri_a15_military_2_3_wanderer_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_2_all_dead");
        state_library["pri_a15_military_2_all_dead"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_all");
        state_library["pri_a15_military_3_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_1_vano");
        state_library["pri_a15_military_3_1_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_1_sokolov");
        state_library["pri_a15_military_3_1_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_1_zulus");
        state_library["pri_a15_military_3_1_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_1_wanderer");
        state_library["pri_a15_military_3_1_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_2_vano_sokolov");
        state_library["pri_a15_military_3_2_vano_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_2_vano_zulus");
        state_library["pri_a15_military_3_2_vano_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_2_vano_wanderer");
        state_library["pri_a15_military_3_2_vano_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_2_sokolov_zulus");
        state_library["pri_a15_military_3_2_sokolov_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_2_sokolov_wanderer");
        state_library["pri_a15_military_3_2_sokolov_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_2_zulus_wanderer");
        state_library["pri_a15_military_3_2_zulus_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_3_vano_alive");
        state_library["pri_a15_military_3_3_vano_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_3_sokolov_alive");
        state_library["pri_a15_military_3_3_sokolov_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_3_zulus_alive");
        state_library["pri_a15_military_3_3_zulus_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_3_wanderer_alive");
        state_library["pri_a15_military_3_3_wanderer_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_3_all_dead");
        state_library["pri_a15_military_3_all_dead"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_all");
        state_library["pri_a15_military_4_all"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_1_vano");
        state_library["pri_a15_military_4_1_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_1_vano");
        state_library["pri_a15_military_4_1_vano"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_1_sokolov");
        state_library["pri_a15_military_4_1_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_1_zulus");
        state_library["pri_a15_military_4_1_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_1_wanderer");
        state_library["pri_a15_military_4_1_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_2_vano_sokolov");
        state_library["pri_a15_military_4_2_vano_sokolov"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_2_vano_zulus");
        state_library["pri_a15_military_4_2_vano_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_2_vano_wanderer");
        state_library["pri_a15_military_4_2_vano_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_2_sokolov_zulus");
        state_library["pri_a15_military_4_2_sokolov_zulus"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_2_sokolov_wanderer");
        state_library["pri_a15_military_4_2_sokolov_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_2_zulus_wanderer");
        state_library["pri_a15_military_4_2_zulus_wanderer"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_3_vano_alive");
        state_library["pri_a15_military_4_3_vano_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_3_sokolov_alive");
        state_library["pri_a15_military_4_3_sokolov_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_3_zulus_alive");
        state_library["pri_a15_military_4_3_zulus_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_3_wanderer_alive");
        state_library["pri_a15_military_4_3_wanderer_alive"] = state_lib_data;
        state_lib_data = StateLibData(MonsterSpace::eMovementTypeStand, MonsterSpace::eMentalStateFree,
            MonsterSpace::eBodyStateStand, SightManager::eSightTypeAnimationDirection, "unstrapped",
            Globals::kStringUndefined, "pri_a15_military_4_all_dead");
        state_library["pri_a15_military_4_all_dead"] = state_lib_data;
#pragma endregion
#pragma endregion

#pragma region Cordis Initializing animation for monsters by actions(uses in state manager for monster)
        this->m_monster_animation_to_action["free"] = MonsterSpace::eMentalStateFree;
        this->m_monster_animation_to_action["danger"] = MonsterSpace::eMentalStateDanger;
        this->m_monster_animation_to_action["panic"] = MonsterSpace::eMentalStatePanic;
        this->m_monster_animation_to_action["stand_idle"] = MonsterSpace::eAA_StandIdle;
        this->m_monster_animation_to_action["capture_prepare"] = MonsterSpace::eAA_CapturePrepare;
        this->m_monster_animation_to_action["sit_idle"] = MonsterSpace::eAA_SitIdle;
        this->m_monster_animation_to_action["lie_idle"] = MonsterSpace::eAA_LieIdle;
        this->m_monster_animation_to_action["eat"] = MonsterSpace::eAA_Eat;
        this->m_monster_animation_to_action["sleep"] = MonsterSpace::eAA_Sleep;
        this->m_monster_animation_to_action["rest"] = MonsterSpace::eAA_Rest;
        this->m_monster_animation_to_action["attack"] = MonsterSpace::eAA_Attack;
        this->m_monster_animation_to_action["look_around"] = MonsterSpace::eAA_LookAround;
        this->m_monster_animation_to_action["turn"] = MonsterSpace::eAA_Turn;

        this->m_monster_sound_name_to_type_action["idle"] = MonsterSound::EType::eMonsterSoundIdle;
        this->m_monster_sound_name_to_type_action["eat"] = MonsterSound::EType::eMonsterSoundEat;
        this->m_monster_sound_name_to_type_action["attack"] = MonsterSound::EType::eMonsterSoundAggressive;
        this->m_monster_sound_name_to_type_action["attack_hit"] = MonsterSound::EType::eMonsterSoundAttackHit;
        this->m_monster_sound_name_to_type_action["take_damage"] = MonsterSound::EType::eMonsterSoundTakeDamage;
        this->m_monster_sound_name_to_type_action["die"] = MonsterSound::EType::eMonsterSoundDie;
        this->m_monster_sound_name_to_type_action["threaten"] = MonsterSound::EType::eMonsterSoundThreaten;
        this->m_monster_sound_name_to_type_action["steal"] = MonsterSound::EType::eMonsterSoundSteal;
        this->m_monster_sound_name_to_type_action["panic"] = MonsterSound::EType::eMonsterSoundPanic;
#pragma endregion

#pragma region SmartTerrain Initializing
        this->m_game_server_nearest_to_actor_smart_terrain.first = std::uint32_t(-1);
        this->m_game_server_nearest_to_actor_smart_terrain.second = std::uint32_t(-1);
        this->m_registered_smart_terrain_territory_type[Globals::kSmartTerrainTerritoryBase] = true;
        this->m_registered_smart_terrain_territory_type[Globals::kSmartTerrainTerritoryDefault] = true;
        this->m_registered_smart_terrain_territory_type[Globals::kSmartTerrainTerritoryResource] = true;
        this->m_registered_smart_terrain_territory_type[Globals::kSmartTerrainTerritoryTerritory] = true;
        this->m_registered_smart_terrain_path_fields.push_back(Globals::kSmartTerrainPathFieldCenterPoint);
        this->m_registered_smart_terrain_path_fields.push_back(Globals::kSmartTerrainPathFieldPathHome);
        this->m_registered_smart_terrain_path_fields.push_back(Globals::kSmartTerrainPathFieldPathMain);
        this->m_registered_smart_terrain_path_fields.push_back(Globals::kSmartTerrainPathFieldPathWalk);

        this->m_registered_smart_terrain_control_script_states["normal"] = Script_SmartTerrainControl_States::kNormal;
        this->m_registered_smart_terrain_control_script_states["danger"] = Script_SmartTerrainControl_States::kDanger;
        this->m_registered_smart_terrain_control_script_states["alarm"] = Script_SmartTerrainControl_States::kAlarm;
#pragma endregion

#pragma region Cordis SimulationBoard Initializing
        // @ Lord: реализовать автоматическое считываение и сделать нумерацию от 0
        this->m_simulationboard_group_id_by_levels_name["zaton"] = 1;
        this->m_simulationboard_group_id_by_levels_name["pripyat"] = 2;
        this->m_simulationboard_group_id_by_levels_name["jupiter"] = 3;
        this->m_simulationboard_group_id_by_levels_name["labx8"] = 4;
        this->m_simulationboard_group_id_by_levels_name["jupiter_underground"] = 5;
#pragma endregion

#pragma region Cordis SimulationSquad Initializing
        this->m_simulationsquad_is_squad_monster_by_type["monster_predatory_day"] = true;
        this->m_simulationsquad_is_squad_monster_by_type["monster_predatory_night"] = true;
        this->m_simulationsquad_is_squad_monster_by_type["monster_vegetarian"] = true;
        this->m_simulationsquad_is_squad_monster_by_type["monster_zombied_day"] = true;
        this->m_simulationsquad_is_squad_monster_by_type["monster_zombied_night"] = true;
        this->m_simulationsquad_is_squad_monster_by_type["monster_special"] = true;
        this->m_simulationsquad_is_squad_monster_by_type["monster"] = true;
#pragma endregion

#pragma region Cordis SE_Actor initializing
        this->m_game_smarts_by_no_assault_zone["zat_a2_sr_no_assault"] = "zat_stalker_base_smart";
        this->m_game_smarts_by_no_assault_zone["jup_a6_sr_no_assault"] = "jup_a6";
        this->m_game_smarts_by_no_assault_zone["jup_b41_sr_no_assault"] = "jup_b41";
#pragma endregion

#pragma region Cordis Registering XR_CONDITINO Functions
        _REGISTER_FULL_FUNCTION_XR_CONDITION(actor_on_level, XR_CONDITION::is_actor_on_level)
#pragma endregion

#pragma region Cordis Initializing DialogManager
        {
            CScriptIniFile ini = CScriptIniFile("misc\\dialog_manager.ltx");
            xr_string id_name;
            xr_string value_name;
            xr_string category_name;
            // Lord: test it ... точно ли мы должны отмимать единицу
            for (std::size_t i = 0; i < ini.line_count("list") - 1; ++i)
            {
                const char* id;
                const char* value;
                bool result = ini.r_line("list", i, &id, &value);

                if (ini.line_exist(id, "category"))
                {
                    category_name = ini.r_string(id, "category");

                    if (!(category_name == "hello" || category_name == "anomalies" || category_name == "place" ||
                            category_name == "job" || category_name == "information"))
                        category_name = "default";
                }
                else
                {
                    R_ASSERT2(false, "Not categoried section");
                }

                if (category_name != "default")
                {
                    DialogData data;
                    data.setName(id);

                    if (ini.line_exist(id, "npc_community"))
                    {
                        const char* result = ini.r_string(id, "npc_community");
                        data.setNpcCommunities(Globals::Utils::parse_names(result));
                    }
                    else
                    {
                        data.setNpcCommunities(xr_vector<xr_string>{"not_set"});
                    }

                    if (ini.line_exist(id, "level"))
                    {
                        const char* result = ini.r_string(id, "level");
                        data.setLevels(Globals::Utils::parse_names(result));
                    }
                    else
                    {
                        data.setLevels(xr_vector<xr_string>{"not_set"});
                    }

                    if (ini.line_exist(id, "actor_community"))
                    {
                        const char* result = ini.r_string(id, "actor_community");
                        data.setActorCommunities(Globals::Utils::parse_names(result));
                    }
                    else
                    {
                        data.setActorCommunities(xr_vector<xr_string>{"not_set"});
                    }

                    if (ini.line_exist(id, "wounded"))
                    {
                        data.setWounded(ini.r_string(id, "wounded"));
                    }
                    else
                    {
                        data.setWounded(Globals::kStringFalse);
                    }

                    if (ini.line_exist(id, "once"))
                    {
                        data.setOnceStateName(ini.r_string(id, "once"));
                    }
                    else
                    {
                        data.setOnceStateName("always");
                    }

                    if (ini.line_exist(id, "info"))
                    {
                        if (strcmp(ini.r_string(id, "info"), "") != 0)
                        {
                            xr_map<std::uint32_t, CondlistData::CondlistValues> result;
                            xr_string buffer = ini.r_string(id, "info");
                            XR_LOGIC::parse_infopotions(result, buffer);
                            if (!result.empty())
                            {
                                data.setInfo(result);
                            }
                            else
                            {
                                Msg("[Scripts/Script_GlobalHelper/ctor()] WARNING: can't parse infoportions!!!!!!");
                            }
                        }
                    }

                    if (category_name == "anomalies" || category_name == "place")
                    {
                        if (ini.line_exist(id, "smart"))
                        {
                            data.setSmartTerrainName(ini.r_string(id, "smart"));
                        }
                    }

                    data.setID(CRD_DialogManager::generate_id());
                    this->m_phrase_table[category_name][data.getID()] = data;
                    this->m_phrase_priority_table[category_name];
                }
            }
        }

#pragma region Cordis Registering Dialog Manager functions
        {
            _REGISTER_FUNCTION_DIALOG_MANAGER(init_hello_dialogs, CRD_DialogManager::init_hello_dialogs)
        }
#pragma endregion
#pragma endregion

#pragma region Cordis Registering Schemes set_scheme callbacks
        {
            // Lord: обновлять!
            // @ Мы должны явным образом создать объект и к нему обратиться с получением название схемы которую мы же и
            // указали!
            // @ Во-первых для проверки самих себя
            // @ Во-вторых для проверки самого объекта и возвращаемого члена
            // @ В-третьих даём понять юзверю что мы явным образом регистрируем схему
            // @ В-четрветых понимаем сколько вообще схем используется в игре, да наверное не удобно прописывать так,
            // зато гарантия точности и надёжности
            // @ В-пятых это обусловлено луа у пыс можно было mob_walker.something_like_this(), но у нас так нельзя
            // делать потому что C++ и потому что интерфейсы
            // @ В-шестых луа ловушка джокера никогда не используйте lua в таком сложном backend

            Script_SchemeMobCamp mob_camp = Script_SchemeMobCamp(nullptr, DataBase::Storage_Scheme());
            Script_SchemeMobCombat mob_combat = Script_SchemeMobCombat(nullptr, DataBase::Storage_Scheme());
            Script_SchemeMobDeath mob_death = Script_SchemeMobDeath(nullptr, DataBase::Storage_Scheme());
            Script_SchemeMobHome mob_home = Script_SchemeMobHome(nullptr, DataBase::Storage_Scheme());
            Script_SchemeMobJump mob_jump = Script_SchemeMobJump(nullptr, DataBase::Storage_Scheme());
            Script_SchemeMobRemark mob_remark = Script_SchemeMobRemark(nullptr, DataBase::Storage_Scheme());
            Script_SchemeMobWalker mob_walker = Script_SchemeMobWalker(nullptr, DataBase::Storage_Scheme());
            Script_SchemeHelicopterMove heli_move = Script_SchemeHelicopterMove(nullptr, DataBase::Storage_Scheme());

            this->m_registered_schemes_set_scheme_callbacks[mob_camp.getSchemeName()] =
                Script_SchemeMobCamp::set_scheme;
            this->m_registered_schemes_set_scheme_callbacks[mob_combat.getSchemeName()] =
                Script_SchemeMobCombat::set_scheme;
            this->m_registered_schemes_set_scheme_callbacks[mob_home.getSchemeName()] =
                Script_SchemeMobDeath::set_scheme;
            this->m_registered_schemes_set_scheme_callbacks[mob_jump.getSchemeName()] =
                Script_SchemeMobJump::set_scheme;
            this->m_registered_schemes_set_scheme_callbacks[mob_remark.getSchemeName()] =
                Script_SchemeMobRemark::set_scheme;
            this->m_registered_schemes_set_scheme_callbacks[mob_walker.getSchemeName()] =
                Script_SchemeMobWalker::set_scheme;
            this->m_registered_schemes_set_scheme_callbacks[heli_move.getSchemeName()] =
                Script_SchemeHelicopterMove::set_scheme;

            this->m_registered_schemes_add_to_binder_callbacks[mob_camp.getSchemeName()] =
                Script_SchemeMobCamp::add_to_binder;
            this->m_registered_schemes_add_to_binder_callbacks[mob_combat.getSchemeName()] =
                Script_SchemeMobCombat::add_to_binder;
            this->m_registered_schemes_add_to_binder_callbacks[mob_home.getSchemeName()] =
                Script_SchemeMobHome::add_to_binder;
            this->m_registered_schemes_add_to_binder_callbacks[mob_jump.getSchemeName()] =
                Script_SchemeMobJump::add_to_binder;
            this->m_registered_schemes_add_to_binder_callbacks[mob_remark.getSchemeName()] =
                Script_SchemeMobRemark::add_to_binder;
            this->m_registered_schemes_add_to_binder_callbacks[mob_walker.getSchemeName()] =
                Script_SchemeMobWalker::add_to_binder;
            this->m_registered_schemes_add_to_binder_callbacks[heli_move.getSchemeName()] =
                Script_SchemeHelicopterMove::add_to_binder;
        }
#pragma endregion

#pragma region Cordis registering indoor levels for sr_light scheme
        this->m_indoor_levels["jupiter_underground"] = true;
#pragma endregion

#pragma region Cordis initiazlizing ignore distance for XR_DANGER
        this->m_xr_danger_ignore_distance_by_danger_type[CDangerObject::eDangerTypeAttacked] = 150.0f;
        this->m_xr_danger_ignore_distance_by_danger_type[CDangerObject::eDangerTypeGrenade] = 15.0f;
        this->m_xr_danger_ignore_distance_by_danger_type[CDangerObject::eDangerTypeFreshEntityCorpse] = 10.0f;
        this->m_xr_danger_ignore_distance_by_danger_type[CDangerObject::eDangerTypeEntityAttacked] = 150.0f;
        this->m_xr_danger_ignore_distance_by_danger_type[CDangerObject::eDangerTypeEnemySound] = 0.0f;
        this->m_xr_danger_ignore_distance_by_danger_type[CDangerObject::eDangerTypeAttackSound] = 20.0f;
        this->m_xr_danger_ignore_distance_by_danger_type[CDangerObject::eDangerTypeEntityDeath] = 4.0f;
        this->m_xr_danger_ignore_distance_by_danger_type[CDangerObject::eDangerTypeBulletRicochet] = 2.0f;
#pragma endregion

#pragma region Cordis State Manager Initialzing
        this->m_look_direction_states["threat_na"] = true;
        this->m_look_direction_states["wait_na"] = true;
        this->m_look_direction_states["guard_na"] = true;

        StateManagerAnimationData idle_animation_data;
        idle_animation_data.setPropertiesMaxIdle(5);
        idle_animation_data.setPropertiesSumIdle(3);
        idle_animation_data.setPropertiesRandom(80);

        idle_animation_data.addAnimation("idle", 0, "idle_0_idle_1");
        idle_animation_data.addAnimation("idle", 1, "idle_1_idle_1");
        idle_animation_data.addAnimation("idle", 2, "idle_2_idle_1");
        idle_animation_data.addAnimation("idle", 3, "idle_3_idle_1");
        idle_animation_data.addAnimation("idle", 4, "idle_4_idle_1");
        idle_animation_data.addAnimation("idle", 8, "idle_8_idle_1");
        idle_animation_data.addAnimation("idle", 9, "idle_2_idle_1");
        idle_animation_data.addAnimation("idle", 10, "idle_10_idle_1");

        idle_animation_data.addAnimation("rnd", 0, "idle_0_idle_0");
        idle_animation_data.addAnimation("rnd", 0, "idle_0_idle_2");
        idle_animation_data.addAnimation("rnd", 0, "idle_0_idle_3");
        idle_animation_data.addAnimation("rnd", 0, "idle_0_idle_4");

        idle_animation_data.addAnimation("rnd", 1, "idle_1_idle_0");
        idle_animation_data.addAnimation("rnd", 1, "idle_1_idle_2");
        idle_animation_data.addAnimation("rnd", 1, "idle_1_idle_3");
        idle_animation_data.addAnimation("rnd", 1, "idle_1_idle_4");

        idle_animation_data.addAnimation("rnd", 2, "idle_2_idle_0");
        idle_animation_data.addAnimation("rnd", 2, "idle_2_idle_2");
        idle_animation_data.addAnimation("rnd", 2, "idle_2_idle_3");
        idle_animation_data.addAnimation("rnd", 2, "idle_2_idle_4");

        idle_animation_data.addAnimation("rnd", 3, "idle_3_idle_0");
        idle_animation_data.addAnimation("rnd", 3, "idle_3_idle_2");
        idle_animation_data.addAnimation("rnd", 3, "idle_3_idle_3");
        idle_animation_data.addAnimation("rnd", 3, "idle_3_idle_4");

        idle_animation_data.addAnimation("rnd", 4, "idle_4_idle_0");
        idle_animation_data.addAnimation("rnd", 4, "idle_4_idle_2");
        idle_animation_data.addAnimation("rnd", 4, "idle_4_idle_3");
        idle_animation_data.addAnimation("rnd", 4, "idle_4_idle_4");

        idle_animation_data.addAnimation("rnd", 8, "idle_8_idle_0");
        idle_animation_data.addAnimation("rnd", 8, "idle_8_idle_2");
        idle_animation_data.addAnimation("rnd", 8, "idle_8_idle_3");
        idle_animation_data.addAnimation("rnd", 8, "idle_8_idle_4");

        idle_animation_data.addAnimation("rnd", 9, "idle_2_idle_0");
        idle_animation_data.addAnimation("rnd", 9, "idle_2_idle_2");
        idle_animation_data.addAnimation("rnd", 9, "idle_2_idle_3");
        idle_animation_data.addAnimation("rnd", 9, "idle_2_idle_4");

        idle_animation_data.addAnimation("rnd", 10, "idle_10_idle_0");
        idle_animation_data.addAnimation("rnd", 10, "idle_10_idle_2");
        idle_animation_data.addAnimation("rnd", 10, "idle_10_idle_3");
        idle_animation_data.addAnimation("rnd", 10, "idle_10_idle_4");

        this->m_state_manager_animation_list["idle"] = idle_animation_data;

        StateManagerAnimationData idle_chasovoy_animation_data;
        idle_chasovoy_animation_data.setPropertiesMaxIdle(5);
        idle_chasovoy_animation_data.setPropertiesSumIdle(3);
        idle_chasovoy_animation_data.setPropertiesRandom(80);

        idle_chasovoy_animation_data.addAnimation("idle", 0, "idle_0_idle_1");
        idle_chasovoy_animation_data.addAnimation("idle", 1, "idle_1_idle_1");
        idle_chasovoy_animation_data.addAnimation("idle", 2, "idle_2_idle_1");
        idle_chasovoy_animation_data.addAnimation("idle", 3, "idle_3_idle_1");
        idle_chasovoy_animation_data.addAnimation("idle", 4, "idle_4_idle_1");
        idle_chasovoy_animation_data.addAnimation("idle", 8, "idle_8_idle_1");
        idle_chasovoy_animation_data.addAnimation("idle", 9, "idle_2_idle_1");
        idle_chasovoy_animation_data.addAnimation("idle", 10, "idle_10_idle_1");

        idle_chasovoy_animation_data.addAnimation("rnd", 0, "chasovoy_0");
        idle_chasovoy_animation_data.addAnimation("rnd", 0, "chasovoy_1");
        idle_chasovoy_animation_data.addAnimation("rnd", 0, "chasovoy_2");
        idle_chasovoy_animation_data.addAnimation("rnd", 0, "chasovoy_3");
        idle_chasovoy_animation_data.addAnimation("rnd", 0, "chasovoy_4");

        idle_chasovoy_animation_data.addAnimation("rnd", 1, "chasovoy_0");
        idle_chasovoy_animation_data.addAnimation("rnd", 1, "chasovoy_1");
        idle_chasovoy_animation_data.addAnimation("rnd", 1, "chasovoy_2");
        idle_chasovoy_animation_data.addAnimation("rnd", 1, "chasovoy_3");
        idle_chasovoy_animation_data.addAnimation("rnd", 1, "chasovoy_4");

        idle_chasovoy_animation_data.addAnimation("rnd", 2, "chasovoy_0");
        idle_chasovoy_animation_data.addAnimation("rnd", 2, "chasovoy_1");
        idle_chasovoy_animation_data.addAnimation("rnd", 2, "chasovoy_2");
        idle_chasovoy_animation_data.addAnimation("rnd", 2, "chasovoy_3");
        idle_chasovoy_animation_data.addAnimation("rnd", 2, "chasovoy_4");

        idle_chasovoy_animation_data.addAnimation("rnd", 3, "chasovoy_0");
        idle_chasovoy_animation_data.addAnimation("rnd", 3, "chasovoy_1");
        idle_chasovoy_animation_data.addAnimation("rnd", 3, "chasovoy_2");
        idle_chasovoy_animation_data.addAnimation("rnd", 3, "chasovoy_3");
        idle_chasovoy_animation_data.addAnimation("rnd", 3, "chasovoy_4");

        idle_chasovoy_animation_data.addAnimation("rnd", 4, "chasovoy_0");
        idle_chasovoy_animation_data.addAnimation("rnd", 4, "chasovoy_1");
        idle_chasovoy_animation_data.addAnimation("rnd", 4, "chasovoy_2");
        idle_chasovoy_animation_data.addAnimation("rnd", 4, "chasovoy_3");
        idle_chasovoy_animation_data.addAnimation("rnd", 4, "chasovoy_4");

        idle_chasovoy_animation_data.addAnimation("rnd", 8, "chasovoy_0");
        idle_chasovoy_animation_data.addAnimation("rnd", 8, "chasovoy_1");
        idle_chasovoy_animation_data.addAnimation("rnd", 8, "chasovoy_2");
        idle_chasovoy_animation_data.addAnimation("rnd", 8, "chasovoy_3");
        idle_chasovoy_animation_data.addAnimation("rnd", 8, "chasovoy_4");

        idle_chasovoy_animation_data.addAnimation("rnd", 9, "chasovoy_0");
        idle_chasovoy_animation_data.addAnimation("rnd", 9, "chasovoy_1");
        idle_chasovoy_animation_data.addAnimation("rnd", 9, "chasovoy_2");
        idle_chasovoy_animation_data.addAnimation("rnd", 9, "chasovoy_3");
        idle_chasovoy_animation_data.addAnimation("rnd", 9, "chasovoy_4");

        idle_chasovoy_animation_data.addAnimation("rnd", 10, "chasovoy_0");
        idle_chasovoy_animation_data.addAnimation("rnd", 10, "chasovoy_1");
        idle_chasovoy_animation_data.addAnimation("rnd", 10, "chasovoy_2");
        idle_chasovoy_animation_data.addAnimation("rnd", 10, "chasovoy_3");
        idle_chasovoy_animation_data.addAnimation("rnd", 10, "chasovoy_4");

        this->m_state_manager_animation_list["idle_chasovoy"] = idle_chasovoy_animation_data;

        StateManagerAnimationData caution_animation_data;
        caution_animation_data.setPropertiesMaxIdle(5);
        caution_animation_data.setPropertiesSumIdle(3);
        caution_animation_data.setPropertiesRandom(80);

        caution_animation_data.addAnimation("into", 0, "prisluh_0_in");
        caution_animation_data.addAnimation("into", 1, "prisluh_1_in");
        caution_animation_data.addAnimation("into", 2, "prisluh_2_in");
        caution_animation_data.addAnimation("into", 3, "prisluh_3_in");
        caution_animation_data.addAnimation("into", 4, "prisluh_4_in");
        caution_animation_data.addAnimation("into", 8, "prisluh_8_in");
        caution_animation_data.addAnimation("into", 9, "prisluh_9_in");
        caution_animation_data.addAnimation("into", 10, "prisluh_10_in");

        caution_animation_data.addAnimation("out", 0, "prisluh_0_out");
        caution_animation_data.addAnimation("out", 1, "prisluh_1_out");
        caution_animation_data.addAnimation("out", 2, "prisluh_2_out");
        caution_animation_data.addAnimation("out", 3, "prisluh_3_out");
        caution_animation_data.addAnimation("out", 4, "prisluh_4_out");
        caution_animation_data.addAnimation("out", 8, "prisluh_8_out");
        caution_animation_data.addAnimation("out", 9, "prisluh_9_out");
        caution_animation_data.addAnimation("out", 10, "prisluh_10_out");

        caution_animation_data.addAnimation("idle", 0, "prisluh_0_1");
        caution_animation_data.addAnimation("idle", 1, "prisluh_1_1");
        caution_animation_data.addAnimation("idle", 2, "prisluh_2_1");
        caution_animation_data.addAnimation("idle", 3, "prisluh_3_1");
        caution_animation_data.addAnimation("idle", 4, "prisluh_4_1");
        caution_animation_data.addAnimation("idle", 8, "prisluh_8_1");
        caution_animation_data.addAnimation("idle", 9, "prisluh_9_1");
        caution_animation_data.addAnimation("idle", 10, "prisluh_10_1");

        caution_animation_data.addAnimation("rnd", 0, "prisluh_0_0");
        caution_animation_data.addAnimation("rnd", 0, "prisluh_0_2");
        caution_animation_data.addAnimation("rnd", 1, "prisluh_1_0");
        caution_animation_data.addAnimation("rnd", 1, "prisluh_1_2");
        caution_animation_data.addAnimation("rnd", 2, "prisluh_2_0");
        caution_animation_data.addAnimation("rnd", 2, "prisluh_2_2");
        caution_animation_data.addAnimation("rnd", 3, "prisluh_3_0");
        caution_animation_data.addAnimation("rnd", 3, "prisluh_3_2");
        caution_animation_data.addAnimation("rnd", 4, "prisluh_4_0");
        caution_animation_data.addAnimation("rnd", 4, "prisluh_4_2");
        caution_animation_data.addAnimation("rnd", 8, "prisluh_8_0");
        caution_animation_data.addAnimation("rnd", 8, "prisluh_8_2");
        caution_animation_data.addAnimation("rnd", 9, "prisluh_9_0");
        caution_animation_data.addAnimation("rnd", 9, "prisluh_9_2");
        caution_animation_data.addAnimation("rnd", 10, "prisluh_10_0");
        caution_animation_data.addAnimation("rnd", 10, "prisluh_10_2");

        this->m_state_manager_animation_list["caution"] = caution_animation_data;

        StateManagerAnimationData poisk_animation_data;
        poisk_animation_data.setPropertiesMaxIdle(5);
        poisk_animation_data.setPropertiesSumIdle(3);
        poisk_animation_data.setPropertiesRandom(80);

        poisk_animation_data.addAnimation("idle", 0, "poisk_0_idle_1");
        poisk_animation_data.addAnimation("idle", 1, "poisk_1_idle_1");
        poisk_animation_data.addAnimation("idle", 2, "poisk_2_idle_1");
        poisk_animation_data.addAnimation("idle", 3, "poisk_3_idle_1");
        poisk_animation_data.addAnimation("idle", 4, "poisk_4_idle_1");
        poisk_animation_data.addAnimation("idle", 8, "poisk_8_idle_1");
        poisk_animation_data.addAnimation("idle", 9, "poisk_9_idle_1");
        poisk_animation_data.addAnimation("idle", 10, "poisk_10_idle_1");

        poisk_animation_data.addAnimation("rnd", 0, "poisk_0_idle_0");
        poisk_animation_data.addAnimation("rnd", 0, "poisk_0_idle_2");
        poisk_animation_data.addAnimation("rnd", 1, "poisk_1_idle_0");
        poisk_animation_data.addAnimation("rnd", 1, "poisk_1_idle_2");
        poisk_animation_data.addAnimation("rnd", 2, "poisk_2_idle_0");
        poisk_animation_data.addAnimation("rnd", 2, "poisk_2_idle_2");
        poisk_animation_data.addAnimation("rnd", 3, "poisk_3_idle_0");
        poisk_animation_data.addAnimation("rnd", 3, "poisk_3_idle_2");
        poisk_animation_data.addAnimation("rnd", 4, "poisk_4_idle_0");
        poisk_animation_data.addAnimation("rnd", 4, "poisk_4_idle_2");
        poisk_animation_data.addAnimation("rnd", 8, "poisk_8_idle_0");
        poisk_animation_data.addAnimation("rnd", 8, "poisk_8_idle_2");
        poisk_animation_data.addAnimation("rnd", 9, "poisk_9_idle_0");
        poisk_animation_data.addAnimation("rnd", 9, "poisk_9_idle_2");
        poisk_animation_data.addAnimation("rnd", 10, "poisk_10_idle_0");
        poisk_animation_data.addAnimation("rnd", 10, "poisk_10_idle_2");

        this->m_state_manager_animation_list["poisk"] = poisk_animation_data;

        StateManagerAnimationData stoop_no_weap_animation_data;
        stoop_no_weap_animation_data.setPropertiesMaxIdle(2);
        stoop_no_weap_animation_data.setPropertiesSumIdle(1);
        stoop_no_weap_animation_data.setPropertiesRandom(80);

        stoop_no_weap_animation_data.addAnimation("idle", 0, "poisk_0_idle_0");

        this->m_state_manager_animation_list["stoop_no_weap"] = stoop_no_weap_animation_data;

        StateManagerAnimationData hide_animation_data;
        hide_animation_data.setPropertiesMaxIdle(5);
        hide_animation_data.setPropertiesSumIdle(3);
        hide_animation_data.setPropertiesRandom(80);

        hide_animation_data.addAnimation("into", 0, "cr_idle_0_in");
        hide_animation_data.addAnimation("into", 1, "cr_idle_1_in");
        hide_animation_data.addAnimation("into", 2, "cr_idle_2_in");
        hide_animation_data.addAnimation("into", 3, "cr_idle_3_in");
        hide_animation_data.addAnimation("into", 4, "cr_idle_4_in");
        hide_animation_data.addAnimation("into", 8, "cr_idle_8_in");
        hide_animation_data.addAnimation("into", 9, "cr_idle_9_in");
        hide_animation_data.addAnimation("into", 10, "cr_idle_10_in");

        hide_animation_data.addAnimation("out", 0, "cr_idle_0_out");
        hide_animation_data.addAnimation("out", 1, "cr_idle_1_out");
        hide_animation_data.addAnimation("out", 2, "cr_idle_2_out");
        hide_animation_data.addAnimation("out", 3, "cr_idle_3_out");
        hide_animation_data.addAnimation("out", 4, "cr_idle_4_out");
        hide_animation_data.addAnimation("out", 8, "cr_idle_8_out");
        hide_animation_data.addAnimation("out", 9, "cr_idle_9_out");
        hide_animation_data.addAnimation("out", 10, "cr_idle_10_out");

        hide_animation_data.addAnimation("idle", 0, "cr_idle_0_1");
        hide_animation_data.addAnimation("idle", 1, "cr_idle_1_1");
        hide_animation_data.addAnimation("idle", 2, "cr_idle_2_1");
        hide_animation_data.addAnimation("idle", 3, "cr_idle_3_1");
        hide_animation_data.addAnimation("idle", 4, "cr_idle_4_1");
        hide_animation_data.addAnimation("idle", 8, "cr_idle_8_1");
        hide_animation_data.addAnimation("idle", 9, "cr_idle_9_1");
        hide_animation_data.addAnimation("idle", 10, "cr_idle_10_1");

        hide_animation_data.addAnimation("rnd", 0, "cr_idle_0_0");
        hide_animation_data.addAnimation("rnd", 0, "cr_idle_0_2");
        hide_animation_data.addAnimation("rnd", 1, "cr_idle_1_0");
        hide_animation_data.addAnimation("rnd", 1, "cr_idle_1_2");
        hide_animation_data.addAnimation("rnd", 2, "cr_idle_2_0");
        hide_animation_data.addAnimation("rnd", 2, "cr_idle_2_2");
        hide_animation_data.addAnimation("rnd", 3, "cr_idle_3_0");
        hide_animation_data.addAnimation("rnd", 3, "cr_idle_3_2");
        hide_animation_data.addAnimation("rnd", 4, "cr_idle_4_0");
        hide_animation_data.addAnimation("rnd", 4, "cr_idle_4_2");
        hide_animation_data.addAnimation("rnd", 8, "cr_idle_8_0");
        hide_animation_data.addAnimation("rnd", 8, "cr_idle_8_2");
        hide_animation_data.addAnimation("rnd", 9, "cr_idle_9_0");
        hide_animation_data.addAnimation("rnd", 9, "cr_idle_9_2");
        hide_animation_data.addAnimation("rnd", 10, "cr_idle_10_0");
        hide_animation_data.addAnimation("rnd", 10, "cr_idle_10_2");

        this->m_state_manager_animation_list["hide"] = hide_animation_data;

        StateManagerAnimationData play_guitar_animation_data;
        play_guitar_animation_data.setPropertiesMaxIdle(3);
        play_guitar_animation_data.setPropertiesSumIdle(3);
        play_guitar_animation_data.setPropertiesRandom(80);

        play_guitar_animation_data.addAnimation("into", 0, "sit_1_guitar_0_0");
        play_guitar_animation_data.addAnimationAttachItemName("into", 0, "guitar_a");
        //       play_guitar_animation_data.addAnimationFunction(sr_camp.play_guitar) Lord: реализовать!
        play_guitar_animation_data.addAnimation("into", 0, "sit_1_guitar_0_1");

        play_guitar_animation_data.addAnimation("out", 0, "guitar_0_sit_1_0");
        play_guitar_animation_data.addAnimationDettachItemName("out", 0, "guitar_a");
        play_guitar_animation_data.addAnimationDettachItemName("out", 0, "guitar_0_sit_1_1");

        play_guitar_animation_data.addAnimation("idle", 0, "guitar_0");

        this->m_state_manager_animation_list["play_guitar"] = play_guitar_animation_data;

        StateManagerAnimationData play_harmonica_animation_data;
        play_harmonica_animation_data.setPropertiesMaxIdle(3);
        play_harmonica_animation_data.setPropertiesSumIdle(3);
        play_harmonica_animation_data.setPropertiesRandom(80);

        play_harmonica_animation_data.addAnimation("into", 0, "sit_2_harmonica_1_0");
        play_harmonica_animation_data.addAnimationAttachItemName("into", 0, "harmonica_a");
        //    play_harmonica_animation_data.addAnimationFunction(sr_camp.start_harmonica); Lord: реализовать!
        play_harmonica_animation_data.addAnimation("into", 0, "sit_2_harmonica_1_1");

        play_harmonica_animation_data.addAnimation("out", 0, "harmonica_1_sit_2_0");
        play_harmonica_animation_data.addAnimationDettachItemName("out", 0, "harmonica_a");
        play_harmonica_animation_data.addAnimation("out", 0, "harmonica_1_sit_2_1");

        play_harmonica_animation_data.addAnimation("idle", 0, "harmonica_0");

        this->m_state_manager_animation_list["play_harmonica"] = play_harmonica_animation_data;

        StateManagerAnimationData hello_animation_data;
        hello_animation_data.setPropertiesMaxIdle(5);
        hello_animation_data.setPropertiesSumIdle(5);
        hello_animation_data.setPropertiesRandom(100);

        hello_animation_data.addAnimation("rnd", 0, "hello_0_idle_0");
        hello_animation_data.addAnimation("rnd", 1, "hello_1_idle_0");
        hello_animation_data.addAnimation("rnd", 2, "hello_2_idle_0");
        hello_animation_data.addAnimation("rnd", 3, "hello_3_idle_0");
        hello_animation_data.addAnimation("rnd", 4, "hello_4_idle_0");
        hello_animation_data.addAnimation("rnd", 8, "hello_8_idle_0");
        hello_animation_data.addAnimation("rnd", 9, "hello_9_idle_0");
        hello_animation_data.addAnimation("rnd", 10, "hello_10_idle_0");

        this->m_state_manager_animation_list["hello"] = hello_animation_data;

        StateManagerAnimationData refuse_animation_data;
        refuse_animation_data.setPropertiesMaxIdle(3);
        refuse_animation_data.setPropertiesSumIdle(3);
        refuse_animation_data.setPropertiesRandom(100);

        refuse_animation_data.addAnimation("rnd", 0, "net_0_0");
        refuse_animation_data.addAnimation("rnd", 1, "net_1_0");
        refuse_animation_data.addAnimation("rnd", 2, "net_2_0");
        refuse_animation_data.addAnimation("rnd", 3, "net_3_0");
        refuse_animation_data.addAnimation("rnd", 4, "net_4_0");
        refuse_animation_data.addAnimation("rnd", 8, "net_8_0");
        refuse_animation_data.addAnimation("rnd", 9, "net_9_0");
        refuse_animation_data.addAnimation("rnd", 10, "net_10_0");

        this->m_state_manager_animation_list["refuse"] = refuse_animation_data;

        StateManagerAnimationData claim_animation_data;
        claim_animation_data.setPropertiesMaxIdle(5);
        claim_animation_data.setPropertiesSumIdle(2);
        claim_animation_data.setPropertiesRandom(100);

        claim_animation_data.addAnimation("rnd", 1, "gop_stop_1_0");
        claim_animation_data.addAnimation("rnd", 2, "gop_stop_2_0");
        claim_animation_data.addAnimation("rnd", 3, "gop_stop_3_0");
        claim_animation_data.addAnimation("rnd", 4, "gop_stop_4_0");
        claim_animation_data.addAnimation("rnd", 8, "gop_stop_8_0");
        claim_animation_data.addAnimation("rnd", 9, "gop_stop_9_0");
        claim_animation_data.addAnimation("rnd", 10, "gop_stop_10_0");

        this->m_state_manager_animation_list["claim"] = claim_animation_data;

        StateManagerAnimationData backoff_animation_data;
        backoff_animation_data.setPropertiesMaxIdle(5);
        backoff_animation_data.setPropertiesSumIdle(2);
        backoff_animation_data.setPropertiesRandom(100);

        backoff_animation_data.addAnimation("rnd", 0, "uhodi_1_0");
        backoff_animation_data.addAnimation("rnd", 0, "uhodi_1_1");
        backoff_animation_data.addAnimation("rnd", 1, "uhodi_1_0");
        backoff_animation_data.addAnimation("rnd", 1, "uhodi_1_1");
        backoff_animation_data.addAnimation("rnd", 2, "uhodi_2_0");
        backoff_animation_data.addAnimation("rnd", 2, "uhodi_2_1");
        backoff_animation_data.addAnimation("rnd", 3, "uhodi_3_0");
        backoff_animation_data.addAnimation("rnd", 3, "uhodi_3_1");
        backoff_animation_data.addAnimation("rnd", 4, "uhodi_4_0");
        backoff_animation_data.addAnimation("rnd", 4, "uhodi_4_1");
        backoff_animation_data.addAnimation("rnd", 8, "uhodi_8_0");
        backoff_animation_data.addAnimation("rnd", 8, "uhodi_8_1");
        backoff_animation_data.addAnimation("rnd", 9, "uhodi_9_0");
        backoff_animation_data.addAnimation("rnd", 9, "uhodi_9_1");
        backoff_animation_data.addAnimation("rnd", 10, "uhodi_10_0");
        backoff_animation_data.addAnimation("rnd", 10, "uhodi_10_1");

        this->m_state_manager_animation_list["backoff"] = backoff_animation_data;

        StateManagerAnimationData punch_animation_data;
        punch_animation_data.setPropertiesMaxIdle(5);
        punch_animation_data.setPropertiesSumIdle(2);
        punch_animation_data.setPropertiesRandom(100);

        punch_animation_data.addAnimation("into", 0, "norm_facer_0_0");
        // punch_animation_data.addAnimationFunction("into", 0, xr_effects.actor_punch); Lord: реализовать!
        punch_animation_data.addAnimation("into", 0, "norm_facer_0_1");
        // punch_animation_data.addAnimationFunction("into", 0, xr_effects.clearAbuse); Lord: реализовать!
        punch_animation_data.addAnimation("into", 1, "norm_facer_1_0");
        // punch_animation_data.addAnimationFunction("into", 1, xr_effects.actor_punch); Lord: реализовать!
        punch_animation_data.addAnimation("into", 1, "norm_facer_1_1");
        // punch_animation_data.addAnimationFunction("into", 1, xr_effects.clearAbuse); Lord: реализовать!
        punch_animation_data.addAnimation("into", 2, "norm_facer_2_0");
        // punch_animation_data.addAnimationFunction("into", 2, xr_effects.actor_punch); Lord: реализовать!
        punch_animation_data.addAnimation("into", 2, "norm_facer_2_1");
        // punch_animation_data.addAnimationFunction("into", 2, xr_effects.clearAbuse); Lord: реализовать!
        punch_animation_data.addAnimation("into", 3, "norm_facer_3_0");
        // punch_animation_data.addAnimationFunction("into", 3, xr_effects.actor_punch); Lord: реализовать!
        punch_animation_data.addAnimation("into", 3, "norm_facer_3_1");
        // punch_animation_data.addAnimationFunction("into", 3, xr_effects.clearAbuse); Lord: реализовать!
        punch_animation_data.addAnimation("into", 4, "norm_facer_4_0");
        // punch_animation_data.addAnimationFunction("into", 4, xr_effects.actor_punch); Lord: реализовать!
        punch_animation_data.addAnimation("into", 4, "norm_facer_4_1");
        // punch_animation_data.addAnimationFunction("into", 4, xr_effects.clearAbuse); Lord: реализовать!
        punch_animation_data.addAnimation("into", 8, "norm_facer_8_0");
        // punch_animation_data.addAnimationFunction("into", 8, xr_effects.actor_punch); Lord: реализовать!
        punch_animation_data.addAnimation("into", 8, "norm_facer_8_1");
        // punch_animation_data.addAnimationFunction("into", 8, xr_effects.clearAbuse); Lord: реализовать!
        punch_animation_data.addAnimation("into", 9, "norm_facer_9_0");
        // punch_animation_data.addAnimationFunction("into", 9, xr_effects.actor_punch); Lord: реализовать!
        punch_animation_data.addAnimation("into", 9, "norm_facer_9_1");
        // punch_animation_data.addAnimationFunction("into", 9, xr_effects.clearAbuse); Lord: реализовать!
        punch_animation_data.addAnimation("into", 10, "norm_facer_10_0");
        // punch_animation_data.addAnimationFunction("into", 10, xr_effects.actor_punch); Lord: реализовать!
        punch_animation_data.addAnimation("into", 10, "norm_facer_10_1");
        // punch_animation_data.addAnimationFunction("into", 10, xr_effects.clearAbuse); Lord: реализовать!

        this->m_state_manager_animation_list["punch"] = punch_animation_data;

        StateManagerAnimationData sleeping_animation_data;
        sleeping_animation_data.setPropertiesMaxIdle(5);
        sleeping_animation_data.setPropertiesSumIdle(10);
        sleeping_animation_data.setPropertiesRandom(100);

        sleeping_animation_data.addAnimation("into", 0, "idle_0_to_sit_0");
        sleeping_animation_data.addAnimation("into", 0, "sit_to_sleep_0");
        sleeping_animation_data.addAnimation("out", 0, "sleep_to_sit_0");
        sleeping_animation_data.addAnimation("out", 0, "sit_0_to_idle_0");
        sleeping_animation_data.addAnimation("idle", 0, "sleep_idle_0");
        sleeping_animation_data.addAnimation("rnd", 0, "sleep_idle_1");

        this->m_state_manager_animation_list["sleeping"] = sleeping_animation_data;

        StateManagerAnimationData wounded_animation_data;
        wounded_animation_data.setPropertiesMaxIdle(5);
        wounded_animation_data.setPropertiesSumIdle(10);
        wounded_animation_data.setPropertiesRandom(70);

        wounded_animation_data.addAnimation("into", 0, "idle_to_wounded_0");
        wounded_animation_data.addAnimation("out", 0, "wounded_to_idle_0");
        wounded_animation_data.addAnimation("idle", 0, "wounded_idle_0");

        this->m_state_manager_animation_list["wounded"] = wounded_animation_data;

        StateManagerAnimationData wounded_heavy_1_animation_data;
        wounded_heavy_1_animation_data.setPropertiesMaxIdle(5);
        wounded_heavy_1_animation_data.setPropertiesSumIdle(10);
        wounded_heavy_1_animation_data.setPropertiesRandom(70);

        wounded_heavy_1_animation_data.addAnimation("into", 0, "idle_to_wounded_1");
        wounded_heavy_1_animation_data.addAnimation("out", 0, "waunded_1_out");
        wounded_heavy_1_animation_data.addAnimation("idle", 0, "waunded_1_idle_0");

        this->m_state_manager_animation_list["wounded_heavy_1"] = wounded_heavy_1_animation_data;

        StateManagerAnimationData wounded_heavy_2_animation_data;
        wounded_heavy_2_animation_data.setPropertiesMaxIdle(5);
        wounded_heavy_2_animation_data.setPropertiesSumIdle(10);
        wounded_heavy_2_animation_data.setPropertiesRandom(70);

        wounded_heavy_2_animation_data.addAnimation("into", 0, "idle_to_wounded_2");
        wounded_heavy_2_animation_data.addAnimation("out", 0, "wounded_2_out");
        wounded_heavy_2_animation_data.addAnimation("idle", 0, "wounded_2_idle_0");

        this->m_state_manager_animation_list["wounded_heavy_2"] = wounded_heavy_2_animation_data;

        StateManagerAnimationData wounded_heavy_3_animation_data;
        wounded_heavy_3_animation_data.setPropertiesMaxIdle(5);
        wounded_heavy_3_animation_data.setPropertiesSumIdle(10);
        wounded_heavy_3_animation_data.setPropertiesRandom(70);

        wounded_heavy_3_animation_data.addAnimation("idle", 0, "idle_to_wounded_3");
        wounded_heavy_3_animation_data.addAnimation("out", 0, "wounded_3_out");
        wounded_heavy_3_animation_data.addAnimation("idle", 0, "wounded_3_idle_0");

        this->m_state_manager_animation_list["wounded_heavy_3"] = wounded_heavy_3_animation_data;

        StateManagerAnimationData wounded_zombie_animation_data;
        wounded_zombie_animation_data.setPropertiesMaxIdle(5);
        wounded_zombie_animation_data.setPropertiesSumIdle(10);
        wounded_zombie_animation_data.setPropertiesRandom(70);

        wounded_zombie_animation_data.addAnimation("into", 0, "idle_to_wounded_0");
        wounded_zombie_animation_data.addAnimation("out", 0, "wounded_to_idle_0");
        wounded_zombie_animation_data.addAnimation("idle", 0, "wounded_idle_0");
        wounded_zombie_animation_data.addAnimation("rnd", 0, "wounded_idle_1");

        this->m_state_manager_animation_list["wounded_zombie"] = wounded_zombie_animation_data;

        StateManagerAnimationData choosing_animation_data;
        choosing_animation_data.setPropertiesMaxIdle(8);
        choosing_animation_data.setPropertiesSumIdle(10);
        choosing_animation_data.setPropertiesRandom(80);

        choosing_animation_data.addAnimation("rnd", 0, "komandir_0");
        choosing_animation_data.addAnimation("rnd", 0, "komandir_1");
        choosing_animation_data.addAnimation("rnd", 0, "komandir_2");

        this->m_state_manager_animation_list["choosing"] = choosing_animation_data;

        StateManagerAnimationData press_animation_data;
        press_animation_data.setPropertiesMaxIdle(8);
        press_animation_data.setPropertiesSumIdle(10);
        press_animation_data.setPropertiesRandom(80);

        press_animation_data.addAnimation("into", 0, "knopka_0");
        press_animation_data.addAnimation("out", 0, "knopka_1");
        press_animation_data.addAnimation("idle", 0, "knopka_2");

        this->m_state_manager_animation_list["press"] = press_animation_data;

        StateManagerAnimationData warding_animation_data;
        warding_animation_data.setPropertiesMaxIdle(10);
        warding_animation_data.setPropertiesSumIdle(10);
        warding_animation_data.setPropertiesRandom(0);

        warding_animation_data.addAnimation("idle", 0, "ohrana_0");
        warding_animation_data.addAnimation("out", 0, "ohrana_2");
        warding_animation_data.addAnimation("idle", 0, "ohrana_1");

        this->m_state_manager_animation_list["warding"] = warding_animation_data;

        StateManagerAnimationData warding_short_animation_data;
        warding_short_animation_data.setPropertiesMaxIdle(10);
        warding_short_animation_data.setPropertiesSumIdle(10);
        warding_short_animation_data.setPropertiesRandom(0);

        warding_short_animation_data.addAnimation("into", 0, "ohrana_0");
        warding_short_animation_data.addAnimation("out", 0, "ohrana_2");
        warding_short_animation_data.addAnimation("idle", 0, "ohrana_1_short");

        this->m_state_manager_animation_list["warding_short"] = warding_short_animation_data;

        StateManagerAnimationData fold_arms_animation_data;
        fold_arms_animation_data.setPropertiesMaxIdle(10);
        fold_arms_animation_data.setPropertiesSumIdle(10);
        fold_arms_animation_data.setPropertiesRandom(0);

        fold_arms_animation_data.addAnimation("idle", 0, "cut_scene_idle_0");

        this->m_state_manager_animation_list["fold_arms"] = fold_arms_animation_data;

        StateManagerAnimationData talk_default_animation_data;
        talk_default_animation_data.setPropertiesMaxIdle(5);
        talk_default_animation_data.setPropertiesSumIdle(5);
        talk_default_animation_data.setPropertiesRandom(70);

        talk_default_animation_data.addAnimation("into", 2, "norm_talk_2_in_0");
        talk_default_animation_data.addAnimation("out", 2, "norm_talk_2_out_0");
        talk_default_animation_data.addAnimation("idle", 0, "idle_0_idle_1");
        talk_default_animation_data.addAnimation("idle", 2, "norm_talk_2_idle_1");
        talk_default_animation_data.addAnimation("rnd", 0, "idle_0_idle_0");
        talk_default_animation_data.addAnimation("rnd", 2, "norm_talk_2_idle_0");
        talk_default_animation_data.addAnimation("rnd", 2, "norm_talk_2_idle_2");
        talk_default_animation_data.addAnimation("rnd", 2, "norm_talk_2_idle_3");
        talk_default_animation_data.addAnimation("rnd", 2, "norm_talk_2_idle_4");

        this->m_state_manager_animation_list["talk_default"] = talk_default_animation_data;

        StateManagerAnimationData binocular_animation_data;
        binocular_animation_data.setPropertiesMaxIdle(1);
        binocular_animation_data.setPropertiesSumIdle(1);
        binocular_animation_data.setPropertiesRandom(100);

        binocular_animation_data.addAnimation("into", 0, "binoculars_draw_0");
        binocular_animation_data.addAnimationAttachItemName("into", 0, "wpn_binoc");
        binocular_animation_data.addAnimation("into", 0, "binoculars_draw_1");
        binocular_animation_data.addAnimation("into", 0, "binoculars_zoom_in_0");

        binocular_animation_data.addAnimation("out", 0, "binoculars_zoom_out_0");
        binocular_animation_data.addAnimation("out", 0, "binoculars_hide_0");
        binocular_animation_data.addAnimationAttachItemName("out", 0, "wpn_binoc");
        binocular_animation_data.addAnimation("out", 0, "binoculars_hide_1");

        binocular_animation_data.addAnimation("idle", 0, "binoculars_zoom_idle_0");

        binocular_animation_data.addAnimation("rnd", 0, "binoculars_zoom_idle_1");
        binocular_animation_data.addAnimation("rnd", 0, "binoculars_zoom_idle_2");
        binocular_animation_data.addAnimation("rnd", 0, "binoculars_zoom_idle_3");
        binocular_animation_data.addAnimation("rnd", 0, "binoculars_zoom_idle_4");

        this->m_state_manager_animation_list["binocular"] = binocular_animation_data;

        StateManagerAnimationData salut_animation_data;
        salut_animation_data.setPropertiesMaxIdle(1);
        salut_animation_data.setPropertiesSumIdle(1);
        salut_animation_data.setPropertiesRandom(100);

        salut_animation_data.addAnimation("into", 0, "chest_0_idle_0");
        salut_animation_data.addAnimation("into", 0, "chest_0_idle_2");

        salut_animation_data.addAnimation("out", 0, "chest_0_idle_3");

        salut_animation_data.addAnimation("idle", 0, "chest_0_idle_1");

        this->m_state_manager_animation_list["salut"] = salut_animation_data;

        StateManagerAnimationData salut_free_animation_data;
        salut_free_animation_data.setPropertiesMaxIdle(1);
        salut_free_animation_data.setPropertiesSumIdle(1);
        salut_free_animation_data.setPropertiesRandom(100);

        salut_free_animation_data.addAnimation("into", 0, "chest_1_idle_0");

        this->m_state_manager_animation_list["salut_free"] = salut_free_animation_data;

        StateManagerAnimationData hands_up_animation_data;
        hands_up_animation_data.setPropertiesMaxIdle(1);
        hands_up_animation_data.setPropertiesSumIdle(1);
        hands_up_animation_data.setPropertiesRandom(100);

        hands_up_animation_data.addAnimation("idle", 0, "hand_up_0");

        this->m_state_manager_animation_list["hands_up"] = hands_up_animation_data;

        StateManagerAnimationData trans_0_animation_data;
        trans_0_animation_data.setPropertiesMaxIdle(1);
        trans_0_animation_data.setPropertiesSumIdle(1);
        trans_0_animation_data.setPropertiesRandom(100);

        trans_0_animation_data.addAnimation("into", 0, "idle_0_to_trans_0");
        trans_0_animation_data.addAnimation("out", 0, "trans_0_to_idle_0");
        trans_0_animation_data.addAnimation("idle", 0, "trans_0_idle_0");

        this->m_state_manager_animation_list["trans_0"] = trans_0_animation_data;

        StateManagerAnimationData trans_1_animation_data;
        trans_1_animation_data.setPropertiesMaxIdle(1);
        trans_1_animation_data.setPropertiesSumIdle(1);
        trans_1_animation_data.setPropertiesRandom(100);

        trans_1_animation_data.addAnimation("into", 0, "idle_0_to_trans_1");
        trans_1_animation_data.addAnimation("out", 0, "trans_1_to_idle_0");
        trans_1_animation_data.addAnimation("idle", 0, "trans_1_idle_0");

        this->m_state_manager_animation_list["trans_1"] = trans_1_animation_data;

        StateManagerAnimationData trans_zombied_animation_data;
        trans_zombied_animation_data.setPropertiesMaxIdle(1);
        trans_zombied_animation_data.setPropertiesSumIdle(1);
        trans_zombied_animation_data.setPropertiesRandom(100);

        trans_zombied_animation_data.addAnimation("into", 0, "trans_0_idle_1");
        trans_zombied_animation_data.addAnimation("out", 0, "trans_0_idle_0");
        trans_zombied_animation_data.addAnimation("out", 0, "trans_0_idle_2");
        trans_zombied_animation_data.addAnimation("out", 0, "trans_0_idle_3");
        trans_zombied_animation_data.addAnimation("out", 0, "trans_0_idle_4");
        trans_zombied_animation_data.addAnimation("out", 0, "trans_0_idle_5");
        trans_zombied_animation_data.addAnimation("out", 0, "trans_0_idle_6");

        this->m_state_manager_animation_list["trans_zombied"] = trans_zombied_animation_data;

        StateManagerAnimationData probe_stand_animation_data;
        probe_stand_animation_data.setPropertiesMaxIdle(0);
        probe_stand_animation_data.setPropertiesSumIdle(0);
        probe_stand_animation_data.setPropertiesRandom(100);

        probe_stand_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_0");
        //  probe_stand_animation_data.addAnimationFunction("into", 0, XR_EFFECTS.get_best_detector); Lord: реализовать!
        probe_stand_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_1");

        probe_stand_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_0");
        //  probe_stand_animation_data.addAnimationFunction("out", 0, XR_EFFECTS.hide_best_detector); Lord: реализовать!
        probe_stand_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_1");

        probe_stand_animation_data.addAnimation("idle", 0, "metering_anomalys_0_idle_0");

        probe_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_1");
        probe_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_2");
        probe_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_3");
        probe_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_4");
        probe_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_5");

        this->m_state_manager_animation_list["probe_stand"] = probe_stand_animation_data;

        StateManagerAnimationData probe_way_animation_data;
        probe_way_animation_data.setPropertiesMaxIdle(0);
        probe_way_animation_data.setPropertiesSumIdle(0);
        probe_way_animation_data.setPropertiesRandom(100);

        probe_way_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_0");
        //     probe_way_animation_data.addAnimationFunction("into", 0, XR_EFFECTS.get_best_detector); Lord:
        //     реализовать!
        probe_way_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_1");
        probe_way_animation_data.addAnimation("into", 0, "metering_anomalys_0_idle_6");

        probe_way_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_0");
        //  probe_way_animation_data.addAnimationFunction("out", 0, XR_EFFECTS.hide_best_detector); Lord: реализовать
        probe_way_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_1");

        probe_way_animation_data.addAnimation("idle", 0, "metering_anomalys_0_idle_0");

        this->m_state_manager_animation_list["probe_way"] = probe_way_animation_data;

        StateManagerAnimationData probe_crouch_animation_data;
        probe_crouch_animation_data.setPropertiesMaxIdle(0);
        probe_crouch_animation_data.setPropertiesSumIdle(0);
        probe_crouch_animation_data.setPropertiesRandom(100);

        probe_crouch_animation_data.addAnimation("into", 0, "metering_anomalys_1_draw_0");
        // probe_crouch_animation_data.addAnimationFunction("into", 0, XR_EFFECTS.get_best_detector); Lord: реализовать!
        probe_crouch_animation_data.addAnimation("into", 0, "metering_anomalys_1_draw_1");

        probe_crouch_animation_data.addAnimation("out", 0, "metering_anomalys_1_hide_0");
        //    probe_crouch_animation_data.addAnimationDettachItemName("out", 0, XR_EFFECTS.hide_best_detector); Lord:
        //    реализовать!
        probe_crouch_animation_data.addAnimation("out", 0, "metering_anomalys_1_hide_1");

        probe_crouch_animation_data.addAnimation("idle", 0, "metering_anomalys_1_idle_0");

        probe_crouch_animation_data.addAnimation("rnd", 0, "metering_anomalys_1_idle_1");
        probe_crouch_animation_data.addAnimation("rnd", 0, "metering_anomalys_1_idle_2");
        probe_crouch_animation_data.addAnimation("rnd", 0, "metering_anomalys_1_idle_3");
        probe_crouch_animation_data.addAnimation("rnd", 0, "metering_anomalys_1_idle_4");

        this->m_state_manager_animation_list["probe_crouch"] = probe_crouch_animation_data;

        StateManagerAnimationData scaner_stand_animation_data;
        scaner_stand_animation_data.setPropertiesMaxIdle(0);
        scaner_stand_animation_data.setPropertiesSumIdle(0);
        scaner_stand_animation_data.setPropertiesRandom(100);

        scaner_stand_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_0");
        scaner_stand_animation_data.addAnimationAttachItemName("into", 0, "anomaly_scaner");
        scaner_stand_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_1");

        scaner_stand_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_0");
        scaner_stand_animation_data.addAnimationDettachItemName("out", 0, "anomaly_scaner");
        scaner_stand_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_1");

        scaner_stand_animation_data.addAnimation("idle", 0, "metering_anomalys_0_idle_0");

        scaner_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_1");
        scaner_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_2");
        scaner_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_3");
        scaner_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_4");
        scaner_stand_animation_data.addAnimation("rnd", 0, "metering_anomalys_0_idle_5");

        this->m_state_manager_animation_list["scaner_stand"] = scaner_stand_animation_data;

        StateManagerAnimationData scaner_way_animation_data;
        scaner_way_animation_data.setPropertiesMaxIdle(0);
        scaner_way_animation_data.setPropertiesSumIdle(0);
        scaner_way_animation_data.setPropertiesRandom(100);

        scaner_way_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_0");
        scaner_way_animation_data.addAnimationAttachItemName("into", 0, "anomaly_scaner");
        scaner_way_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_1");
        scaner_way_animation_data.addAnimation("into", 0, "metering_anomalys_0_idle_6");

        scaner_way_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_0");
        scaner_way_animation_data.addAnimationDettachItemName("out", 0, "anomaly_scaner");
        scaner_way_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_1");

        scaner_way_animation_data.addAnimation("idle", 0, "metering_anomalys_0_idle_0");

        this->m_state_manager_animation_list["scaner_way"] = scaner_way_animation_data;

        StateManagerAnimationData scaner_crouch_animation_data;
        scaner_crouch_animation_data.setPropertiesMaxIdle(0);
        scaner_crouch_animation_data.setPropertiesSumIdle(0);
        scaner_crouch_animation_data.setPropertiesRandom(100);

        scaner_crouch_animation_data.addAnimation("into", 0, "metering_anomalys_1_draw_0");
        scaner_crouch_animation_data.addAnimationAttachItemName("into", 0, "anomaly_scaner");
        scaner_crouch_animation_data.addAnimation("into", 0, "metering_anomalys_1_draw_1");

        scaner_crouch_animation_data.addAnimation("out", 0, "metering_anomalys_1_hide_0");
        scaner_crouch_animation_data.addAnimationDettachItemName("out", 0, "anomaly_scaner");
        scaner_crouch_animation_data.addAnimation("out", 0, "metering_anomalys_1_hide_1");

        scaner_crouch_animation_data.addAnimation("idle", 0, "metering_anomalys_1_idle_0");

        scaner_crouch_animation_data.addAnimation("rnd", 0, "metering_anomalys_1_idle_1");
        scaner_crouch_animation_data.addAnimation("rnd", 0, "metering_anomalys_1_idle_2");
        scaner_crouch_animation_data.addAnimation("rnd", 0, "metering_anomalys_1_idle_3");
        scaner_crouch_animation_data.addAnimation("rnd", 0, "metering_anomalys_1_idle_4");

        this->m_state_manager_animation_list["scaner_crouch"] = scaner_crouch_animation_data;

        StateManagerAnimationData prisoner_animation_data;
        prisoner_animation_data.setPropertiesMaxIdle(1);
        prisoner_animation_data.setPropertiesSumIdle(1);
        prisoner_animation_data.setPropertiesRandom(100);

        prisoner_animation_data.addAnimation("into", 0, "prisoner_0_sit_down_0");
        prisoner_animation_data.addAnimation("out", 0, "prisoner_0_stand_up_0");
        prisoner_animation_data.addAnimation("idle", 0, "prisoner_0_sit_idle_0");

        this->m_state_manager_animation_list["prisoner"] = prisoner_animation_data;

        StateManagerAnimationData raciya_animation_data;
        raciya_animation_data.setPropertiesMaxIdle(1);
        raciya_animation_data.setPropertiesSumIdle(1);
        raciya_animation_data.setPropertiesRandom(100);

        raciya_animation_data.addAnimation("into", 0, "raciya_0_draw_0");
        raciya_animation_data.addAnimationAttachItemName("into", 0, "hand_radio");
        raciya_animation_data.addAnimation("into", 0, "raciya_0_draw_1");
        raciya_animation_data.addAnimation("into", 1, "raciya_1_draw_0");
        raciya_animation_data.addAnimationAttachItemName("into", 1, "hand_radio");
        raciya_animation_data.addAnimation("into", 1, "raciya_1_draw_1");
        raciya_animation_data.addAnimation("into", 2, "raciya_2_draw_0");
        raciya_animation_data.addAnimationAttachItemName("into", 2, "hand_radio");
        raciya_animation_data.addAnimation("into", 2, "raciya_2_draw_1");
        raciya_animation_data.addAnimation("into", 3, "raciya_3_draw_0");
        raciya_animation_data.addAnimationAttachItemName("into", 3, "hand_radio");
        raciya_animation_data.addAnimation("into", 3, "raciya_3_draw_1");
        raciya_animation_data.addAnimation("into", 4, "raciya_4_draw_0");
        raciya_animation_data.addAnimationAttachItemName("into", 4, "hand_radio");
        raciya_animation_data.addAnimation("into", 4, "raciya_4_draw_1");
        raciya_animation_data.addAnimation("into", 8, "raciya_8_draw_0");
        raciya_animation_data.addAnimationAttachItemName("into", 8, "hand_radio");
        raciya_animation_data.addAnimation("into", 8, "raciya_8_draw_1");
        raciya_animation_data.addAnimation("into", 9, "raciya_9_draw_0");
        raciya_animation_data.addAnimationAttachItemName("into", 9, "hand_radio");
        raciya_animation_data.addAnimation("into", 9, "raciya_9_draw_1");
        raciya_animation_data.addAnimation("into", 10, "raciya_10_draw_0");
        raciya_animation_data.addAnimationAttachItemName("into", 10, "hand_radio");
        raciya_animation_data.addAnimation("into", 10, "raciya_10_draw_1");

        raciya_animation_data.addAnimation("out", 0, "raciya_0_hide_0");
        raciya_animation_data.addAnimationDettachItemName("out", 0, "hand_radio");
        raciya_animation_data.addAnimation("out", 0, "raciya_0_hide_1");
        raciya_animation_data.addAnimation("out", 1, "raciya_1_hide_0");
        raciya_animation_data.addAnimationDettachItemName("out", 1, "hand_radio");
        raciya_animation_data.addAnimation("out", 1, "raciya_1_hide_1");
        raciya_animation_data.addAnimation("out", 2, "raciya_2_hide_0");
        raciya_animation_data.addAnimationDettachItemName("out", 2, "hand_radio");
        raciya_animation_data.addAnimation("out", 2, "raciya_2_hide_1");
        raciya_animation_data.addAnimation("out", 3, "raciya_3_hide_0");
        raciya_animation_data.addAnimationDettachItemName("out", 3, "hand_radio");
        raciya_animation_data.addAnimation("out", 3, "raciya_3_hide_1");
        raciya_animation_data.addAnimation("out", 4, "raciya_4_hide_0");
        raciya_animation_data.addAnimationDettachItemName("out", 4, "hand_radio");
        raciya_animation_data.addAnimation("out", 4, "raciya_4_hide_1");
        raciya_animation_data.addAnimation("out", 8, "raciya_8_hide_0");
        raciya_animation_data.addAnimationDettachItemName("out", 8, "hand_radio");
        raciya_animation_data.addAnimation("out", 8, "raciya_8_hide_1");
        raciya_animation_data.addAnimation("out", 9, "raciya_9_hide_0");
        raciya_animation_data.addAnimationDettachItemName("out", 9, "hand_radio");
        raciya_animation_data.addAnimation("out", 9, "raciya_9_hide_1");
        raciya_animation_data.addAnimation("out", 10, "raciya_10_hide_0");
        raciya_animation_data.addAnimationDettachItemName("out", 10, "hand_radio");
        raciya_animation_data.addAnimation("out", 10, "raciya_10_hide_1");

        raciya_animation_data.addAnimation("idle", 0, "raciya_0_idle_0");
        raciya_animation_data.addAnimation("idle", 1, "raciya_1_idle_0");
        raciya_animation_data.addAnimation("idle", 2, "raciya_2_idle_0");
        raciya_animation_data.addAnimation("idle", 3, "raciya_3_idle_0");
        raciya_animation_data.addAnimation("idle", 4, "raciya_4_idle_0");
        raciya_animation_data.addAnimation("idle", 8, "raciya_8_idle_0");
        raciya_animation_data.addAnimation("idle", 9, "raciya_9_idle_0");
        raciya_animation_data.addAnimation("idle", 10, "raciya_10_idle_0");

        raciya_animation_data.addAnimation("rnd", 0, "raciya_0_talk_0");
        raciya_animation_data.addAnimation("rnd", 1, "raciya_1_talk_0");
        raciya_animation_data.addAnimation("rnd", 2, "raciya_2_talk_0");
        raciya_animation_data.addAnimation("rnd", 3, "raciya_3_talk_0");
        raciya_animation_data.addAnimation("rnd", 4, "raciya_4_talk_0");
        raciya_animation_data.addAnimation("rnd", 8, "raciya_8_talk_0");
        raciya_animation_data.addAnimation("rnd", 9, "raciya_9_talk_0");
        raciya_animation_data.addAnimation("rnd", 10, "raciya_10_talk_0");

        this->m_state_manager_animation_list["raciya"] = raciya_animation_data;

        StateManagerAnimationData cr_raciya_animation_data;
        cr_raciya_animation_data.setPropertiesMaxIdle(1);
        cr_raciya_animation_data.setPropertiesSumIdle(1);
        cr_raciya_animation_data.setPropertiesRandom(100);

        cr_raciya_animation_data.addAnimation("into", 0, "cr_raciya_0_draw_0");
        cr_raciya_animation_data.addAnimationAttachItemName("into", 0, "hand_radio");
        cr_raciya_animation_data.addAnimation("into", 0, "cr_raciya_0_draw_1");
        cr_raciya_animation_data.addAnimation("into", 1, "cr_raciya_1_draw_0");
        cr_raciya_animation_data.addAnimationAttachItemName("into", 1, "hand_radio");
        cr_raciya_animation_data.addAnimation("into", 1, "cr_raciya_1_draw_1");
        cr_raciya_animation_data.addAnimation("into", 2, "cr_raciya_2_draw_0");
        cr_raciya_animation_data.addAnimationAttachItemName("into", 2, "hand_radio");
        cr_raciya_animation_data.addAnimation("into", 2, "cr_raciya_2_draw_1");
        cr_raciya_animation_data.addAnimation("into", 3, "cr_raciya_3_draw_0");
        cr_raciya_animation_data.addAnimationAttachItemName("into", 3, "hand_radio");
        cr_raciya_animation_data.addAnimation("into", 3, "cr_raciya_3_draw_1");
        cr_raciya_animation_data.addAnimation("into", 4, "cr_raciya_4_draw_0");
        cr_raciya_animation_data.addAnimationAttachItemName("into", 4, "hand_radio");
        cr_raciya_animation_data.addAnimation("into", 4, "cr_raciya_4_draw_1");
        cr_raciya_animation_data.addAnimation("into", 8, "cr_raciya_8_draw_0");
        cr_raciya_animation_data.addAnimationAttachItemName("into", 8, "hand_radio");
        cr_raciya_animation_data.addAnimation("into", 8, "cr_raciya_8_draw_1");
        cr_raciya_animation_data.addAnimation("into", 9, "cr_raciya_9_draw_0");
        cr_raciya_animation_data.addAnimationAttachItemName("into", 9, "hand_radio");
        cr_raciya_animation_data.addAnimation("into", 9, "cr_raciya_9_draw_1");
        cr_raciya_animation_data.addAnimation("into", 10, "cr_raciya_10_draw_0");
        cr_raciya_animation_data.addAnimationAttachItemName("into", 10, "hand_radio");
        cr_raciya_animation_data.addAnimation("into", 10, "cr_raciya_10_draw_1");

        cr_raciya_animation_data.addAnimation("out", 0, "cr_raciya_0_hide_0");
        cr_raciya_animation_data.addAnimationDettachItemName("out", 0, "hand_radio");
        cr_raciya_animation_data.addAnimation("out", 0, "cr_raciya_0_hide_1");
        cr_raciya_animation_data.addAnimation("out", 1, "cr_raciya_1_hide_0");
        cr_raciya_animation_data.addAnimationDettachItemName("out", 1, "hand_radio");
        cr_raciya_animation_data.addAnimation("out", 1, "cr_raciya_1_hide_1");
        cr_raciya_animation_data.addAnimation("out", 2, "cr_raciya_2_hide_0");
        cr_raciya_animation_data.addAnimationDettachItemName("out", 2, "hand_radio");
        cr_raciya_animation_data.addAnimation("out", 2, "cr_raciya_2_hide_1");
        cr_raciya_animation_data.addAnimation("out", 3, "cr_raciya_3_hide_0");
        cr_raciya_animation_data.addAnimationDettachItemName("out", 3, "hand_radio");
        cr_raciya_animation_data.addAnimation("out", 3, "cr_raciya_3_hide_1");
        cr_raciya_animation_data.addAnimation("out", 4, "cr_raciya_4_hide_0");
        cr_raciya_animation_data.addAnimationDettachItemName("out", 4, "hand_radio");
        cr_raciya_animation_data.addAnimation("out", 4, "cr_raciya_4_hide_1");
        cr_raciya_animation_data.addAnimation("out", 8, "cr_raciya_8_hide_0");
        cr_raciya_animation_data.addAnimationDettachItemName("out", 8, "hand_radio");
        cr_raciya_animation_data.addAnimation("out", 8, "cr_raciya_8_hide_1");
        cr_raciya_animation_data.addAnimation("out", 9, "cr_raciya_9_hide_0");
        cr_raciya_animation_data.addAnimationDettachItemName("out", 9, "hand_radio");
        cr_raciya_animation_data.addAnimation("out", 9, "cr_raciya_9_hide_1");
        cr_raciya_animation_data.addAnimation("out", 10, "cr_raciya_10_hide_0");
        cr_raciya_animation_data.addAnimationDettachItemName("out", 10, "hand_radio");
        cr_raciya_animation_data.addAnimation("out", 10, "cr_raciya_10_hide_1");

        cr_raciya_animation_data.addAnimation("idle", 0, "cr_raciya_0_idle_0");
        cr_raciya_animation_data.addAnimation("idle", 1, "cr_raciya_1_idle_0");
        cr_raciya_animation_data.addAnimation("idle", 2, "cr_raciya_2_idle_0");
        cr_raciya_animation_data.addAnimation("idle", 3, "cr_raciya_3_idle_0");
        cr_raciya_animation_data.addAnimation("idle", 4, "cr_raciya_4_idle_0");
        cr_raciya_animation_data.addAnimation("idle", 8, "cr_raciya_8_idle_0");
        cr_raciya_animation_data.addAnimation("idle", 9, "cr_raciya_9_idle_0");
        cr_raciya_animation_data.addAnimation("idle", 10, "cr_raciya_10_idle_0");

        cr_raciya_animation_data.addAnimation("rnd", 0, "cr_raciya_0_talk_0");
        cr_raciya_animation_data.addAnimation("rnd", 1, "cr_raciya_1_talk_0");
        cr_raciya_animation_data.addAnimation("rnd", 2, "cr_raciya_2_talk_0");
        cr_raciya_animation_data.addAnimation("rnd", 3, "cr_raciya_3_talk_0");
        cr_raciya_animation_data.addAnimation("rnd", 4, "cr_raciya_4_talk_0");
        cr_raciya_animation_data.addAnimation("rnd", 8, "cr_raciya_8_talk_0");
        cr_raciya_animation_data.addAnimation("rnd", 9, "cr_raciya_9_talk_0");
        cr_raciya_animation_data.addAnimation("rnd", 10, "cr_raciya_10_talk_0");

        this->m_state_manager_animation_list["cr_raciya"] = cr_raciya_animation_data;

        StateManagerAnimationData psy_armed_animation_data;
        psy_armed_animation_data.setPropertiesMaxIdle(1);
        psy_armed_animation_data.setPropertiesSumIdle(1);
        psy_armed_animation_data.setPropertiesRandom(100);

        psy_armed_animation_data.addAnimation("into", 0, "idle_0_to_psy_0_idle_0");
        psy_armed_animation_data.addAnimation("into", 1, "idle_0_to_psy_1_idle_0");
        psy_armed_animation_data.addAnimation("out", 0, "psy_0_idle_0_to_idle_0");
        psy_armed_animation_data.addAnimation("out", 1, "psy_1_idle_0_to_idle_0");
        psy_armed_animation_data.addAnimation("idle", 0, "psy_0_idle_0");
        psy_armed_animation_data.addAnimation("idle", 1, "psy_1_idle_0");
        psy_armed_animation_data.addAnimation("rnd", 0, "psy_0_idle_1");
        psy_armed_animation_data.addAnimation("rnd", 0, "psy_0_idle_2");
        psy_armed_animation_data.addAnimation("rnd", 0, "psy_0_idle_3");
        psy_armed_animation_data.addAnimation("rnd", 1, "psy_1_idle_1");
        psy_armed_animation_data.addAnimation("rnd", 1, "psy_1_idle_2");
        psy_armed_animation_data.addAnimation("rnd", 1, "psy_1_idle_3");

        this->m_state_manager_animation_list["psy_armed"] = psy_armed_animation_data;

        StateManagerAnimationData psy_shoot_animation_data;
        psy_shoot_animation_data.setPropertiesMaxIdle(1);
        psy_shoot_animation_data.setPropertiesSumIdle(1);
        psy_shoot_animation_data.setPropertiesRandom(100);

        psy_shoot_animation_data.addAnimation("into", 1, "psy_1_shot_0");
        psy_shoot_animation_data.addAnimationHitPower("into", 1, 1000.0f);

        psy_shoot_animation_data.addAnimation("idle", 1, "psy_1_death_0");

        this->m_state_manager_animation_list["psy_shoot"] = psy_shoot_animation_data;

        StateManagerAnimationData lay_on_bed_animation_data;
        lay_on_bed_animation_data.setPropertiesMaxIdle(1);
        lay_on_bed_animation_data.setPropertiesSumIdle(1);
        lay_on_bed_animation_data.setPropertiesRandom(100);
        lay_on_bed_animation_data.setPropertiesMoving(true);

        lay_on_bed_animation_data.addAnimation("into", 0, "cut_scene_0_actor");

        this->m_state_manager_animation_list["lay_on_bed"] = lay_on_bed_animation_data;

        StateManagerAnimationData search_corpse_animation_data;
        search_corpse_animation_data.setPropertiesMaxIdle(1);
        search_corpse_animation_data.setPropertiesSumIdle(1);
        search_corpse_animation_data.setPropertiesRandom(100);

        search_corpse_animation_data.addAnimation("into", 0, "dinamit_1");
        //      search_corpse_animation_data.addAnimationFunction("into", 0, xr_corpse_detection.get_all_from_corpse);
        //      Lord: реализовать!

        this->m_state_manager_animation_list["search_corpse"] = search_corpse_animation_data;

        StateManagerAnimationData help_wounded_animation_data;
        help_wounded_animation_data.setPropertiesMaxIdle(1);
        help_wounded_animation_data.setPropertiesSumIdle(1);
        help_wounded_animation_data.setPropertiesRandom(100);

        help_wounded_animation_data.addAnimation("into", 0, "dinamit_1");
        //    help_wounded_animation_data.addAnimationFunction("into", 0, xr_help_wounded.help_wounded); Lord:
        //    реализовать!

        this->m_state_manager_animation_list["help_wounded"] = help_wounded_animation_data;

        StateManagerAnimationData animpoint_stay_wall_animation_data;
        animpoint_stay_wall_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_wall_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_wall_animation_data.setPropertiesRandom(80);
        animpoint_stay_wall_animation_data.setPropertiesMoving(true);

        animpoint_stay_wall_animation_data.addAnimation("idle", 0, "animpoint_stay_wall_idle_1");
        animpoint_stay_wall_animation_data.addAnimation("idle", 1, "animpoint_stay_wall_idle_1");

        animpoint_stay_wall_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_idle_rnd_1");
        animpoint_stay_wall_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_idle_rnd_2");
        animpoint_stay_wall_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_idle_rnd_3");
        animpoint_stay_wall_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_idle_rnd_4");

        animpoint_stay_wall_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_idle_rnd_1");
        animpoint_stay_wall_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_idle_rnd_2");
        animpoint_stay_wall_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_idle_rnd_3");
        animpoint_stay_wall_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_idle_rnd_4");

        this->m_state_manager_animation_list["animpoint_stay_wall"] = animpoint_stay_wall_animation_data;

        StateManagerAnimationData animpoint_stay_table_animation_data;
        animpoint_stay_table_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_table_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_table_animation_data.setPropertiesRandom(80);
        animpoint_stay_table_animation_data.setPropertiesMoving(true);

        animpoint_stay_table_animation_data.addAnimation("idle", 0, "animpoint_stay_table_idle_1");
        animpoint_stay_table_animation_data.addAnimation("idle", 1, "animpoint_stay_table_idle_1");

        animpoint_stay_table_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_1");
        animpoint_stay_table_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_2");
        animpoint_stay_table_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_3");
        animpoint_stay_table_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_4");
        animpoint_stay_table_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_5");

        animpoint_stay_table_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_1");
        animpoint_stay_table_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_2");
        animpoint_stay_table_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_3");
        animpoint_stay_table_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_4");
        animpoint_stay_table_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_5");

        this->m_state_manager_animation_list["animpoint_stay_table"] = animpoint_stay_table_animation_data;

        StateManagerAnimationData animpoint_sit_high_animation_data;
        animpoint_sit_high_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_high_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_high_animation_data.setPropertiesRandom(80);
        animpoint_sit_high_animation_data.setPropertiesMoving(true);

        animpoint_sit_high_animation_data.addAnimation("idle", 0, "animpoint_stay_table_idle_1");
        animpoint_sit_high_animation_data.addAnimation("idle", 1, "animpoint_stay_table_idle_1");
        animpoint_sit_high_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_1");
        animpoint_sit_high_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_2");
        animpoint_sit_high_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_3");
        animpoint_sit_high_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_4");
        animpoint_sit_high_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_rnd_5");

        animpoint_sit_high_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_1");
        animpoint_sit_high_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_2");
        animpoint_sit_high_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_3");
        animpoint_sit_high_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_4");
        animpoint_sit_high_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_rnd_5");

        this->m_state_manager_animation_list["animpoint_sit_high"] = animpoint_sit_high_animation_data;

        StateManagerAnimationData animpoint_sit_normal_animation_data;
        animpoint_sit_normal_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_normal_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_normal_animation_data.setPropertiesRandom(80);
        animpoint_sit_normal_animation_data.setPropertiesMoving(true);

        animpoint_sit_normal_animation_data.addAnimation("idle", 0, "animpoint_sit_normal_idle_1");
        animpoint_sit_normal_animation_data.addAnimation("idle", 1, "animpoint_sit_normal_idle_1");

        animpoint_sit_normal_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_idle_rnd_1");
        animpoint_sit_normal_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_idle_rnd_2");
        animpoint_sit_normal_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_idle_rnd_3");
        animpoint_sit_normal_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_idle_rnd_4");

        animpoint_sit_normal_animation_data.addAnimation("rnd", 1, "animpoint_sit_normal_idle_rnd_1");
        animpoint_sit_normal_animation_data.addAnimation("rnd", 1, "animpoint_sit_normal_idle_rnd_2");
        animpoint_sit_normal_animation_data.addAnimation("rnd", 1, "animpoint_sit_normal_idle_rnd_3");
        animpoint_sit_normal_animation_data.addAnimation("rnd", 1, "animpoint_sit_normal_idle_rnd_4");

        this->m_state_manager_animation_list["animpoint_sit_normal"] = animpoint_sit_normal_animation_data;

        StateManagerAnimationData animpoint_sit_low_animation_data;
        animpoint_sit_low_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_low_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_low_animation_data.setPropertiesRandom(80);
        animpoint_sit_low_animation_data.setPropertiesMoving(true);

        animpoint_sit_low_animation_data.addAnimation("idle", 0, "animpoint_sit_low_idle_1");
        animpoint_sit_low_animation_data.addAnimation("idle", 1, "animpoint_sit_low_idle_1");

        animpoint_sit_low_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_idle_rnd_1");
        animpoint_sit_low_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_idle_rnd_2");
        animpoint_sit_low_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_idle_rnd_3");
        animpoint_sit_low_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_idle_rnd_4");

        animpoint_sit_low_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_idle_rnd_1");
        animpoint_sit_low_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_idle_rnd_2");
        animpoint_sit_low_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_idle_rnd_3");
        animpoint_sit_low_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_idle_rnd_4");

        this->m_state_manager_animation_list["animpoint_sit_low"] = animpoint_sit_low_animation_data;

        StateManagerAnimationData animpoint_stay_wall_eat_bread_animation_data;
        animpoint_stay_wall_eat_bread_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_wall_eat_bread_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_wall_eat_bread_animation_data.setPropertiesRandom(80);
        animpoint_stay_wall_eat_bread_animation_data.setPropertiesMoving(true);

        animpoint_stay_wall_eat_bread_animation_data.addAnimation("into", 0, "animpoint_stay_wall_eat_in_1");
        animpoint_stay_wall_eat_bread_animation_data.addAnimationAttachItemName("into", 0, "bread");
        animpoint_stay_wall_eat_bread_animation_data.addAnimation("into", 0, "animpoint_stay_wall_eat_in_2");

        animpoint_stay_wall_eat_bread_animation_data.addAnimation("into", 1, "animpoint_stay_wall_eat_in_1");
        animpoint_stay_wall_eat_bread_animation_data.addAnimationAttachItemName("into", 1, "bread");
        animpoint_stay_wall_eat_bread_animation_data.addAnimation("into", 1, "animpoint_stay_wall_eat_in_2");

        animpoint_stay_wall_eat_bread_animation_data.addAnimation("out", 0, "animpoint_stay_wall_eat_out_1");
        animpoint_stay_wall_eat_bread_animation_data.addAnimationDettachItemName("out", 0, "bread");
        animpoint_stay_wall_eat_bread_animation_data.addAnimation("out", 0, "animpoint_stay_wall_eat_out_2");

        animpoint_stay_wall_eat_bread_animation_data.addAnimation("out", 1, "animpoint_stay_wall_eat_out_1");
        animpoint_stay_wall_eat_bread_animation_data.addAnimationDettachItemName("out", 1, "bread");
        animpoint_stay_wall_eat_bread_animation_data.addAnimation("out", 1, "animpoint_stay_wall_eat_out_2");

        animpoint_stay_wall_eat_bread_animation_data.addAnimation("idle", 0, "animpoint_stay_wall_eat_idle_1");
        animpoint_stay_wall_eat_bread_animation_data.addAnimation("idle", 1, "animpoint_stay_wall_eat_idle_1");

        animpoint_stay_wall_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_eat_idle_rnd_1");
        animpoint_stay_wall_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_eat_idle_rnd_2");

        animpoint_stay_wall_eat_bread_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_eat_idle_rnd_1");
        animpoint_stay_wall_eat_bread_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_eat_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_stay_wall_eat_bread"] =
            animpoint_stay_wall_eat_bread_animation_data;

        StateManagerAnimationData animpoint_stay_wall_eat_kolbasa_animation_data;
        animpoint_stay_wall_eat_kolbasa_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_wall_eat_kolbasa_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_wall_eat_kolbasa_animation_data.setPropertiesRandom(80);
        animpoint_stay_wall_eat_kolbasa_animation_data.setPropertiesMoving(true);

        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("into", 0, "animpoint_stay_wall_eat_in_1");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimationAttachItemName("into", 0, "kolbasa");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("into", 0, "animpoint_stay_wall_eat_in_2");

        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("into", 1, "animpoint_stay_wall_eat_in_1");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimationAttachItemName("into", 1, "kolbasa");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("into", 1, "animpoint_stay_wall_eat_in_2");

        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("out", 0, "animpoint_stay_wall_eat_out_1");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimationDettachItemName("out", 0, "kolbasa");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("out", 0, "animpoint_stay_wall_eat_out_2");

        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("out", 1, "animpoint_stay_wall_eat_out_1");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimationDettachItemName("out", 1, "kolbasa");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("out", 1, "animpoint_stay_wall_eat_out_2");

        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("idle", 0, "animpoint_stay_wall_eat_idle_1");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("idle", 1, "animpoint_stay_wall_eat_idle_1");

        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_eat_idle_rnd_1");
        animpoint_stay_wall_eat_kolbasa_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_eat_idle_rnd_1");

        this->m_state_manager_animation_list["animpoint_stay_wall_eat_kolbasa"] =
            animpoint_stay_wall_eat_kolbasa_animation_data;

        StateManagerAnimationData animpoint_stay_table_eat_bread_animation_data;
        animpoint_stay_table_eat_bread_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_table_eat_bread_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_table_eat_bread_animation_data.setPropertiesRandom(80);
        animpoint_stay_table_eat_bread_animation_data.setPropertiesMoving(true);

        animpoint_stay_table_eat_bread_animation_data.addAnimation("idle", 0, "animpoint_stay_table_idle_1");
        animpoint_stay_table_eat_bread_animation_data.addAnimation("idle", 1, "animpoint_stay_table_idle_1");

        animpoint_stay_table_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_1");
        animpoint_stay_table_eat_bread_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_1");

        this->m_state_manager_animation_list["animpoint_stay_table_eat_bread"] =
            animpoint_stay_table_eat_bread_animation_data;

        StateManagerAnimationData animpoint_stay_table_eat_kolbasa_animation_data;
        animpoint_stay_table_eat_kolbasa_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_table_eat_kolbasa_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_table_eat_kolbasa_animation_data.setPropertiesRandom(80);
        animpoint_stay_table_eat_kolbasa_animation_data.setPropertiesMoving(true);

        animpoint_stay_table_eat_kolbasa_animation_data.addAnimation("idle", 0, "animpoint_stay_table_idle_1");
        animpoint_stay_table_eat_kolbasa_animation_data.addAnimation("idle", 1, "animpoint_stay_table_idle_1");

        animpoint_stay_table_eat_kolbasa_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_1");
        animpoint_stay_table_eat_kolbasa_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_1");

        this->m_state_manager_animation_list["animpoint_stay_table_eat_kolbasa"] =
            animpoint_stay_table_eat_kolbasa_animation_data;

        StateManagerAnimationData animpoint_sit_high_eat_bread_animation_data;
        animpoint_sit_high_eat_bread_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_high_eat_bread_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_high_eat_bread_animation_data.setPropertiesRandom(80);
        animpoint_sit_high_eat_bread_animation_data.setPropertiesMoving(true);

        animpoint_sit_high_eat_bread_animation_data.addAnimation("into", 0, "animpoint_sit_high_eat_in_1");
        animpoint_sit_high_eat_bread_animation_data.addAnimationAttachItemName("into", 0, "bread");
        animpoint_sit_high_eat_bread_animation_data.addAnimation("into", 0, "animpoint_sit_high_eat_in_2");

        animpoint_sit_high_eat_bread_animation_data.addAnimation("into", 1, "animpoint_sit_high_eat_in_1");
        animpoint_sit_high_eat_bread_animation_data.addAnimationAttachItemName("into", 1, "bread");
        animpoint_sit_high_eat_bread_animation_data.addAnimation("into", 1, "animpoint_sit_high_eat_in_2");

        animpoint_sit_high_eat_bread_animation_data.addAnimation("out", 0, "animpoint_sit_high_eat_out_1");
        animpoint_sit_high_eat_bread_animation_data.addAnimationAttachItemName("out", 0, "bread");
        animpoint_sit_high_eat_bread_animation_data.addAnimation("out", 0, "animpoint_sit_high_eat_out_2");

        animpoint_sit_high_eat_bread_animation_data.addAnimation("out", 1, "animpoint_sit_high_eat_out_1");
        animpoint_sit_high_eat_bread_animation_data.addAnimationAttachItemName("out", 1, "bread");
        animpoint_sit_high_eat_bread_animation_data.addAnimation("out", 1, "animpoint_sit_high_eat_out_2");

        animpoint_sit_high_eat_bread_animation_data.addAnimation("idle", 0, "animpoint_sit_high_eat_idle_1");
        animpoint_sit_high_eat_bread_animation_data.addAnimation("idle", 1, "animpoint_sit_high_eat_idle_1");

        animpoint_sit_high_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_sit_high_eat_idle_rnd_1");
        animpoint_sit_high_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_sit_high_eat_idle_rnd_2");

        animpoint_sit_high_eat_bread_animation_data.addAnimation("rnd", 1, "animpoint_sit_high_eat_idle_rnd_1");
        animpoint_sit_high_eat_bread_animation_data.addAnimation("rnd", 1, "animpoint_sit_high_eat_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_sit_high_eat_bread"] =
            animpoint_sit_high_eat_bread_animation_data;

        StateManagerAnimationData animpoint_sit_high_eat_kolbasa_animation_data;
        animpoint_sit_high_eat_kolbasa_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_high_eat_kolbasa_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_high_eat_kolbasa_animation_data.setPropertiesRandom(80);
        animpoint_sit_high_eat_kolbasa_animation_data.setPropertiesMoving(true);

        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("into", 0, "animpoint_sit_high_eat_in_1");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimationAttachItemName("into", 0, "kolbasa");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("into", 0, "animpoint_sit_high_eat_in_2");

        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("into", 1, "animpoint_sit_high_eat_in_1");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimationAttachItemName("into", 1, "kolbasa");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("into", 1, "animpoint_sit_high_eat_in_2");

        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("out", 0, "animpoint_sit_high_eat_out_1");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimationDettachItemName("out", 0, "kolbasa");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("out", 0, "animpoint_sit_high_eat_out_2");

        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("out", 1, "animpoint_sit_high_eat_out_1");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimationDettachItemName("out", 1, "kolbasa");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("out", 1, "animpoint_sit_high_eat_out_2");

        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("idle", 0, "animpoint_sit_high_eat_idle_1");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("idle", 1, "animpoint_sit_high_eat_idle_1");

        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("rnd", 0, "animpoint_sit_high_eat_idle_rnd_1");
        animpoint_sit_high_eat_kolbasa_animation_data.addAnimation("rnd", 1, "animpoint_sit_high_eat_idle_rnd_1");

        this->m_state_manager_animation_list["animpoint_sit_high_eat_kolbasa"] =
            animpoint_sit_high_eat_kolbasa_animation_data;

        StateManagerAnimationData animpoint_sit_normal_eat_bread_animation_data;
        animpoint_sit_normal_eat_bread_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_normal_eat_bread_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_normal_eat_bread_animation_data.setPropertiesRandom(80);
        animpoint_sit_normal_eat_bread_animation_data.setPropertiesMoving(true);

        animpoint_sit_normal_eat_bread_animation_data.addAnimation("into", 0, "animpoint_sit_normal_eat_in_1");
        animpoint_sit_normal_eat_bread_animation_data.addAnimationAttachItemName("into", 0, "bread");
        animpoint_sit_normal_eat_bread_animation_data.addAnimation("into", 0, "animpoint_sit_normal_eat_in_2");

        animpoint_sit_normal_eat_bread_animation_data.addAnimation("into", 1, "animpoint_sit_normal_eat_in_1");
        animpoint_sit_normal_eat_bread_animation_data.addAnimationAttachItemName("into", 1, "bread");
        animpoint_sit_normal_eat_bread_animation_data.addAnimation("into", 1, "animpoint_sit_normal_eat_in_2");

        animpoint_sit_normal_eat_bread_animation_data.addAnimation("out", 0, "animpoint_sit_normal_eat_out_1");
        animpoint_sit_normal_eat_bread_animation_data.addAnimationDettachItemName("out", 0, "bread");
        animpoint_sit_normal_eat_bread_animation_data.addAnimation("out", 0, "animpoint_sit_normal_eat_out_2");

        animpoint_sit_normal_eat_bread_animation_data.addAnimation("out", 1, "animpoint_sit_normal_eat_out_1");
        animpoint_sit_normal_eat_bread_animation_data.addAnimationDettachItemName("out", 1, "bread");
        animpoint_sit_normal_eat_bread_animation_data.addAnimation("out", 1, "animpoint_sit_normal_eat_out_2");

        animpoint_sit_normal_eat_bread_animation_data.addAnimation("idle", 0, "animpoint_sit_normal_eat_idle_1");
        animpoint_sit_normal_eat_bread_animation_data.addAnimation("idle", 1, "animpoint_sit_normal_eat_idle_1");

        animpoint_sit_normal_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_eat_idle_rnd_1");
        animpoint_sit_normal_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_eat_idle_rnd_2");

        animpoint_sit_normal_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_eat_idle_rnd_1");
        animpoint_sit_normal_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_eat_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_sit_normal_eat_bread"] =
            animpoint_sit_normal_eat_bread_animation_data;

        StateManagerAnimationData animpoint_sit_normal_eat_kolbasa_animation_data;
        animpoint_sit_normal_eat_kolbasa_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_normal_eat_kolbasa_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_normal_eat_kolbasa_animation_data.setPropertiesRandom(80);
        animpoint_sit_normal_eat_kolbasa_animation_data.setPropertiesMoving(true);

        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("into", 0, "animpoint_sit_normal_eat_in_1");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimationAttachItemName("into", 0, "kolbasa");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("into", 0, "animpoint_sit_normal_eat_in_2");

        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("into", 1, "animpoint_sit_normal_eat_in_1");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimationAttachItemName("into", 1, "kolbasa");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("into", 1, "animpoint_sit_normal_eat_in_2");

        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("out", 0, "animpoint_sit_normal_eat_out_1");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimationDettachItemName("out", 0, "kolbasa");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("out", 0, "animpoint_sit_normal_eat_out_2");

        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("out", 1, "animpoint_sit_normal_eat_out_1");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimationDettachItemName("out", 1, "kolbasa");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("out", 1, "animpoint_sit_normal_eat_out_2");

        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("idle", 0, "animpoint_sit_normal_eat_idle_1");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("idle", 1, "animpoint_sit_normal_eat_idle_1");

        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_eat_idle_1");
        animpoint_sit_normal_eat_kolbasa_animation_data.addAnimation("rnd", 1, "animpoint_sit_normal_eat_idle_1");

        this->m_state_manager_animation_list["animpoint_sit_normal_eat_kolbasa"] =
            animpoint_sit_normal_eat_kolbasa_animation_data;

        StateManagerAnimationData animpoint_sit_low_eat_bread_animation_data;
        animpoint_sit_low_eat_bread_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_low_eat_bread_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_low_eat_bread_animation_data.setPropertiesRandom(80);
        animpoint_sit_low_eat_bread_animation_data.setPropertiesMoving(true);

        animpoint_sit_low_eat_bread_animation_data.addAnimation("into", 0, "animpoint_sit_low_eat_in_1");
        animpoint_sit_low_eat_bread_animation_data.addAnimationAttachItemName("into", 0, "bread");
        animpoint_sit_low_eat_bread_animation_data.addAnimation("into", 0, "animpoint_sit_low_eat_in_2");

        animpoint_sit_low_eat_bread_animation_data.addAnimation("into", 1, "animpoint_sit_low_eat_in_1");
        animpoint_sit_low_eat_bread_animation_data.addAnimationAttachItemName("into", 1, "bread");
        animpoint_sit_low_eat_bread_animation_data.addAnimation("into", 1, "animpoint_sit_low_eat_in_2");

        animpoint_sit_low_eat_bread_animation_data.addAnimation("out", 0, "animpoint_sit_low_eat_out_1");
        animpoint_sit_low_eat_bread_animation_data.addAnimationDettachItemName("out", 0, "bread");
        animpoint_sit_low_eat_bread_animation_data.addAnimation("out", 0, "animpoint_sit_low_eat_out_2");

        animpoint_sit_low_eat_bread_animation_data.addAnimation("out", 1, "animpoint_sit_low_eat_out_1");
        animpoint_sit_low_eat_bread_animation_data.addAnimationDettachItemName("out", 1, "bread");
        animpoint_sit_low_eat_bread_animation_data.addAnimation("out", 1, "animpoint_sit_low_eat_out_2");

        animpoint_sit_low_eat_bread_animation_data.addAnimation("idle", 0, "animpoint_sit_low_eat_idle_1");
        animpoint_sit_low_eat_bread_animation_data.addAnimation("idle", 0, "animpoint_sit_low_eat_idle_1");

        animpoint_sit_low_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_eat_idle_1");
        animpoint_sit_low_eat_bread_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_eat_idle_2");

        animpoint_sit_low_eat_bread_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_eat_idle_1");
        animpoint_sit_low_eat_bread_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_eat_idle_2");

        this->m_state_manager_animation_list["animpoint_sit_low_eat_bread"] =
            animpoint_sit_low_eat_bread_animation_data;

        StateManagerAnimationData animpoint_sit_low_eat_kolbasa_animation_data;
        animpoint_sit_low_eat_kolbasa_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_low_eat_kolbasa_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_low_eat_kolbasa_animation_data.setPropertiesRandom(80);
        animpoint_sit_low_eat_kolbasa_animation_data.setPropertiesMoving(true);

        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("into", 0, "animpoint_sit_low_eat_in_1");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimationAttachItemName("into", 0, "kolbasa");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("into", 0, "animpoint_sit_low_eat_in_2");

        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("into", 1, "animpoint_sit_low_eat_in_1");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimationAttachItemName("into", 1, "kolbasa");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("into", 1, "animpoint_sit_low_eat_in_2");

        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("out", 0, "animpoint_sit_low_eat_out_1");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimationDettachItemName("out", 0, "kolbasa");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("out", 0, "animpoint_sit_low_eat_out_2");

        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("out", 1, "animpoint_sit_low_eat_out_1");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimationDettachItemName("out", 1, "kolbasa");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("out", 1, "animpoint_sit_low_eat_out_2");

        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("idle", 0, "animpoint_sit_low_eat_idle_1");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("idle", 0, "animpoint_sit_low_eat_idle_1");

        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_eat_idle_1");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_eat_idle_2");

        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_eat_idle_1");
        animpoint_sit_low_eat_kolbasa_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_eat_idle_2");

        this->m_state_manager_animation_list["animpoint_sit_low_eat_kolbasa"] =
            animpoint_sit_low_eat_kolbasa_animation_data;

        StateManagerAnimationData animpoint_stay_wall_drink_vodka_animation_data;
        animpoint_stay_wall_drink_vodka_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_wall_drink_vodka_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_wall_drink_vodka_animation_data.setPropertiesRandom(80);
        animpoint_stay_wall_drink_vodka_animation_data.setPropertiesMoving(true);

        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("into", 0, "animpoint_stay_wall_drink_in_1");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimationAttachItemName("into", 0, "vodka");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("into", 0, "animpoint_stay_wall_drink_in_2");

        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("into", 1, "animpoint_stay_wall_drink_in_1");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimationAttachItemName("into", 1, "vodka");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("into", 1, "animpoint_stay_wall_drink_in_2");

        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("out", 0, "animpoint_stay_wall_drink_out_1");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimationDettachItemName("out", 0, "vodka");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("out", 0, "animpoint_stay_wall_drink_out_2");

        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("out", 1, "animpoint_stay_wall_drink_out_1");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimationDettachItemName("out", 1, "vodka");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("out", 1, "animpoint_stay_wall_drink_out_2");

        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("idle", 0, "animpoint_stay_wall_drink_idle_1");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("idle", 0, "animpoint_stay_wall_drink_idle_1");

        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_drink_idle_rnd_1");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_drink_idle_rnd_2");

        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_drink_idle_rnd_1");
        animpoint_stay_wall_drink_vodka_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_drink_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_stay_wall_drink_vodka"] =
            animpoint_stay_wall_drink_vodka_animation_data;

        StateManagerAnimationData animpoint_stay_wall_drink_energy_animation_data;
        animpoint_stay_wall_drink_energy_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_wall_drink_energy_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_wall_drink_energy_animation_data.setPropertiesRandom(80);
        animpoint_stay_wall_drink_energy_animation_data.setPropertiesMoving(true);

        animpoint_stay_wall_drink_energy_animation_data.addAnimation("into", 0, "animpoint_stay_wall_drink_in_1");
        animpoint_stay_wall_drink_energy_animation_data.addAnimationAttachItemName("into", 0, "energy_drink");
        animpoint_stay_wall_drink_energy_animation_data.addAnimation("into", 0, "animpoint_stay_wall_drink_in_2");

        animpoint_stay_wall_drink_energy_animation_data.addAnimation("into", 1, "animpoint_stay_wall_drink_in_1");
        animpoint_stay_wall_drink_energy_animation_data.addAnimationAttachItemName("into", 1, "energy_drink");
        animpoint_stay_wall_drink_energy_animation_data.addAnimation("into", 1, "animpoint_stay_wall_drink_in_2");

        animpoint_stay_wall_drink_energy_animation_data.addAnimation("out", 0, "animpoint_stay_wall_drink_out_1");
        animpoint_stay_wall_drink_energy_animation_data.addAnimationDettachItemName("out", 0, "energy_drink");
        animpoint_stay_wall_drink_energy_animation_data.addAnimation("out", 0, "animpoint_stay_wall_drink_out_2");

        animpoint_stay_wall_drink_energy_animation_data.addAnimation("out", 1, "animpoint_stay_wall_drink_out_1");
        animpoint_stay_wall_drink_energy_animation_data.addAnimationDettachItemName("out", 1, "energy_drink");
        animpoint_stay_wall_drink_energy_animation_data.addAnimation("out", 1, "animpoint_stay_wall_drink_out_2");

        animpoint_stay_wall_drink_energy_animation_data.addAnimation("idle", 0, "animpoint_stay_wall_drink_idle_1");
        animpoint_stay_wall_drink_energy_animation_data.addAnimation("idle", 0, "animpoint_stay_wall_drink_idle_1");

        animpoint_stay_wall_drink_energy_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_drink_idle_rnd_1");
        animpoint_stay_wall_drink_energy_animation_data.addAnimation("rnd", 0, "animpoint_stay_wall_drink_idle_rnd_2");

        animpoint_stay_wall_drink_energy_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_drink_idle_rnd_1");
        animpoint_stay_wall_drink_energy_animation_data.addAnimation("rnd", 1, "animpoint_stay_wall_drink_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_stay_wall_drink_energy"] =
            animpoint_stay_wall_drink_energy_animation_data;

        StateManagerAnimationData animpoint_stay_table_drink_vodka_aniamtion_data;
        animpoint_stay_table_drink_vodka_aniamtion_data.setPropertiesMaxIdle(5);
        animpoint_stay_table_drink_vodka_aniamtion_data.setPropertiesSumIdle(3);
        animpoint_stay_table_drink_vodka_aniamtion_data.setPropertiesRandom(80);
        animpoint_stay_table_drink_vodka_aniamtion_data.setPropertiesMoving(true);

        animpoint_stay_table_drink_vodka_aniamtion_data.addAnimation("idle", 0, "animpoint_stay_table_idle_1");
        animpoint_stay_table_drink_vodka_aniamtion_data.addAnimation("idle", 1, "animpoint_stay_table_idle_1");

        animpoint_stay_table_drink_vodka_aniamtion_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_1");
        animpoint_stay_table_drink_vodka_aniamtion_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_1");

        this->m_state_manager_animation_list["animpoint_stay_table_drink_vodka"] =
            animpoint_stay_table_drink_vodka_aniamtion_data;

        StateManagerAnimationData animpoint_stay_table_drink_energy_animation_data;
        animpoint_stay_table_drink_energy_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_table_drink_energy_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_table_drink_energy_animation_data.setPropertiesRandom(80);
        animpoint_stay_table_drink_energy_animation_data.setPropertiesMoving(true);

        animpoint_stay_table_drink_energy_animation_data.addAnimation("idle", 0, "animpoint_stay_table_idle_1");
        animpoint_stay_table_drink_energy_animation_data.addAnimation("idle", 1, "animpoint_stay_table_idle_1");

        animpoint_stay_table_drink_energy_animation_data.addAnimation("rnd", 0, "animpoint_stay_table_idle_1");
        animpoint_stay_table_drink_energy_animation_data.addAnimation("rnd", 1, "animpoint_stay_table_idle_1");

        this->m_state_manager_animation_list["animpoint_stay_table_drink_energy"] =
            animpoint_stay_table_drink_energy_animation_data;

        StateManagerAnimationData animpoint_sit_high_drink_vodka_animation_data;
        animpoint_sit_high_drink_vodka_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_high_drink_vodka_animation_data.setPropertiesMoving(true);
        animpoint_sit_high_drink_vodka_animation_data.setPropertiesRandom(80);
        animpoint_sit_high_drink_vodka_animation_data.setPropertiesSumIdle(3);

        animpoint_sit_high_drink_vodka_animation_data.addAnimation("into", 0, "animpoint_sit_high_drink_in_1");
        animpoint_sit_high_drink_vodka_animation_data.addAnimationAttachItemName("into", 0, "vodka");
        animpoint_sit_high_drink_vodka_animation_data.addAnimation("into", 0, "animpoint_sit_high_drink_in_2");

        animpoint_sit_high_drink_vodka_animation_data.addAnimation("into", 1, "animpoint_sit_high_drink_in_1");
        animpoint_sit_high_drink_vodka_animation_data.addAnimationAttachItemName("into", 1, "vodka");
        animpoint_sit_high_drink_vodka_animation_data.addAnimation("into", 1, "animpoint_sit_high_drink_in_2");

        animpoint_sit_high_drink_vodka_animation_data.addAnimation("out", 0, "animpoint_sit_high_drink_out_1");
        animpoint_sit_high_drink_vodka_animation_data.addAnimationDettachItemName("out", 0, "vodka");
        animpoint_sit_high_drink_vodka_animation_data.addAnimation("out", 0, "animpoint_sit_high_drink_out_2");

        animpoint_sit_high_drink_vodka_animation_data.addAnimation("out", 1, "animpoint_sit_high_drink_out_1");
        animpoint_sit_high_drink_vodka_animation_data.addAnimationDettachItemName("out", 1, "vodka");
        animpoint_sit_high_drink_vodka_animation_data.addAnimation("out", 1, "animpoint_sit_high_drink_out_2");

        animpoint_sit_high_drink_vodka_animation_data.addAnimation("idle", 0, "animpoint_sit_high_drink_idle_1");
        animpoint_sit_high_drink_vodka_animation_data.addAnimation("idle", 0, "animpoint_sit_high_drink_idle_1");

        animpoint_sit_high_drink_vodka_animation_data.addAnimation("rnd", 0, "animpoint_sit_high_drink_idle_rnd_1");
        animpoint_sit_high_drink_vodka_animation_data.addAnimation("rnd", 0, "animpoint_sit_high_drink_idle_rnd_2");

        animpoint_sit_high_drink_vodka_animation_data.addAnimation("rnd", 1, "animpoint_sit_high_drink_idle_rnd_1");
        animpoint_sit_high_drink_vodka_animation_data.addAnimation("rnd", 1, "animpoint_sit_high_drink_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_sit_high_drink_vodka"] =
            animpoint_sit_high_drink_vodka_animation_data;

        StateManagerAnimationData animpoint_sit_high_drink_energy_animation_data;
        animpoint_sit_high_drink_energy_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_high_drink_energy_animation_data.setPropertiesMoving(true);
        animpoint_sit_high_drink_energy_animation_data.setPropertiesRandom(80);
        animpoint_sit_high_drink_energy_animation_data.setPropertiesSumIdle(3);

        animpoint_sit_high_drink_energy_animation_data.addAnimation("into", 0, "animpoint_sit_high_drink_in_1");
        animpoint_sit_high_drink_energy_animation_data.addAnimationAttachItemName("into", 0, "energy_drink");
        animpoint_sit_high_drink_energy_animation_data.addAnimation("into", 0, "animpoint_sit_high_drink_in_2");

        animpoint_sit_high_drink_energy_animation_data.addAnimation("into", 1, "animpoint_sit_high_drink_in_1");
        animpoint_sit_high_drink_energy_animation_data.addAnimationAttachItemName("into", 1, "energy_drink");
        animpoint_sit_high_drink_energy_animation_data.addAnimation("into", 1, "animpoint_sit_high_drink_in_2");

        animpoint_sit_high_drink_energy_animation_data.addAnimation("out", 0, "animpoint_sit_high_drink_out_1");
        animpoint_sit_high_drink_energy_animation_data.addAnimationDettachItemName("out", 0, "energy_drink");
        animpoint_sit_high_drink_energy_animation_data.addAnimation("out", 0, "animpoint_sit_high_drink_out_2");

        animpoint_sit_high_drink_energy_animation_data.addAnimation("out", 1, "animpoint_sit_high_drink_out_1");
        animpoint_sit_high_drink_energy_animation_data.addAnimationDettachItemName("out", 1, "energy_drink");
        animpoint_sit_high_drink_energy_animation_data.addAnimation("out", 1, "animpoint_sit_high_drink_out_2");

        animpoint_sit_high_drink_energy_animation_data.addAnimation("idle", 0, "animpoint_sit_high_drink_idle_1");
        animpoint_sit_high_drink_energy_animation_data.addAnimation("idle", 0, "animpoint_sit_high_drink_idle_1");

        animpoint_sit_high_drink_energy_animation_data.addAnimation("rnd", 0, "animpoint_sit_high_drink_idle_rnd_1");
        animpoint_sit_high_drink_energy_animation_data.addAnimation("rnd", 0, "animpoint_sit_high_drink_idle_rnd_2");

        animpoint_sit_high_drink_energy_animation_data.addAnimation("rnd", 1, "animpoint_sit_high_drink_idle_rnd_1");
        animpoint_sit_high_drink_energy_animation_data.addAnimation("rnd", 1, "animpoint_sit_high_drink_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_sit_high_drink_energy"] =
            animpoint_sit_high_drink_energy_animation_data;

        StateManagerAnimationData animpoint_sit_normal_drink_vodka_animation_data;
        animpoint_sit_normal_drink_vodka_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_normal_drink_vodka_animation_data.setPropertiesMoving(true);
        animpoint_sit_normal_drink_vodka_animation_data.setPropertiesRandom(80);
        animpoint_sit_normal_drink_vodka_animation_data.setPropertiesSumIdle(3);

        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("into", 0, "animpoint_sit_normal_drink_in_1");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimationAttachItemName("into", 0, "vodka");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("into", 0, "animpoint_sit_normal_drink_in_2");

        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("into", 1, "animpoint_sit_normal_drink_in_1");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimationAttachItemName("into", 1, "vodka");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("into", 1, "animpoint_sit_normal_drink_in_2");

        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("out", 0, "animpoint_sit_normal_drink_out_1");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimationDettachItemName("out", 0, "vodka");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("out", 0, "animpoint_sit_normal_drink_out_2");

        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("out", 1, "animpoint_sit_normal_drink_out_1");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimationDettachItemName("out", 1, "vodka");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("out", 1, "animpoint_sit_normal_drink_out_2");

        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("idle", 0, "animpoint_sit_normal_drink_idle_1");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("idle", 0, "animpoint_sit_normal_drink_idle_1");

        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_drink_idle_rnd_1");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_drink_idle_rnd_2");

        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("rnd", 1, "animpoint_sit_normal_drink_idle_rnd_1");
        animpoint_sit_normal_drink_vodka_animation_data.addAnimation("rnd", 1, "animpoint_sit_normal_drink_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_sit_normal_drink_vodka"] =
            animpoint_sit_normal_drink_vodka_animation_data;

        StateManagerAnimationData animpoint_sit_normal_drink_energy_animation_data;
        animpoint_sit_normal_drink_energy_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_normal_drink_energy_animation_data.setPropertiesMoving(true);
        animpoint_sit_normal_drink_energy_animation_data.setPropertiesRandom(80);
        animpoint_sit_normal_drink_energy_animation_data.setPropertiesSumIdle(3);

        animpoint_sit_normal_drink_energy_animation_data.addAnimation("into", 0, "animpoint_sit_normal_drink_in_1");
        animpoint_sit_normal_drink_energy_animation_data.addAnimationAttachItemName("into", 0, "energy_drink");
        animpoint_sit_normal_drink_energy_animation_data.addAnimation("into", 0, "animpoint_sit_normal_drink_in_2");

        animpoint_sit_normal_drink_energy_animation_data.addAnimation("into", 1, "animpoint_sit_normal_drink_in_1");
        animpoint_sit_normal_drink_energy_animation_data.addAnimationAttachItemName("into", 1, "energy_drink");
        animpoint_sit_normal_drink_energy_animation_data.addAnimation("into", 1, "animpoint_sit_normal_drink_in_2");

        animpoint_sit_normal_drink_energy_animation_data.addAnimation("out", 0, "animpoint_sit_normal_drink_out_1");
        animpoint_sit_normal_drink_energy_animation_data.addAnimationDettachItemName("out", 0, "energy_drink");
        animpoint_sit_normal_drink_energy_animation_data.addAnimation("out", 0, "animpoint_sit_normal_drink_out_2");

        animpoint_sit_normal_drink_energy_animation_data.addAnimation("out", 1, "animpoint_sit_normal_drink_out_1");
        animpoint_sit_normal_drink_energy_animation_data.addAnimationDettachItemName("out", 1, "energy_drink");
        animpoint_sit_normal_drink_energy_animation_data.addAnimation("out", 1, "animpoint_sit_normal_drink_out_2");

        animpoint_sit_normal_drink_energy_animation_data.addAnimation("idle", 0, "animpoint_sit_normal_drink_idle_1");
        animpoint_sit_normal_drink_energy_animation_data.addAnimation("idle", 0, "animpoint_sit_normal_drink_idle_1");

        animpoint_sit_normal_drink_energy_animation_data.addAnimation(
            "rnd", 0, "animpoint_sit_normal_drink_idle_rnd_1");
        animpoint_sit_normal_drink_energy_animation_data.addAnimation(
            "rnd", 0, "animpoint_sit_normal_drink_idle_rnd_2");

        animpoint_sit_normal_drink_energy_animation_data.addAnimation(
            "rnd", 1, "animpoint_sit_normal_drink_idle_rnd_1");
        animpoint_sit_normal_drink_energy_animation_data.addAnimation(
            "rnd", 1, "animpoint_sit_normal_drink_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_sit_normal_drink_energy"] =
            animpoint_sit_normal_drink_energy_animation_data;

        StateManagerAnimationData animpoint_sit_low_drink_vodka_animation_data;
        animpoint_sit_low_drink_vodka_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_low_drink_vodka_animation_data.setPropertiesMoving(true);
        animpoint_sit_low_drink_vodka_animation_data.setPropertiesRandom(80);
        animpoint_sit_low_drink_vodka_animation_data.setPropertiesSumIdle(3);

        animpoint_sit_low_drink_vodka_animation_data.addAnimation("into", 0, "animpoint_sit_low_drink_in_1");
        animpoint_sit_low_drink_vodka_animation_data.addAnimationAttachItemName("into", 0, "vodka");
        animpoint_sit_low_drink_vodka_animation_data.addAnimation("into", 0, "animpoint_sit_low_drink_in_2");

        animpoint_sit_low_drink_vodka_animation_data.addAnimation("into", 1, "animpoint_sit_low_drink_in_1");
        animpoint_sit_low_drink_vodka_animation_data.addAnimationAttachItemName("into", 1, "vodka");
        animpoint_sit_low_drink_vodka_animation_data.addAnimation("into", 1, "animpoint_sit_low_drink_in_2");

        animpoint_sit_low_drink_vodka_animation_data.addAnimation("out", 0, "animpoint_sit_low_drink_out_1");
        animpoint_sit_low_drink_vodka_animation_data.addAnimationDettachItemName("out", 0, "vodka");
        animpoint_sit_low_drink_vodka_animation_data.addAnimation("out", 0, "animpoint_sit_low_drink_out_2");

        animpoint_sit_low_drink_vodka_animation_data.addAnimation("out", 1, "animpoint_sit_low_drink_out_1");
        animpoint_sit_low_drink_vodka_animation_data.addAnimationDettachItemName("out", 1, "vodka");
        animpoint_sit_low_drink_vodka_animation_data.addAnimation("out", 1, "animpoint_sit_low_drink_out_2");

        animpoint_sit_low_drink_vodka_animation_data.addAnimation("idle", 0, "animpoint_sit_low_drink_idle_1");
        animpoint_sit_low_drink_vodka_animation_data.addAnimation("idle", 0, "animpoint_sit_low_drink_idle_1");

        animpoint_sit_low_drink_vodka_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_drink_idle_rnd_1");
        animpoint_sit_low_drink_vodka_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_drink_idle_rnd_2");

        animpoint_sit_low_drink_vodka_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_drink_idle_rnd_1");
        animpoint_sit_low_drink_vodka_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_drink_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_sit_low_drink_vodka"] =
            animpoint_sit_low_drink_vodka_animation_data;

        StateManagerAnimationData animpoint_sit_low_drink_energy_animation_data;
        animpoint_sit_low_drink_energy_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_low_drink_energy_animation_data.setPropertiesMoving(true);
        animpoint_sit_low_drink_energy_animation_data.setPropertiesRandom(80);
        animpoint_sit_low_drink_energy_animation_data.setPropertiesSumIdle(3);

        animpoint_sit_low_drink_energy_animation_data.addAnimation("into", 0, "animpoint_sit_low_drink_in_1");
        animpoint_sit_low_drink_energy_animation_data.addAnimationAttachItemName("into", 0, "energy_drink");
        animpoint_sit_low_drink_energy_animation_data.addAnimation("into", 0, "animpoint_sit_low_drink_in_2");

        animpoint_sit_low_drink_energy_animation_data.addAnimation("into", 1, "animpoint_sit_low_drink_in_1");
        animpoint_sit_low_drink_energy_animation_data.addAnimationAttachItemName("into", 1, "energy_drink");
        animpoint_sit_low_drink_energy_animation_data.addAnimation("into", 1, "animpoint_sit_low_drink_in_2");

        animpoint_sit_low_drink_energy_animation_data.addAnimation("out", 0, "animpoint_sit_low_drink_out_1");
        animpoint_sit_low_drink_energy_animation_data.addAnimationDettachItemName("out", 0, "energy_drink");
        animpoint_sit_low_drink_energy_animation_data.addAnimation("out", 0, "animpoint_sit_low_drink_out_2");

        animpoint_sit_low_drink_energy_animation_data.addAnimation("out", 1, "animpoint_sit_low_drink_out_1");
        animpoint_sit_low_drink_energy_animation_data.addAnimationDettachItemName("out", 1, "energy_drink");
        animpoint_sit_low_drink_energy_animation_data.addAnimation("out", 1, "animpoint_sit_low_drink_out_2");

        animpoint_sit_low_drink_energy_animation_data.addAnimation("idle", 0, "animpoint_sit_low_drink_idle_1");
        animpoint_sit_low_drink_energy_animation_data.addAnimation("idle", 0, "animpoint_sit_low_drink_idle_1");

        animpoint_sit_low_drink_energy_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_drink_idle_rnd_1");
        animpoint_sit_low_drink_energy_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_drink_idle_rnd_2");

        animpoint_sit_low_drink_energy_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_drink_idle_rnd_1");
        animpoint_sit_low_drink_energy_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_drink_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_sit_low_drink_energy"] =
            animpoint_sit_low_drink_energy_animation_data;

        StateManagerAnimationData animpoint_stay_wall_guitar_animation_data;
        animpoint_stay_wall_guitar_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_wall_guitar_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_wall_guitar_animation_data.setPropertiesRandom(80);
        animpoint_stay_wall_guitar_animation_data.setPropertiesMoving(true);

        animpoint_stay_wall_guitar_animation_data.addAnimation("idle", 0, "idle_0_idle_1");
        animpoint_stay_wall_guitar_animation_data.addAnimation("idle", 1, "idle_0_idle_1");

        animpoint_stay_wall_guitar_animation_data.addAnimation("rnd", 0, "idle_0_idle_0");
        animpoint_stay_wall_guitar_animation_data.addAnimation("rnd", 1, "idle_0_idle_0");

        this->m_state_manager_animation_list["animpoint_stay_wall_guitar"] = animpoint_stay_wall_guitar_animation_data;

        StateManagerAnimationData animpoint_stay_table_guitar_animation_data;
        animpoint_stay_table_guitar_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_table_guitar_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_table_guitar_animation_data.setPropertiesRandom(80);
        animpoint_stay_table_guitar_animation_data.setPropertiesMoving(true);

        animpoint_stay_table_guitar_animation_data.addAnimation("idle", 0, "idle_0_idle_1");
        animpoint_stay_table_guitar_animation_data.addAnimation("idle", 1, "idle_0_idle_1");

        animpoint_stay_table_guitar_animation_data.addAnimation("rnd", 0, "idle_0_idle_0");
        animpoint_stay_table_guitar_animation_data.addAnimation("rnd", 1, "idle_0_idle_0");

        this->m_state_manager_animation_list["animpoint_stay_table_guitar"] =
            animpoint_stay_table_guitar_animation_data;

        StateManagerAnimationData animpoint_sit_high_guitar_animation_data;
        animpoint_sit_high_guitar_animation_data.setPropertiesMaxIdle(5);
        animpoint_sit_high_guitar_animation_data.setPropertiesSumIdle(3);
        animpoint_sit_high_guitar_animation_data.setPropertiesRandom(80);
        animpoint_sit_high_guitar_animation_data.setPropertiesMoving(true);

        animpoint_sit_high_guitar_animation_data.addAnimation("idle", 0, "idle_0_idle_1");
        animpoint_sit_high_guitar_animation_data.addAnimation("idle", 1, "idle_0_idle_1");

        animpoint_sit_high_guitar_animation_data.addAnimation("rnd", 0, "idle_0_idle_0");
        animpoint_sit_high_guitar_animation_data.addAnimation("rnd", 1, "idle_0_idle_0");

        this->m_state_manager_animation_list["animpoint_sit_high_guitar"] = animpoint_sit_high_guitar_animation_data;

        StateManagerAnimationData animpoint_sit_normal_guitar_animation_data;
        animpoint_sit_normal_guitar_animation_data.setPropertiesMaxIdle(0);
        animpoint_sit_normal_guitar_animation_data.setPropertiesSumIdle(0);
        animpoint_sit_normal_guitar_animation_data.setPropertiesRandom(80);
        animpoint_sit_normal_guitar_animation_data.setPropertiesMoving(true);

        animpoint_sit_normal_guitar_animation_data.addAnimation("into", 0, "animpoint_sit_normal_guitar_in_1");
        animpoint_sit_normal_guitar_animation_data.addAnimationAttachItemName("into", 0, "guitar_a");
        //    animpoint_sit_normal_guitar_animation_data.addAnimationFunction("into", 0, sr_camp.start_guitar); Lord:
        //    доделать!
        animpoint_sit_normal_guitar_animation_data.addAnimation("into", 0, "animpoint_sit_normal_guitar_in_2");

        animpoint_sit_normal_guitar_animation_data.addAnimation("into", 1, "animpoint_sit_normal_guitar_in_1");
        animpoint_sit_normal_guitar_animation_data.addAnimationAttachItemName("into", 1, "guitar_a");
        //    animpoint_sit_normal_guitar_animation_data.addAnimationFunction("into", 1, sr_camp.start_guitar); Lord:
        //    доделать!
        animpoint_sit_normal_guitar_animation_data.addAnimation("into", 1, "animpoint_sit_normal_guitar_in_2");

        animpoint_sit_normal_guitar_animation_data.addAnimation("out", 0, "animpoint_sit_normal_guitar_out_1");
        animpoint_sit_normal_guitar_animation_data.addAnimationDettachItemName("out", 0, "guitar_a");
        animpoint_sit_normal_guitar_animation_data.addAnimation("out", 0, "animpoint_sit_normal_guitar_out_2");

        animpoint_sit_normal_guitar_animation_data.addAnimation("out", 1, "animpoint_sit_normal_guitar_out_1");
        animpoint_sit_normal_guitar_animation_data.addAnimationDettachItemName("out", 1, "guitar_a");
        animpoint_sit_normal_guitar_animation_data.addAnimation("out", 1, "animpoint_sit_normal_guitar_out_2");

        animpoint_sit_normal_guitar_animation_data.addAnimation("idle", 0, "animpoint_sit_normal_guitar_idle_1");
        animpoint_sit_normal_guitar_animation_data.addAnimation("idle", 1, "animpoint_sit_normal_guitar_idle_1");

        animpoint_sit_normal_guitar_animation_data.addAnimation("rnd", 0, "animpoint_sit_normal_guitar_idle_rnd_1");
        animpoint_sit_normal_guitar_animation_data.addAnimation("rnd", 1, "animpoint_sit_normal_guitar_idle_rnd_1");

        this->m_state_manager_animation_list["animpoint_sit_normal_guitar"] =
            animpoint_sit_normal_guitar_animation_data;

        StateManagerAnimationData animpoint_sit_low_guitar_animation_data;
        animpoint_sit_low_guitar_animation_data.setPropertiesMaxIdle(0);
        animpoint_sit_low_guitar_animation_data.setPropertiesSumIdle(0);
        animpoint_sit_low_guitar_animation_data.setPropertiesRandom(80);
        animpoint_sit_low_guitar_animation_data.setPropertiesMoving(true);

        animpoint_sit_low_guitar_animation_data.addAnimation("into", 0, "animpoint_sit_low_guitar_in_1");
        animpoint_sit_low_guitar_animation_data.addAnimationAttachItemName("into", 0, "guitar_a");
        //    animpoint_sit_low_guitar_animation_data.addAnimationFunction("into", 0, sr_camp.start_guitar); Lord:
        //    доделать!
        animpoint_sit_low_guitar_animation_data.addAnimation("into", 0, "animpoint_sit_low_guitar_in_2");

        animpoint_sit_low_guitar_animation_data.addAnimation("into", 1, "animpoint_sit_low_guitar_in_1");
        animpoint_sit_low_guitar_animation_data.addAnimationAttachItemName("into", 1, "guitar_a");
        //    animpoint_sit_low_guitar.addAnimationFunction("into", 1, sr_camp.start_guitar); Lord:
        //    доделать!
        animpoint_sit_low_guitar_animation_data.addAnimation("into", 1, "animpoint_sit_low_guitar_in_2");

        animpoint_sit_low_guitar_animation_data.addAnimation("out", 0, "animpoint_sit_low_guitar_out_1");
        animpoint_sit_low_guitar_animation_data.addAnimationDettachItemName("out", 0, "guitar_a");
        animpoint_sit_low_guitar_animation_data.addAnimation("out", 0, "animpoint_sit_low_guitar_out_2");

        animpoint_sit_low_guitar_animation_data.addAnimation("out", 1, "animpoint_sit_low_guitar_out_1");
        animpoint_sit_low_guitar_animation_data.addAnimationDettachItemName("out", 1, "guitar_a");
        animpoint_sit_low_guitar_animation_data.addAnimation("out", 1, "animpoint_sit_low_guitar_out_2");

        animpoint_sit_low_guitar_animation_data.addAnimation("idle", 0, "animpoint_sit_low_guitar_idle_1");
        animpoint_sit_low_guitar_animation_data.addAnimation("idle", 0, "animpoint_sit_low_guitar_idle_1");

        animpoint_sit_low_guitar_animation_data.addAnimation("rnd", 0, "animpoint_sit_low_guitar_idle_rnd_2");
        animpoint_sit_low_guitar_animation_data.addAnimation("rnd", 1, "animpoint_sit_low_guitar_idle_rnd_2");

        this->m_state_manager_animation_list["animpoint_sit_low_guitar"] = animpoint_sit_low_guitar_animation_data;

        StateManagerAnimationData animpoint_stay_wall_harmonica_animation_data;
        animpoint_stay_wall_harmonica_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_wall_harmonica_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_wall_harmonica_animation_data.setPropertiesRandom(80);
        animpoint_stay_wall_harmonica_animation_data.setPropertiesMoving(true);

        animpoint_stay_wall_harmonica_animation_data.addAnimation("idle", 0, "idle_0_idle_1");
        animpoint_stay_wall_harmonica_animation_data.addAnimation("idle", 1, "idle_0_idle_1");

        animpoint_stay_wall_harmonica_animation_data.addAnimation("rnd", 0, "idle_0_idle_0");
        animpoint_stay_wall_harmonica_animation_data.addAnimation("rnd", 1, "idle_0_idle_0");

        this->m_state_manager_animation_list["animpoint_stay_wall_harmonica"] =
            animpoint_stay_wall_harmonica_animation_data;

        StateManagerAnimationData animpoint_stay_table_harmonica_animation_data;
        animpoint_stay_table_harmonica_animation_data.setPropertiesMaxIdle(5);
        animpoint_stay_table_harmonica_animation_data.setPropertiesSumIdle(3);
        animpoint_stay_table_harmonica_animation_data.setPropertiesRandom(80);
        animpoint_stay_table_harmonica_animation_data.setPropertiesMoving(true);

        animpoint_stay_table_harmonica_animation_data.addAnimation("idle", 0, "idle_0_idle_1");
        animpoint_stay_table_harmonica_animation_data.addAnimation("idle", 1, "idle_0_idle_1");

        animpoint_stay_table_harmonica_animation_data.addAnimation("rnd", 0, "idle_0_idle_0");
        animpoint_stay_table_harmonica_animation_data.addAnimation("rnd", 1, "idle_0_idle_0");

        this->m_state_manager_animation_list["animpoint_stay_table_harmonica"] =
            animpoint_stay_table_harmonica_animation_data;

        StateManagerAnimationData animpoint_sit_high_harmonica_animation_data;
        animpoint_sit_high_harmonica_animation_data.setPropertiesMaxIdle(0);
        animpoint_sit_high_harmonica_animation_data.setPropertiesSumIdle(0);
        animpoint_sit_high_harmonica_animation_data.setPropertiesRandom(100);
        animpoint_sit_high_harmonica_animation_data.setPropertiesMoving(true);

        animpoint_sit_high_harmonica_animation_data.addAnimation("into", 0, "animpoint_sit_high_harmonica_in_1");
        animpoint_sit_high_harmonica_animation_data.addAnimationAttachItemName("into", 0, "harmonica_a");
        //    animpoint_sit_high_harmonica_animation_data.addAnimationFunction("into", 0, sr_camp.start_harmonica);
        //    Lord: доделать!
        animpoint_sit_high_harmonica_animation_data.addAnimation("into", 0, "animpoint_sit_high_harmonica_in_2");

        animpoint_sit_high_harmonica_animation_data.addAnimation("into", 1, "animpoint_sit_high_harmonica_in_1");
        animpoint_sit_high_harmonica_animation_data.addAnimationAttachItemName("into", 1, "harmonica_a");
        //    animpoint_sit_low_guitar.addAnimationFunction("into", 1, sr_camp.start_harmonica); Lord:
        //    доделать!
        animpoint_sit_high_harmonica_animation_data.addAnimation("into", 1, "animpoint_sit_high_harmonica_in_2");

        animpoint_sit_high_harmonica_animation_data.addAnimation("out", 0, "animpoint_sit_high_harmonica_out_1");
        animpoint_sit_high_harmonica_animation_data.addAnimationDettachItemName("out", 0, "harmonica_a");
        animpoint_sit_high_harmonica_animation_data.addAnimation("out", 0, "animpoint_sit_high_harmonica_out_2");

        animpoint_sit_high_harmonica_animation_data.addAnimation("out", 1, "animpoint_sit_high_harmonica_out_1");
        animpoint_sit_high_harmonica_animation_data.addAnimationDettachItemName("out", 1, "harmonica_a");
        animpoint_sit_high_harmonica_animation_data.addAnimation("out", 1, "animpoint_sit_high_harmonica_out_2");

        animpoint_sit_high_harmonica_animation_data.addAnimation("idle", 0, "animpoint_sit_high_harmonica_idle_1");
        animpoint_sit_high_harmonica_animation_data.addAnimation("idle", 1, "animpoint_sit_high_harmonica_idle_1");

        this->m_state_manager_animation_list["animpoint_sit_high_harmonica"] =
            animpoint_sit_high_harmonica_animation_data;

        StateManagerAnimationData animpoint_sit_normal_harmonica_animation_data;
        animpoint_sit_normal_harmonica_animation_data.setPropertiesMaxIdle(0);
        animpoint_sit_normal_harmonica_animation_data.setPropertiesSumIdle(0);
        animpoint_sit_normal_harmonica_animation_data.setPropertiesRandom(100);
        animpoint_sit_normal_harmonica_animation_data.setPropertiesMoving(true);

        animpoint_sit_normal_harmonica_animation_data.addAnimation("idle", 0, "idle_0_idle_1");
        animpoint_sit_normal_harmonica_animation_data.addAnimation("idle", 1, "idle_0_idle_1");

        animpoint_sit_normal_harmonica_animation_data.addAnimation("rnd", 0, "idle_0_idle_0");
        animpoint_sit_normal_harmonica_animation_data.addAnimation("rnd", 1, "idle_0_idle_0");

        this->m_state_manager_animation_list["animpoint_sit_normal_harmonica"] =
            animpoint_sit_normal_harmonica_animation_data;

        StateManagerAnimationData animpoint_sit_low_harmonica_animation_data;
        animpoint_sit_low_harmonica_animation_data.setPropertiesMaxIdle(0);
        animpoint_sit_low_harmonica_animation_data.setPropertiesSumIdle(0);
        animpoint_sit_low_harmonica_animation_data.setPropertiesRandom(100);
        animpoint_sit_low_harmonica_animation_data.setPropertiesMoving(true);

        animpoint_sit_low_harmonica_animation_data.addAnimation("into", 0, "animpoint_sit_low_harmonica_in_1");
        animpoint_sit_low_harmonica_animation_data.addAnimationAttachItemName("into", 0, "harmonica_a");
        //    animpoint_sit_low_harmonica_animation_data.addAnimationFunction("into", 0, sr_camp.start_harmonica);
        //    Lord: доделать!
        animpoint_sit_low_harmonica_animation_data.addAnimation("into", 0, "animpoint_sit_low_harmonica_in_2");

        animpoint_sit_low_harmonica_animation_data.addAnimation("into", 1, "animpoint_sit_low_harmonica_in_1");
        animpoint_sit_low_harmonica_animation_data.addAnimationAttachItemName("into", 1, "harmonica_a");
        //    animpoint_sit_low_guitar.addAnimationFunction("into", 1, sr_camp.start_harmonica); Lord:
        //    доделать!
        animpoint_sit_low_harmonica_animation_data.addAnimation("into", 1, "animpoint_sit_low_harmonica_in_2");

        animpoint_sit_low_harmonica_animation_data.addAnimation("out", 0, "animpoint_sit_low_harmonica_out_1");
        animpoint_sit_low_harmonica_animation_data.addAnimationDettachItemName("out", 0, "harmonica_a");
        animpoint_sit_low_harmonica_animation_data.addAnimation("out", 0, "animpoint_sit_low_harmonica_out_2");

        animpoint_sit_low_harmonica_animation_data.addAnimation("out", 1, "animpoint_sit_low_harmonica_out_1");
        animpoint_sit_low_harmonica_animation_data.addAnimationDettachItemName("out", 1, "harmonica_a");
        animpoint_sit_low_harmonica_animation_data.addAnimation("out", 1, "animpoint_sit_low_harmonica_out_2");

        animpoint_sit_low_harmonica_animation_data.addAnimation("idle", 0, "animpoint_sit_low_harmonica_idle_1");
        animpoint_sit_low_harmonica_animation_data.addAnimation("idle", 1, "animpoint_sit_low_harmonica_idle_1");

        this->m_state_manager_animation_list["animpoint_sit_low_harmonica"] =
            animpoint_sit_low_harmonica_animation_data;

        StateManagerAnimationData zat_b14_give_artefact_idle_animation_data;
        zat_b14_give_artefact_idle_animation_data.setPropertiesMaxIdle(1);
        zat_b14_give_artefact_idle_animation_data.setPropertiesSumIdle(4);
        zat_b14_give_artefact_idle_animation_data.setPropertiesRandom(100);

        zat_b14_give_artefact_idle_animation_data.addAnimation("into", 0, "zat_b14_give_artefact_ible");
        zat_b14_give_artefact_idle_animation_data.addAnimationAttachItemName("into", 0, "af_quest_b14_twisted");

        zat_b14_give_artefact_idle_animation_data.addAnimation("idle", 0, "zat_b14_give_artefact_ible");

        this->m_state_manager_animation_list["zat_b14_give_artefact_idle"] = zat_b14_give_artefact_idle_animation_data;

        StateManagerAnimationData zat_b14_give_artefact_act_animation_data;
        zat_b14_give_artefact_act_animation_data.setPropertiesMaxIdle(1);
        zat_b14_give_artefact_act_animation_data.setPropertiesSumIdle(1);
        zat_b14_give_artefact_act_animation_data.setPropertiesRandom(100);

        zat_b14_give_artefact_act_animation_data.addAnimation("into", 0, "zat_b14_give_artefact_in");
        zat_b14_give_artefact_act_animation_data.addAnimationDettachItemName("into", 0, "af_quest_b14_twisted");
        zat_b14_give_artefact_act_animation_data.addAnimation("into", 0, "zat_b14_give_artefact_out");

        this->m_state_manager_animation_list["zat_b14_give_artefact_act"] = zat_b14_give_artefact_act_animation_data;

        StateManagerAnimationData zat_b14_stay_wall_animation_data;
        zat_b14_stay_wall_animation_data.setPropertiesRandom(100);
        zat_b14_stay_wall_animation_data.setPropertiesMoving(true);
        zat_b14_stay_wall_animation_data.setPropertiesMaxIdle(1);
        zat_b14_stay_wall_animation_data.setPropertiesSumIdle(1);

        zat_b14_stay_wall_animation_data.addAnimation("into", 0, "animpoint_stay_wall_in_1");
        zat_b14_stay_wall_animation_data.addAnimation("out", 0, "animpoint_stay_wall_out_1");
        zat_b14_stay_wall_animation_data.addAnimation("idle", 0, "animpoint_stay_wall_idle_1");

        this->m_state_manager_animation_list["zat_b14_stay_wall"] = zat_b14_stay_wall_animation_data;

        StateManagerAnimationData zat_b38_stalker_break_lock_animation_data;
        zat_b38_stalker_break_lock_animation_data.setPropertiesMaxIdle(1);
        zat_b38_stalker_break_lock_animation_data.setPropertiesSumIdle(1);
        zat_b38_stalker_break_lock_animation_data.setPropertiesRandom(100);
        zat_b38_stalker_break_lock_animation_data.setPropertiesMoving(true);

        zat_b38_stalker_break_lock_animation_data.addAnimation("into", 0, "zat_b38_stalker_break_lock");
        // zat_b38_stalker_break_lock_animation_data.addAnimationFunction("into", 0,
        // xr_effects.zat_b38_underground_door_open); Lord: доделать!

        this->m_state_manager_animation_list["zat_b38_stalker_break_lock"] = zat_b38_stalker_break_lock_animation_data;

        StateManagerAnimationData zat_b38_stalker_turn_on_lift_animation_data;
        zat_b38_stalker_turn_on_lift_animation_data.setPropertiesMaxIdle(1);
        zat_b38_stalker_turn_on_lift_animation_data.setPropertiesSumIdle(1);
        zat_b38_stalker_turn_on_lift_animation_data.setPropertiesMoving(true);
        zat_b38_stalker_turn_on_lift_animation_data.setPropertiesRandom(100);

        zat_b38_stalker_turn_on_lift_animation_data.addAnimation("into", 0, "zat_b38_stalker_jump_lift_in_1");
        // zat_b38_stalker_turn_on_lift_animation_data.addAnimationFunction("into", 0, xr_effects.zat_b38_open_info);
        // Lord: доделать!
        zat_b38_stalker_turn_on_lift_animation_data.addAnimation("into", 0, "zat_b38_stalker_jump_lift_in_2");
        // zat_b38_stalker_turn_on_lift_animation_data.addAnimationFunction("into", 0, xr_effects.zat_b38_switch_info);
        // Lord: доделать!
        zat_b38_stalker_turn_on_lift_animation_data.addAnimation("into", 0, "zat_b38_stalker_jump_lift_in_3");
        zat_b38_stalker_turn_on_lift_animation_data.addAnimation("into", 0, "zat_b38_stalker_jump_lift_idle");
        zat_b38_stalker_turn_on_lift_animation_data.addAnimation("into", 0, "zat_b38_stalker_jump_lift_out");

        this->m_state_manager_animation_list["zat_b38_stalker_turn_on_lift"] =
            zat_b38_stalker_turn_on_lift_animation_data;

        StateManagerAnimationData zat_b38_stalker_jump_tonnel_animation_data;
        zat_b38_stalker_jump_tonnel_animation_data.setPropertiesMaxIdle(1);
        zat_b38_stalker_jump_tonnel_animation_data.setPropertiesSumIdle(1);
        zat_b38_stalker_jump_tonnel_animation_data.setPropertiesRandom(100);
        zat_b38_stalker_jump_tonnel_animation_data.setPropertiesMoving(true);

        zat_b38_stalker_jump_tonnel_animation_data.addAnimation("into", 0, "zat_b38_stalker_jump_tonnel");
        //   zat_b38_stalker_jump_tonnel_animation_data.addAnimationFunction("into", 0,
        //   xr_effects.zat_b38_jump_tonnel_info); Lord: доделать!

        this->m_state_manager_animation_list["zat_b38_stalker_jump_tonnel"] =
            zat_b38_stalker_jump_tonnel_animation_data;

        StateManagerAnimationData zat_b20_noah_jump_animation_data;
        zat_b20_noah_jump_animation_data.setPropertiesMaxIdle(1);
        zat_b20_noah_jump_animation_data.setPropertiesSumIdle(1);
        zat_b20_noah_jump_animation_data.setPropertiesMoving(true);
        zat_b20_noah_jump_animation_data.setPropertiesRandom(100);

        zat_b20_noah_jump_animation_data.addAnimation("into", 0, "zat_b20_noah_jump");

        this->m_state_manager_animation_list["zat_b20_noah_jump"] = zat_b20_noah_jump_animation_data;

        StateManagerAnimationData zat_b38_stalker_alert_animation_data;
        zat_b38_stalker_alert_animation_data.setPropertiesMaxIdle(1);
        zat_b38_stalker_alert_animation_data.setPropertiesSumIdle(1);
        zat_b38_stalker_alert_animation_data.setPropertiesRandom(100);
        zat_b38_stalker_alert_animation_data.setPropertiesMoving(true);

        zat_b38_stalker_alert_animation_data.addAnimation("into", 0, "zat_b38_stalker_alert");
        // zat_b38_stalker_alert_animation_data.addAnimationFunction("into", 0, xr_effects.pri_a17_ice_climb_end); Lord:
        // доделать!

        this->m_state_manager_animation_list["zat_b38_stalker_alert"] = zat_b38_stalker_alert_animation_data;

        StateManagerAnimationData pri_a17_ice_climb_animation_data;
        pri_a17_ice_climb_animation_data.setPropertiesMaxIdle(1);
        pri_a17_ice_climb_animation_data.setPropertiesSumIdle(1);
        pri_a17_ice_climb_animation_data.setPropertiesMoving(true);
        pri_a17_ice_climb_animation_data.setPropertiesRandom(100);

        pri_a17_ice_climb_animation_data.addAnimation("into", 0, "pri_a17_sniper_climbing");

        this->m_state_manager_animation_list["pri_a17_ice_climb"] = pri_a17_ice_climb_animation_data;

        StateManagerAnimationData pri_a17_fall_down_animation_data;
        pri_a17_fall_down_animation_data.setPropertiesMaxIdle(1);
        pri_a17_fall_down_animation_data.setPropertiesSumIdle(1);
        pri_a17_fall_down_animation_data.setPropertiesRandom(100);
        pri_a17_fall_down_animation_data.setPropertiesMoving(true);

        pri_a17_fall_down_animation_data.addAnimation("into", 0, "ragdoll_sniper_body_front_2");
        //  pri_a17_fall_down_animation_data.addAnimationFunction("into", 0, xr_effects.pri_a17_preacher_death); Lord:
        //  доделать!

        this->m_state_manager_animation_list["pri_a17_fall_down"] = pri_a17_fall_down_animation_data;

        StateManagerAnimationData pri_a17_pray_in_animation_data;
        pri_a17_pray_in_animation_data.setPropertiesMaxIdle(1);
        pri_a17_pray_in_animation_data.setPropertiesSumIdle(1);
        pri_a17_pray_in_animation_data.setPropertiesRandom(100);
        pri_a17_pray_in_animation_data.setPropertiesMoving(true);

        pri_a17_pray_in_animation_data.addAnimation("into", 0, "pri_a17_preacher_sermon_in");
        //  pri_a17_pray_in_animation_data.addAnimationFunction("into", 0, xr_effects.pri_a17_pray_start); // Lord:
        //  доделать!
        pri_a17_pray_in_animation_data.addAnimation("into", 0, "pri_a17_preacher_sermon_out");

        this->m_state_manager_animation_list["pri_a17_pray_in"] = pri_a17_pray_in_animation_data;

        StateManagerAnimationData pri_a17_pray_animation_data;
        pri_a17_pray_animation_data.setPropertiesMaxIdle(1);
        pri_a17_pray_animation_data.setPropertiesSumIdle(1);
        pri_a17_pray_animation_data.setPropertiesMoving(true);
        pri_a17_pray_animation_data.setPropertiesRandom(100);

        pri_a17_pray_animation_data.addAnimation("idle", 0, "pri_a17_preacher_sermon_out");

        this->m_state_manager_animation_list["pri_a17_pray"] = pri_a17_pray_animation_data;

        StateManagerAnimationData dynamite_animation_data;
        dynamite_animation_data.setPropertiesMaxIdle(1);
        dynamite_animation_data.setPropertiesSumIdle(1);
        dynamite_animation_data.setPropertiesRandom(100);

        dynamite_animation_data.addAnimation("into", 0, "dinamit_1");

        this->m_state_manager_animation_list["dynamite"] = dynamite_animation_data;

        StateManagerAnimationData bloodsucker_panic_animation_data;
        bloodsucker_panic_animation_data.setPropertiesMaxIdle(1);
        bloodsucker_panic_animation_data.setPropertiesSumIdle(1);
        bloodsucker_panic_animation_data.setPropertiesRandom(100);

        bloodsucker_panic_animation_data.addAnimation("idle", 0, "norm_alert_attack_0");

        this->m_state_manager_animation_list["bloodsucker_panic"] = bloodsucker_panic_animation_data;

        StateManagerAnimationData bloodsucker_search_animation_data;
        bloodsucker_search_animation_data.setPropertiesMaxIdle(0);
        bloodsucker_search_animation_data.setPropertiesSumIdle(0);
        bloodsucker_search_animation_data.setPropertiesRandom(100);

        bloodsucker_search_animation_data.addAnimation("into", 0, "norm_alert_in_0");

        bloodsucker_search_animation_data.addAnimation("idle", 0, "norm_alert_idle_0");

        bloodsucker_search_animation_data.addAnimation("out", 0, "norm_alert_out_0");

        bloodsucker_search_animation_data.addAnimation("rnd", 0, "norm_alert_idle_0");
        bloodsucker_search_animation_data.addAnimation("rnd", 0, "norm_alert_idle_1");
        bloodsucker_search_animation_data.addAnimation("rnd", 0, "norm_alert_idle_3");

        this->m_state_manager_animation_list["bloodsucker_search"] = bloodsucker_search_animation_data;

        StateManagerAnimationData give_orders_animation_data;
        give_orders_animation_data.setPropertiesMaxIdle(1);
        give_orders_animation_data.setPropertiesSumIdle(1);
        give_orders_animation_data.setPropertiesRandom(100);

        give_orders_animation_data.addAnimation("into", 0, "norm_alert_idle_0");
        give_orders_animation_data.addAnimation("into", 0, "norm_alert_command_0");

        this->m_state_manager_animation_list["give_orders"] = give_orders_animation_data;

        StateManagerAnimationData zat_b22_medic_turn_idle_animation_data;
        zat_b22_medic_turn_idle_animation_data.setPropertiesMaxIdle(1);
        zat_b22_medic_turn_idle_animation_data.setPropertiesSumIdle(1);
        zat_b22_medic_turn_idle_animation_data.setPropertiesMoving(true);

        zat_b22_medic_turn_idle_animation_data.addAnimation("idle", 0, "zat_b22_medic_turn_idle");

        this->m_state_manager_animation_list["zat_b22_medic_turn_idle"] = zat_b22_medic_turn_idle_animation_data;

        StateManagerAnimationData zat_b22_medic_turn_out_animation_data;
        zat_b22_medic_turn_out_animation_data.setPropertiesMaxIdle(1);
        zat_b22_medic_turn_out_animation_data.setPropertiesSumIdle(1);
        zat_b22_medic_turn_out_animation_data.setPropertiesMoving(true);

        zat_b22_medic_turn_out_animation_data.addAnimation("into", 0, "zat_b22_medic_turn_out");

        this->m_state_manager_animation_list["zat_b22_medic_turn_out"] = zat_b22_medic_turn_out_animation_data;

        StateManagerAnimationData zat_b22_medic_suicide_animation_data;
        zat_b22_medic_suicide_animation_data.setPropertiesMaxIdle(1);
        zat_b22_medic_suicide_animation_data.setPropertiesSumIdle(1);
        zat_b22_medic_suicide_animation_data.setPropertiesMoving(true);

        zat_b22_medic_suicide_animation_data.addAnimation("into", 0, "zat_b22_medic_suicide_in");
        zat_b22_medic_suicide_animation_data.addAnimation("idle", 0, "zat_b22_medic_suicide_idle");

        this->m_state_manager_animation_list["zat_b22_medic_suicide"] = zat_b22_medic_suicide_animation_data;

        StateManagerAnimationData zat_b3_tech_drunk_animation_data;
        zat_b3_tech_drunk_animation_data.setPropertiesMaxIdle(1);
        zat_b3_tech_drunk_animation_data.setPropertiesSumIdle(1);
        zat_b3_tech_drunk_animation_data.setPropertiesRandom(100);
        zat_b3_tech_drunk_animation_data.setPropertiesMoving(true);

        zat_b3_tech_drunk_animation_data.addAnimation("into", 0, "zat_b3_tech_drunk_in");

        zat_b3_tech_drunk_animation_data.addAnimation("out", 0, "zat_b3_tech_drunk_out");
        //  zat_b3_tech_drunk_animation_data.addAnimationFunction("out", 0, xr_effects.zat_b3_tech_waked_up);

        zat_b3_tech_drunk_animation_data.addAnimation("idle", 0, "zat_b3_tech_drunk_idle");

        this->m_state_manager_animation_list["zat_b3_tech_drunk"] = zat_b3_tech_drunk_animation_data;

        StateManagerAnimationData zat_b3_tech_idle_1_animation_data;
        zat_b3_tech_idle_1_animation_data.setPropertiesMaxIdle(1);
        zat_b3_tech_idle_1_animation_data.setPropertiesSumIdle(1);
        zat_b3_tech_idle_1_animation_data.setPropertiesRandom(100);
        zat_b3_tech_idle_1_animation_data.setPropertiesMoving(true);

        zat_b3_tech_idle_1_animation_data.addAnimation("idle", 0, "zat_b3_tech_idle_1");

        this->m_state_manager_animation_list["zat_b3_tech_idle_1"] = zat_b3_tech_idle_1_animation_data;

        StateManagerAnimationData zat_b3_tech_surprise_animation_data;
        zat_b3_tech_surprise_animation_data.setPropertiesMaxIdle(1);
        zat_b3_tech_surprise_animation_data.setPropertiesSumIdle(1);
        zat_b3_tech_surprise_animation_data.setPropertiesRandom(100);
        zat_b3_tech_surprise_animation_data.setPropertiesMoving(true);

        zat_b3_tech_surprise_animation_data.addAnimation("into", 0, "zat_b3_tech_surprise");
        //    zat_b3_tech_surprise_animation_data.addAnimationFunction("into", 0,
        //    xr_effects.zat_b3_tech_surprise_anim_end); // Lord: доделать!

        zat_b3_tech_surprise_animation_data.addAnimation("out", 0, "zat_b3_tech_drunk_idle");
        zat_b3_tech_surprise_animation_data.addAnimation("idle", 0, "zat_b3_tech_drunk_idle");

        this->m_state_manager_animation_list["zat_b3_tech_surprise"] = zat_b3_tech_surprise_animation_data;

        StateManagerAnimationData zat_b3_tech_drink_animation_data;
        zat_b3_tech_drink_animation_data.setPropertiesMaxIdle(1);
        zat_b3_tech_drink_animation_data.setPropertiesSumIdle(1);
        zat_b3_tech_drink_animation_data.setPropertiesMoving(true);
        zat_b3_tech_drink_animation_data.setPropertiesRandom(100);

        zat_b3_tech_drink_animation_data.addAnimation("into", 0, "zat_b3_tech_drink_in");
        zat_b3_tech_drink_animation_data.addAnimationAttachItemName("into", 0, "vodka");

        zat_b3_tech_drink_animation_data.addAnimationDettachItemName("out", 0, "vodka");
        zat_b3_tech_drink_animation_data.addAnimation("out", 0, "zat_b3_tech_drink_out");
        // zat_b3_tech_drink_animation_data.addAnimationFunction("out", 0, xr_effects.zat_b3_tech_drinked_out); // Lord:
        // доделать!

        zat_b3_tech_drink_animation_data.addAnimation("idle", 0, "zat_b3_tech_drink_idle");

        this->m_state_manager_animation_list["zat_b3_tech_drink"] = zat_b3_tech_drink_animation_data;

        StateManagerAnimationData jup_b10_drunk_ravings_animation_data;
        jup_b10_drunk_ravings_animation_data.setPropertiesMaxIdle(1);
        jup_b10_drunk_ravings_animation_data.setPropertiesSumIdle(1);
        jup_b10_drunk_ravings_animation_data.setPropertiesRandom(100);
        jup_b10_drunk_ravings_animation_data.setPropertiesMoving(true);

        jup_b10_drunk_ravings_animation_data.addAnimation("idle", 0, "zat_b3_tech_drunk_idle");

        this->m_state_manager_animation_list["jup_b10_drunk_ravings"] = jup_b10_drunk_ravings_animation_data;

        StateManagerAnimationData pas_b400_vano_probe_animation_data;
        pas_b400_vano_probe_animation_data.setPropertiesMaxIdle(0);
        pas_b400_vano_probe_animation_data.setPropertiesSumIdle(0);
        pas_b400_vano_probe_animation_data.setPropertiesRandom(100);

        pas_b400_vano_probe_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_0");
        pas_b400_vano_probe_animation_data.addAnimationAttachItemName("into", 0, "detector_elite");
        pas_b400_vano_probe_animation_data.addAnimation("into", 0, "metering_anomalys_0_draw_1");

        pas_b400_vano_probe_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_0");
        pas_b400_vano_probe_animation_data.addAnimationDettachItemName("out", 0, "detector_elite");
        pas_b400_vano_probe_animation_data.addAnimation("out", 0, "metering_anomalys_0_hide_1");

        pas_b400_vano_probe_animation_data.addAnimation("idle", 0, "metering_anomalys_0_idle_0");

        this->m_state_manager_animation_list["pas_b400_vano_probe"] = pas_b400_vano_probe_animation_data;

        StateManagerAnimationData pri_a28_kirillov_sit_high_radio_animation_data;
        pri_a28_kirillov_sit_high_radio_animation_data.setPropertiesMaxIdle(0);
        pri_a28_kirillov_sit_high_radio_animation_data.setPropertiesSumIdle(0);
        pri_a28_kirillov_sit_high_radio_animation_data.setPropertiesRandom(100);

        pri_a28_kirillov_sit_high_radio_animation_data.addAnimation("into", 0, "pri_a28_kirillov_radio_on_in");
        //     pri_a28_kirillov_sit_high_radio_animation_data.addAnimationFunction("into", 0,
        //     xr_effects.pri_a28_kirillov_hq_online); // Lord: доделать!

        pri_a28_kirillov_sit_high_radio_animation_data.addAnimation("out", 0, "pri_a28_kirillov_radio_on_out");

        pri_a28_kirillov_sit_high_radio_animation_data.addAnimation("idle", 0, "pri_a28_kirillov_radio_on_idle");

        this->m_state_manager_animation_list["pri_a28_kirillov_sit_high_radio"] =
            pri_a28_kirillov_sit_high_radio_animation_data;

        StateManagerAnimationData pri_a18_inspert_monolit_actor_animation_data;
        pri_a18_inspert_monolit_actor_animation_data.setPropertiesRandom(0);
        pri_a18_inspert_monolit_actor_animation_data.setPropertiesMaxIdle(1);
        pri_a18_inspert_monolit_actor_animation_data.setPropertiesSumIdle(1);
        pri_a18_inspert_monolit_actor_animation_data.setPropertiesMoving(true);

        pri_a18_inspert_monolit_actor_animation_data.addAnimationAttachItemName("into", 0, "hand_radio_r");
        pri_a18_inspert_monolit_actor_animation_data.addAnimation("into", 0, "pri_a18_inspert_monolit_actor_in");
        //    pri_a18_inspert_monolit_actor_animation_data.addAnimationFunction("into", 0,
        //    xr_effects.pri_a18_radio_start); // Lord: доделать!
        pri_a18_inspert_monolit_actor_animation_data.addAnimation("into", 0, "pri_a18_inspert_monolit_actor_idle");
        pri_a18_inspert_monolit_actor_animation_data.addAnimation("into", 0, "pri_a18_inspert_monolit_actor_idle");
        pri_a18_inspert_monolit_actor_animation_data.addAnimation("into", 0, "pri_a18_inspert_monolit_actor_idle");
        pri_a18_inspert_monolit_actor_animation_data.addAnimation("into", 0, "pri_a18_inspert_monolit_actor_out");
        pri_a18_inspert_monolit_actor_animation_data.addAnimationDettachItemName("into", 0, "hand_radio_r");

        this->m_state_manager_animation_list["pri_a18_inspert_monolit_actor"] =
            pri_a18_inspert_monolit_actor_animation_data;

        StateManagerAnimationData pri_a21_sentry_madness_animation_data;
        pri_a21_sentry_madness_animation_data.setPropertiesMaxIdle(1);
        pri_a21_sentry_madness_animation_data.setPropertiesSumIdle(1);
        pri_a21_sentry_madness_animation_data.setPropertiesMoving(true);

        pri_a21_sentry_madness_animation_data.addAnimation("idle", 0, "pri_a21_sentry_madness_idle");

        this->m_state_manager_animation_list["pri_a21_sentry_madness"] = pri_a21_sentry_madness_animation_data;

        StateManagerAnimationData pri_a21_sentry_madness_suicide_animation_data;
        pri_a21_sentry_madness_suicide_animation_data.setPropertiesMaxIdle(1);
        pri_a21_sentry_madness_suicide_animation_data.setPropertiesSumIdle(1);
        pri_a21_sentry_madness_suicide_animation_data.setPropertiesMoving(true);

        pri_a21_sentry_madness_suicide_animation_data.addAnimation("into", 0, "pri_a21_sentry_madness_suicide");

        pri_a21_sentry_madness_suicide_animation_data.addAnimation("out", 0, "pri_a21_sentry_madness_suicide_idle");

        this->m_state_manager_animation_list["pri_a21_sentry_madness_suicide"] =
            pri_a21_sentry_madness_suicide_animation_data;

        StateManagerAnimationData pri_a22_colonel_lean_on_table_in_animation_data;
        pri_a22_colonel_lean_on_table_in_animation_data.setPropertiesMaxIdle(1);
        pri_a22_colonel_lean_on_table_in_animation_data.setPropertiesSumIdle(1);
        pri_a22_colonel_lean_on_table_in_animation_data.setPropertiesRandom(100);
        pri_a22_colonel_lean_on_table_in_animation_data.setPropertiesMoving(true);

        pri_a22_colonel_lean_on_table_in_animation_data.addAnimation("into", 0, "pri_a22_colonel_lean_on_tadl_in");

        pri_a22_colonel_lean_on_table_in_animation_data.addAnimation("idle", 0, "pri_a22_colonel_lean_on_tadl_idle");

        this->m_state_manager_animation_list["pri_a22_colonel_lean_on_table_in"] =
            pri_a22_colonel_lean_on_table_in_animation_data;

        StateManagerAnimationData pri_a22_colonel_lean_on_table_idle_animation_data;
        pri_a22_colonel_lean_on_table_idle_animation_data.setPropertiesMaxIdle(1);
        pri_a22_colonel_lean_on_table_idle_animation_data.setPropertiesSumIdle(1);
        pri_a22_colonel_lean_on_table_idle_animation_data.setPropertiesRandom(100);

        pri_a22_colonel_lean_on_table_idle_animation_data.addAnimation("idle", 0, "pri_a22_colonel_lean_on_tadl_idle");

        this->m_state_manager_animation_list["pri_a22_colonel_lean_on_table_idle"] =
            pri_a22_colonel_lean_on_table_idle_animation_data;

        StateManagerAnimationData pri_a22_colonel_stand_from_table_animation_data;
        pri_a22_colonel_stand_from_table_animation_data.setPropertiesMaxIdle(1);
        pri_a22_colonel_stand_from_table_animation_data.setPropertiesSumIdle(1);
        pri_a22_colonel_stand_from_table_animation_data.setPropertiesMoving(true);
        pri_a22_colonel_stand_from_table_animation_data.setPropertiesRandom(100);

        pri_a22_colonel_stand_from_table_animation_data.addAnimation("into", 0, "pri_a22_colonel_lean_on_tadl_out");

        this->m_state_manager_animation_list["pri_a22_colonel_stand_from_table"] =
            pri_a22_colonel_stand_from_table_animation_data;

        StateManagerAnimationData pri_a28_army_trance_out_animation_data;
        pri_a28_army_trance_out_animation_data.setPropertiesMaxIdle(1);
        pri_a28_army_trance_out_animation_data.setPropertiesSumIdle(1);
        pri_a28_army_trance_out_animation_data.setPropertiesMoving(true);

        pri_a28_army_trance_out_animation_data.addAnimation("into", 0, "pri_a28_army_trance_out_in");
        pri_a28_army_trance_out_animation_data.addAnimation("out", 0, "pri_a28_army_trance_out_out");
        pri_a28_army_trance_out_animation_data.addAnimation("idle", 0, "pri_a28_army_trance_out_idle");

        this->m_state_manager_animation_list["pri_a28_army_trance_out"] = pri_a28_army_trance_out_animation_data;

        StateManagerAnimationData zat_b106_wounded_idle_animation_data;
        zat_b106_wounded_idle_animation_data.setPropertiesMaxIdle(1);
        zat_b106_wounded_idle_animation_data.setPropertiesSumIdle(1);
        zat_b106_wounded_idle_animation_data.setPropertiesMoving(true);
        zat_b106_wounded_idle_animation_data.setPropertiesRandom(100);

        zat_b106_wounded_idle_animation_data.addAnimation("idle", 0, "cut_scene_0_actor_1");

        this->m_state_manager_animation_list["zat_b106_wounded_idle"] = zat_b106_wounded_idle_animation_data;

        StateManagerAnimationData zat_b38_cop_dead_animation_data;
        zat_b38_cop_dead_animation_data.setPropertiesMaxIdle(1);
        zat_b38_cop_dead_animation_data.setPropertiesSumIdle(1);
        zat_b38_cop_dead_animation_data.setPropertiesMoving(true);
        zat_b38_cop_dead_animation_data.setPropertiesRandom(100);

        zat_b38_cop_dead_animation_data.addAnimation("into", 0, "cut_scene_0_actor");
        //    zat_b38_cop_dead_animation_data.addAnimationFunction("into", 0, ); // Lord: доделать

        zat_b38_cop_dead_animation_data.addAnimation("idle", 0, "cut_scene_0_actor");

        this->m_state_manager_animation_list["zat_b38_cop_dead"] = zat_b38_cop_dead_animation_data;

        StateManagerAnimationData jup_b15_zulus_sit_drink_animation_data;
        jup_b15_zulus_sit_drink_animation_data.setPropertiesMaxIdle(1);
        jup_b15_zulus_sit_drink_animation_data.setPropertiesSumIdle(1);
        jup_b15_zulus_sit_drink_animation_data.setPropertiesMoving(true);
        jup_b15_zulus_sit_drink_animation_data.setPropertiesRandom(100);

        jup_b15_zulus_sit_drink_animation_data.addAnimation("into", 0, "jup_b15_zulus_sit_drink_in");
        jup_b15_zulus_sit_drink_animation_data.addAnimationAttachItemName("into", 0, "vodka");
        jup_b15_zulus_sit_drink_animation_data.addAnimation("into", 0, "jup_b15_zulus_sit_drink_idle");
        jup_b15_zulus_sit_drink_animation_data.addAnimationDettachItemName("into", 0, "vodka");
        jup_b15_zulus_sit_drink_animation_data.addAnimation("into", 0, "jup_b15_zulus_sit_drink_out");
        //  jup_b15_zulus_sit_drink_animation_data.addAnimationFunction(
        //  "into", 0, xr_effects.jup_b15_zulus_drink_anim_info); Lord: доделать

        jup_b15_zulus_sit_drink_animation_data.addAnimation("idle", 0, "jup_b15_zulus_sit_idle_short");

        this->m_state_manager_animation_list["jup_b15_zulus_sit_drink"] = jup_b15_zulus_sit_drink_animation_data;

        StateManagerAnimationData jup_b15_zulus_sit_idle_animation_data;
        jup_b15_zulus_sit_idle_animation_data.setPropertiesMaxIdle(1);
        jup_b15_zulus_sit_idle_animation_data.setPropertiesSumIdle(1);
        jup_b15_zulus_sit_idle_animation_data.setPropertiesMoving(true);
        jup_b15_zulus_sit_idle_animation_data.setPropertiesRandom(100);

        jup_b15_zulus_sit_idle_animation_data.addAnimation("idle", 0, "jup_b15_zulus_sit_idle");

        this->m_state_manager_animation_list["jup_b15_zulus_sit_idle"] = jup_b15_zulus_sit_idle_animation_data;

        StateManagerAnimationData jup_b15_zulus_sit_idle_short_animation_data;
        jup_b15_zulus_sit_idle_short_animation_data.setPropertiesMaxIdle(1);
        jup_b15_zulus_sit_idle_short_animation_data.setPropertiesSumIdle(1);
        jup_b15_zulus_sit_idle_short_animation_data.setPropertiesMoving(true);
        jup_b15_zulus_sit_idle_short_animation_data.setPropertiesRandom(100);

        jup_b15_zulus_sit_idle_short_animation_data.addAnimation("idle", 0, "jup_b15_zulus_sit_idle_short");

        this->m_state_manager_animation_list["jup_b15_zulus_sit_idle_short"] =
            jup_b15_zulus_sit_idle_short_animation_data;

        StateManagerAnimationData jup_b15_zulus_sit_out_animation_data;
        jup_b15_zulus_sit_out_animation_data.setPropertiesMaxIdle(1);
        jup_b15_zulus_sit_out_animation_data.setPropertiesSumIdle(1);
        jup_b15_zulus_sit_out_animation_data.setPropertiesMoving(true);
        jup_b15_zulus_sit_out_animation_data.setPropertiesRandom(100);

        jup_b15_zulus_sit_out_animation_data.addAnimation("idle", 0, "jup_b15_zulus_sit_out");

        this->m_state_manager_animation_list["jup_b15_zulus_sit_out"] = jup_b15_zulus_sit_out_animation_data;

        StateManagerAnimationData jup_b219_actor_one_animation_data;
        jup_b219_actor_one_animation_data.setPropertiesMaxIdle(1);
        jup_b219_actor_one_animation_data.setPropertiesSumIdle(1);
        jup_b219_actor_one_animation_data.setPropertiesMoving(true);
        jup_b219_actor_one_animation_data.setPropertiesRandom(100);

        jup_b219_actor_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_actor_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_actor_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_actor_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_actor_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_ready");
        jup_b219_actor_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        //   jup_b219_actor_one_animation_data.addAnimationFunction("into", 0, xr_effects.jup_b219_opening); Lord:
        //   доделать!
        jup_b219_actor_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_actor_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_go");
        jup_b219_actor_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        jup_b219_actor_one_animation_data.addAnimation("into", 1, "jup_b219_descent_actor_1");
        jup_b219_actor_one_animation_data.addAnimation("into", 1, "jup_b219_descent_actor_2");
        jup_b219_actor_one_animation_data.addAnimation("into", 1, "jup_b219_descent_actor_3");
        jup_b219_actor_one_animation_data.addAnimation("into", 1, "jup_b219_descent_actor_4");
        jup_b219_actor_one_animation_data.addAnimationSoundName("into", 1, "jup_b219_actor_ready");
        jup_b219_actor_one_animation_data.addAnimation("into", 1, "jup_b219_descent_actor_8");
        //   jup_b219_actor_one_animation_data.addAnimationFunction("into", 1, xr_effects.jup_b219_opening); Lord:
        //   доделать!
        jup_b219_actor_one_animation_data.addAnimation("into", 1, "jup_b219_descent_actor_9");
        jup_b219_actor_one_animation_data.addAnimationSoundName("into", 1, "jup_b219_actor_go");
        jup_b219_actor_one_animation_data.addAnimation("into", 1, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_actor_one"] = jup_b219_actor_one_animation_data;

        StateManagerAnimationData jup_b219_actor_one_vano_animation_data;
        jup_b219_actor_one_vano_animation_data.setPropertiesMaxIdle(1);
        jup_b219_actor_one_vano_animation_data.setPropertiesSumIdle(1);
        jup_b219_actor_one_vano_animation_data.setPropertiesMoving(true);
        jup_b219_actor_one_vano_animation_data.setPropertiesRandom(100);

        jup_b219_actor_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_actor_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_actor_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_actor_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_actor_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_5");
        jup_b219_actor_one_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_ready");
        jup_b219_actor_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        //   jup_b219_actor_one_vano_animation_data.addAnimationFunction("into", 0, xr_effects.jup_b219_opening); Lord:
        //   доделать!
        jup_b219_actor_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_actor_one_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_go");
        jup_b219_actor_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_actor_one_vano"] = jup_b219_actor_one_vano_animation_data;

        StateManagerAnimationData jup_b219_actor_one_monolith_animation_data;
        jup_b219_actor_one_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_actor_one_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_actor_one_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_actor_one_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_actor_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_actor_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_actor_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_actor_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_actor_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_6");
        jup_b219_actor_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_ready");
        jup_b219_actor_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        //   jup_b219_actor_one_monolith_animation_data.addAnimationFunction("into", 0, xr_effects.jup_b219_opening);
        //   Lord: доделать!
        jup_b219_actor_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_actor_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_go");
        jup_b219_actor_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_actor_one_monolith"] =
            jup_b219_actor_one_monolith_animation_data;

        StateManagerAnimationData jup_b219_actor_one_soldier_animation_data;
        jup_b219_actor_one_soldier_animation_data.setPropertiesMaxIdle(1);
        jup_b219_actor_one_soldier_animation_data.setPropertiesSumIdle(1);
        jup_b219_actor_one_soldier_animation_data.setPropertiesMoving(true);
        jup_b219_actor_one_soldier_animation_data.setPropertiesRandom(100);

        jup_b219_actor_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_actor_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_actor_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_actor_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_actor_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_7");
        jup_b219_actor_one_soldier_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_ready");
        jup_b219_actor_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        //   jup_b219_actor_one_soldier_animation_data.addAnimationFunction("into", 0, xr_effects.jup_b219_opening);
        //   Lord: доделать!
        jup_b219_actor_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_actor_one_soldier_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_go");
        jup_b219_actor_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_actor_one_soldier"] = jup_b219_actor_one_soldier_animation_data;

        StateManagerAnimationData jup_b219_actor_all_animation_data;
        jup_b219_actor_all_animation_data.setPropertiesMaxIdle(1);
        jup_b219_actor_all_animation_data.setPropertiesSumIdle(1);
        jup_b219_actor_all_animation_data.setPropertiesMoving(true);
        jup_b219_actor_all_animation_data.setPropertiesRandom(100);

        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_5");
        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_6");
        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_7");
        jup_b219_actor_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_ready");
        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        //   jup_b219_actor_all_animation_data.addAnimationFunction("into", 0, xr_effects.jup_b219_opening); Lord:
        //   доделать!
        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_actor_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_go");
        jup_b219_actor_all_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_actor_all"] = jup_b219_actor_all_animation_data;

        StateManagerAnimationData jup_b219_actor_soldier_vano_animation_data;
        jup_b219_actor_soldier_vano_animation_data.setPropertiesMaxIdle(1);
        jup_b219_actor_soldier_vano_animation_data.setPropertiesSumIdle(1);
        jup_b219_actor_soldier_vano_animation_data.setPropertiesMoving(true);
        jup_b219_actor_soldier_vano_animation_data.setPropertiesRandom(100);

        jup_b219_actor_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_actor_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_actor_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_actor_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_actor_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_5");
        jup_b219_actor_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_7");
        jup_b219_actor_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_ready");
        jup_b219_actor_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        //   jup_b219_actor_soldier_vano_animation_data.addAnimationFunction("into", 0, xr_effects.jup_b219_opening);
        //   Lord: доделать!
        jup_b219_actor_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_actor_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_go");
        jup_b219_actor_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_actor_soldier_vano"] =
            jup_b219_actor_soldier_vano_animation_data;

        StateManagerAnimationData jup_b219_actor_soldier_monolith_animation_data;
        jup_b219_actor_soldier_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_actor_soldier_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_actor_soldier_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_actor_soldier_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_actor_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_actor_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_actor_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_actor_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_actor_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_6");
        jup_b219_actor_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_7");
        jup_b219_actor_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_ready");
        jup_b219_actor_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        //   jup_b219_actor_soldier_monolith_animation_data.addAnimationFunction("into", 0,
        //   xr_effects.jup_b219_opening); Lord: доделать!
        jup_b219_actor_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_actor_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_go");
        jup_b219_actor_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_actor_soldier_monolith"] =
            jup_b219_actor_soldier_monolith_animation_data;

        StateManagerAnimationData jup_b219_actor_vano_monolith_animation_data;
        jup_b219_actor_vano_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_actor_vano_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_actor_vano_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_actor_vano_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_actor_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_actor_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_actor_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_actor_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_actor_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_5");
        jup_b219_actor_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_6");
        jup_b219_actor_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_ready");
        jup_b219_actor_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        //   jup_b219_actor_vano_monolith_animation_data.addAnimationFunction("into", 0,
        //   xr_effects.jup_b219_opening); Lord: доделать!
        jup_b219_actor_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_actor_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_actor_go");
        jup_b219_actor_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_actor_vano_monolith"] =
            jup_b219_actor_vano_monolith_animation_data;

        StateManagerAnimationData jup_b219_zulus_one_animation_data;
        jup_b219_zulus_one_animation_data.setPropertiesMaxIdle(1);
        jup_b219_zulus_one_animation_data.setPropertiesSumIdle(1);
        jup_b219_zulus_one_animation_data.setPropertiesMoving(true);
        jup_b219_zulus_one_animation_data.setPropertiesRandom(100);

        jup_b219_zulus_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_zulus_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_zulus_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_zulus_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_duty_ready");
        jup_b219_zulus_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_zulus_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        jup_b219_zulus_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_zulus_one_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_zulus_one"] = jup_b219_zulus_one_animation_data;

        StateManagerAnimationData jup_b219_zulus_one_vano_animation_data;
        jup_b219_zulus_one_vano_animation_data.setPropertiesMaxIdle(1);
        jup_b219_zulus_one_vano_animation_data.setPropertiesSumIdle(1);
        jup_b219_zulus_one_vano_animation_data.setPropertiesMoving(true);
        jup_b219_zulus_one_vano_animation_data.setPropertiesRandom(100);

        jup_b219_zulus_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_zulus_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_zulus_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_zulus_one_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_duty_ready");
        jup_b219_zulus_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_zulus_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_5");
        jup_b219_zulus_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        jup_b219_zulus_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_zulus_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_zulus_one_vano"] = jup_b219_zulus_one_vano_animation_data;

        StateManagerAnimationData jup_b219_zulus_one_monolith_animation_data;
        jup_b219_zulus_one_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_zulus_one_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_zulus_one_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_zulus_one_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_zulus_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_duty_ready");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_6");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_zulus_one_monolith"] =
            jup_b219_zulus_one_monolith_animation_data;

        StateManagerAnimationData jup_b219_zulus_one_soldier_animation_data;
        jup_b219_zulus_one_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_zulus_one_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_zulus_one_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_zulus_one_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_zulus_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_duty_ready");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_7");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_zulus_one_soldier"] = jup_b219_zulus_one_soldier_animation_data;

        StateManagerAnimationData jup_b219_zulus_all_animation_data;
        jup_b219_zulus_one_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_zulus_one_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_zulus_one_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_zulus_one_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_zulus_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_duty_ready");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_5");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_6");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_7");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_zulus_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_zulus_all"] = jup_b219_zulus_all_animation_data;

        StateManagerAnimationData jup_b219_zulus_soldier_vano_animation_data;
        jup_b219_zulus_soldier_vano_animation_data.setPropertiesMaxIdle(1);
        jup_b219_zulus_soldier_vano_animation_data.setPropertiesSumIdle(1);
        jup_b219_zulus_soldier_vano_animation_data.setPropertiesMoving(true);
        jup_b219_zulus_soldier_vano_animation_data.setPropertiesRandom(100);

        jup_b219_zulus_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_zulus_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_zulus_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_zulus_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_duty_ready");
        jup_b219_zulus_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_zulus_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_5");
        jup_b219_zulus_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_7");
        jup_b219_zulus_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        jup_b219_zulus_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_zulus_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_zulus_soldier_vano"] =
            jup_b219_zulus_soldier_vano_animation_data;

        StateManagerAnimationData jup_b219_zulus_soldier_monolith_animation_data;
        jup_b219_zulus_soldier_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_zulus_soldier_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_zulus_soldier_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_zulus_soldier_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_zulus_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_zulus_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_zulus_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_zulus_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_duty_ready");
        jup_b219_zulus_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_zulus_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_6");
        jup_b219_zulus_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_7");
        jup_b219_zulus_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        jup_b219_zulus_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_zulus_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_zulus_soldier_monolith"] =
            jup_b219_zulus_soldier_monolith_animation_data;

        StateManagerAnimationData jup_b219_zulus_vano_monolith_animation_data;
        jup_b219_zulus_vano_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_zulus_vano_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_zulus_vano_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_zulus_vano_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_zulus_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_1");
        jup_b219_zulus_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_2");
        jup_b219_zulus_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_3");
        jup_b219_zulus_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_duty_ready");
        jup_b219_zulus_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_4");
        jup_b219_zulus_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_5");
        jup_b219_zulus_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_6");
        jup_b219_zulus_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_8");
        jup_b219_zulus_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_9");
        jup_b219_zulus_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_actor_10");

        this->m_state_manager_animation_list["jup_b219_zulus_vano_monolith"] =
            jup_b219_zulus_vano_monolith_animation_data;

        StateManagerAnimationData jup_b219_soldier_one_animation_data;
        jup_b219_soldier_one_animation_data.setPropertiesMaxIdle(1);
        jup_b219_soldier_one_animation_data.setPropertiesSumIdle(1);
        jup_b219_soldier_one_animation_data.setPropertiesMoving(true);
        jup_b219_soldier_one_animation_data.setPropertiesRandom(100);

        jup_b219_soldier_one_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_1");
        jup_b219_soldier_one_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_2");
        jup_b219_soldier_one_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_3");
        jup_b219_soldier_one_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_4");
        jup_b219_soldier_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_soldier_ready");
        jup_b219_soldier_one_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_7");
        jup_b219_soldier_one_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_8");
        jup_b219_soldier_one_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_9");
        jup_b219_soldier_one_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_10");

        this->m_state_manager_animation_list["jup_b219_soldier_one"] = jup_b219_soldier_one_animation_data;

        StateManagerAnimationData jup_b219_soldier_all_animation_data;
        jup_b219_soldier_all_animation_data.setPropertiesMaxIdle(1);
        jup_b219_soldier_all_animation_data.setPropertiesSumIdle(1);
        jup_b219_soldier_all_animation_data.setPropertiesMoving(true);
        jup_b219_soldier_all_animation_data.setPropertiesRandom(100);

        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_1");
        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_2");
        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_3");
        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_4");
        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_5");
        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_6");
        jup_b219_soldier_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_soldier_ready");
        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_7");
        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_8");
        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_9");
        jup_b219_soldier_all_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_10");

        this->m_state_manager_animation_list["jup_b219_soldier_all"] = jup_b219_soldier_all_animation_data;

        StateManagerAnimationData jup_b219_soldier_soldier_vano_animation_data;
        jup_b219_soldier_soldier_vano_animation_data.setPropertiesMaxIdle(1);
        jup_b219_soldier_soldier_vano_animation_data.setPropertiesSumIdle(1);
        jup_b219_soldier_soldier_vano_animation_data.setPropertiesMoving(true);
        jup_b219_soldier_soldier_vano_animation_data.setPropertiesRandom(100);

        jup_b219_soldier_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_1");
        jup_b219_soldier_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_2");
        jup_b219_soldier_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_3");
        jup_b219_soldier_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_4");
        jup_b219_soldier_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_5");
        jup_b219_soldier_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_soldier_ready");
        jup_b219_soldier_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_7");
        jup_b219_soldier_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_8");
        jup_b219_soldier_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_9");
        jup_b219_soldier_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_10");

        this->m_state_manager_animation_list["jup_b219_soldier_soldier_vano"] =
            jup_b219_soldier_soldier_vano_animation_data;

        StateManagerAnimationData jup_b219_soldier_soldier_monolith_animation_data;
        jup_b219_soldier_soldier_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_soldier_soldier_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_soldier_soldier_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_soldier_soldier_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_soldier_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_1");
        jup_b219_soldier_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_2");
        jup_b219_soldier_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_3");
        jup_b219_soldier_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_4");
        jup_b219_soldier_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_5");
        jup_b219_soldier_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_soldier_ready");
        jup_b219_soldier_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_7");
        jup_b219_soldier_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_8");
        jup_b219_soldier_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_9");
        jup_b219_soldier_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_soldier_10");

        this->m_state_manager_animation_list["jup_b219_soldier_soldier_monolith"] =
            jup_b219_soldier_soldier_monolith_animation_data;

        StateManagerAnimationData jup_b219_monolith_one_animation_data;
        jup_b219_monolith_one_animation_data.setPropertiesMaxIdle(1);
        jup_b219_monolith_one_animation_data.setPropertiesSumIdle(1);
        jup_b219_monolith_one_animation_data.setPropertiesMoving(true);
        jup_b219_monolith_one_animation_data.setPropertiesRandom(100);

        jup_b219_monolith_one_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_1");
        jup_b219_monolith_one_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_2");
        jup_b219_monolith_one_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_3");
        jup_b219_monolith_one_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_4");
        jup_b219_monolith_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_monolith_ready");
        jup_b219_monolith_one_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_6");
        jup_b219_monolith_one_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_8");
        jup_b219_monolith_one_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_9");
        jup_b219_monolith_one_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_10");

        this->m_state_manager_animation_list["jup_b219_monolith_one"] = jup_b219_monolith_one_animation_data;

        StateManagerAnimationData jup_b219_monolith_all_animation_data;
        jup_b219_monolith_all_animation_data.setPropertiesMaxIdle(1);
        jup_b219_monolith_all_animation_data.setPropertiesSumIdle(1);
        jup_b219_monolith_all_animation_data.setPropertiesMoving(true);
        jup_b219_monolith_all_animation_data.setPropertiesRandom(100);

        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_1");
        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_2");
        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_3");
        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_4");
        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_5");
        jup_b219_monolith_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_monolith_ready");
        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_6");
        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_7");
        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_8");
        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_9");
        jup_b219_monolith_all_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_10");

        this->m_state_manager_animation_list["jup_b219_monolith_all"] = jup_b219_monolith_all_animation_data;

        StateManagerAnimationData jup_b219_monolith_soldier_monolith_animation_data;
        jup_b219_monolith_soldier_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_monolith_soldier_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_monolith_soldier_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_monolith_soldier_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_monolith_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_1");
        jup_b219_monolith_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_2");
        jup_b219_monolith_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_3");
        jup_b219_monolith_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_4");
        jup_b219_monolith_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_monolith_ready");
        jup_b219_monolith_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_6");
        jup_b219_monolith_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_7");
        jup_b219_monolith_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_8");
        jup_b219_monolith_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_9");
        jup_b219_monolith_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_10");

        this->m_state_manager_animation_list["jup_b219_monolith_soldier_monolith"] =
            jup_b219_monolith_soldier_monolith_animation_data;

        StateManagerAnimationData jup_b219_monolith_vano_monolith_animation_data;
        jup_b219_monolith_vano_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_monolith_vano_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_monolith_vano_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_monolith_vano_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_monolith_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_1");
        jup_b219_monolith_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_2");
        jup_b219_monolith_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_3");
        jup_b219_monolith_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_4");
        jup_b219_monolith_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_5");
        jup_b219_monolith_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_monolith_ready");
        jup_b219_monolith_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_6");
        jup_b219_monolith_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_8");
        jup_b219_monolith_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_9");
        jup_b219_monolith_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_monolit_10");

        this->m_state_manager_animation_list["jup_b219_monolith_vano_monolith"] =
            jup_b219_monolith_vano_monolith_animation_data;

        StateManagerAnimationData jup_b219_vano_one_animation_data;
        jup_b219_vano_one_animation_data.setPropertiesMaxIdle(1);
        jup_b219_vano_one_animation_data.setPropertiesSumIdle(1);
        jup_b219_vano_one_animation_data.setPropertiesMoving(true);
        jup_b219_vano_one_animation_data.setPropertiesRandom(100);

        jup_b219_vano_one_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_1");
        jup_b219_vano_one_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_2");
        jup_b219_vano_one_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_3");
        jup_b219_vano_one_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_4");
        jup_b219_vano_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_stalker_ready");
        jup_b219_vano_one_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_5");
        jup_b219_vano_one_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_8");
        jup_b219_vano_one_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_9");
        jup_b219_vano_one_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_10");

        this->m_state_manager_animation_list["jup_b219_vano_one"] = jup_b219_vano_one_animation_data;

        StateManagerAnimationData jup_b219_vano_all_animation_data;
        jup_b219_vano_all_animation_data.setPropertiesMaxIdle(1);
        jup_b219_vano_all_animation_data.setPropertiesSumIdle(1);
        jup_b219_vano_all_animation_data.setPropertiesMoving(true);
        jup_b219_vano_all_animation_data.setPropertiesRandom(100);

        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_1");
        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_2");
        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_3");
        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_4");
        jup_b219_vano_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_stalker_ready");
        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_5");
        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_6");
        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_7");
        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_8");
        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_9");
        jup_b219_vano_all_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_10");

        this->m_state_manager_animation_list["jup_b219_vano_all"] = jup_b219_vano_all_animation_data;

        StateManagerAnimationData jup_b219_vano_soldier_vano_animation_data;
        jup_b219_vano_soldier_vano_animation_data.setPropertiesMaxIdle(1);
        jup_b219_vano_soldier_vano_animation_data.setPropertiesSumIdle(1);
        jup_b219_vano_soldier_vano_animation_data.setPropertiesMoving(true);
        jup_b219_vano_soldier_vano_animation_data.setPropertiesRandom(100);

        jup_b219_vano_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_1");
        jup_b219_vano_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_2");
        jup_b219_vano_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_3");
        jup_b219_vano_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_4");
        jup_b219_vano_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_stalker_ready");
        jup_b219_vano_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_5");
        jup_b219_vano_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_7");
        jup_b219_vano_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_8");
        jup_b219_vano_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_9");
        jup_b219_vano_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_10");

        this->m_state_manager_animation_list["jup_b219_vano_soldier_vano"] = jup_b219_vano_soldier_vano_animation_data;

        StateManagerAnimationData jup_b219_vano_vano_monolith_animation_data;
        jup_b219_vano_vano_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_vano_vano_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_vano_vano_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_vano_vano_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_vano_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_1");
        jup_b219_vano_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_2");
        jup_b219_vano_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_3");
        jup_b219_vano_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_4");
        jup_b219_vano_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_stalker_ready");
        jup_b219_vano_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_5");
        jup_b219_vano_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_6");
        jup_b219_vano_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_8");
        jup_b219_vano_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_9");
        jup_b219_vano_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_stalker_10");

        this->m_state_manager_animation_list["jup_b219_vano_vano_monolith"] =
            jup_b219_vano_vano_monolith_animation_data;

        StateManagerAnimationData jup_b219_azot_one_animation_data;
        jup_b219_azot_one_animation_data.setPropertiesMaxIdle(1);
        jup_b219_azot_one_animation_data.setPropertiesSumIdle(1);
        jup_b219_azot_one_animation_data.setPropertiesMoving(true);
        jup_b219_azot_one_animation_data.setPropertiesRandom(100);

        jup_b219_azot_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_damn");
        jup_b219_azot_one_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1");
        jup_b219_azot_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_success");
        jup_b219_azot_one_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1_1");
        jup_b219_azot_one_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_2");
        jup_b219_azot_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_ready");
        jup_b219_azot_one_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_3");
        jup_b219_azot_one_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_4");
        jup_b219_azot_one_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_8");
        jup_b219_azot_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_opening");
        jup_b219_azot_one_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_9");
        jup_b219_azot_one_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_10");
        jup_b219_azot_one_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_to_duty");

        this->m_state_manager_animation_list["jup_b219_azot_one"] = jup_b219_azot_one_animation_data;

        StateManagerAnimationData jup_b219_azot_one_vano_animation_data;
        jup_b219_azot_one_vano_animation_data.setPropertiesMaxIdle(1);
        jup_b219_azot_one_vano_animation_data.setPropertiesSumIdle(1);
        jup_b219_azot_one_vano_animation_data.setPropertiesMoving(true);
        jup_b219_azot_one_vano_animation_data.setPropertiesRandom(100);

        jup_b219_azot_one_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_damn");
        jup_b219_azot_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1");
        jup_b219_azot_one_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_success");
        jup_b219_azot_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1_1");
        jup_b219_azot_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_2");
        jup_b219_azot_one_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_ready");
        jup_b219_azot_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_3");
        jup_b219_azot_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_4");
        jup_b219_azot_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_5");
        jup_b219_azot_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_8");
        jup_b219_azot_one_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_opening");
        jup_b219_azot_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_9");
        jup_b219_azot_one_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_10");
        jup_b219_azot_one_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_to_duty");

        this->m_state_manager_animation_list["jup_b219_azot_one_vano"] = jup_b219_azot_one_vano_animation_data;

        StateManagerAnimationData jup_b219_azot_one_monolith_animation_data;
        jup_b219_azot_one_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_azot_one_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_azot_one_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_azot_one_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_azot_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_damn");
        jup_b219_azot_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1");
        jup_b219_azot_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_success");
        jup_b219_azot_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1_1");
        jup_b219_azot_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_2");
        jup_b219_azot_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_ready");
        jup_b219_azot_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_3");
        jup_b219_azot_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_4");
        jup_b219_azot_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_6");
        jup_b219_azot_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_8");
        jup_b219_azot_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_opening");
        jup_b219_azot_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_9");
        jup_b219_azot_one_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_10");
        jup_b219_azot_one_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_to_duty");

        this->m_state_manager_animation_list["jup_b219_azot_one_monolith"] = jup_b219_azot_one_monolith_animation_data;

        StateManagerAnimationData jup_b219_azot_one_soldier_animation_data;
        jup_b219_azot_one_soldier_animation_data.setPropertiesMaxIdle(1);
        jup_b219_azot_one_soldier_animation_data.setPropertiesSumIdle(1);
        jup_b219_azot_one_soldier_animation_data.setPropertiesMoving(true);
        jup_b219_azot_one_soldier_animation_data.setPropertiesRandom(100);

        jup_b219_azot_one_soldier_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_damn");
        jup_b219_azot_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1");
        jup_b219_azot_one_soldier_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_success");
        jup_b219_azot_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1_1");
        jup_b219_azot_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_2");
        jup_b219_azot_one_soldier_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_ready");
        jup_b219_azot_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_3");
        jup_b219_azot_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_4");
        jup_b219_azot_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_7");
        jup_b219_azot_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_8");
        jup_b219_azot_one_soldier_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_opening");
        jup_b219_azot_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_9");
        jup_b219_azot_one_soldier_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_10");
        jup_b219_azot_one_soldier_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_to_duty");

        this->m_state_manager_animation_list["jup_b219_azot_one_soldier"] = jup_b219_azot_one_soldier_animation_data;

        StateManagerAnimationData jup_b219_azot_soldier_vano_animation_data;
        jup_b219_azot_soldier_vano_animation_data.setPropertiesMaxIdle(1);
        jup_b219_azot_soldier_vano_animation_data.setPropertiesSumIdle(1);
        jup_b219_azot_soldier_vano_animation_data.setPropertiesMoving(true);
        jup_b219_azot_soldier_vano_animation_data.setPropertiesRandom(100);

        jup_b219_azot_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_damn");
        jup_b219_azot_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1");
        jup_b219_azot_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_success");
        jup_b219_azot_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1_1");
        jup_b219_azot_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_2");
        jup_b219_azot_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_ready");
        jup_b219_azot_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_3");
        jup_b219_azot_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_4");
        jup_b219_azot_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_7");
        jup_b219_azot_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_8");
        jup_b219_azot_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_opening");
        jup_b219_azot_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_9");
        jup_b219_azot_soldier_vano_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_10");
        jup_b219_azot_soldier_vano_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_to_duty");

        this->m_state_manager_animation_list["jup_b219_azot_soldier_vano"] = jup_b219_azot_soldier_vano_animation_data;

        StateManagerAnimationData jup_b219_azot_soldier_monolith_animation_data;
        jup_b219_azot_soldier_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_azot_soldier_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_azot_soldier_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_azot_soldier_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_azot_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_damn");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1");
        jup_b219_azot_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_success");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1_1");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_2");
        jup_b219_azot_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_ready");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_3");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_4");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_5");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_7");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_8");
        jup_b219_azot_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_opening");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_9");
        jup_b219_azot_soldier_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_10");
        jup_b219_azot_soldier_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_to_duty");

        this->m_state_manager_animation_list["jup_b219_azot_soldier_monolith"] =
            jup_b219_azot_soldier_monolith_animation_data;

        StateManagerAnimationData jup_b219_azot_vano_monolith_animation_data;
        jup_b219_azot_vano_monolith_animation_data.setPropertiesMaxIdle(1);
        jup_b219_azot_vano_monolith_animation_data.setPropertiesSumIdle(1);
        jup_b219_azot_vano_monolith_animation_data.setPropertiesMoving(true);
        jup_b219_azot_vano_monolith_animation_data.setPropertiesRandom(100);

        jup_b219_azot_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_damn");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1");
        jup_b219_azot_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_success");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1_1");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_2");
        jup_b219_azot_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_ready");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_3");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_4");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_5");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_6");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_8");
        jup_b219_azot_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_opening");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_9");
        jup_b219_azot_vano_monolith_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_10");
        jup_b219_azot_vano_monolith_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_to_duty");

        this->m_state_manager_animation_list["jup_b219_azot_vano_monolith"] =
            jup_b219_azot_vano_monolith_animation_data;

        StateManagerAnimationData jup_b219_azot_all_animation_data;
        jup_b219_azot_all_animation_data.setPropertiesMaxIdle(1);
        jup_b219_azot_all_animation_data.setPropertiesSumIdle(1);
        jup_b219_azot_all_animation_data.setPropertiesMoving(true);
        jup_b219_azot_all_animation_data.setPropertiesRandom(100);

        jup_b219_azot_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_damn");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1");
        jup_b219_azot_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_success");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_1_1");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_2");
        jup_b219_azot_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_ready");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_3");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_4");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_5");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_6");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_7");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_8");
        jup_b219_azot_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_opening");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_9");
        jup_b219_azot_all_animation_data.addAnimation("into", 0, "jup_b219_descent_tech_10");
        jup_b219_azot_all_animation_data.addAnimationSoundName("into", 0, "jup_b219_tech_to_duty");

        this->m_state_manager_animation_list["jup_b219_azot_all"] = jup_b219_azot_all_animation_data;

        StateManagerAnimationData zat_b100_heli_2_serch_animation_data;
        zat_b100_heli_2_serch_animation_data.setPropertiesMaxIdle(1);
        zat_b100_heli_2_serch_animation_data.setPropertiesSumIdle(1);
        zat_b100_heli_2_serch_animation_data.setPropertiesRandom(100);

        zat_b100_heli_2_serch_animation_data.addAnimationAttachItemName("into", 0, "device_pda");
        zat_b100_heli_2_serch_animation_data.addAnimation("into", 0, "zat_b100_heli_2_serch");

        zat_b100_heli_2_serch_animation_data.addAnimation("idle", 0, "zat_b100_heli_2_serch");

        this->m_state_manager_animation_list["zat_b100_heli_2_serch"] = zat_b100_heli_2_serch_animation_data;

        StateManagerAnimationData zat_b101_heli_5_serch_animation_data;
        zat_b101_heli_5_serch_animation_data.setPropertiesMaxIdle(1);
        zat_b101_heli_5_serch_animation_data.setPropertiesSumIdle(1);
        zat_b101_heli_5_serch_animation_data.setPropertiesRandom(100);

        zat_b101_heli_5_serch_animation_data.addAnimationAttachItemName("into", 0, "device_pda");
        zat_b101_heli_5_serch_animation_data.addAnimation("into", 0, "zat_b101_heli_5_serch");

        zat_b101_heli_5_serch_animation_data.addAnimation("idle", 0, "zat_b101_heli_5_serch");

        this->m_state_manager_animation_list["zat_b101_heli_5_serch"] = zat_b101_heli_5_serch_animation_data;

        StateManagerAnimationData zat_b28_heli3_serch_animation_data;
        zat_b28_heli3_serch_animation_data.setPropertiesMaxIdle(1);
        zat_b28_heli3_serch_animation_data.setPropertiesSumIdle(1);
        zat_b28_heli3_serch_animation_data.setPropertiesRandom(100);

        zat_b28_heli3_serch_animation_data.addAnimationAttachItemName("into", 0, "device_pda");
        zat_b28_heli3_serch_animation_data.addAnimation("into", 0, "zat_b28_heli3_serch");

        zat_b28_heli3_serch_animation_data.addAnimation("idle", 0, "zat_b28_heli3_serch");

        this->m_state_manager_animation_list["zat_b28_heli3_serch"] = zat_b28_heli3_serch_animation_data;

        StateManagerAnimationData jup_b217_guide_stand_animation_data;
        jup_b217_guide_stand_animation_data.setPropertiesMaxIdle(1);
        jup_b217_guide_stand_animation_data.setPropertiesSumIdle(1);
        jup_b217_guide_stand_animation_data.setPropertiesMoving(true);
        jup_b217_guide_stand_animation_data.setPropertiesRandom(100);

        jup_b217_guide_stand_animation_data.addAnimation("into", 0, "jup_b217_guide_stand");

        this->m_state_manager_animation_list["jup_b217_guide_stand"] = jup_b217_guide_stand_animation_data;

        StateManagerAnimationData jup_b217_nitro_stand_animation_data;
        jup_b217_nitro_stand_animation_data.setPropertiesMaxIdle(1);
        jup_b217_nitro_stand_animation_data.setPropertiesSumIdle(1);
        jup_b217_nitro_stand_animation_data.setPropertiesMoving(true);
        jup_b217_nitro_stand_animation_data.setPropertiesRandom(100);

        jup_b217_nitro_stand_animation_data.addAnimation("into", 0, "jup_b217_nitro_stand");

        this->m_state_manager_animation_list["jup_b217_nitro_stand"] = jup_b217_nitro_stand_animation_data;

        StateManagerAnimationData jup_b41_novikov_stand_animation_data;
        jup_b41_novikov_stand_animation_data.setPropertiesMaxIdle(10);
        jup_b41_novikov_stand_animation_data.setPropertiesSumIdle(8);
        jup_b41_novikov_stand_animation_data.setPropertiesMoving(true);
        jup_b41_novikov_stand_animation_data.setPropertiesRandom(80);

        jup_b41_novikov_stand_animation_data.addAnimation("into", 0, "lead_1_in_0");
        jup_b41_novikov_stand_animation_data.addAnimation("out", 0, "lead_1_out_0");
        jup_b41_novikov_stand_animation_data.addAnimation("idle", 0, "lead_1_idle");
        jup_b41_novikov_stand_animation_data.addAnimation("rnd", 0, "lead_1_idle_0");
        jup_b41_novikov_stand_animation_data.addAnimation("rnd", 0, "lead_1_idle_1");
        jup_b41_novikov_stand_animation_data.addAnimation("rnd", 0, "lead_1_idle_2");
        jup_b41_novikov_stand_animation_data.addAnimation("rnd", 0, "lead_1_idle_3");
        jup_b41_novikov_stand_animation_data.addAnimation("rnd", 0, "lead_1_idle_4");
        jup_b41_novikov_stand_animation_data.addAnimation("rnd", 0, "lead_1_idle_5");

        this->m_state_manager_animation_list["jup_b41_novikov_stand"] = jup_b41_novikov_stand_animation_data;

        StateManagerAnimationData pri_b305_actor_animation_data;
        pri_b305_actor_animation_data.setPropertiesMaxIdle(1);
        pri_b305_actor_animation_data.setPropertiesSumIdle(1);
        pri_b305_actor_animation_data.setPropertiesMoving(true);
        pri_b305_actor_animation_data.setPropertiesRandom(100);

        pri_b305_actor_animation_data.addAnimation("into", 0, "pri_b305_actor");

        this->m_state_manager_animation_list["pri_b305_actor"] = pri_b305_actor_animation_data;

        StateManagerAnimationData jup_a9_cam1_actor_animation_data;
        jup_a9_cam1_actor_animation_data.setPropertiesMaxIdle(1);
        jup_a9_cam1_actor_animation_data.setPropertiesSumIdle(1);
        jup_a9_cam1_actor_animation_data.setPropertiesRandom(100);

        jup_a9_cam1_actor_animation_data.addAnimation("into", 0, "poisk_8_idle_2");
        //    jup_a9_cam1_actor_animation_data.addAnimationFunction("into", 0, xr_effects.jup_a9_cam1_actor_anim_end);
        //    Lord: доделать!

        this->m_state_manager_animation_list["jup_a9_cam1_actor"] = jup_a9_cam1_actor_animation_data;

        StateManagerAnimationData jup_a9_cam2_actor_animation_data;
        jup_a9_cam2_actor_animation_data.setPropertiesMaxIdle(1);
        jup_a9_cam2_actor_animation_data.setPropertiesSumIdle(1);
        jup_a9_cam2_actor_animation_data.setPropertiesRandom(100);

        jup_a9_cam2_actor_animation_data.addAnimation("into", 0, "poisk_2_idle_1");

        this->m_state_manager_animationstate_list["jup_a9_cam2_actor"] = jup_a9_cam2_actor_animation_data;

        StateManagerAnimationData jup_a9_cam3_actor_animation_data;
        jup_a9_cam3_actor_animation_data.setPropertiesMaxIdle(1);
        jup_a9_cam3_actor_animation_data.setPropertiesSumIdle(1);
        jup_a9_cam3_actor_animation_data.setPropertiesRandom(100);

        jup_a9_cam3_actor_animation_data.addAnimation("into", 0, "poisk_2_idle_1");

        this->m_state_manager_animation_list["jup_a9_cam3_actor"] = jup_a9_cam3_actor_animation_data;

        StateManagerAnimationData jup_b217_nitro_straight_animation_data;
        jup_b217_nitro_straight_animation_data.setPropertiesMaxIdle(1);
        jup_b217_nitro_straight_animation_data.setPropertiesSumIdle(1);
        jup_b217_nitro_straight_animation_data.setPropertiesRandom(100);

        jup_b217_nitro_straight_animation_data.addAnimation("idle", 0, "idle_0_idle_1");

        this->m_state_manager_animation_list["jup_b217_nitro_straight"] = jup_b217_nitro_straight_animation_data;

        StateManagerAnimationData pri_a25_psy_medic_idle_animation_data;
        pri_a25_psy_medic_idle_animation_data.setPropertiesMaxIdle(1);
        pri_a25_psy_medic_idle_animation_data.setPropertiesSumIdle(1);
        pri_a25_psy_medic_idle_animation_data.setPropertiesRandom(100);

        pri_a25_psy_medic_idle_animation_data.addAnimation("idle", 0, "psy_0_idle_0");
        this->m_state_manager_animation_list["pri_a25_psy_medic_idle"] = pri_a25_psy_medic_idle_animation_data;

        StateManagerAnimationData pri_a25_psy_medic_out_animation_data;
        pri_a25_psy_medic_out_animation_data.setPropertiesMaxIdle(1);
        pri_a25_psy_medic_out_animation_data.setPropertiesSumIdle(1);
        pri_a25_psy_medic_out_animation_data.setPropertiesRandom(100);

        pri_a25_psy_medic_out_animation_data.addAnimation("into", 0, "psy_0_idle_0_to_idle_0");
        this->m_state_manager_animation_list["pri_a25_psy_medic_out"] = pri_a25_psy_medic_out_animation_data;
#pragma endregion
    }

public:
    inline static Script_GlobalHelper& getInstance(void) noexcept
    {
        static Script_GlobalHelper instance;
        return instance;
    }

    ~Script_GlobalHelper(void)
    {
        if (this->m_tutorial)
        {
            Msg("[Scripts/Script_GlobalHelper/dtor()] Deleting GlobalTutorial!");
            delete this->m_tutorial;
            this->m_tutorial = nullptr;
        }
    }
    Script_GlobalHelper(const Script_GlobalHelper&) = delete;
    Script_GlobalHelper& operator=(const Script_GlobalHelper&) = delete;
    Script_GlobalHelper(Script_GlobalHelper&&) = delete;
    Script_GlobalHelper& operator=(Script_GlobalHelper&&) = delete;

    inline void InitializeAlifeSimulator(void) {}
    inline void RegisterFunctionsFromAnotherFiles(void)
    {
        // @ Lord: реализовать
#pragma region XR_CONDITION

#pragma endregion

#pragma region XR_EFFECTS

#pragma endregion
    }

    inline const xr_map<int, bool>& getMonsterClasses(void) const noexcept { return this->m_monster_classes; }

    inline void setMonsterClasses(const xr_map<int, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setMonsterClasses(map)] WARNING: map.size() = 0! You are "
                "trying to set an empty "
                "map!");
            //   return;
        }

        this->m_monster_classes = map;
    }

    inline void setMonsterClasses(const std::pair<int, bool>& pair) noexcept
    {
        if (pair.first == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setMonsterClasses(pair)] WARNING: pair.first = "
                "std::uint32_t(-1)! Your value is "
                "undefined!");
            //     return;
        }

        this->m_monster_classes.insert(pair);
    }

    inline void setMonsterClasses(const int monster_id, const bool& value) noexcept
    {
        if (monster_id == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setMonsterClasses(monster_id, value)] WARNING: "
                "monster_id = std::uint32_t(-1)! "
                "Your value is undefined!");
            //     return;
        }

        this->m_monster_classes[monster_id] = value;
    }

    inline const xr_map<int, bool>& getStalkerClasses(void) const noexcept { return this->m_stalker_classes; }

    inline void setStalkerClasses(const xr_map<int, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setStalkerClasses(map)] WARNING: map.size() = 0! You are "
                "trying to set an empty "
                "map!");
            //   return;
        }

        this->m_stalker_classes = map;
    }

    inline void setStalkerClasses(const std::pair<int, bool>& pair) noexcept
    {
        if (pair.first == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setStalkerClasses(pair)] WARNING: pair.first = "
                "std::uint32_t(-1)! Your value is "
                "undefined!");
            //  return;
        }

        this->m_stalker_classes.insert(pair);
    }

    inline void setStalkerClasses(const int stalker_id, const bool& value) noexcept
    {
        if (stalker_id == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setStalkerClasses(stalker_id, value)] WARNING: "
                "stalker_id = std::uint32_t(-1)! "
                "Your value is undefined!");
            //    return;
        }

        this->m_stalker_classes[stalker_id] = value;
    }

    inline const xr_map<int, bool>& getWeaponClasses(void) const noexcept { return this->m_weapon_classes; }

    inline void setWeaponClasses(const xr_map<int, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setWeaponClasses(map)] WARNING: map.size() = 0! You are "
                "trying to set an empty "
                "map!");
            //   return;
        }

        this->m_weapon_classes = map;
    }

    inline void setWeaponClasses(const std::pair<int, bool>& pair) noexcept
    {
        if (pair.first == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setWeaponClasses(pair)] WARNING: pair.first = "
                "std::uint32_t(-1)! You value is "
                "undefined!");
            // return;
        }

        this->m_weapon_classes.insert(pair);
    }

    inline void setWeaponClasses(const int weapon_id, const bool& value) noexcept
    {
        if (weapon_id == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setWeaponClasses(weapon_id, value)] WARNING: weapon_id = "
                "std::uint32_t(-1)! Your "
                "value is undefined!");
            //    return;
        }

        this->m_weapon_classes[weapon_id] = value;
    }

    inline const xr_map<int, bool>& getArtefactClasses(void) const noexcept { return this->m_artefact_classes; }

    inline void setArtefactClasses(const xr_map<int, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setArtefactClasses(map)] WARNING: map.size() = 0! You "
                "are trying to set an empty "
                "map!");
            //   return;
        }

        this->m_artefact_classes = map;
    }

    inline void setArtefactClasses(const std::pair<int, bool>& pair) noexcept
    {
        if (pair.first == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setArtefactClasses(pair)] WARNING: pair.first == "
                "std::uint32_t(-1)! You are "
                "trying to set an undefined value!");
            //  return;
        }

        this->m_artefact_classes.insert(pair);
    }

    inline void setArtefactClasses(const int artefact_id, const bool& value) noexcept
    {
        if (artefact_id == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setArtefactClasses(artefact_id, value)] WARNING: "
                "artefact_id = "
                "std::uint32_t(-1)! Your value is undefined!");
            //    return;
        }

        this->m_artefact_classes[artefact_id] = value;
    }

    inline const xr_map<std::uint32_t, bool>& getAmmoSection(void) const noexcept { return this->m_ammo_section; }

    inline void setAmmoSection(const xr_map<std::uint32_t, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setAmmoSection(map)] WARNING: map.size() = 0! You are "
                "trying to set an empty "
                "map!");
            //   return;
        }

        this->m_ammo_section = map;
    }

    inline void setAmmoSection(const std::pair<std::uint32_t, bool>& pair) noexcept
    {
        if (pair.first == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setAmmoSection(pair)] WARNING: pair.first = "
                "std::uint32_t(-1)! "
                "Your value is undefined!!!");
            //  return;
        }

        this->m_ammo_section.insert(pair);
    }

    inline void setAmmoSection(const std::uint32_t& ammo_section, const bool& value) noexcept
    {
        if (ammo_section == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setAmmoSection(ammo_section, value)] WARNING: "
                "ammo_section = std::uint32_t(-1)! "
                "Your value is undefined!!!");
            //  return;
        }

        this->m_ammo_section[ammo_section] = value;
    }

    inline const xr_map<xr_string, bool>& getQuestSection(void) const noexcept { return this->m_quest_section; }

    inline void setQuestSection(const xr_map<xr_string, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setQuestSection(map)] WARNING: map.size() = 0! You are "
                "trying to set an empty "
                "map!");
            // return;
        }

        this->m_quest_section = map;
    }

    inline void setQuestSection(const std::pair<xr_string, bool>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setQuestSection] WARNING: pair.first.size() = 0! You are "
                "trying to set an "
                "empty pair!");
            //   return;
        }

        this->m_quest_section.insert(pair);
    }

    inline void setQuestSection(const xr_string& section_name, const bool& value) noexcept
    {
        if (!section_name.size())
        {
            Msg("[Script_GlobalHelper/setQuestSection] WARNING: section_name.size() = 0! You "
                "are trying to set an "
                "empty string!");
            //    return;
        }

        this->m_quest_section[section_name] = value;
    }

    inline const xr_map<xr_string, xr_string>& getSquadCommunityByBehavior(void) const noexcept
    {
        return this->m_squad_community_by_behavior;
    }

    inline void setSquadCommunityByBehavior(const xr_map<xr_string, xr_string>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setSquadCommunityByBehavior(map)] WARNING: map.size() = "
                "0! You are trying to set "
                "an empty map!");
            //  return;
        }

        this->m_squad_community_by_behavior = map;
    }

    inline void setSquadCommunityByBehavior(const std::pair<xr_string, xr_string>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setSquadCommunityByBehavior(pair)] WARNING: "
                "pair.first.size() = 0! You are trying to set an empty pair!");
            //  return;
        }

        this->m_squad_community_by_behavior.insert(pair);
    }

    inline void setSquadCommunityByBehavior(const xr_string& community_name, const xr_string& behavior_name) noexcept
    {
        if (!community_name.size())
        {
            Msg("[Script_GlobalHelper/setSquadCommunityByBehavior(community_name, "
                "behavior_name)] WARNING: "
                "community_name.size() = 0! You are trying to set an empty string!");
            // return;
        }

        this->m_squad_community_by_behavior[community_name] = behavior_name;
    }

    inline xr_map<xr_string, AnyCallable<void>>& getRegisteredFunctionsXREffects(void) noexcept
    {
        return this->m_registered_functions_xr_effects;
    }

    inline void setRegisteredFunctionsXREffects(const xr_map<xr_string, AnyCallable<void>>& map)
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredFunctionsXREffects(map)] WARNING: "
                "map.size() = 0! You are trying to "
                "set an empty map!");
            //   return;
        }

        this->m_registered_functions_xr_effects = map;
    }

    inline void setRegisteredFunctionsXREffects(const std::pair<xr_string, AnyCallable<void>>& pair)
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredFunctionsXREffects(pair)] WARNING: "
                "pair.first.size() = 0! You are trying to set an empty pair!");
            // return;
        }

        this->m_registered_functions_xr_effects.insert(pair);
    }

    inline void setRegisteredFunctionsXREffects(const xr_string& function_name, const AnyCallable<void>& function)
    {
        if (!function_name.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredFunctionsXREffects(function_name, "
                "function)] WARNING: "
                "function_name.size() = 0! You are trying to set an empty string!");
            // return;
        }

        this->m_registered_functions_xr_effects[function_name] = function;
    }

    inline xr_map<xr_string, AnyCallable<bool>>& getRegisteredFunctionsXRCondition(void) noexcept
    {
        return this->m_registered_functions_xr_conditions;
    }

    inline void setRegisteredFunctionsXRCondition(const xr_map<xr_string, AnyCallable<bool>>& map)
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredFunctionsXRCondition(map)] WARNING: "
                "map.size() = 0! You are trying "
                "to set an empty map!");
            //  return;
        }

        this->m_registered_functions_xr_conditions = map;
    }

    inline void setRegisteredFunctionsXRCondition(const std::pair<xr_string, AnyCallable<bool>>& pair)
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredFunctionsXRCondition(pair)] WARNING: "
                "pair.first.size() = 0! You are trying to set an empty pair!");
            //  return;
        }

        this->m_registered_functions_xr_conditions.insert(pair);
    }

    inline void setRegisteredFunctionsXRCondition(const xr_string& function_name, const AnyCallable<bool>& function)
    {
        if (!function_name.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredFunctionsXRCondition(function_name, "
                "function)] WARNING: "
                "function_name.size() = 0! You are trying to set an empty string!");
            //    return;
        }

        this->m_registered_functions_xr_conditions[function_name] = function;
    }

    // @ It uses in Level Editor as list of smartcovers as spawnelement and it's using in-game
    inline const xr_map<xr_string, SmartCoverData>& getRegisteredSmartCovers(void) const noexcept
    {
        return this->m_registered_smartcovers;
    }

    inline void setRegisteredSmartCovers(const xr_map<xr_string, SmartCoverData>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartCovers(map)] WARNING: map.size() = 0! "
                "You are trying to set an "
                "empty map!");
            //     return;
        }

        this->m_registered_smartcovers = map;
    }

    inline void setRegisteredSmartCovers(const std::pair<xr_string, SmartCoverData>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartCovers(smart_name, data)] WARNING: "
                "pair.first.size() = 0! You "
                "are trying to set an empty string,");
            //   return;
        }

        this->m_registered_smartcovers.insert(pair);
    }

    inline void setRegisteredSmartCovers(const xr_string& smart_name, const SmartCoverData& data) noexcept
    {
        if (!smart_name.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartCovers(smart_name, data)] WARNING: "
                "smart_name.size() = 0! You "
                "are trying to set an empty string.");
            //   return;
        }

        this->m_registered_smartcovers[smart_name] = data;
    }

    inline const xr_map<xr_string, xr_string>& getJobTypesByScheme(void) const noexcept
    {
        return this->m_job_type_by_scheme;
    }

    inline void setJobTypesByScheme(const xr_map<xr_string, xr_string>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setJobTypesByScheme(map)] WARNING: map.size() = 0! You "
                "are trying to set an "
                "empty map!");
            //   return;
        }

        this->m_job_type_by_scheme = map;
    }

    inline void setJobTypesByScheme(const std::pair<xr_string, xr_string>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setJobTypesByScheme(type_name, scheme_name)] WARNING: "
                "pair.first.size() = 0! You "
                "are trying to set an empty string");
            // return;
        }

        this->m_job_type_by_scheme.insert(pair);
    }

    inline void setJobTypesByScheme(const xr_string& type_name, const xr_string& scheme_name) noexcept
    {
        if (!type_name.size())
        {
            Msg("[Script_GlobalHelper/setJobTypesByScheme(type_name, scheme_name)] WARNING: "
                "type_name.size() = 0! You "
                "are trying to set an empty string,");
            //   return;
        }

        this->m_job_type_by_scheme[type_name] = scheme_name;
    }

#pragma region Cordis InGame
    // @ First - id | Second - distance
    inline const std::pair<std::uint32_t, std::uint32_t>& getGameNearestToActorServerSmartTerrain(void) const noexcept
    {
        return this->m_game_server_nearest_to_actor_smart_terrain;
    }

    inline void setGameNearestToActorServerSmartTerrain(const std::pair<std::uint32_t, std::uint32_t>& pair) noexcept
    {
        if (pair.first == Globals::kUnsignedInt32Undefined || pair.second == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setGameNearestToActorServerSmartTerrain(id, distance)] "
                "WARNING: pair.first || "
                "pair.second = "
                "std::uint32_t(-1)!!! Values id or distance are not initialized at all or "
                "equals minus one!");
        }

        this->m_game_server_nearest_to_actor_smart_terrain = pair;
    }

    inline void setGameNearestToActorServerSmartTerrain(const std::uint32_t& id, const std::uint32_t& distance) noexcept
    {
        if (id == Globals::kUnsignedInt32Undefined || distance == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Script_GlobalHelper/setGameNearestToActorServerSmartTerrain(id, distance)] "
                "WARNING: id || distance = "
                "std::uint32_t(-1)!!! Values id or distance are undefined at all or equals "
                "minus one!");
        }

        this->m_game_server_nearest_to_actor_smart_terrain.first = id;
        this->m_game_server_nearest_to_actor_smart_terrain.second = distance;
    }

    inline const xr_map<xr_string, xr_string>& getGameSmartsByAssaultZones(void) const noexcept
    {
        return this->m_game_smarts_by_no_assault_zone;
    }

    inline void setGameSmartsByAssaultZones(const xr_map<xr_string, xr_string>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setGameSmartsByAssaultZones(map)] WARNING: map.size() = "
                "0! You are trying to set "
                "an empty map!");
            //  return;
        }

        this->m_game_smarts_by_no_assault_zone = map;
    }

    inline void setGameSmartsByAssaultZones(const std::pair<xr_string, xr_string>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setGameSmartsByAssaultZones(pair)] WARNING: "
                "pair.first.size() = 0! You are "
                "trying to set an empty string!");
            //  return;
        }

        this->m_game_smarts_by_no_assault_zone.insert(pair);
    }

    inline void setGameSmartsByAssaultZones(const xr_string& smart_name, const xr_string& zone_name) noexcept
    {
        if (!smart_name.size())
        {
            Msg("[Script_GlobalHelper/setGameSmartsByAssaultZones(smart_name, zone_name)] "
                "WARNING: smart_name.size() = "
                "0! You are trying to set an empty string!");
            //    return;
        }

        this->m_game_smarts_by_no_assault_zone[smart_name] = zone_name;
    }
#pragma endregion

#pragma region Cordis System variables
    inline CUISequencer* getGlobalTutorial(void) const { return this->m_tutorial; }
    inline void setGlobalTutorial(CUISequencer* sequence)
    {
        if (!sequence)
        {
            Msg("[Scripts/Script_GlobalHelper/setGlobalTutorial(sequence)] WARNING: sequence = "
                "nullptr!");
            //  return;
        }

        this->m_tutorial = sequence;
    }

    inline const xr_map<xr_string, bool>& getRegisteredSmartTerrainTerritoryType(void) const noexcept
    {
        return this->m_registered_smart_terrain_territory_type;
    }

    inline void setRegisteredSmartTerrainTerritoryType(const xr_map<xr_string, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartTerrainTerritoryType(map)] WARNING: "
                "map.size() = 0! You are "
                "trying to set an empty map!");
            //  return;
        }

        this->m_registered_smart_terrain_territory_type = map;
    }

    inline void setRegisteredSmartTerrainTerritoryType(const std::pair<xr_string, bool>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartTerrainTerritoryType(pair)] WARNING: "
                "pair.first.size() = 0! "
                "You are trying to set an empty pair!");
            //   return;
        }

        this->m_registered_smart_terrain_territory_type.insert(pair);
    }

    inline void setRegisteredSmartTerrainTerritoryType(const xr_string& name, const bool& value) noexcept
    {
        if (!name.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartTerrainTerritoryType(name, value)] "
                "WARNING: name.size() = 0! "
                "You are trying to set an empty string!");
            //    return;
        }

        this->m_registered_smart_terrain_territory_type[name] = value;
    }

    inline const xr_vector<xr_string>& getRegisteredSmartTerrainPathFileds(void) const noexcept
    {
        return this->m_registered_smart_terrain_path_fields;
    }

    inline void setRegisteredSmartTerrainPathFields(const xr_vector<xr_string>& vector) noexcept
    {
        if (!vector.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartTerrainPathFields(vector)] WARNING: "
                "vector.size() = 0! You are "
                "trying to set an empty vector!");
            //    return;
        }

        this->m_registered_smart_terrain_path_fields = vector;
    }

    inline void setRegisteredSmartTerrainPathFields(const xr_string& name) noexcept
    {
        if (!name.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartTerrainFields(name)] WARNING: "
                "name.size() = 0! You are trying "
                "to set an empty string!");
            //   return;
        }

        this->m_registered_smart_terrain_path_fields.push_back(name);
    }

    inline const xr_map<xr_string, std::uint32_t>& getSimulationBoardGroupIDLevelsByName(void) const noexcept
    {
        return this->m_simulationboard_group_id_by_levels_name;
    }

    inline void setSimulationBoardGroupIDLevelsByName(const xr_map<xr_string, std::uint32_t>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setSimulationBoardGroupIDLevelsByName(map)] WARNING: "
                "map.size() = 0! You are "
                "trying to set an empty map!");
            //   return;
        }

        this->m_simulationboard_group_id_by_levels_name = map;
    }

    inline void setSimulationBoardGroupIDLevelsByName(const std::pair<xr_string, std::uint32_t>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setSimulationBoardGroupIDLevelsByName(pair)] WARNING: "
                "pair.first.size() = 0! you "
                "are trying to set an empty string!");
            //   return;
        }

        this->m_simulationboard_group_id_by_levels_name.insert(pair);
    }

    inline void setSimulationBoardGroupIDLevelsByName(const xr_string& name, const std::uint32_t& id) noexcept
    {
        if (!name.size())
        {
            Msg("[Script_GlobalHelper/setSimulationBoardGropIDLevelsByName(name, id)] WARNING: "
                "name.size() = 0! you "
                "are trying to set an empty string!");
            //    return;
        }

        this->m_simulationboard_group_id_by_levels_name[name] = id;
    }

    inline const xr_map<xr_string, bool>& getSimulationSquadIsSquadMonster(void) const noexcept
    {
        return this->m_simulationsquad_is_squad_monster_by_type;
    }

    inline void setSimulationSquadIsSquadMonster(const xr_map<xr_string, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setSimulationSquadIsSquadMonster(map)] map.size() = 0! "
                "you are trying to set an "
                "empty map!");
            // return;
        }

        this->m_simulationsquad_is_squad_monster_by_type = map;
    }

    inline void setSimulationSquadIsSquadMonster(const std::pair<xr_string, bool>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setSimulationSquadIsSquadMonster(pair)] WARNING: "
                "pair.first.size() = 0! you are "
                "trying to set an empty string");
            //  return;
        }

        this->m_simulationsquad_is_squad_monster_by_type.insert(pair);
    }

    inline void setSimulationSquadIsSquadMonster(const xr_string& name, const bool& value) noexcept
    {
        if (!name.size())
        {
            Msg("[Script_GlobalHelper/setSimulationSquadIsSquadMonster(name, value)] WARNING: "
                "name.size() = 0! you are "
                "trying to set an empty value");
            // return;
        }

        this->m_simulationsquad_is_squad_monster_by_type[name] = value;
    }

    inline const xr_map<xr_string, Script_SmartTerrainControl_States>& getRegisteredSmartTerrainControlScriptStates(
        void) const noexcept
    {
        return this->m_registered_smart_terrain_control_script_states;
    }

    inline void setRegisteredSmartTerrainControlScriptStates(
        const xr_map<xr_string, Script_SmartTerrainControl_States>& map)
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartTerrainControlScriptStates(map)] "
                "WARNING: map.size() = 0! you "
                "are trying to set an empty map!");
            //   return;
        }

        this->m_registered_smart_terrain_control_script_states = map;
    }

    inline void setRegisteredSmartTerrainControlScriptStates(
        const std::pair<xr_string, Script_SmartTerrainControl_States>& pair)
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartTerrainControlScriptStates(pair)] "
                "WARNING: pair.first is empty "
                "string! You are trying to set an empty string,");
            //   return;
        }

        this->m_registered_smart_terrain_control_script_states.insert(pair);
    }

    inline void setRegisteredSmartTerrainControlScriptStates(
        const xr_string& name, const Script_SmartTerrainControl_States& state) noexcept
    {
        if (!name.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredSmartTerrainControlScriptStates(name, "
                "state)] WARNING: you are "
                "trying to set an empty string");
            //    return;
        }

        this->m_registered_smart_terrain_control_script_states[name] = state;
    }

    inline const xr_map<xr_string, bool>& getRegisteredEatableVisuals(void) const noexcept
    {
        return this->m_registered_eatable_visuals;
    }

    inline void setRegisteredEatableVisuals(const xr_map<xr_string, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredEatableVisuals(map)] WARNING: you're set an "
                "empty map!");
            //  return;
        }

        this->m_registered_eatable_visuals = map;
    }

    inline void setRegisteredEatableVisuals(const std::pair<xr_string, bool>& pair)
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredEatableVisuals(pair)] WARNING: you're "
                "trying to set an empty pair "
                "to map!");
            //    return;
        }

        this->m_registered_eatable_visuals.insert(pair);
    }

    inline void setRegisteredEatableVisuals(const xr_string& name, const bool& is_used) noexcept
    {
        if (!name.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredEatableVisuals(name, is_used)] WARNING: "
                "name.size() = 0! (string is "
                "null!)");
            //   return;
        }

        this->m_registered_eatable_visuals[name] = is_used;
    }

    inline const xr_map<xr_string, bool>& getRegisteredHarmonicaVisuals(void) const noexcept
    {
        return this->m_registered_harmonica_visuals;
    }

    inline void setRegisteredHarmonicaVisuals(const xr_map<xr_string, bool>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredHarmonicaVisuals(map)] WARNING: map.size() "
                "= 0! You are trying to "
                "set an empty map! No assignment!");
            return;
        }

        this->m_registered_harmonica_visuals = map;
    }

    inline void setRegisteredHarmonicaVisuals(const std::pair<xr_string, bool>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredHarmonicaVisuals(pair)] WARNING: "
                "pair.first.size() = 0! You are "
                "trying to set an empty pair!");
            //  return;
        }

        this->m_registered_harmonica_visuals.insert(pair);
    }

    inline void setRegisteredHarmonicaVisuals(const xr_string& visual_name, const bool& is_used) noexcept
    {
        if (!visual_name.size())
        {
            Msg("[Script_GlobalHelper/setRegisteredHarmonicaVisuals(visual_name, value)] "
                "WARNING: visual_name.size() = "
                "0! You are trying to set an empty string!");
            //   return;
        }

        this->m_registered_harmonica_visuals[visual_name] = is_used;
    }

    inline const xr_map<xr_string, xr_vector<std::pair<std::function<bool(std::uint16_t, bool)>, xr_string>>>&
    getAnimpointTable(void) noexcept
    {
        return this->m_animpoint_table;
    }

    inline void setAnimpointTable(
        const xr_map<xr_string, xr_vector<std::pair<std::function<bool(std::uint16_t, bool)>, xr_string>>>& map)
    {
        if (!map.size())
        {
            Msg("[Script_GlobalHelper/setAnimpointTable(pair)] WARNING: "
                "map.size() = 0! You are trying to set an empty string!");
            //  return;
        }

        this->m_animpoint_table = map;
    }

    inline const xr_map<xr_string, StateLibData>& getStateLibrary(void) const noexcept { return this->m_state_library; }
    inline void setStateLibrary(const xr_map<xr_string, StateLibData>& map) noexcept
    {
        if (!map.size())
        {
            Msg("[DataBase/Storage/setStateLibrary(map)] WARNING: map.size() = 0! You are "
                "trying to set an empty "
                "map! ");
            //    return;
        }

        this->m_state_library = map;
    }

    inline void setStateLibrary(const std::pair<xr_string, StateLibData>& pair) noexcept
    {
        if (!pair.first.size())
        {
            Msg("[DataBase/Storage/setStateLibrary(pair)] WARNING: pair.first.size() = 0! You "
                "are trying to set an "
                "empty pair!");
            //    return;
        }

        this->m_state_library.insert(pair);
    }

    inline void setStateLibrary(const xr_string& animation_name, const StateLibData& data) noexcept
    {
        if (!animation_name.size())
        {
            Msg("[DataBase/Storage/setStateLibrary(animation_name, data)] WARNING: "
                "animation_name.size() = 0! You are "
                "trying to set an empty string!");
            //   return;
        }

        this->m_state_library[animation_name] = data;
    }

    /*
        inline void setAnimpointTable(
            const std::pair<xr_string, std::pair<std::function<bool(std::uint16_t, bool)>,
       xr_string>>& pair)
        {
            if (!pair.first.size())
            {
                Msg("[Script_GlobalHelper/setAnimpointTable(pair)] WARNING: "
                    "pair.first.size() = 0! You are trying to set an empty string! No
       assignment!"); return;
            }

            if (!pair.second.first)
            {
                Msg("[Script_GlobalHelper/setAnimpointTable(pair)] WARNING: "
                    "pair.second.first = null! You are trying to set an empty function! No
       assignment!"); return;
            }

            if (!pair.second.second.size())
            {
                Msg("[Script_GlobalHelper/setAnimpointTable(pair)] WARNING: "
                    "pair.second.second.size() = 0! You are trying to set an empty string! No
       assignment!"); return;
            }

            this->m_animpoint_table.insert(pair);
        }*/

    inline void setAnimpointTable(
        const xr_string& animpoint_name, const std::pair<std::function<bool(std::uint16_t, bool)>, xr_string>& pair)
    {
        if (!animpoint_name.size())
        {
            Msg("[Script_GlobalHelper/setAnimpointTable(animpoint_name, function, "
                "animpoint_animation_name)] WARNING: "
                "animation_name.size() = 0! You are trying to set an empty string! No "
                "assignment!");
            //  return;
        }

        if (!pair.first)
        {
            Msg("[Script_GlobalHelper/setAnimpointTable(animpoint_name, function, "
                "animpoint_animation_name)] WARNING: "
                "pair.first = null! You are trying to set an empty function!");
            // return;
        }

        if (!pair.second.size())
        {
            Msg("[Script_GlobalHelper/setAnimpointTable(animpoint_name, function, "
                "animpoint_animation_name)] WARNING: "
                "pair.second.size() = 0! You are trying to set an empty string!");
            //   return;
        }

        this->m_animpoint_table[animpoint_name].push_back(pair);
    }

    inline void setAnimpointTable(const xr_string& animpoint_name,
        const std::function<bool(std::uint16_t, bool)> function, const xr_string& animpoint_animation_name)
    {
        if (!animpoint_name.size())
        {
            Msg("[Script_GlobalHelper/setAnimpointTable(animpoint_name, function, "
                "animpoint_animation_name)] WARNING: "
                "animation_name.size() = 0! You are trying to set an empty string!");
            //  return;
        }

        if (!function)
        {
            Msg("[Script_GlobalHelper/setAnimpointTable(animpoint_name, function, "
                "animpoint_animation_name)] WARNING: "
                "function = null! You are trying to set an empty function!");
            //  return;
        }

        if (!animpoint_animation_name.size())
        {
            Msg("[Script_GlobalHelper/setAnimpointTable(animpoint_name, function, "
                "animpoint_animation_name)] WARNING: "
                "animpoint_animation_name.size() = 0! You are trying to set an empty string!");
            // return;
        }

        this->m_animpoint_table[animpoint_name].push_back({function, animpoint_animation_name});
    }

    inline const xr_map<xr_string, xr_map<std::uint32_t, DialogData>>& getPhraseTable(void) const noexcept
    {
        return this->m_phrase_table;
    }

    inline void setPhraseTable(
        const xr_string& phrase_category_name, const std::uint32_t id, const DialogData& data) noexcept
    {
        if (phrase_category_name.empty())
        {
            Msg("[Scripts/Script_GlobalHelper/setPhraseTable(phrase_category_name, data)] "
                "WARNING: "
                "phrase_category_name.empty() == true! Can't assign return...");
            return;
        }

        this->m_phrase_table[phrase_category_name][id] = data;
    }

    /*
        inline void setPhraseTable(const std::pair<xr_string, std::pair<std::uint32_t, DialogData>>& pair) noexcept
        {
            if (pair.first.empty())
            {
                Msg("[Scripts/Script_GlobalHelper/setPhraseTable(pair)] WARNING: "
                    "pair.first.empty() == true! Can't assign "
                    "return...");
                return;
            }

            this->m_phrase_table.insert(pair);
        }*/

    inline void setPhraseTable(const xr_map<xr_string, xr_map<std::uint32_t, DialogData>>& map) noexcept
    {
        if (map.empty())
        {
            Msg("[Scripts/Script_GlobalHelper/setPhraseTable(map)] WARNING: map.empty() == "
                "true! Can't assign "
                "return...");
            return;
        }

        this->m_phrase_table = map;
    }

    inline xr_map<xr_string, AnyCallable<void>>& getRegisteredFunctionsDialogManager(void)
    {
        return this->m_registered_functions_dialog_manager;
    }

    inline xr_map<xr_string, AnyCallable<bool>>& getRegisteredFunctionsBoolDialogManager(void)
    {
        return this->m_registered_functions_bool_dialog_manager;
    }

    inline const xr_map<xr_string, xr_map<std::uint16_t, xr_map<std::uint32_t, int>>>& getPhrasePriorityTable(
        void) const noexcept
    {
        return this->m_phrase_priority_table;
    }

    inline void setPhrasePriorityTable(
        const xr_map<xr_string, xr_map<std::uint16_t, xr_map<std::uint32_t, int>>>& map) noexcept
    {
        if (map.empty())
        {
            Msg("[Scripts/Script_GlobalHelper/setPhrasePriorityTable(map)] WARNING: map.empty() == true! You are "
                "trying to set an empty map");
        }

        this->m_phrase_priority_table = map;
    }

    inline void setPhrasePriorityTable(const xr_string& dialog_type_name, const std::uint16_t npc_id,
        const std::uint32_t phrase_id, const int priority) noexcept
    {
        if (dialog_type_name.empty())
        {
            Msg("[Scripts/Script_GlobalHelper/setPhrasePriorityTable(dialog_type_name, npc_id, phrase_id, priority)] "
                "WARNING: dialog_type_name.empty() == true! You are trying to set an empty string no assigment!");
            return;
        }

        if (npc_id == Globals::kUnsignedInt16Undefined)
        {
            Msg("[Scripts/Script_GlobalHelper/setPhrasePriorityTable(dialog_type_name, npc_id, phrase_id, priority)] "
                "WARNING: npc_id is "
                "undefined! std::uint16_t(-1)!");
        }

        if (phrase_id == Globals::kUnsignedInt32Undefined)
        {
            Msg("[Scripts/Script_GlobalHelper/setPhrasePriorityTable(dialog_type_name, npc_id, phrase_id, priority)] "
                "WARNING: phrase_id "
                "is undefined! std::uint32_t(-1)!");
        }

        this->m_phrase_priority_table[dialog_type_name][npc_id][phrase_id] = priority;
    }

    // Lord: здесь переименовать комметарий под уже изменившийся файл когда используется CRD
    // @ Private, using in Script_XR_Gulag
    inline const xr_map<xr_string, CScriptIniFile*>& getDynamicLtx(void) const noexcept
    {
        return this->m_registered_generated_gulag_inis;
    }

    inline void setDynamicLtx(const xr_string& name, CScriptIniFile* file)
    {
        if (name.empty())
        {
            Msg("[Scripts/Script_GlobalHelper/setDynamicLtx(name, file)] WARNING: name.empty() == true! Can't assign "
                "return");
            return;
        }

        if (!file)
        {
            Msg("[Scripts/Script_GlobalHelper/setDynamicLtx(name, file)] WARNING: file == nullptr! Can't assign "
                "return");
            return;
        }

        this->m_registered_generated_gulag_inis[name] = file;
    }

    inline void setDynamicLtx(const std::pair<xr_string, CScriptIniFile*>& pair)
    {
        if (pair.first.empty())
        {
            Msg("[Scripts/Script_GlobalHelper/setDynamicLtx(pair)] WARNING: pair.first.empty() == true! Can't assign "
                "return");
            return;
        }

        if (!pair.second)
        {
            Msg("[Scripts/Script_GlobalHelper/setDynamicLtx(pair)] WARNING: pair.second == nullptr! Can't assign "
                "return");
            return;
        }

        this->m_registered_generated_gulag_inis.insert(pair);
    }

    inline void setDynamicLtx(const xr_map<xr_string, CScriptIniFile*> map)
    {
        if (map.empty())
        {
            Msg("[Scripts/Script_GlobalHelper/setDynamicLtx(map)] WARNING: map.empty() == true! Can't assign return");
            return;
        }

        this->m_registered_generated_gulag_inis = map;
    }

    // @ Private, don't call it personally!
    inline void DeallocateDynamicLtx(void)
    {
        if (!this->m_registered_generated_gulag_inis.empty())
        {
            for (std::pair<const xr_string, CScriptIniFile*>& it : this->m_registered_generated_gulag_inis)
            {
                Msg("[Scripts/Script_GlobalHelper/DeallocateDynamicLtx()] deleting generated CScriptIniFile logic "
                    "stuff from "
                    "GulagGenerator! %s",
                    it.second->fname());
                xr_delete(it.second);
            }
        }
    }

    inline std::uint32_t getMonsterAnimationToAction(const xr_string& animation_name)
    {
        if (this->m_monster_animation_to_action.empty())
        {
            R_ASSERT2(false, "user this structure must initialized!");
            return MonsterSpace::eAA_StandIdle;
        }

        if (this->m_monster_animation_to_action.find(animation_name) == this->m_monster_animation_to_action.end())
            return MonsterSpace::eAA_StandIdle;

        return this->m_monster_animation_to_action[animation_name];
    }

    inline const xr_map<xr_string, MonsterSound::EType>& getSoundNameToAction(void) const noexcept
    {
        return this->m_monster_sound_name_to_type_action;
    }

    inline xr_map<xr_string,
        std::function<void(
            CScriptGameObject* const, CScriptIniFile* const, const xr_string&, const xr_string&, const xr_string&)>>&
    getSchemesSetSchemeCallbacks(void) noexcept
    {
        return this->m_registered_schemes_set_scheme_callbacks;
    }

    inline xr_map<xr_string,
        std::function<void(CScriptGameObject* const, CScriptIniFile* const, const xr_string&, const xr_string&,
            DataBase::Storage_Scheme&)>>
    getSchemesAddToBinderCallbacks(void) noexcept
    {
        return this->m_registered_schemes_add_to_binder_callbacks;
    }

    // @ Uses in Script_SchemeSRLight
    inline const xr_map<xr_string, bool>& getIndoorLevels(void) const noexcept { return this->m_indoor_levels; }
    inline void setIndoorLevels(const xr_string& level_name, const bool value) noexcept
    {
        if (level_name.empty())
        {
            Msg("[Scripts/Script_GlobalHelper/setIndoorLevels(level_name, value)] WARNING: level_name.empty() == true! "
                "You set an empty string return ...");
            return;
        }

        this->m_indoor_levels[level_name] = value;
    }

    inline float getXRDangerIgnoreDistanceByDangerType(const CDangerObject::EDangerType type) const noexcept
    {
        if (this->m_xr_danger_ignore_distance_by_danger_type.find(type) !=
            this->m_xr_danger_ignore_distance_by_danger_type.end())
            return this->m_xr_danger_ignore_distance_by_danger_type.at(type);

        Msg("[Scripts/Script_GlobalHelper/setXRDangerIgnoreDistanceByDangerType(type)] WARNING: returns 0.0f, because "
            "can't find a danger type -> %d",
            static_cast<std::uint32_t>(type));

        return 0.0f;
    }

    inline const xr_map<xr_string, bool>& getLookDirectionStates(void) const noexcept
    {
        return this->m_look_direction_states;
    }

    inline const xr_map<xr_string, StateManagerAnimationData>& getStateManagerAnimationList(void) const noexcept
    {
        return this->m_state_manager_animation_list;
    }

    inline const xr_map<xr_string, StateManagerAnimationData>& getStateManagerAnimationStateList(void) const noexcept
    {
        return this->m_state_manager_animationstate_list;
    }
#pragma endregion

private:
    CUISequencer* m_tutorial;
    xr_map<int, bool> m_monster_classes;
    xr_map<int, bool> m_stalker_classes;
    xr_map<int, bool> m_weapon_classes;
    xr_map<int, bool> m_artefact_classes;
    xr_map<std::uint32_t, bool> m_ammo_section;
    xr_map<xr_string, bool> m_look_direction_states;
    xr_map<xr_string, bool> m_registered_eatable_visuals;
    xr_map<xr_string, bool> m_registered_harmonica_visuals;
    xr_map<xr_string, bool> m_quest_section;
    xr_map<xr_string,
        std::function<void(
            CScriptGameObject* const, CScriptIniFile* const, const xr_string&, const xr_string&, const xr_string&)>>
        m_registered_schemes_set_scheme_callbacks;
    xr_map<xr_string,
        std::function<void(CScriptGameObject* const, CScriptIniFile* const, const xr_string&, const xr_string&,
            DataBase::Storage_Scheme&)>>
        m_registered_schemes_add_to_binder_callbacks;
    xr_map<xr_string, Script_SmartTerrainControl_States> m_registered_smart_terrain_control_script_states;
    xr_map<xr_string, xr_string> m_squad_community_by_behavior;
    xr_map<xr_string, xr_vector<std::pair<std::function<bool(std::uint16_t, bool)>, xr_string>>> m_animpoint_table;
    xr_map<xr_string, AnyCallable<void>> m_registered_functions_xr_effects;
    xr_map<xr_string, AnyCallable<bool>> m_registered_functions_xr_conditions;
    xr_map<xr_string, AnyCallable<void>> m_registered_functions_dialog_manager;
    xr_map<xr_string, AnyCallable<bool>> m_registered_functions_bool_dialog_manager;
    xr_map<xr_string, xr_map<std::uint32_t, DialogData>> m_phrase_table;
    xr_map<xr_string, xr_map<std::uint16_t, xr_map<std::uint32_t, int>>> m_phrase_priority_table;
    xr_map<xr_string, CScriptIniFile*> m_registered_generated_gulag_inis;
    xr_map<xr_string, StateLibData> m_state_library;
    xr_map<xr_string, StateManagerAnimationData> m_state_manager_animation_list;
    xr_map<xr_string, StateManagerAnimationData> m_state_manager_animationstate_list;
    xr_map<xr_string, SmartCoverData> m_registered_smartcovers;
    xr_map<xr_string, xr_string> m_job_type_by_scheme;
    xr_map<xr_string, xr_string> m_game_smarts_by_no_assault_zone;
    xr_map<xr_string, std::uint32_t> m_simulationboard_group_id_by_levels_name;
    xr_map<xr_string, std::uint32_t> m_monster_animation_to_action;
    xr_map<xr_string, MonsterSound::EType> m_monster_sound_name_to_type_action;
    xr_map<xr_string, bool> m_registered_smart_terrain_territory_type;
    xr_map<xr_string, bool> m_simulationsquad_is_squad_monster_by_type;
    xr_map<xr_string, bool> m_indoor_levels;
    xr_map<CDangerObject::EDangerType, float> m_xr_danger_ignore_distance_by_danger_type;
    // @ First - id | Second - distance
    std::pair<std::uint32_t, std::uint32_t> m_game_server_nearest_to_actor_smart_terrain;
    xr_vector<xr_string> m_registered_smart_terrain_path_fields;
};

} // namespace Scripts
} // namespace Cordis
