#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const char D_8022409C_C8640[13] =
    "Fly Mode Off\000";
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C288D[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C2C3D[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C2BFD[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800C295D[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8022409C_C8640_us_rev1.c */
const unsigned char s_flyModeOffText[13] = {
    0x46, 0x6C, 0x79, 0x20, 0x4D, 0x6F, 0x64, 0x65, 0x20, 0x4F, 0x66, 0x66, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800C7A4D[3] = {
    0x00, 0x00, 0x00,
};
#endif
