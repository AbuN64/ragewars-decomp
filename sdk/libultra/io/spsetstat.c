#include "include_asm.h"
#include "COMMON/OSTASK_T.H"
#include "../../include/libultra/io/spsetstat.h"

/** Write a word to the SP status register. */
void __osSpSetStatus(unsigned int statusCommand) {
    *(volatile unsigned int *)0xA4040010 = statusCommand;
}

#if defined(VERSION_US)
char s_startJumpMemberNameFragment[12] =
    "\000\020m_StartJum";
#endif
