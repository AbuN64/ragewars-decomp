#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
const unsigned char D_8041BE90_E2080[3] = {
    0x25, 0x64, 0x00,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800DC103[13] =
    "_MEDALS_SCREE";
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
char rodata_unresolved_800DD453[13] =
    "m object inde";
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_8041BE90_E2080_us_rev1.c */
const unsigned char g_noteCountIntFormat[] = {
    0x25, 0x64, 0x00,
#if defined(VERSION_US_REV1)
    0x86,
#endif
};
#endif
