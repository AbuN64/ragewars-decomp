#include "span_16E000/code_8041F1FC.h"
/* Confirms a player's character choice and, once no player is still choosing, fills the match roster and starts the game; scheduler lever: the block-scoped match pointer inside the roster loop places the hoisted match address after the loop constants, as the cartridge does. */








extern SelectMenu *D_800E42D0;


extern CharacterScreenCell D_800E029E[][9];
extern Match_func_80420618_de D_801462C8;
extern unsigned char D_800FEB0F[];

extern void func_8041B7B4_de(void *, int, int);
extern void *func_8040EC30_de(void *, int);
extern void func_8040E8D8_de(void *, int);
extern void func_8041F18C_de(int);
extern void func_8041CE10_de(void *, int);

extern void func_80298368_de(int);

void func_80420618_de(int player, int choice) {
    int i;
    int j;
    int count;
    RosterSlot *slot;
    int kind;

    D_800E42D0->entries[player].state = 3;
    func_8041B7B4_de(D_800E42D0->menu, player, 1);
    D_800E42D0->entries[player].confirmed = 1;
    for (i = 0; i < 3; i++) {
        func_8040E8D8_de(func_8040EC30_de(D_800E42D0->screen, D_800E029E[player][i].id), 1);
    }
    D_800E42D0->entries[player].choice = choice;
    func_8041F18C_de(choice);
    func_8041CE10_de(D_800E42D0->entries[player].preview, 0);

    count = 0;
    for (j = 0; j < 4; j++) {
        if (D_800E42D0->entries[j].state == 1 || D_800E42D0->entries[j].state == 2) {
            count++;
        }
    }
    if (count != 0) {
        return;
    }

    slot = D_801462C8.slots;
    for (i = 0; i < 8; i++) {
        slot[i].active = 0;
        if (D_800E42D0->entries[i].state == 3) {
            slot[i].locked = 0;
            slot[i].active = 1;
            slot[i].player = i;
            kind = func_8041F1D8_de(D_800E42D0->entries[i].choice);
            slot[i].kind = kind;
            {
                Match_func_80420618_de *match = &D_801462C8;

                if (match->mode == 1) {
                    D_800FEB0F[i * 0x190] = kind;
                }
            }
            slot[i].variant = D_800E42D0->entries[i].variant[3];
        }
    }
    func_80298368_de(D_801462C8.mode == 1 ? 10 : 8);
}
