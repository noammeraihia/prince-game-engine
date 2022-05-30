#pragma once

#include <SDL2/SDL.h>

#include <PGE/utils/pgeLogger.h>
#include "PGE/graphics/pgeColor.h"

namespace pge 
{ 
    namespace graphics
    {
        class Renderer
        {
        public:
            Renderer(SDL_Window* window);
            ~Renderer();

            inline SDL_Renderer* getHandle() { return mHandle; } ;
            inline void SetDrawColor(Color color) { SDL_SetRenderDrawColor(mHandle, color.r, color.g, color.b, color.a); }

            void Clear(Color color);
            void Submit();
            void Flush();

        private:
            SDL_Renderer* mHandle;
        };
    }
}