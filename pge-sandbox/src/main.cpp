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

    void SetupECS()
    {
        mECS->RegisterComponent<pge::ecs::SpriteCMP>();
	    mECS->RegisterComponent<pge::ecs::TransformCMP>();
        mECS->RegisterComponent<pge::ecs::RigidbodyCMP>();

        mPhysicsSystem = mECS->RegisterSystem<pge::ecs::PhysicsSystem>(mECS, 90.f);
        mPhysicsSystem->Init();

        mRenderSystem = mECS->RegisterSystem<pge::ecs::RenderSystem>(mECS, mRenderer);
        mRenderSystem->Init();
    }

    void Setup()
    {
        SetupECS();

        mRenderer->SetClearColor(pge::graphics::Color(255, 255, 255, 255));
        mPlayerTexture = new pge::graphics::Texture(pge::graphics::Color(0, 255, 0, 255), "res/gfx/test_bmp/test_character__evil_charlie.bmp", 32, 32, SDL_FLIP_NONE);
        mTexMan->CreateTexture(mRenderer->getHandle(), mPlayerTexture);

        mECS->AddComponent<pge::ecs::SpriteCMP>(mPlayer, pge::ecs::SpriteCMP{mPlayerTexture, glm::vec2(0.f, 0.f), glm::vec2(32.f, 32.f)});;
        mECS->AddComponent<pge::ecs::TransformCMP>(mPlayer, pge::ecs::TransformCMP{glm::vec2(100.f, 100.f), glm::vec2(3.f), 0.f});
        mECS->AddComponent<pge::ecs::RigidbodyCMP>(mPlayer, pge::ecs::RigidbodyCMP{.submittedToGravity = false, .mass = 1.f, .gravityMultiplier = 1.f});
    }

    void Run()
    {
        if (_GetKeyDown(SDL_SCANCODE_D))
        {
            mECS->GetComponent<pge::ecs::RigidbodyCMP>(mPlayer).force.x = 300.f;
        }
        if (_GetKeyDown(SDL_SCANCODE_A))
        {
            mECS->GetComponent<pge::ecs::RigidbodyCMP>(mPlayer).force.x = -300.f;
        }
        if (_GetKeyDown(SDL_SCANCODE_W))
        {
            mECS->GetComponent<pge::ecs::RigidbodyCMP>(mPlayer).force.y = -300.f;
        }
        if (_GetKeyDown(SDL_SCANCODE_S))
        {
            mECS->GetComponent<pge::ecs::RigidbodyCMP>(mPlayer).force.y = 300.f;
        }

        // printf("%f\n", mECS->GetComponent<pge::ecs::RigidbodyCMP>(mPlayer).force.x);

        mPhysicsSystem->Update(_GetDT());
        mRenderSystem->Update();
    }

private:
    std::shared_ptr<pge::ecs::RenderSystem> mRenderSystem;
    std::shared_ptr<pge::ecs::PhysicsSystem> mPhysicsSystem;

    pge::graphics::Texture* mPlayerTexture;
    pge::ecs::EntityID mPlayer = mECS->CreateEntity();

};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}