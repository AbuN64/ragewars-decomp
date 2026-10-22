#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_802B2120_CD344);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C7424);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8AC4);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C80F4);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_d0_e81657b8a691ed6c[4] = {
    0x49742400, 0x41F00000, 0x00000000, 0x4F000000,
};
#endif
