#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022F3E8.h"
#include "types.h"
#include "span_C76B0/data.h"
#include "common/types_8a8189af7b05.h"
#include "menu_text.h"

/* Advances a player's charging action: when the trigger is released (controller latch for a controlled
 * player, otherwise flag 0x2000 with no hold and a disallowed action) or the cooldown is past D_800C2F5C_de, it
 * switches to action 2, runs func_8022AF40_de and func_8022B00C_de and plays sound 0x978 at the player's target or
 * position; otherwise it grows the charge at 0x128 by the charge rate and, each time the cue timer at 0x64
 * runs out, restarts it and plays the charge cue (0x3FB in a multiplayer match without controller, 0x4CD
 * otherwise). */


extern s32 D_800CA37C;
extern f32 D_800D2988;
extern s32 D_80140FF8;
extern void func_80214178_de(void *, void *, s32);

extern void func_8022AF40_de(void *);

extern s32 func_8025DE54_de(s16, s32, s32, s32, s32 *, s32);
extern void func_80274870_de(f32 *, f32, f32);
















static inline s32 released(void *actor, char *player) {
    char *control;
    s32 latch;

    if (((func_80230BB8_S1 *)(player))->unk11D8 > D_800C2F5C_de) {
        return 1;
    }
    if ((((func_80230BB8_S2 *)(actor))->unk100 & 0x300000) && ((func_80230BB8_S1 *)(player))->unk1450 != 0) {
        control = ((func_80230BB8_S1 *)(player))->unk1454;
        latch = ((func_80230BB8_S3 *)(control))->unk23C;
        ((func_80230BB8_S3 *)(control))->unk23C = 0;
        return latch == 0;
    }
    if (!(((func_80230BB8_S1 *)(player))->unk6AC & 0x2000)) {
        return 1;
    }
    if (((func_80230BB8_S1 *)(player))->unk11B4 != 0) {
        return 1;
    }
    return func_80222AA4_de(player, ((func_80230BB8_S1 *)(player))->unk62E) == 0;
}

void func_802312C8_de(void *actor, void *attack) {
    char *player;
    s32 *position;
    char *target;

    player = ((func_80230BB8_S2 *)(actor))->unk1D8.v0;
    target = ((func_80230BB8_S1 *)(player))->unk5DC;
    if (target != 0) {
        position = &((func_802063EC_S2 *)(target))->unk128;
    } else {
        position = &((func_80230BB8_S1 *)(player))->unk8;
    }
    if (released(actor, player)) {
        func_80214178_de(actor, attack, 2);
        func_8022AF40_de(player);
        func_8022B00C_de(player);
        func_8025DE54_de(0x978, position[0], position[1], position[2], position, -1);
        return;
    }
    func_80274870_de(&((func_80230BB8_S5 *)(attack))->unk128, (f32)D_800CA37C * D_800C2F60_de, 0.4f);
    ((func_80230BB8_S5 *)(attack))->unk64 -= D_800D2988;
    if (((func_80230BB8_S5 *)(attack))->unk64 <= 0.0f) {
        ((func_80230BB8_S5 *)(attack))->unk64 = ((func_802077F4_S2 *)(&D_800C2F60_de))->unk4;
        if (((func_80230BB8_S1 *)(player))->unk1450 == 0 && D_80140FF8 == 1) {
            func_8021A9A4_de(((func_80230BB8_S2 *)(actor))->unk1D8.v1, 0x3FB);
        } else {
            func_8021A9A4_de(((func_80230BB8_S2 *)(actor))->unk1D8.v1, 0x4CD);
        }
    }
}

extern f32 D_800D2988;

extern void func_80274870_de(f32 *, f32, f32);

void func_80231474_de(Shared_Actor *arg0, WeaponFireState *arg1) {
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    SharedPlayer *temp_s1;
    void *temp_v0;

    temp_s1 = (SharedPlayer *)arg0->entity;
    if (arg1->variant != 4) {
        temp_f12 = arg1->spin;
        if (temp_f12 > 0.0f) {
            arg1->spin = func_802747A0_de(temp_f12, D_800C2F68_de);
        } else {
            f32 value = arg1->spinStep;
            f32 period = D_800C2F6C_de;
            arg1->spin = 0.0f;
            if (period <= value) {
                do {
                    value -= period;
                    arg1->spinStep = value;
                } while (period <= value);
            }
            period = arg1->spinStep;
            if (period < D_800C2F70_de) {
                func_80274870_de(&arg1->spinStep, 0.0f, 0.125f);
            } else if (period < D_800C2F74_de) {
                func_80274870_de(&arg1->spinStep, 2.0943952f, 0.125f);
            } else if (period < D_800C2F78_de) {
                func_80274870_de(&arg1->spinStep, 4.1887903f, 0.125f);
            } else {
                func_80274870_de(&arg1->spinStep, 6.2831855f, 0.125f);
            }
        }
    }
    arg1->spinStep += (arg1->spin * D_800D2988) * 2.0f;
    temp_f1 = arg1->spin;
    temp_v0 = temp_s1->views5E8.view698_34.unk698;
    if (!(temp_f1 < 0.0f
              ? D_800C2F80_de < (-temp_f1 * D_800C2F7C_de)
              : D_800C2F88_de < (temp_f1 * D_800C2F84_de))) {
        temp_f2 = arg1->spin;
        if (temp_f2 < 0.0f) {
            ((WeaponAnimationState *)temp_v0)->speed = (f32) (-temp_f2 * D_800C2F8C_de);
            return;
        }
        ((WeaponAnimationState *)temp_v0)->speed = (f32) (temp_f2 * D_800C2F90_de);
        return;
    }
    ((WeaponAnimationState *)temp_v0)->speed = (f32) D_800C2F94_de;
}

/* Runs a player's rapid-fire action: when the current action is not allowed a type 2 request drops to type 1
 * and retries once before the idle state is refreshed; a player flagged 0x4000 that may fire with rounds at
 * 0x144 turns a type 1 request into type 2 (reporting the empty weapon and staying type 1 when firing is
 * not allowed) or any other request into type 1, and holds one round; the barrel spin at 0x11F4 then winds
 * down by 0.5 to 1 while type 1 or up by 0.05 to 2 while type 2 and turns the barrel frame at 0x11F8 (of
 * 8); finally the default action for the player's state starts unless func_802301F4_de handled the request
 * or the actor is flagged 0x400. Adapted from func_80231BB0_de with the same static fire check. */
extern WeaponActionRecord D_800CE8DC[];
extern char D_80102B00[];
extern u8 D_801462D5;
extern s32 D_800D30BC[];

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
            func_80239908_de(&D_80145088, ((SharedPlayer_func_8022A398_de *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, D_80152789), func_8022A5A0_de(&D_80145040, player),
                          1.0f);
        }
    }
    return ammo;
}
void func_80231664_de(void *actor, void *arg1) {
    char *player;
    s32 action;
    s32 single;
    player = ((Shared_Actor *)(actor))->entity;
    action = D_800CE8DC[((SharedPlayer_func_8022A398_de *)(player))->views5E8.view650_15.unk650].action;
    if (func_80222AA4_de(player, ((SharedPlayer_func_8022A398_de *)(player))->views5E8.view62E_13.unk62E) == 0) {
        if (((WeaponFireState *)(arg1))->mode != 2) {
            goto idle;
        }
        ((WeaponFireState *)(arg1))->mode = 1;
        if (func_80222AA4_de(player, ((SharedPlayer_func_8022A398_de *)(player))->views5E8.view62E_13.unk62E) == 0) {
        idle:
            ((SharedPlayer_func_8022A398_de *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
            return;
        }
    }
    if ((((SharedPlayer_func_8022A398_de *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) && can_fire(player) && ((WeaponFireState *)(arg1))->rounds > 0) {
        single = 1;
        if (((WeaponFireState *)(arg1))->mode == single) {
            ((WeaponFireState *)(arg1))->mode = 2;
            if (func_80222AA4_de(player, ((SharedPlayer_func_8022A398_de *)(player))->views5E8.view62E_13.unk62E) == 0) {
                func_8025DF34_de(0xD4D);
                if (((SharedPlayer_func_8022A398_de *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                    func_80239908_de(&D_80145040.object, ((SharedPlayer_func_8022A398_de *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, D_80145040.object.language),
                                  func_8022A5A0_de(&D_80145040, player), 1.0f);
                }
                ((WeaponFireState *)(arg1))->mode = single;
                goto spin;
            }
        } else {
            ((WeaponFireState *)(arg1))->mode = single;
        }
        ((WeaponFireState *)(arg1))->rounds = single;
    }
spin:
    if (((WeaponFireState *)(arg1))->mode == 1) {
        if (((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.spin > 1.0f) {
            ((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.spin -= 0.5f;
        }
        if (((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.spin < 1.0f) {
            ((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.spin = 1.0f;
        }
    } else if (((WeaponFireState *)(arg1))->mode == 2) {
        if (((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.spin < 2.0f) {
            ((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.spin += 0.05f;
        }
        if (((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.spin > 2.0f) {
            ((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.spin = 2.0f;
        }
    }
    ((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.frame = (((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.frame + (s32)((SharedPlayer_func_8022A398_de *)(player))->views5E8.rapidFireView.spin) % 8;
    if (func_802301F4_de(actor, arg1) == 0 && !(((Shared_Actor *)(actor))->weaponFlags & 0x400)) {
        func_80214178_de(actor, arg1, action);
    }
}
