#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "span_C76B0/data.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"

extern void *D_800D052C[];
extern void func_8022AF74_de(void *arg0, s32 arg1);


void func_802328D8_de(void *arg0, void *arg1) {
    Shared_ActorView *temp_a0;
    s16 idx;

    temp_a0 = ((Shared_ActorView *)arg0)->self;
    idx = temp_a0->selectedAction;
    ((WeaponFireState *)arg1)->charge = ((WeaponInfo *)D_800D052C[idx])->chargeRate * D_800C3014_de;
    if ((temp_a0->selectedAction == 5) && (temp_a0->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0x46A);
    }
}
