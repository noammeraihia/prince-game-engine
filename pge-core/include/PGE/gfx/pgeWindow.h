#pragma once
#include <iostream>
#include <SDL2/SDL.h>

namespace pge
{
    namespace gfx
    {
        struct WindowProps
        {
            WindowProps(int w, int h, const char* t);
            ~WindowProps();

            int width;
            int height;
            const char* title;

        };
        
        class Window 
        {
        public:    
            Window(struct WindowProps props);
            ~Window();

            void Init();

        private:
            SDL_Window* mHandle;
            SDL_Renderer* mRenderer;
            WindowProps mProps;

        };
    };
}