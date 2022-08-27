#include "PGE/ecs/pgeEcs.h"

namespace pge
{
    namespace ecs
    {
        EntityManager::EntityManager()
        {
            for (EntityID e = 0; e < MAX_ENTITIES; ++e)
                mAvailableEntities.push(e);
        }

        EntityManager::~EntityManager()
        {

        }

        EntityID EntityManager::CreateEntity()
        {
            if (mLivingEntityCount > MAX_ENTITIES)
            {
                PGE_LOG(PGELLVL_ERROR, "Too many living entities -> %d (max: %d)", mLivingEntityCount, MAX_ENTITIES);
                return 6000;
            }

            EntityID e = mAvailableEntities.front();
            mAvailableEntities.pop();
            ++mLivingEntityCount;

            return e;
        }

        void EntityManager::DestroyEntity(EntityID entity)
        {
            if (entity > MAX_ENTITIES)
            {
                PGE_LOG(PGELLVL_ERROR, "Entity (id: %d) is out of range (max: %d)", entity, MAX_ENTITIES);
                return;
            }

            mSignatures[entity].reset();

            mAvailableEntities.push(entity);
            --mLivingEntityCount;

            return;
        }

        void EntityManager::SetSignature(EntityID entity, Signature signature)
        {
            if (entity > MAX_ENTITIES)
            {
                PGE_LOG(PGELLVL_ERROR, "Entity (id: %d) is out of range (max: %d)", entity, MAX_ENTITIES);
                return;
            }

            mSignatures[entity] = signature;

            return;
        }

        Signature EntityManager::GetSignature(EntityID entity)
        {
            if (entity > MAX_ENTITIES)
            {
                PGE_LOG(PGELLVL_ERROR, "Entity (id: %d) is out of range (max: %d)", entity, MAX_ENTITIES);
                Signature errSign = 4056;
                return errSign;
            }

            return mSignatures[entity];
        }

        ComponentManager::ComponentManager()
        {

        }

        ComponentManager::~ComponentManager()
        {

        }

        void ComponentManager::EntityDestroyed(EntityID entity)
        {
            // Notify each component array that an entity has been destroyed
            // If it has a component for that entity, it will remove it
            for (auto const& pair : mComponentArrays)
            {
                auto const& component = pair.second;

                component->EntityDestroyed(entity);
            }
        }

        SystemManager::SystemManager()
        {

        }

        SystemManager::~SystemManager()
        {

        }

        void SystemManager::EntityDestroyed(EntityID entity)
        {
            for (auto const& pair : mSystems)
            {
                auto const& system = pair.second;

                system->mEntities.erase(entity);
            }
        }

        void SystemManager::EntitySignatureChanged(EntityID entity, Signature signature)
        {
            for (auto const& pair : mSystems)
            {
                auto const& type = pair.first;
                auto const& system = pair.second;
                auto const& systemSignature = mSignatures[type];

                if ((signature & systemSignature) == systemSignature)
                {
                    system->mEntities.insert(entity);
                }
                else
                {
                    system->mEntities.erase(entity);
                }
            }
        }

        ECSCoordinator::ECSCoordinator()
        {
            mComponentManager = std::make_unique<ComponentManager>();
		    mEntityManager = std::make_unique<EntityManager>();
		    mSystemManager = std::make_unique<SystemManager>();
        }

        ECSCoordinator::~ECSCoordinator()
        {

        }

        EntityID ECSCoordinator::CreateEntity()
        {
            return mEntityManager->CreateEntity();
        }

        void ECSCoordinator::DestroyEntity(EntityID entity)
        {
            mEntityManager->DestroyEntity(entity);
            mComponentManager->EntityDestroyed(entity);
            mSystemManager->EntityDestroyed(entity);
        }
    }
}