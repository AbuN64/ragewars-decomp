#include "include_asm.h"

/* ROM-grounded data: src/rw_pool_802850C8_CAB90_us_rev1.c */
const unsigned int g_Particle_FindNearestForeignEffectDistanceConstantsUsRev1[1] = {
    0x4B189680,
};

#if defined(VERSION_EU_X)
unsigned int k_ParticleFindnearestforeigneffectdistanceEncodedWordsBlock1[3] = {
    0x3F800000, 0x3C23D70A, 0x3E95CBEC,
};
#endif

#if defined(VERSION_DE)
unsigned int k_ParticleFindnearestforeigneffectdistanceEncodedWords[3] = {
    0x00000000, 0x38000100, 0x00003021,
};
#endif
