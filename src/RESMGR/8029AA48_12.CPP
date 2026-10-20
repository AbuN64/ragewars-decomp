#include "COMMON/CALLBACK.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "RESMGR/8029AA48_12.H"
#include "SCENE/802508E0_13.H"
#include "RESMGR/resmgr_string_memory.H"

/** Store a word through the global pointer at D_8014D0B0. */


void *func_8025305C_de(s32);



void func_8029AA78_de(void) {
    Callback *temp_v0;
    temp_v0 = func_8025305C_de(0xC44);
    D_8014D0B0 = temp_v0;
    func_802A0748_de(temp_v0, 0, 0xC44);
}

void func_8029AAAC_de(void) {
    func_802547E4_de(D_8014D0B0);
    D_8014D0B0 = 0;
}
