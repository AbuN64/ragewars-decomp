#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_8021035C_C7C40[13] = {
    0x44C00000, 0x44666666, 0x44000000, 0x3F490FDC, 0x4016CBE5, 0x3F8CCCCD, 0x3F99999A, 0x3F4CCCCD,
    0x3F4CCCCD, 0x3F8CCCCD, 0x3F99999A, 0x3F800000, 0x3F000000,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_800C1EB4[12] =
    "LifeTimeR\000\000(";
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C2264[3] = {
    0x40490FDB, 0x40A78D36, 0x3FE52EDF,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_8021035C_C7C40_us_rev1[13] = {
    0x44C00000, 0x44666666, 0x44000000, 0x3F490FDC, 0x4016CBE5, 0x3F8CCCCD, 0x3F99999A, 0x3F4CCCCD,
    0x3F4CCCCD, 0x3F8CCCCD, 0x3F99999A, 0x3F800000, 0x3F000000,
};
#endif
