#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "span_C76B0/data.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
#include "TYPES.H"
#include "span_1000/code_8022E938.h"

extern void func_8022AF74_de(Shared_ActorView *arg0, s32 arg1);


void func_802328D8_de(Shared_ActorView *arg0, WeaponFireState *arg1) {
    Shared_ActorView *temp_a0;
    s16 idx;

    temp_a0 = arg0->self;
    idx = temp_a0->selectedAction;
    arg1->charge = ((WeaponInfo *)D_800D052C[idx])->chargeRate * D_800C3014_de;
    if ((temp_a0->selectedAction == 5) && (temp_a0->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0x46A);
    }
}
