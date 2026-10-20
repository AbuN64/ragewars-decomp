#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_RODATA("data_800C", D_8040B444_E19CC);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DBA51);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", data_unresolved_800DBA54);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCDA1);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800DCDA4);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8040B444_E19CC_us_rev1.c */
const unsigned char D_blob_d03d5379f8c440c18cae[5] = {
    0x25, 0x31, 0x64, 0x2E, 0x00,
};
#endif
