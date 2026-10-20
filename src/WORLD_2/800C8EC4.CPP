#include "include_asm.h"

/* ROM-grounded data: rodata/shared/800C8EC4 */
const unsigned char D_blob_phase2_b1889aeb9007051833a0[11] = {
    0x73, 0x69, 0x6D, 0x70, 0x20, 0x6D, 0x6F, 0x64, 0x65, 0x6C, 0x00,
};

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3D0F);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C40CF);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C408F);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C3DDF);
#endif

#if defined(VERSION_US_REV1)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8ECF);
#endif
