#include "include_asm.h"
#include "COMMON/OSTASK_T.H"
#include "AUDIO/SPSETSTAT.H"
#include "sdk/libgultra/sptaskyield.h"

void osSpTaskYield(void) { Audio_WriteSignalProcessorStatus(0x400U); }

#if defined(VERSION_US)
unsigned int k_SptaskyieldEncodedWords[1] = {
    0x7265644A,
};
#endif

#if defined(VERSION_DE)
unsigned char g_SptaskyieldTrailingBytes[4] = { 0x0C, 0x0A, 0xE8, 0x60 };
#endif

