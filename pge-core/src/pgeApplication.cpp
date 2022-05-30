#include "PGE/pgeApplication.h"

namespace pge 
{
    Application::Application()
        :mIsRunning(true)
    {

    }

    Application::~Application()
    {

    }

    void Application::Init()
    {
        mWindow = new graphics::Window();
        mRenderer = new graphics::Renderer(mWindow->getHandle());
    }

    void Application::Run()
    {
        while(mIsRunning);
    }
}