#include "include_asm.h"
#include "sdk/libgultra.h"

unsigned int D_auto_rodata_unresolved_800CD4C4[8] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800C81B4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800C9854);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800C8E84);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800C8294);
#endif
