#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const char D_8028BEAC_CAED8[12] =
    "graphicset\000\000";
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const char D_8028BEAC_CAED8[11] =
    "graphicset\000";
#endif
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C5123[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU_X)
unsigned char rodata_unresolved_800C54E3[1] = {
    0x00,
};
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C54A3[1] = {
    0x00,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8028BEAC_CAED8_us_rev1.c */
const unsigned char D_blob_e98011d0118cc10a79ee[11] = {
    0x67, 0x72, 0x61, 0x70, 0x68, 0x69, 0x63, 0x73, 0x65, 0x74, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800CA2E3[1] = {
    0x00,
};
#endif
