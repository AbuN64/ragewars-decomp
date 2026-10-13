#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041F1FC.h"
#include "types.h"
/* Advances a player panel from its ready state and starts its selection. */


extern State_func_80420C10_de *D_800E42D0;
extern u8 D_801462D5;
void func_8029973C_de(void);                           /* extern */
void func_8041B7B4_de(s32, s32, s32, State_func_80420C10_de *);         /* extern */
void func_8041CE10_de(void *, s32);                    /* extern */
void func_80420438_de(s32);                            


/* extern */

s32 func_80420C10_de(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_s0;
    s32 temp_s1;
    State_func_80420C10_de *temp_a3;

    func_8029973C_de();
    temp_s0 = arg2 & 0xFFFF;
    temp_s1 = temp_s0 * 0x4C8;
    temp_a3 = (State_func_80420C10_de *)&((PanelRecord *)D_800E42D0)[temp_s0];
    temp_a0 = temp_a3->unk14;
    switch (temp_a0) {
    case 1:
        if (D_801462D5 != 1) {
            D_800E42D0->unk1338 = 5;
            D_800E42D0->unk133C = 4;
            D_800E42D0->unk1354 = 3;
        }
        break;
    case 3:
        temp_a3->unk14 = 1;
        func_8041B7B4_de(D_800E42D0->unk4, temp_s0, 0, temp_a3);
        func_8041CE10_de(&((PanelRecord *)(temp_s1 + (s32)D_800E42D0))->target, 1);
        func_80420438_de(temp_s0);
        break;
    }
    return 0;
}
