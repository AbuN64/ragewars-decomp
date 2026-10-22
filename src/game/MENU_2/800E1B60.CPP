#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800E1B60 */
const unsigned char D_blob_phase2_d8cba5f9791df715fbae[3] = {
    0x25, 0x64, 0x00,
};

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800E9373);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", data_unresolved_800E9374);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DDB33);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", data_unresolved_800DDB34);
#endif
