#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042F988.h"
#include "span_16E000/code_80434F4C.h"
#include "types.h"
/* Steps each channel's fade timer and writes the level its curve currently reaches. */


extern Blk *D_800E54A4;

extern Resource_func_80419E54_de *func_8041B7FC_de(s32, s32);
extern void func_80434E34_de(s32);
extern void func_80434EF4_de(s32);


void func_80433398_de(s32 arg0) {
    f32 temp_f0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_idx;
    Resource_func_80419E54_de *temp_s0;
    s32 var_s1;
    Blk *temp_a0;
    Blk *temp_a0_2;
    Blk *temp_v0_3;
    Blk *temp_v0_4;
    Blk *temp_v0_5;

    var_s1 = 0;
    do {
        temp_a0 = (Blk *)((char *)D_800E54A4 + (var_s1 * 0xB68));
        temp_v1 = temp_a0->unk58;
        switch (temp_v1) {
        case 0:
            func_80434FC4_de(var_s1);
            break;
        case 0xC:
            temp_s0 = func_8041B7FC_de(D_800E54A4->unk4, var_s1);
            temp_v0_4 = (Blk *)((char *)D_800E54A4 + (var_s1 * 4));
            temp_f0 = (func_802B6560_de((f32)var_s1 + ((f32)temp_v0_4->unk2C * 0.005f)) * 100.0f) + 150.0f;
            temp_s0->value = temp_f0;
            temp_a0_2 = (Blk *)((char *)D_800E54A4 + (var_s1 * 0xB68));
            temp_v1_2 = temp_a0_2->unkBA0;
            switch (temp_v1_2) {
            case 0:
                temp_v0 = temp_a0_2->unkBA4 + 1;
                temp_a0_2->unkBA4 = temp_v0;
                if (temp_v0 >= 6) {
                    func_80434EF4_de(var_s1);
                }
                break;
            case 1:
                temp_v0_2 = temp_a0_2->unkBA4 + 1;
                temp_a0_2->unkBA4 = temp_v0_2;
                if (temp_v0_2 >= 6) {
                    func_80434E34_de(var_s1);
                }
                break;
            case 2:
                break;
            }
            break;
        case 4:
            temp_idx = ((temp_a0->unkB30 - temp_a0->unkB34) * 4) + (var_s1 * 0xB68);
            temp_s0 = ((Blk *)((char *)D_800E54A4 + temp_idx))->unkB38;
            temp_v0_5 = (Blk *)((char *)D_800E54A4 + (var_s1 * 4));
            temp_f0 = (func_802B6560_de((f32)var_s1 + ((f32)temp_v0_5->unk2C * 0.005f)) * 100.0f) + 150.0f;
            temp_s0->value = temp_f0;
            break;
        }
        temp_v0_3 = (Blk *)((char *)D_800E54A4 + (var_s1 * 4));
        temp_v0_3->unk2C = temp_v0_3->unk2C + arg0;
        var_s1 += 1;
    } while (var_s1 < 4);
}
