#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800CA374 */
const unsigned char D_blob_phase2_2968dfa2b2531d534a4c[11] = {
    0x6C, 0x65, 0x76, 0x65, 0x6C, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x00,
};

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C557F);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C553F);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C528F);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800CA37F);
#endif
