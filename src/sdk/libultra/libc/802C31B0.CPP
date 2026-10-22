#include "include_asm.h"
#include "SDK/EXTERNS.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "SDK/PRINTF/802C31B0.H"

/* This hook intentionally ignores both supplied words. */
void func_802BE0C0_de(void *unused_state, unsigned char unused_code)
{
}

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", func_802BE3A8_eu_x_padding_BEFA8);
#endif

#if defined(VERSION_DE)
INCLUDE_DATA("span_1000", func_802BE0C8_de_padding_BECC8);
#endif
