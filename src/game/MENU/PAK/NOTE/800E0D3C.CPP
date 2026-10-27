#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_displayBufferText[15] = "Display Buffer";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804058B0_E193C_us_rev1.c */
const char g_displayBufferText[15] = "Display Buffer";
#endif
