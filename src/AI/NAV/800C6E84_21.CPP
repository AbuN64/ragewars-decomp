#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8021321C_C7DE0);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C23D4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C2394);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C20F4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8021321C_C7DE0_us_rev1.c */
const unsigned int D_blob_191e35959cee9de3e658[1] = {
    0x42CCCCCC,
};
#endif
