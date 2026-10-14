#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041F1FC.h"
#include "types.h"

/* Resets player p's choice on the screen D_800E42D0: calls func_8040E8D8_de(1) on the three items in
   option cells from 0x18 of p's 36-byte layout row D_800E42D4, dims the item of the current choice at 0x18 of
   p's 0x4C8-byte entry to alpha 0x50 through func_8040E928_de(0) and resets the choice to 0; unless
   the entry's kind at 0x10 is -1 it then calls func_8040E8D8_de(0) on as many of those cells as the
   count byte (at least one) at 0x57 plus the index func_8041F1D8_de gives for the kind in p's
   400-byte record of D_80102B00, and highlights the item of the choice with alpha 0x96. Adapted
   from func_804201A4_de. */











extern struct Screen_func_804201A4_de *D_800E42D0;
extern struct RowRecAt18 D_800E42D4[];
extern u8 D_800FEB57[];
extern struct Resource_func_80419E54_de *func_8040EC30_de(void *, s32);
extern void func_8040E928_de(struct Resource_func_80419E54_de *, s32);
extern void func_8040E8D8_de(struct Resource_func_80419E54_de *, s32);


void func_80420438_de(s32 player) {
    struct Resource_func_80419E54_de *item;
    s32 count;
    s32 i;

    for (i = 0; i < 3; i++) {
        func_8040E8D8_de(func_8040EC30_de(D_800E42D0->entries[0].window, D_800E42D4[player].options[i].flags), 1);
    }
    item = func_8040EC30_de(D_800E42D0->entries[0].window,
                         D_800E42D4[player].cells[D_800E42D0->entries[player].choice].flags);
    func_8040E928_de(item, 0);
    item->value = 0x50;
    D_800E42D0->entries[player].choice = 0;
    if (D_800E42D0->entries[player].kind == -1) {
        return;
    }
    count = D_800FEB57[func_8041F1D8_de(D_800E42D0->entries[player].kind) + player * 400];
    if (count <= 0) {
        count = 1;
    }
    for (i = 0; i < count; i++) {
        func_8040E8D8_de(func_8040EC30_de(D_800E42D0->entries[0].window, D_800E42D4[player].options[i].flags), 0);
    }
    item = func_8040EC30_de(D_800E42D0->entries[0].window,
                         D_800E42D4[player].cells[D_800E42D0->entries[player].choice].flags);
    func_8040E928_de(item, 1);
    item->value = 0x96;
}
