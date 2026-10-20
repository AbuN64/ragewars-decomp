#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8029E104_CB9F0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5B9C);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5F4C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5F0C);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5C6C);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8029E104_CB9F0_us_rev1.c */
const unsigned int D_blob_8e301e1dd53d50fc50fe[3] = {
    0x40490FDB, 0x41C90FDC, 0xC1C90FDC,
};
#endif
