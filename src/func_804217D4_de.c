#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80420E90.h"
#include "types.h"
#include "stddef.h"
/* Advances the animation frame countdown and wraps exhausted frames. */
Frame_func_804217D4_de *func_8040EC30_de(s32, s32); /* extern */
void func_80421568_de(void *, void *); /* extern */
extern State_func_804217D4_de *D_800E4400;
void func_804217D4_de(void) {
    s32 temp_v0;
    Frame_func_804217D4_de *temp_a0;
    Frame_func_804217D4_de *temp_a0_2;
    Frame_func_804217D4_de *temp_v0_2;
    temp_v0 = D_800E4400->unk2C - 1;
    D_800E4400->unk2C = temp_v0;
    if (temp_v0 <= 0) {
#if defined(VERSION_DE)
        temp_v0_2 = func_8040EC30_de(D_800E4400->unk8, 0x3B2);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
        temp_v0_2 = func_8040EC30_de(D_800E4400->unk8, 0x3B8);
#elif defined(VERSION_EU_X)
        temp_v0_2 = func_8040EC30_de(D_800E4400->unk8, 0x3BC);
#endif
        temp_a0 = D_800E4400->unk20;
        temp_a0->unk16 = (u16) (temp_a0->unk16 - 1);
        temp_a0_2 = D_800E4400->unk20;
        if (((s16) temp_a0_2->unk16 + temp_v0_2->unk1A) < 0) {
            temp_a0_2->unk16 = 2U;
            func_80421568_de(temp_a0_2, D_800E4400);
        }
        D_800E4400->unk2C = 1;
    }
}
