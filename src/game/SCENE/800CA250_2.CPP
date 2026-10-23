#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned short D_80286AA8_CAE50[3] = {
    0x6C69, 0x6E6B, 0x7300,
};
#endif
#if defined(VERSION_EU)
const char D_80286AA8_CAE50[8] =
    "links\000\000\000";
#endif
#endif

#if defined(VERSION_US)
unsigned short rodata_unresolved_800C5096[1] = {
    0x0000,
};
#endif

#if defined(VERSION_EU_X)
unsigned short rodata_unresolved_800C5456[1] = {
    0x0000,
};
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800C5166[1] = {
    0x0000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_80286AA8_CAE50_us_rev1.c */
const char D_blob_7b20c7c5cce5d400fe67[6] = "links";
#endif

#if defined(VERSION_US_REV1)
unsigned short rodata_unresolved_800CA256[1] = {
    0x0000,
};
#endif
