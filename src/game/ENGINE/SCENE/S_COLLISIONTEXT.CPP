#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_EU) || defined(VERSION_US)
const char D_80286AA8_CAE0C[10] =
    "collision\000";
#endif
#if defined(VERSION_EU_X)
const char D_80286AA8_CAE0C[12] =
    "collision\000\000\000";
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80286AA8_CAE0C_us_rev1.c */
const char s_collisionText[10] = "collision";
#endif
