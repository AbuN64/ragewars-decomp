#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char g_sprawdmaText[14] =
    "io/sprawdma.c\000";
#endif

#if defined(VERSION_US)
char rodata_unresolved_800C78E2[14] =
    "MHUD_EXPANDHR\000";
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
unsigned short rodata_unresolved_800C85B2[7] = {
    0x0000, 0x41F0, 0x0000, 0x4180, 0x0000, 0x41F0, 0x0000,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800C79C2[7] = {
    0x0000, 0x0000, 0x0000, 0x4F00, 0x0000, 0x8E02, 0x0024,
};
#endif

#if defined(VERSION_DE)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_802B9FD0_CD804_us_rev1.c */
const char s_sprawdmaText[14] = "io/sprawdma.c";
#endif
