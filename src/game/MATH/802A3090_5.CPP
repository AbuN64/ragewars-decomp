#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/STATEPAIR.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"

/** Set D_800D2C90 to one. */


s32 func_80299958_de();

extern void func_8029AA34_de(s32 *arg0);

/** Return the global word at D_800D2C98. */




void func_802A2360_de(void) {
    s32 *p;

    p = &D_800CDA24;
    if (*p != 1) {
        *p = 1;
        func_8029AA34_de(p);
    }
}

void func_802A2394_de(void) {
    D_800CDA24 = 0;
}

int func_802A23A4_de(void) {
    return D_800CDA24;
}

int func_802A23B4_de(void) {
    return D_800D2C98;
}

void func_802A23C4_de(s32 arg0) {
    if (arg0 == 1) {
        D_800CDA2C = arg0;
        return;
    }
    D_800CDA2C = 0;
}

int func_802A23F0_de(void) {
    return D_800CDA2C;
}
