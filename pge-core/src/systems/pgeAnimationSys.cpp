#include "PGE/systems/pgeAnimationSys.h"

namespace pge
{
    namespace ecs
    {
        AnimationSystem::AnimationSystem(ECSCoordinator* coordinator)
        {
            mCoordinator = coordinator;
        }

        AnimationSystem::~AnimationSystem()
        {

        }

        void AnimationSystem::Init()
        {
            Signature signature;
            signature.set(mCoordinator->GetComponentType<Sprite>());
            signature.set(mCoordinator->GetComponentType<AnimationMachine>());
            mCoordinator->SetSystemSignature<AnimationSystem>(signature);
        }

        void AnimationSystem::Update(f32 dt)
        {
            for (auto& entity : mEntities)
            {
                auto& spriteCmp = mCoordinator->GetComponent<Sprite>(entity);
                auto& animCmp = mCoordinator->GetComponent<AnimationMachine>(entity);

                animCmp.currentState = &animCmp.statesMap.at(animCmp.currentStateName);

                animCmp.currentState->currentFrameF += 1.f * animCmp.currentState->speed * dt;
                animCmp.currentState->currentFrame = ((int)animCmp.currentState->currentFrameF % animCmp.currentState->frameCount);

                printf("current frame: %d\n", animCmp.currentState->currentFrame);

                spriteCmp.currentFramePosition.x = animCmp.currentState->currentFrame * spriteCmp.currentFrameSize.x;
            }
        }
    }
}