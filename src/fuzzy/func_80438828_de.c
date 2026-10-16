#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_80438614_de_closed.h"
#include "span_16E000/code_8043962C.h"
#include "TYPES.H"
void func_804399D0(MenuModelItem *item);
void func_80438614_de(void);
extern s32 D_800D15E0;
extern f32 D_800D15F0;
extern f32 D_800DDF3C_de;

void func_80438828_de(void) {
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_v0;

    temp_s1 = D_800E5830->selected;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    if ((D_800E5830->rows[temp_s1].unk0 >= 0) && (*((s32 *) ((u8 *) (D_800E5830) + 448)) != 0)) {
        D_800D15E0 = 1;
        D_800D15F0 = (f32) D_800E5830->rows[temp_s1].unk8;
        func_804399D0((void *)&D_800E5830->modelWorkspace);
        D_800D15F0 = D_800DDF3C_de;
        temp_v1 = D_800E5830->rows[temp_s1].unk4;
        D_800D15E0 = 0;
        switch (temp_v1) {                          /* irregular */
        case 0:
            temp_v0 = D_800E5830->rows[temp_s1].unk8 + 2;
            D_800E5830->rows[temp_s1].unk8 = temp_v0;
            if (temp_v0 >= 0x97) {
                D_800E5830->rows[temp_s1].unk8 = 0x96;
                D_800E5830->rows[temp_s1].unk4 = 2;
                if (temp_s1 <= 0) {
                    var_v0 = temp_s1 * 4;
                    if (D_800E5830->rows[temp_s1 + 1].unk0 > 0) {
                        D_800E5830->rows[temp_s1].unkC = 0x96;
                        return;
                    }
                    goto block_15;
                }
                var_v0 = temp_s1 * 4;
block_15:
                D_800E5830->rows[temp_s1].unkC = 0x38F;
                return;
            }
            break;
        case 2:
            temp_v1_2 = D_800E5830->rows[temp_s1].unkC;
            temp_v0_2 = temp_v1_2 - 1;
            if (temp_v1_2 != 0x38F) {
                D_800E5830->rows[temp_s1].unkC = temp_v0_2;
                if (temp_v0_2 <= 0) {
                    D_800E5830->rows[temp_s1].unk4 = 1;
                    return;
                }
            }
            break;
        case 1:
            temp_v0_3 = D_800E5830->rows[temp_s1].unk8 - 2;
            D_800E5830->rows[temp_s1].unk8 = temp_v0_3;
            if (temp_v0_3 < 0xA) {
                D_800E5830->rows[temp_s1].unk8 = 0xA;
                D_800E5830->selected += 1;
                func_80438614_de();
            }
            break;
        }
    }
}
