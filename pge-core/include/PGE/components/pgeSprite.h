#pragma once

#include "PGE/utils/pgeLogger.h"
#include "PGE/graphics/pgeTexture.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace pge
{
    namespace ecs
    {
        struct SpriteCMP
        {
            graphics::Texture* texture;
            glm::vec2 currentFramePosition;
            glm::vec2 currentFrameSize;

        };
    }
}