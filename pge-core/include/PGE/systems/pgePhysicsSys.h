#pragma once

#include "PGE/utils/pgeLogger.h"
#include "PGE/ecs/pgeEcs.h"
#include "PGE/components/components.h"

namespace pge
{
    namespace ecs
    {
        class PhysicsSystem : public System
        {
        public:
            PhysicsSystem(ECSCoordinator* coordinator, float gravity);
            ~PhysicsSystem();

            void Init();
            void Update(float dt);

        private:
            ECSCoordinator* mCoordinator;
            float mGravity;

        };
    }
}