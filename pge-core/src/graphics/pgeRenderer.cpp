#include "PGE/graphics/pgeRendererWrapper.h"

namespace pge 
{ 
    namespace graphics
    {
        RendererWrapper::RendererWrapper()
        {
            
        }

        RendererWrapper::RendererWrapper(SDL_Window* window)
        {
            mHandle = NULL;
            mHandle = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (mHandle == NULL)
            {
                PGE_LOG(PGELLVL_ERROR, "Failed to create renderer");
                return;
            }
            PGE_LOG(PGELLVL_INFO, "Renderer successfuly created");
        }

        RendererWrapper::~RendererWrapper()
        {
            SDL_DestroyRenderer(mHandle);

            PGE_LOG(PGELLVL_INFO, "Renderer has been destroyed");
        }

        void RendererWrapper::ClearScreen()
        {
            SetDrawColor(mClearColor);
            Clear();
        }

        void RendererWrapper::Submit(Texture* tex, glm::vec4 src, glm::vec4 dst, float rotation)
        {
            SDL_Rect _src = {(int)src.x, (int)src.y, (int)src.z, (int)src.w};
            SDL_Rect _dst = {(int)dst.x, (int)dst.y, (int)dst.z, (int)dst.w};

            SetDrawColor(tex->color);
            SDL_RenderCopyEx(mHandle,
                   tex->handle,
                   &_src,
                   &_dst,
                   rotation,
                   NULL,
                   tex->flip);

        }

        void RendererWrapper::Flush()
        {
            SDL_RenderPresent(mHandle);
        }

    }
}