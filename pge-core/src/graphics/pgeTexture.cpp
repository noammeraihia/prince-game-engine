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
            if (!tex->srcImg)
            {
                tex->handle = SDL_CreateTexture(renderer, tex->format, tex->access, tex->width, tex->height);

                SDL_SetRenderTarget(renderer, tex->handle);
                SDL_SetRenderDrawColor(renderer, tex->color.r, tex->color.g, tex->color.b, tex->color.a);
                SDL_RenderClear(renderer);
                SDL_SetRenderTarget(renderer, nullptr);

                return;
            }
            
            tex->handle = SDL_CreateTextureFromSurface(renderer, tex->srcImg);

            allTexturesHandle.emplace_back(tex);
        }

        Texture::Texture() 
        {
            
        }

        Texture::Texture(Color color, const char* srcImgPath, int w, int h, uint32_t format, int access) 
            :color(color), width(w), height(h), format(format), access(access) 
        {
            if (!srcImgPath)
            {
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