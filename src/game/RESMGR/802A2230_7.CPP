#include "COMMON/STATEPAIR.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "RESMGR/802A2230_7.H"

/** Set D_800D2C90 to one. */


s32 func_80299958_de();

extern void func_8029AA34_de(s32 *arg0);

void func_802A230C_de(void) {
    extern int D_800D2C90;
    D_800D2C90 = 1;
}

void func_802A2320_de(void) {
    if (D_800E28D8 == 1) {
        func_802A2480_de(func_80411DCC_de(func_80299958_de()), 0);
    }
}
