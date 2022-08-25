// #pragma once

// #include "PGE/utils/pgeLogger.h"
// #include "PGE/ecs/pgeEcs.h"

// #include <glm/glm.hpp>
// #include <glm/ext.hpp>

// #include "PGE/components/pgePosition.h"

// namespace pge
// {
//     class TransformCMP : public ecs::Component
//     {
//     public:
//         TransformCMP();
//         ~TransformCMP();

//         void Init() override;
//         void Update() override;

//         inline glm::vec3 getTransform() { return mTransform; }
//         void setTransformX(float transX);
//         void setTransformY(float transX);
//         void setTransformRot(float transRot);
        
//     private:
//         PositionCMP& mParentPosition = pParent->getCmp<PositionCMP>();
//         glm::vec3 mTransform;
        
//     };
// }