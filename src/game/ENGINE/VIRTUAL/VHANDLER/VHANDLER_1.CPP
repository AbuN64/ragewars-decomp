#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_virtualRegionText[15] =
    "Virtual Region\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8023C78C_C92F0_us_rev1.c */
const unsigned char s_virtualRegionText[15] = {
    0x56, 0x69, 0x72, 0x74, 0x75, 0x61, 0x6C, 0x20, 0x52, 0x65, 0x67, 0x69, 0x6F, 0x6E, 0x00,
};
#endif
