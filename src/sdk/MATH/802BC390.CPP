#include "include_asm.h"
#include "COMMON/EXTERNS_16.H"
#include "sdk/MATH/802BC390.H"

/** Read the hardware register at 0xA450000C. */
unsigned int osAiGetStatus(void) {
    return *(volatile unsigned int *)0xA450000C;
}

#if defined(VERSION_US)
char rodata_unresolved_802B7204[12] =
    "_t\015m_pmeTiny";
#endif
