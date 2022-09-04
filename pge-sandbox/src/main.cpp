#include <stdio.h>
#include <PGE/pge.h>

#include <glm/glm.hpp>

class Sandbox : public pge::Application
{
public:
    Sandbox()
    {
        
    }

    ~Sandbox()
    {
        _Destroy();
    }

    void Setup()
    {
        mRenderer->SetClearColor(pge::graphics::Color(255, 255, 255, 255));

        mPlayerTexture = new pge::graphics::Texture(pge::graphics::Color(0, 255, 0, 255), "res/gfx/test_bmp/test_character__evil_charlie.bmp", 32, 32, SDL_FLIP_NONE);
        mTexMan->CreateTexture(mRenderer->getHandle(), mPlayerTexture);

        mECS->AddComponent<pge::Sprite>(mPlayer, pge::Sprite{mPlayerTexture, glm::vec2(0.f, 0.f), glm::vec2(32.f, 32.f)});
        mECS->AddComponent<pge::AnimationMachine>(mPlayer, pge::AnimationMachine {});
        mECS->AddComponent<pge::Transform>(mPlayer, pge::Transform{glm::vec2(100.f, 100.f), glm::vec2(4.f), 0.f});

        auto& animMachine = mECS->GetComponent<pge::AnimationMachine>(mPlayer);

        pge::CreateAnimState(&animMachine, "Idle", 0, 4, 1.f);
        pge::CreateAnimState(&animMachine, "Transformation", 4, 10, 1.f);

        animMachine.currentStateName = "Transformation";
    }

    void Run()
    {
        
    }

private:
    pge::graphics::Texture* mPlayerTexture;
    pge::ecs::EntityID mPlayer = mECS->CreateEntity();

};

pge::Application* pge::AppInit()
{
    return new Sandbox();
}