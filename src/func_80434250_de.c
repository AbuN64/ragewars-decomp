#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042F988.h"
#include "types.h"














#if defined(VERSION_DE)
enum { PAK_LIST_FIELD = 748 };
#elif defined(VERSION_EU_X)
enum { PAK_LIST_FIELD = 752 };
#else
enum { PAK_LIST_FIELD = 726 };
#endif

/* Moves player p's list cursor in the block D_800E54A4 points to: direction 1 steps the cursor at
   0xAD8 of the player's 2920-byte record at 0x58 forward below 15 and scrolls the window at 0xADC
   so the cursor stays in the three visible rows (at most 13), any other direction steps both back
   while positive; then it sets the three row labels at 0xAE0 to alpha 0xFF with the texts of the
   70-byte name entries at 0x658 from the scroll position, and points item PAK_LIST_FIELD of the player's
   window at 0xC at the code at 0x3C of the entry under the cursor. */

extern PakMenuController *D_800E54A4;
extern MenuWidget *func_8040EC30_de(void *, s32);

void func_80434250_de(s32 player, s32 direction) {
    s32 i;
    s32 cursor;

    if (direction == 1) {
        if (D_800E54A4->players[player].slot < 15) {
            D_800E54A4->players[player].slot++;
            if (D_800E54A4->players[player].slot >= D_800E54A4->players[player].scroll + 3) {
                if (D_800E54A4->players[player].scroll + 3 < 15) {
                    D_800E54A4->players[player].scroll++;
                } else {
                    D_800E54A4->players[player].scroll = 13;
                }
            }
        }
    } else if (D_800E54A4->players[player].slot > 0) {
        D_800E54A4->players[player].slot--;
        if (D_800E54A4->players[player].scroll > 0 &&
            D_800E54A4->players[player].slot - D_800E54A4->players[player].scroll < 0) {
            D_800E54A4->players[player].scroll--;
        }
    }
    for (i = 0; i < 3; i++) {
        D_800E54A4->players[player].labels[i]->alpha = 0xFF;
        D_800E54A4->players[player].labels[i]->text =
            D_800E54A4->players[player].displayNames[D_800E54A4->players[player].scroll + i].text;
    }
    cursor = D_800E54A4->players[player].slot;
    func_8040EC30_de(D_800E54A4->players[player].menuWidget, PAK_LIST_FIELD)->text =
        D_800E54A4->players[player].displayNames[cursor].code;
}
