#include "PGE/graphics/pgeWindow.h"

namespace pge 
{ 
    namespace graphics
    {
        Window::Window()
        {
            mHandle = NULL;
            mHandle = SDL_CreateWindow("PGE Display", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, 0);
            if (mHandle == NULL)
            {
                PGE_LOG(PGELLVL_ERROR, "Failed to create window");
                return;
            }
            PGE_LOG(PGELLVL_INFO, "Window successfuly created");
        }

        Window::~Window()
        {
            SDL_DestroyWindow(mHandle);

            PGE_LOG(PGELLVL_INFO, "Window has been destroyed");
        }

    }
}