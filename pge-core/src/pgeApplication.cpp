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

    void Application::_Init()
    {
        Logger::Init();
        core::Init();
        mWindow = new graphics::Window();
        mRenderer = new graphics::RendererWrapper(mWindow->getHandle());
    }
    
    void Application::_HandleEvents()
    {
        ehandler::Proc(&mEHD, &mIsRunning);
    }

    void Application::Run()
    {
        while(mIsRunning)
        {
            _HandleEvents();

            mRenderer->Clear();
            mRenderer->Flush();
        }
    }
}