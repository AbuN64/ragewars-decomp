#ifndef PARTICLE_5_PARTICLE_5_H
#define PARTICLE_5_PARTICLE_5_H
#include "COMMON/ITEMRECAT20V1.H"
#include "FX/PARTICLE_SOUND.H"
#include "COMMON/UNUSED.H"
#include "COMMON/PACKEDMESHMATERIAL.H"
#include "RENDER/8028469C.H"
extern void Particle_StopSound(void *a);
extern void Particle_ReleaseFirstHandle(char *obj, unsigned char count);
extern void *Particle_FindOwnerEntry(EffectSystem *effectSystem, s32, EffectEntry *effectEntry);
extern void Particle_InsertEntryGroup(EffectSystem *, ParticleEffect *);
extern s32 Particle_RandomInclusiveCount(s32);
extern void Particle_AdvanceRandomWhenNonzero(f32);
extern float Particle_GetConditionalFirstValue(ParticleEffect *effect);
extern f32 Particle_GetConditionalSecondValue(ParticleEffect *effect);
extern s32 Particle_IsKind2Or86Or273Or294(ParticleEffect *effect);
extern s32 Particle_IsKind5To7Or9Or17Or19Or26Or257Or272(ParticleEffect *effect);
extern s32 Particle_IsKind8Or13Or18(ParticleEffect *effect);
extern void Particle_UpdateForcesAndMotion(ParticleEffect *effect);
extern void Particle_CheckNearbyPlayerContacts(Shared_Particle *particle);
extern s32 Particle_HasClearMotionPath(Instance8020CD74 *, Arg1 *);
extern void Particle_MarkNearbyObjects(s32 unused, ObjParticleMarkNearbyObjects *center, ObjParticleMarkNearbyObjects * *objects, s32 count);
extern void Particle_UpdateNearbyObjectFlags(int context, ObjParticleMarkNearbyObjects * *objects, int count);
#endif
