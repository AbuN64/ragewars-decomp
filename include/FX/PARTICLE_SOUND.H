#ifndef FX_2_PARTICLE_SOUND_H
#define FX_2_PARTICLE_SOUND_H
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
/* Sound-capable particles append their playback node to the common particle. */
typedef struct SoundParticle {
    Shared_Particle particle;
    Node80253610 *sound; /* 0x1DC */
} SoundParticle;
#endif
