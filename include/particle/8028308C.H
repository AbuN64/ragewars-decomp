#ifndef FX_2_8028308C_H
#define FX_2_8028308C_H
#include "COMMON/OBJECTLINKS1E8.H"
extern void func_80283BA0_de(void *arg0, s32 arg1);
extern void func_80283BCC_de(void *arg0);
extern s32 Particle_GetRenderLayer(void *arg0);
extern s32 func_80283D38_de(s32 arg0);
extern void Particle_InitializeObjectLinks(void *arg0);
struct Shared_Particle;
struct GameplayCamera;
extern float Particle_CameraScale(struct Shared_Particle *particle, float depth, struct GameplayCamera *camera);
#endif
