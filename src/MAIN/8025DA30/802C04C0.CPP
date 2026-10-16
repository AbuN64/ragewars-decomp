#include "MAIN/8025DA30.H"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BB15C.h"
#include "TYPES.H"
#include "shared/func_802BB8B0_de_closed.h"


extern void __osRestoreInt(u32);

void func_802BB3D0_de(s32 arg0) {
    u32 temp_v0;
    s32 *p;

    temp_v0 = func_802BCF30_de();
    p = &D_800D5258;
    *p &= ~arg0 | 0x401;
    __osRestoreInt(temp_v0);
}
