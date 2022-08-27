#include "PGE/systems/pgeRenderSys.h"

namespace pge
{
    namespace ecs
    {
        RenderSystem::RenderSystem(ECSCoordinator* coordinator, graphics::RendererWrapper* renderer)
        {
            mCoordinator = coordinator;
            mRenderer = renderer;
        }

        RenderSystem::~RenderSystem()
        {

        }

        void RenderSystem::Init()
        {
            Signature signature;
            signature.set(mCoordinator->GetComponentType<SpriteCMP>());
            signature.set(mCoordinator->GetComponentType<TransformCMP>());
            mCoordinator->SetSystemSignature<RenderSystem>(signature);
        }

        void RenderSystem::Update()
        {
            for (auto& entity : mEntities)
            {
                auto& spriteCmp = mCoordinator->GetComponent<SpriteCMP>(entity);
                auto& transformCmp = mCoordinator->GetComponent<TransformCMP>(entity);

                mRenderer->Submit(spriteCmp.texture, 
                                glm::vec4(spriteCmp.currentFramePosition.x, spriteCmp.currentFramePosition.y, spriteCmp.currentFrameSize.x, spriteCmp.currentFrameSize.y),
                                glm::vec4(transformCmp.position.x, transformCmp.position.y, spriteCmp.texture->width * transformCmp.scale.x, spriteCmp.texture->height * transformCmp.scale.y)
                                );
            }
        }
    }
}