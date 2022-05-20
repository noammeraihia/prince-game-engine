#pragma once

#include <iostream>

namespace pge
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        virtual void Run();
    };

    Application* AppInit();
}