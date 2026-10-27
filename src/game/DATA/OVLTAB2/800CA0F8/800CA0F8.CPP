#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned char s_curvesText[7] = {
    0x63, 0x75, 0x72, 0x76, 0x65, 0x73, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8044B7C0_CACF8_us_rev1.c */
const unsigned char g_curves[7] = {
    0x63, 0x75, 0x72, 0x76, 0x65, 0x73, 0x00,
};
#endif
