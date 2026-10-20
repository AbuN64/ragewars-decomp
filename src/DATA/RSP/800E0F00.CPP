#include "include_asm.h"

#if defined(VERSION_DE)
unsigned short D_auto_rodata_writable_800E0F00[11] = {
    0x0042, 0x994C, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};
#endif

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", rodata_unresolved_800E0F16);
#endif
