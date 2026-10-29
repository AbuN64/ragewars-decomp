#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_tempVisText[9] =
    "temp vis\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80286AA8_CAE44_us_rev1.c */
const unsigned char g_temporaryVisibilityText[9] = {
    0x74, 0x65, 0x6D, 0x70, 0x20, 0x76, 0x69, 0x73, 0x00,
};
#endif
