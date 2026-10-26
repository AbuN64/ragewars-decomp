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

#if defined(VERSION_US)
unsigned short rodata_unresolved_800C5056[1] = {
    0x0000,
};
#endif

#if defined(VERSION_EU)
unsigned short rodata_unresolved_800C53D6[1] = {
    0x0000,
};
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800C5126[1] = {
    0x0000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80286AA8_CAE0C_us_rev1.c */
const char s_collisionText[10] = "collision";
#endif

#if defined(VERSION_US_REV1)
unsigned short rodata_unresolved_800CA216[1] = {
    0x0000,
};
#endif
