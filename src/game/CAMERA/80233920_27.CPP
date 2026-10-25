#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CHANNEL.H"

extern void Particle_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);
extern f32 func_802B72B0_de(float arg0);




f32 func_8023946C_de(void *gameplayCamera, CVector3 *arg1) {
    CVector3 delta;
    GameplayCamera *camera = gameplayCamera;
    Particle_SubtractVectors(&delta, &camera->position, arg1);
    return func_802B72B0_de((delta.x * delta.x) + (delta.y * delta.y) + (delta.z * delta.z));
}
