#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8042ED70_E2784);
#endif

#if defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_func_8042FD3C_eu_x_800E93A0);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_d0_d497922e2f7fa66e[3] = {
    0x44610000, 0x41700000, 0xBF800000,
};
#endif
