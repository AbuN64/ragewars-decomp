#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8020E674_C7B30);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1D7C);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C20EC);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1E4C);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_d0_d204073b84f77a59[3] = {
    0x3F800000, 0x3FAAAAAB, 0x3F000000,
};
#endif
