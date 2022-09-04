#pragma once

#include <SDL2/SDL.h>

namespace pge
{
    inline f32 getTime()
    {
        f32 t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }

    struct TSData
    {
        const f32 timeStep = 0.01f;
        f32 accumulator = 0.f;
        f32 currentTime = getTime();
        f32 deltaTime;
    };
}