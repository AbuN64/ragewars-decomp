#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* ROM-grounded data: rodata/shared/800E27E8 */
const unsigned char D_blob_phase2_549979ed41c81b2253c7[5] = {
    0x20, 0x25, 0x33, 0x64, 0x00,
};
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800DE7AD);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800E27ED);
#endif
