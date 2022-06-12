#include <stdio.h>
#include <PGE/pge.h>

#include <glm/glm.hpp>

class Sandbox : public pge::Application
{
public:
    Sandbox()
    {
        _Init();

        vec = glm::vec<2, int>(56, 4);
    }

    ~Sandbox()
    {
        delete mWindow;
    }

    void Run()
    {
        mRenderer->SetClearColor(pge::graphics::Color(255, 21, 45, 255));
        PGE_LOG(pge::PGELLVL_INFO, "VEC2 : [%d, %d]", vec.x, 5);

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
    glm::vec<2, int> vec;

};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}