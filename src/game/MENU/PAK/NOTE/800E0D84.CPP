#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char s_audioHeapText[11] = "audio heap";
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E859F[1] = {
    0x38,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DCD5F[1] = {
    0x63,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804058B0_E1984_us_rev1.c */
const char D_blob_43b0ba6b1ac402bbd480[11] = "audio heap";
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800E0D8F[1] = {
    0x40,
};
#endif
