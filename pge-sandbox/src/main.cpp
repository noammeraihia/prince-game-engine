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
        mECS->RegisterComponent<pge::ecs::SpriteCMP>();
	    mECS->RegisterComponent<pge::ecs::TransformCMP>();

        mRenderSystem = mECS->RegisterSystem<pge::ecs::RenderSystem>(mECS, mRenderer);
        mRenderSystem->Init();

        mRenderer->SetClearColor(pge::graphics::Color(255, 255, 255, 255));
        mPlayerTexture = new pge::graphics::Texture(pge::graphics::Color(0, 255, 0, 255), "res/gfx/test_bmp/test_character__evil_charlie.bmp", 32, 32, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET);
        mTexMan->CreateTexture(mRenderer->getHandle(), mPlayerTexture);

        mECS->AddComponent<pge::ecs::SpriteCMP>(mPlayer, pge::ecs::SpriteCMP{mPlayerTexture, glm::vec2(0.f, 0.f), glm::vec2(32.f, 32.f)});;
        mECS->AddComponent<pge::ecs::TransformCMP>(mPlayer, pge::ecs::TransformCMP{glm::vec2(100.f, 0.f), glm::vec2(3.f), 0.f});
    }

    void Run()
    {
        mRenderSystem->Update();

        std::cout << mECS->GetComponent<pge::ecs::TransformCMP>(mPlayer).position.x << std::endl;
    }

private:
    std::shared_ptr<pge::ecs::RenderSystem> mRenderSystem;

    pge::graphics::Texture* mPlayerTexture;
    pge::ecs::EntityID mPlayer = mECS->CreateEntity();

};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}