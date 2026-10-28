#include "include_asm.h"
#include "sdk/libgultra.h"

#if defined(VERSION_DE) || defined(VERSION_EU)
const unsigned int rodata_unresolved_800CCF48_unclaimed_CDE50_unclaimed_CDF50[6] = {
    0x41F00000, 0x00000000, 0x40F00000, 0x00000000, 0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C8D08[2] = {
    0x3DCCCCCD, 0x3F000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C8118[2] = {
    0x40F00000, 0x00000000,
};
#endif

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* ROM-grounded exact candidate, normalized from prior lane proof. */
unsigned int D_blob_b9e185f66508d14a5109[8] = {
    0x41F00000, 0x00000000, 0x40F00000, 0x00000000, 0x41F00000, 0x00000000, 0x00040000, 0x000C0000,
};
#endif
