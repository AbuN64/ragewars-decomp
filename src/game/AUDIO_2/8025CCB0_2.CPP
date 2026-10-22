#include "include_asm.h"
#include "COMMON/EXTERNS.H"
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "TYPES.H"
#include "AUDIO/ALSNDP.H"
#include "COMMON/SELF.H"
#include "AUDIO_2/8025CCB0_2.H"
#include "TEXTURE/80256220_16.H"
#include "AUDIO_2/802591C0.H"
#include "SYSTEM_3/80265370.H"
#include "RENDER_4/8028FD2C_6.H"

/* Starts a random song from a group on a music player: picks one of the group's songs with equal weight, returning -1 when the group has none, records the group and song and takes the next request id, repeats the pick for the queued group, sets the volume to 0x40 and the speed from the given scale, then either stops the current song so it restarts (while starting or playing) or requests a start, and returns the request id. The picker and restart are inline helpers; the pick for the queued group is repeated with its result unused, as in the cartridge. */









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
        alSndpStop(channel);
    }
}

/* Initialises a resource record with the resource, -1 at 4 and 0xC, zero at 8 and 0x14, 0x40 at 0x18, and at 0x1C the halfword func_802B2510_de returns for func_80258D40_de's result on the stored resource and D_800D0D78. Adapted from func_80205694_de with the two calls replaced by field stores and a nested call pair whose first argument is read back from the record. */




extern s16 func_802B2510_de(void *, void *);

s32 func_8025CED0_de(PlayerRecAt1E *player, s32 group, f32 scale, int arg3) {
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

    PlayerRecAt1E *player = arg0;
    void *temp_v0_2;
    s32 temp_v0;

    func_80258740_de((s32 *)player->bank);
    temp_v0 = player->state;
    if (temp_v0 != 2 && temp_v0 != 0) {
        player->state = 2;
        temp_v0_2 = func_80258D40_de(player->bank);
        func_802B2F00_de(temp_v0_2, player->id);
        alSndpStop(temp_v0_2);
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

    PlayerRecAt1E *player = arg0;
    void *temp_v0_2;
    s32 temp_v0;

    temp_v0 = player->state;
    if (temp_v0 != 2 && temp_v0 != 0) {
        player->state = 2;
        temp_v0_2 = func_80258D40_de(player->bank);
        func_802B2F00_de(temp_v0_2, player->id);
        alSndpStop(temp_v0_2);
    }
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_8025D3E8);
#endif
