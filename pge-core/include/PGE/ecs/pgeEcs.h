#pragma once

#include <iostream>
#include <bitset>
#include <queue>
#include <array>

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
    }
}