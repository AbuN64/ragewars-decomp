#include "types.h"
typedef struct SavedPlayer { s32 data[28]; } SavedPlayer;
typedef struct SavedSettings { s32 data[353]; } SavedSettings;
typedef struct SavedState {
    char pad0[8]; f32 rules[4]; SavedPlayer player; SavedSettings settings;
    u8 table[1];
} SavedState;
typedef struct RestorePlayer { char pad0[0x5E0]; SavedPlayer saved; } RestorePlayer;
extern SavedState *D_800E28BC;
extern SavedSettings D_801462C8;
extern f32 D_801468A0[];
extern s32 D_8013B2D4;
extern u8 D_80146848, D_800F91F0[];
extern s32 D_8011FE88[];
void func_80409AC0_de(RestorePlayer *player) {
    s32 i;
    u8 *from, *to;
    s32 *info = D_8011FE88;
    u8 saved = D_80146848;
    player->saved = D_800E28BC->player;
    D_801462C8 = D_800E28BC->settings;
    D_801468A0[0] = D_800E28BC->rules[0];
    D_801468A0[1] = D_800E28BC->rules[1];
    D_801468A0[2] = D_800E28BC->rules[2];
    D_801468A0[3] = D_800E28BC->rules[3];
    D_8013B2D4 = D_801462C8.data[1];
    D_80146848 = saved;
    from = D_800E28BC->table;
    to = D_800F91F0;
    for (i = 0; i < info[17]; i++) *to++ = *from++;
}
