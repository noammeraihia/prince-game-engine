#pragma once

#include <SDL2/SDL.h>

#include <PGE/utils/pgeLogger.h>

namespace pge 
{ 
    namespace graphics
    {
        class Window
        {
        public:
            Window();
            ~Window();

            inline SDL_Window* getHandle() { return mHandle; } ;

        private:
            SDL_Window* mHandle;
        };
    }
}