#include "include_asm.h"
#include "COMMON/NAME.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/AIPROFILE.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "RENDER_2/8022AE90_2.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

/* Runs a player's aiming action: refreshes the idle state when the action is not allowed; while the aim
 * flag 0x4000 is held and the weapon may fire (as in func_80231BB0_de) the attack enters aiming and, for scoped
 * weapons, zooms in through func_8022B1A8; when aiming stops it zooms back out unless the zoom was already
 * cancelled; then the default action for the player's state starts unless func_802301F4_de handled the
 * request or the actor is flagged 0x400. Adapted from func_80231BB0_de with the aiming state.
 */

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 *D_800E0D44[], *D_800DCC68[];

#else
#endif
extern WeaponActionRecord D_800CE8DC[];
extern MatchRewardsRecord D_80102B00[];

extern u8 *D_800D30BC;


extern s32 func_8022F96C_de(void *);
extern s32 func_8022F55C_de(void *, s32);
extern s32 func_8022A5A0_de(void *, void *);
extern Message *func_80239908_de(void *, void *, u8 *, s32, f32);
extern s32 func_802301F4_de(void *, void *);

#if defined(VERSION_EU_X)
extern void func_80228E60_eu(void *, s32);

#else
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
    ammo = func_8022F55C_de(&D_80102B00[((SharedPlayer *)(player))->views1C.view5D4_45.unk5D4], ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E);
    if (ammo == 0) {
        func_8025DF34_de(0xD4D);
        if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
#if defined(VERSION_EU)
            func_80239908_de(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, ((D_800E0D44)[D_80152789]), func_8022A5A0_de(&D_80145040, player),
#elif defined(VERSION_EU_X)
            func_80239908_de(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, ((D_800DCC68)[D_80152789]), func_8022A5A0_de(&D_80145040, player),
#else
            func_80239908_de(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, (D_800D30BC), func_8022A5A0_de(&D_80145040, player),
#endif
                          D_800C2FCC_de);
        }
    }
    return ammo;
}

void func_802321C8_de(Shared_Actor *actor, WeaponFireState *attack) {
    char *player;
    s32 action;

    player = (char *)actor->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (Weapons_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
    }
    if ((((SharedPlayer *)(player))->views5E8.view6AC_45.unk6AC & 0x4000) && can_fire(player)) {
        attack->triggered = 1;
        if (((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x2000) {

#if defined(VERSION_EU_X)
            func_80228E60_eu(player, 0);
#else
            func_8022B1A8(player, 0);
#endif

            attack->alternate = 1;
        }
    } else if (attack->triggered != 0) {
        if (attack->alternate == 0) {

#if defined(VERSION_EU_X)
            func_80228E60_eu(player, 1);
#else
            func_8022B1A8(player, 1);
#endif

        } else {
            attack->alternate = 0;
        }
        attack->triggered = 0;
    }
    if (func_802301F4_de(actor, attack) == 0 && !(actor->weaponFlags & 0x400)) {
        func_80214178_de(actor, attack, action);
    }
}


/* D_800C2FCC_de is resident shared data supplied by its retained ROM slice. */

#ifdef NON_MATCHING
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C2FD0_de;
extern u8 *D_800D30BC;
extern void func_8022B984_de(void *);
/* Runs a pending special action of a player: decides from the player's state (0x62E) and its flags whether
 * the action is blocked, handled by func_802301F4_de, or started; when started it plays the state 5 effect,
 * checks the state 3 resource through func_8022F55C_de and starts the default action (2, or 0xB when the
 * weapon state at 0x594 is 2). The request byte at 0xCB is cleared when the action was refused. */
void func_802323A4_de(void *actor, void *attack) {
    void *player = FIELD(void *, actor, 0x1D8);
    s32 refused;
    s32 started;
    s32 result;
    if (FIELD(s8, attack, 0xCB) == 0) {
        return;
    }
    switch (FIELD(s16, player, 0x62E)) {
    case 4:
    case 0xE:
    case 0xF:
        refused = 0;
        break;
    case 0xA:
        refused = (FIELD(u32, player, 0x6AC) & 0x4000) != 0 && FIELD(s16, player, 0x5F8) != 0;
        break;
    case 3:
        refused = (FIELD(u32, player, 0x6AC) & 0x6000) == 0x6000 && FIELD(s16, player, 0x5F4) != 0 &&
                  FIELD(s16, player, 0x5F6) == 0;
        break;
    default:
        refused = func_802301F4_de(actor, attack);
        break;
    }
    if (refused != 0) {
        FIELD(s8, attack, 0xCB) = 0;
        FIELD(s8, attack, 0x35) = -1;
        result = 1;
    } else {
        if (FIELD(s16, player, 0x62E) == 5) {
            func_8022B00C_de(player);
            func_8025DE54_de(0x460, FIELD(CVector3, player, 0x8), (s32)((char *)player + 8), -1);
        }
        if (FIELD(s16, player, 0x62E) == 3) {
            if (0.0f < FIELD(f32, player, 0x11D8)) {
                started = 0;
            } else if (FIELD(s32, player, 0x1450) != 0 || D_801462D5 != 1) {
                started = 1;
            } else {
                started = func_8022F55C_de(D_80102B00 + FIELD(s32, player, 0x5D4) * 400, 3);
                if (started == 0) {
                    func_8025DF34_de(0xD4D);
                    if (FIELD(void *, player, 0x5DC) != 0) {
                        func_8022A5A0_de(&D_80145040, player);
                        func_80239908_de(&D_80145088, FIELD(void *, player, 0x5DC), D_800D30BC, started, D_800C2FD0_de);
                    }
                }
            }
            if (started != 0 && FIELD(s32, player, 0x594) == 2) {
                func_80214178_de(actor, attack, 0xB);
                func_8022B984_de(player);
            } else {
                func_80214178_de(actor, attack, 2);
            }
        } else {
            func_80214178_de(actor, attack, 2);
        }
        result = 1;
    }
    FIELD(s32, player, 0x788) = result;
    FIELD(s32, player, 0x78C) = 0;
}
#else
INCLUDE_ASM("span_1000", func_802323A4_de);
#endif
