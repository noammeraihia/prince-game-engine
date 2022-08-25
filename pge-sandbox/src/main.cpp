#include <stdio.h>
#include <PGE/pge.h>

#include <glm/glm.hpp>

class Sandbox : public pge::Application
{
public:
    Sandbox()
    : pge::Application()
    {
    }

    ~Sandbox()
    {
        _Destroy();
    }

    void Setup()
    {
        mRenderer->SetClearColor(pge::graphics::Color(255, 255, 255, 255));
        mPlayerTexture = new pge::graphics::Texture(pge::graphics::Color(0, 255, 0, 255), "res/gfx/test_bmp/test_character__evil_charlie.bmp", 32, 32, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET);
        mTexMan->CreateTexture(mRenderer->getHandle(), mPlayerTexture);
    }

    void Run()
    {
        mRenderer->Submit(mPlayerTexture, glm::vec4(0, 0, 32, 32), glm::vec4(100, 100, 128, 128));
    }

private:
    pge::graphics::Texture* mPlayerTexture;

};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}