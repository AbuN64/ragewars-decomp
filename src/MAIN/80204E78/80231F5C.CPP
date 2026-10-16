#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
#include "TYPES.H"
#include "span_16E000/code_804264F0.h"
/* Handles a player's charged secondary action: refreshes the idle state when the action is not allowed and
 * picks the effect position (the weapon's at 0x128, else the player's); a player flagged 0x4000 that may
 * fire with a type 1 request marks it type 2 and, once charged to 50, plays sound 0xB23 at that position and
 * takes action 5, otherwise reports the empty weapon and restores type 1; any other request func_802301F4_de
 * handles becomes type 1 with 0x124 cleared, else the state's default action starts unless the actor is
 * flagged 0x400. Adapted from func_80231BB0_de with the same static fire check. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern s32 D_800E0D44[], D_800DCC68[];
#endif

extern WeaponActionRecord D_800CE8DC[];
extern char D_80102B00[];
extern s32 D_800D30BC[];


extern char D_80145040[];
#include "shared/menu_match_globals.h"

extern s16 func_8022F96C_de(void *);
extern s32 func_8022F55C_de(void *, s16);
extern s32 func_8025DF34_de(s32);
extern s32 func_8025DE54_de(s32, s32, s32, s32, void *, void *);
extern s32 func_8022A5A0_de(void *, void *);
extern void func_80239908_de(void *, void *, s32, s32, f32);
extern s32 func_802301F4_de(void *, void *);
extern void func_80214178_de(void *, void *, s32);

static inline s32 can_fire(char *player) {
    s32 ammo;

    if (((SharedPlayer *)(player))->views5E8.view11D8_147.unk11D8 > 0.0f) {
        return 0;
    }
    if (((SharedPlayer *)(player))->views1450.view1450_0.unk1450 != 0) {
        return 1;
    }
    if (D_801462D5 != 1) {
        return 1;
    }
    ammo = func_8022F55C_de(&D_80102B00[((SharedPlayer *)(player))->views1C.view5D4_45.unk5D4 * 0x190], ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E);
    if (ammo == 0) {
        func_8025DF34_de(0xD4D);
        if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
            func_80239908_de(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, D_80152789), func_8022A5A0_de(D_80145040, player),
                          D_800C2FC4_de);
        }
    }
    return ammo;
}

void func_80231F6C_de(Shared_Actor *actor, WeaponFireState *arg1) {
    char *player;
    s32 action;
    s32 *pos;
    s32 type;

    player = actor->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (func_80222AA4_de(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
    }
    if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
        pos = (s32 *)(((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC + 0x128);
    } else {
        pos = (s32 *)&((SharedPlayer *)(player))->views0.view8_2.unk8;
    }
    if ((((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) && can_fire(player) && (type = arg1->mode) == 1) {
        arg1->mode = 2;
        if (((SharedPlayer *)(player))->views5E8.chargeView.charge >= 0x32) {
            func_8025DE54_de(0xB23, pos[0], pos[1], pos[2], pos, player);
            func_80214178_de(actor, arg1, 5);
        } else {
            func_8025DF34_de(0xD4D);
            if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                func_80239908_de(D_80145040 + 0x48, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, (u8)D_80145040[0x1809]),
                              func_8022A5A0_de(D_80145040, player), D_800C2FC8_de);
            }
            arg1->mode = type;
        }
        return;
    }
    if (func_802301F4_de(actor, arg1) == 0) {
        if (!(actor->weaponFlags & 0x400)) {
            func_80214178_de(actor, arg1, action);
        }
        return;
    }
    arg1->mode = 1;
    arg1->spinStep = 0.0f;
}
