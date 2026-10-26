#include "include_asm.h"
#include "COMMON/OSTASK_T.H"
#include "AUDIO_3/802BF1F0.H"
#include "sdk/libgultra/sptaskyield.h"

void func_802BA120_de(void) { func_802BA100_de(0x400U); }

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BA06C[1] = {
    0x7265644A,
};
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_802BA13C_de_padding_BAD3C[4] = { 0x0C, 0x0A, 0xE8, 0x60 };
#endif

#if defined(VERSION_DE)
unsigned int data_unresolved_802BA140[1] = {
    0x27BDFFE8,
};
#endif
