#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022BA90.h"
/** Set up a player's starting lives from the game mode and character, then reset its respawn state. */








extern Rules_func_8022C110_de D_801462C8;
extern Course *D_800E4680;
extern char D_80102B00[][0x190];
extern unsigned char func_8022F454_de(char *, int);

void func_8022C110_de(PlayerRecAt1450V2 *player) {
    short state;

    if (D_801462C8.started != 0) {
        if (D_801462C8.mode == 1 && player->isBot == 0) {
            player->lives = (unsigned char)func_8022F454_de(D_80102B00[player->character], player->info->unk80) / 2 + 1;
        }
        if (D_801462C8.mode == 4 && player->isBot == 0 && D_800E4680 != 0) {
            player->lives = D_800E4680->laps;
        }
        state = 1;
    } else {
        state = 3;
    }
    player->state = state;
    player->timer = 0;
}
