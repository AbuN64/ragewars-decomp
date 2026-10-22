#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_804322AC_E29F8);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCA7F);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E960F);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EE44F);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DDDCF);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_804322AC_E29F8_us_rev1.c */
const unsigned char D_blob_e009c53f41fd4006bf5e[7] = {
    0x5B, 0x4D, 0x4F, 0x44, 0x45, 0x5D, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E1DFF);
#endif
