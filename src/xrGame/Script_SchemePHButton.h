#pragma once

namespace Cordis
{
namespace Scripts
{
class Script_SchemePHButton : public Script_ISchemeEntity
{
    using inherited_scheme = Script_ISchemeEntity;

public:
    Script_SchemePHButton(void) = delete;
    Script_SchemePHButton(CScriptGameObject* const p_client_object, DataBase::Script_ComponentScheme_PHButton* storage);
    ~Script_SchemePHButton(void);

    virtual void reset_scheme(const bool value, CScriptGameObject* const p_client_object);
    virtual void update(const float delta);
    virtual void use_callback(CScriptGameObject* const p_client_object, CScriptGameObject* const p_client_who);
    virtual void hit_callback(CScriptGameObject* p_client_object, const float amount, const Fvector& local_direction,
        CScriptGameObject* p_client_who, const std::int16_t bone_index);

    // @ PRIVATE uses, in XR_LOGIC
    static inline void add_to_binder(CScriptGameObject* const p_client_object, CScriptIniFile* const p_ini,
        const xr_string& scheme_name, const xr_string& section_name, DataBase::Script_IComponentScheme* p_storage)
    {
        if (!p_client_object)
        {
            R_ASSERT2(false, "object is null!");
            return;
        }

        if (!p_ini)
        {
            R_ASSERT2(false, "object is null!");
            return;
        }

        MESSAGEI("added scheme to binder, name=%s scheme=%s section=%s",
            p_client_object->Name(), scheme_name.c_str(), section_name.c_str());

        Script_ISchemeEntity* p_scheme = new Script_SchemePHButton(p_client_object, reinterpret_cast<DataBase::Script_ComponentScheme_PHButton*>(p_storage));

        DataBase::Storage::getInstance().setStorageSchemesActions(p_client_object->ID(), scheme_name, p_scheme);
    }

    // @ PRIVATE, uses in XR_LOGIC
    static void set_scheme(CScriptGameObject* const p_client_object, CScriptIniFile* const p_ini,
        const xr_string& scheme_name, const xr_string& section_name, const xr_string& gulag_name);

private:
    bool try_switch(void);

private:
    std::uint32_t m_last_hit_time;
    DataBase::Script_ComponentScheme_PHButton* m_p_storage;
};
}
} // namespace Cordis

