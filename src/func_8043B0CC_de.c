#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043A0A4.h"
#include "types.h"

/* Enters player p's loadout panel on the screen D_800E59E0: marks the entry open, hides the panel
   item D_800E59E6[p][0], then by the entry's mode at 0x4D4 either hides column item
   D_800E59EE[p][5] and fades label D_800E5A1A[p][5] to alpha 0x23 (mode 0), or for each of the
   3 (mode 1) or 6 (mode 2 and any other) columns hides D_800E59EE[p][c], fades D_800E5A1A[p][c]
   to 0x23 and redraws the column through func_8043B49C_de with the entry's value; mode 1 then also
   hides column 5's item, fades its label and hides the entry's item. Finally it hides the five
   D_800E5A06[p] items at alpha 0x37 and shows the selected column's label at alpha 0x96 through
   func_8040E928_de. */









extern struct Screen_func_8043B0CC_de *D_800E59E0;
extern struct StateFlags D_800E59E6[][19];
extern struct StateFlags D_800E59EE[][19];
extern struct StateFlags D_800E5A06[][19];
extern struct StateFlags D_800E5A1A[][19];
extern struct Resource_func_80419E54_de *func_8040EC30_de(s32, s32);
extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);
extern void func_8040E928_de(struct Resource_func_80419E54_de *, s32);
extern void func_8043B49C_de(s32, s32, s32);

void func_8043B0CC_de(s32 player) {
    struct Resource_func_80419E54_de *item;
    s32 i;

    D_800E59E0->entries[player].open = 1;
    func_8040E8D8_de(func_8040EC30_de(D_800E59E0->window, D_800E59E6[player][0].value), 0);
    switch (D_800E59E0->entries[player].mode) {
    case 0:
        func_8040E8D8_de(func_8040EC30_de(D_800E59E0->window, D_800E59EE[player][5].value), 0);
        item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][5].value);
        func_8040E8D8_de(item, 1);
        item->value = 0x23;
        break;
    case 1:
        for (i = 0; i < 3; i++) {
            func_8040E8D8_de(func_8040EC30_de(D_800E59E0->window, D_800E59EE[player][i].value), 0);
            item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][i].value);
            func_8040E8D8_de(item, 1);
            item->value = 0x23;
            func_8043B49C_de(player, i, D_800E59E0->entries[player].values[i]);
        }
        func_8040E8D8_de(func_8040EC30_de(D_800E59E0->window, D_800E59EE[player][5].value), 0);
        item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][5].value);
        func_8040E8D8_de(item, 1);
        item->value = 0x23;
        func_8040E8D8_de(D_800E59E0->entries[player].item, 0);
        break;
    case 2:
    default:
        for (i = 0; i < 6; i++) {
            func_8040E8D8_de(func_8040EC30_de(D_800E59E0->window, D_800E59EE[player][i].value), 0);
            item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][i].value);
            func_8040E8D8_de(item, 1);
            item->value = 0x23;
            func_8043B49C_de(player, i, D_800E59E0->entries[player].values[i]);
        }
        break;
    }
    for (i = 0; i < 5; i++) {
        item = func_8040EC30_de(D_800E59E0->window, D_800E5A06[player][i].value);
        func_8040E8D8_de(item, 0);
        item->value = 0x37;
    }
    item = func_8040EC30_de(D_800E59E0->window,
                         D_800E5A1A[player][D_800E59E0->entries[player].column].value);
    func_8040E928_de(item, 1);
    item->value = 0x96;
}
