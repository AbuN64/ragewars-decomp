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

/* Continues a player's secondary action: refreshes the idle state when the current action is not allowed;
 * a player flagged 0x4000 that may fire with a type 1 request takes action 5 and marks the request type 2,
 * unless it is in state 4 with a charge under 48, which reports the empty weapon; otherwise a request
 * func_802301F4_de handles is marked type 1 and the default action for the player's state is started unless
 * the actor is flagged 0x400. Adapted from func_80231BB0_de with the same static fire check. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

extern WeaponActionRecord D_800CE8DC[];
extern char D_80102B00[];


extern char D_80145040[];
#include "COMMON/MENU_MATCH_GLOBALS.H"

extern s16 func_8022F96C_de(void *);
extern s32 Player_GetProfileAchievementFlag(void *, s16);
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
    ammo = Player_GetProfileAchievementFlag(&D_80102B00[((SharedPlayer *)(player))->views1C.view5D4_45.unk5D4 * 0x190], ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E);
    if (ammo == 0) {
        Render_PlayFlatSound(0xD4D);
        if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
            Camera_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, g_languageIndex), Weapons_GetPlayerIndex(D_80145040, player),
                          D_800C2FBC_de);
        }
    }
    return ammo;
}

void func_80231D48_de(Shared_Actor *actor, WeaponFireState *fireState) {
    char *player;
    s32 action;

    player = actor->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (Weapons_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = func_8022F96C_de(player);
    }
    if ((((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) && can_fire(player) && fireState->mode == 1) {
        if (((SharedPlayer *)(player))->views5E8.view5F4_11.unk5F4[0] >= 0x30 || ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E != 4) {
            Weapons_RequestActorState(actor, fireState, 5);
            fireState->mode = 2;
            return;
        } else {
            Render_PlayFlatSound(0xD4D);
            if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                Camera_PostTargetedScreenMessage(D_80145040 + 0x48, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, (u8)D_80145040[0x1809]),
                              Weapons_GetPlayerIndex(D_80145040, player), D_800C2FC0_de);
            }
        }
        return;
    }
    if (func_802301F4_de(actor, fireState) == 0) {
        if (!(actor->weaponFlags & 0x400)) {
            Weapons_RequestActorState(actor, fireState, action);
        }
        return;
    }
    fireState->mode = 1;
}
