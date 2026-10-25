#ifndef ENGINE_SCENE_11_H
#define ENGINE_SCENE_11_H
#include "TYPES.H"
#include "COMMON/PARTICLE_LIGHTING.H"
struct Shared_World;
extern void Engine_SampleWorldLighting(struct Shared_World *world, CVector3 *position, Shared_ParticleLighting *out);
#endif
