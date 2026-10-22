#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "MENU/TEAMMENU.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/OBJECTSTATE90.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "RENDER_2/8025DE50_5.H"

/* Runs a player's weapon menu each frame: the menu button (0x8000 of the controller at 0x698) counts
   only while func_8022C460_de allows and the controller is not paused through D_801468F4, which instead
   closes the menu (state 3), as does holding the button while the value at 0x4 is positive; from a
   closed state holding it clears the pending weapon at 0xCC0, rebuilds the menu through func_802181FC_de
   and opens it, while releasing it with a weapon pending outside category 8 rebuilds it and marks it
   open; with no category the slot under the cursor from func_80217B3C_de, when it changes, plays sound
   0xD4D for an unowned weapon, forgets an empty slot, moves the cursor at 0x37C and requests the
   slot's weapon at 0x770 unless it is current, switching the slot to the weapon's alternate at 0xC of
   its D_800D052C record when the player holds that one and input bit 0x1000 is clear. */




extern s32 func_80217B3C_de(void *);






void func_80217D74_de(s32 *menu, void *player, s32 arg2) {
    s32 held;
    s32 slot;
    s32 category;
    Entry34 *entry;
    s16 weapon;
    s16 alternate;
    char *ammo;

    held = ((struct ObjRecAtB0 *) ((ObjectLinks11B8 *) player)->unk_698)->unkB0 & 0x8000;
    if (func_8022C460_de(player) != 0) {
        held = 0;
    }
    if (D_801468F4 != 0 && ((struct ObjRecAt8F *) ((ObjectLinks11B8 *) player)->unk_5D8)->unk8F == 1) {
        held = 0;
        menu[0] = 3;
    }
    if (held && ((struct func_802077F4_S2 *) menu)->unk4 > 0.0f) {
        menu[0] = 3;
    }
    if (menu[0] == 0 || menu[0] == 3) {
        if (!held) {
            if (((ObjectLinks11B8 *)(player))->unk_CC0 != -1 && menu[0x388 / 4] != 8) {
                func_802181FC_de(menu, 0, player);
                menu[0] = 1;
            }
            return;
        }
        ((ObjectLinks11B8 *)(player))->unk_CC0 = -1;
        func_802181FC_de(menu, held, player);
        ((ObjectLinks11B8 *)(player))->unk_11B4 = 1;
        menu[0] = 1;
    }
    category = menu[0x388 / 4];
    if (category != -1) {
        return;
    }
    slot = func_80217B3C_de(player);
    if (slot == menu[0x390 / 4]) {
        return;
    }
    if (slot != category) {
        entry = (Entry34 *)&((Block24 *)menu)[slot];
        weapon = entry->weapon;
        if (entry->owned == 0) {
            func_8025DF34_de(0xD4D);
            return;
        }
        if (weapon < 0) {
            menu[0x390 / 4] = category;
            return;
        }
        if (slot != menu[0x37C / 4]) {
            menu[0x37C / 4] = slot;
        }
        if (weapon == ((ObjectLinks11B8 *)(player))->unk_62E) {
            menu[0x390 / 4] = slot;
            return;
        }
        ((ObjectLinks11B8 *)(player))->unk_770 = weapon;
        if (!(((ObjectLinks11B8 *)(player))->unk_38 & 0x1000)) {
            alternate = ((WeaponInfo *)(D_800D052C[weapon]))->alternate;
            if (alternate != category && (ammo = (char *) player + alternate * 2)[0x602] != 0) {
                entry->weapon = alternate;
            }
        }
    }
    menu[0x390 / 4] = slot;
}

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

s32 func_8021846C_de(void *, void *);
s16 func_8022FAF8_de(void *);
s32 func_80285974_de(s32, s32);
void Team_UpdateDraftPanel(DraftState17F4C *state, DraftPlayer17F4C *player, s32 arg2)
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
        func_80217D74_de(&state->state, player, arg2);
    }
    if (player->choice != player->oldChoice) {
        if (player->effect) {
            func_80285974_de((s32)player->effect, 0);
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

#ifdef NON_MATCHING
#include "TYPES.H"

typedef struct DraftChoiceEntry {
    s32 index;
    void *resource;
    s32 enabled;
    f32 angle, value, scale;
} DraftChoiceEntry;
typedef struct DraftChoiceMenu {
    u8 pad0[0x1C];
    DraftChoiceEntry choices[8];
    u8 padDC[0x37C-0xDC];
    s32 selected, ready;
    void *context;
    s32 filter, active;
} DraftChoiceMenu;
typedef struct DraftChoiceMap { u8 unused; s8 slot; } DraftChoiceMap;
typedef struct DraftChoicePlayer {
    u8 pad0[0x602];
    DraftChoiceMap map[22];
    s16 selected;
} DraftChoicePlayer;
extern void *D_800D052C[];
extern f32 D_800C2248_de, D_800C913C_de;
extern s32 func_8022EB0C_de(void *);

void func_802181FC_de(void *menuIn, s32 contextIn, void *playerIn) {
    DraftChoiceMenu *menu = (DraftChoiceMenu *)menuIn;
    void *context = (void *)contextIn;
    DraftChoicePlayer *player = (DraftChoicePlayer *)playerIn;
    DraftChoiceEntry *entry = menu->choices;
    s32 i = 0;
    s32 j;
    s32 filter;
    s32 accept;
    menu->active = 0;
    menu->context = context;
    menu->selected = -1;
    do {
        for (j = 0; j < 22; j++) {
            if (i == player->map[j].slot) break;
        }
        if (j < 22) {
            filter = menu->filter;
            if (filter == -1) accept = 1;
            else if (filter == 3 || filter == 7) accept = i == filter;
            else if (filter == 4) accept = i == 4;
            else {
                accept = 0;
                if (i == filter || i == filter + 1) accept = 1;
            }
            if (!accept) {
                entry->index = -1;
                entry->enabled = 0;
            } else {
                entry->index = j;
                if (player->selected == j) menu->selected = i;
                entry->resource = D_800D052C[j];
                if (func_8022EB0C_de(player) == 0) entry->enabled = 0;
                else entry->enabled = 1;
                entry->value = 0.0f;
                entry->scale = D_800C913C_de;
                entry->angle = (f32)i * D_800C2248_de;
            }
        } else {
            entry->index = -1;
            entry->enabled = 0;
        }
        i++;
        entry++;
    } while (i < 8);
    menu->ready = 1;
}
#else
INCLUDE_ASM("span_1000", func_802181FC_de);
#endif
