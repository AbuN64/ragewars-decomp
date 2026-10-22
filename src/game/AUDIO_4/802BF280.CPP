#include "include_asm.h"
#include "COMMON/EXTERNS_17.H"
#include "AUDIO_4/802BF280.H"

/** Read the SP status register. */
unsigned int func_802BA190_de(void) {
    return *(volatile unsigned int *)0xA4040010;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802BA0D4);
#endif
