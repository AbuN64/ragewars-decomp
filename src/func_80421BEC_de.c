#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80420E90.h"
#include "types.h"
/* Advances menu selection timing and dispatches the selected action. */



void func_80298368_de(s32);                               /* extern */
void func_8029973C_de();                                  /* extern */
void func_802A2360_de();                                  /* extern */
void func_802A2394_de();                                  /* extern */
s32 func_8041A470_de(void *);                          /* extern */
extern s32 D_800E28E0;                          
extern State_func_80421BEC_de *D_800E4450;                     

s32 func_80421BEC_de(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_a0;
    CellRecAt1A *temp_a0;
    CellRecAt1A *temp_v1;

    if (D_800E28E0 >= 2) {
        func_802A2394_de();
        return 0;
    }
    func_802A2360_de();
    temp_v0 = func_8041A470_de(D_800E4450->unk0);
    switch (temp_v0) {                              /* irregular */
    case 3:
        temp_v0_2 = D_800E4450->unkC - 1;
        D_800E4450->unkC = temp_v0_2;
        if (temp_v0_2 <= 0) {
            temp_v1 = D_800E4450->unk8;
            temp_v1->unk16 = (u16) (temp_v1->unk16 - 1);
            temp_a0 = D_800E4450->unk8;
            if (((s16) temp_a0->unk16 + temp_a0->unk1A) < 0) {
                temp_a0->unk16 = (u16) D_800E4450->unk0->unk44->unk1A;
            }
            D_800E4450->unkC = temp_v0;
        }
block_12:
        return 0;
    case 4:
        func_8029973C_de();
        var_a0 = D_800E4450->unk10;
        if (var_a0 == -1) {
            var_a0 = 3;
        }
        func_80298368_de(var_a0);
        goto block_12;
    default:
        return 0;
    }
}
