#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CHANNEL.H"

extern void GraphU64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
extern f32 Math_Sqrtf(float arg0);




f32 Gsky_GetDistanceTo(void *gameplayCamera, CVector3 *targetPosition) {
    CVector3 delta;
    GameplayCamera *camera = gameplayCamera;
    GraphU64_SubtractVectors(&delta, &camera->position, targetPosition);
    return Math_Sqrtf((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z));
}
