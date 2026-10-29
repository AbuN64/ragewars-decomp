#include "include_asm.h"

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int func_80210198_eu_padding_10D78[2] = {
    0x7235699E, 0xB7FD4342,
};
#endif
#if defined(VERSION_US)
char func_80210198_eu_padding_10D78[8] =
    "PAWN_PLA";
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_80210198_eu_padding_10D78 */
unsigned int g_NavRequestrandomarmedweaponEncodedWords[2] = {
    0xAE020318, 0x8E020064,
};
#endif
