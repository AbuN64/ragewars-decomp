#include "include_asm.h"
#include "sdk/EXTERNS.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "sdk/PRINTF/802C31B0.H"

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
