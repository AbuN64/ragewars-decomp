#include "include_asm.h"
#include "COMMON/GUMTXL2F.H"
#include "sdk/MATH/aigetlen.H"

/** Read the hardware register at 0xA450000C. */
unsigned int osAiGetStatus(void) {
    return *(volatile unsigned int *)0xA450000C;
}

#if defined(VERSION_US)
char s_AigetlenTPmeTinyText[12] =
    "_t\015m_pmeTiny";
#endif
