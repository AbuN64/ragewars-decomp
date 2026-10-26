#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_warpDestsText[11] =
    "warp dests\000";
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C4F37[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C52F7[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C52B7[1] = {
    0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800C5007[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8044B7C0_CACEC_us_rev1.c */
const unsigned char g_warpDests[11] = {
    0x77, 0x61, 0x72, 0x70, 0x20, 0x64, 0x65, 0x73, 0x74, 0x73, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CA0F7[1] = {
    0x00,
};
#endif
