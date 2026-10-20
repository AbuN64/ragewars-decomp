#include "include_asm.h"

#if !(defined(VERSION_DE))
const unsigned char D_auto_rodata_shared_800CAF30[23] = {
    0x2E, 0x2E, 0x5C, 0x44, 0x41, 0x54, 0x41, 0x5C, 0x54, 0x53, 0x63, 0x72, 0x65, 0x64, 0x44, 0x61,
    0x74, 0x61, 0x2E, 0x65, 0x78, 0x70, 0x00,
};
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5CE7);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C6097);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C6057);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CAF47);
#endif
