#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802AE5B8_CD150);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C722C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C88CC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7EFC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C730C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AE5B8_CD150_us_rev1.c */
const unsigned int D_blob_68ac9033c68a4956883c[3] = {
    0x41F00000, 0x00000000, 0x3F800000,
};
#endif
