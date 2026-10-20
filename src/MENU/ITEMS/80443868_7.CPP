#include "COMMON/ACTORRECAT260.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/RECORDRECATCV1.H"
#include "SDK/PFS/80443868_7.H"

/* Updates display flags and activates the selected resource. */
s32 func_8022A5A0_de(s32 *, s32);

 /* extern */


 /* extern */

 /* extern */
extern s32 D_80145040;

extern s32 D_801468F4[];

extern s32 D_8015375C[];

/* Updates object display flags and selects the requested resource. */


s32 func_8022A5A0_de(int *, s32);

                               /* extern */
extern int D_80145040;

 /* const */
extern void func_80264770_de(s32 kind);
extern s32 D_800E28C0[];
void func_80443CD4_de(ArgRecAt1C *arg0) {
    s32 temp_a1;
    s32 var_s0;
    ActorRecAt260 *temp_a0;
    ActorRecAt260 *temp_v0;
    ActorRecAt260 *temp_v1;
    ActorRecAt260 *temp_v1_2;
    ActorRecAt260 *temp_v1_3;
    ActorRecAt260 *temp_v1_4;
    ActorRecAt260 *temp_v1_5;
    temp_v1 = arg0->unkC;
    temp_v1->flags238 = (s32) (temp_v1->flags238 | 0x01800000);
    temp_v1_2 = arg0->unkC;
    temp_v1_2->flags260 = (s32) (temp_v1_2->flags260 | 0x01800000);
    temp_v1_3 = arg0->unkC;
    temp_v1_3->flags1c0 = (s32) (temp_v1_3->flags1c0 & 0xFE7FFFFF);
    temp_v1_4 = arg0->unkC;
    temp_v1_4->flags58 = (s32) (temp_v1_4->flags58 & 0xFE7FFFFF);
    temp_v1_5 = arg0->unkC;
    temp_v1_5->flags210 = (s32) (temp_v1_5->flags210 & 0xFE7FFFFF);
    D_8015375C[0] = 0;
    D_800E28C0[0] = 0;
    var_s0 = 0;
    if (D_801468F4[0] != 0) {
        temp_v0 = arg0->unkC;
        temp_v0->flags120 = (s32) (temp_v0->flags120 | 0x01000000);
    } else {
        temp_a0 = arg0->unkC;
        temp_a0->flags120 = (s32) (temp_a0->flags120 & 0xFEFFFFFF);
    }
    temp_a1 = arg0->unk1C;
    if (temp_a1 != 0) {
        var_s0 = func_8022A5A0_de(&D_80145040, temp_a1);
    }
    func_80264770_de(var_s0);
    func_80404E28_de(var_s0);
}

                          /* const */

void func_80443DD0_de(ArgRecAt1C *arg0) {
    s32 temp_a1;
    s32 var_v0;
    ActorRecAt260 *temp_a0;
    ActorRecAt260 *temp_v0;
    ActorRecAt260 *temp_v1;
    ActorRecAt260 *temp_v1_2;
    ActorRecAt260 *temp_v1_3;
    ActorRecAt260 *temp_v1_4;
    ActorRecAt260 *temp_v1_5;

    temp_a1 = arg0->unk1C;
    D_800E28C0[0] = 0;
    var_v0 = 0;
    if (temp_a1 != 0) {
        var_v0 = func_8022A5A0_de(&D_80145040, temp_a1);
    }
    func_80264770_de(var_v0);
    temp_v1 = arg0->unkC;
    temp_v1->flags238 = (s32) (temp_v1->flags238 | 0x01800000);
    temp_v1_2 = arg0->unkC;
    temp_v1_2->flags260 = (s32) (temp_v1_2->flags260 | 0x01800000);
    temp_v1_3 = arg0->unkC;
    temp_v1_3->flags1c0 = (s32) (temp_v1_3->flags1c0 & 0xFE7FFFFF);
    temp_v1_4 = arg0->unkC;
    temp_v1_4->flags58 = (s32) (temp_v1_4->flags58 & 0xFE7FFFFF);
    temp_v1_5 = arg0->unkC;
    temp_v1_5->flags210 = (s32) (temp_v1_5->flags210 & 0xFE7FFFFF);
    if (D_801468F4[0] != 0) {
        temp_v0 = arg0->unkC;
        temp_v0->flags120 = (s32) (temp_v0->flags120 | 0x01000000);
        return;
    }
    temp_a0 = arg0->unkC;
    temp_a0->flags120 = (s32) (temp_a0->flags120 & 0xFEFFFFFF);
}
