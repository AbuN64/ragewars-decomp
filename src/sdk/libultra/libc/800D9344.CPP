#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_EU_X)
const char D_802BDDE0_D9F44[17] =
    "0123456789ABCDEF\000";
#endif
#if defined(VERSION_US)
const char D_802BDDE0_D9F44[20] =
    "0123456789ABCDEF\000_PA";
#endif
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800E59A5[11] = {
    0x0C, 0x6A, 0x98, 0x80, 0x0C, 0x65, 0xA0, 0x80, 0x0C, 0x6A, 0x8C,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800D5325[11] = {
    0x00, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00, 0x4F, 0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
const unsigned char D_auto_src_rw_text_802BDDE0_D9F44_us_rev1[17] = {
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46,
    0x00,
};
#endif
