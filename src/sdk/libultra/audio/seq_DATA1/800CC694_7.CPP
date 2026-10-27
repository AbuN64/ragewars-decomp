#include "include_asm.h"

#if !(defined(VERSION_US_REV1))
const unsigned int D_802B2120_CD344[4] = {
    0x49742400, 0x41F00000, 0x00000000, 0x4F000000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C7424[3] = {
    0x0000D055, 0x02000800, 0x08000812,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C8AC4[3] = {
    0x00000000, 0x420A3D70, 0x3FDD2F1C,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C80F4[3] = {
    0x0022EC3C, 0x0022EC3C, 0x0022EC3C,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int D_d0_e81657b8a691ed6c[4] = {
    0x49742400, 0x41F00000, 0x00000000, 0x4F000000,
};
#endif
