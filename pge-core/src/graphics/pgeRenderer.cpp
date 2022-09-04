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
            SDL_Rect _src = {(i32)src.x, (i32)src.y, (i32)src.z, (i32)src.w};
            SDL_Rect _dst = {(i32)dst.x, (i32)dst.y, (i32)dst.z, (i32)dst.w};

            SetDrawColor(tex->color);
            SDL_RenderCopyEx(mHandle,
                   tex->handle,
                   &_src,
                   &_dst,
                   rotation,
                   NULL,
                   tex->flip);

        }

        void RendererWrapper::SubmitRect(glm::vec4 rect, Color color)
        {
            SetDrawColor(color);
            SDL_Rect sdlRect = {.x = (i32)rect.x, .y = (i32)rect.y, .w = (i32)rect.z, .h = (i32)rect.w};
            SDL_RenderDrawRect(mHandle, &sdlRect);

        }

        void RendererWrapper::Flush()
        {
            
            SDL_RenderPresent(mHandle);
        }

    }
}