#include "common/types_1dc8418c21db.h"
#include "shared/gameplay_transition.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"

extern void *D_800D052C[];

extern void func_8022AF74_de(void *arg0, s32 arg1);










void func_80232C88_de(void *arg0, void *arg1) {
    void *temp_a0;
    s16 idx;

    temp_a0 = ((Shared_ActorView *)arg0)->self;
    idx = ((Shared_ActorView *)temp_a0)->selectedAction;
    ((WeaponFireState *)arg1)->charge = ((WeaponInfo *)D_800D052C[idx])->chargeRate * D_800C3020_de;
    if ((((Shared_ActorView *)temp_a0)->selectedAction == 8) && (((Shared_ActorView *)temp_a0)->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0xA3C);
    }
}
