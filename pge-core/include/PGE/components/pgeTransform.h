#pragma once

#include "PGE/utils/pgeLogger.h"
#include "PGE/ecs/pgeEcs.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace pge
{
    namespace ecs
    {
        struct TransformCMP
        {
            glm::vec2 position;
            glm::vec2 scale;
            float rotation;
        };
    }
}