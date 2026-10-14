#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022A274.h"
/** Return the capacity for an item slot: the player's own value, or in mode 1 the base value plus the character's bonus. */






extern unsigned char D_801462D5;
extern int D_800CE3E8[];
extern ProfileRecAt16 D_80102B00[];

int func_8022ACB8_de(Player_func_8022ACB8_de *player, int slot) {
    int value;

    if (slot == -1) {
        return 0;
    }
    if (D_801462D5 != 1) {
        value = player->loadout->capacity[slot];
    } else {
        value = D_800CE3E8[slot];
        if (player->isBot == 0) {
            if (slot == 0) {
                value += D_80102B00[player->character].bonus0;
            } else if (slot == 1) {
                value += D_80102B00[player->character].bonus1;
            } else if (slot == 2) {
                value += D_80102B00[player->character].bonus2;
            }
        }
    }
    return value;
}
