#pragma once

#include <iostream>
#include <SDL2/SDL.h>

#include "PGE/events/pgeInput.h"

#include "PGE/utils/pgeLogger.h"
#include "PGE/utils/pgeTypes.h"

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

        void Handle(EHData* EHD, b8* isAppRunning);
    };
}