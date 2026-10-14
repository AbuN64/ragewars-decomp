#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043A0A4.h"
#include "types.h"

extern struct Screen_func_8043B0CC_de *D_800E59E0;
extern struct Shape_typemap_165 D_800E5B44[];
extern HudStatusShared_Settings D_801462C8;
extern Record_func_80433914_de D_80102B00[];
extern s32 func_8022F4DC_de(s32 record, s32 item);
extern void func_8043B49C_de(s32 player, s32 category, s32 choice);

/* Step an equipment choice, rejecting duplicates and the locked item 15. */
void func_8043AE5C_de(s32 player, s32 step) {
    s32 count;
    s32 low;
    s32 high;
    s32 category;
    s32 value;
    s32 valid;
    s32 i;

    if (D_800E59E0->entries[player].mode == 2) {
        count = 0;
        low = 0;
        high = 0;
        category = D_800E59E0->entries[player].column;
        switch (category) {
        case 0:
        case 1:
            count = 4;
            low = 0;
            high = 1;
            break;
        case 2:
        case 3:
            count = 8;
            low = 2;
            high = 3;
            break;
        case 4:
            count = 3;
            low = 4;
            high = 4;
            break;
        case 5:
            return;
        }
        value = D_800E59E0->entries[player].values[category];
        value += step;
        do {
            if (value >= count) {
                value = 0;
            }
            if (value < 0) {
                value = count - 1;
            }
            valid = 1;
            for (i = low; i < high + 1; i++) {
                if (valid != 1) {
                    break;
                }
                if (D_800E59E0->entries[player].values[i] == value) {
                    value += step;
                    valid = 0;
                }
            }
            if (valid == 1 && (category == 2 || category == 3) &&
                D_800E5B44[value].field_8 == 15 &&
                !(D_801462C8.flags & 0x10000000) &&
                !func_8022F4DC_de((s32)&D_80102B00[player], 15)) {
                value += step;
                valid = 0;
            }
        } while (!valid);
        func_8043B49C_de(player, category, value);
        D_800E59E0->entries[player].values[category] = value;
    }
}
