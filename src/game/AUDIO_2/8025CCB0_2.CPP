#include "include_asm.h"
#include "COMMON/EXTERNS.H"
#include "COMMON/LLDIVRESULT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "AUDIO_2/8025CCB0.H"
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
        roll = Nav_NextRandom() % total;
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
        channel = Audio_GetSoundPlayer(player->bank);
        func_802B2F00_de(channel, player->id);
        alSndpStop(channel);
    }
}

/* Initialises a resource record with the resource, -1 at 4 and 0xC, zero at 8 and 0x14, 0x40 at 0x18, and at 0x1C the halfword func_802B2510_de returns for Audio_GetSoundPlayer's result on the stored resource and D_800D0D78. Adapted from func_80205694_de with the two calls replaced by field stores and a nested call pair whose first argument is read back from the record. */




extern s16 func_802B2510_de(void *, void *);

s32 func_8025CED0_de(PlayerRecAt1E *player, s32 group, f32 scale, int unused3) {
    s32 song;
    s32 request;

    song = pick(player->bank, (s16)group);
    if (song == -1) {
        return -1;
    }
    Audio_GetSoundPlayer(player->bank);
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
    record->field_1C = func_802B2510_de(Audio_GetSoundPlayer(record->field_0), D_800D0D78);
}

void func_8025D1BC_de(void *arg0) {

    PlayerRecAt1E *player = arg0;
    void *soundPlayer;
    s32 state;

    func_80258740_de((s32 *)player->bank);
    state = player->state;
    if (state != 2 && state != 0) {
        player->state = 2;
        soundPlayer = Audio_GetSoundPlayer(player->bank);
        func_802B2F00_de(soundPlayer, player->id);
        alSndpStop(soundPlayer);
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
        draw = Nav_NextRandom() % total;
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

void func_8025D350_de(void *arg0, s32 songIndex) {
    PlayerRecAt24 *player = arg0;
    f64 tempoValue;
    s32 tempo;
    SongHeader *song;

    song = Render_GetPackSection(player->bank->songs, songIndex * 2);
    tempo = song->tempo;
    tempoValue = (f64) tempo;
    if (tempo < 0) {
        tempoValue += D_800C3FB8_de;
    }
    player->tempoScale = (f32) tempoValue * D_800C3FC0_de;
    player->volume = (f32) song->volume;
    Render_GetPackSection(player->bank->songs, (songIndex * 2) | 1);
}

void func_8025D3E4_de(void *arg0) {

    PlayerRecAt1E *player = arg0;
    void *soundPlayer;
    s32 state;

    state = player->state;
    if (state != 2 && state != 0) {
        player->state = 2;
        soundPlayer = Audio_GetSoundPlayer(player->bank);
        func_802B2F00_de(soundPlayer, player->id);
        alSndpStop(soundPlayer);
    }
}

#if defined(VERSION_US)
char rodata_unresolved_8025D3E8[8] =
    "EHAVIOR_";
#endif

#if !(defined(VERSION_US_REV1))
const unsigned int D_8025D350_C9CA8[3] = {
    0x41F00000, 0x00000000, 0x3C23D70A,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C4274[3] = {
    0x8E740020, 0x186000DD, 0x02A08821,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C3FC4[3] = {
    0x3C23D70A, 0x46FFFE00, 0x3C23D70A,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8025D350_C9CA8_us_rev1.c */
const unsigned int D_blob_a274f83a44ed3e23c66c[3] = {
    0x41F00000, 0x00000000, 0x3C23D70A,
};
#endif
