#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80243A90_C9480);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3A9C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3A5C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C37AC);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_80243A90_C9480_us_rev1[7] = {
    0xBEE66666, 0xBF350481, 0x434CCCCC, 0x3F800000, 0x424CCCCC, 0x3F83126F, 0x424CCCCC,
};
#endif
