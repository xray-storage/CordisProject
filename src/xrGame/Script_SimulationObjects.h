#pragma once

namespace Cordis
{
namespace Scripts
{
class Script_SimulationObjects
{
private:
    Script_SimulationObjects(void) {}

public:
    inline static Script_SimulationObjects& getInstance(void) noexcept
    {
        static Script_SimulationObjects instance;
        return instance;
    }

    ~Script_SimulationObjects(void);
    Script_SimulationObjects(const Script_SimulationObjects&) = delete;
    Script_SimulationObjects& operator=(const Script_SimulationObjects&) = delete;
    Script_SimulationObjects(Script_SimulationObjects&&) = delete;
    Script_SimulationObjects& operator=(Script_SimulationObjects&&) = delete;

    float evaluate_priority(CSE_ALifeObject* target, CSE_ALifeObject* squad);

private:
    inline float evaluate_priority_by_distance(CSE_ALifeObject* target, CSE_ALifeObject* squad)
    {
        float distance = Globals::sim_dist_to(target, squad);

        if (distance < 1.0f)
            distance = 1.0f;

        return (1.0f + 1.0f / distance);    
    }
};
} // namespace Scripts
} // namespace Cordis
