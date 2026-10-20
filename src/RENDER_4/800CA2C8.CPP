#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8028BE08_CAEC8);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5115);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C54D5);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C5495);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C51E5);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8028BE08_CAEC8_us_rev1.c */
const unsigned char D_blob_677bcfc9617d0a99a715[13] = {
    0x62, 0x69, 0x6E, 0x61, 0x72, 0x79, 0x20, 0x62, 0x6C, 0x6F, 0x63, 0x6B, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CA2D5);
#endif
