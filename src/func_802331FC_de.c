#include "common/types_1dc8418c21db.h"
#include "shared/gameplay_transition.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
/* FAKEMATCH: retains inherited volatile storage qualifiers to preserve compiler load/store order; semantic volatility has not been established. */
#include "types.h"

extern struct Shape_func_8020AF9C_de_2 D_80140FF8;
extern void *D_800D052C[];
extern f32 D_800C3048_de[2];

extern void func_802227F4_de(void *, void *, s32);

extern s32 func_80214178_de(void *, void *, s32);
extern void func_8022AEA0_de(void *arg0, s32 arg1);
extern void func_8022AF74_de(void *arg0, s32 arg1);












void func_802331FC_de(void *arg0, void *arg1) {
    void *temp_s0;
    void *temp_a0;
    s16 index;

    temp_s0 = ((Shared_ActorView *)arg0)->self;
    if (((WeaponFireState *)arg1)->mode == 2) {
        func_802227F4_de(temp_s0, temp_s0, 2);
    } else {
        ((WeaponFireState *)arg1)->cueTimer = D_800C3048_de[0];
        if ((((Shared_ActorView *)temp_s0)->remote == 0) &&
            (D_80140FF8.field_0 == 1)) {
            func_8021A9A4_de(((Shared_ActorView *)arg0)->self, 0x3FB);
        } else {
            func_8021A9A4_de(((Shared_ActorView *)arg0)->self, 0x4CD);
        }
        func_80214178_de(arg0, arg1, 4);
        func_8022AEA0_de(temp_s0, 0x977);
        func_8022AF74_de(temp_s0, 0x974);

        temp_a0 = ((Shared_ActorView *)arg0)->self;
        index = ((Shared_ActorView *)temp_a0)->selectedAction;
        ((WeaponFireState *)arg1)->charge =
            ((WeaponInfo *)D_800D052C[index])->chargeRate *
            D_800C3048_de[1];
        if ((((Shared_ActorView *)temp_a0)->selectedAction == 8) &&
            (((Shared_ActorView *)temp_a0)->field11C0 == 0)) {
            func_8022AF74_de(temp_a0, 0xA3C);
        }
    }
}
