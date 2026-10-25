#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/MATH_HELPERS.H"
#include "MENU/TEAMMENU.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/OBJECTSTATE90.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "RENDER_2/8025DE50_5.H"

/* Runs a player's weapon menu each frame: the menu button (0x8000 of the controller at 0x698) counts
   only while func_8022C460_de allows and the controller is not paused through D_801468F4, which instead
   closes the menu (state 3), as does holding the button while the value at 0x4 is positive; from a
   closed state holding it clears the pending weapon at 0xCC0, rebuilds the menu through Team_InitWeaponChoices
   and opens it, while releasing it with a weapon pending outside category 8 rebuilds it and marks it
   open; with no category the slot under the cursor from func_80217B3C_de, when it changes, plays sound
   0xD4D for an unowned weapon, forgets an empty slot, moves the cursor at 0x37C and requests the
   slot's weapon at 0x770 unless it is current, switching the slot to the weapon's alternate at 0xC of
   its D_800D052C record when the player holds that one and input bit 0x1000 is clear. */




extern s32 func_80217B3C_de(void *);






void func_80217D74_de(s32 *menu, void *player, s32 unused2) {
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
                Team_InitWeaponChoices((CBarrel *)menu, 0, player);
                menu[0] = 1;
            }
            return;
        }
        ((ObjectLinks11B8 *)(player))->unk_CC0 = -1;
        Team_InitWeaponChoices((CBarrel *)menu, held, player);
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
            Render_PlayFlatSound(0xD4D);
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
extern f32 D_800D2988;

s32 func_8021846C_de(void *, void *);
s16 func_8022FAF8_de(void *);
s32 func_80285974_de(s32, s32);
void Team_UpdateDraftPanel(DraftState17F4C *state, DraftPlayer17F4C *player, s32 arg2)
{
    if ((u32)(player->type - 17) < 2) return;
    if (player->blocked) return;
    if (player->delay > 0.0f) return;
    if (Camera_IsSequenceActive()) return;
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
        state->timer += D_800D2988 * 1.25f;
        if (state->selection != -1) state->value = 16.0f;
        else state->value = 0.0f;
        if (state->timer >= 1.0f) {
            state->state = 2; state->timer = 1.0f;
            if (state->selection != -1) state->selection = 8;
        }
        break;
    case 2:
        if (!func_8021846C_de(state, player)) break;
        state->selection = -1; player->active = 0; state->state = 3;
    case 3:
        state->timer -= D_800D2988 * 0.25f;
        if (state->timer <= 0.0f) { state->timer = 0.0f; state->state = 0; }
        break;
    }
    if (state->state) state->angle += D_800D2988 * (RW_PI_F6 / 6);
    else player->active = 0;
}

/* CPlayer_t as the weapon barrel reads it (debug catalog): m_Data (CPlayerLoadSaveData_t at 0x5E0) holds per weapon
   index whether the player holds it and its barrel slot (m_WeaponList, CWeapon_t at 0x602), then m_CurrentWeapon. */
typedef struct CWeapon_t {
    s8 m_bHolding;
    s8 m_nWeaponSlot;
} CWeapon;
struct TeamWeaponPlayer {
    u8 pad0[0x602];
    CWeapon m_WeaponList[22];
    s16 m_CurrentWeapon;
};
extern f32 D_800C2248_de, D_800C913C_de;
extern s32 World_PlayerHasAmmoForWeapon(void *player, s32 weapon);
/* Fills the first eight weapons of the barrel: a slot shows the weapon the player put in it when m_DisplaySlot
   allows that slot (-1 every slot, 3, 7 or 4 only that slot, else that slot and the next), with its D_800D052C
   record, whether the player has ammo for it and a rotation of 45 degrees per slot, and m_Selected lands on the
   current weapon; any other slot is empty (-1). */
void Team_InitWeaponChoices(CBarrel *barrel, s32 buttonAWheel, TeamWeaponPlayer *player) {
    s32 choice;
    s32 weapon;
    s32 displaySlot;
    s32 accepted;
    barrel->m_UnderwaterWhenSetup = 0;
    barrel->m_ButtonAWheel = buttonAWheel;
    barrel->m_Selected = -1;
    choice = 0;
    do {
        for (weapon = 0; weapon < 22; weapon++) {
            if (choice == player->m_WeaponList[weapon].m_nWeaponSlot) break;
        }
        if (weapon >= 22) {
            barrel->m_WeaponList[choice].m_Weapon = -1;
            barrel->m_WeaponList[choice].m_bEnabled = 0;
        } else {
            displaySlot = barrel->m_DisplaySlot;
            if (displaySlot == -1) accepted = 1;
            else if (displaySlot == 3 || displaySlot == 7) accepted = choice == displaySlot;
            else if (displaySlot == 4) accepted = choice == 4;
            else {
                accepted = 0;
                if (choice == displaySlot || choice == displaySlot + 1) accepted = 1;
            }
            if (!accepted) {
                barrel->m_WeaponList[choice].m_Weapon = -1;
                barrel->m_WeaponList[choice].m_bEnabled = 0;
            } else {
                barrel->m_WeaponList[choice].m_Weapon = weapon;
                if (player->m_CurrentWeapon == weapon) barrel->m_Selected = choice;
                barrel->m_WeaponList[choice].m_pInfo = D_800D052C[weapon];
                if (World_PlayerHasAmmoForWeapon(player, weapon) != 0) barrel->m_WeaponList[choice].m_bEnabled = 1;
                else barrel->m_WeaponList[choice].m_bEnabled = 0;
                barrel->m_WeaponList[choice].m_Spin = 0.0f;
                barrel->m_WeaponList[choice].m_Scale = D_800C913C_de;
                barrel->m_WeaponList[choice].m_Rot = (f32)choice * D_800C2248_de;
            }
        }
        choice++;
    } while (choice < 8);
    barrel->m_QuickSelect = 1;
}
