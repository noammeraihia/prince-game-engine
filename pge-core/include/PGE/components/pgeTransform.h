#pragma once

#include "PGE/utils/pgeLogger.h"
#include "PGE/utils/pgeTypes.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace pge
{
    struct Transform
    {
        glm::vec2 position;
        glm::vec2 scale;
        f32 rotation;
    };
}