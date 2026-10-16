#include "TYPES.H"
typedef struct DraftConfig17F4C { u8 pad[0x82]; u8 mode; } DraftConfig17F4C;
typedef struct DraftInput17F4C { u8 pad[0xB0]; u32 pressed; u8 padB4[4]; u32 held; } DraftInput17F4C;
typedef struct DraftPlayer17F4C {
    u8 pad[0x48C]; s8 enabled; u8 pad48D[0x5D8 - 0x48D];
    DraftConfig17F4C *config; void *ui; s32 type;
    u8 pad5E4[0x62E - 0x5E4]; s16 oldChoice; u8 pad630[0x698 - 0x630];
    DraftInput17F4C *input; u8 pad69C[0x770 - 0x69C]; s16 choice;
    u8 pad772[0xCC0 - 0x772]; s32 selection; u8 padCC4[8]; s32 blocked;
    u8 padCD0[0x11B0 - 0xCD0]; void *effect; s32 active;
    u8 pad11B8[0x20]; f32 delay; u8 pad11DC[0x14]; s32 word11F0;
    u8 pad11F4[4]; s32 word11F8;
} DraftPlayer17F4C;
typedef struct DraftState17F4C {
    s32 state; f32 value, timer; u8 padC[8]; f32 angle;
    u8 pad18[0x380 - 0x18]; s32 mode; u8 pad384[4]; s32 selection;
} DraftState17F4C;
extern f32 D_800D2988, D_800C2234_de, D_800C2238_de, D_800C223C_de, D_800C2240_de, D_800C2244_de;
extern s32 func_80245784_de(void), func_80232ABC_de(void *), func_8022FAF8_de(void *);
extern void func_80217D74_de(void *, void *, s32), func_80285974_de(void *, s32);
extern s32 func_8021846C_de(void *, void *);
void func_80217F4C_de(DraftState17F4C *state, DraftPlayer17F4C *player, s32 arg2)
{
    if ((u32)(player->type - 17) < 2) return;
    if (player->blocked) return;
    if (player->delay > 0.0f) return;
    if (func_80245784_de()) return;
    state->mode = player->config->mode == 1;
    if (player->type == 14) {
        if (!player->enabled) return;
        if (player->input->pressed & 0x8000) player->choice = func_80232ABC_de(player);
    } else if ((player->input->held & 0x8000) && player->config->mode) {
        player->choice = func_8022FAF8_de(player);
    } else if (player->config->mode != 1 || (player->selection != -1 && state->selection != 8)) {
        func_80217D74_de(state, player, arg2);
    }
    if (player->choice != player->oldChoice) {
        if (player->effect) {
            func_80285974_de(player->effect, 0);
            player->effect = 0;
        }
        player->word11F0 = 0; player->word11F8 = -1;
    }
    switch (state->state) {
    case 1:
        state->timer += D_800D2988 * D_800C2234_de;
        if (state->selection != -1) state->value = D_800C2238_de;
        else state->value = 0.0f;
        if (state->timer >= D_800C223C_de) {
            state->state = 2; state->timer = D_800C223C_de;
            if (state->selection != -1) state->selection = 8;
        }
        break;
    case 2:
        if (!func_8021846C_de(state, player)) break;
        state->selection = -1; player->active = 0; state->state = 3;
    case 3:
        state->timer -= D_800D2988 * D_800C2240_de;
        if (state->timer <= 0.0f) { state->timer = 0.0f; state->state = 0; }
        break;
    }
    if (state->state) state->angle += D_800D2988 * D_800C2244_de;
    else player->active = 0;
}
