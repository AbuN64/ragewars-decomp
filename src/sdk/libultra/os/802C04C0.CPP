#include "TYPES.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_11.H"
#include "sdk/OS/802C04C0.H"
#include "sdk/os.h"


void func_802BB3D0_de(s32 arg0) {
    u32 temp_v0;
    s32 *p;

    temp_v0 = func_802BCF30_de();
    p = &D_800D5258;
    *p &= ~arg0 | 0x401;
    __osRestoreInt(temp_v0);
}
