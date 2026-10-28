#include "COMMON/VECTOR4F.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800E0D44.H"
#include "COMMON/LONE/D_800DCC68.H"
#include "COMMON/LONE/D_800D30BC.H"
#include "COMMON/LONE/D_80152789.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "TYPES.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

/* Handles a player's charged secondary action: refreshes the idle state when the action is not allowed and
 * picks the effect position (the weapon's at 0x128, else the player's); a player flagged 0x4000 that may
 * fire with a type 1 request marks it type 2 and, once charged to 50, plays sound 0xB23 at that position and
 * takes action 5, otherwise reports the empty weapon and restores type 1; any other request func_802301F4_de
 * handles becomes type 1 with 0x124 cleared, else the state's default action starts unless the actor is
 * flagged 0x400. Adapted from Weapon_TryEnterAlternateStateEight with the same static fire check. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

extern WeaponActionRecord D_800CE8DC[];
extern char D_80102B00[];


extern char D_80145040[];
#include "COMMON/MENU_MATCH_GLOBALS.H"

extern s16 Weapon_FindNextUsableWeapon(void *);
extern s32 Player_GetProfileAchievementFlag(void *, s16);
extern s32 SoundElement_PlaySoundAtPosition(s32, s32, s32, s32, void *, void *);
extern s32 Player_GetPlayerIndex(void *, void *);
extern void Sky_PostTargetedScreenMessage(void *, void *, s32, s32, f32);
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
        SoundElement_PlayFlatSound(0xD4D);
        if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
            Sky_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, g_languageIndex), Player_GetPlayerIndex(D_80145040, player),
                          D_800C2FC4_de);
        }
    }
    return ammo;
}

void Weaponai_TryEnterChargedAlternateMode(Shared_Actor *actor, WeaponFireState *fireState) {
    char *player;
    s32 action;
    s32 *pos;
    s32 type;

    player = actor->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (Player_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = Weapon_FindNextUsableWeapon(player);
    }
    if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
        pos = (s32 *)(((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC + 0x128);
    } else {
        pos = (s32 *)&((SharedPlayer *)(player))->views0.view8_2.unk8;
    }
    if ((((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) && can_fire(player) && (type = fireState->mode) == 1) {
        fireState->mode = 2;
        if (((SharedPlayer *)(player))->views5E8.chargeView.charge >= 0x32) {
            SoundElement_PlaySoundAtPosition(0xB23, pos[0], pos[1], pos[2], pos, player);
            Nav_RequestActorState(actor, fireState, 5);
        } else {
            SoundElement_PlayFlatSound(0xD4D);
            if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                Sky_PostTargetedScreenMessage(D_80145040 + 0x48, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, (u8)D_80145040[0x1809]),
                              Player_GetPlayerIndex(D_80145040, player), D_800C2FC8_de);
            }
            fireState->mode = type;
        }
        return;
    }
    if (func_802301F4_de(actor, fireState) == 0) {
        if (!(actor->weaponFlags & 0x400)) {
            Nav_RequestActorState(actor, fireState, action);
        }
        return;
    }
    fireState->mode = 1;
    fireState->spinStep = 0.0f;
}
