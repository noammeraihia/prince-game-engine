#pragma once

#include "PGE/utils/pgeLogger.h"
#include "PGE/utils/pgeTypes.h"

#include "PGE/graphics/pgeTexture.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

namespace pge
{
    struct Sprite
    {
        graphics::Texture* texture;
        glm::vec2 currentFramePosition;
        glm::vec2 currentFrameSize;

    };
}