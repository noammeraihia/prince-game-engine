#include "PGE/pgeApplication.h"

namespace pge 
{
    Application::Application()
    {
        mIsRunning = true;

        Logger::Init();
        core::Init();
        mWindow = new graphics::Window();
        mRenderer = new graphics::RendererWrapper(mWindow->getHandle());
        mTexMan = new graphics::TextureManager();
        mECS = new ecs::ECSCoordinator();
        mEHD = ehandler::EHData();
    }

    Application::~Application()
    {
        
    }

    void Application::_Destroy()
    {
        delete mECS;
        delete mTexMan;
        delete mRenderer;
        delete mWindow;
    }
    
    void Application::_HandleEvents()
    {
        ehandler::Handle(&mEHD, &mIsRunning);
    }

    void Application::Setup()
    {
        mRenderer->SetClearColor(pge::graphics::Color(50, 50, 50, 255));
    }

    void Application::Run()
    {
        
    }

    void Application::_MainLoop()
    {
        Setup();
        while (mIsRunning)
        {
            _HandleEvents();
            mRenderer->ClearScreen();
            Run();
            mRenderer->Flush();
        }
        SDL_Quit();
    }
}