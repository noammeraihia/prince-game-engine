#pragma once

#include <iostream>

#include "PGE/graphics/pgeWindow.h"

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
    };

    Application* AppInit();
}