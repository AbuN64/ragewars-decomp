#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8043C080_E2C60[7] = {
    0x3F800000, 0x3FD85689, 0x3FCF914C, 0x3FD85689, 0x3F8A60DE, 0x41100000, 0x40800000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E988C[1] = {
    0x00000018,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DE04C[1] = {
    0x0043C384,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_8043C080_E2C60_us_rev1[7] = {
    0x3F800000, 0x3FD85689, 0x3FCF914C, 0x3FD85689, 0x3F8A60DE, 0x41100000, 0x40800000,
};
#endif
