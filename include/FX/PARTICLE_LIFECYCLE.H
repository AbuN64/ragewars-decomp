#ifndef FX_PARTICLE_LIFECYCLE_H
#define FX_PARTICLE_LIFECYCLE_H
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "FX/PARTICLE_ATTACHMENT.H"
/* The common particle remains 0x1DC bytes; sound and list state follow it. */
typedef struct LiveParticle {
    Shared_Particle particle;
    CacheResourceNode *sound;
    f32 scale;
} LiveParticle;
/* Effect arguments use the same two-word ABI with signed halfword controls. */
typedef union ParticleActionPair {
    struct IntPair words;
    struct { s16 upper, lower; s32 last; } control;
} ParticleActionPair;
#endif
