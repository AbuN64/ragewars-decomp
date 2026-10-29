#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const unsigned int g_alFxNewConstantWords_de_eu_eu_x_us[7] = {
    0x41F00000, 0x00000000, 0x36C1D168, 0x3F800000, 0x3F100000, 0x00000000, 0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
const unsigned int g_alFxNewConstantWords_us_rev1[6] = {
    0x41F00000, 0x00000000, 0x36C1D168, 0x3F800000, 0x3F100000, 0x00000000,
};

/* ROM-grounded data: src/rw_pool_802B450C_CD430_us_rev1.c */
const unsigned int g_alResampleNewConstantWords[1] = {
    0x3F800000,
};
#endif
