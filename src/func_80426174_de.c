#include "span_16E000/code_804251F4.h"
#include "types.h"
#include "gfx.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
/* Copies a player's enabled options into its option list: unless the player's info (at 0x5D8) is
   locked (byte 0x91 is 1) or absent (byte 0x78 is 0), each of the 22 option flags at 0x4C that is 1
   is recorded as the pair (1, value from 0x62) at 0x602 plus twice its index. */




void func_80426174_de(Player_func_80426174_de *p) {
    int i;

    if (p->info->locked != 1 && p->info->present != 0) {
        for (i = 0; i < 22; i++) {
            if (p->info->enabled[i] == 1) {
                p->options[i].flag = p->info->enabled[i];
                p->options[i].value = p->info->values[i];
            }
        }
    }
}

extern void *func_8028D474_de(void *, s32);

void func_804261DC_de(WeaponPlayer *player) {
    WeaponStatus *status = player->status;
    s32 i;
    u16 *entries;
    s32 id;
    s32 active;

    if (status->out != 1 && status->active != 0) {
        void *table = func_8028D474_de(&D_8011FE88, D_8015402C);
        i = 0;
        active = 1;
        entries = table;
        do {
            id = entries[3];
            if (id >= 0x4C3) {
                id -= 0x4C3;
                player->weapons[id][0] = active;
                player->weapons[id][1] = i;
            }
            i++;
            entries++;
        } while (i < 8);
    }
}
