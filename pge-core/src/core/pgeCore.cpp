#include "PGE/core/pgeCore.h"

namespace pge
{
    namespace core
    {
        i8 Init()
        {
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
            {
                PGE_LOG(PGELLVL_ERROR, "SDL Initialization failed -> \n\t %s", SDL_GetError());
                return -1;
            }

            PGE_LOG(PGELLVL_INFO, "SDL Initialization success");

            return 0;
        }
    }
}