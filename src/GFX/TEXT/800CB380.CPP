#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802AA7A4_CBF80);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C6124);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C64D4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C6494);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C61F4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AA7A4_CBF80_us_rev1.c */
const unsigned int D_blob_c6bebb857d303d439c85[1] = {
    0x3F333333,
};
#endif
