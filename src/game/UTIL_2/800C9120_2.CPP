#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8025DD60_C9D24);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C432C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C403C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025DD60_C9D24_us_rev1.c */
const unsigned int D_blob_4d5302c2d0e80d970cfa[2] = {
    0x3C23D70A, 0x46FFFE00,
};
#endif
