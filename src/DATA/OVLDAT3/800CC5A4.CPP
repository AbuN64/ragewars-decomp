#include "include_asm.h"

const unsigned char D_auto_rodata_shared_800CC5A4[17] = {
    0x61, 0x75, 0x64, 0x69, 0x6F, 0x2F, 0x63, 0x73, 0x70, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x2E, 0x63,
    0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7285);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8925);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7F55);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7365);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CC5B5);
#endif
