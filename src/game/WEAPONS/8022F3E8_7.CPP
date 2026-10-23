#include "COMMON/OBJECTLINKS14C.H"
#include "WEAPONS/MEASUREDRECAT1D8V1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MENU_TEXT.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/INTEGERSTATE244.H"
#include "TYPES.H"
#include "RENDER_2/8022AE90.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

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


extern s32 D_800D30BC[];


extern char D_80145040[];

extern s16 func_8022F96C_de(void *);

extern s32 func_8022F55C_de(void *, s16);


extern s32 func_8022A5A0_de(void *, void *);

extern void Camera_PostTargetedScreenMessage(void *, void *, s32, s32, f32);

extern s32 func_802301F4_de(void *, void *);

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
            Camera_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, D_80152789), func_8022A5A0_de(D_80145040, player),
                          1.0f);
        }
    }
    return ammo;
}

extern s32 func_8022AB20_de(void *arg0, s16 arg1);

/* Advances a player's second charging action: when the trigger is released (as in func_802312C8_de) or the
 * cooldown is past D_800C8008, it switches to action 2, runs func_8022AF40_de and func_8022B00C_de, plays sound
 * 0x794 at the player's target or position and pushes the charge at 0x128 by the release amount; otherwise
 * it grows the charge by the charge rate and each time the cue timer at 0x64 runs out adds the cue period
 * back and plays the charge cue (0x3F9 in a multiplayer match without controller, 0x4CB otherwise).
 * Adapted from func_802312C8_de. */




extern s32 D_80140FF8;


extern s32 func_8025DE54_de(s16, CVector3, void *, s32);


static inline s32 released(void *actor, char *player) {
    char *control;
    s32 latch;

    if (((Actor_func_8022D290_de *)player)->unk_0x11D8 > D_800C8008) {
        return 1;
    }
    if ((((LevelActor *)actor)->flags & 0x300000) && ((Actor_func_8022D290_de *)player)->unk_0x1450 != 0) {
        control = ((Actor_func_8022D290_de *)player)->unk_0x1454;
        latch = ((Brain_func_80212D78_eu_x *)control)->triggerLatch;
        ((Brain_func_80212D78_eu_x *)control)->triggerLatch = 0;
        return latch == 0;
    }
    if (!(((Actor_func_8022D290_de *)player)->unk_0x06AC & 0x2000)) {
        return 1;
    }
    if (((Actor_func_8022D290_de *)player)->unk_0x11B4 != 0) {
        return 1;
    }
    return Weapons_HasAmmoForMode(player, ((Actor_func_8022D290_de *)player)->unk_0x062E) == 0;
}

void func_802307FC_de(Shared_Actor *actor, WeaponFireState *fire) {
    char *player;
    s32 action;
    char *model;
    player = actor->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (Weapons_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
    }
    if ((((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) && can_fire(player) && fire->mode == 1) {
        if (((SharedPlayer *)(player))->views5E8.chargeView.charge >= 50) {
            func_80214178_de(actor, fire, 5);
            fire->mode = 2;
        } else {
            func_8025DF34_de(0xD4D);
            if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                Camera_PostTargetedScreenMessage((D_80145040 + 0x48), ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, (u8)D_80145040[0x1809]),
                              func_8022A5A0_de(D_80145040, player), 1.0f);
            }
            fire->mode = 1;
        }
        return;
    }
    if (func_802301F4_de(actor, fire) == 0) {
        if (!(actor->weaponFlags & 0x400)) {
            func_80214178_de(actor, fire, action);
        }
    } else {
        fire->spin += fire->spin * D_800D2988 * 2.0f;
        model = ((SharedPlayer *)(player))->views5E8.view698_37.emitter;
        if (!(fire->spin < 0.0f ? 1.0f < -fire->spin * 1.7904929f
                                                     : 1.0f < fire->spin * 1.7904929f)) {
            if (fire->spin < 0.0f) {
                ((WeaponAnimationState *)(model))->speed = -fire->spin * 1.7904929f;
            } else {
                ((WeaponAnimationState *)(model))->speed = fire->spin * 1.7904929f;
            }
        } else {
            ((WeaponAnimationState *)(model))->speed = 1.0f;
        }
        fire->spinStep = fire->spin * D_800D2988 * 2.0f;
        fire->mode = 1;
    }
}

void func_80230B04_de(struct MeasuredRecAt1D8V1 *arg0, void *arg1) {
    s16 temp_a1;
    s32 temp_v1;
    void *temp_a0;

    temp_a0 = arg0->value;
    if (!(((struct MeasuredRecAt6AC *)(temp_a0))->value & 0x2000)) {
        temp_a1 = ((struct MeasuredRecAt62EV2 *)(temp_a0))->value;
        if (temp_a1 != 0) {
            if (temp_a1 == 2) {
                temp_v1 = ((struct MeasuredRecAt13CV2 *)(arg1))->value;
                if (temp_v1 == 1) {
                    func_80214178_de(arg0, arg1, 5);
                } else if (temp_v1 == temp_a1) {
                    func_80214178_de(arg0, arg1, 9);
                } else {
                    goto check_height;
                }
            } else {
                goto check_state;
            }
        } else {
check_height:
            if (!(((struct MeasuredRecAt40 *)(arg1))->value > D_800C2F14_de)) {
                func_80214178_de(arg0, arg1, 9);
            } else {
                func_80214178_de(arg0, arg1, 5);
            }
        }
        goto done;
check_state:
        if (func_8022AB20_de(temp_a0, temp_a1) == 1) {
            func_80214178_de(arg0, arg1, 7);
        } else {
            func_80214178_de(arg0, arg1, 5);
        }
done:
        ;
    }
}

void func_80230BC8_de(LevelActor *actor, Dest *attack) {
    char *player;
    CVector3 *position;
    char *target;

    player = actor->controller;
    target = ((Actor_func_8022D290_de *)player)->unk_0x05DC;
    if (target != 0) {
        position = &((SharedRecAt564V1 *)target)->position;
    } else {
        position = &((Shared_ActorView *)player)->position.vector;
    }
    if (released(actor, player)) {
        func_80214178_de(actor, attack, 2);
        func_8022AF40_de(player);
        func_8022B00C_de(player);
        func_8025DE54_de(0x794, *position, position, -1);
        func_80274870_de(&attack->charge, (f32)D_800CA2D8_de * D_800C2F1C_de, 0.4f);
        return;
    }
    func_80274870_de(&attack->charge, (f32)D_800CA2D8_de * D_800C2F20_de, 0.4f);
    attack->cueTimer -= D_800D2988;
    if (attack->cueTimer <= 0.0f) {
        attack->cueTimer += D_800C2F24_de;
        if (((Actor_func_8022D290_de *)player)->unk_0x1450 == 0 && D_80140FF8 == 1) {
            func_8021A9A4_de(actor->controller, 0x3F9);
        } else {
            func_8021A9A4_de(actor->controller, 0x4CB);
        }
    }
}
