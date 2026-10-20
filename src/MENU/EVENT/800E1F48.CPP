#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8043829C_E2B48);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCBCD);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E975D);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EE59D);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DDF1D);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8043829C_E2B48_us_rev1.c */
const unsigned char D_blob_bf6d36a4ef6a7f69696e[5] = {
    0x25, 0x64, 0x25, 0x25, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E1F4D);
#endif
