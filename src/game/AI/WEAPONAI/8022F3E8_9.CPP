#include "COMMON/VECTOR4F.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800E0D44.H"
#include "COMMON/LONE/D_800DCC68.H"
#include "COMMON/LONE/D_800D30BC.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "TYPES.H"
#include "COMMON/MENU_TEXT.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

/* Runs a weapon's two-shot alternate fire for its holder at 0x1D8: when the holder cannot use the
   alternate mode of its weapon (Player_HasAmmoForMode) a pending switch at 0x13C is cancelled and, if still
   unusable, the holder picks its next weapon at 0x770 through Weapon_FindNextUsableWeapon; otherwise, while the
   alternate input 0x4000 is held and the weapon can fire (not stunned, and with ammunition in a single
   player game, clicking and showing the empty message when out), mode 1 with a second shot available
   arms mode 2, clicking and showing the unavailable message and falling back to mode 1 when mode 2
   cannot be used, and any other state resets to mode 1; finally, unless func_802301F4_de handled the
   weapon or the actor has flag 0x400, it fires through func_80214178_de with the holder's state's fire
   mode from D_800CE8DC. */
extern WeaponActionRecord D_800CE8DC[];
extern char D_80102B00[];
extern char D_80145040[];
#include "COMMON/MENU_MATCH_GLOBALS.H"

extern s16 Weapon_FindNextUsableWeapon(void *);
extern s32 Player_GetProfileAchievementFlag(void *, s16);
extern s32 Player_GetPlayerIndex(void *, void *);
extern void Sky_PostTargetedScreenMessage(void *, void *, s32, s32, f32);
extern s32 func_802301F4_de(void *, void *);
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU)
#elif defined(VERSION_EU_X)
#endif
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
                          1.0f);
        }
    }
    return ammo;
}
void Weapon_ToggleFiringModeWithAmmoCheck(Shared_Actor *actor, WeaponFireState *fireState) {
    char *player;
    s32 action;
    player = actor->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (Player_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        if (fireState->mode != 2) {
            ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = Weapon_FindNextUsableWeapon(player);
            return;
        }
        fireState->mode = 1;
        if (Player_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
            ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = Weapon_FindNextUsableWeapon(player);
            return;
        }
    }
    if ((((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) && can_fire(player)) {
        if (fireState->mode == 1 && can_fire(player)) {
            fireState->mode = 2;
            if (Player_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
                SoundElement_PlayFlatSound(0xD4D);
                if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
                    Sky_PostTargetedScreenMessage((D_80145040 + 0x48), ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, (u8)D_80145040[0x1809]),
                                  Player_GetPlayerIndex(D_80145040, player), 1.0f);
                }
                fireState->mode = 1;
            }
        } else {
            fireState->mode = 1;
        }
    }
    if (func_802301F4_de(actor, fireState) == 0 && !(actor->weaponFlags & 0x400)) {
        Nav_RequestActorState(actor, fireState, action);
    }
}
