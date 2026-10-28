#ifndef PARTICLE_INSTHDR_H
#define PARTICLE_INSTHDR_H
#include "COMMON/PROBE.H"
#include "COMMON/OBJB.H"
extern void Insthdr_PlayActorGraphSound(void *actor, CVector3 position, s32 sound, f32 volume);
extern s32 Insthdr_GetModelPropertyFlag1(void *obj);
extern s32 Insthdr_GetModelPropertyFlag2(void *obj);
#endif
