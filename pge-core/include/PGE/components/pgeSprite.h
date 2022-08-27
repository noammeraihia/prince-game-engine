// #pragma once

// #include "PGE/utils/pgeLogger.h"
// #include "PGE/graphics/pgeTexture.h"
// #include "PGE/graphics/pgeRendererWrapper.h"
// #include "PGE/ecs/pgeEcs.h"

// #include <glm/glm.hpp>
// #include <glm/ext.hpp>

// #include "PGE/components/pgePosition.h"

// namespace pge
// {
//     class SpriteCMP : public ecs::Component
//     {
//     public:
//         SpriteCMP(graphics::Texture* tex, glm::vec2 framePos, glm::vec2 frameSize, glm::vec2 scale, graphics::RendererWrapper* parentRenderer);
//         ~SpriteCMP();

//         void Init() override;
//         void Render() override;

//         inline glm::vec2 getCurrFramePos() { return mCurrentFramePosition; }
//         inline glm::vec2 getCurrFrameSize() { return mCurrentFrameSize; }
//         inline glm::vec2 getScale() { return mScale; }

//         inline void setCurrFramePos(glm::vec2 framePos) { mCurrentFramePosition = framePos; }
//         inline void setCurrFrameSize(glm::vec2 frameSize) { mCurrentFrameSize = frameSize; }
//         inline void setScale(glm::vec2 scale) { mScale = scale; }

//     private:
//         graphics::Texture* mTexture;
//         PositionCMP& mParentPosition = pParent->getCmp<PositionCMP>();

//         glm::vec2 mCurrentFramePosition;
//         glm::vec2 mCurrentFrameSize;
//         glm::vec2 mScale;

//         graphics::RendererWrapper* mParentRenderer;

//     };
// }

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
            // SpriteCMP(graphics::Texture* _texture, glm::vec2 framePos, glm::vec2 frameSize)
            // {
            //     texture = _texture;
            //     currentFramePosition = framePos;
            //     currentFrameSize = frameSize;
            // }

            graphics::Texture* texture;
            glm::vec2 currentFramePosition;
            glm::vec2 currentFrameSize;

        };
    }
}