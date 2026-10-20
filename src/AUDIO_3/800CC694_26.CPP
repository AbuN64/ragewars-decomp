#include "include_asm.h"
#include "COMMON/EXTERNS_2.H"

#if !(defined(VERSION_US))
/* ROM-grounded data: src/rw_formats_802B6658_eu_x_CD640_us_rev1.c */
const unsigned char D_blob_3e9a18b4da19e6114370[3] = {
    0x45, 0x58, 0x00,
};
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8DB3);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C83E3);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C77F3);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CCA43);
#endif
