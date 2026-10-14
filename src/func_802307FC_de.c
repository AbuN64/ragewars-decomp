#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022F3E8.h"
#include "types.h"
#include "menu_text.h"
/* Runs a charge weapon's fire for its holder at 0x1D8: picks the holder's next weapon at 0x770 through
   func_8022F96C_de when the current one cannot be used; while the fire input 0x4000 is held on a weapon
   that can fire (not stunned, with ammunition, clicking and showing the empty message otherwise) in
   ready state 1 at 0x13C, a full charge of at least 50 at 0x5F6 fires action 5 and enters state 2,
   while a partial charge clicks and shows the not-ready message; otherwise it fires the state's action
   from D_800CE8DC unless func_802301F4_de handles the weapon or the actor has flag 0x400, and when
   func_802301F4_de handles it the barrel spin at 0x128 grows, drives the model's animation speed at 0x168
   (capped at 1), returns the weapon to state 1 and sets the spin step at 0x124. */
extern WeaponActionRecord D_800CE8DC[];
extern char D_80102B00[];
extern u8 D_801462D5;
extern s32 D_800D30BC[];
extern f32 D_800D2988;
extern char D_80145040[];
extern char D_80145088;

extern s16 func_8022F96C_de(void *);
extern s32 func_8022F55C_de(void *, s16);
extern s32 func_8025DF34_de(s32);
extern s32 func_8022A5A0_de(void *, void *);
extern void func_80239908_de(void *, void *, s32, s32, f32);
extern s32 func_802301F4_de(void *, void *);
extern void func_80214178_de(void *, void *, s32);
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU)
extern s32 D_800E0D44[];
extern u8 D_80152789;
#elif defined(VERSION_EU_X)
extern s32 D_800DCC68[];
extern u8 D_80152789;
#endif
static inline s32 can_fire(char *player) {
    s32 ammo;
    if (((SharedPlayer_func_8022A398_de *)(player))->views5E8.view11D8_147.unk11D8 > 0.0f) {
        return 0;
    }
    if (((SharedPlayer_func_8022A398_de *)(player))->views1450.view1450_0.unk1450 != 0) {
        return 1;
    }
    if (D_801462D5 != 1) {
        return 1;
    }
    ammo = func_8022F55C_de(&D_80102B00[((SharedPlayer_func_8022A398_de *)(player))->views1C.view5D4_45.unk5D4 * 0x190], ((SharedPlayer_func_8022A398_de *)(player))->views5E8.view62E_13.unk62E);
    if (ammo == 0) {
        func_8025DF34_de(0xD4D);
        if (((SharedPlayer_func_8022A398_de *)(player))->views5DC.view5DC_0.unk5DC != 0) {
            func_80239908_de(&D_80145088, ((SharedPlayer_func_8022A398_de *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, D_80152789), func_8022A5A0_de(D_80145040, player),
                          1.0f);
        }
    }
    return ammo;
}
void func_802307FC_de(void *actor, void *fire) {
    char *player;
    s32 action;
    char *model;
    player = ((Shared_Actor *)(actor))->entity;
    action = D_800CE8DC[((SharedPlayer_func_8022A398_de *)(player))->views5E8.view650_15.unk650].action;
    if (func_80222AA4_de(player, ((SharedPlayer_func_8022A398_de *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer_func_8022A398_de *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
    }
    if ((((SharedPlayer_func_8022A398_de *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) && can_fire(player) && ((WeaponFireState *)(fire))->mode == 1) {
        if (((SharedPlayer_func_8022A398_de *)(player))->views5E8.chargeView.charge >= 50) {
            func_80214178_de(actor, fire, 5);
            ((WeaponFireState *)(fire))->mode = 2;
        } else {
            func_8025DF34_de(0xD4D);
            if (((SharedPlayer_func_8022A398_de *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                func_80239908_de((D_80145040 + 0x48), ((SharedPlayer_func_8022A398_de *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, (u8)D_80145040[0x1809]),
                              func_8022A5A0_de(D_80145040, player), 1.0f);
            }
            ((WeaponFireState *)(fire))->mode = 1;
        }
        return;
    }
    if (func_802301F4_de(actor, fire) == 0) {
        if (!(((Shared_Actor *)(actor))->weaponFlags & 0x400)) {
            func_80214178_de(actor, fire, action);
        }
    } else {
        ((WeaponFireState *)(fire))->spin += ((WeaponFireState *)(fire))->spin * D_800D2988 * 2.0f;
        model = ((SharedPlayer_func_8022A398_de *)(player))->views5E8.view698_37.emitter;
        if (!(((WeaponFireState *)(fire))->spin < 0.0f ? 1.0f < -((WeaponFireState *)(fire))->spin * 1.7904929f
                                                     : 1.0f < ((WeaponFireState *)(fire))->spin * 1.7904929f)) {
            if (((WeaponFireState *)(fire))->spin < 0.0f) {
                ((WeaponAnimationState *)(model))->speed = -((WeaponFireState *)(fire))->spin * 1.7904929f;
            } else {
                ((WeaponAnimationState *)(model))->speed = ((WeaponFireState *)(fire))->spin * 1.7904929f;
            }
        } else {
            ((WeaponAnimationState *)(model))->speed = 1.0f;
        }
        ((WeaponFireState *)(fire))->spinStep = ((WeaponFireState *)(fire))->spin * D_800D2988 * 2.0f;
        ((WeaponFireState *)(fire))->mode = 1;
    }
}
