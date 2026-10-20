#include "include_asm.h"

const unsigned char D_auto_rodata_shared_800CA3AC[37] = {
    0x43, 0x53, 0x63, 0x65, 0x6E, 0x65, 0x5F, 0x5F, 0x47, 0x65, 0x74, 0x42, 0x4C, 0x4C, 0x65, 0x76,
    0x65, 0x6C, 0x44, 0x61, 0x74, 0x61, 0x3A, 0x20, 0x62, 0x6C, 0x6C, 0x65, 0x76, 0x65, 0x6C, 0x20,
    0x64, 0x61, 0x74, 0x61, 0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5211);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C55D1);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5591);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C52E1);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CA3D1);
#endif
