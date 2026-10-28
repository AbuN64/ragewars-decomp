#ifndef PARTICLE_8027A0F4_8_H
#define PARTICLE_8027A0F4_8_H
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
struct EffectActor;
struct EffectSystem;
extern s32 Particle_SpawnEffectGroup(struct EffectSystem *sys, struct EffectActor *source, struct EffectActor *owner,
                            s32 *refCount, s32 arg4, s32 kind, CVector3 arg6, CQuatern rotation, CVector3 pos,
                            CVector3 *aim, s32 arg10, s32 arg11);
#endif
