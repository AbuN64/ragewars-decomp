#include "include_asm.h"
#include "COMMON/OSTASK_T.H"
#include "AUDIO/802BF1F0.H"
#include "sdk/libgultra/sptaskyield.h"

void osSpTaskYield(void) { Audio_WriteSignalProcessorStatus(0x400U); }

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BA06C[1] = {
    0x7265644A,
};
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_802BA13C_de_padding_BAD3C[4] = { 0x0C, 0x0A, 0xE8, 0x60 };
#endif

