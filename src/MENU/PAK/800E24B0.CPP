#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80440838_E30B0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD13C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9CCC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EEB0C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE48C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80440838_E30B0_us_rev1.c */
const unsigned int D_blob_695b22dd21893cfe43ea[3] = {
    0x46200000, 0x3F4CCCCD, 0x40490FDC,
};
#endif
