#pragma once

#include <iostream>
#include <map>

#include "PGE/utils/pgeLogger.h"
#include "PGE/utils/pgeTypes.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace pge
{
    struct AnimationState
    {
        ui16 frameStart;
        ui16 frameEnd;
        ui16 frameCount;
        f32 currentFrameF;
        ui16 currentFrame;
        f32 speed;
        const char* name;
    };

    struct AnimationMachine
    {
        std::map<const char*, AnimationState> statesMap;
        const char* currentStateName;
        AnimationState* currentState;
    };

    inline void CreateAnimState(AnimationMachine* animMach, const char* name, ui16 fStart, ui16 fEnd, f32 speed)
    {
        AnimationState state = {
            fStart, fEnd, (ui16)(fEnd - fStart), 0.f, 0, speed, name
        };

        animMach->statesMap.insert(std::pair<const char*, AnimationState>(name, state));
    }
}