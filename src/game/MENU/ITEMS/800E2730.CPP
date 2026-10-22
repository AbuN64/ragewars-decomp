#include "include_asm.h"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* ROM-grounded data: rodata/shared/800E2730 */
const unsigned char D_blob_phase2_2b46a3cbc59544f3a985[5] = {
    0x25, 0x30, 0x34, 0x64, 0x00,
};
#endif

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800DD3B5);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE705);
#endif
