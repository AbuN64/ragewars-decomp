#include "include_asm.h"

unsigned int D_auto_rodata_writable_800E28B0[8] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xFFFFFFFF, 0x00000000,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DD530);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800EA0B0);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800EEEF0);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800DE880);
#endif

#if !(defined(VERSION_US_REV1))
INCLUDE_DATA("data_800C", rodata_unresolved_800DE88B);
#endif
