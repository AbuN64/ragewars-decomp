#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_80210964_C7C88);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1F28);
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("data_800C", rodata_unresolved_800C22D8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("data_800C", rodata_unresolved_800C1FF8);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_auto_src_rw_pool_80210964_C7C88_us_rev1[6] = {
    0x42C80000, 0x40100000, 0x3F000000, 0x43199999, 0x43999999, 0x42C80000,
};

const unsigned int D_auto_src_rw_pool_80210C14_C7CA0_us_rev1[10] = {
    0x40490FDB, 0x3EC90FDB, 0x40C90FDB, 0x40C90FDB, 0x40C5DCA8, 0x3DCCCCCD, 0x3E22F983, 0x41000000,
    0x43340000, 0x430C0000,
};

const unsigned int D_auto_src_rw_pool_80210EFC_C7CC8_us_rev1[8] = {
    0x3EC90FDB, 0x40C90FDB, 0x40C90FDB, 0x40C5DCA8, 0x3DCCCCCD, 0x3E22F983, 0x41000000, 0x40E00000,
};
#endif
