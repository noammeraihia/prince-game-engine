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

        void RendererWrapper::Clear()
        {
            SetDrawColor(*mClearColor);
            SDL_RenderClear(mHandle);
        }

        void RendererWrapper::Submit()
        {
            SDL_RenderCopy(mHandle, NULL, NULL, NULL);
        }

        void RendererWrapper::Flush()
        {
            SDL_RenderPresent(mHandle);
        }

    }
}