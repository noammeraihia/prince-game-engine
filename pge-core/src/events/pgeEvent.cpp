#include "PGE/events/pgeEvent.h"

namespace pge
{
    namespace ehandler
    {
        void Handle(EHData* EHD, b8* isAppRunning)
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

                case SDL_MOUSEMOTION:
                    SDL_GetGlobalMouseState(&EHD->KID.mousePosX, &EHD->KID.mousePosY);
                    break;

                default:
                    break;
                }
            }
        }
    }
}