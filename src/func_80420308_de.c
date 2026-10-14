#include "span_16E000/code_8041F1FC.h"
#include "types.h"

/* Activates player p's panel on the screen D_800E42D0: passes p and the frame item id from p's
   36-byte layout row D_800E42D4 to func_8041B6E8_de, takes the row's cursor item into the word at 0x8
   of p's 0x4C8-byte entry, places it two units up and left of the frame item, shows it, sets the
   entry's state at 0x14 to one, redraws through func_80420438_de and hides the row's prompt item. */









extern struct Screen_func_80420308_de *D_800E42D0;
extern struct RowRecAtA D_800E42D4[];
extern void func_8041B6E8_de(void *, s32, s32);
extern struct Item_func_80420308_de *func_8040EC30_de(void *, s32);
extern void func_8040E8D8_de(struct Item_func_80420308_de *, s32);
extern void func_80420438_de(s32);

void func_80420308_de(s32 player) {
    struct Item_func_80420308_de *frame;

    func_8041B6E8_de(D_800E42D0->entries[0].window, player, D_800E42D4[player].frame);
    D_800E42D0->entries[player].cursor = func_8040EC30_de(D_800E42D0->entries[0].window, D_800E42D4[player].cursor);
    frame = func_8040EC30_de(D_800E42D0->entries[0].window, (u16)D_800E42D4[player].frame);
    D_800E42D0->entries[player].cursor->x = frame->x - 2;
    D_800E42D0->entries[player].cursor->y = frame->y - 2;
    func_8040E8D8_de(D_800E42D0->entries[player].cursor, 1);
    D_800E42D0->entries[player].state = 1;
    func_80420438_de(player);
    func_8040E8D8_de(func_8040EC30_de(D_800E42D0->entries[0].window, D_800E42D4[player].prompt), 0);
}
