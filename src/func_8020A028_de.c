#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"

extern f32 func_80216F44_de(Player *, Vec3);

void func_8020A028_de(AiController *arg0, AiConfig *arg1)
{
    s32 v0;
    f32 f20;
    f32 f1;
    f32 new_var;
    s32 s1;

    v0 = arg0->unk2EC;
    if (v0 > 0) {
        v0 = v0 - 1;
        arg0->unk2EC = v0;
        if (v0 == 0) {
            f20 = D_800C1CF4_de;
            if (func_80274564_de(f20) < D_800C1CF8_de) {
                arg0->unk2EC = -1;
                arg0->unk2E4 = arg1->unk1C;
                arg0->unk2E4 = (s32) ((f32) arg0->unk2E4
                    + (func_80274564_de(f20) * (f32) arg1->unk20));
                arg0->unk2E8 = arg1->unk24;
                arg0->unk2E8 = (s32) ((f32) arg0->unk2E8
                    + (func_80274564_de(f20) * (f32) arg1->unk28));
            } else {
                arg0->unk2EC = arg1->unk10;
                arg0->unk2EC = (s32) ((f32) arg0->unk2EC
                    + (func_80274564_de(f20) * (f32) arg1->unk14));
            }
        }
    }
    if (arg0->unk2EC == -1) {
        v0 = arg0->unk2E8 - 1;
        arg0->unk2E8 = v0;
        if (v0 == 0) {
            f20 = D_800C1CFC_de;
            arg0->unk2EC = arg1->unk10;
            arg0->unk2EC = (s32) ((f32) arg0->unk2EC
                + (func_80274564_de(f20) * (f32) arg1->unk14));
            arg0->unk2E4 = arg1->unk0;
            arg0->unk2E4 = (s32) ((f32) arg0->unk2E4
                + (func_80274564_de(f20) * (f32) arg1->unk4));
            arg0->unk2E8 = arg1->unk8;
            f1 = (f32) arg0->unk2E8
                + (func_80274564_de(f20) * (f32) arg1->unkC);
            arg0->unk240 = 0;
            arg0->unk2E8 = (s32) f1;
        } else {
            arg0->unk240 = 1;
        }
    }
    v0 = arg0->unk2E4;
    if (v0 > 0) {
        arg0->unk2E4 = v0 - 1;
        return;
    }
    if (arg0->unk240 > 0) {
        s1 = arg1->unk1C;
        new_var = func_80274564_de(D_800C1D00_de);
        if (1) {
            f20 = D_800C1D04_de;
            s1 = (s32) ((f32) s1 + (new_var * (f32) arg1->unk20));
        }
    } else {
        s1 = arg1->unk0;
        s1 = (s32) ((f32) s1 + (func_80274564_de(D_800C1D08_de) * (f32) arg1->unk4));
        f20 = D_800C1D0C_de;
    }
    {
        AiTarget *p = arg0->target;
        Player *q = p->player;
        if (!(f20 < func_80216F44_de(arg0->player,
                                    q->pos))) {
            arg0->unk23C = 1;
            arg0->unk2E4 = s1;
        }
    }
}
