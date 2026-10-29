#ifndef FX_PARTICLE_SOUND_H
#define FX_PARTICLE_SOUND_H
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
/* Sound-capable particles append their playback node to the common particle. */
typedef struct SoundParticle {
    Shared_Particle particle;
    CacheResourceNode *sound; /* 0x1DC */
} SoundParticle;
#endif
