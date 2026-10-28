#include "include_asm.h"
#include "COMMON/EXTERNS_17.H"
#include "AUDIO/SPGETSTAT.H"

/** Read the SP status register. */
unsigned int Audio_ReadSignalProcessorStatus(void) {
    return *(volatile unsigned int *)0xA4040010;
}

#if defined(VERSION_US)
char rodata_unresolved_802BA0D4[12] =
    "\000\014m_SwimOffs";
#endif
