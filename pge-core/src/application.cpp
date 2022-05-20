#include "PGE/application.h"

namespace pge 
{
    Application::Application()
    {

    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        while(true)
        {
            std::cout << "elkne World!" << std::endl;
        }
    }
}