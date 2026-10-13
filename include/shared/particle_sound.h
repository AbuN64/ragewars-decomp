#ifndef RW_PARTICLE_SOUND_H
#define RW_PARTICLE_SOUND_H
#include "span_1000/code_8027A0F4.h"
/* Sound-capable particles append their playback node to the common particle. */
typedef struct SoundParticle {
    Shared_Particle particle;
    Node80253610 *sound; /* 0x1DC */
} SoundParticle;
#endif
