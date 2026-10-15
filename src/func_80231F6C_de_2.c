#include "span_16E000/code_8042F988.h"
#include "span_C76B0/data.h"
#include "types.h"
#include "common/unused.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80231F5C.h"

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
extern s32 func_8022F55C_de(s32, s32);
extern s32 func_8022A5A0_de(void *, unsigned int);
extern Message *func_80239908_de(void *, void *, u8 *, s32, f32);
extern s32 func_802301F4_de(void *, void *);
extern void func_80214178_de(void *, void *, s32);

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
    ammo = func_8022F55C_de((s32)&D_80102B00[((SharedPlayer *)(player))->views1C.view5D4_45.unk5D4], ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E);
    if (ammo == 0) {
        func_8025DF34_de(0xD4D);
        if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
#if defined(VERSION_EU)
            func_80239908_de(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, ((D_800E0D44)[D_80152789]), func_8022A5A0_de(&D_80145040, (u32)player),
#elif defined(VERSION_EU_X)
            func_80239908_de(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, ((D_800DCC68)[D_80152789]), func_8022A5A0_de(&D_80145040, (u32)player),
#else
            func_80239908_de(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, (D_800D30BC), func_8022A5A0_de(&D_80145040, (u32)player),
#endif
                          D_800C2FCC_de);
        }
    }
    return ammo;
}

void func_802321C8_de(void *actor, void *attack) {
    char *player;
    s32 action;

    player = (char *)((Shared_Actor *)(actor))->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (func_80222AA4_de(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
    }
    if ((((SharedPlayer *)(player))->views5E8.view6AC_45.unk6AC & 0x4000) && can_fire(player)) {
        ((WeaponFireState *)(attack))->triggered = 1;
        if (((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x2000) {

#if defined(VERSION_EU_X)
            func_80228E60_eu(player, 0);
#else
            func_8022B1A8(player, 0);
#endif

            ((WeaponFireState *)(attack))->alternate = 1;
        }
    } else if (((WeaponFireState *)(attack))->triggered != 0) {
        if (((WeaponFireState *)(attack))->alternate == 0) {

#if defined(VERSION_EU_X)
            func_80228E60_eu(player, 1);
#else
            func_8022B1A8(player, 1);
#endif

        } else {
            ((WeaponFireState *)(attack))->alternate = 0;
        }
        ((WeaponFireState *)(attack))->triggered = 0;
    }
    if (func_802301F4_de(actor, attack) == 0 && !(((Shared_Actor *)(actor))->weaponFlags & 0x400)) {
        func_80214178_de(actor, attack, action);
    }
}


/* D_800C2FCC_de is resident shared data supplied by its retained ROM slice.
 * The ammo and player-index providers receive numeric addresses; their current
 * source contracts use s32 and unsigned int respectively. */
