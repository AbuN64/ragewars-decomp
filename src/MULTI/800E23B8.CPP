#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8043F120_E2FB8);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD03E);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9BCE);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EEA0E);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE38E);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8043F120_E2FB8_us_rev1.c */
const unsigned short D_blob_1a637ef558bd927194ce[3] = {
    0x2573, 0x2025, 0x7300,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E23BE);
#endif
