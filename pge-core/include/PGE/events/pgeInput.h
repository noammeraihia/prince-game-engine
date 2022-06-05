#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "PGE/utils/pgeLogger.h"

namespace pge
{
    namespace kinput
    {
        struct KIData
        {
            const uint8_t* keyStates;
        };

        bool __GetKeyDown(KIData* KID, SDL_Scancode sc);
        void KeyUp(KIData* KID);
        void KeyDown(KIData* KID);

    };
}