#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RECORDRECATCV1.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "MENU/PAK_LOAD.H"
#include "MENU/PAK/PAK_APPLYSTAGEDPLAYERPROFILE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENURECAT24.H"

/* 80409A88_2.CPP */
/* Copies the saved controller settings block D_80153738 into the settings the object at offset 0x5D8
   of an owner holds: the four halfwords, the flag byte into offset 0x80 and the eight bytes after it
   into offset 0x84. */

void Pak_ApplyStagedPlayerProfile(struct OwnerRecAt5D8V1 *owner) {
    struct ProfileRecAt84 *settings = owner->settings;
    s32 i;

    settings->flags = D_80153738.flag;
    settings->words[0] = D_80153738.values[0];
    settings->words[1] = D_80153738.values[1];
    settings->words[2] = D_80153738.values[2];
    settings->words[3] = D_80153738.values[3];
    for (i = 0; i < 8; i++) {
        settings->name[i] = D_80153738.bytes[i];
    }
}

typedef struct SavedPlayer { s32 data[28]; } SavedPlayer;
typedef struct SavedSettings { s32 data[353]; } SavedSettings;
typedef struct SavedState {
    char pad0[8]; f32 rules[4]; SavedPlayer player; SavedSettings settings;
    u8 table[1];
} SavedState;
typedef struct RestorePlayer { char pad0[0x5E0]; SavedPlayer saved; } RestorePlayer;
extern SavedState *D_800E28BC;
extern s32 D_8013B2D4[]; /* an array: its store may alias the loads through D_800E28BC, so it stays after them */
extern u8 D_80146848;
extern u8 D_800F91F0[];
void Pak_RestoreSavedSession(RestorePlayer *player) {
    Shared_World *world = &g_world;
    s32 i;
    u8 *from, *to;
    u8 saved = D_80146848;
    player->saved = D_800E28BC->player;
    *(SavedSettings *)&D_801462C8 = D_800E28BC->settings;
    D_801462C8.counters.m_GameTimeFifteenth = D_800E28BC->rules[0];
    D_801462C8.counters.m_GameTimeSeconds = D_800E28BC->rules[1];
    D_801462C8.counters.m_GameTimeMinutes = D_800E28BC->rules[2];
    D_801462C8.counters.m_GameTimeHours = D_800E28BC->rules[3];
    D_8013B2D4[0] = ((SavedSettings *)&D_801462C8)->data[1];
    ((u8 *)&D_801462C8)[0x580] = saved;
    from = D_800E28BC->table;
    to = D_800F91F0;
    for (i = 0; i < world->noteCount; i++) *to++ = *from++;
}

/* 80409A88_3.CPP */
/* Returns D_800E28C8 when D_8015375C is set, otherwise the signed byte at offset 4 of the object
   at offset 0x20 of a record. */

extern s32 D_8015375C;

s32 Pak_GetMenuChannel(struct Shared_PakMenu *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->owner->unk4;
}
