#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8044B7C0_CACF8);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4F3F);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C52FF);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C52BF);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C500F);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8044B7C0_CACF8_us_rev1.c */
const unsigned char D_blob_4ecae79b4decda715e4c[7] = {
    0x63, 0x75, 0x72, 0x76, 0x65, 0x73, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CA0FF);
#endif
