#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800CC5A0 */
const unsigned char D_blob_phase2_96d5853c5394c1580524[3] = {
    0x45, 0x58, 0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7273);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8913);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7F43);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7353);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CC5A3);
#endif
