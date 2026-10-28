#include "include_asm.h"

const unsigned int D_auto_src_rw_pool_80265714_CA088_us_rev1[4] = {
    0x3F800000, 0x40490FDC, 0x3F800000, 0x3F000000,
};

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C42D8[2] = {
    0x79520000, 0x29000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C4698[2] = {
    0x40F00000, 0x42080000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4658[2] = {
    0x24050006, 0x24060010,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C43A8[2] = {
    0x24630001, 0x03E00008,
};
#endif
