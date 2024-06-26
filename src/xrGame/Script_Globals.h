#pragma once

#include "Script_StateManager.h"
#include "Script_CampData.h"

extern bool g_bDisableAllInput;

namespace Cordis
{
namespace Scripts
{
namespace DataBase
{
    class Storage_Data;
}

namespace Globals
{
#pragma region Cordis Custom Datas
/*
struct ReachTarget
{
    std::uint16_t m_squad_id = kUnsignedIntUndefined;
    xr_string m_name = "reach_target";

    inline void Clear(void) noexcept
    {
        this->m_squad_id = kUnsignedIntUndefined;
        this->m_name.clear();
    }

    inline bool update(const bool& is_under_simulation)
    {
        // Lord: нужно ли делать метод cast_to_script_se_simulationsquad в CSE_ALifeDynamicObject
        Script_SE_SimulationSquad* squad = (Script_SE_SimulationSquad*)ai().alife().objects().object(this->m_squad_id);
        Script_SE_SmartTerrain* squad_target =
Script_SimulationObjects::getInstance().getObjects()[squad->getAssignedTargetID()]->cast_script_se_smartterrain();

        if (!squad_target)
        {
            // R_ASSERT2(false, "object was null");
            squad->setAssignedTargetID(0);
            return true;
        }

        if (!is_under_simulation)
            squad_target = ai().alife().objects().object(squad->getAssignedTargetID())->cast_script_se_smartterrain();
    }
};*/

#pragma endregion

namespace Utils
{
inline xr_string cfg_get_string(CScriptIniFile* char_ini, const xr_string& section, const xr_string& field,
    bool mandatory = false, const xr_string& gulag_name = "");
inline xr_string cfg_get_string(const CInifile* char_ini, const xr_string& section, const xr_string& field,
    bool mandatory = false, const xr_string& gulag_name = "");
inline xr_string cfg_get_string(CInifile& char_ini, const xr_string& section, const xr_string& field,
    bool mandatory = false, const xr_string& gulag_name = "");
inline float graph_distance(const std::uint16_t& gamevertexid_1, const std::uint16_t& gamevertexid_2);
inline bool cfg_get_bool(const CInifile* char_ini, const xr_string& section, const xr_string& field,
    CScriptGameObject* object = nullptr, bool mandatory = false);
inline bool cfg_get_bool(const CInifile* char_ini, const xr_string& section, const xr_string& field,
    CSE_ALifeDynamicObject* object, bool mandatory = false);
inline bool cfg_get_bool(CScriptIniFile* char_ini, const xr_string& section, const xr_string& field,
    CScriptGameObject* object = nullptr, bool mandatory = false);
inline bool cfg_get_bool(CScriptIniFile* char_ini, const xr_string& section, const xr_string& field,
    CSE_ALifeDynamicObject* object, bool mandatory = false);
inline float cfg_get_number(const CInifile* char_ini, const xr_string& section, const xr_string& field,
    CScriptGameObject* object = nullptr, bool mandatory = false);
inline float cfg_get_number(const CInifile* char_ini, const xr_string& section, const xr_string& field,
    CSE_ALifeDynamicObject* object, bool mandatory = false);
inline float cfg_get_number(CScriptIniFile* char_ini, const xr_string& section, const xr_string& field,
    CScriptGameObject* object = nullptr, bool mandatory = false);
inline float cfg_get_number(CScriptIniFile* char_ini, const xr_string& section, const xr_string& field,
    CSE_ALifeDynamicObject* object, bool mandatory = false);
inline xr_string get_scheme_by_section(xr_string& data);
inline xr_vector<xr_string> parse_names(const xr_string& buffer);
inline void r_2nums(const CInifile& spawn_ini, const xr_string& section_name, const xr_string& line_name,
    std::uint32_t& number_min, std::uint32_t& number_max);
inline xr_vector<std::pair<xr_string, float>> parse_spawns(const xr_string& buffer);
inline bool is_npc_in_zone(CScriptGameObject* npc, CScriptGameObject* zone);
inline bool is_npc_in_zone(CSE_ALifeDynamicObject* server_object, CScriptGameObject* zone);
inline xrTime r_CTime(NET_Packet& packet);
inline xrTime r_CTime(IReader& packet);
inline void w_CTime(NET_Packet& packet, xrTime& time);
inline CondlistWaypoints::CondlistWayPointsData parse_waypoint_data(
    const xr_string& name, const Flags32& waypoint_flags, const xr_string& waypoint_name);
inline CondlistWaypoints path_parse_waypoints(const xr_string& path_name);
inline CondlistWaypoints path_parse_waypoints_argumentlist(const xr_string& path_name, const std::uint32_t point_count,
    const xr_vector<std::pair<std::uint32_t, xr_string>>& data);
inline bool is_stalker_at_waypoint(
    CScriptGameObject* p_client_object, CPatrolPathParams& patrol_path, const std::uint32_t path_point);
inline xr_vector<xr_string> parse_params(const xr_string& params);
inline std::uint32_t send_to_nearest_accessible_vertex(
    CScriptGameObject* const p_client_object, const std::uint32_t vertex_id);
inline xr_map<std::uint32_t, xr_map<std::uint32_t, CondlistData>> parse_data_1v(
    CScriptGameObject* const p_client_object, const xr_string& buffer_name);
inline xr_map<std::uint32_t, std::tuple<std::uint32_t, xr_map<std::uint32_t, CondlistData>, xr_map<std::uint32_t, CondlistData>>> parse_data(const xr_string& buffer_name);
inline bool vector_cmp_prec(const Fvector& a, const Fvector& b, const float c);
} // namespace Utils

namespace Game
{
inline bool has_active_tutotial(void);
inline void start_tutorial(LPCSTR tutorial_name);
inline void stop_tutorial(void);
inline LPCSTR translate_string(LPCSTR str);
inline LPCSTR translate_string(const xr_string& string);
inline xrTime get_game_time(void) noexcept;
inline const CGameGraph* get_game_graph();
inline CSE_Abstract* alife_create(
    const xr_string& section, const Fvector& position, std::uint32_t level_vertex_id, std::uint16_t game_vertex_id);
inline CSE_Abstract* alife_create(const xr_string& section, const Fvector& position,
    const std::uint32_t level_vertex_id, const std::uint16_t game_vertex_id, const std::uint16_t parent_id);
inline void alife_release(CSE_Abstract* object, bool no_assert = false);
inline xr_string get_squad_relation_to_actor_by_id(const std::uint16_t& squad_id);
inline std::uint32_t time_global(void) noexcept;

namespace level
{
inline Fvector vertex_position(u32 level_vertex_id);
inline bool is_level_present(void);
inline u32 vertex_id(Fvector position);
inline float rain_factor(void);
inline CScriptGameObject* get_object_by_id(u16 id);
inline xr_string get_name(void);
inline void map_remove_object_spot(const std::uint16_t& id, LPCSTR spot_type);
inline void map_add_object_spot(const std::uint16_t& id, LPCSTR spot_type, LPCSTR text);
inline std::uint16_t map_has_object_spot(const std::uint16_t& id, LPCSTR spot_type);
inline void map_add_object_spot_ser(const std::uint16_t& id, LPCSTR spot_type, LPCSTR text);
inline void map_change_spot_hint(const std::uint16_t& id, LPCSTR spot_type, LPCSTR text);
inline void add_pp_effector(LPCSTR fn, int id, bool cyclic);
inline float get_snd_volume(void) noexcept;
inline void set_snd_volume(float v) noexcept;
inline void spawn_phantom(const Fvector& position);
inline void remove_pp_effector(int id);
inline void set_pp_effector_factor(int id, float f, float f_sp);
inline void set_pp_effector_factor(int id, float f);
inline float add_cam_effector(LPCSTR fn, int id, bool cyclic, LPCSTR cb_func);
inline float add_cam_effector2(LPCSTR fn, int id, bool cyclic, LPCSTR cb_func, float cam_fov);
inline void remove_cam_effector(int id);
inline void show_weapon(bool b);
inline void disable_input(void);
inline void enable_input(void);
inline void hide_indicators_safe(void);
inline void show_indicators(void);
inline void add_complex_effector(LPCSTR section, int id);
inline void remove_complex_effector(int id);
inline float get_time_factor(void);
inline LPCSTR get_weather(void);
inline void set_weather(pcstr const weather_name, const bool forced);
inline bool set_weather_fx(pcstr const weather_name);
inline bool is_wfx_playing(void);
inline float get_wfx_time(void);
inline void stop_weather_fx(void);
inline void set_time_factor(const float time_factor);
inline bool start_weather_fx_from_time(pcstr const weather_name, const float time);

} // namespace level

} // namespace Game

namespace GameRelations
{
inline bool check_all_squad_members(const xr_string& squad_name, const xr_string& goodwill_name);
inline int community_goodwill(LPCSTR community_name, int entity_id);
inline int get_community_relation(const xr_string& faction, const xr_string& faction_to);
inline std::uint32_t get_npcs_relation(CScriptGameObject* const p_npc1, CScriptGameObject* const p_npc2);
inline void set_npc_sympathy(CScriptGameObject* npc, float new_sympathy);
inline void set_npcs_relation(
    CScriptGameObject* client_from_object1, CScriptGameObject* client_to_object2, const xr_string& new_relation_name);
inline void set_npcs_relation(
    const std::uint16_t& server_from_object_id, const std::uint16_t& server_to_object_id, xr_string& new_relation_name);
inline void set_npcs_relation(CSE_ALifeMonsterAbstract* server_from_object, CSE_ALifeMonsterAbstract* server_to_object,
    xr_string& new_relation_name);
inline bool is_factions_enemies(const xr_string& faction, const xr_string& faction_to);
inline bool is_factions_friends(const xr_string& faction, const xr_string& faction_to);
inline void set_squad_goodwill(const xr_string& squad_id_name, const xr_string& goodwill_name);
inline void set_squad_goodwill_to_npc(
    CScriptGameObject* const p_npc, const xr_string& squad_id_name, const xr_string& goodwill_name);
inline void change_factions_community_num(const xr_string& community_name, const std::uint16_t npc_id, const int delta);
inline std::uint32_t get_relation_id_by_name(const xr_string& relation_name);
} // namespace GameRelations

inline float distance_between(CScriptGameObject* object1, CScriptGameObject* object2);
inline float distance_between(CScriptGameObject* object1, CSE_ALifeDynamicObject* server_object2);
inline float distance_between(CSE_ALifeDynamicObject* server_object1, CSE_ALifeDynamicObject* server_object2);
inline float distance_between(CSE_ALifeDynamicObject* server_object1, CScriptGameObject* object2);
inline std::uint16_t get_story_object_id(const xr_string& object_id_name);
inline xr_string get_object_story_id(const std::uint16_t object_id);
inline Script_SE_SimulationSquad* get_story_squad(const xr_string& object_id_name);
inline Script_SE_SimulationSquad* get_object_squad(const std::uint16_t& object_id);
inline bool is_npc_in_actor_frustrum(CScriptGameObject* npc);
inline bool is_npc_in_actor_frustrum(CSE_ALifeDynamicObject* server_npc);
inline CScriptGameObject* get_story_object(const xr_string& object_id);
inline int get_script_clsid(const CLASS_ID& clsid);
inline std::uint32_t vertex_in_direction(
    const std::uint32_t& level_vertex_id, const Fvector& direction, const float& max_distance);
inline float yaw(const Fvector& vector1, const Fvector& vector2);
inline float yaw_degree(const Fvector& vector1, const Fvector& vector2);
// @ 2D
inline Fvector vector_cross(const Fvector& vector1, const Fvector& vector2);
inline Fvector vector_rotate_y(Fvector& vector, float& angle);
inline bool patrol_path_exists(LPCSTR patrol_path);
inline void load_sound(void);
inline void init_npc_sound(CScriptGameObject* npc);
inline bool has_alife_info(LPCSTR info_id);
inline bool has_alife_info(const xr_string& info_id_name);
inline int get_general_goodwill_between(const std::uint16_t& from, const std::uint16_t& to);
inline bool check_squad_for_enemies(CSE_ALifeOnlineOfflineGroup* squad);
inline bool IsMonster(CScriptGameObject* object, int class_id);
inline bool IsMonster(CSE_ALifeDynamicObject* server_object, int class_id);
inline bool IsStalker(CScriptGameObject* object, int class_id);
inline bool IsStalker(CSE_ALifeDynamicObject* server_object, int class_id);
inline bool IsArtefact(CScriptGameObject* object, int class_id);
inline bool IsWeapon(CScriptGameObject* object, int class_id = 0);
inline xr_string character_community(CScriptGameObject* object);
inline void change_team_squad_group(CSE_ALifeDynamicObject* server_object, const std::uint8_t& team,
    const std::uint8_t& group, const std::uint8_t& squad);

constexpr const char* kSaveMarkerMode_Save = "save";
constexpr const char* kSaveMarkerMode_Load = "load";

inline bool is_level_present(void);

inline bool is_device_paused(void);

inline void set_device_paused(bool b);

inline const CInifile* get_system_ini(void);

#pragma region Instances
inline static xr_map<xr_string, unsigned int>& SaveMarkers(void) noexcept;
inline static xr_map<xr_string, xr_string>& Schemes(void) noexcept;
inline static xr_map<xr_string, unsigned int>& STypes(void) noexcept;
// @ Uses when parsing condlists
inline static xr_map<xr_string, Cordis::AnyCallable<void>>& getXREffects_Functions(void) noexcept;
#pragma endregion

inline void load_scheme(const xr_string& filename, const xr_string& scheme, unsigned int stype);
inline void start_game_callback(void);
// @ Для тех сущностей, которые мы должны удалить уже после созданной игры
// @ Но при этом они либо в singleton сузностях либо где-то ещё
// @ PRIVATE FUNCTION, DON'T CALL IT AS YOU WISH!!!!
inline void system_deallocation(void);

inline void set_save_marker(NET_Packet& packet, const xr_string& mode, bool check, const xr_string& prefix);
inline void set_save_marker(IReader& packet, const xr_string& mode, bool check, const xr_string& prefix);
// @ from simulation_objects
inline bool is_on_the_same_level(CSE_ALifeObject* object1, CSE_ALifeObject* object2);
inline float sim_dist_to(CSE_ALifeObject* object1, CSE_ALifeObject* object2);
inline ESingleGameDifficulty get_game_difficulty();
inline std::uint32_t get_time_days();
inline std::uint32_t get_time_hours();
inline std::uint32_t get_time_minutes();
inline bool in_time_interval(const std::uint32_t& value1, const std::uint32_t& value2);
inline xr_string get_job_restrictor(const xr_string& waypoint_name);
inline xr_string get_job_restrictor(const char* waypoint_name);
inline bool is_accessible_job(CSE_ALifeDynamicObject* server_object, const xr_string& waypoint_name);
inline bool is_accessible_job(CSE_ALifeDynamicObject* server_object, const char* waypoint_name);
inline CScriptIniFile* create_ini_file(LPCSTR ini_string);
inline std::uint32_t get_time_global(void);
inline void reset_action(CScriptGameObject* client_object, const xr_string& scheme_name);
inline void action(
    CScriptGameObject* client_object, CScriptMovementAction& move_action, CScriptActionCondition& condition_action);
inline void action(CScriptGameObject* client_object, CScriptAnimationAction& animation_actoion,
    CScriptSoundAction& sound_action, CScriptActionCondition& condition_action);
inline void action(CScriptGameObject* client_object, CScriptMovementAction& move_action,
    CScriptAnimationAction& animation_action, CScriptSoundAction& sound_action,
    CScriptActionCondition& condition_action);
inline void action(CScriptGameObject* client_object, CScriptAnimationAction& animation_action,
    CScriptActionCondition& condition_action);
inline void action(CScriptGameObject* p_client_object, CScriptAnimationAction& animation_action,
    CScriptWatchAction& look_action, CScriptActionCondition& condition_action);
inline void action(
    CScriptGameObject* client_object, CScriptMovementAction& move_action, CScriptSoundAction& sound_action);
inline void action(
    CScriptGameObject* p_client_object, CScriptWatchAction& look_action, CScriptActionCondition& condition_action);
inline std::uint32_t choose_look_point(
    CPatrolPathParams* patrol_look, const CondlistWaypoints& path_look_info, const Flags32& search_for);
inline bool is_vector_nil(const Fvector& data);
inline CScriptActionPlanner* get_script_action_planner(CScriptGameObject* obj);
inline CScriptActionPlanner* cast_planner(CScriptActionBase* action);
inline bool is_strappable_weapon(CScriptGameObject* const p_client_object);

// @ Uses in state manager of action of direction
inline bool is_look_object_type(CScriptGameObject* const p_client_object, Script_StateManager* const p_state_manager);
inline void look_at_object(CScriptGameObject* const p_client_object, Script_StateManager* const p_state_manager);
inline std::uint32_t look_position_type(
    CScriptGameObject* const p_client_object, Script_StateManager* const p_state_manager);
inline void turn(CScriptGameObject* const p_client_object, Script_StateManager* const p_state_manager);
// @ Uses in state manager of action of weapon
inline std::uint32_t get_idle_state(const xr_string& target_state_name);
inline CScriptGameObject* const get_weapon(
    CScriptGameObject* const p_client_object, const xr_string& target_state_name);
inline void set_state(CScriptGameObject* const p_client_object, const xr_string& state_name,
    StateManagerCallbackData& callback, const std::uint32_t timeout,
    std::pair<Fvector, CScriptGameObject* const> target, const StateManagerExtraData& extra);
// inline std::uint32_t get_level_id(void);
inline LPCSTR get_level_name(int level_id);
inline void update_logic(CScriptGameObject* const p_object);
inline void change_anomalies_names(void);
inline bool isImportantSave(void);
inline void set_inactivate_input_time(const std::uint32_t delta);
inline xr_map<xr_string, xr_string> parse_ini_section_to_array(
    CScriptIniFile* const p_ini, const xr_string& section_name);
inline void start_surge(void);
inline void stop_surge(void);
inline void change_game_time(std::uint32_t days, std::uint32_t hours, std::uint32_t mins);
inline void stop_play_sound(CScriptGameObject* const p_npc);
inline bool is_npc_in_combat(CScriptGameObject* const p_npc);
#pragma region Cordis State Manager
inline void unstrap_weapon(
    CScriptGameObject* const p_npc, CScriptGameObject* const p_not_used, const xr_vector<xr_string>& not_used);
inline void strap_weapon(
    CScriptGameObject* const p_npc, CScriptGameObject* const p_not_used, const xr_vector<xr_string>& not_used);
inline void lights_off(CScriptGameObject* const p_not_used_1, CScriptGameObject* const p_not_used_2, const xr_vector<xr_string>& not_used);
inline void lights_on(CScriptGameObject* const p_not_used_1, CScriptGameObject* const p_not_used_2, const xr_vector<xr_string>& not_used);
inline void end_scene(
    CScriptGameObject* const p_not_used_1, CScriptGameObject* const p_not_used_2, const xr_vector<xr_string>& not_used);
inline void break_fence(
    CScriptGameObject* const p_not_used_1, CScriptGameObject* const p_not_used_2, const xr_vector<xr_string>& not_used);
#pragma endregion

#pragma region Cordis sr_camp
inline Script_CampData* get_current_camp(const Fvector& position);
inline void start_guitar(CScriptGameObject* const p_npc);
inline void start_harmonica(CScriptGameObject* const p_npc);
#pragma endregion

#pragma region Cordis XR Sleeper
inline bool is_npc_asleep(CScriptGameObject* const p_npc);
#pragma endregion

#pragma region Cordis XR Wounded
inline void unlock_medkit(CScriptGameObject* const p_client_object);
inline bool is_wounded(CScriptGameObject* const p_client_object);
inline void hit_callback(const std::uint16_t npc_id);
inline bool is_heavy_wounded(const std::uint16_t npc_id);
inline bool is_psy_wounded_by_id(const std::uint16_t npc_id);
#pragma endregion

#pragma region Cordis Script_Binder_Campfire
inline void turn_on_campfires_by_smart_name(const xr_string& name);
inline void turn_off_campfires_by_smart_name(const xr_string& name);
#pragma endregion

inline void setup_gulag_and_logic_on_spawn(CScriptGameObject* const p_client_object, const DataBase::Storage_Data& storage, const std::uint16_t stype, const bool loaded);

#pragma region Cordis
inline void load_info(CScriptGameObject* const p_client_object, CScriptIniFile* const p_ini);
#pragma endregion

} // namespace Globals
} // namespace Scripts
} // namespace Cordis
