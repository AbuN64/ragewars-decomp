#ifndef PARTICLE_8027A0F4_4_H
#define PARTICLE_8027A0F4_4_H
#include "TYPES.H"
struct Actor_func_8027DAD0_de;
struct CVector3_t;
struct EffectActor;
struct Shared_ActorView;
extern void *Particle_ParentTransform(struct EffectActor *particle, struct Shared_ActorView *camera);
extern void Particle_Attach(struct Actor_func_8027DAD0_de *actor, struct CVector3_t *outPosition,
                            struct CVector3_t *outHeading);
#endif
