#include "span_16E000/code_8042F988.h"
#include "types.h"

/* Places player p's chosen record into a free place: when the flag word for the chosen slot (index
   at 0xAEC of the player's 2920-byte record at 0x58, flags from 0xAF0) is 1, it takes the first of
   the four 12-byte places at 0x2DF8 of the block D_800E54A4 points to whose id is -1, records it in
   the entry func_804351E4_de returns (id 0, value the place, word 8 set to 1), copies the chosen
   400-byte slot from 0x18 of the player's record into that place of D_80102B00 through
   func_802A0724_de, marks p as its owner at 0xD, clears the player's word at 0x4 and relabels through
   func_80433BCC_de(-1), returning 1; otherwise it returns 0. */









extern struct Block_func_8043497C_de *D_800E54A4;
extern struct Record_func_804347CC_de D_80102B00[];
extern s32 func_804351E4_de();
extern void func_802A0724_de(void *, void *, s32);
extern void func_80433BCC_de(s32);

s32 func_8043497C_de(s32 player) {
    struct Record_func_804347CC_de *record;
    s32 chosen;
    s32 place;
    s32 found;
    s32 entry;
    s32 result;
    s32 i;

    chosen = D_800E54A4->players[player].chosen;
    result = 0;
    if (D_800E54A4->players[player].flags[chosen] == 1) {
        found = -1;
        for (i = 0; i < 4 && found == -1; i++) {
            if (D_800E54A4->places[i].x == -1) {
                found = i;
            }
        }
        place = found;
        if (place >= 0) {
            entry = func_804351E4_de();
            if (entry >= 0) {
                D_800E54A4->places[entry].x = 0;
                D_800E54A4->places[entry].y = place;
                D_800E54A4->places[entry].z = 1;
            }
            record = &D_80102B00[found];
            func_802A0724_de(record, D_800E54A4->players[player].slots[chosen], 400);
            record->owner = player;
            D_800E54A4->players[player].word4 = 0;
            place = -1;
            func_80433BCC_de(place);
            result = 1;
        }
    }
    return result;
}
