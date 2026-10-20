#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802BB0F0_CD850);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7923);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8FC3);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C85F3);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7A03);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_802BB0F0_CD850_us_rev1.c */
const unsigned char D_blob_5843326ad6f37145c68a[3] = {
    0x45, 0x58, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CCC53);
#endif
