#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#ifdef VERSION_DE
unsigned int D_auto_rodata_writable_800CBC80[9] = {
    0x00000000, 0x38383800, 0xFFFFFF00, 0xFFFFFF00, 0x38383800, 0x38383800, 0xFFFFFF00, 0xFFFFFF00,
    0xD61EDC00,
};
#endif
#ifdef VERSION_EU_X
unsigned int D_auto_rodata_writable_800CBC80[9] = {
    0x00000000, 0x3F7F9F36, 0x3F7F52FA, 0x3F7F06B0, 0x38383800, 0x38383800, 0xFFFFFF00, 0xFFFFFF00,
    0xD61EDC00,
};
#endif
#ifdef VERSION_EU
unsigned int D_auto_rodata_writable_800CBC80[9] = {
    0x00000000, 0x00000000, 0x4E4F5553, 0x20564F55, 0x38383800, 0x38383800, 0xFFFFFF00, 0xFFFFFF00,
    0xD61EDC00,
};
#endif
#ifdef VERSION_US
unsigned int D_auto_rodata_writable_800CBC80[9] = {
    0x00000000, 0x52454144, 0x59657175, 0x5200006C, 0x38383800, 0x38383800, 0xFFFFFF00, 0xFFFFFF00,
    0xD61EDC00,
};
#endif
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800CBBB4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800CD254);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800CC884);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800CBCA4);
#endif
