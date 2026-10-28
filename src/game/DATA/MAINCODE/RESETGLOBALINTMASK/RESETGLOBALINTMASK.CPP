#include "TYPES.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/EXTERNS_11.H"
#include "sdk/OS/__OSRESETGLOBALINTMASK.H"
#include "sdk/os.h"

/* 802C0390_6.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802BB418_de_padding_BC018[8] = { 0x00, 0x80, 0x80, 0x21, 0xAF, 0xB5, 0x00, 0x24 };
#endif

/* 802C04C0.CPP */
void __osResetGlobalIntMask(s32 interruptMask) {
    u32 savedInterruptMask;
    s32 *p;

    savedInterruptMask = __osDisableInt();
    p = &D_800D5258;
    *p &= ~interruptMask | 0x401;
    __osRestoreInt(savedInterruptMask);
}
