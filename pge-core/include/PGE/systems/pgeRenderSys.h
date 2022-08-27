#pragma once

#include "PGE/utils/pgeLogger.h"
#include "PGE/ecs/pgeEcs.h"
#include "PGE/components/components.h"
#include "PGE/graphics/pgeRendererWrapper.h"

namespace pge
{
    namespace ecs
    {
        class RenderSystem : public System
        {
        public:
            RenderSystem(ECSCoordinator* coordinator, graphics::RendererWrapper* renderer);
            ~RenderSystem();

            void Init();
            void Update();

        private:
            ECSCoordinator* mCoordinator;
            graphics::RendererWrapper* mRenderer;

        };
    }
}