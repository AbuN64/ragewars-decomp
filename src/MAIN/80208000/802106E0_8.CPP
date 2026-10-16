#include "span_1000/code_802106E0.h"
#include "TYPES.H"

/* Resets a player's eight pairs of levels at offsets 0x1D0 and 0x1F0 to D_800C70F0, clears the word
   at 0x1CC, sets 0x288 and loads 0x210 with D_800C70F4, when the player exists and is active. */





void func_802110C4_de(struct PlayerRecAt288 *player) {
    u32 i;

    if (player != 0 && player->active != 0) {
        for (i = 0; i < 8; i++) {
            player->first[i] = D_800C70F0;
            player->second[i] = D_800C70F0;
        }
        player->timer = 0;
        player->ready = 1;
        player->level = D_800C70F4;
    }
}
