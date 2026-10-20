#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80276CB0_CA750);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C49CC);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4D8C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4D4C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4A9C);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_80276CB0_CA750_us_rev1[15] = {
    0x37C80000, 0x32200000, 0xBF800000, 0x32200000, 0x3C23D70A, 0x3C23D70A, 0x3C23D70A, 0x3C23D70A,
    0x3C23D70A, 0x3C23D70A, 0x37C80000, 0x30000000, 0x41F00000, 0x00000000, 0x361F6000,
};
#endif
