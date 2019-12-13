#pragma once

namespace Cordis
{
namespace Scripts
{
/*
class Script_ActionStateManager : public CScriptActionBase
{
public:
    Script_ActionStateManager(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManager(void) {}

    virtual void initialize(void) { CScriptActionBase::initialize(); }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void)
    { CScriptActionBase::finalize();
    }

private:
    Script_StateManager* m_p_state_manager;
};
*/
#pragma region Cordis State Manager Actions about state manager
class Script_ActionStateManagerEnd : public CScriptActionBase
{
public:
    Script_ActionStateManagerEnd(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerEnd(void) {}
    virtual void initialize(void) { CScriptActionBase::initialize(); }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerLocked : public CScriptActionBase
{
public:
    Script_ActionStateManagerLocked(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerLocked(void) {}

    virtual void initialize(void) { CScriptActionBase::initialize(); }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};
#pragma endregion

#pragma region Cordis State Manager Actions about animations
class Script_ActionStateManagerAnimationStart : public CScriptActionBase
{
public:
    Script_ActionStateManagerAnimationStart(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerAnimationStart(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        // Lord: доделать когда будет state_mgr.animation
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerAnimationStop : public CScriptActionBase
{
public:
    Script_ActionStateManagerAnimationStop(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerAnimationStop(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        // Lord: доделать когда будет state_mgr.animation
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};
#pragma endregion

#pragma region Cordis State Manager Actions about animstate
class Script_ActionStateManagerAnimStateStart : public CScriptActionBase
{
public:
    Script_ActionStateManagerAnimStateStart(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerAnimStateStart(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        // Lord: доделать когда будет state_mgr.animstate
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerAnimStateStop : public CScriptActionBase
{
public:
    Script_ActionStateManagerAnimStateStop(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerAnimStateStop(void) {}

    virtual void initialize(void) { CScriptActionBase::initialize(); }

    virtual void execute(void)
    {
        CScriptActionBase::execute();
        // Lord: доделать когда будет state_mgr.animstate
    }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};
#pragma endregion

#pragma region Cordis State Manager Actions about bodystate
class Script_ActionStateManagerBodyStateCrouch : public CScriptActionBase
{
public:
    Script_ActionStateManagerBodyStateCrouch(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerBodyStateCrouch(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_body_state(eBodyStateCrouch);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerBodyStateStanding : public CScriptActionBase
{
public:
    Script_ActionStateManagerBodyStateStanding(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerBodyStateStanding(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_body_state(eBodyStateStand);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerBodyStateCrouchDanger : public CScriptActionBase
{
public:
    Script_ActionStateManagerBodyStateCrouchDanger(
        const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerBodyStateCrouchDanger(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_mental_state(eMentalStateDanger);
        this->m_object->set_body_state(eBodyStateCrouch);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerBodyStateStandingFree : public CScriptActionBase
{
public:
    Script_ActionStateManagerBodyStateStandingFree(
        const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerBodyStateStandingFree(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_body_state(eBodyStateStand);
        this->m_object->set_mental_state(eMentalStateFree);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};
#pragma endregion

#pragma region Cordis State Manager Actions about direction
class Script_ActionStateManagerDirectionTurn : public CScriptActionBase
{
public:
    Script_ActionStateManagerDirectionTurn(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerDirectionTurn(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->turn();
    }

    virtual void execute(void)
    {
        CScriptActionBase::execute();
        this->turn();
    }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    inline void turn(void)
    {
        this->m_p_state_manager->setPointObjectDirection(
            Globals::is_look_object_type(this->m_object, this->m_p_state_manager));

        if (this->m_p_state_manager->getLookObject() &&
            Globals::Game::level::get_object_by_id(this->m_p_state_manager->getLookObject()->ID()))
        {
            Globals::look_at_object(this->m_object, this->m_p_state_manager);
        }
        else if (!Globals::is_vector_nil(this->m_p_state_manager->getLookPosition()))
        {
            if (Script_GlobalHelper::getInstance()
                    .getStateLibrary()
                    .at(this->m_p_state_manager->getTargetStateName())
                    .getDirectionType())
            {
                this->m_object->set_sight(SightManager::eSightTypeAnimationDirection, false, false);
                return;
            }

            Fvector direction = Fvector().sub(this->m_p_state_manager->getLookPosition(), this->m_object->Position());
            if (this->m_p_state_manager->isPointObjectDirection())
                direction.y = 0.0f;

            direction.normalize();
            if (Globals::is_vector_nil(direction))
            {
                Msg("[Scripts/Script_ActionStateManagerDirectionTurn/turn()] WARNINIG: you are trying to set wrong "
                    "direction");
                this->m_p_state_manager->setLookPosition(
                    Fvector().set((this->m_object->Position().x + this->m_object->Direction().x),
                        (this->m_object->Position().y + this->m_object->Direction().y),
                        (this->m_object->Position().z + this->m_object->Direction().z)));
                direction = this->m_object->Direction();
            }

            this->m_object->set_sight(SightManager::eSightTypeDirection, direction, true);
        }
    }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerDirectionSearch : public CScriptActionBase
{
public:
    Script_ActionStateManagerDirectionSearch(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerDirectionSearch(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        if (Script_GlobalHelper::getInstance()
                .getStateLibrary()
                .at(this->m_p_state_manager->getTargetStateName())
                .getDirectionType() &&
            Script_GlobalHelper::getInstance()
                    .getStateLibrary()
                    .at(this->m_p_state_manager->getTargetStateName())
                    .getDirectionType() == SightManager::eSightTypeAnimationDirection)
        {
            this->m_object->set_sight(SightManager::eSightTypeAnimationDirection, false, false);
        }
        else
        {
            this->m_object->set_sight(static_cast<SightManager::ESightType>(
                                          Globals::look_position_type(this->m_object, this->m_p_state_manager)),
                nullptr, std::uint32_t(0));
        }
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};
#pragma endregion

#pragma region Cordis State Manager Actions about mental
class Script_ActionStateManagerMentalFree : public CScriptActionBase
{
public:
    Script_ActionStateManagerMentalFree(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMentalFree(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_mental_state(eMentalStateFree);
    }

    virtual void execute(void)
    {
        CScriptActionBase::execute();
        this->m_object->set_mental_state(eMentalStateFree);
    }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMentalDanger : public CScriptActionBase
{
public:
    Script_ActionStateManagerMentalDanger(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMentalDanger(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_mental_state(eMentalStateDanger);
    }

    virtual void execute(void)
    {
        CScriptActionBase::execute();
        this->m_object->set_mental_state(eMentalStateDanger);
    }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMentalPanic : public CScriptActionBase
{
public:
    Script_ActionStateManagerMentalPanic(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMentalPanic(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_mental_state(eMentalStatePanic);
    }

    virtual void execute(void)
    {
        CScriptActionBase::execute();
        this->m_object->set_mental_state(eMentalStatePanic);
    }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};
#pragma endregion

#pragma region Cordis State Manager Actions about movement
class Script_ActionStateManagerMovementWalk : public CScriptActionBase
{
public:
    Script_ActionStateManagerMovementWalk(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMovementWalk(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_movement_type(eMovementTypeWalk);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMovementRun : public CScriptActionBase
{
public:
    Script_ActionStateManagerMovementRun(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMovementRun(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_movement_type(eMovementTypeRun);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMovementStand : public CScriptActionBase
{
public:
    Script_ActionStateManagerMovementStand(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMovementStand(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_movement_type(eMovementTypeStand);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMovementStandTurn : public CScriptActionBase
{
public:
    Script_ActionStateManagerMovementStandTurn(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMovementStandTurn(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        Globals::turn(this->m_object, this->m_p_state_manager);
        this->m_object->set_movement_type(eMovementTypeStand);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMovementStandSearch : public CScriptActionBase
{
public:
    Script_ActionStateManagerMovementStandSearch(
        const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMovementStandSearch(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_movement_type(eMovementTypeStand);
        this->m_object->set_sight(
            static_cast<SightManager::ESightType>(Globals::look_position_type(this->m_object, this->m_p_state_manager)),
            nullptr, std::uint32_t(0));
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMovementWalkTurn : public CScriptActionBase
{
public:
    Script_ActionStateManagerMovementWalkTurn(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMovementWalkTurn(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_movement_type(eMovementTypeWalk);
        Globals::turn(this->m_object, this->m_p_state_manager);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMovementWalkSearch : public CScriptActionBase
{
public:
    Script_ActionStateManagerMovementWalkSearch(
        const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMovementWalkSearch(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_movement_type(eMovementTypeWalk);
        this->m_object->set_sight(
            static_cast<SightManager::ESightType>(Globals::look_position_type(this->m_object, this->m_p_state_manager)),
            nullptr, std::uint32_t(0));
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMovementRunTurn : public CScriptActionBase
{
public:
    Script_ActionStateManagerMovementRunTurn(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMovementRunTurn(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_movement_type(eMovementTypeRun);
        Globals::turn(this->m_object, this->m_p_state_manager);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerMovementRunSearch : public CScriptActionBase
{
public:
    Script_ActionStateManagerMovementRunSearch(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerMovementRunSearch(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_movement_type(eMovementTypeRun);
        this->m_object->set_sight(
            static_cast<SightManager::ESightType>(Globals::look_position_type(this->m_object, this->m_p_state_manager)),
            nullptr, std::uint32_t(0));
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};
#pragma endregion

#pragma region Cordis State Manager Actions about weapon
class Script_ActionStateManagerWeaponUnStrapp : public CScriptActionBase
{
public:
    Script_ActionStateManagerWeaponUnStrapp(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerWeaponUnStrapp(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_item(static_cast<MonsterSpace::EObjectAction>(
                                     Globals::get_idle_state(this->m_p_state_manager->getTargetStateName())),
            Globals::get_weapon(this->m_object, this->m_p_state_manager->getTargetStateName()));
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerWeaponStrapp : public CScriptActionBase
{
public:
    Script_ActionStateManagerWeaponStrapp(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerWeaponStrapp(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        CScriptGameObject* const p_client_item =
            Globals::get_weapon(this->m_object, this->m_p_state_manager->getTargetStateName());

        if (Globals::is_strappable_weapon(p_client_item))
            this->m_object->set_item(MonsterSpace::eObjectActionStrapped, p_client_item);
        else
            this->m_object->set_item(MonsterSpace::eObjectActionIdle, nullptr);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerWeaponNone : public CScriptActionBase
{
public:
    Script_ActionStateManagerWeaponNone(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerWeaponNone(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        this->m_object->set_item(MonsterSpace::eObjectActionIdle, nullptr);
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};

class Script_ActionStateManagerWeaponDrop : public CScriptActionBase
{
public:
    Script_ActionStateManagerWeaponDrop(const xr_string& action_name, Script_StateManager* const p_state_manager)
        : CScriptActionBase(nullptr, action_name.c_str()), m_p_state_manager(p_state_manager)
    {
    }
    ~Script_ActionStateManagerWeaponDrop(void) {}

    virtual void initialize(void)
    {
        CScriptActionBase::initialize();
        CScriptGameObject* const p_client_item = Globals::get_weapon(this->m_object, this->m_p_state_manager->getTargetStateName());

        if (Globals::is_strappable_weapon(p_client_item))
        {
            this->m_object->set_item(MonsterSpace::eObjectActionDrop, p_client_item);
            // Lord: доделать когда будет death_manager, а так пока что можно тестировать на запуск схеи!
        }
        else
        {
            this->m_object->set_item(MonsterSpace::eObjectActionIdle, nullptr);
        }
    }

    virtual void execute(void) { CScriptActionBase::execute(); }

    virtual void finalize(void) { CScriptActionBase::finalize(); }

private:
    Script_StateManager* m_p_state_manager;
};
#pragma endregion
} // namespace Scripts
} // namespace Cordis
