#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802AE824_CD178);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7254);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C88F4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7F24);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7334);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AE824_CD178_us_rev1.c */
const unsigned int D_blob_0076579712f8943876c3[3] = {
    0x41F00000, 0x00000000, 0x49742400,
};
#endif
