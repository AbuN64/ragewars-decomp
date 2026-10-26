#ifndef FX_2_8028308C_H
#define FX_2_8028308C_H
#include "COMMON/OBJECTLINKS1E8.H"
extern void Particle_FlagKind86ModeTwo(void *arg0, s32 arg1);
extern void Particle_CaptureSharedTrailState(void *arg0);
extern s32 Particle_GetRenderLayer(void *arg0);
extern s32 Particle_MapEventTenToZero(s32 arg0);
extern void Particle_InitializeObjectLinks(void *arg0);
struct Shared_Particle;
struct GameplayCamera;
extern float Particle_CameraScale(struct Shared_Particle *particle, float depth, struct GameplayCamera *camera);
#endif
