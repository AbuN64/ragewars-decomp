#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
INCLUDE_RODATA("data_800C", D_8040A614_E19B4);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DBA42);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DCD92);
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_text_8040A614_E19B4_us_rev1.c */
const unsigned short D_blob_bcd7ce4fb0e9048e666e[7] = {
    0x2533, 0x642E, 0x2530, 0x3264, 0x2E25, 0x3032, 0x6400,
};
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E0DC2);
#endif
