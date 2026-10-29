#include "include_asm.h"
#include "COMMON/ALFXPARAM.H"

#if !(defined(VERSION_US_REV1))
const unsigned int g_EnvWords1[2] = {
    0x37800000, 0x3F800000,
};
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int g_EnvWords2[10] = {
    0x00000000, 0x00000000, 0x3FF00000, 0x00000000, 0x3FE00000, 0x00000000, 0x3FE00000, 0x00000000,
    0x00000000, 0x00000000,
};
#endif

#if defined(VERSION_US)
char s_EnvTGamText[8] =
    "_t\014m_Gam";
#endif

#if defined(VERSION_EU)
char k_EnvEncodedBytes[8] =
    "D\026\000\000\077333";
#endif

#if defined(VERSION_DE)
unsigned int k_EnvEncodedWords[2] = {
    0x38000000, 0x00000000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802B5288_CD558_us_rev1.c */
const unsigned int g_EnvWords4[2] = {
    0x37800000, 0x3F800000,
};

const unsigned int g_EnvWords3[10] = {
    0x00000000, 0x00000000, 0x3FF00000, 0x00000000, 0x3FE00000, 0x00000000, 0x3FE00000, 0x00000000,
    0x00000000, 0x00000000,
};
#endif
