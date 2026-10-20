#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80286AA8_CADF4);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C503D);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C53FD);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C53BD);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C510D);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80286AA8_CADF4_us_rev1.c */
const unsigned char D_blob_0369ebfa80ed0a96c156[9] = {
    0x4D, 0x61, 0x74, 0x72, 0x69, 0x63, 0x65, 0x73, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CA1FD);
#endif
