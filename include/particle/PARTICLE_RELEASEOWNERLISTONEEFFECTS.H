#ifndef PARTICLE_PARTICLE_RELEASEOWNERLISTONEEFFECTS_H
#define PARTICLE_PARTICLE_RELEASEOWNERLISTONEEFFECTS_H
#include "COMMON/PARTICLE_ATTACHMENT_AND_OWNER_VIEWS.H"
extern void Particle_FlagKind86ModeTwo(void *owner, s32 mode);
extern void Particle_CaptureSharedTrailState(void *owner);
extern s32 Particle_GetRenderLayer(void *particle);
extern s32 Particle_MapEventTenToZero(s32 event);
extern void Particle_InitializeObjectLinks(void *owner);
struct Shared_Particle;
struct GameplayCamera;
extern float Particle_CameraScale(struct Shared_Particle *particle, float depth, struct GameplayCamera *camera);
#endif
