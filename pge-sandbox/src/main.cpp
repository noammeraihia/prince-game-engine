#include <stdio.h>
#include <PGE/pge.h>

class Sandbox : public pge::Application
{
public:
    Sandbox()
    {
        pge::Logger::Init();
        pge::core::Init();
        Init();
    }

    ~Sandbox()
    {
        delete mWindow;
    }

    void Run()
    {
        while (mIsRunning)
        {
            while (SDL_PollEvent(&mEvent))
            {
                if (mEvent.type == SDL_QUIT)
                {
                    PGE_LOG(pge::PGELLVL_INFO, "Quiting...");
                    mIsRunning = false;
                }
            }
        }

        SDL_Quit();
    }

private:
    SDL_Event mEvent;

};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}