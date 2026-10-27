#include "MENU/TEAMMENU.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "RENDER_2/8025DE50_5.H"

/* Runs a player's team selection menu each frame unless a menu is paused (Cinema_IsSequenceActive): while the
   game is ending (D_8014561C) an open menu is closed through func_80218F84_de; a closed menu opens through
   func_80219124_de when team selection D_801468C4 is on and the player has no team yet (0xFF at 0x92 of its
   controls); while it is open the player is held (0x11B4, 0x11B8) and shielded for 2, and the team slot
   under the stick (func_80218988_de) becomes the hovered entry at 0x70, moving the cursor at 0x6C and
   choosing the entry's team for the player unless the entry is disabled or flagged 0x8000; the menu
   then slides open at 0.25 per frame, and once func_8021917C_de confirms a choice it releases the player,
   announces the chosen team with its message and sound, and slides closed, the menu's spin at 0x14
   turning while it is shown. */











#ifdef VERSION_EU
#elif defined(VERSION_EU_X)
#endif
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/CHANNEL.H"
extern s32 D_8014561C;
extern void func_80218F84_de(TeamMenu *);
extern void func_80219124_de(TeamMenu *, s32, SharedPlayer *);
extern s32 func_80218988_de(SharedPlayer *);
extern s32 func_8021917C_de(TeamMenu *, SharedPlayer *);

void func_80218B84_de(TeamMenu *menu, SharedPlayer *player) {
    s32 held;
    s32 slot;
    Entry *entry;
    u16 team;

    if (Cinema_IsSequenceActive() != 0) {
        return;
    }
    if (D_8014561C != 0 && menu->state != 0) {
        func_80218F84_de(menu);
        return;
    }
    held = player->views5E8.view698_35.controller->unkB0 & 0x8000;
    if (menu->state == 0 || menu->state == 3) {
        if (D_801462C8.counters.teams == 0 || player->views5D8.view5D8_1.record->team != 0xFF) {
            goto run;
        }
        func_80219124_de(menu, held, player);
        menu->state = 1;
    }
    player->views5E8.view11B4_136.locked = 1;
    player->views5E8.view11B8_138.frozen = 1;
    player->views5E8.view670_31.shield = 2.0f;
    slot = func_80218988_de(player);
    if (slot != menu->hover) {
        if (slot != -1) {
            entry = (Entry *) ((char *) menu + slot * 0x14);
            team = entry->team;
            if (entry->enabled == 0) {
                goto run;
            }
            if ((s16) team < 0) {
                menu->hover = -1;
                goto run;
            }
            if (slot != menu->cursor) {
                menu->cursor = slot;
            }
            player->views5D8.view5D8_1.record->team = team;
        }
        menu->hover = slot;
    }
run:
    switch (menu->state) {
    case 1:
        menu->open += D_800D2988 * 0.25f;
        if (1.0f <= menu->open) {
            menu->open = 1.0f;
            menu->state = 2;
        }
        break;
    case 2:
        if (func_8021917C_de(menu, player) == 0) {
            break;
        }
        menu->state = 3;
        player->views5E8.view11B4_136.locked = 0;
        player->views5E8.view11B8_138.frozen = 0;
        switch (player->views5D8.view5D8_1.record->team) {
        case 0:
#ifdef VERSION_EU
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800E0FF4[((u8 *) &D_80145088)[0x17C1]]);
#elif defined(VERSION_EU_X)
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800DCE6C[((u8 *) &D_80145088)[0x17C1]]);
#else
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800D3168);
#endif
            SoundElement_PlayFlatSound(0x2E6);
            break;
        case 1:
#ifdef VERSION_EU
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800E1004[((u8 *) &D_80145088)[0x17C1]]);
#elif defined(VERSION_EU_X)
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800DCE78[((u8 *) &D_80145088)[0x17C1]]);
#else
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800D316C);
#endif
            SoundElement_PlayFlatSound(0x2E4);
            break;
        case 2:
#ifdef VERSION_EU
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800E1014[((u8 *) &D_80145088)[0x17C1]]);
#elif defined(VERSION_EU_X)
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800DCE84[((u8 *) &D_80145088)[0x17C1]]);
#else
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800D3170);
#endif
            SoundElement_PlayFlatSound(0x2E8);
            break;
        case 3:
#ifdef VERSION_EU
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800E1024[((u8 *) &D_80145088)[0x17C1]]);
#elif defined(VERSION_EU_X)
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800DCE90[((u8 *) &D_80145088)[0x17C1]]);
#else
            Camera_PostScreenMessage(&D_80145088, player->views5DC.view5DC_1.view, D_800D3174);
#endif
            SoundElement_PlayFlatSound(0x2EC);
            break;
        }
        /* fall through */
    case 3:
        menu->open -= D_800D2988 * 0.25f;
        if (menu->open <= 0.0f) {
            menu->open = 0.0f;
            menu->state = 0;
        }
        break;
    }
    if (menu->state != 0) {
        menu->spin += D_800D2988 * 0.52359885f;
    }
}
