#include "PGE/events/pgeEvent.h"

namespace pge
{
    void ehandler::Proc(EHData* EHD, bool* isAppRunning)
    {
        while (SDL_PollEvent(&EHD->event))
        {
            switch (EHD->event.type)
            {
            case SDL_QUIT:
                PGE_LOG(PGELLVL_INFO, "Quiting...");
                *isAppRunning = false;
                break;

            case SDL_KEYDOWN:
                kinput::KeyDown(&EHD->KID);
                break;

            case SDL_KEYUP:
                kinput::KeyUp(&EHD->KID);
                break;

            default:
                break;
            }
        }
    }
}