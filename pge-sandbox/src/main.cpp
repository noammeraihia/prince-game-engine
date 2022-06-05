#include <stdio.h>
#include <PGE/pge.h>

class Sandbox : public pge::Application
{
public:
    Sandbox()
    {
        _Init();
    }

    ~Sandbox()
    {
        delete mWindow;
    }

    void Run()
    {
        mRenderer->SetClearColor(pge::graphics::Color(255, 21, 45, 255));

        while(mIsRunning)
        {
            _HandleEvents();

            if (_GetKeyDown(SDL_SCANCODE_E))
            {
                PGE_LOG(pge::PGELLVL_DEBUG, "E PRESSED !!");
            }

            mRenderer->Clear();
            mRenderer->Flush();
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