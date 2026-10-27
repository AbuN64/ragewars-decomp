#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE) || defined(VERSION_US)
const unsigned short D_80433EA0_E2AF0[3] = {
    0x2564, 0x2E25, 0x7300,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned char D_80433EA0_E2AF0[3] = {
    0x25, 0x64, 0x00,
};
#endif
#endif

#if defined(VERSION_US)
unsigned short rodata_unresolved_800DCB76[1] = {
    0x0000,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800E96F3[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800EE533[1] = {
    0x00,
};
#endif

#if defined(VERSION_DE)
unsigned short rodata_unresolved_800DDEC6[1] = {
    0x0000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
const unsigned short D_blob_a91dbb5d7223c482b0ba[3] = {
    0x2564, 0x2E25, 0x7300,
};
#endif

#if defined(VERSION_US_REV1)
unsigned short rodata_unresolved_800E1EF6[1] = {
    0x0000,
};
#endif
