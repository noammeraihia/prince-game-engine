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
            kinput::KIData KID;
            SDL_Event event;
        };

        void Proc(EHData* EHD, bool* isAppRunning);
    };
}