#pragma once

#include <iostream>

#include "PGE/graphics/pgeWindow.h"
#include "PGE/graphics/pgeRenderer.h"

namespace pge
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Init();
        virtual void Run();

    protected:
        bool mIsRunning;

        graphics::Window* mWindow;
        graphics::Renderer* mRenderer;
    };

    Application* AppInit();
}