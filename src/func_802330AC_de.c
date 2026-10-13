#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "span_C76B0/data.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
/* FAKEMATCH: retains inherited volatile storage qualifiers to preserve compiler load/store order; semantic volatility has not been established. */
#include "types.h"
extern s32 D_80140FF8;
extern void *D_800D052C[];



extern void func_8022AEA0_de(void *arg0, s32 arg1);
extern void func_8022AF74_de(void *arg0, s32 arg1);














void func_802330AC_de(void *arg0, void *arg1) {
    Shared_ActorView *temp_s0;
    Shared_ActorView *temp_a0;
    s16 index;

    temp_s0 = ((Shared_ActorView *)arg0)->self;
    ((WeaponFireState *)arg1)->cueTimer = 0;
    if ((temp_s0->remote == 0) &&
        (D_80140FF8 == 1)) {
        func_8021A9A4_de(((Shared_ActorView *)arg0)->self, 0x3F9);
    } else {
        func_8021A9A4_de(((Shared_ActorView *)arg0)->self, 0x4CB);
    }
    func_8022AEA0_de(temp_s0, 0x78A);
    func_8022AF74_de(temp_s0, 0x780);

    temp_a0 = ((Shared_ActorView *)arg0)->self;
    index = temp_a0->selectedAction;
    ((WeaponFireState *)arg1)->charge =
        ((WeaponInfo *)D_800D052C[index])->chargeRate *
        D_800C3044_de;
    if ((temp_a0->selectedAction == 8) &&
        (temp_a0->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0xA3C);
    }
}
