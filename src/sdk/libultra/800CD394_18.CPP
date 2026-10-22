#include "include_asm.h"
#include "sdk/libgultra.h"

unsigned int D_auto_rodata_unresolved_800CD3C0[8] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800C80B0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800C9750);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800C8D80);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800C8190);
#endif
