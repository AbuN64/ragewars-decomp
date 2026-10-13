#ifndef RW_PARTICLE_LIFECYCLE_H
#define RW_PARTICLE_LIFECYCLE_H
#include "span_1000/code_8027A0F4.h"
#include "shared/particle_attachment.h"
/* The common particle remains 0x1DC bytes; sound and list state follow it. */
typedef struct LiveParticle {
    Shared_Particle particle;
    Node80253610 *sound;
    f32 scale;
} LiveParticle;
/* Effect arguments use the same two-word ABI with signed halfword controls. */
typedef union ParticleActionPair {
    struct Shape_func_802764D4_de_2 words;
    struct { s16 upper, lower; s32 last; } control;
} ParticleActionPair;
#endif
