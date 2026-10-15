#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043A0A4.h"
#include "types.h"

/* Moves player p's column cursor on the screen D_800E59E0: fades the shown item of the current
   column (D_800E5A1A[p][column]) to alpha 0x23, calls func_8040E8D8_de(0) on the item D_800E5A06[p][column]
   unless the column is 5, then steps the column back for direction 1 (0 wraps to 5, and in mode 1
   at 0x4D4 anything above 2 becomes 2) or forward otherwise (5 wraps to 0, and in mode 1 anything
   past 2 becomes 5), and redraws through func_8043BA5C_de. */









extern struct Screen_func_8043ACF0_de *D_800E59E0;
extern struct StateFlags D_800E5A06[][19];
extern struct StateFlags D_800E5A1A[][19];
extern struct Resource_func_80419E54_de *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);
extern void func_8040E928_de(struct Resource_func_80419E54_de *, s32);
extern void func_8043BA5C_de(s32, s32);

void func_8043ACF0_de(s32 player, s32 direction) {
    struct Resource_func_80419E54_de *item;
    s32 column;

    column = D_800E59E0->entries[player].column;
    item = func_8040EC30_de(D_800E59E0->window, D_800E5A1A[player][column].value);
    func_8040E928_de(item, 0);
    item->value = 0x23;
    if (column != 5) {
        func_8040E8D8_de(func_8040EC30_de(D_800E59E0->window, D_800E5A06[player][column].value), 0);
    }
    if (direction == 1) {
        if (column == 0) {
            column = 5;
        } else {
            column--;
            if (D_800E59E0->entries[player].mode == 1 && column >= 3) {
                column = 2;
            }
        }
    } else {
        if (column == 5) {
            column = 0;
        } else {
            column++;
            if (D_800E59E0->entries[player].mode == 1 && column >= 3) {
                column = 5;
            }
        }
    }
    func_8043BA5C_de(player, column);
}
