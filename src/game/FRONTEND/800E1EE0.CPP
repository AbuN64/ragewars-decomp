#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_RODATA("data_800C", D_80433EA0_E2AE0);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCB63);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DDEB3);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_80433EA0_E2AE0_us_rev1.c */
const unsigned char D_blob_cf15e13137027ce1e3ab[3] = {
    0x25, 0x64, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E1EE3);
#endif
