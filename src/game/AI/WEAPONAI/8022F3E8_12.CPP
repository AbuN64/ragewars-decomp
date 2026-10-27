#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800E0D44.H"
#include "COMMON/LONE/D_800DCC68.H"
#include "COMMON/NAME.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/EXTERNS_13.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

/* Starts a player's action: when the current action is not allowed the idle state is refreshed; a player
 * flagged 0x4000 with no cooldown, no lock and the ammo option enabled checks its weapon's ammo, playing sound
 * 0xD4D and reporting the empty weapon when it is out, and takes action 8 when it may fire; otherwise the
 * default action for the player's state is started unless func_802301F4_de handled the request or the actor is
 * flagged 0x400. */

#if defined(VERSION_EU) || defined(VERSION_EU_X)

#else
#endif
extern WeaponActionRecord D_800CE8DC[];
extern MatchRewardsRecord D_80102B00[];

extern s32 D_800D30BC;


extern s16 Weapon_FindNextUsableWeapon(void *);
extern s32 Player_GetProfileAchievementFlag(void *, s16);
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
    ammo = Player_GetProfileAchievementFlag(&D_80102B00[((SharedPlayer *)(player))->views1C.view5D4_45.unk5D4], ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E);
    if (ammo == 0) {
        SoundElement_PlayFlatSound(0xD4D);
        if (((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC != 0) {
#if defined(VERSION_EU)
            Sky_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, ((D_800E0D44)[g_languageIndex]), Player_GetPlayerIndex(&D_80145040, player),
#elif defined(VERSION_EU_X)
            Sky_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, ((D_800DCC68)[g_languageIndex]), Player_GetPlayerIndex(&D_80145040, player),
#else
            Sky_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, (D_800D30BC), Player_GetPlayerIndex(&D_80145040, player),
#endif
                          D_800C2FB8_de);
        }
    }
    return ammo;
}

void Weapon_TryEnterAlternateStateEight(Shared_Actor *actor, void *attack) {
    char *player;
    s32 action;

    player = actor->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (Player_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = Weapon_FindNextUsableWeapon(player);
        return;
    }
    if ((((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x4000) && can_fire(player)) {
        Nav_RequestActorState(actor, attack, 8);
        return;
    }
    if (func_802301F4_de(actor, attack) == 0 && !(actor->weaponFlags & 0x400)) {
        Nav_RequestActorState(actor, attack, action);
    }
}
