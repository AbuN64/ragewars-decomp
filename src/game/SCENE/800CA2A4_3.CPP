#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80286AA8_CAEA4);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C50EF);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C54AF);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80286AA8_CAEA4_us_rev1.c */
const unsigned char D_blob_32ba39b5006aef489261[11] = {
    0x73, 0x6B, 0x79, 0x20, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x73, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CA2AF);
#endif
