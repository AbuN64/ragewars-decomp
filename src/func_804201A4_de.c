#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041F1FC.h"
#include "types.h"

/* Cycles player p's choice on the screen D_800E42D0: dims the item for the current choice at 0x18
   of p's 0x4C8-byte entry (from p's 36-byte layout row D_800E42D4, cells from 0xC) to alpha 0x50
   through func_8040E928_de(0), advances the choice modulo the count byte (at least one) found at
   0x57 plus the index func_8041F1D8_de gives for the entry's word at 0x10 in p's 400-byte record of
   D_80102B00, highlights the new choice's item with alpha 0x96 and stores it. Written from the
   assembly with the entries as an array member of the screen. */











extern struct Screen_func_804201A4_de *D_800E42D0;
extern struct Row D_800E42D4[];
extern u8 D_800FEB57[];
extern struct Resource_func_80419E54_de *func_8040EC30_de(void *, s32);
extern void func_8040E928_de(struct Resource_func_80419E54_de *, s32);


void func_804201A4_de(s32 player) {
    struct Resource_func_80419E54_de *item;
    s32 choice;
    s32 count;

    choice = D_800E42D0->entries[player].choice;
    item = func_8040EC30_de(D_800E42D0->entries[0].window, D_800E42D4[player].cells[choice].flags);
    func_8040E928_de(item, 0);
    item->value = 0x50;
    count = D_800FEB57[func_8041F1D8_de(D_800E42D0->entries[player].kind) + player * 400];
    if (count <= 0) {
        count = 1;
    }
    choice = (choice + 1) % count;
    item = func_8040EC30_de(D_800E42D0->entries[0].window, D_800E42D4[player].cells[choice].flags);
    func_8040E928_de(item, 1);
    item->value = 0x96;
    D_800E42D0->entries[player].choice = choice;
}
