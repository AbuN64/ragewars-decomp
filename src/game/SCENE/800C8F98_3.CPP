#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned short D_8025305C_C9B98[3] = {
    0x616C, 0x6C6F, 0x6300,
};
#endif
#if defined(VERSION_EU)
const char D_8025305C_C9B98[8] =
    "alloc\000\000\000";
#endif
#endif

#if defined(VERSION_US)
unsigned short rodata_unresolved_800C3DDE[1] = {
    0x0008,
};
#endif

#if defined(VERSION_EU_X)
unsigned short rodata_unresolved_800C419E[1] = {
    0xCBEC,
};
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800C3EAE[1] = {
    0x0000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8025305C_C9B98_us_rev1.c */
const char D_blob_66a6a2bbfb831a34114b[6] = "alloc";
#endif
