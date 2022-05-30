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

        private:
            SDL_Window* mHandle;
        };
    }
}