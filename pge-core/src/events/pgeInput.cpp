#include "PGE/events/pgeInput.h"

namespace pge
{
    namespace kinput
    {
        bool __GetKeyDown(KIData* KID, SDL_Scancode sc)
        {
            return (KID->keyStates[sc] == 1);
        }

        void KeyUp(KIData* KID)
        {
            KID->keyStates = SDL_GetKeyboardState(nullptr);
            PGE_LOG(PGELLVL_DEBUG, "Key up");
        }

        void KeyDown(KIData* KID)
        {
            KID->keyStates = SDL_GetKeyboardState(nullptr);
            PGE_LOG(PGELLVL_DEBUG, "Key down");
        }
    }
}