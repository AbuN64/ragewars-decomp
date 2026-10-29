#include "include_asm.h"
#include "../../../include/EXTERNS.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "../../../include/PRINTF/_LDTOB.H"

/* 802C31B0.CPP */
/* This hook intentionally ignores both supplied words. */
void _Ldtob(void *unused_state, unsigned char unused_code)
{
}

#if defined(VERSION_EU_X)
unsigned int func_802BE3A8_eu_x_padding_BEFA8[2] = {
    0x0C0AFC24, 0xAFAB0010,
};
#endif

#if defined(VERSION_DE)
unsigned int func_802BE0C8_de_padding_BECC8[2] = {
    0x8FB20068, 0xAFB7004C,
};
#endif

/* g_XldtobEncodedWords_Xldtob.CPP */
#if defined(VERSION_US)
char func_802BE3A8_eu_x_padding_C3DB8[8] =
    "\000\007GT_COO";
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: func_802BE3A8_eu_x_padding_C3DB8 */
unsigned int g_XldtobEncodedWords[2] = {
    0x0C0B0FA8, 0xAFAB0010,
};
#endif

/* 802C6A00.CPP */
#if defined(VERSION_EU)
unsigned char g_XldtobTrailingBytes[8] = { 0x8F, 0xA2, 0x00, 0x18, 0x8C, 0x42, 0x00, 0x14 };
#endif
