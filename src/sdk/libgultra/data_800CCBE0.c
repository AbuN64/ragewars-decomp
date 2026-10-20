#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B9CB0_CD7E0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C78B3);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8F53);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8583);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7993);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_802B9CB0_CD7E0_us_rev1.c */
const unsigned char D_blob_d8f8e509258da113a18f[3] = {
    0x45, 0x58, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CCBE3);
#endif
