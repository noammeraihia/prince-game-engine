#pragma once

#include <SDL2/SDL.h>

#include <PGE/utils/pgeLogger.h>
#include "PGE/graphics/pgeColor.h"

namespace pge 
{ 
    namespace graphics
    {
        class RendererWrapper
        {
        public:
            RendererWrapper(SDL_Window* window);
            ~RendererWrapper();

            inline SDL_Renderer* getHandle() { return mHandle; } ;
            inline void SetDrawColor(Color color) { SDL_SetRenderDrawColor(mHandle, color.r, color.g, color.b, color.a); }
            inline void SetClearColor(Color color) 
            {
                mClearColor = &color;
                // PGE_LOG(PGELLVL_INFO, "Clear color setted to : %s", mClearColor->AsCStr());
                printf("Clear color setted to : %s\n", mClearColor->AsCStr());
            }

            void Clear();
            void Submit();
            void Flush();

        private:
            SDL_Renderer* mHandle;
            Color* mClearColor;
        };
    }
}