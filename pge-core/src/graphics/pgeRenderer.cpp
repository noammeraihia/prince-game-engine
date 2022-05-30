#include "PGE/graphics/pgeRenderer.h"

namespace pge 
{ 
    namespace graphics
    {
        Renderer::Renderer(SDL_Window* window)
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

        Renderer::~Renderer()
        {
            SDL_DestroyRenderer(mHandle);

            PGE_LOG(PGELLVL_INFO, "Renderer has been destroyed");
        }

        void Renderer::Clear(Color color)
        {
            SetDrawColor(color);
            SDL_RenderClear(mHandle);
        }

        void Renderer::Submit()
        {
            SDL_RenderCopy(mHandle, NULL, NULL, NULL);
        }

        void Renderer::Flush()
        {
            SDL_RenderPresent(mHandle);
        }

    }
}