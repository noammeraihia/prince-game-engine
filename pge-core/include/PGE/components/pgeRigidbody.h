#pragma once

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace pge
{
    namespace ecs
    {
        struct RigidbodyCMP
        {
            glm::vec2 force = glm::vec2(0.0f, 0.0f);
            glm::vec2 velocity = glm::vec2(0.0f, 0.0f);
            glm::vec2 acceleration = glm::vec2(0.0f, 0.0f);
            glm::vec2 friction = glm::vec2(0.01f);
            bool submittedToGravity;
            float mass;
            float gravityMultiplier;
        };
    }
}