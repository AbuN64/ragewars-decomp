#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_EU)
const char D_80286AA8_CAEA4[12] =
    "sky layers\000\000";
#endif
#if defined(VERSION_EU_X) || defined(VERSION_US)
const char D_80286AA8_CAEA4[11] =
    "sky layers\000";
#endif
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C50EF[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C54AF[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80286AA8_CAEA4_us_rev1.c */
const unsigned char D_blob_32ba39b5006aef489261[11] = {
    0x73, 0x6B, 0x79, 0x20, 0x6C, 0x61, 0x79, 0x65, 0x72, 0x73, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CA2AF[1] = {
    0x00,
};
#endif
