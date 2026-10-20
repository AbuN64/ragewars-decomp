#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RECORDRECATCV1.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "MENU/PAK_LOAD.H"
#include "MENU/PAK/80409A88_2.H"

/* Copies the saved controller settings block D_80153738 into the settings the object at offset 0x5D8
   of an owner holds: the four halfwords, the flag byte into offset 0x80 and the eight bytes after it
   into offset 0x84. */







void func_80409A5C_de(struct OwnerRecAt5D8V1 *owner) {
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

#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct SavedPlayer { s32 data[28]; } SavedPlayer;
typedef struct SavedSettings { s32 data[353]; } SavedSettings;
typedef struct SavedState {
    char pad0[8]; f32 rules[4]; SavedPlayer player; SavedSettings settings;
    u8 table[1];
} SavedState;
typedef struct RestorePlayer { char pad0[0x5E0]; SavedPlayer saved; } RestorePlayer;
extern SavedState *D_800E28BC;
extern s32 D_8013B2D4;
extern u8 D_80146848, D_800F91F0[];
void func_80409AC0_de(RestorePlayer *player) {
    s32 i;
    u8 *from, *to;
    u8 saved = D_80146848;
    player->saved = D_800E28BC->player;
    *(SavedSettings *)&D_801462C8 = D_800E28BC->settings;
    D_801462C8.counters.ticks = D_800E28BC->rules[0];
    D_801462C8.counters.seconds = D_800E28BC->rules[1];
    D_801462C8.counters.minutes = D_800E28BC->rules[2];
    D_801462C8.counters.hours = D_800E28BC->rules[3];
    D_8013B2D4 = ((SavedSettings *)&D_801462C8)->data[1];
    D_80146848 = saved;
    from = D_800E28BC->table;
    to = D_800F91F0;
    for (i = 0; i < D_8011FE88.noteCount; i++) *to++ = *from++;
}
#else
INCLUDE_ASM("ovl_80400000", func_80409AC0_de);
#endif
