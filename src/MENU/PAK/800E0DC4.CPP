#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_RODATA("data_800C", D_8040A9A0_E19C4);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DBA49);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCD99);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8040A9A0_E19C4_us_rev1.c */
const unsigned char D_blob_1047215efff4750e6ff2[5] = {
    0x25, 0x30, 0x34, 0x64, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E0DC9);
#endif
