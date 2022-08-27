#pragma once

#include <iostream>
#include <memory>
#include <bitset>
#include <queue>
#include <array>
#include <unordered_map>
#include <set>
#include <typeinfo> 

#include "PGE/utils/pgeLogger.h"

namespace pge
{
    namespace ecs
    {
        using EntityID = uint32_t;
        const uint16_t MAX_ENTITIES = 1024;

        using ComponentType = uint8_t;
        const uint8_t MAX_COMPONENTS = 32;

        using Signature = std::bitset<MAX_COMPONENTS>;

        class EntityManager
        {
        public:
            EntityManager();
            ~EntityManager();

            EntityID CreateEntity();
            void DestroyEntity(EntityID entity);
            void SetSignature(EntityID entity, Signature signature);
            Signature GetSignature(EntityID entity);

        private:
            std::queue<EntityID> mAvailableEntities{};
            std::array<Signature, MAX_ENTITIES> mSignatures{};

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
            void InsertData(EntityID entity, T component)
            {
                if (mEntityToIndex.find(entity) != mEntityToIndex.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "Component added to same entity (id: %d) more than once", entity);
                    return;
                }

                size_t newIndex = mSize;
                mEntityToIndex[entity] = newIndex;
                mIndexToEntity[newIndex] = entity;
                mComponentArray[newIndex] = component;
                ++mSize;
            }

            void RemoveData(EntityID entity)
            {
                if (mEntityToIndex.find(entity) == mEntityToIndex.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "Removing non-existent component");
                    return;
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

                return;
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
            std::array<T, MAX_ENTITIES> mComponentArray{};

            std::unordered_map<EntityID, size_t> mEntityToIndex{};
            std::unordered_map<size_t, EntityID> mIndexToEntity{};

            size_t mSize;
        };

        class ComponentManager
        {
        public:
            ComponentManager();
            ~ComponentManager();

            template<typename T>
            void RegisterComponent()
            {
                const char* typeName = typeid(T).name();

                if (mComponentTypes.find(typeName) != mComponentTypes.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "Registering component type more than once");

                    return;
                }
        
                mComponentTypes.insert({typeName, mNextComponentType});
                mComponentArrays.insert({typeName, std::make_shared<ComponentArray<T>>()});

                ++mNextComponentType;

                return;
            }

            template<typename T>
            ComponentType GetComponentType()
            {
                const char* typeName = typeid(T).name();

                if (mComponentTypes.find(typeName) == mComponentTypes.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "(fn -> GetComponentType) Component not registered before use");
                }

                return mComponentTypes[typeName];
            }

            template<typename T>
            void AddComponent(EntityID entity, T component)
            {
                GetComponentArray<T>()->InsertData(entity, component);
            }

            template<typename T>
            void RemoveComponent(EntityID entity)
            {
                GetComponentArray<T>()->RemoveData(entity);
            }

            template<typename T>
            T& GetComponent(EntityID entity)
            {
                return GetComponentArray<T>()->GetData(entity);
            }

            void EntityDestroyed(EntityID entity);

        private:
            std::unordered_map<const char*, ComponentType> mComponentTypes{};
            std::unordered_map<const char*, std::shared_ptr<IComponentArray>> mComponentArrays{};

            ComponentType mNextComponentType{};

            template<typename T>
            std::shared_ptr<ComponentArray<T>> GetComponentArray()
            {
                const char* typeName = typeid(T).name();

                if (mComponentTypes.find(typeName) == mComponentTypes.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "(fn -> GetComponentArray) Component not registered before use");;
                }

                return std::static_pointer_cast<ComponentArray<T>>(mComponentArrays[typeName]);
            }
        };

        class System
        {
        public:
            std::set<EntityID> mEntities;

        };

        class SystemManager
        {
        public:
            SystemManager();
            ~SystemManager();

            template<typename T, typename... TArgs>
            std::shared_ptr<T> RegisterSystem(TArgs&&... mArgs)
            {
                const char* typeName = typeid(T).name();

                if (mSystems.find(typeName) != mSystems.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "Registering system more than once.");
                    std::shared_ptr<T> errSys = NULL;
                    return errSys;
                }

                auto system = std::make_shared<T>(std::forward<TArgs>(mArgs)...);
                mSystems.insert({typeName, system});

                return system;
            }

            template<typename T>
            void SetSignature(Signature signature)
            {
                const char* typeName = typeid(T).name();

                if (mSystems.find(typeName) == mSystems.end())
                {
                    PGE_LOG(PGELLVL_ERROR, "System used before registered.");

                    return;
                }

                mSignatures.insert({typeName, signature});

                return;
            }

            void EntityDestroyed(EntityID entity);
            void EntitySignatureChanged(EntityID entity, Signature signature);

        private:
            std::unordered_map<const char*, Signature> mSignatures{};
            std::unordered_map<const char*, std::shared_ptr<System>> mSystems{};

        };

        class ECSCoordinator
        {
        public:
            ECSCoordinator();
            ~ECSCoordinator();

            EntityID CreateEntity();
            void DestroyEntity(EntityID entity);


            // Component methods
            template<typename T>
            void RegisterComponent()
            {
                mComponentManager->RegisterComponent<T>();
            }

            template<typename T>
            void AddComponent(EntityID entity, T component)
            {
                mComponentManager->AddComponent<T>(entity, component);

                auto signature = mEntityManager->GetSignature(entity);
                signature.set(mComponentManager->GetComponentType<T>(), true);
                mEntityManager->SetSignature(entity, signature);

                mSystemManager->EntitySignatureChanged(entity, signature);
            }

            template<typename T>
            void RemoveComponent(EntityID entity)
            {
                mComponentManager->RemoveComponent<T>(entity);

                auto signature = mEntityManager->GetSignature(entity);
                signature.set(mComponentManager->GetComponentType<T>(), false);
                mEntityManager->SetSignature(entity, signature);

                mSystemManager->EntitySignatureChanged(entity, signature);
            }

            template<typename T>
            T& GetComponent(EntityID entity)
            {
                return mComponentManager->GetComponent<T>(entity);
            }

            template<typename T>
            ComponentType GetComponentType()
            {
                return mComponentManager->GetComponentType<T>();
            }


            // System methods
            template<typename T, typename... TArgs>
            std::shared_ptr<T> RegisterSystem(TArgs&&... mArgs)
            {
                return mSystemManager->RegisterSystem<T>(std::forward<TArgs>(mArgs)...);
            }

            template<typename T>
            void SetSystemSignature(Signature signature)
            {
                mSystemManager->SetSignature<T>(signature);
            }


        private:
            std::unique_ptr<ComponentManager> mComponentManager;
            std::unique_ptr<EntityManager> mEntityManager;
	        std::unique_ptr<SystemManager> mSystemManager;

        };
    }
}