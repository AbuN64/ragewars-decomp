#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
INCLUDE_RODATA("data_800C", D_8042CE74_E272C);
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_d0_50636ccbd30087db[4] = {
    0x3E99999A, 0x40400000, 0xC1F00000, 0xC2C80000,
};
#endif
