#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800E251C */
const unsigned char D_blob_phase2_866ba8f28e81b8aecc75[5] = {
    0x6D, 0x65, 0x6E, 0x75, 0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800DD1A1);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9D31);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800EEB71);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE4F1);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E2521);
#endif
