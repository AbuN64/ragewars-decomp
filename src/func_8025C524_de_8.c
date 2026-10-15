#include "span_1000/code_8025C544.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802BE0D0.h"
#include "types.h"

/* Runs a music player's state machine on its channel: a start request loads the song's header and sequence from the song bank, records its tempo scale and volume, sets the sequence, clears the player queue, starts the sequence through func_802C00B0_de, then sets the channel's sample rate from the sequence rate over 22050, its tempo, priority, channel volume, master volume and plays it; a playing song that has ended is stopped and returns to idle or to the start state when it loops, and a stop request stops the sequencer. The state is unsigned with an empty case 0, and the rate and tempo factors are literals so the resident rodata keeps its order. */











extern QueueRec D_80108064[];

extern void func_802C020C_de(void);

extern s32 func_802C00B0_de(void *, s32, s32 *);

extern s32 func_802B2620_de(char *);

extern void func_802B2E80_de(char *, f32);

extern void func_802B2F10_de(char *, s32);

extern void func_802B2E30_de(char *, s32);

extern void func_802B2ED0_de(char *, s32, s32);

extern void func_802B2DE0_de(char *, s32);

extern void func_802B2D80_de(char *);

/* Starts a random song from a group on a music player: picks one of the group's songs with equal weight, returning -1 when the group has none, records the group and song and takes the next request id, repeats the pick for the queued group, sets the volume to 0x40 and the speed from the given scale, then either stops the current song so it restarts (while starting or playing) or requests a start, and returns the request id. The picker and restart are inline helpers; the pick for the queued group is repeated with its result unused, as in the cartridge. */







extern s32 func_80265550_de(s32, s32, s32, s32 *, s32 *);

extern s32 func_802744D4_de(void);

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
    extern void func_802B2F60_de(char *);
    extern void func_802B2F00_de(char *, s32);
    extern char *func_80258D40_de(Bank_func_8025CED0_de *);
    char *channel;

    if (player->state != 2 && player->state != 0) {
        player->state = 2;
        channel = func_80258D40_de(player->bank);
        func_802B2F00_de(channel, player->id);
        func_802B2F60_de(channel);
    }
}

/* Initialises a resource record with the resource, -1 at 4 and 0xC, zero at 8 and 0x14, 0x40 at 0x18, and at 0x1C the halfword func_802B2510_de returns for func_80258D40_de's result on the stored resource and D_800D0D78. Adapted from func_80205694_de with the two calls replaced by field stores and a nested call pair whose first argument is read back from the record. */




extern s16 func_802B2510_de(void *, void *);

void func_8025CC90_de(PlayerRecAt24 *player) {
    extern void func_802B2F00_de(char *, s32);
    extern void *func_8028FDB4_de(void *, s32);
    extern char *func_80258D40_de(Bank *);
    extern void func_802587A4_de(Bank *);
    extern void func_80258740_de(Bank *);
    extern func_80203E78_S1 *D_800D0D78;
    s32 rate;
    char *channel;
    s32 index;
    SongHeader *header;
    void *sequence;

    func_80258740_de(player->bank);
    channel = func_80258D40_de(player->bank);
    switch (player->state) {
        case 0:
            break;
        case 3:
            func_802C020C_de();
            break;
        case 2:
            func_802B2F00_de(channel, player->id);
            if (func_802B2620_de(channel) == 0) {
                func_802C021C_de();
                if (player->loop >= 0) {
                    player->state = 1;
                } else {
                    player->state = 0;
                }
            }
            break;
        case 1:
            ((s32 *)D_80108064)[0] = 0;
            ((u8 *)D_80108064)[4] = 2;
            ((s32 *)D_80108064)[2] = 0;
            index = player->song * 2;
            header = func_8028FDB4_de(player->bank->songs, index);
            player->tempoScale = header->tempo * 0.01f;
            player->volume = header->volume;
            sequence = func_8028FDB4_de(player->bank->songs, index | 1);
            ((void **)D_80108064)[-1] = sequence;
            D_800D0D78->unk4 = func_802C00B0_de(sequence, 0x5622, &rate);
            player->state = 3;
            func_802B2F00_de(channel, player->id);
            func_802B2E80_de(channel, rate * 4.5351473e-05f);
            func_802B2F10_de(channel, (s16)(player->speed * player->tempoScale));
            func_802B2E30_de(channel, player->priority);
            func_802B2ED0_de(channel, player->id, 0x7F);
            func_802B2DE0_de(channel, (u8)(u32)player->volume);
            func_802B2D80_de(channel);
            player->loop = -1;
            break;
    }
    func_802587A4_de(player->bank);
}

s32 func_8025CED0_de(PlayerRecAt1E *player, s32 group, f32 scale) {
    extern char *func_80258D40_de(Bank_func_8025CED0_de *);
    extern void func_802587A4_de(Bank_func_8025CED0_de *);
    extern void func_80258740_de(Bank_func_8025CED0_de *);
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

void func_8025D158_de(struct Shape_typemap_110 *record, s32 resource) {
    extern void *func_80258D40_de(s32);
    extern char D_800D0D78[];
    record->field_0 = resource;
    record->field_4 = -1;
    record->field_C = -1;
    record->field_8 = 0;
    record->field_14 = 0;
    record->field_18 = 0x40;
    record->field_1C = func_802B2510_de(func_80258D40_de(record->field_0), D_800D0D78);
}

void func_8025D1BC_de(void *arg0) {
    extern void func_802B2F60_de(void *arg0);
    extern void func_802B2F00_de(void *arg0, s16 arg1);
    extern void *func_80258D40_de(void *arg0);
    extern void func_802587A4_de(s32 *arg0);
    extern void func_80258740_de(s32 *arg0);
    PlayerRecAt1E *player = arg0;
    void *temp_v0_2;
    s32 temp_v0;

    func_80258740_de((s32 *)player->bank);
    temp_v0 = player->state;
    if (temp_v0 != 2 && temp_v0 != 0) {
        player->state = 2;
        temp_v0_2 = func_80258D40_de(player->bank);
        func_802B2F00_de(temp_v0_2, player->id);
        func_802B2F60_de(temp_v0_2);
    }
    func_802587A4_de((s32 *)player->bank);
}

s32 func_8025D238_de(void **arg0, s16 id, s16 avoid) {
    s32 first;
    s32 last;
    s32 total;
    s32 entry;
    s32 draw;
    ContextRecAt2BB8 *table;
    s32 result;

    total = 0;
    table = *arg0;
    if (func_80265550_de(table->unk2B60, table->unk2B64, id, &first, &last) == 0) {
        return -1;
    }
    result = first;
    if (result != last) {
        for (entry = first; entry <= last; entry++) {
            total += 100;
        }
        draw = func_802744D4_de() % total;
        total = 0;
        for (entry = first; entry < last; entry++) {
            total += 100;
            if (total >= draw) {
                break;
            }
        }
        if (avoid != 0 && entry == avoid) {
            if (entry == last) {
                entry--;
            } else {
                entry++;
            }
        }
        result = entry;
    }
    return result;
}

void func_8025D350_de(void *arg0, s32 arg1) {
    extern char *func_8028FDB4_de(s32 *, s32);
    PlayerRecAt24 *player = arg0;
    f64 var_f2;
    s32 temp_v0_2;
    SongHeader *temp_v0;

    temp_v0 = func_8028FDB4_de(player->bank->songs, arg1 * 2);
    temp_v0_2 = temp_v0->tempo;
    var_f2 = (f64) temp_v0_2;
    if (temp_v0_2 < 0) {
        var_f2 += D_800C3FB8_de;
    }
    player->tempoScale = (f32) var_f2 * D_800C3FC0_de;
    player->volume = (f32) temp_v0->volume;
    func_8028FDB4_de(player->bank->songs, (arg1 * 2) | 1);
}

void func_8025D3E4_de(void *arg0) {
    extern void func_802B2F60_de(void *arg0);
    extern void func_802B2F00_de(void *arg0, s16 arg1);
    extern void *func_80258D40_de(void *arg0);
    PlayerRecAt1E *player = arg0;
    void *temp_v0_2;
    s32 temp_v0;

    temp_v0 = player->state;
    if (temp_v0 != 2 && temp_v0 != 0) {
        player->state = 2;
        temp_v0_2 = func_80258D40_de(player->bank);
        func_802B2F00_de(temp_v0_2, player->id);
        func_802B2F60_de(temp_v0_2);
    }
}
