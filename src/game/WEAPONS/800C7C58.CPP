#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_playersText[8] =
    "Players\000";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80226950_C8858_us_rev1.c */
const char s_playersText[8] = "Players";
#endif
