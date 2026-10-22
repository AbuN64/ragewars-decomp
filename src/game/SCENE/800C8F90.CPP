#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800C8F90 */
const unsigned char D_blob_phase2_7081c74ca20d52b6678c[7] = {
    0x68, 0x65, 0x61, 0x64, 0x65, 0x72, 0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3DD7);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4197);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C4157);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3EA7);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8F97);
#endif
