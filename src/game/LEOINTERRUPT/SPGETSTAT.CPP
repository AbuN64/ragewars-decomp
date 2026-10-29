#include "include_asm.h"
#include "AUDIO/SPGETSTAT.H"

/** Read the SP status register. */
unsigned int Audio_ReadSignalProcessorStatus(void) {
    return *(volatile unsigned int *)0xA4040010;
}

#if defined(VERSION_US)
char s_swimOffsetMemberNameFragment[12] =
    "\000\014m_SwimOffs";
#endif
