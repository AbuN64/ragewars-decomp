#include "include_asm.h"

const unsigned char g_audioCsplayerText[17] = {
    0x61, 0x75, 0x64, 0x69, 0x6F, 0x2F, 0x63, 0x73, 0x70, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x2E, 0x63,
    0x00,
};

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C7285[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C8925[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C7F55[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800C7365[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CC5B5[3] = {
    0x00, 0x00, 0x00,
};
#endif
