#pragma once
#include "Script_SurgeManager.h"
#include "Script_XR_Sound.h"
#include "Script_XR_Gulag.h"
#include "Script_XR_Wounded.h"

namespace Cordis
{
namespace Scripts
{
namespace XR_CONDITION
{
inline bool is_surge_started(void) { return Script_SurgeManager::getInstance().IsStarted(); }

inline bool is_surge_complete(void) { return Script_SurgeManager::getInstance().IsFinished(); }

inline bool is_surge_kill_all(void) { return Script_SurgeManager::getInstance().IsKillingAll(); }

inline bool is_enemy_actor(CScriptGameObject* enemy, CScriptGameObject* object)
{
    if (!enemy)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!object)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return (enemy->ID() == object->ID());
}

inline bool is_fighting_dist_ge(CScriptGameObject* enemy, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!enemy)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    float distance = atof(buffer[0].c_str());

    return (enemy->Position().distance_to_sqr(npc->Position()) >= (distance * distance));
}

inline bool is_fighting_dist_ge(
    CSE_ALifeDynamicObject* enemy, CSE_ALifeDynamicObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!enemy)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    float distance = atof(buffer[0].c_str());

    return (enemy->Position().distance_to_sqr(npc->Position()) >= (distance * distance));
}

inline bool is_fighting_dist_le(CScriptGameObject* enemy, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!enemy)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    float distance = atof(buffer[0].c_str());

    return (enemy->Position().distance_to_sqr(npc->Position()) <= distance * distance);
}

inline bool is_fighting_dist_le(
    CSE_ALifeDynamicObject* enemy, CSE_ALifeDynamicObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!enemy)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    float distance = atof(buffer[0].c_str());

    return (enemy->Position().distance_to_sqr(npc->Position()) <= distance * distance);
}

inline bool is_enemy_in_zone(CScriptGameObject* enemy, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!enemy)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& zone_name = buffer[0];

    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (!zone)
    {
        R_ASSERT2(false, "Can't find a script object's zone!");
        return false;
    }

    return Globals::Utils::is_npc_in_zone(enemy, zone);
}

inline bool is_enemy_in_zone(
    CSE_ALifeDynamicObject* server_enemy, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!server_enemy)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& zone_name = buffer[0];

    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (!zone)
    {
        R_ASSERT2(false, "Can't find a script object's zone");
        return false;
    }

    return Globals::Utils::is_npc_in_zone(server_enemy, zone);
}

inline bool is_black_screen(CScriptGameObject* actor, CScriptGameObject* npc) { return Device.dwPrecacheFrame > 1; }

inline bool is_black_screen(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    return Device.dwPrecacheFrame > 1;
}

inline bool check_npc_name(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!actor)
    {
        R_ASSERT2(false, "actor is null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "npc is null!");
        return false;
    }

    if (!npc->Name())
    {
        R_ASSERT2(false, "String can't be nullptr! Something goes wrong!");
        return false;
    }

    const xr_string& npc_name = buffer[0];

    if (!npc_name.size())
    {
        R_ASSERT2(false, "String can't be empty!");
        return false;
    }

    return (npc->Name() == npc_name);
}

inline bool check_npc_name(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!server_npc->name_replace())
    {
        R_ASSERT2(false, "string can't be null! Something goes wrong!");
        return false;
    }

    const xr_string& npc_name = buffer[0];

    if (!npc_name.size())
    {
        R_ASSERT2(false, "Name can't be empty!");
        return false;
    }

    return (server_npc->name_replace() == npc_name);
}

inline bool check_enemy_name(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    const xr_string& npc_name = buffer[0];

    if (!npc_name.size())
    {
        R_ASSERT2(false, "Name can't be empty!");
        return false;
    }

    const std::uint16_t& enemy_id = DataBase::Storage::getInstance().getStorage().at(npc->ID()).getEnemyID();
    CScriptGameObject* enemy = DataBase::Storage::getInstance().getStorage().at(enemy_id).getClientObject();

    if (!enemy)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (enemy->Alive())
    {
        xr_string name = enemy->Name();
        return (name == npc_name);
    }

    return false;
}

inline bool is_playing_sound(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return XR_SOUND::getSoundDatabase()[npc->ID()];
}

inline bool is_see_npc(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!npc)
    {
        Msg("[Scripts/XR_CONDITION/is_see_npc(actor, npc, npc_name)] WARNING: npc = nullptr! Returned value = false.");
        return false;
    }

    const xr_string& npc_name = buffer[0];

    CScriptGameObject* npc1 = Globals::get_story_object(npc_name);

    if (!npc1)
    {
        Msg("[Scripts/XR_CONDITION/is_see_npc(actor, npc, npc_name)] WARNING: npc1 = nullptr! Returned value = false.");
        return false;
    }

    return npc->CheckObjectVisibility(npc1);
}

inline bool is_actor_see_npc(CScriptGameObject* actor, CScriptGameObject* npc)
{
    return DataBase::Storage::getInstance().getActor()->CheckObjectVisibility(npc);
}

inline bool is_npc_in_actor_frustrum(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return Globals::is_npc_in_actor_frustrum(npc);
}

inline bool is_wounded(CScriptGameObject* actor, CScriptGameObject* npc) { return XR_WOUNDED::is_wounded(npc); }

inline bool is_dist_to_actor_ge(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    float distance = atof(buffer[0].c_str());

    if (fis_zero(distance))
    {
        Msg("[Scripts/XR_CONDITION/is_dist_to_actor_ge(actor, npc, distance)] WARNING: distance is ZERO -> %f",
            distance);
        return false;
    }

    if (distance < 0.0f)
    {
        Msg("[Scripts/XR_CONDITION/is_dist_to_actor_ge(actor, npc, distance)] WARNING: distance is a negative value -> "
            "%f",
            distance);
        return false;
    }

    return (npc->Position().distance_to_sqr(actor->Position()) >= (distance * distance));
}

inline bool is_dist_to_actor_ge(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    float distance = atof(buffer[0].c_str());

    if (fis_zero(distance))
    {
        Msg("[Scripts/XR_CONDITION/is_dist_to_actor_ge(server_actor, server_npc, distance)] WARNING: distance is ZERO "
            "-> %f",
            distance);
        return false;
    }

    if (distance < 0.0f)
    {
        Msg("[Scripts/XR_CONDITION/is_dist_to_actor_ge(server_actor, server_npc, distance)] WARNING: distance is a "
            "negative value -> %f",
            distance);
        return false;
    }

    return (server_npc->Position().distance_to_sqr(actor->Position()) >= (distance * distance));
}

inline bool is_dist_to_actor_ge(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!server_actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    float distance = atof(buffer[0].c_str());

    if (fis_zero(distance))
    {
        Msg("[Scripts/XR_CONDITION/is_dist_to_actor_ge(server_actor, server_npc, distance)] WARNING: distnace is ZERO "
            "-> %f",
            distance);
        return false;
    }

    if (distance < 0.0f)
    {
        Msg("[Scripts/XR_CONDITION/is_dist_to_actor_ge(server_actor, server_npc, distance)] WARNING: distance is a "
            "negative value -> %f",
            distance);
        return false;
    }

    return (server_npc->Position().distance_to_sqr(server_actor->Position()) >= (distance * distance));
}

inline bool is_obj_on_job(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    const xr_string& logic_name = buffer[0];

    if (!logic_name.size())
    {
        R_ASSERT2(false, "string can't be empty!");
        return false;
    }

    Script_SE_SmartTerrain* server_smart = nullptr;

    const xr_string& smart_terrain_name = buffer[1];

    if (!smart_terrain_name.size())
    {
        Msg("[Scripts/XR_CONDITION/is_obj_on_job(actor, npc, logic_name, smart_terrain_name)] WARNING: "
            "smart_terrain_name is empty string!");
        server_smart = XR_GULAG::get_npc_smart(npc)->cast_script_se_smartterrain();

        if (!server_smart)
        {
            Msg("[Scripts/XR_CONDITION/is_obj_on_job(actor, npc, logic_name, smart_terrain_name)] WARNING: "
                "server_smart_terrain was nullptr! Return false.");
            return false;
        }
    }
    else
    {
        Msg("[Scripts/XR_CONDITION/is_obj_on_job(actor, npc, logic_name, smart_terrain_name)] getting smart terrain by "
            "argument -> smart_terrain_name = %s",
            smart_terrain_name.c_str());
        server_smart = Script_SimulationBoard::getInstance().getSmartTerrainsByName().at(smart_terrain_name);

        if (!server_smart)
        {
            Msg("[Scripts/XR_CONDITION/is_obj_on_job(actor, npc, logic_name, smart_terrain_name)] WARNING: "
                "server_smart_terrain was nullptr! Return false.");
            return false;
        }
    }

    for (std::pair<const std::uint32_t, NpcInfo>& it : server_smart->getNpcInfo())
    {
        JobDataSmartTerrain& job_data = server_smart->getJobData()[it.second.m_job_link.m_job_index];

        Msg("[Scripts/XR_CONDITION/is_obj_on_job(actor, npc, logic_name, smart_terrain_name)] section %s",
            job_data.m_job_id.first.c_str());

        if (job_data.m_job_id.first == logic_name)
            return true;
    }

    return false;
}

inline bool is_distance_to_obj_on_job_le(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& logic_name = buffer[0];
    float distance = atof(buffer[1].c_str());

    if (!logic_name.size())
    {
        R_ASSERT2(false, "string can't be empty!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    Script_SE_SmartTerrain* server_smart = XR_GULAG::get_npc_smart(npc)->cast_script_se_smartterrain();

    for (std::pair<const std::uint32_t, NpcInfo>& it : server_smart->getNpcInfo())
    {
        JobDataSmartTerrain& job_data = server_smart->getJobData()[it.second.m_job_link.m_job_index];

        if (job_data.m_job_id.first == logic_name)
        {
            return (npc->Position().distance_to_sqr(it.second.m_server_object->Position()) <= (distance * distance));
        }
    }

    return false;
}

inline bool is_story_obj_in_zone_by_name(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& object_id_name = buffer[0];
    const xr_string& zone_name = buffer[1];

    if (!object_id_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!zone_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    std::uint16_t object_id = Globals::get_story_object_id(object_id_name);
    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (object_id && zone)
    {
        CSE_ALifeDynamicObject* server_object = ai().alife().objects().object(object_id);

        if (!server_object)
        {
            R_ASSERT2(false, "object was null!");
            return false;
        }

        return zone->inside(server_object->Position());
    }

    return false;
}

inline bool is_story_obj_in_zone_by_name(
    CSE_ALifeDynamicObject* actor, CSE_ALifeDynamicObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& object_id_name = buffer[0];
    const xr_string& zone_name = buffer[1];

    if (!object_id_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!zone_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    std::uint16_t object_id = Globals::get_story_object_id(object_id_name);
    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (object_id && zone)
    {
        CSE_ALifeDynamicObject* server_object = ai().alife().objects().object(object_id);

        if (!server_object)
        {
            R_ASSERT2(false, "object was null!");
            return false;
        }

        return zone->inside(server_object->Position());
    }

    return false;
}

inline bool is_actor_in_zone(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& zone_name = buffer[0];

    if (!zone_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (!zone)
    {
        R_ASSERT2(false, "something goes wrong!");
        return false;
    }

    return Globals::Utils::is_npc_in_zone(DataBase::Storage::getInstance().getActor(), zone);
}

inline bool is_actor_in_zone(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& zone_name = buffer[0];

    if (!zone_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!DataBase::Storage::getInstance().getActor())
    {
        Msg("[Scripts/XR_CONDITION/is_actor_in_zone(server_actor, server_npc, zone_name)] WARNING: Client still not "
            "initialize! Early calling!!! DataBase::Storage::Actor = nullptr! Return false.");
        return false;
    }

    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (!zone)
    {
        R_ASSERT2(false, "something goes wrong!");
        return false;
    }

    return Globals::Utils::is_npc_in_zone(DataBase::Storage::getInstance().getActor(), zone);
}

inline bool is_actor_in_zone(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& zone_name = buffer[0];

    if (!zone_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!DataBase::Storage::getInstance().getActor())
    {
        Msg("[Scripts/XR_CONDITION/is_actor_in_zone(server_actor, server_npc, zone_name)] WARNING: Client still not "
            "initialize! Early calling!!! DataBase::Storage::Actor = nullptr! Return false.");
        return false;
    }

    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (!zone)
    {
        R_ASSERT2(false, "something goes wrong!");
        return false;
    }

    return Globals::Utils::is_npc_in_zone(DataBase::Storage::getInstance().getActor(), zone);
}

inline bool is_npc_in_zone(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& zone_name = buffer[0];

    if (!zone_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (!zone)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return Globals::Utils::is_npc_in_zone(npc, zone);
}

inline bool is_npc_in_zone(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& zone_name = buffer[0];

    if (!zone_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (!zone)
    {
        Msg("[Scripts/XR_CONDITION/is_npc_in_zone(server_actor, server_npc, zone_name)] NOTIFY: zone = nullptr! "
            "Returns true.");
        return true;
    }

    CScriptGameObject* npc = DataBase::Storage::getInstance().getStorage().at(server_npc->ID).getClientObject();

    if (!npc)
    {
        Msg("[Scripts/XR_CONDITION/is_npc_in_zone(server_actor, server_npc, zone_name)] NOTIFY: npc = nullptr! Returns "
            "zone->inside(server_npc->Position())");
        return zone->inside(server_npc->Position());
    }

    return Globals::Utils::is_npc_in_zone(npc, zone);
}

inline bool is_npc_in_zone(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& zone_name = buffer[0];

    if (!zone_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    CScriptGameObject* zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);

    if (!zone)
    {
        Msg("[Scripts/XR_CONDITION/is_npc_in_zone(server_actor, server_npc, zone_name)] NOTIFY: zone = nullptr! "
            "Returns true.");
        return true;
    }

    CScriptGameObject* npc = DataBase::Storage::getInstance().getStorage().at(server_npc->ID).getClientObject();

    if (!npc)
    {
        Msg("[Scripts/XR_CONDITION/is_npc_in_zone(server_actor, server_npc, zone_name)] NOTIFY: npc = nullptr! Returns "
            "zone->inside(server_npc->Position())");
        return zone->inside(server_npc->Position());
    }

    return Globals::Utils::is_npc_in_zone(npc, zone);
}

inline bool is_health_le(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    float value = atof(buffer[0].c_str());

    if (value)
        return (npc->GetHealth() < value);

    Msg("[Scripts/XR_CONDITION/is_health_le(actor, npc, value)] WARNING: value is less than 0 or equals 0! Return "
        "false.");

    return false;
}

inline bool is_actor_health_le(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    float value = atof(buffer[0].c_str());

    if (value)
        return (actor->GetHealth() < value);

    Msg("[Scripts/XR_CONDITION/is_actor_health_le(actor, npc, value)] WARNING: value is less than 0 or equals 0! "
        "Return "
        "false.");

    return false;
}

inline bool is_npc_community(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& community_name = buffer[0];

    if (!community_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (Globals::character_community(npc) == community_name)
        return true;

    return false;
}

inline bool is_npc_community(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& community_name = buffer[0];

    if (!community_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    CScriptGameObject* npc = DataBase::Storage::getInstance().getStorage().at(server_npc->ID).getClientObject();

    if (!npc)
    {
        CSE_ALifeTraderAbstract* server_trader = server_npc->cast_trader_abstract();
        if (!server_trader)
        {
            R_ASSERT2(false, "can't be check class!!!");
            return false;
        }

        return (server_trader->CommunityName() == community_name);
    }

    if (Globals::character_community(npc) == community_name)
        return true;

    return false;
}

inline bool is_npc_community(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    const xr_string& community_name = buffer[0];

    if (!community_name.size())
    {
        R_ASSERT2(false, "can't be empty!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    CScriptGameObject* npc = DataBase::Storage::getInstance().getStorage().at(server_npc->ID).getClientObject();

    if (!npc)
    {
        CSE_ALifeTraderAbstract* server_trader = server_npc->cast_trader_abstract();
        if (!server_trader)
        {
            R_ASSERT2(false, "can't be check class!!!");
            return false;
        }

        return (server_trader->CommunityName() == community_name);
    }

    if (Globals::character_community(npc) == community_name)
        return true;

    return false;
}

// Lord: доделать когда будет сделано xr_hit
inline bool is_hitted_by(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    return false;
}

// Lord: доделать когда будет сделано xr_hit
inline bool is_hitted_on_bone(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    return false;
}

inline bool is_best_pistol(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    CScriptGameObject* pistol = npc->item_in_slot(1);

    if (!pistol)
    {
        Msg("[Scripts/XR_CONDITION/is_best_pistol(actor, npc)] Actor doesn't have a pistol in slot!");
        return false;
    }

    return true;
}

// Lord: доделать когда будет сделано xr_hit
inline bool is_deadly_hit(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return false;
}

// Lord: доделать когда будет сделано xr_death
inline bool is_killed_by(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return false;
}

inline bool is_alive_one(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    CSE_ALifeCreatureAbstract* server_object = nullptr;
    std::uint16_t server_npc_id = 0;
    for (const xr_string& it : buffer)
    {
        server_npc_id = Globals::get_story_object_id(it);

        if (!server_npc_id)
        {
            Msg("[Scripts/XR_CONDITION/is_alive_one(actor, npc, buffer)] WARNING: server_npc_id < 0. Can't find a "
                "valid id!");
            return false;
        }

        server_object = ai().alife().objects().object(server_npc_id)->cast_creature_abstract();

        if (!server_object)
        {
            Msg("[Scripts/XR_CONDITION/is_alive_one(actor, npc, buffer)] WARNING: server_object = nullptr. Maybe a "
                "stalker was deleted! OR Maybe BAD CAST!!!!");
            return false;
        }

        if (server_object->g_Alive() && Globals::IsStalker(server_object, 0))
            return true;
    }

    return false;
}

inline bool is_alive_one(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    CSE_ALifeCreatureAbstract* server_object = nullptr;
    std::uint16_t server_npc_id = 0;
    for (const xr_string& it : buffer)
    {
        server_npc_id = Globals::get_story_object_id(it);

        if (!server_npc_id)
        {
            Msg("[Scripts/XR_CONDITION/is_alive_one(actor, npc, buffer)] WARNING: server_npc_id < 0. Can't find a "
                "valid id!");
            return false;
        }

        server_object = ai().alife().objects().object(server_npc_id)->cast_creature_abstract();

        if (!server_object)
        {
            Msg("[Scripts/XR_CONDITION/is_alive_one(actor, npc, buffer)] WARNING: server_object = nullptr. Maybe a "
                "stalker was deleted! OR Maybe BAD CAST!!!!");
            return false;
        }

        if (server_object->g_Alive() && Globals::IsStalker(server_object, 0))
            return true;
    }

    return false;
}

inline bool is_alive_one(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    CSE_ALifeCreatureAbstract* server_object = nullptr;
    std::uint16_t server_npc_id = 0;
    for (const xr_string& it : buffer)
    {
        server_npc_id = Globals::get_story_object_id(it);

        if (!server_npc_id)
        {
            Msg("[Scripts/XR_CONDITION/is_alive_one(actor, npc, buffer)] WARNING: server_npc_id < 0. Can't find a "
                "valid id!");
            return false;
        }

        server_object = ai().alife().objects().object(server_npc_id)->cast_creature_abstract();

        if (!server_object)
        {
            Msg("[Scripts/XR_CONDITION/is_alive_one(actor, npc, buffer)] WARNING: server_object = nullptr. Maybe a "
                "stalker was deleted! OR Maybe BAD CAST!!!!");
            return false;
        }

        if (server_object->g_Alive() && Globals::IsStalker(server_object, 0))
            return true;
    }

    return false;
}

inline bool is_alive(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_alive(actor, npc, buffer)] buffer.size() = 0!");
        return false;
    }

    CSE_ALifeCreatureAbstract* server_object = nullptr;
    if (!npc)
    {
        server_object =
            ai().alife().objects().object(Globals::get_story_object_id(buffer[0]))->cast_creature_abstract();

        if (!server_object)
        {
            Msg("[Scripts/XR_CONDITION/is_alive(actor, npc, buffer)] WARNING: server_object = nullptr. Maybe bad cast "
                "or object not found!");
            return false;
        }
    }
    else
    {
        server_object = ai().alife().objects().object(npc->ID())->cast_creature_abstract();

        if (!server_object)
        {
            Msg("[Scripts/XR_CONDITION/is_alive(actor, npc, buffer)] WARNING: server_object = nullptr. Maybe bad cast "
                "or object not found!");
            return false;
        }
    }

    if (server_object->g_Alive() && Globals::IsStalker(server_object, 0))
        return true;

    return false;
}

inline bool is_alive(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_alive(actor, server_npc, buffer)] buffer.size() = 0!");
        return false;
    }

    CSE_ALifeCreatureAbstract* server_object = nullptr;
    if (!server_npc)
    {
        server_object =
            ai().alife().objects().object(Globals::get_story_object_id(buffer[0]))->cast_creature_abstract();

        if (!server_object)
        {
            Msg("[Scripts/XR_CONDITION/is_alive(actor, server_npc, buffer)] WARNING: server_object = nullptr. Maybe "
                "bad cast "
                "or object not found!");
            return false;
        }
    }
    else
    {
        server_object = ai().alife().objects().object(server_npc->ID)->cast_creature_abstract();

        if (!server_object)
        {
            Msg("[Scripts/XR_CONDITION/is_alive(actor, server_npc, buffer)] WARNING: server_object = nullptr. Maybe "
                "bad cast "
                "or object not found!");
            return false;
        }
    }

    if (server_object->g_Alive() && Globals::IsStalker(server_object, 0))
        return true;

    return false;
}

inline bool is_alive(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_alive(server_actor, server_npc, buffer)] buffer.size() = 0!");
        return false;
    }

    CSE_ALifeCreatureAbstract* server_object = nullptr;
    if (!server_npc)
    {
        server_object =
            ai().alife().objects().object(Globals::get_story_object_id(buffer[0]))->cast_creature_abstract();

        if (!server_object)
        {
            Msg("[Scripts/XR_CONDITION/is_alive(server_actor, server_npc, buffer)] WARNING: server_object = nullptr. "
                "Maybe bad cast "
                "or object not found!");
            return false;
        }
    }
    else
    {
        server_object = ai().alife().objects().object(server_npc->ID)->cast_creature_abstract();

        if (!server_object)
        {
            Msg("[Scripts/XR_CONDITION/is_alive(server_actor, server_npc, buffer)] WARNING: server_object = nullptr. "
                "Maybe bad cast "
                "or object not found!");
            return false;
        }
    }

    if (server_object->g_Alive() && Globals::IsStalker(server_object, 0))
        return true;

    return false;
}

inline bool is_dead(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    CScriptGameObject* npc1 = Globals::get_story_object(buffer[0]);

    if (npc1)
    {
        if (!npc1->Alive())
            return true;
        else
            return false;
    }

    return false;
}

inline bool is_dead(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    CScriptGameObject* npc1 = Globals::get_story_object(buffer[0]);

    if (npc1)
    {
        if (!npc1->Alive())
            return true;
        else
            return false;
    }

    return false;
}

inline bool is_dead(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    CScriptGameObject* npc1 = Globals::get_story_object(buffer[0]);

    if (npc1)
    {
        if (!npc1->Alive())
            return true;
        else
            return false;
    }

    return false;
}

inline bool is_story_object_exist(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    CScriptGameObject* npc1 = Globals::get_story_object(buffer[0]);

    return (!!npc1);
}

inline bool is_story_object_exist(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    CScriptGameObject* npc1 = Globals::get_story_object(buffer[0]);

    return (!!npc1);
}

inline bool is_story_object_exist(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument list can't be empty!");
        return false;
    }

    CScriptGameObject* npc1 = Globals::get_story_object(buffer[0]);

    return (!!npc1);
}

inline bool is_actor_has_item(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_actor_has_item(actor, npc, buffer)] WARNING: buffer.size() = 0! Returning "
            "false.");
        return false;
    }

    CScriptGameObject* story_actor = Globals::get_story_object("actor");

    if (story_actor)
        if (story_actor->GetObjectByName(buffer[0].c_str()))
            return true;

    return false;
}

inline bool is_actor_has_item(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_actor_has_item(actor, server_npc, buffer)] WARNING: buffer.size() = 0! Returning "
            "false.");
        return false;
    }

    CScriptGameObject* story_actor = Globals::get_story_object("actor");

    if (story_actor)
        if (story_actor->GetObjectByName(buffer[0].c_str()))
            return true;

    return false;
}

inline bool is_actor_has_item(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_actor_has_item(server_actor, server_npc, buffer)] WARNING: buffer.size() = 0! "
            "Returning "
            "false.");
        return false;
    }

    CScriptGameObject* story_actor = Globals::get_story_object("actor");

    if (story_actor)
        if (story_actor->GetObjectByName(buffer[0].c_str()))
            return true;

    return false;
}

inline bool is_npc_has_item(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_actor_has_item(actor, npc, buffer)] buffer.size() = 0! Returning false.");
        return false;
    }

    if (npc)
        if (npc->GetObjectByName(buffer[0].c_str()))
            return true;

    return false;
}

inline bool is_signal(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_signal(actor, npc, buffer)] WARNING: buffer.size() = 0! Returning false.");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    const DataBase::Storage_Data& storage_data = DataBase::Storage::getInstance().getStorage().at(npc->ID());

    return storage_data.getData().at(storage_data.getActiveSchemeName()).getSignals().at(buffer[0]);
}

/* Lord наверное не используется ибо такой перегрузки вообще нет
inline bool is_signal(CSE_ALifeDynamicObject* server_actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_signal(server_actor, npc, buffer)] WARNING: buffer.size() = 0! Returning false.");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    DataBase::Storage_Data& storage_data = DataBase::Storage::getInstance().getStorage()[npc->ID()];

    return storage_data[storage_data.m_active_scheme].m_signals[buffer[0]];
}*/

inline bool is_counter_greater(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    std::uint8_t argument_number = atoi(buffer[1].c_str());
    std::uint8_t pstor_number = XR_LOGIC::pstor_retrieve_number(actor, buffer[0]);

    return (pstor_number > argument_number);
}

inline bool is_counter_greater(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    std::uint8_t argument_number = atoi(buffer[1].c_str());
    std::uint8_t pstor_number = XR_LOGIC::pstor_retrieve_number(actor, buffer[0]);

    return (pstor_number > argument_number);
}

inline bool is_counter_equal(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    std::uint8_t argument_number = atoi(buffer[1].c_str());
    std::uint8_t pstor_number = XR_LOGIC::pstor_retrieve_number(actor, buffer[0]);

    return (pstor_number == argument_number);
}

inline bool is_counter_equal(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    std::uint8_t argument_number = atoi(buffer[1].c_str());
    std::uint8_t pstor_number = XR_LOGIC::pstor_retrieve_number(actor, buffer[0]);

    return (pstor_number == argument_number);
}

// Lord: реализовать _kamp_talker(actor, npc) когда будет xr_kamp
inline bool is_kamp_talk(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return false;
}

inline bool check_smart_alarm_status(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    const xr_string& smart_name = buffer[0];
    Script_SmartTerrainControl_States state =
        Script_GlobalHelper::getInstance().getRegisteredSmartTerrainControlScriptStates().at(buffer[1]);

    Script_SE_SmartTerrain* smart = Script_SimulationBoard::getInstance().getSmartTerrainsByName().at(smart_name);
    Script_SmartTerrainControl* smart_control = smart->getBaseOnActorControl();

    if (!smart_control)
    {
        Msg("Cannot calculate 'check_smart_alarm_status' for smart %s", smart_name.c_str());
        R_ASSERT(false);
        return false;
    }

    return (smart_control->getState() == state);
}

inline bool check_smart_alarm_status(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    const xr_string& smart_name = buffer[0];
    Script_SmartTerrainControl_States state =
        Script_GlobalHelper::getInstance().getRegisteredSmartTerrainControlScriptStates().at(buffer[1]);

    Script_SE_SmartTerrain* smart = Script_SimulationBoard::getInstance().getSmartTerrainsByName().at(smart_name);
    Script_SmartTerrainControl* smart_control = smart->getBaseOnActorControl();

    if (!smart_control)
    {
        Msg("Cannot calculate 'check_smart_alarm_status' for smart %s", smart_name.c_str());
        R_ASSERT(false);
        return false;
    }

    return (smart_control->getState() == state);
}

inline bool check_smart_alarm_status(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    const xr_string& smart_name = buffer[0];
    Script_SmartTerrainControl_States state =
        Script_GlobalHelper::getInstance().getRegisteredSmartTerrainControlScriptStates().at(buffer[1]);

    Script_SE_SmartTerrain* smart = Script_SimulationBoard::getInstance().getSmartTerrainsByName().at(smart_name);
    Script_SmartTerrainControl* smart_control = smart->getBaseOnActorControl();

    if (!smart_control)
    {
        R_ASSERT2(false, "Cannot calculate 'check_smart_alarm_status' for smart %s", smart_name.c_str());
        return false;
    }

    return (smart_control->getState() == state);
}

inline bool is_has_enemy(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return (!!npc->GetBestEnemy());
}

inline bool is_has_actor_enemy(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }
    CScriptGameObject* best_enemy = npc->GetBestEnemy();

    if (best_enemy)
    {
        return (best_enemy->ID() == DataBase::Storage::getInstance().getActor()->ID());
    }

    return false;
}

inline bool is_see_enemy(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    CScriptGameObject* best_enemy = npc->GetBestEnemy();

    if (best_enemy)
    {
        return npc->CheckObjectVisibility(best_enemy);
    }

    return false;
}

inline bool is_has_enemy_in_current_loopholes_fov(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (npc->GetBestEnemy() && npc->in_smart_cover())
    {
        if (npc->in_current_loophole_fov(npc->GetBestEnemy()->Position()))
            return true;
    }

    return false;
}

inline bool is_talking(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
    }

    return actor->IsTalking();
}

inline bool is_npc_talking(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return npc->IsTalking();
}

inline bool is_see_actor(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return (npc->Alive() && npc->CheckObjectVisibility(actor));
}

// Lord: реализовать когда будет xr_death или что-то
inline bool is_actor_enemy(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return false;
}

inline bool is_actor_friend(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return npc->GetRelationType(actor) == ALife::ERelationType::eRelationTypeFriend;
}

inline bool is_actor_neutral(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return npc->GetRelationType(actor) == ALife::ERelationType::eRelationTypeNeutral;
}

inline bool is_factions_enemies(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return Globals::GameRelations::is_factions_enemies(Globals::character_community(actor), buffer[0]);
}

inline bool is_factions_friends(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return Globals::GameRelations::is_factions_friends(Globals::character_community(actor), buffer[0]);
}

inline bool is_factions_neutrals(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return !(is_factions_enemies(actor, npc, buffer) || is_factions_friends(actor, npc, buffer));
}

inline bool is_faction_enemy_to_actor(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return Globals::GameRelations::community_goodwill(
               buffer[0].c_str(), DataBase::Storage::getInstance().getActor()->ID()) <= Globals::kRelationKoeffEnemy;
}

inline bool is_faction_enemy_to_actor(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return Globals::GameRelations::community_goodwill(
               buffer[0].c_str(), DataBase::Storage::getInstance().getActor()->ID()) <= Globals::kRelationKoeffEnemy;
}

inline bool is_faction_enemy_to_actor(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return Globals::GameRelations::community_goodwill(
               buffer[0].c_str(), DataBase::Storage::getInstance().getActor()->ID()) <= Globals::kRelationKoeffEnemy;
}

inline bool is_faction_friend_to_actor(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return Globals::GameRelations::community_goodwill(
               buffer[0].c_str(), DataBase::Storage::getInstance().getActor()->ID()) >= Globals::kRelationKoeffFriend;
}

inline bool is_faction_friend_to_actor(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return Globals::GameRelations::community_goodwill(
               buffer[0].c_str(), DataBase::Storage::getInstance().getActor()->ID()) >= Globals::kRelationKoeffFriend;
}

inline bool is_faction_friend_to_actor(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return Globals::GameRelations::community_goodwill(
               buffer[0].c_str(), DataBase::Storage::getInstance().getActor()->ID()) >= Globals::kRelationKoeffFriend;
}

inline bool is_faction_neutral_to_actor(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return !(is_faction_friend_to_actor(actor, npc, buffer) || is_faction_enemy_to_actor(actor, npc, buffer));
}

inline bool is_faction_neutral_to_actor(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return !(is_faction_friend_to_actor(server_actor, server_npc, buffer) ||
        is_faction_enemy_to_actor(server_actor, server_npc, buffer));
}

inline bool is_faction_neutral_to_actor(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    return !(
        is_faction_friend_to_actor(actor, server_npc, buffer) || is_faction_enemy_to_actor(actor, server_npc, buffer));
}

inline bool is_squad_friend_to_actor(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_squad_friend_to_actor(actor, npc, buffer)] WARNING: argument list is empty! "
            "Returns False.");
        return false;
    }

    return Globals::GameRelations::check_all_squad_members(buffer[0], Globals::kRelationsTypeFriends);
}

inline bool is_squad_friend_to_actor(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_squad_friend_to_actor(actor, npc, buffer)] WARNING: argument list is empty! "
            "Returns False.");
        return false;
    }

    return Globals::GameRelations::check_all_squad_members(buffer[0], Globals::kRelationsTypeFriends);
}

inline bool is_squad_friend_to_actor(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        Msg("[Scripts/XR_CONDITION/is_squad_friend_to_actor(actor, npc, buffer)] WARNING: argument list is empty! "
            "Returns False.");
        return false;
    }

    return Globals::GameRelations::check_all_squad_members(buffer[0], Globals::kRelationsTypeFriends);
}

inline bool is_squad_enemy_to_actor(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    for (const xr_string& it : buffer)
    {
        if (Globals::GameRelations::check_all_squad_members(it, Globals::kRelationsTypeEnemy))
            return true;
    }

    return false;
}

inline bool is_squad_enemy_to_actor(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    for (const xr_string& it : buffer)
    {
        if (Globals::GameRelations::check_all_squad_members(it, Globals::kRelationsTypeEnemy))
            return true;
    }

    return false;
}

inline bool is_squad_enemy_to_actor(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    for (const xr_string& it : buffer)
    {
        if (Globals::GameRelations::check_all_squad_members(it, Globals::kRelationsTypeEnemy))
            return true;
    }

    return false;
}

inline bool is_squad_neutral_to_actor(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    return !(is_squad_friend_to_actor(actor, npc, buffer) || is_squad_enemy_to_actor(actor, npc, buffer));
}

inline bool is_squad_neutral_to_actor(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    return !(is_squad_friend_to_actor(server_actor, server_npc, buffer) ||
        is_squad_enemy_to_actor(server_actor, server_npc, buffer));
}

inline bool is_squad_neutral_to_actor(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    return !(is_squad_friend_to_actor(actor, server_npc, buffer) || is_squad_enemy_to_actor(actor, server_npc, buffer));
}

inline bool is_fighting_actor(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    const std::uint16_t& enemy_id = DataBase::Storage::getInstance().getStorage().at(npc->ID()).getEnemyID();
    CScriptGameObject* enemy = DataBase::Storage::getInstance().getStorage().at(enemy_id).getClientObject();

    if (!enemy)
        return false;

    return (enemy->ID() == actor->ID());
}

// Lord: когда будет реализовать hit в DataBase реализовать данную функцию
inline bool is_hit_by_actor(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return false;
}

// Lord: когда будет реализован death в DataBase реализовать данную фунцию
inline bool is_killed_by_actor(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return false;
}

inline bool is_actor_has_weapon(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    CScriptGameObject* active_item = actor->GetActiveItem();

    if (!active_item)
        return false;

    return Globals::IsWeapon(active_item);
}

inline bool is_actor_has_weapon(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    CScriptGameObject* active_item = actor->GetActiveItem();

    if (!active_item)
        return false;

    return Globals::IsWeapon(active_item);
}

inline bool is_actor_active_detector(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    CScriptGameObject* active_detector = DataBase::Storage::getInstance().getActor()->active_detector();

    if (!active_detector)
        return false;

    return (active_detector->Section() == buffer[0]);
}

inline bool is_actor_active_detector(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    CScriptGameObject* active_detector = DataBase::Storage::getInstance().getActor()->active_detector();

    if (!active_detector)
        return false;

    return (active_detector->Section() == buffer[0]);
}

inline bool is_actor_active_detector(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    CScriptGameObject* active_detector = DataBase::Storage::getInstance().getActor()->active_detector();

    if (!active_detector)
        return false;

    return (active_detector->Section() == buffer[0]);
}
// Lord: реализоват когда будет сделан xr_wounded
inline bool is_heavy_wounded(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return false;
}

inline bool is_rain(CScriptGameObject* actor, CScriptGameObject* npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::Game::level::rain_factor() > 0.0f));
}

inline bool is_rain(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::Game::level::rain_factor() > 0.0f));
}

inline bool is_rain(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::Game::level::rain_factor() > 0.0f));
}

inline bool is_heavy_rain(CScriptGameObject* actor, CScriptGameObject* npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::Game::level::rain_factor() > 0.5f));
}

inline bool is_heavy_rain(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::Game::level::rain_factor() > 0.5f));
}

inline bool is_heavy_rain(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::Game::level::rain_factor() > 0.5f));
}

inline bool is_day(CScriptGameObject* actor, CScriptGameObject* npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 6) &&
        (Globals::get_time_hours() < 21));
}

inline bool is_day(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 6) &&
        (Globals::get_time_hours() < 21));
}

inline bool is_day(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 6) &&
        (Globals::get_time_hours() < 21));
}

inline bool is_dark_night(CScriptGameObject* actor, CScriptGameObject* npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() < 3) &&
        (Globals::get_time_hours() > 22));
}

inline bool is_dark_night(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() < 3) &&
        (Globals::get_time_hours() > 22));
}

inline bool is_dark_night(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() < 3) &&
        (Globals::get_time_hours() > 22));
}

inline bool is_jup_a12_mercs_time(CScriptGameObject* actor, CScriptGameObject* npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 1) &&
        (Globals::get_time_hours() < 5));
}

inline bool is_jup_a12_mercs_time(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 1) &&
        (Globals::get_time_hours() < 5));
}

inline bool is_jup_a12_mercs_time(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 1) &&
        (Globals::get_time_hours() < 5));
}

inline bool is_zat_b7_is_night(CScriptGameObject* actor, CScriptGameObject* npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 23) &&
        (Globals::get_time_hours() < 5));
}

inline bool is_zat_b7_is_night(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 23) &&
        (Globals::get_time_hours() < 5));
}

inline bool is_zat_b7_is_night(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 23) &&
        (Globals::get_time_hours() < 5));
}

inline bool is_zat_b7_is_late_attack_time(CScriptGameObject* actor, CScriptGameObject* npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 23) &&
        (Globals::get_time_hours() < 9));
}

inline bool is_zat_b7_is_late_attack_time(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 23) &&
        (Globals::get_time_hours() < 9));
}

inline bool is_zat_b7_is_late_attack_time(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    return (DataBase::Storage::getInstance().getActor() && (Globals::get_time_hours() >= 23) &&
        (Globals::get_time_hours() < 9));
}

inline bool is_mob_has_enemy(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        Msg("[Scripts/XR_CONDITION/is_mob_has_enemy(actor, npc)] WARNING: npc = nullptr! Returns False");
        return false;
    }

    return !!(npc->GetEnemy());
}

inline bool is_mob_was_hit(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        Msg("[Scripts/XR_CONDITION/is_mob_was_hit(actor, npc)] WARNING: npc = nullptr! Returns False");
        return false;
    }

    CScriptMonsterHitInfo hit_info = npc->GetMonsterHitInfo();
    if (hit_info.who && hit_info.time)
    {
        Msg("[Scripts/XR_CONDITION/is_mob_was_hit(actor, npc)] who [%s] time [%d]", hit_info.who->Name(),
            hit_info.time);
        return true;
    }

    return false;
}

inline bool is_actor_on_level(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't empty!");
        return false;
    }

    for (const xr_string& it : buffer)
    {
        if (Globals::Game::level::get_name() == it)
            return true;
    }

    return false;
}

inline bool is_actor_on_level(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't empty!");
        return false;
    }

    for (const xr_string& it : buffer)
    {
        if (Globals::Game::level::get_name() == it)
            return true;
    }

    return false;
}

inline bool is_actor_on_level(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't empty!");
        return false;
    }

    for (const xr_string& it : buffer)
    {
        if (Globals::Game::level::get_name() == it)
            return true;
    }

    return false;
}

inline bool is_squad_in_zone(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    xr_string zone_name = (buffer.size() >= 2 ? buffer[2] : npc->Name());
    Script_SE_SimulationSquad* server_squad = Globals::get_story_squad(story_id_name);

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone(actor, npc, buffer)] WARNING: server_squad = nullptr! Returns "
            "False");
        return false;
    }

    CScriptGameObject* client_zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);
    if (!client_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone(actor, npc, buffer)] WARNING: client_zone = nullptr! Returns "
            "False");
        return false;
    }

    for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        Fvector position = (DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject() ?
                DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject()->Position() :
                it->second->Position());

        if (client_zone->inside(position))
            return true;
    }

    return false;
}

inline bool is_squad_in_zone(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    xr_string zone_name = (buffer.size() >= 2 ? buffer[2] : server_npc->name_replace());
    Script_SE_SimulationSquad* server_squad = Globals::get_story_squad(story_id_name);

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone(actor, npc, buffer)] WARNING: server_squad = nullptr! Returns "
            "False");
        return false;
    }

    CScriptGameObject* client_zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);
    if (!client_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone(actor, npc, buffer)] WARNING: client_zone = nullptr! Returns "
            "False");
        return false;
    }

    for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        Fvector position = (DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject() ?
                DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject()->Position() :
                it->second->Position());

        if (client_zone->inside(position))
            return true;
    }

    return false;
}

// Lord: доделать!!!!!!!!
inline bool is_squad_has_enemy(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];

    Script_SE_SimulationSquad* server_squad = Globals::get_story_squad(story_id_name);

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_has_enemy(actor, npc, buffer)] WARNING: server_squad = nullptr! Returns "
            "False.");
        return false;
    }

    for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        CScriptGameObject* client_object = Globals::Game::level::get_object_by_id(it->second->ID);

        if (!client_object)
        {
            Msg("[Scripts/XR_CONDITION/is_squad_has_enemy(actor, npc, buffer)] WARNING: client_object = nullptr! "
                "Returns False");
            return false;
        }

        if (client_object->GetBestEnemy())
            return true;
    }

    return false;
}

inline bool is_squad_has_enemy(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];

    Script_SE_SimulationSquad* server_squad = Globals::get_story_squad(story_id_name);

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_has_enemy(server_actor, server_npc, buffer)] WARNING: server_squad = "
            "nullptr! Returns "
            "False.");
        return false;
    }

    for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        CScriptGameObject* client_object = Globals::Game::level::get_object_by_id(it->second->ID);

        if (!client_object)
        {
            Msg("[Scripts/XR_CONDITION/is_squad_has_enemy(server_actor, server_npc, buffer)] WARNING: client_object = "
                "nullptr! "
                "Returns False");
            return false;
        }

        if (client_object->GetBestEnemy())
            return true;
    }

    return false;
}

inline bool is_squad_has_enemy(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];

    Script_SE_SimulationSquad* server_squad = Globals::get_story_squad(story_id_name);

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_has_enemy(actor, server_npc, buffer)] WARNING: server_squad = nullptr! "
            "Returns "
            "False.");
        return false;
    }

    for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        CScriptGameObject* client_object = Globals::Game::level::get_object_by_id(it->second->ID);

        if (!client_object)
        {
            Msg("[Scripts/XR_CONDITION/is_squad_has_enemy(actor, server_npc, buffer)] WARNING: client_object = "
                "nullptr! "
                "Returns False");
            return false;
        }

        if (client_object->GetBestEnemy())
            return true;
    }

    return false;
}

inline bool is_squad_in_zone_all(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    const xr_string& zone_name = buffer[1];

    Script_SE_SimulationSquad* server_squad = Globals::get_story_squad(story_id_name);
    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone_all(actor, npc, buffer)] WARNING: server_squad = nullptr! Returns "
            "False");
        return false;
    }

    CScriptGameObject* client_zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);
    if (!client_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone_all(actor, npc, buffer)] WARNING: client_zone = nullptr! Returns "
            "False");
        return false;
    }

    for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        const Fvector& position = (!!DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject()) ?
            DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject()->Position() :
            it->second->Position();

        if (!client_zone->inside(position))
            return false;
    }

    return true;
}

inline bool is_squad_in_zone_all(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    const xr_string& zone_name = buffer[1];

    Script_SE_SimulationSquad* server_squad = Globals::get_story_squad(story_id_name);
    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone_all(server_actor, server_npc, buffer)] WARNING: server_squad = "
            "nullptr! Returns "
            "False");
        return false;
    }

    CScriptGameObject* client_zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);
    if (!client_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone_all(server_actor, server_npc, buffer)] WARNING: client_zone = "
            "nullptr! Returns "
            "False");
        return false;
    }

    for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        const Fvector& position = (!!DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject()) ?
            DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject()->Position() :
            it->second->Position();

        if (!client_zone->inside(position))
            return false;
    }

    return true;
}

inline bool is_squad_in_zone_all(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    const xr_string& zone_name = buffer[1];

    Script_SE_SimulationSquad* server_squad = Globals::get_story_squad(story_id_name);
    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone_all(actor, server_npc, buffer)] WARNING: server_squad = nullptr! "
            "Returns "
            "False");
        return false;
    }

    CScriptGameObject* client_zone = DataBase::Storage::getInstance().getZoneByName().at(zone_name);
    if (!client_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_in_zone_all(actor, server_npc, buffer)] WARNING: client_zone = nullptr! "
            "Returns "
            "False");
        return false;
    }

    for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        const Fvector& position = (!!DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject()) ?
            DataBase::Storage::getInstance().getStorage().at(it->first).getClientObject()->Position() :
            it->second->Position();

        if (!client_zone->inside(position))
            return false;
    }

    return true;
}

inline bool is_squads_in_zone_b41(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    Script_SE_SmartTerrain* server_smart = Script_SimulationBoard::getInstance().getSmartTerrainsByName().at("jup_b41");
    CScriptGameObject* client_zone = DataBase::Storage::getInstance().getZoneByName().at("jup_b41_sr_light");

    if (!client_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_squads_in_zone_b41(actor, npc, buffer)] WARNING: client_zone = nullptr! Returns "
            "False");
        return false;
    }

    if (!server_smart)
    {
        Msg("[Scripts/XR_CONDITION/is_squads_in_zone_b41(actor, npc, buffer)] WARNING: server_smart = nullptr! Returns "
            "False");
        return false;
    }

    if (Script_SimulationBoard::getInstance().getSmarts().at(server_smart->ID).getSquads().size())
    {
        for (std::pair<std::uint32_t, Script_SE_SimulationSquad*> it :
            Script_SimulationBoard::getInstance().getSmarts().at(server_smart->ID).getSquads())
        {
            if (it.second)
            {
                for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator i =
                         it.second->squad_members().begin();
                     i != it.second->squad_members().end(); ++i)
                {
                    if (!client_zone->inside(i->second->Position()))
                        return false;
                }
            }
        }
    }

    return true;
}

inline bool is_squads_in_zone_b41(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    Script_SE_SmartTerrain* server_smart = Script_SimulationBoard::getInstance().getSmartTerrainsByName().at("jup_b41");
    CScriptGameObject* client_zone = DataBase::Storage::getInstance().getZoneByName().at("jup_b41_sr_light");

    if (!client_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_squads_in_zone_b41(server_actor, server_npc, buffer)] WARNING: client_zone = "
            "nullptr! Returns "
            "False");
        return false;
    }

    if (!server_smart)
    {
        Msg("[Scripts/XR_CONDITION/is_squads_in_zone_b41(server_actor, server_npc, buffer)] WARNING: server_smart = "
            "nullptr! Returns "
            "False");
        return false;
    }

    if (Script_SimulationBoard::getInstance().getSmarts().at(server_smart->ID).getSquads().size())
    {
        for (std::pair<std::uint32_t, Script_SE_SimulationSquad*> it :
            Script_SimulationBoard::getInstance().getSmarts().at(server_smart->ID).getSquads())
        {
            if (it.second)
            {
                for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator i =
                         it.second->squad_members().begin();
                     i != it.second->squad_members().end(); ++i)
                {
                    if (!client_zone->inside(i->second->Position()))
                        return false;
                }
            }
        }
    }

    return true;
}

inline bool is_squads_in_zone_b41(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    Script_SE_SmartTerrain* server_smart = Script_SimulationBoard::getInstance().getSmartTerrainsByName().at("jup_b41");
    CScriptGameObject* client_zone = DataBase::Storage::getInstance().getZoneByName().at("jup_b41_sr_light");

    if (!client_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_squads_in_zone_b41(server_actor, server_npc, buffer)] WARNING: client_zone = "
            "nullptr! Returns "
            "False");
        return false;
    }

    if (!server_smart)
    {
        Msg("[Scripts/XR_CONDITION/is_squads_in_zone_b41(server_actor, server_npc, buffer)] WARNING: server_smart = "
            "nullptr! Returns "
            "False");
        return false;
    }

    if (Script_SimulationBoard::getInstance().getSmarts().at(server_smart->ID).getSquads().size())
    {
        for (std::pair<std::uint32_t, Script_SE_SimulationSquad*> it :
            Script_SimulationBoard::getInstance().getSmarts().at(server_smart->ID).getSquads())
        {
            if (it.second)
            {
                for (AssociativeVector<std::uint16_t, CSE_ALifeMonsterAbstract*>::const_iterator i =
                         it.second->squad_members().begin();
                     i != it.second->squad_members().end(); ++i)
                {
                    if (!client_zone->inside(i->second->Position()))
                        return false;
                }
            }
        }
    }

    return true;
}

inline bool is_target_squad_name(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (Globals::IsStalker(server_npc, 0) || Globals::IsMonster(server_npc, 0))
    {
        if (!ai().alife().objects().object(server_npc->cast_monster_abstract()->m_group_id))
            return false;

        if (buffer[0].find(ai().alife().objects().object(server_npc->cast_monster_abstract()->m_group_id)->name()))
            return true;
    }

    return (buffer[0] == server_npc->name());
}

inline bool is_target_squad_name(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    if (Globals::IsStalker(server_npc, 0) || Globals::IsMonster(server_npc, 0))
    {
        if (!ai().alife().objects().object(server_npc->cast_monster_abstract()->m_group_id))
            return false;

        if (buffer[0].find(ai().alife().objects().object(server_npc->cast_monster_abstract()->m_group_id)->name()))
            return true;
    }

    return (buffer[0] == server_npc->name());
}

inline bool is_target_smart_name(CScriptGameObject* actor, CScriptGameObject* smart, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    if (!smart)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    return (buffer[0] == smart->Name());
}

inline bool is_squad_exist(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];

    Script_SE_SimulationSquad* squad = Globals::get_story_squad(story_id_name);

    return (!!squad);
}

inline bool is_squad_exist(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];

    Script_SE_SimulationSquad* squad = Globals::get_story_squad(story_id_name);

    return (!!squad);
}

inline bool is_squad_exist(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't be empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];

    Script_SE_SimulationSquad* squad = Globals::get_story_squad(story_id_name);

    return (!!squad);
}

inline bool is_squad_commander(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    Script_SE_SimulationSquad* squad = Globals::get_object_squad(npc->ID());

    if (squad)
        if (squad->commander_id() == npc->ID())
            return true;

    return false;
}

inline bool is_squad_commander(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    Script_SE_SimulationSquad* squad = Globals::get_object_squad(server_npc->ID);

    if (squad)
        if (squad->commander_id() == server_npc->ID)
            return true;

    return false;
}

inline bool is_squad_commander(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    if (!server_npc)
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    Script_SE_SimulationSquad* squad = Globals::get_object_squad(server_npc->ID);

    if (squad)
        if (squad->commander_id() == server_npc->ID)
            return true;

    return false;
}

inline bool is_squad_npc_count_ge(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    int argument_value = atoi(buffer[1].c_str());

    Script_SE_SimulationSquad* squad = Globals::get_story_squad(story_id_name);

    if (squad)
    {
        return (squad->npc_count() > argument_value);
    }

    return false;
}

inline bool is_squad_npc_count_ge(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    int argument_value = atoi(buffer[1].c_str());

    Script_SE_SimulationSquad* squad = Globals::get_story_squad(story_id_name);

    if (squad)
    {
        return (squad->npc_count() > argument_value);
    }

    return false;
}

inline bool is_squad_npc_count_ge(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list can't empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    int argument_value = atoi(buffer[1].c_str());

    Script_SE_SimulationSquad* squad = Globals::get_story_squad(story_id_name);

    if (squad)
    {
        return (squad->npc_count() > argument_value);
    }

    return false;
}

inline bool is_quest_npc_enemy_actor(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    CScriptGameObject* object = Globals::get_story_object(story_id_name);

    if (!object)
    {
        Msg("[Scripts/XR_CONDITION/is_quest_npc_enemy_actor(actor, npc, buffer)] WARNING: object = nullptr! Returns "
            "False");
    }
    else
    {
        if (Globals::IsStalker(object, 0))
        {
            if (DataBase::Storage::getInstance().getActor())
            {
                if (object->GetAttitude(DataBase::Storage::getInstance().getActor()) <= Globals::kRelationKoeffEnemy)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

inline bool is_quest_npc_enemy_actor(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    CScriptGameObject* object = Globals::get_story_object(story_id_name);

    if (!object)
    {
        Msg("[Scripts/XR_CONDITION/is_quest_npc_enemy_actor(server_actor, server_npc, buffer)] WARNING: object = "
            "nullptr! Returns "
            "False");
    }
    else
    {
        if (Globals::IsStalker(object, 0))
        {
            if (DataBase::Storage::getInstance().getActor())
            {
                if (object->GetAttitude(DataBase::Storage::getInstance().getActor()) <= Globals::kRelationKoeffEnemy)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

inline bool is_quest_npc_enemy_actor(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "object was null!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    CScriptGameObject* object = Globals::get_story_object(story_id_name);

    if (!object)
    {
        Msg("[Scripts/XR_CONDITION/is_quest_npc_enemy_actor(actor, server_npc, buffer)] WARNING: object = nullptr! "
            "Returns "
            "False");
    }
    else
    {
        if (Globals::IsStalker(object, 0))
        {
            if (DataBase::Storage::getInstance().getActor())
            {
                if (object->GetAttitude(DataBase::Storage::getInstance().getActor()) <= Globals::kRelationKoeffEnemy)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

inline bool is_animpoint_reached(CScriptGameObject* actor, CScriptGameObject* npc)
{
    const DataBase::StorageAnimpoint_Data& animpoint_storage =
        DataBase::Storage::getInstance().getStorage().at(npc->ID()).getStorageAnimpoint();
    Script_Animpoint* animpoint = animpoint_storage.getAnimpoint();
    if (!animpoint)
    {
        Msg("[Scripts/XR_CONDITION/is_animpoint_reached(actor, npc)] WARNING: animpoint = nullptr! Returns False");
        return false;
    }

    return animpoint->is_position_riched();
}

inline bool is_distance_to_obj_ge(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "arguemnt buffer can't be empty!");
        return false;
    }
    float comparator = atof(buffer[1].c_str());
    const std::uint16_t& npc_id = Globals::get_story_object_id(buffer[0]);
    if (npc_id)
    {
        CSE_ALifeDynamicObject* server_npc = ai().alife().objects().object(npc_id);

        if (server_npc)
        {
            return DataBase::Storage::getInstance().getActor()->Position().distance_to_sqr(server_npc->Position()) >=
                comparator * comparator;
        }
    }

    return false;
}

inline bool is_distance_to_obj_ge(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "arguemnt buffer can't be empty!");
        return false;
    }
    float comparator = atof(buffer[1].c_str());
    const std::uint16_t& npc_id = Globals::get_story_object_id(buffer[0]);
    if (npc_id)
    {
        CSE_ALifeDynamicObject* server_npc = ai().alife().objects().object(npc_id);

        if (server_npc)
        {
            return DataBase::Storage::getInstance().getActor()->Position().distance_to_sqr(server_npc->Position()) >=
                comparator * comparator;
        }
    }

    return false;
}

inline bool is_distance_to_obj_ge(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "arguemnt buffer can't be empty!");
        return false;
    }
    float comparator = atof(buffer[1].c_str());
    const std::uint16_t& npc_id = Globals::get_story_object_id(buffer[0]);
    if (npc_id)
    {
        CSE_ALifeDynamicObject* server_npc = ai().alife().objects().object(npc_id);

        if (server_npc)
        {
            return DataBase::Storage::getInstance().getActor()->Position().distance_to_sqr(server_npc->Position()) >=
                comparator * comparator;
        }
    }

    return false;
}

inline bool is_distance_to_obj_le(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "arguemnt buffer can't be empty!");
        return false;
    }
    float comparator = atof(buffer[1].c_str());
    const std::uint16_t& npc_id = Globals::get_story_object_id(buffer[0]);
    if (npc_id)
    {
        CSE_ALifeDynamicObject* server_npc = ai().alife().objects().object(npc_id);

        if (server_npc)
        {
            return DataBase::Storage::getInstance().getActor()->Position().distance_to_sqr(server_npc->Position()) >=
                comparator * comparator;
        }
    }

    return false;
}

inline bool is_distance_to_obj_le(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "arguemnt buffer can't be empty!");
        return false;
    }
    float comparator = atof(buffer[1].c_str());
    const std::uint16_t& npc_id = Globals::get_story_object_id(buffer[0]);
    if (npc_id)
    {
        CSE_ALifeDynamicObject* server_npc = ai().alife().objects().object(npc_id);

        if (server_npc)
        {
            return DataBase::Storage::getInstance().getActor()->Position().distance_to_sqr(server_npc->Position()) >=
                comparator * comparator;
        }
    }

    return false;
}

inline bool is_distance_to_obj_le(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "arguemnt buffer can't be empty!");
        return false;
    }
    float comparator = atof(buffer[1].c_str());
    const std::uint16_t& npc_id = Globals::get_story_object_id(buffer[0]);
    if (npc_id)
    {
        CSE_ALifeDynamicObject* server_npc = ai().alife().objects().object(npc_id);

        if (server_npc)
        {
            return DataBase::Storage::getInstance().getActor()->Position().distance_to_sqr(server_npc->Position()) >=
                comparator * comparator;
        }
    }

    return false;
}

inline bool is_in_dest_smart_cover(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->in_smart_cover();
}

/* Lord: NOT USED (check it in game that fact)
inline bool is_active_item(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (buffer.size())
    {
        
    }
}*/

// Lord: наверное лучше всё таки написать под стандарт или всё таки есть перегрузка и под войд?
inline bool is_actor_nomove_nowpn(void)
{
    if (!Globals::IsWeapon(DataBase::Storage::getInstance().getActor()->GetActiveItem()) ||
        DataBase::Storage::getInstance().getActor()->IsTalking())
    {
        return true;
    }

    return false;
}

inline bool is_jup_b16_is_zone_active(CScriptGameObject* actor, CScriptGameObject* npc)
{
    return Globals::has_alife_info(npc->Name());
}

inline bool is_dist_to_story_obj_ge(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument buffer can't be empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    const std::uint16_t& story_obj_id = Globals::get_story_object_id(story_id_name);

    if (!story_obj_id)
        return true;

    CSE_ALifeDynamicObject* server_object = ai().alife().objects().object(story_obj_id);

    if (!server_object)
    {
        Msg("[Scripts/XR_CONDITION/is_dist_to_story_obj_ge(actor, npc, buffer)] WARNING: server_object = nullptr! "
            "Returning false!");
        return false;
    }

    return server_object->Position().distance_to(DataBase::Storage::getInstance().getActor()->Position()) >
        atof(buffer[1].c_str());
}

inline bool is_dist_to_story_obj_ge(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument buffer can't be empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    const std::uint16_t& story_obj_id = Globals::get_story_object_id(story_id_name);

    if (!story_obj_id)
        return true;

    CSE_ALifeDynamicObject* server_object = ai().alife().objects().object(story_obj_id);

    if (!server_object)
    {
        Msg("[Scripts/XR_CONDITION/is_dist_to_story_obj_ge(actor, server_npc, buffer)] WARNING: server_object = "
            "nullptr! "
            "Returning false!");
        return false;
    }

    return server_object->Position().distance_to(DataBase::Storage::getInstance().getActor()->Position()) >
        atof(buffer[1].c_str());
}

inline bool is_dist_to_story_obj_ge(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "Argument buffer can't be empty!");
        return false;
    }

    const xr_string& story_id_name = buffer[0];
    const std::uint16_t& story_obj_id = Globals::get_story_object_id(story_id_name);

    if (!story_obj_id)
        return true;

    CSE_ALifeDynamicObject* server_object = ai().alife().objects().object(story_obj_id);

    if (!server_object)
    {
        Msg("[Scripts/XR_CONDITION/is_dist_to_story_obj_ge(server_actor, server_npc, buffer)] WARNING: server_object = "
            "nullptr! "
            "Returning false!");
        return false;
    }

    return server_object->Position().distance_to(DataBase::Storage::getInstance().getActor()->Position()) >
        atof(buffer[1].c_str());
}

inline bool is_actor_has_nimble_weapon(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    xr_vector<xr_string> weapon_list = {"wpn_groza_nimble", "wpn_desert_eagle_nimble", "wpn_fn2000_nimble",
        "wpn_g36_nimble", "wpn_protecta_nimble", "wpn_mp5_nimble", "wpn_sig220_nimble", "wpn_spas12_nimble",
        "wpn_usp_nimble", "wpn_vintorez_nimble", "wpn_svu_nimble", "wpn_svd_nimble"};

    for (const xr_string& it : weapon_list)
    {
        if (actor->GetObjectByName(it.c_str()))
            return true;
    }

    return false;
}

inline bool is_actor_has_nimble_weapon(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    xr_vector<xr_string> weapon_list = {"wpn_groza_nimble", "wpn_desert_eagle_nimble", "wpn_fn2000_nimble",
        "wpn_g36_nimble", "wpn_protecta_nimble", "wpn_mp5_nimble", "wpn_sig220_nimble", "wpn_spas12_nimble",
        "wpn_usp_nimble", "wpn_vintorez_nimble", "wpn_svu_nimble", "wpn_svd_nimble"};

    for (const xr_string& it : weapon_list)
    {
        if (actor->GetObjectByName(it.c_str()))
            return true;
    }

    return false;
}

// Lord: потестировать std::find правда ли находит?
inline bool is_actor_has_active_nimble_weapon(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    xr_vector<xr_string> weapon_list = {"wpn_groza_nimble", "wpn_desert_eagle_nimble", "wpn_fn2000_nimble",
        "wpn_g36_nimble", "wpn_protecta_nimble", "wpn_mp5_nimble", "wpn_sig220_nimble", "wpn_spas12_nimble",
        "wpn_usp_nimble", "wpn_vintorez_nimble", "wpn_svu_nimble", "wpn_svd_nimble"};

    if (actor->item_in_slot(2) &&
        std::find(weapon_list.begin(), weapon_list.end(), actor->item_in_slot(2)->Section()) != weapon_list.end())
    {
        return true;
    }

    if (actor->item_in_slot(3) &&
        std::find(weapon_list.begin(), weapon_list.end(), actor->item_in_slot(3)->Section()) != weapon_list.end())
    {
        return true;
    }

    return false;
}

inline bool is_actor_has_active_nimble_weapon(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    xr_vector<xr_string> weapon_list = {"wpn_groza_nimble", "wpn_desert_eagle_nimble", "wpn_fn2000_nimble",
        "wpn_g36_nimble", "wpn_protecta_nimble", "wpn_mp5_nimble", "wpn_sig220_nimble", "wpn_spas12_nimble",
        "wpn_usp_nimble", "wpn_vintorez_nimble", "wpn_svu_nimble", "wpn_svd_nimble"};

    if (actor->item_in_slot(2) &&
        std::find(weapon_list.begin(), weapon_list.end(), actor->item_in_slot(2)->Section()) != weapon_list.end())
    {
        return true;
    }

    if (actor->item_in_slot(3) &&
        std::find(weapon_list.begin(), weapon_list.end(), actor->item_in_slot(3)->Section()) != weapon_list.end())
    {
        return true;
    }

    return false;
}

inline bool is_jup_b202_inventory_box_empty(CScriptGameObject* actor, CScriptGameObject* npc)
{
    CScriptGameObject* inventory_box = Globals::get_story_object("jup_b202_actor_treasure");
    return inventory_box->IsInvBoxEmpty();
}

inline bool is_jup_b202_inventory_box_empty(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    CScriptGameObject* inventory_box = Globals::get_story_object("jup_b202_actor_treasure");
    return inventory_box->IsInvBoxEmpty();
}

inline bool is_jup_b202_inventory_box_empty(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    CScriptGameObject* inventory_box = Globals::get_story_object("jup_b202_actor_treasure");
    return inventory_box->IsInvBoxEmpty();
}

inline bool is_object_exist(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer can't be empty!");
        return false;
    }

    return !!Globals::get_story_object(buffer[0]);
}

inline bool is_object_exist(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer can't be empty!");
        return false;
    }

    return !!Globals::get_story_object(buffer[0]);
}

inline bool is_object_exist(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer can't be empty!");
        return false;
    }

    return !!Globals::get_story_object(buffer[0]);
}

inline bool is_squad_curr_action(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer can't be empty!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    Script_SE_SimulationSquad* server_squad = Globals::get_object_squad(npc->ID());

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_curr_action(actor, npc, buffer)] WARNING: server_squad = nullptr! "
            "Returning false!");
        return false;
    }

    return server_squad->getCurrentAction().getName().size() ? server_squad->getCurrentAction().getName() == buffer[0] :
                                                               false;
}

inline bool is_squad_curr_action(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer can't be empty!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    Script_SE_SimulationSquad* server_squad = Globals::get_object_squad(server_npc->ID);

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_curr_action(actor, server_npc, buffer)] WARNING: server_squad = nullptr! "
            "Returning false!");
        return false;
    }

    return server_squad->getCurrentAction().getName().size() ? server_squad->getCurrentAction().getName() == buffer[0] :
                                                               false;
}

inline bool is_squad_curr_action(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer can't be empty!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    Script_SE_SimulationSquad* server_squad = Globals::get_object_squad(server_npc->ID);

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_squad_curr_action(server_actor, server_npc, buffer)] WARNING: server_squad = "
            "nullptr! "
            "Returning false!");
        return false;
    }

    return server_squad->getCurrentAction().getName().size() ? server_squad->getCurrentAction().getName() == buffer[0] :
                                                               false;
}

inline bool is_monster_snork(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->clsid() == CLSID_SE_MONSTER_SNORK;
}

inline bool is_monster_dog(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->clsid() == CLSID_SE_MONSTER_DOG;
}

inline bool is_monster_psy_dog(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->clsid() == CLSID_SE_MONSTER_DOG_PSY;
}

inline bool is_monster_polter(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->clsid() == CLSID_SE_MONSTER_POLTERGEIST;
}

inline bool is_monster_tushkano(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->clsid() == CLSID_SE_MONSTER_TUSHKANO;
}

inline bool is_monster_burer(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->clsid() == CLSID_SE_MONSTER_BURER;
}

inline bool is_monster_controller(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->clsid() == CLSID_SE_MONSTER_CONTROLLER;
}

inline bool is_monster_flesh(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->clsid() == CLSID_SE_MONSTER_FLESH;
}

inline bool is_monster_boar(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    return npc->clsid() == CLSID_SE_MONSTER_BOAR;
}

inline bool is_jup_b47_npc_online(CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer can't be empty!");
        return false;
    }

    CScriptGameObject* story_object = Globals::get_story_object(buffer[0]);

    if (!story_object)
    {
        return false;
    }

    CSE_ALifeDynamicObject* server_object = ai().alife().objects().object(story_object->ID());

    return !!server_object;
}

inline bool is_jup_b47_npc_online(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer can't be empty!");
        return false;
    }

    CScriptGameObject* story_object = Globals::get_story_object(buffer[0]);

    if (!story_object)
    {
        return false;
    }

    CSE_ALifeDynamicObject* server_object = ai().alife().objects().object(story_object->ID());

    return !!server_object;
}

inline bool is_jup_b47_npc_online(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer can't be empty!");
        return false;
    }

    CScriptGameObject* story_object = Globals::get_story_object(buffer[0]);

    if (!story_object)
    {
        return false;
    }

    CSE_ALifeDynamicObject* server_object = ai().alife().objects().object(story_object->ID());

    return !!server_object;
}

inline bool is_zat_b29_anomaly_has_af(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)

{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer is empty!");
        return false;
    }

    const xr_string& anomaly_zone_name = buffer[0];
    // Lord: доделать когда будет сделан bind_anomaly_zone
    CScriptGameObject* anomaly_zone = DataBase::Storage::getInstance().getAnomalyByName().at(anomaly_zone_name);

    if (!anomaly_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_zat_b29_anomaly_has_af(actor, npc, buffer)] anomaly_zone = nullptr! Return "
            "false");
        return false;
    }

    return false;
}

inline bool is_zat_b29_anomaly_has_af(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)

{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer is empty!");
        return false;
    }

    const xr_string& anomaly_zone_name = buffer[0];
    // Lord: доделать когда будет сделан bind_anomaly_zone
    CScriptGameObject* anomaly_zone = DataBase::Storage::getInstance().getAnomalyByName().at(anomaly_zone_name);

    if (!anomaly_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_zat_b29_anomaly_has_af(actor, server_npc, buffer)] anomaly_zone = nullptr! "
            "Return "
            "false");
        return false;
    }

    return false;
}

inline bool is_zat_b29_anomaly_has_af(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)

{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument buffer is empty!");
        return false;
    }

    const xr_string& anomaly_zone_name = buffer[0];
    // Lord: доделать когда будет сделан bind_anomaly_zone
    CScriptGameObject* anomaly_zone = DataBase::Storage::getInstance().getAnomalyByName().at(anomaly_zone_name);

    if (!anomaly_zone)
    {
        Msg("[Scripts/XR_CONDITION/is_zat_b29_anomaly_has_af(server_actor, server_npc, buffer)] anomaly_zone = "
            "nullptr! "
            "Return "
            "false");
        return false;
    }

    return false;
}

inline bool is_jup_b221_who_will_start(
    CScriptGameObject* actor, CScriptGameObject* npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    xr_vector<std::uint16_t> reachable_theme_list;
    std::pair<xr_string, std::uint8_t> faction_pair;

    xr_vector<xr_string> info_list = {"jup_b25_freedom_flint_gone", "jup_b25_flint_blame_done_to_duty",
        "jup_b4_monolith_squad_in_duty", "jup_a6_duty_leader_bunker_guards_work", "jup_a6_duty_leader_employ_work",
        "jup_b207_duty_wins",
        // freedom
        "jup_b207_freedom_know_about_depot", "jup_b46_duty_founder_pda_to_freedom", "jup_b4_monolith_squad_in_freedom",
        "jup_a6_freedom_leader_bunker_guards_work", "jup_a6_freedom_leader_employ_work", "jup_b207_freedom_wins"};

    for (std::uint16_t i = 0; i < info_list.size(); ++i)
    {
        if (i <= 5)
        {
            faction_pair.first = "duty";
            faction_pair.second = 0;
        }
        else
        {
            faction_pair.first = "freedom";
            faction_pair.second = 6;
        }

        xr_string formed_string = "jup_b221_";
        formed_string += faction_pair.first;
        formed_string += "_main_";
        formed_string += std::to_string(i - faction_pair.second);
        formed_string += "_played";
        if (Globals::has_alife_info(info_list[i].c_str()) && (!Globals::has_alife_info(formed_string.c_str())))
        {
            reachable_theme_list.push_back(i);
            Msg("[Scripts/XR_CONDITION/is_jup_b221_who_will_start(actor, npc, buffer)] jup_b221_who_will_start: "
                "reachable_theme %d",
                i);
        }
    }

    if (buffer[0] == "ability")
        return !!reachable_theme_list.size(); // если массив пуст значит нет доступных тем и ненадо играть сцену
    else if (buffer[0] == "choose")
        return reachable_theme_list[Globals::Script_RandomInt::getInstance().Generate(
                   0, reachable_theme_list.size())] <= 6;
    else
        R_ASSERT2(false, "Something goes wrong and it can't be!");
}

inline bool is_jup_b221_who_will_start(
    CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    xr_vector<std::uint16_t> reachable_theme_list;
    std::pair<xr_string, std::uint8_t> faction_pair;

    xr_vector<xr_string> info_list = {"jup_b25_freedom_flint_gone", "jup_b25_flint_blame_done_to_duty",
        "jup_b4_monolith_squad_in_duty", "jup_a6_duty_leader_bunker_guards_work", "jup_a6_duty_leader_employ_work",
        "jup_b207_duty_wins",
        // freedom
        "jup_b207_freedom_know_about_depot", "jup_b46_duty_founder_pda_to_freedom", "jup_b4_monolith_squad_in_freedom",
        "jup_a6_freedom_leader_bunker_guards_work", "jup_a6_freedom_leader_employ_work", "jup_b207_freedom_wins"};

    for (std::uint16_t i = 0; i < info_list.size(); ++i)
    {
        if (i <= 5)
        {
            faction_pair.first = "duty";
            faction_pair.second = 0;
        }
        else
        {
            faction_pair.first = "freedom";
            faction_pair.second = 6;
        }

        xr_string formed_string = "jup_b221_";
        formed_string += faction_pair.first;
        formed_string += "_main_";
        formed_string += std::to_string(i - faction_pair.second);
        formed_string += "_played";
        if (Globals::has_alife_info(info_list[i].c_str()) && (!Globals::has_alife_info(formed_string.c_str())))
        {
            reachable_theme_list.push_back(i);
            Msg("[Scripts/XR_CONDITION/is_jup_b221_who_will_start(actor, server_npc, buffer)] jup_b221_who_will_start: "
                "reachable_theme %d",
                i);
        }
    }

    if (buffer[0] == "ability")
        return !!reachable_theme_list.size(); // если массив пуст значит нет доступных тем и ненадо играть сцену
    else if (buffer[0] == "choose")
        return reachable_theme_list[Globals::Script_RandomInt::getInstance().Generate(
                   0, reachable_theme_list.size())] <= 6;
    else
        R_ASSERT2(false, "Something goes wrong and it can't be!");
}

inline bool is_jup_b221_who_will_start(
    CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc, const xr_vector<xr_string>& buffer)
{
    if (!buffer.size())
    {
        R_ASSERT2(false, "argument list is empty!");
        return false;
    }

    xr_vector<std::uint16_t> reachable_theme_list;
    std::pair<xr_string, std::uint8_t> faction_pair;

    xr_vector<xr_string> info_list = {"jup_b25_freedom_flint_gone", "jup_b25_flint_blame_done_to_duty",
        "jup_b4_monolith_squad_in_duty", "jup_a6_duty_leader_bunker_guards_work", "jup_a6_duty_leader_employ_work",
        "jup_b207_duty_wins",
        // freedom
        "jup_b207_freedom_know_about_depot", "jup_b46_duty_founder_pda_to_freedom", "jup_b4_monolith_squad_in_freedom",
        "jup_a6_freedom_leader_bunker_guards_work", "jup_a6_freedom_leader_employ_work", "jup_b207_freedom_wins"};

    for (std::uint16_t i = 0; i < info_list.size(); ++i)
    {
        if (i <= 5)
        {
            faction_pair.first = "duty";
            faction_pair.second = 0;
        }
        else
        {
            faction_pair.first = "freedom";
            faction_pair.second = 6;
        }

        xr_string formed_string = "jup_b221_";
        formed_string += faction_pair.first;
        formed_string += "_main_";
        formed_string += std::to_string(i - faction_pair.second);
        formed_string += "_played";
        if (Globals::has_alife_info(info_list[i].c_str()) && (!Globals::has_alife_info(formed_string.c_str())))
        {
            reachable_theme_list.push_back(i);
            Msg("[Scripts/XR_CONDITION/is_jup_b221_who_will_start(server_actor, server_npc, buffer)] "
                "jup_b221_who_will_start: "
                "reachable_theme %d",
                i);
        }
    }

    if (buffer[0] == "ability")
        return !!reachable_theme_list.size(); // если массив пуст значит нет доступных тем и ненадо играть сцену
    else if (buffer[0] == "choose")
        return reachable_theme_list[Globals::Script_RandomInt::getInstance().Generate(
                   0, reachable_theme_list.size())] <= 6;
    else
        R_ASSERT2(false, "Something goes wrong and it can't be!");
}

inline bool is_pas_b400_actor_far_forward(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    CScriptGameObject* forward_object = Globals::get_story_object("pas_b400_fwd");

    if (forward_object)
    {
        if (Globals::distance_between(forward_object, DataBase::Storage::getInstance().getActor()) >
            Globals::distance_between(forward_object, npc))
            return false;
    }
    else
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, npc)] WARNING: forward_object = nullptr! "
            "Return false");
        return false;
    }

    float distance = 70.0f * 70.0f;
    float self_distance = npc->Position().distance_to_sqr(actor->Position());

    if (self_distance < distance)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, npc)] self_distance < distance. Return false");
        return false;
    }

    Script_SE_SimulationSquad* server_squad =
        ai().alife()
            .objects()
            .object(ai().alife().objects().object(npc->ID())->cast_monster_abstract()->m_group_id)
            ->cast_script_se_simulationsquad();

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, npc)] WARNING: server_squad = nullptr! Return "
            "false");
        return false;
    }

    for (AssociativeVector<ALife::_OBJECT_ID, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        float other_distance = it->second->Position().distance_to_sqr(actor->Position());

        if (other_distance < distance)
        {
            Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, npc)] other_distance < distance. Return "
                "false");
            return false;
        }
    }

    return true;
}

inline bool is_pas_b400_actor_far_forward(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    CScriptGameObject* forward_object = Globals::get_story_object("pas_b400_fwd");

    if (forward_object)
    {
        if (Globals::distance_between(forward_object, DataBase::Storage::getInstance().getActor()) >
            Globals::distance_between(forward_object, server_npc))
            return false;
    }
    else
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, server_npc)] WARNING: forward_object = nullptr! "
            "Return false");
        return false;
    }

    float distance = 70.0f * 70.0f;
    float self_distance = server_npc->Position().distance_to_sqr(actor->Position());

    if (self_distance < distance)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, server_npc)] self_distance < distance. Return false");
        return false;
    }

    Script_SE_SimulationSquad* server_squad =
        ai().alife()
            .objects()
            .object(ai().alife().objects().object(server_npc->ID)->cast_monster_abstract()->m_group_id)
            ->cast_script_se_simulationsquad();

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, server_npc)] WARNING: server_squad = nullptr! Return "
            "false");
        return false;
    }

    for (AssociativeVector<ALife::_OBJECT_ID, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        float other_distance = it->second->Position().distance_to_sqr(actor->Position());

        if (other_distance < distance)
        {
            Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, server_npc)] other_distance < distance. Return "
                "false");
            return false;
        }
    }

    return true;
}

inline bool is_pas_b400_actor_far_forward(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    if (!server_actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    CScriptGameObject* forward_object = Globals::get_story_object("pas_b400_fwd");

    if (forward_object)
    {
        if (Globals::distance_between(forward_object, DataBase::Storage::getInstance().getActor()) >
            Globals::distance_between(forward_object, server_npc))
            return false;
    }
    else
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(server_actor, server_npc)] WARNING: forward_object = "
            "nullptr! "
            "Return false");
        return false;
    }

    float distance = 70.0f * 70.0f;
    float self_distance = server_npc->Position().distance_to_sqr(server_actor->Position());

    if (self_distance < distance)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(server_actor, server_npc)] self_distance < distance. Return "
            "false");
        return false;
    }

    Script_SE_SimulationSquad* server_squad =
        ai().alife()
            .objects()
            .object(ai().alife().objects().object(server_npc->ID)->cast_monster_abstract()->m_group_id)
            ->cast_script_se_simulationsquad();

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(server_actor, server_npc)] WARNING: server_squad = nullptr! "
            "Return "
            "false");
        return false;
    }

    for (AssociativeVector<ALife::_OBJECT_ID, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        float other_distance = it->second->Position().distance_to_sqr(server_actor->Position());

        if (other_distance < distance)
        {
            Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(server_actor, server_npc)] other_distance < distance. "
                "Return "
                "false");
            return false;
        }
    }

    return true;
}

inline bool is_pas_b400_actor_far_backward(CScriptGameObject* actor, CScriptGameObject* npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    if (!npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    CScriptGameObject* forward_object = Globals::get_story_object("pas_b400_bwd");

    if (forward_object)
    {
        if (Globals::distance_between(forward_object, DataBase::Storage::getInstance().getActor()) >
            Globals::distance_between(forward_object, npc))
            return false;
    }
    else
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, npc)] WARNING: forward_object = nullptr! "
            "Return false");
        return false;
    }

    float distance = 70.0f * 70.0f;
    float self_distance = npc->Position().distance_to_sqr(actor->Position());

    if (self_distance < distance)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, npc)] self_distance < distance. Return false");
        return false;
    }

    Script_SE_SimulationSquad* server_squad =
        ai().alife()
            .objects()
            .object(ai().alife().objects().object(npc->ID())->cast_monster_abstract()->m_group_id)
            ->cast_script_se_simulationsquad();

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, npc)] WARNING: server_squad = nullptr! Return "
            "false");
        return false;
    }

    for (AssociativeVector<ALife::_OBJECT_ID, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        float other_distance = it->second->Position().distance_to_sqr(actor->Position());

        if (other_distance < distance)
        {
            Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, npc)] other_distance < distance. Return "
                "false");
            return false;
        }
    }

    return true;
}

inline bool is_pas_b400_actor_far_backward(CScriptGameObject* actor, CSE_ALifeDynamicObject* server_npc)
{
    if (!actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    CScriptGameObject* forward_object = Globals::get_story_object("pas_b400_bwd");

    if (forward_object)
    {
        if (Globals::distance_between(forward_object, DataBase::Storage::getInstance().getActor()) >
            Globals::distance_between(forward_object, server_npc))
            return false;
    }
    else
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, server_npc)] WARNING: forward_object = "
            "nullptr! "
            "Return false");
        return false;
    }

    float distance = 70.0f * 70.0f;
    float self_distance = server_npc->Position().distance_to_sqr(actor->Position());

    if (self_distance < distance)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, server_npc)] self_distance < distance. Return "
            "false");
        return false;
    }

    Script_SE_SimulationSquad* server_squad =
        ai().alife()
            .objects()
            .object(ai().alife().objects().object(server_npc->ID)->cast_monster_abstract()->m_group_id)
            ->cast_script_se_simulationsquad();

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, server_npc)] WARNING: server_squad = nullptr! "
            "Return "
            "false");
        return false;
    }

    for (AssociativeVector<ALife::_OBJECT_ID, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        float other_distance = it->second->Position().distance_to_sqr(actor->Position());

        if (other_distance < distance)
        {
            Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(actor, server_npc)] other_distance < distance. "
                "Return "
                "false");
            return false;
        }
    }

    return true;
}

inline bool is_pas_b400_actor_far_backward(CSE_ALifeDynamicObject* server_actor, CSE_ALifeDynamicObject* server_npc)
{
    if (!server_actor)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    if (!server_npc)
    {
        R_ASSERT2(false, "object is null!");
        return false;
    }

    CScriptGameObject* forward_object = Globals::get_story_object("pas_b400_bwd");

    if (forward_object)
    {
        if (Globals::distance_between(forward_object, DataBase::Storage::getInstance().getActor()) >
            Globals::distance_between(forward_object, server_npc))
            return false;
    }
    else
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(server_actor, server_npc)] WARNING: forward_object = "
            "nullptr! "
            "Return false");
        return false;
    }

    float distance = 70.0f * 70.0f;
    float self_distance = server_npc->Position().distance_to_sqr(server_actor->Position());

    if (self_distance < distance)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(server_actor, server_npc)] self_distance < distance. "
            "Return "
            "false");
        return false;
    }

    Script_SE_SimulationSquad* server_squad =
        ai().alife()
            .objects()
            .object(ai().alife().objects().object(server_npc->ID)->cast_monster_abstract()->m_group_id)
            ->cast_script_se_simulationsquad();

    if (!server_squad)
    {
        Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(server_actor, server_npc)] WARNING: server_squad = "
            "nullptr! "
            "Return "
            "false");
        return false;
    }

    for (AssociativeVector<ALife::_OBJECT_ID, CSE_ALifeMonsterAbstract*>::const_iterator it =
             server_squad->squad_members().begin();
         it != server_squad->squad_members().end(); ++it)
    {
        float other_distance = it->second->Position().distance_to_sqr(server_actor->Position());

        if (other_distance < distance)
        {
            Msg("[Scripts/XR_CONDITION/is_pas_b400_actor_far_forward(server_actor, server_npc)] other_distance < "
                "distance. "
                "Return "
                "false");
            return false;
        }
    }

    return true;
}

} // namespace XR_CONDITION
} // namespace Scripts
} // namespace Cordis
