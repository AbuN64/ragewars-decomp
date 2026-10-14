#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022F3E8.h"
#include "types.h"
/* Starts a player's secondary action: sets the request type to 1, refreshes the idle state when the current
 * action is not allowed, and when the player is flagged 0x4000, may fire and holds a charge either releases
 * a charged shot (sound 0x42E at the player, action 0xB) once charged past 24 or reports the empty weapon;
 * otherwise the default action for the player's state is started unless func_802301F4_de handled the request
 * or the actor is flagged 0x400. Adapted from func_80231BB0_de with the same static fire check. */
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
extern s32 func_8025DE54_de(s32, s32, s32, s32, void *, s32);
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
                          D_800C2FB0_de);
        }
    }
    return ammo;
}

void func_8023196C_de(void *actor, void *arg1) {
    char *player;
    s32 action;

    player = ((Shared_Actor *)(actor))->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    ((WeaponFireState *)(arg1))->mode = 1;
    if (func_80222AA4_de(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
        return;
    }
    if ((((SharedPlayer *)(player))->views5E8.view6AC_45.unk6AC & 0x4000) && can_fire(player) && ((SharedPlayer *)(player))->views5E4.view5E4_0.unk5E4 != 0) {
        if (((SharedPlayer *)(player))->views5E8.view5F4_11.unk5F4[0] >= 0x19) {
            func_8025DE54_de(0x42E, ((SharedPlayer *)(player))->views0.positionBits.positionWords[0], ((SharedPlayer *)(player))->views0.positionBits.positionWords[1], ((SharedPlayer *)(player))->views0.positionBits.positionWords[2], player + 0x8,
                          -1);
            func_80214178_de(actor, arg1, 0xB);
        } else if (((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) {
            func_8025DF34_de(0xD4D);
            if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                func_80239908_de(D_80145040 + 0x48, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, (u8)D_80145040[0x1809]),
                              func_8022A5A0_de(D_80145040, player), D_800C2FB4_de);
            }
        }
        return;
    }
    if (func_802301F4_de(actor, arg1) == 0 && !(((Shared_Actor *)(actor))->weaponFlags & 0x400)) {
        func_80214178_de(actor, arg1, action);
    }
}
