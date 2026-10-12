#include "types.h"

typedef struct WeaponStatus {
    u8 pad[0x78];
    u8 active;
    u8 pad79[0x18];
    u8 out;
} WeaponStatus;

typedef struct WeaponPlayer {
    u8 pad[0x5D8];
    WeaponStatus *status;
    u8 pad5DC[0x26];
    u8 weapons[22][2];
} WeaponPlayer;

extern char D_8011FE88[];
extern s32 D_8015402C;
extern void *func_8028D474_de(void *, s32);

void func_804261DC_de(WeaponPlayer *player) {
    WeaponStatus *status = player->status;
    s32 i;
    u16 *entries;
    s32 id;
    s32 active;

    if (status->out != 1 && status->active != 0) {
        entries = func_8028D474_de(D_8011FE88, D_8015402C);
        i = 0;
        active = 1;
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
