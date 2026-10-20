#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B3D10_CD3C0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7493);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8B33);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8163);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7573);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_802B3D10_CD3C0_us_rev1.c */
const unsigned char D_blob_ed102ecd4bfebc3b6053[3] = {
    0x45, 0x58, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CC7C3);
#endif
