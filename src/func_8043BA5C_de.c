#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043A0A4.h"
#include "types.h"

/* Moves the cursor of player p's 0x4D0-byte entry of D_800E59E0 to column c: unless c is 5 it
   hides the item whose id D_800E5A06[p * 19 + c] names in the screen window, shows the item
   D_800E5A1A[p * 19 + c] names with alpha 0x96, stores c as the entry's selection and redraws that
   column through func_8043B49C_de with the entry's value for it. */









extern struct Screen_func_8043BA5C_de *D_800E59E0;
extern struct StateFlags D_800E5A06[];
extern struct StateFlags D_800E5A1A[][19];
extern struct Resource_func_80419E54_de *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);
extern void func_8040E928_de(struct Resource_func_80419E54_de *, s32);
extern void func_8043B49C_de(s32, s32, s32);

void func_8043BA5C_de(s32 player, s32 column) {
    struct Resource_func_80419E54_de *item;

    if (column != 5) {
        item = func_8040EC30_de(D_800E59E0->entries[0].window, D_800E5A06[player * 19 + column].value);
        func_8040E8D8_de(item, 1);
    }
    item = func_8040EC30_de(D_800E59E0->entries[0].window, D_800E5A1A[player][column].value);
    func_8040E928_de(item, 1);
    item->value = 0x96;
    D_800E59E0->entries[player].selection = column;
    func_8043B49C_de(player, column, D_800E59E0->entries[player].values[column]);
}
