#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802BD430_CD960);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7A34);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C90D4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8704);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7B14);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_802BD430_CD960_us_rev1.c */
const unsigned int D_blob_a0a68c2fc90206a13910[1] = {
    0x686C4C00,
};
#endif
