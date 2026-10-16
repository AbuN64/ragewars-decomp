#include "types.h"

typedef struct { u8 pad0[0x18]; s32 health; u8 pad1C[0xE0]; f32 x, y, z; } ActorTemplate;
typedef struct { u8 pad0[0x80]; s8 kind; u8 pad81[0xE]; u8 special; u8 pad90[4]; u8 boosted; } PlayerInfo;
typedef struct {
    u8 pad0[3]; u8 alpha; u8 pad4[0x14]; ActorTemplate *model;
    u8 pad1C[0x34]; f32 x, y, z; u8 pad5C[0x118]; s32 health;
    u8 pad178[0x45C]; s32 slot; PlayerInfo *info; s32 pad5DC;
    s32 modelId; s32 maxHealth; u8 pad5E8[0xE68]; s32 bot;
} Player;
typedef struct { s32 value; u8 pad4[0x18C]; } PlayerBonus;
struct World;
extern struct World D_8011FE88;
extern s32 D_801468F4, D_80146938;
extern u8 D_801462D5;
extern PlayerBonus D_800FEB10[];
struct Shared_World;
extern void *func_8028CFA0_de(struct Shared_World *, s32, s32);

void func_80226708_de(Player *player) {
    ActorTemplate *model;
    s32 id, health;
    s8 kind;
    id = player->modelId;
    if (D_801468F4 != 0 && player->info->special == 1) id = 0x13;
    model = func_8028CFA0_de(&D_8011FE88, 0xB, id);
    if (model == 0) {
        model = func_8028CFA0_de(&D_8011FE88, 0xB, -1);
        if (model == 0) model = func_8028CFA0_de(&D_8011FE88, -1, -1);
    }
    player->model = model;
    player->x = model->x; player->y = model->y; player->z = model->z;
    if (D_801468F4 != 0 && player->info->special != 0) {
        player->maxHealth = 0xA00;
        player->health = 0xA00;
        return;
    }
    if (D_80146938 != 0 && player->info->boosted != 0) {
        kind = player->info->kind;
        if (kind == 0xB || kind == 0xC) health = 0x19000;
        else if (kind == 0xE || kind == 0xD) health = 0x12C00;
        else goto fallback_first;
    } else {
fallback_first:
        health = player->model->health << 8;
    }
    if (D_801462D5 == 1 && player->bot == 0) health += D_800FEB10[player->slot].value;
    player->maxHealth = health;
    if (D_80146938 != 0 && player->info->boosted != 0) {
        kind = player->info->kind;
        if (kind == 0xB || kind == 0xC) health = 0x19000;
        else if (kind == 0xE || kind == 0xD) health = 0x12C00;
        else goto fallback_second;
    } else {
fallback_second:
        health = player->model->health << 8;
    }
    if (D_801462D5 == 1 && player->bot == 0) health += D_800FEB10[player->slot].value;
    player->health = health;
    player->alpha = 0xFF;
}
