#include "PGE/pgeCore.h"
#include <SDL.h>

namespace pge
{
    namespace core
    {
        void InitDeps()
        {
            if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
            {
                std::cout << "[PGE] SDL Initialization succeed !" << std::endl;
                return;
            }
            
            std::cout << "[PGE] SDL initialization failed !" << std::endl;
        }
    }
}