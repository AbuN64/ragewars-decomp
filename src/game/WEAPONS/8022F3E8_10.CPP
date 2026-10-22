#include "COMMON/AIPROFILE.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "TYPES.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MENU_TEXT.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/EXTERNS_13.H"
#include "COMMON/INTEGERSTATE244.H"
#include "RENDER_2/8022AE90.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

/* Advances a player's charging action: when the trigger is released (controller latch for a controlled
 * player, otherwise flag 0x2000 with no hold and a disallowed action) or the cooldown is past D_800C2F5C_de, it
 * switches to action 2, runs func_8022AF40_de and func_8022B00C_de and plays sound 0x978 at the player's target or
 * position; otherwise it grows the charge at 0x128 by the charge rate and, each time the cue timer at 0x64
 * runs out, restarts it and plays the charge cue (0x3FB in a multiplayer match without controller, 0x4CD
 * otherwise). */


extern s32 D_80140FF8;


















static inline s32 released(void *actor, Player *player) {
    AiController *control;
    s32 latch;

    if (player->cooldown > D_800C2F5C_de) {
        return 1;
    }
    if ((((Shared_Actor *)actor)->weaponFlags & 0x300000) && player->computer != 0) {
        control = player->controller;
        latch = control->unk23C;
        control->unk23C = 0;
        return latch == 0;
    }
    if (!(player->inputFlags & 0x2000)) {
        return 1;
    }
    if (player->locked != 0) {
        return 1;
    }
    return Weapons_HasAmmoForMode(player, player->selectedAction) == 0;
}

void func_802312C8_de(Shared_Actor *actor, WeaponFireState *attack) {
    Player *player;
    CVector3 *position;
    SharedRecAt564V1 *target;

    player = actor->entity;
    target = player->owner;
    if (target != 0) {
        position = &target->position;
    } else {
        position = &player->pos;
    }
    if (released(actor, player)) {
        func_80214178_de(actor, attack, 2);
        func_8022AF40_de(player);
        func_8022B00C_de(player);
        func_8025DE54_de(0x978, *position, (s32)position, -1);
        return;
    }
    func_80274870_de(&attack->spin, (f32)D_800CA37C * D_800C2F60_de, 0.4f);
    attack->cueTimer -= D_800D2988;
    if (attack->cueTimer <= 0.0f) {
        attack->cueTimer = D_800C2F64_de;
        if (player->computer == 0 && D_80140FF8 == 1) {
            func_8021A9A4_de(actor->entity, 0x3FB);
        } else {
            func_8021A9A4_de(actor->entity, 0x4CD);
        }
    }
}



void func_80231474_de(Shared_Actor *arg0, WeaponFireState *arg1) {
    f32 temp_f12;
    f32 temp_f1;
    f32 temp_f2;
    Player *temp_s1;
    void *temp_v0;

    temp_s1 = (Player *)arg0->entity;
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
    temp_v0 = temp_s1->weaponAnimation;
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
extern s32 D_800D30BC[];

extern s16 func_8022F96C_de(void *);
extern s32 func_8022F55C_de(void *, s16);
extern void func_80239908_de(void *, void *, s32, s32, f32);
extern s32 func_802301F4_de(void *, void *);
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU)
extern s32 D_800E0D44[];
extern u8 D_80152789;
#elif defined(VERSION_EU_X)
extern s32 D_800DCC68[];
extern u8 D_80152789;
#endif
static inline s32 can_fire(Player *player) {
    s32 ammo;
    if (player->cooldown > 0.0f) {
        return 0;
    }
    if (player->computer != 0) {
        return 1;
    }
    if (D_801462D5 != 1) {
        return 1;
    }
    ammo = func_8022F55C_de(&D_80102B00[player->slot * 0x190], player->selectedAction);
    if (ammo == 0) {
        func_8025DF34_de(0xD4D);
        if (player->owner != 0) {
            func_80239908_de(&D_80145088, player->owner, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, D_80152789), func_8022A5A0_de(&D_80145040, player),
                          1.0f);
        }
    }
    return ammo;
}
void func_80231664_de(Shared_Actor *actor, WeaponFireState *arg1) {
    Player *player;
    s32 action;
    s32 single;
    player = actor->entity;
    action = D_800CE8DC[player->pose].action;
    if (Weapons_HasAmmoForMode(player, player->selectedAction) == 0) {
        if (arg1->mode != 2) {
            goto idle;
        }
        arg1->mode = 1;
        if (Weapons_HasAmmoForMode(player, player->selectedAction) == 0) {
        idle:
            player->weapon = func_8022F96C_de(player);
            return;
        }
    }
    if ((player->actionFlags & 0x4000) && can_fire(player) && arg1->rounds > 0) {
        single = 1;
        if (arg1->mode == single) {
            arg1->mode = 2;
            if (Weapons_HasAmmoForMode(player, player->selectedAction) == 0) {
                func_8025DF34_de(0xD4D);
                if (player->owner != 0) {
                    func_80239908_de(&D_80145040.object, player->owner, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, D_80145040.object.language),
                                  func_8022A5A0_de(&D_80145040, player), 1.0f);
                }
                arg1->mode = single;
                goto spin;
            }
        } else {
            arg1->mode = single;
        }
        arg1->rounds = single;
    }
spin:
    if (arg1->mode == 1) {
        if (player->fireSpin > 1.0f) {
            player->fireSpin -= 0.5f;
        }
        if (player->fireSpin < 1.0f) {
            player->fireSpin = 1.0f;
        }
    } else if (arg1->mode == 2) {
        if (player->fireSpin < 2.0f) {
            player->fireSpin += 0.05f;
        }
        if (player->fireSpin > 2.0f) {
            player->fireSpin = 2.0f;
        }
    }
    player->fireFrame = (player->fireFrame + (s32)player->fireSpin) % 8;
    if (func_802301F4_de(actor, arg1) == 0 && !(actor->weaponFlags & 0x400)) {
        func_80214178_de(actor, arg1, action);
    }
}
