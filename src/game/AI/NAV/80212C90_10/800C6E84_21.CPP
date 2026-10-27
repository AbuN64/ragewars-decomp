#include "include_asm.h"

#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
const unsigned int D_8021321C_C7DE0[1] = {
    0x42CCCCCC,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C23D4[3] = {
    0x00000000, 0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C2394[3] = {
    0x216BFFFF, 0x40021000, 0x04010002,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C20F4[3] = {
    0x43000000, 0x41F00000, 0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8021321C_C7DE0_us_rev1.c */
const unsigned int D_blob_191e35959cee9de3e658[1] = {
    0x42CCCCCC,
};
#endif
