// #pragma once

// #include "PGE/utils/pgeLogger.h"
// #include "PGE/ecs/pgeEcs.h"

// #include <glm/glm.hpp>
// #include <glm/ext.hpp>

// namespace pge
// {
//     class PositionCMP : public ecs::Component
//     {
//     public:
//         PositionCMP(int x, int y);
//         ~PositionCMP();

//         inline glm::vec2 getPos() { return mPosition; }

//         inline float getX() { return mPosition.x; }
//         inline float getY() { return mPosition.y; }
//         inline float getRot() { return mRotation; }

//         inline void setPos(glm::vec2 pos) { mPosition = pos; }
//         inline void setRot(float rot) { mRotation = rot; }

//     private:
//         glm::vec2 mPosition;
//         float mRotation;
        
//     };
// }