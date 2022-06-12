#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "PGE/events/pgeInput.h"
#include "PGE/utils/pgeLogger.h"

namespace pge
{
    namespace ehandler
    {
        struct EHData
        {
            EHData()
            {
                KID.keyStates = SDL_GetKeyboardState(nullptr);
            }

            kinput::KIData KID;
            SDL_Event event;

        };

        void Handle(EHData* EHD, bool* isAppRunning);
    };
}