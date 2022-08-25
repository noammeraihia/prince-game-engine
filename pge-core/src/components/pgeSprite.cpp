// #include "PGE/components/pgeSprite.h"

// namespace pge
// {
//     SpriteCMP::SpriteCMP(graphics::Texture* tex, glm::vec2 framePos, glm::vec2 frameSize, glm::vec2 scale, graphics::RendererWrapper* parentRenderer)
//     {
//         mTexture = tex;
//         mCurrentFramePosition = framePos;
//         mCurrentFrameSize = frameSize;
//         mScale = scale;
//         mParentRenderer = parentRenderer;
//     }

//     SpriteCMP::~SpriteCMP()
//     {
//     }

//     void SpriteCMP::Init()
//     {
//         // if (mParentPosition == NULL)
//         // {
//         //     PGE_LOG(PGELLVL_ERROR, "Parent has no Position component !");
//         // }
//     }

//     void SpriteCMP::Render()
//     {
//         mParentRenderer->Submit(mTexture, 
//                                 glm::vec4(mCurrentFramePosition.x, mCurrentFramePosition.y, mCurrentFrameSize.x, mCurrentFrameSize.y),
//                                 glm::vec4(mParentPosition.getX(), mParentPosition.getY(), mTexture->width * mScale.x, mTexture->height * mScale.y)
//                                 );
//     }
// }