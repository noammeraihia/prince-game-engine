#pragma once

#include <SDL2/SDL.h>

#include <PGE/utils/pgeLogger.h>
#include "PGE/graphics/pgeColor.h"

#include <vector>

namespace pge
{
    namespace graphics
    {
        struct Texture
        {
            Texture();
            Texture(Color color, const char* srcImgPath, int w, int h, SDL_RendererFlip flip);

            SDL_Texture* handle;
            Color color;
            SDL_Surface* srcImg;
            int width, height;
            SDL_RendererFlip flip;
        };
        
        class TextureManager
        {
        public:
            TextureManager();
            ~TextureManager();

            void CreateTexture(SDL_Renderer* renderer, Texture* tex);

        private:
            std::vector<Texture*> allTexturesHandle;

        };

    }
}