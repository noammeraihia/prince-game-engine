#pragma once

#include <iostream>
#include <bitset>
#include <queue>
#include <array>
#include <unordered_map>

#include "PGE/utils/pgeLogger.h"

namespace pge
{
    namespace ecs
    {


        using EntityID = uint32_t;
        const uint16_t MAX_ENTITIES = 1024;

#define PGE_ECS_ERRCODE 4056
#define PGE_ECS_SUCCESSCODE PGE_ECS_ERRCODE * 2

        using ComponentType = uint8_t;
        const uint8_t MAX_COMPONENTS = 32;

        using EntitySignature = std::bitset<MAX_COMPONENTS>;

        class EntityManager
        {
        public:
            EntityManager();
            ~EntityManager();

            EntityID CreateEntity();
            uint16_t DestroyEntity(EntityID entity);
            uint16_t SetSignature(EntityID entity, EntitySignature signature);
            EntitySignature GetSignature(EntityID entity);

        private:
            std::queue<EntityID> mAvailableEntities{};
            std::array<EntitySignature, MAX_ENTITIES> mSignatures{};

            uint32_t mLivingEntityCount{};
        };

        class IComponentArray
        {
        public:
            virtual ~IComponentArray() = default;
            virtual void EntityDestroyed(EntityID entity) = 0;
        };

        template <typename T>
        class ComponentArray : public IComponentArray
        {
        public:
            uint16_t InsertData(EntityID entity, T component)
            {
                if (mEntityToIndex.find(entity) != mEntityToIndex.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "Component added to same entity (id: %d) more than once", entity);
                    return PGE_ECS_ERRCODE;
                }

                size_t newIndex = mSize;
                mEntityToIndex[entity] = newIndex;
                mIndexToEntity[newIndex] = entity;
                mComponentArray[newIndex] = component;
                ++mSize;

                return PGE_ECS_SUCCESSCODE;
            }

            uint16_t RemoveData(EntityID entity)
            {
                if (mEntityToIndex.find(entity) == mEntityToIndex.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "Removing non-existent component");
                    return PGE_ECS_ERRCODE;
                }

                size_t indexOfRemovedEntity = mEntityToIndex[entity];
                size_t indexOfLastElement = mSize - 1;
                mComponentArray[indexOfRemovedEntity] = mComponentArray[indexOfLastElement];

                EntityID entityOfLastElement = mIndexToEntity[indexOfLastElement];
                mEntityToIndex[entityOfLastElement] = indexOfRemovedEntity;
                mIndexToEntity[indexOfRemovedEntity] = entityOfLastElement;

                mEntityToIndex.erase(entity);
                mIndexToEntity.erase(indexOfLastElement);

                --mSize;

                return PGE_ECS_SUCCESSCODE;
            }

            T& GetData(EntityID entity)
            {
                if (mEntityToIndex.find(entity) == mEntityToIndex.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "Retrieving non-existent component.");
                    T* errDat = NULL;
                    return *errDat;
                }

                return mComponentArray[mEntityToIndex[entity]];
            }

            void EntityDestroyed(EntityID entity) override
            {
                if (mEntityToIndex.find(entity) != mEntityToIndex.end())
                {
                    RemoveData(entity);
                }
            }

        private:
            std::array<T, MAX_ENTITIES> mComponentArray;

            std::unordered_map<EntityID, size_t> mEntityToIndex;
            std::unordered_map<size_t, EntityID> mIndexToEntity;

            size_t mSize;
        };
    }
}