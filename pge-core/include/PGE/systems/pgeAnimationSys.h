#pragma once

#include "PGE/utils/pgeLogger.h"
#include "PGE/ecs/pgeEcs.h"
#include "PGE/components/components.h"

namespace pge
{
    namespace ecs
    {
        class AnimationSystem : public System
        {
        public:
            AnimationSystem(ECSCoordinator* coordinator);
            ~AnimationSystem();

            void Init();
            void Update(f32 dt);

        private:
            ECSCoordinator* mCoordinator;

        };
    }
}