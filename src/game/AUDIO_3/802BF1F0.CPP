#include "include_asm.h"
#include "COMMON/OSTASK_T.H"
#include "AUDIO_3/802BF1F0.H"

/** Write a word to the SP status register. */
void Audio_WriteSignalProcessorStatus(unsigned int statusCommand) {
    *(volatile unsigned int *)0xA4040010 = statusCommand;
}

#if defined(VERSION_US)
char rodata_unresolved_802BA044[12] =
    "\000\020m_StartJum";
#endif
