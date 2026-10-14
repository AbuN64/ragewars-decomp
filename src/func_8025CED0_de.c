#include "span_1000/code_8025C544.h"
#include "types.h"
/* Starts a random song from a group on a music player: picks one of the group's songs with equal weight, returning -1 when the group has none, records the group and song and takes the next request id, repeats the pick for the queued group, sets the volume to 0x40 and the speed from the given scale, then either stops the current song so it restarts (while starting or playing) or requests a start, and returns the request id. The picker and restart are inline helpers; the pick for the queued group is repeated with its result unused, as in the cartridge. */







extern s32 func_80265550_de(s32, s32, s32, s32 *, s32 *);
extern s32 func_802744D4_de(void);
extern char *func_80258D40_de(Bank_func_8025CED0_de *);
extern void func_80258740_de(Bank_func_8025CED0_de *);
extern void func_802587A4_de(Bank_func_8025CED0_de *);
extern void func_802B2F00_de(char *, s32);
extern void func_802B2F60_de(char *);

static inline s32 pick(Bank_func_8025CED0_de *bank, s32 group) {
    s32 first;
    s32 last;
    s32 i;
    s32 total;
    s32 roll;

    total = 0;
    if (func_80265550_de(bank->table, bank->count, group, &first, &last) == 0) {
        return -1;
    }
    if (first != last) {
        for (i = first; i <= last; i++) {
            total += 100;
        }
        roll = func_802744D4_de() % total;
        total = 0;
        for (i = first; i < last; i++) {
            total += 100;
            if (roll <= total) {
                return i;
            }
        }
        return i;
    }
    return first;
}

static inline void restart(PlayerRecAt1E *player) {
    char *channel;

    if (player->state != 2 && player->state != 0) {
        player->state = 2;
        channel = func_80258D40_de(player->bank);
        func_802B2F00_de(channel, player->id);
        func_802B2F60_de(channel);
    }
}

s32 func_8025CED0_de(PlayerRecAt1E *player, s32 group, f32 scale) {
    s32 song;
    s32 request;

    song = pick(player->bank, (s16)group);
    if (song == -1) {
        return -1;
    }
    func_80258D40_de(player->bank);
    func_80258740_de(player->bank);
    player->group = group;
    player->song = song;
    request = ++player->request;
    pick(player->bank, (s16)player->group);
    player->speed = scale * *(&D_800C3FB0_de + 1);
    player->volume = 0x40;
    if (player->state == 3 || player->state == 1) {
        restart(player);
    } else {
        player->state = 1;
    }
    func_802587A4_de(player->bank);
    return request;
}
