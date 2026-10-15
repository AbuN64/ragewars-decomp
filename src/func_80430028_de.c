#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042F988.h"
#include "types.h"
/* Cancels player arg2's pickup when the state at 0x58 of its 2920-byte record is 12 and arg3 asks:
   sets the word at 0xBA0 to 2, clears 0xBA4, drops one from the count at 0xB9C, stamps 0x41 on
   that count's two-byte slot at 0xB8C when the slot is free, silences the sound handle taken from
   the player's entry of the slot array at 4 of the block, and reports the cancel through
   func_8025DF34_de. Records 13 and above are left alone; the function always returns zero. */









extern struct Block_func_80430028_de *D_800E54A4;
extern struct Resource_func_80419E54_de *func_8041B7FC_de(struct Slots_func_8041B7FC_de *, s32);
extern s32 func_8025DF34_de(s32);

s32 func_80430028_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Resource_func_80419E54_de *sound;
    struct RowRecAtBA4 *row;
    char *base;
    u8 *mark;
    s32 index;
    s32 offset;
    s32 state;
    s32 count;

    index = arg2 & 0xFFFF;
    offset = index * 0xB68;
    state = ((struct RowRecAtBA4 *)(offset + (char *)D_800E54A4))->state;
    if (state == 0xD) {
        return 0;
    }
    if (state >= 0xE) {
        return 0;
    }
    if (state == 0xC && arg3 == 1) {
        sound = func_8041B7FC_de(D_800E54A4->slots, index);
        row = (struct RowRecAtBA4 *)(index * 0xB68 + (char *)D_800E54A4);
        row->phase = 2;
        count = row->count;
        row->timer = 0;
        if (count > 0) {
            row->count = count - 1;
        }
        base = (char *)D_800E54A4;
        mark = (u8 *)(base + ((((struct RowRecAtBA4 *)(offset + base))->count * 2) +
                              index * 0xB68) + 0xB8C);
        if (*mark == 0) {
            *mark = 0x41;
        }
        sound->value = 0xFF;
        func_8025DF34_de(0xE74);
    }
    return 0;
}
