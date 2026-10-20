#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8043F120_E2FC0);
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800DD043);
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800DD044);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9BD3);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800E9BD4);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800EEA13);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800EEA14);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE393);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800DE394);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_8043F120_E2FC0_us_rev1.c */
const unsigned char D_blob_3ab17b82f55563784bf9[3] = {
    0x25, 0x73, 0x00,
};
#endif
