#include "TYPES.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_11.H"
#include "sdk/OS/802C04C0.H"
#include "sdk/os.h"


void func_802BB3D0_de(s32 interruptMask) {
    u32 savedInterruptMask;
    s32 *p;

    savedInterruptMask = __osDisableInt();
    p = &D_800D5258;
    *p &= ~interruptMask | 0x401;
    __osRestoreInt(savedInterruptMask);
}
