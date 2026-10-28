#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_libcZeroPaddingText[33] =
    "00000000000000000000000000000000\000";
#endif

#if defined(VERSION_US)
char rodata_unresolved_800D3FA5[11] =
    "NICT\000\000\004\000\000\000f";
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E0B35[11] = {
    0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800E5975[11] = {
    0x0C, 0x6B, 0x38, 0x80, 0x0C, 0x6B, 0x28, 0x80, 0x0C, 0x6B, 0x1C,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
char rodata_unresolved_800D52F5[11] =
    "56789abcdef";
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
const unsigned char D_auto_src_rw_text_802BD430_D9F04_us_rev1[] = {
    0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x00,
#if defined(VERSION_US_REV1)
    0x20, 0x00, 0x00,
#endif
};
#endif
