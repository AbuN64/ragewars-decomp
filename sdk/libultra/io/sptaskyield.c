#include "include_asm.h"
#include <ultra64.h>
#include <PR/os_internal_rsp.h>

void osSpTaskYield(void) { __osSpSetStatus(0x400U); }

#if defined(VERSION_US)
unsigned int k_SptaskyieldEncodedWords[1] = {
    0x7265644A,
};
#endif

#if defined(VERSION_DE)
unsigned char g_SptaskyieldTrailingBytes[4] = { 0x0C, 0x0A, 0xE8, 0x60 };
#endif

