#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const unsigned int D_802A1B24_CBB20[1] = {
    0x25640044,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned char D_802A1B24_CBB20[3] = {
    0x25, 0x64, 0x00,
};
#endif
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C5CC3[13] = {
    0x08, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x73, 0x5F, 0x43, 0x43,
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
char rodata_unresolved_800C6073[13] =
    "WE - PURLIN\000\000";
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C6033[13] = {
    0x08, 0x27, 0xBD, 0x00, 0x18, 0x44, 0x00, 0x00, 0x00, 0xBF, 0x80, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_802A1B24_CBB20_us_rev1.c */
const unsigned char D_blob_66a5e2efda41fe7042e8[] = {
    0x25, 0x64, 0x00,
#if defined(VERSION_US_REV1)
    0x52,
#endif
};
#endif
