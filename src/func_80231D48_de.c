#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022F3E8.h"
#include "types.h"
/* Continues a player's secondary action: refreshes the idle state when the current action is not allowed;
 * a player flagged 0x4000 that may fire with a type 1 request takes action 5 and marks the request type 2,
 * unless it is in state 4 with a charge under 48, which reports the empty weapon; otherwise a request
 * func_802301F4_de handles is marked type 1 and the default action for the player's state is started unless
 * the actor is flagged 0x400. Adapted from func_80231BB0_de with the same static fire check. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern s32 D_800E0D44[], D_800DCC68[];
#endif

extern WeaponActionRecord D_800CE8DC[];
extern char D_80102B00[];
extern u8 D_801462D5;
extern s32 D_800D30BC[];


extern char D_80145040[];
extern char D_80145088;

extern s16 func_8022F96C_de(void *);
extern s32 func_8022F55C_de(void *, s16);
extern s32 func_8025DF34_de(s32);
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
                          D_800C2FBC_de);
        }
    }
    return ammo;
}

void func_80231D48_de(void *actor, void *arg1) {
    char *player;
    s32 action;

    player = ((Shared_Actor *)(actor))->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (func_80222AA4_de(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
    }
    if ((((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) && can_fire(player) && ((WeaponFireState *)(arg1))->mode == 1) {
        if (((SharedPlayer *)(player))->views5E8.view5F4_11.unk5F4[0] >= 0x30 || ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E != 4) {
            func_80214178_de(actor, arg1, 5);
            ((WeaponFireState *)(arg1))->mode = 2;
            return;
        } else {
            func_8025DF34_de(0xD4D);
            if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                func_80239908_de(D_80145040 + 0x48, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, (u8)D_80145040[0x1809]),
                              func_8022A5A0_de(D_80145040, player), D_800C2FC0_de);
            }
        }
        return;
    }
    if (func_802301F4_de(actor, arg1) == 0) {
        if (!(((Shared_Actor *)(actor))->weaponFlags & 0x400)) {
            func_80214178_de(actor, arg1, action);
        }
        return;
    }
    ((WeaponFireState *)(arg1))->mode = 1;
}
