#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int func_80210248_eu_padding_10E28[2] = {
    0x48478600, 0xE4EAB100,
};
#endif
#if defined(VERSION_US)
char func_80210248_eu_padding_10E28[8] =
    "Requ\004.eo";
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_80210248_eu_padding_10E28 */
unsigned int g_NavCheckcloseattackrouteEncodedWordsBlock2[2] = {
    0x04620001, 0x24620003,
};
#endif
