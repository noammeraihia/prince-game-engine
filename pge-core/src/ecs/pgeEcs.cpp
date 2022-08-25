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
                return PGE_ECS_ERRCODE;
            }

            EntityID e = mAvailableEntities.front();
            mAvailableEntities.pop();
            ++mLivingEntityCount;

            return e;
        }

        uint16_t EntityManager::DestroyEntity(EntityID entity)
        {
            if (entity > MAX_ENTITIES)
            {
                PGE_LOG(PGELLVL_ERROR, "Entity (id: %d) is out of range (max: %d)", entity, MAX_ENTITIES);
                return PGE_ECS_ERRCODE;
            }

            mSignatures[entity].reset();

            mAvailableEntities.push(entity);
            --mLivingEntityCount;

            return PGE_ECS_SUCCESSCODE;
        }

        uint16_t EntityManager::SetSignature(EntityID entity, EntitySignature signature)
        {
            if (entity > MAX_ENTITIES)
            {
                PGE_LOG(PGELLVL_ERROR, "Entity (id: %d) is out of range (max: %d)", entity, MAX_ENTITIES);
                return PGE_ECS_ERRCODE;
            }

            mSignatures[entity] = signature;

            return PGE_ECS_SUCCESSCODE;
        }

        EntitySignature EntityManager::GetSignature(EntityID entity)
        {
            if (entity > MAX_ENTITIES)
            {
                PGE_LOG(PGELLVL_ERROR, "Entity (id: %d) is out of range (max: %d)", entity, MAX_ENTITIES);
                EntitySignature errSign = PGE_ECS_ERRCODE;
                return errSign;
            }

            return mSignatures[entity];
        }
    }
}