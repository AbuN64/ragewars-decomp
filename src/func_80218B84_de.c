#include "span_1000/code_80217388.h"
#include "types.h"




























/* Runs a player's team selection menu each frame unless a menu is paused (func_80245784_de): while the
   game is ending (D_8014561C) an open menu is closed through func_80218F84_de; a closed menu opens through
   func_80219124_de when team selection D_801468C4 is on and the player has no team yet (0xFF at 0x92 of its
   controls); while it is open the player is held (0x11B4, 0x11B8) and shielded for 2, and the team slot
   under the stick (func_80218988_de) becomes the hovered entry at 0x70, moving the cursor at 0x6C and
   choosing the entry's team for the player unless the entry is disabled or flagged 0x8000; the menu
   then slides open at 0.25 per frame, and once func_8021917C_de confirms a choice it releases the player,
   announces the chosen team with its message and sound, and slides closed, the menu's spin at 0x14
   turning while it is shown. */











extern f32 D_800D2988;
extern s32 D_800D3168;
extern s32 D_800D316C;
extern s32 D_800D3170;
extern s32 D_800D3174;
#ifdef VERSION_EU
extern s32 D_800E0FF4[];
extern s32 D_800E1004[];
extern s32 D_800E1014[];
extern s32 D_800E1024[];
#elif defined(VERSION_EU_X)
extern s32 D_800DCE6C[];
extern s32 D_800DCE78[];
extern s32 D_800DCE84[];
extern s32 D_800DCE90[];
#endif
extern char D_80145088;
extern s32 D_8014561C;
extern s32 D_801468C4;
extern s32 func_80245784_de(void);
extern void func_80218F84_de(TeamMenu *);
extern void func_80219124_de(TeamMenu *, s32, SharedPlayer_func_80218B84_de *);
extern s32 func_80218988_de(SharedPlayer_func_80218B84_de *);
extern s32 func_8021917C_de(TeamMenu *, SharedPlayer_func_80218B84_de *);
extern void func_80237E80_de(char *, void *, s32);
extern void func_8025DF34_de(s32);

void func_80218B84_de(TeamMenu *menu, SharedPlayer_func_80218B84_de *player) {
    s32 held;
    s32 slot;
    Entry *entry;
    u16 team;

    if (func_80245784_de() != 0) {
        return;
    }
    if (D_8014561C != 0 && menu->state != 0) {
        func_80218F84_de(menu);
        return;
    }
    held = player->views5E8.view698_35.controller->unkB0 & 0x8000;
    if (menu->state == 0 || menu->state == 3) {
        if (D_801468C4 == 0 || player->views5D8.view5D8_2.controls->team != 0xFF) {
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
            player->views5D8.view5D8_2.controls->team = team;
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
        switch (player->views5D8.view5D8_2.controls->team) {
        case 0:
#ifdef VERSION_EU
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800E0FF4[((u8 *) &D_80145088)[0x17C1]]);
#elif defined(VERSION_EU_X)
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800DCE6C[((u8 *) &D_80145088)[0x17C1]]);
#else
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800D3168);
#endif
            func_8025DF34_de(0x2E6);
            break;
        case 1:
#ifdef VERSION_EU
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800E1004[((u8 *) &D_80145088)[0x17C1]]);
#elif defined(VERSION_EU_X)
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800DCE78[((u8 *) &D_80145088)[0x17C1]]);
#else
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800D316C);
#endif
            func_8025DF34_de(0x2E4);
            break;
        case 2:
#ifdef VERSION_EU
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800E1014[((u8 *) &D_80145088)[0x17C1]]);
#elif defined(VERSION_EU_X)
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800DCE84[((u8 *) &D_80145088)[0x17C1]]);
#else
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800D3170);
#endif
            func_8025DF34_de(0x2E8);
            break;
        case 3:
#ifdef VERSION_EU
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800E1024[((u8 *) &D_80145088)[0x17C1]]);
#elif defined(VERSION_EU_X)
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800DCE90[((u8 *) &D_80145088)[0x17C1]]);
#else
            func_80237E80_de(&D_80145088, player->views5DC.view5DC_1.view, D_800D3174);
#endif
            func_8025DF34_de(0x2EC);
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
