#pragma once

#include <SDL2/SDL.h>

namespace pge
{
    inline float getTime()
    {
        float t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }

    struct TSData
    {
        const float timeStep = 0.01f;
        float accumulator = 0.f;
        float currentTime = getTime();
        float deltaTime;
    };
}