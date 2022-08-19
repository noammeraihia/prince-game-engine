#include "PGE/graphics/pgeRendererWrapper.h"

namespace pge 
{ 
    namespace graphics
    {
        RendererWrapper::RendererWrapper(SDL_Window* window)
        {
            mHandle = NULL;
            mHandle = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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

        void RendererWrapper::Submit(Texture* tex, glm::vec4 src, glm::vec4 dst)
        {
            SDL_Rect _src = {src.x, src.y, src.z, src.w};
            SDL_Rect _dst = {dst.x, dst.y, dst.z, dst.w};
            SDL_RenderCopy(mHandle, tex->handle, &_src, &_dst);
        }

        void RendererWrapper::Flush()
        {
            SDL_RenderPresent(mHandle);
        }

    }
}