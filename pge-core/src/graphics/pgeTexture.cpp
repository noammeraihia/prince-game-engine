#include "PGE/graphics/pgeTexture.h"

namespace pge
{
    namespace graphics
    {
        TextureManager::TextureManager() 
        {
            PGE_LOG(PGELLVL_INFO, "Texture Manager successfuly created");
        }
        TextureManager::~TextureManager()
        {
            for (auto tex : allTexturesHandle)
            {
                SDL_DestroyTexture(tex->handle);
                delete tex;
            }

            PGE_LOG(PGELLVL_INFO, "Texture Manager has been destroyed");
        }

        void TextureManager::CreateTexture(SDL_Renderer* renderer, Texture* tex)
        {    
            tex->handle = SDL_CreateTextureFromSurface(renderer, tex->srcImg);

            allTexturesHandle.emplace_back(tex);
        }

        Texture::Texture() 
        {
            
        }

        Texture::Texture(Color color, const char* srcImgPath, int w, int h, SDL_RendererFlip flip) 
            :color(color), width(w), height(h), flip(flip)
        {
            if (!srcImgPath)
            {
                srcImg = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0);
                SDL_FillRect(srcImg, NULL, SDL_MapRGBA(srcImg->format, color.r, color.g, color.b, color.a));
                return;
            }

            srcImg = SDL_LoadBMP(srcImgPath);
            if (!srcImg)
            {
                PGE_LOG(PGELLVL_ERROR, "Surface loading failure...");
            }
        }
    }
}