#include "TYPES.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "../../../../sdk/include/OS/__OSRESETGLOBALINTMASK.H"
#include "../../../../sdk/include/os.h"

/* 802C0390_6.CPP */
#if defined(VERSION_DE)
unsigned char g_ResetglobalintmaskTrailingBytes[8] = { 0x00, 0x80, 0x80, 0x21, 0xAF, 0xB5, 0x00, 0x24 };
#endif

/* 802C04C0.CPP */
void __osResetGlobalIntMask(s32 interruptMask) {
    u32 savedInterruptMask;
    s32 *p;

    savedInterruptMask = __osDisableInt();
    p = &g_globalInterruptMask;
    *p &= ~interruptMask | 0x401;
    __osRestoreInt(savedInterruptMask);
}
