#include "include_asm.h"
#include "COMMON/EXTERNS_16.H"
#include "sdk/lib_802BB630/802BC390.H"

/** Read the hardware register at 0xA450000C. */
unsigned int func_802B72C0_de(void) {
    return *(volatile unsigned int *)0xA450000C;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802B7204);
#endif
