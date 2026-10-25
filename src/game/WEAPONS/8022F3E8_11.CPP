#include "COMMON/VECTOR4F.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800E0D44.H"
#include "COMMON/LONE/D_800DCC68.H"
#include "COMMON/LONE/D_800D30BC.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "TYPES.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

/* Starts a player's secondary action: sets the request type to 1, refreshes the idle state when the current
 * action is not allowed, and when the player is flagged 0x4000, may fire and holds a charge either releases
 * a charged shot (sound 0x42E at the player, action 0xB) once charged past 24 or reports the empty weapon;
 * otherwise the default action for the player's state is started unless func_802301F4_de handled the request
 * or the actor is flagged 0x400. Adapted from func_80231BB0_de with the same static fire check. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

extern WeaponActionRecord D_800CE8DC[];
extern char D_80102B00[];


extern char D_80145040[];
#include "COMMON/MENU_MATCH_GLOBALS.H"

extern s16 func_8022F96C_de(void *);
extern s32 func_8022F55C_de(void *, s16);
extern s32 Render_PlaySoundAtPosition(s32, s32, s32, s32, void *, s32);
extern s32 Weapons_GetPlayerIndex(void *, void *);
extern void Camera_PostTargetedScreenMessage(void *, void *, s32, s32, f32);
extern s32 func_802301F4_de(void *, void *);

static inline s32 can_fire(char *player) {
    s32 ammo;

    if (((SharedPlayer *)(player))->views5E8.view11D8_147.unk11D8 > 0.0f) {
        return 0;
    }
    if (((SharedPlayer *)(player))->views1450.view1450_0.unk1450 != 0) {
        return 1;
    }
    if (D_801462C8.controllerMode != 1) {
        return 1;
    }
    ammo = func_8022F55C_de(&D_80102B00[((SharedPlayer *)(player))->views1C.view5D4_45.unk5D4 * 0x190], ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E);
    if (ammo == 0) {
        func_8025DF34_de(0xD4D);
        if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
            Camera_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, D_80152789), Weapons_GetPlayerIndex(D_80145040, player),
                          D_800C2FB0_de);
        }
    }
    return ammo;
}

void func_8023196C_de(Shared_Actor *actor, WeaponFireState *fireState) {
    char *player;
    s32 action;

    player = actor->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    fireState->mode = 1;
    if (Weapons_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
        return;
    }
    if ((((SharedPlayer *)(player))->views5E8.view6AC_45.unk6AC & 0x4000) && can_fire(player) && ((SharedPlayer *)(player))->views5E4.view5E4_0.unk5E4 != 0) {
        if (((SharedPlayer *)(player))->views5E8.view5F4_11.unk5F4[0] >= 0x19) {
            Render_PlaySoundAtPosition(0x42E, ((SharedPlayer *)(player))->views0.positionBits.positionWords[0], ((SharedPlayer *)(player))->views0.positionBits.positionWords[1], ((SharedPlayer *)(player))->views0.positionBits.positionWords[2], player + 0x8,
                          -1);
            Weapons_RequestActorState(actor, fireState, 0xB);
        } else if (((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) {
            func_8025DF34_de(0xD4D);
            if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                Camera_PostTargetedScreenMessage(D_80145040 + 0x48, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, (u8)D_80145040[0x1809]),
                              Weapons_GetPlayerIndex(D_80145040, player), D_800C2FB4_de);
            }
        }
        return;
    }
    if (func_802301F4_de(actor, fireState) == 0 && !(actor->weaponFlags & 0x400)) {
        Weapons_RequestActorState(actor, fireState, action);
    }
}
