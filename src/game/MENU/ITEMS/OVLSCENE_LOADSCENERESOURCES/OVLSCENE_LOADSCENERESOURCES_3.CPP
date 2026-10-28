#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const char s_particleEffectsText[20] =
    "particle effects\000\000\000\000";
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const char s_particleEffectsText[17] =
    "particle effects\000";
#endif
#endif

#if defined(VERSION_US_REV1)
const unsigned char g_particleEffects[17] = {
    0x70, 0x61, 0x72, 0x74, 0x69, 0x63, 0x6C, 0x65, 0x20, 0x65, 0x66, 0x66, 0x65, 0x63, 0x74, 0x73,
    0x00,
};
#endif
