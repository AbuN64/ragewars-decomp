#include "shared/character_selection_ids.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_804264F0.h"
#include "span_16E000/code_8040C780.h"

extern struct Row_func_80426788_de D_800E3A58[];
extern s32 func_8025DF34_de(s32);
extern void func_80298368_de(s32), func_8029973C_de(void), func_802A2360_de(void);
extern void func_80419F24_de(void *), func_80419F58_de(void *, s32);
extern s32 func_80419F38_de(void *), func_8040EBD0_de(struct Node_func_8040EB48_de *);
extern void func_80420438_de(s32), func_80420850_de(s32);
extern s32 func_8041F1D8_de(s32);
extern struct Node_func_8040EB48_de *func_8041B7FC_de(struct Slots_func_8041B7FC_de *, s32);

/* Advances the selection panels, cursor highlight and character previews. */
s32 func_8041F6C8_de(s32 arg0,s32 arg1,s32 arg2) {
    Vec3 scale;
    f32 temp_f0;
    s16 temp_a0_4;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 var_s3;
    s32 empty_slot;
    MenuWidget *temp_a0_2;
    MenuWidget *temp_a0_3;
    MenuWidget *temp_a0_5;
    MenuWidget *temp_a0_6;
    MenuWidget *temp_a0_7;
    MenuWidget *temp_a1;
    MenuWidget *temp_a1_2;
    struct Node_func_8040EB48_de *temp_v0_3;

    temp_v0 = D_800E42D0->phase;
    switch (temp_v0) {
    case 1:
        temp_a1 = D_800E42D0->header;
        temp_a1->x = (u16) (temp_a1->x + (u16)D_800E42D0->headerStep);
        temp_a1_2 = D_800E42D0->footer;
        temp_a1_2->x = (u16) (temp_a1_2->x - (u16)D_800E42D0->footerStep);
        temp_v0_2 = D_800E42D0->timer - 1;
        D_800E42D0->timer = temp_v0_2;
        if (temp_v0_2 <= 0) {
            func_8025DF34_de(0xE79);
            func_8040E8D8_de(D_800E42D0->promptItem, 1);
            func_80419F58_de(D_800E42D0->prompt, 4);
            D_800E42D0->phase = 4;
            D_800E42D0->timer = 4;
        }
        break;
    case 2:
        temp_a0_5 = D_800E42D0->header;
        temp_a0_5->x = (u16) (temp_a0_5->x - (u16)D_800E42D0->headerStep);
        temp_a0_6 = D_800E42D0->footer;
        temp_a0_6->x = (u16) (temp_a0_6->x + (u16)D_800E42D0->footerStep);
        temp_v0_4 = D_800E42D0->timer - 1;
        D_800E42D0->timer = temp_v0_4;
        if (temp_v0_4 <= 0) {
            D_800E42D0->phase = 3;
            func_8029973C_de();
            func_80298368_de(D_800E42D0->result);
            return 0;
        }
        break;
    case 3:
        func_802A2360_de();
        break;
    case 4:
        D_800E42D0->timer = D_800E42D0->timer - 1 < 0 ? 0 :
            D_800E42D0->timer - 1 > D_800E42D0->timer ? D_800E42D0->timer : D_800E42D0->timer - 1;
        if ((D_800E42D0->timer <= 0) && (func_80419F38_de(D_800E42D0->prompt) != 0)) {
            func_80419F24_de(D_800E42D0->prompt);
            D_800E42D0->phase = 6;
            D_800E42D0->timer = 4;
            func_8040E8D8_de(D_800E42D0->pulse, 1);
        }
        break;
    case 5:
        func_8025DF34_de(0xE78);
        D_800E42D0->phase = 2;
        D_800E42D0->timer = 4;
        func_8040E8D8_de(D_800E42D0->promptItem, 0);
        func_8040E8D8_de(D_800E42D0->pulse, 0);
        break;
    case 7: break;
    case 6:
        temp_a0_7 = D_800E42D0->pulse;
        temp_a0_7->alpha = (u8) (temp_a0_7->alpha + (u8)D_800E42D0->pulseStep);
        temp_v0_6 = D_800E42D0->timer - 1;
        D_800E42D0->timer = temp_v0_6;
        if (temp_v0_6 <= 0) {
            D_800E42D0->pulse->alpha = 0xC8;
            D_800E42D0->phase = 3;
        }
        break;
    }
        if (D_800E42D0->phase == 3) {
            var_s3 = 0;
            empty_slot = CHARACTER_EMPTY_SLOT;
            D_800E42D0->clock = (s32) (D_800E42D0->clock + arg2);
            do {
                if (D_800E42D0->players[var_s3].unkC == 1) {
                    if (D_800E42D0->players[var_s3].highlight != 0) {
                        temp_f0 = (func_802B6560_de((f32) var_s3 + ((f32) D_800E42D0->clock * 0.0033333334f)) * 70.0f) + 170.0f;
                        temp_a0_2 = (&D_800E42D0->players[var_s3])->highlight;
                        temp_a0_2->alpha=(unsigned int)temp_f0;
                    }
                    temp_v0_3 = func_8041B7FC_de(D_800E42D0->unk4, var_s3);
                    temp_a0_3 = (&D_800E42D0->players[var_s3])->highlight;
                    if ((temp_a0_3->x != (temp_v0_3->x - 2)) || (temp_a0_3->y != (temp_v0_3->y - 2))) {
                        func_8025DF34_de(0xE7F);
                        if (func_8040EBD0_de(temp_v0_3) == 0) {
                            temp_a0_4 = temp_v0_3->resource;
                            if (temp_a0_4 != empty_slot) {
                                (&D_800E42D0->players[var_s3])->kind = (s32) temp_a0_4;
                                temp_s0 = func_8041F1D8_de(temp_a0_4);
                                temp_v1 = func_8041F18C_de((&D_800E42D0->players[var_s3])->kind);
                                scale.x = D_800E3A58[temp_v1].scale[var_s3];
                                scale.y = D_800E3A58[temp_v1].scale[var_s3];
                                scale.z = D_800E3A58[temp_v1].scale[var_s3];
                                func_8041CAD8_de(D_800E42D0->players[var_s3].model, 9, temp_s0 + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[temp_v1].position[var_s3], D_800E3A58[temp_v1].distance[var_s3], D_800E3A58[temp_v1].light[var_s3]);
                            } else {
                                func_80420850_de(var_s3);
                            }
                        } else {
                            (&D_800E42D0->players[var_s3])->kind = -1;
                        }
                        func_80420438_de(var_s3);
                    } else if (temp_v0_3->resource == empty_slot) {
                        func_80420850_de(var_s3);
                    }
                    D_800E42D0->players[var_s3].highlight->x = (s16) ((u16) temp_v0_3->x - 2);
                    D_800E42D0->players[var_s3].highlight->y = (s16) ((u16) temp_v0_3->y - 2);
                }
                var_s3 += 1;
            } while (var_s3 < 4);
        }
        return 0;
}
