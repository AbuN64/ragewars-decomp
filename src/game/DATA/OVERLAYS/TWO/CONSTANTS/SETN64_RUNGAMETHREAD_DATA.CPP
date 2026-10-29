#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned short g_SetN64_RunGameThreadConstantWords[3] = {
    0x2573, 0x2025, 0x7300,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80293534_CB0F0_us_rev1.c */
const char g_gameThreadTwoStringFormat[6] = "%s %s";
#endif
