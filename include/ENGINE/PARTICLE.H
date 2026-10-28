#ifndef ENGINE_PARTICLE_H
#define ENGINE_PARTICLE_H
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
extern void Particle_DrawModel(struct Shared_Particle *particle, GameplayCamera *view);
extern void Particle_DrawGroundShadow(struct Shared_Particle *actor, GameplayCamera *view);
extern u8 D_8011026D;
#endif
