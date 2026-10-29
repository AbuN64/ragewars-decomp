#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

const unsigned int g_Math_CosfConstantWords_de_eu_eu_x_us_us_rev1[6] = {
    0x3FE00000, 0x00000000, 0x00000000, 0x00000000, 0x3FE00000, 0x00000000,
};

#if defined(VERSION_US)
unsigned int k_cosineSignedUnitWords[2] = {
    0xBF800000, 0x3F800000,
};
#endif
