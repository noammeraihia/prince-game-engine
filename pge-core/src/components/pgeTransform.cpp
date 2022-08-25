// #include "PGE/components/pgeTransform.h"

// namespace pge
// {
//     TransformCMP::TransformCMP()
//     {
//         mTransform = glm::vec3(0);
//     }

//     TransformCMP::~TransformCMP()
//     {

//     }

//     void TransformCMP::Init()
//     {
//         // if (mParentPosition == NULL)
//         // {
//         //     PGE_LOG(PGELLVL_ERROR, "Parent has no Position component !");
//         // }
//     }

//     void TransformCMP::Update()
//     {
//         // PGE_LOG(PGELLVL_DEBUG, "Transform (%f, %f, %f)", mTransform.x, mTransform.y, mTransform.z);

//         mParentPosition.setPos(glm::vec2(mParentPosition.getPos().x + mTransform.x, mParentPosition.getPos().y + mTransform.y));
//         mParentPosition.setRot(mParentPosition.getRot() + mTransform.z);

//         // mTransform = glm::vec3(0);
//     }

//     void TransformCMP::setTransformX(float transX) { mTransform.x = transX; printf("ljkh"); }
//     void TransformCMP::setTransformY(float transX) { mTransform.y = transX; }
//     void TransformCMP::setTransformRot(float transRot) { mTransform.z = transRot; }
// }