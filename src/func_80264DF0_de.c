#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802646F4.h"
#include "types.h"


extern f32 D_80142C38[2];

extern func_8020CA10_G1 D_800C4310_de;

extern func_8020CA10_G1 D_800C4314_de;

extern func_8020CA10_G1 D_800C4318_de;






s32 func_80264DF0_de(void *arg0) {
    Player_func_80264EE0_de *player = arg0;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 temp_v1;
    Curve_func_80264EE0_de *temp_a0;

    temp_a0 = player->curve;
    temp_v1 = temp_a0->type;
    switch (temp_v1) {
    case 0: {
        f32 divisor = D_80142C38[1];
        temp_f1 = player->time + (D_800C4310_de.unk0 / divisor);
        player->time = temp_f1;
        if (temp_a0->length <= temp_f1) {
            return 1;
        }
        goto block_7;
    }
    case 1: {
        RandomCurve *random = (void *)temp_a0;
        f32 divisor = D_80142C38[1];
        temp_f1_2 = player->time - (D_800C4314_de.unk0 / divisor);
        player->time = temp_f1_2;
        if (temp_f1_2 <= 0.0f) {
            player->time =
                temp_f1_2 + random->period;
            player->value = func_80274A90_de(
                (f32)random->minimum * D_800C4318_de.unk0,
                (f32)random->maximum * D_800C4318_de.unk0);
        }
        goto block_7;
    }
    default:
block_7:
        return 0;
    }
}
