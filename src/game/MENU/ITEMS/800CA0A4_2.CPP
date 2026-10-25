#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const char D_8044B7C0_CACA4[20] =
    "particle effects\000\000\000\000";
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const char D_8044B7C0_CACA4[17] =
    "particle effects\000";
#endif
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C4EF5[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C52B5[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C5275[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned char g_particleEffects[17] = {
    0x70, 0x61, 0x72, 0x74, 0x69, 0x63, 0x6C, 0x65, 0x20, 0x65, 0x66, 0x66, 0x65, 0x63, 0x74, 0x73,
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CA0B5[3] = {
    0x00, 0x00, 0x00,
};
#endif
