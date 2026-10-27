#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
const unsigned char D_8040A9A0_E19C4[5] = {
    0x25, 0x30, 0x34, 0x64, 0x00,
};
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DBA49[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DCD99[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8040A9A0_E19C4_us_rev1.c */
const unsigned char g_pakFormatInt04[5] = {
    0x25, 0x30, 0x34, 0x64, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800E0DC9[3] = {
    0x00, 0x00, 0x00,
};
#endif
