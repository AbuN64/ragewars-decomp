#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_cinemaText[7] = {
    0x43, 0x69, 0x6E, 0x65, 0x6D, 0x61, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804009F4_E1740_us_rev1.c */
const unsigned char s_cinemaResourceTagUsRev1[7] = {
    0x43, 0x69, 0x6E, 0x65, 0x6D, 0x61, 0x00,
};
#endif
