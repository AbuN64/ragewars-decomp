#include "include_asm.h"

#if !(defined(VERSION_US))
const unsigned int D_d0_04d5a1aca44dd465[3] = {
    0x437F0000, 0x437F0000, 0x437F0000,
};
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9BBC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EE9FC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE37C);
#endif
