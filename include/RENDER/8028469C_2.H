#ifndef RENDER_8028469C_2_H
#define RENDER_8028469C_2_H
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "RENDER/8028469C.H"
extern void Particle_UpdateNearbyObjectFlags(int context, struct ObjParticleMarkNearbyObjects * * objects, int count);
extern void Particle_MarkNearbyObjects(s32 unused, ObjParticleMarkNearbyObjects *center, ObjParticleMarkNearbyObjects **objects, s32 count);
#endif
