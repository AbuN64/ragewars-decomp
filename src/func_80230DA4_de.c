#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022F3E8.h"
#include "types.h"
#include "menu_text.h"
/* Runs a spinning weapon's barrel for its holder at 0x1D8: unless the weapon is in state 4 the spin
   speed at 0x128 decays, the spin angle at 0x124 advances by twice the speed per frame, and the
   holder's model animation speed at 0x168 follows the spin speed, capped at 1; while the fire input
   0x4000 is held and the holder is not stunned, a single player game (D_801462D5) without infinite
   ammunition at 0x1450 checks the ammunition through func_8022F55C_de and, when it is empty, clicks
   (sound 0xD4D) and shows the empty message on the holder's view; with ammunition and a loaded
   weapon at 0x5F6 it plays the wind-up sound 0x7BC unless already firing, sets the firing flags
   0x18400 and restarts the firing timer at 0x1230 at 25. Written with the fire check as the static
   helper shared with func_80231BB0_de. */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern s32 D_800E0D44[], D_800DCC68[];
#endif
extern WeaponActionRecord D_800CE8DC[];
extern char D_80102B00[];
extern u8 D_801462D5;
extern s32 D_800D30BC;
extern f32 D_800D2988;
extern char D_80145040[];
extern char D_80145088;

extern s16 func_8022F96C_de(void *);
extern s32 func_8022F55C_de(void *, s16);
extern s32 func_8025DF34_de(s32);
extern s32 func_8022A5A0_de(void *, void *);
extern void func_80239908_de(void *, void *, s32, s32, f32);

extern void func_80214178_de(void *, void *, s32);
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
            func_80239908_de(&D_80145088, ((SharedPlayer_func_8022A398_de *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC, D_800E0D44, D_800DCC68, D_80152789), func_8022A5A0_de(D_80145040, player),
                          1.0f);
        }
    }
    return ammo;
}
void func_80230DA4_de(void *actor, void *weapon) {
    char *player;
    char *model;
    player = ((Shared_Actor *)(actor))->entity;
    if (((WeaponFireState *)(weapon))->variant != 4) {
        ((WeaponFireState *)(weapon))->spin = func_802747A0_de(((WeaponFireState *)(weapon))->spin, 0.013613569f);
    }
    ((WeaponFireState *)(weapon))->spinStep += ((WeaponFireState *)(weapon))->spin * D_800D2988 * 2.0f;
    model = ((SharedPlayer_func_8022A398_de *)(player))->views5E8.view698_37.emitter;
    if (!(((WeaponFireState *)(weapon))->spin < 0.0f ? 1.0f < -((WeaponFireState *)(weapon))->spin * 1.7904929f
                                                   : 1.0f < ((WeaponFireState *)(weapon))->spin * 1.7904929f)) {
        if (((WeaponFireState *)(weapon))->spin < 0.0f) {
            ((WeaponAnimationState *)(model))->speed = -((WeaponFireState *)(weapon))->spin * 1.7904929f;
        } else {
            ((WeaponAnimationState *)(model))->speed = ((WeaponFireState *)(weapon))->spin * 1.7904929f;
        }
    } else {
        ((WeaponAnimationState *)(model))->speed = 1.0f;
    }
    if ((((SharedPlayer_func_8022A398_de *)(player))->views5E8.view6AC_45.unk6AC & 0x4000) && can_fire(player) && ((SharedPlayer_func_8022A398_de *)(player))->views5E8.chargeView.charge > 0) {
        if (!(((SharedPlayer_func_8022A398_de *)(player))->views122C.view122C_2.options & 0x18400)) {
            func_8025DF34_de(0x7BC);
        }
        ((SharedPlayer_func_8022A398_de *)(player))->views122C.view122C_2.options |= 0x18400;
        ((SharedPlayer_func_8022A398_de *)(player))->fxTime = 25.0f;
    }
}
