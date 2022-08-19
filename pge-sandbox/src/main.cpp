#include <stdio.h>
#include <PGE/pge.h>

#include <glm/glm.hpp>

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

    void Setup()
    {
        mRenderer->SetClearColor(pge::graphics::Color(255, 255, 255, 255));
        whiteTexture = new pge::graphics::Texture(pge::graphics::Color(0, 255, 0, 255), "res/gfx/test_bmp/test_texture.bmp", 32, 32, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET);
        mTexMan->CreateTexture(mRenderer->getHandle(), whiteTexture);
    }

    void Run()
    {
        if (_GetKeyDown(SDL_SCANCODE_E))
        {
            PGE_LOG(pge::PGELLVL_DEBUG, "E PRESSED !!");
        }

        mRenderer->ClearScreen();
        mRenderer->Submit(whiteTexture, glm::vec4(0, 0, 32, 32), glm::vec4(100, 100, 64, 64));
        mRenderer->Flush();
    }

private:
    pge::graphics::Texture* whiteTexture;

};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}