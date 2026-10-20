#include "include_asm.h"

const unsigned char D_auto_rodata_shared_800E0B2C[17] = {
    0x43, 0x69, 0x6E, 0x65, 0x6D, 0x61, 0x20, 0x44, 0x69, 0x72, 0x65, 0x63, 0x74, 0x6F, 0x72, 0x79,
    0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DB7BD);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E834D);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800ED18D);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCB0D);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E0B3D);
#endif
