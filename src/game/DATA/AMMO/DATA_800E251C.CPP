#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800E251C */
const unsigned char g_menuText[5] = {
    0x6D, 0x65, 0x6E, 0x75, 0x00,
};

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DD1A1[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E9D31[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800EEB71[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DE4F1[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800E2521[3] = {
    0x00, 0x00, 0x00,
};
#endif
