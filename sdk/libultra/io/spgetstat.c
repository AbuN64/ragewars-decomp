#include "include_asm.h"
#include <ultra64.h>
#include <PR/os_internal_rsp.h>

/** Read the SP status register. */
unsigned int __osSpGetStatus(void) {
    return *(volatile unsigned int *)0xA4040010;
}

#if defined(VERSION_US)
char s_swimOffsetMemberNameFragment[12] =
    "\000\014m_SwimOffs";
#endif
