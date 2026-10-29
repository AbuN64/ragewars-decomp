#include "include_asm.h"

#if !(defined(VERSION_US))
/* ROM-grounded data: src/navUpdatepatrolrouteDataFloatConstantWords.c */
const unsigned int k_navUpdatepatrolrouteDataFloatConstantWords[1] = {
    0x42CCCCCC,
};
#endif

#if defined(VERSION_EU_X)
unsigned int k_NavUpdatepatrolrouteEncodedWordsBlock1[3] = {
    0x3C8EFA36, 0x41800000, 0x4F000000,
};
#endif

#if defined(VERSION_DE)
unsigned int k_NavUpdatepatrolrouteEncodedWords[3] = {
    0x424CCCCC, 0xAFB10014, 0x00C08821,
};
#endif
