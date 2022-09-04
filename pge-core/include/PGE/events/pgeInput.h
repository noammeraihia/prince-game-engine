#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "PGE/utils/pgeLogger.h"
#include "PGE/utils/pgeTypes.h"

namespace pge
{
    namespace kinput
    {
        struct KIData
        {
            const ui8* keyStates;
            i32 mousePosX, mousePosY;
        };

        bool __GetKeyDown(KIData* KID, SDL_Scancode sc);
        void KeyUp(KIData* KID);
        void KeyDown(KIData* KID);

    };
}