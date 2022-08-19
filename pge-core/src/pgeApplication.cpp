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
        mTexMan = new graphics::TextureManager();
        
        mEHD = ehandler::EHData();
    }
    
    void Application::_HandleEvents()
    {
        ehandler::Handle(&mEHD, &mIsRunning);
    }

    void Application::_Setup()
    {
        PGE_LOG(pge::PGELLVL_INFO, "App setup started...");
        Setup();
        PGE_LOG(pge::PGELLVL_INFO, "App setup finished...");
    }

    void Application::Setup()
    {
        mRenderer->SetClearColor(pge::graphics::Color(50, 50, 50, 255));
    }

    void Application::Run()
    {
        mRenderer->Clear();
        mRenderer->Flush();
    }

    void Application::_MainLoop()
    {
        _Setup();
        while (mIsRunning)
        {
            _HandleEvents();
            Run();
        }
        SDL_Quit();
    }
}