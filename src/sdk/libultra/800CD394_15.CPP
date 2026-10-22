#include "include_asm.h"
#include "sdk/libgultra.h"

#if defined(VERSION_DE) || defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800CCF48_unclaimed_CDE50_unclaimed_CDF50);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8D08);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C8118);
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int D_blob_b9e185f66508d14a5109[8] = {
    0x41F00000, 0x00000000, 0x40F00000, 0x00000000, 0x41F00000, 0x00000000, 0x00040000, 0x000C0000,
};
#endif
