#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_804379C8.h"
#include "types.h"
#include "stddef.h"
/* Advances a menu selection on its countdown and dispatches the exit action. */
void func_80298368_de(s32); /* extern */
void func_8029973C_de(); /* extern */
void func_802998A8_de(void); /* extern */
s32 func_8041A470_de(void *); /* extern */
extern State_func_80421BEC_de *D_800E5784; /* const */
s32 func_80437810_de(void) {
    s32 temp_a0_2;
    s32 temp_v0;
    s32 temp_v0_2;
    CellRecAt1A *temp_a0;
    CellRecAt1A *temp_v1;
    temp_v0 = func_8041A470_de(D_800E5784->unk0);
    switch (temp_v0) { /* irregular */
    case 3:
        temp_v0_2 = D_800E5784->unkC - 1;
        D_800E5784->unkC = temp_v0_2;
        if (temp_v0_2 <= 0) {
            temp_v1 = D_800E5784->unk8;
            temp_v1->unk16 = (u16) (temp_v1->unk16 - 1);
            temp_a0 = D_800E5784->unk8;
            if (((s16) temp_a0->unk16 + temp_a0->unk1A) < 0) {
                temp_a0->unk16 = (u16) D_800E5784->unk0->unk44->unk1A;
            }
            D_800E5784->unkC = temp_v0;
        }
block_10:
        return 0;
    case 4:
        func_8029973C_de();
        temp_a0_2 = D_800E5784->unk10;
        if (temp_a0_2 == -1) {
            func_802998A8_de();
            return 0;
        }
        func_80298368_de(temp_a0_2);
        goto block_10;
    default:
        return 0;
    }
}
