#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"

extern char D_8011D8D0;

extern void func_802850C8_de(void *arg0, void *arg1, f32 *arg2);

extern f32 func_80216F44_de(Player *, Vec3);
extern f32 func_8020AA0C_de(void *arg0);

void func_8020A458_de(void *object, void *settings) {
    AiController *arg0 = object;
    AiConfig *arg1 = settings;
    s32 timer;
    s32 minus_one;
    Player *record;
    f32 distance;

    if (arg0 == 0) {
        return;
    }

    timer = arg0->unk2EC;
    if (timer == 0) {
        f32 value;

        func_802850C8_de(&D_8011D8D0, arg0->player, &value);
        if (value < D_800C1D1C_de) {
            f32 k = D_800C1D24_de;
            f32 threshold = func_80274564_de(D_800C1D20_de) + k;

            if ((f32) arg1->unk34 < threshold) {
                s32 base = arg1->unk24;
                arg0->unk240 =
                    (s32) ((f32) base + func_80274564_de(k) * (f32) arg1->unk28);
            }
            arg0->unk2EC = arg1->unk2C;
            arg0->unk2EC =
                (s32) ((f32) arg0->unk2EC +
                       func_80274564_de(k) * (f32) arg1->unk30);
            arg0->unk2EC += arg0->unk240;
        }
    } else {
        arg0->unk2EC = timer - 1;
    }

    timer = arg0->unk2E4;
    if (timer > 0) {
        arg0->unk2E4 = timer - 1;
        return;
    }
    minus_one = -1;
    if (timer == minus_one) {
        arg0->unk23C = 1;
        arg0->unk2E8 += minus_one;
    } else {
        record = arg0->target->player;
        distance = func_80216F44_de(arg0->player,
                                 record->pos);
        if (func_8020AA0C_de(arg0) < distance) {
            return;
        }
        arg0->unk23C = 1;
        arg0->unk2E4 = minus_one;
    }
    if (arg0->unk2E8 == 0) {
        arg0->unk23C = 0;
        func_8020A95C_de(arg0, arg1);
    }
}
