#include "PGE/systems/pgePhysicsSys.h"

namespace pge
{
    namespace ecs
    {
        PhysicsSystem::PhysicsSystem(ECSCoordinator* coordinator, float gravity)
        {
            mCoordinator = coordinator;
            mGravity = gravity;
        }

        PhysicsSystem::~PhysicsSystem()
        {
            
        }
    
        void PhysicsSystem::Init()
        {
            Signature signature;
            signature.set(mCoordinator->GetComponentType<RigidbodyCMP>());
            signature.set(mCoordinator->GetComponentType<TransformCMP>());
            mCoordinator->SetSystemSignature<PhysicsSystem>(signature);
        }

        void PhysicsSystem::Update(float dt)
        {
            for (auto& entity : mEntities)
            {
                auto& rbCmp = mCoordinator->GetComponent<RigidbodyCMP>(entity);
                auto& transformCmp = mCoordinator->GetComponent<TransformCMP>(entity);

                if (rbCmp.submittedToGravity)
                {
                    rbCmp.force.y += (mGravity * rbCmp.gravityMultiplier);
                    rbCmp.acceleration.y = rbCmp.force.y / rbCmp.mass;
                }
                else
                    rbCmp.acceleration.y = rbCmp.force.y / rbCmp.mass;

                    
                rbCmp.acceleration.x = rbCmp.force.x / rbCmp.mass;
                
                rbCmp.velocity += rbCmp.acceleration * dt;
                transformCmp.position += rbCmp.velocity * dt;

                rbCmp.velocity *= glm::vec2(1.f) - rbCmp.friction;

                rbCmp.force = glm::vec2(0.f, 0.f);
            }
        }
    }
}