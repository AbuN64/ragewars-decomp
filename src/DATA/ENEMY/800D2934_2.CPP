#include "include_asm.h"

unsigned int D_auto_rodata_writable_800D2950[6] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000014, 0x00000000, 0x00000000,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800CD628);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800CECC8);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", data_unresolved_800CE2F8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800CD718);
#endif
