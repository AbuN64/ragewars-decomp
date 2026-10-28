#include "COMMON/VECTOR4F.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800E0D44.H"
#include "COMMON/LONE/D_800DCC68.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "TYPES.H"
#include "COMMON/MENU_TEXT.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "RENDER_2/8025DE50_5.H"

/* Runs a spinning weapon's barrel for its holder at 0x1D8: unless the weapon is in state 4 the spin
   speed at 0x128 decays, the spin angle at 0x124 advances by twice the speed per frame, and the
   holder's model animation speed at 0x168 follows the spin speed, capped at 1; while the fire input
   0x4000 is held and the holder is not stunned, a single player game (D_801462D5) without infinite
   ammunition at 0x1450 checks the ammunition through Player_GetProfileAchievementFlag and, when it is empty, clicks
   (sound 0xD4D) and shows the empty message on the holder's view; with ammunition and a loaded
   weapon at 0x5F6 it plays the wind-up sound 0x7BC unless already firing, sets the firing flags
   0x18400 and restarts the firing timer at 0x1230 at 25. Written with the fire check as the static
   helper shared with Weapon_TryEnterAlternateStateEight. */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
#elif defined(VERSION_EU) || defined(VERSION_EU_X)
#endif
extern char D_80102B00[];
extern s32 D_800D30BC;
extern char D_80145040[];
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "WEAPONS/8022F3E8_8.H"

extern s32 Player_GetProfileAchievementFlag(void *, s16);
extern s32 Player_GetPlayerIndex(void *, void *);
extern void Sky_PostTargetedScreenMessage(void *, void *, s32, s32, f32);

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
            Sky_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, RW_LOCALIZED_TEXT(D_800D30BC, D_800E0D44, D_800DCC68, g_languageIndex), Player_GetPlayerIndex(D_80145040, player),
                          1.0f);
        }
    }
    return ammo;
}
void Weaponai_DecaySpinAndActivateEffect(Shared_Actor *actor, WeaponFireState *weapon) {
    char *player;
    char *model;
    player = actor->entity;
    if (weapon->variant != 4) {
        weapon->spin = GraphU64_DecayToZero(weapon->spin, 0.013613569f);
    }
    weapon->spinStep += weapon->spin * D_800D2988 * 2.0f;
    model = ((SharedPlayer *)(player))->views5E8.view698_37.emitter;
    if (!(weapon->spin < 0.0f ? 1.0f < -weapon->spin * 1.7904929f
                                                   : 1.0f < weapon->spin * 1.7904929f)) {
        if (weapon->spin < 0.0f) {
            ((WeaponAnimationState *)(model))->speed = -weapon->spin * 1.7904929f;
        } else {
            ((WeaponAnimationState *)(model))->speed = weapon->spin * 1.7904929f;
        }
    } else {
        ((WeaponAnimationState *)(model))->speed = 1.0f;
    }
    if ((((SharedPlayer *)(player))->views5E8.view6AC_45.unk6AC & 0x4000) && can_fire(player) && ((SharedPlayer *)(player))->views5E8.chargeView.charge > 0) {
        if (!(((SharedPlayer *)(player))->views122C.view122C_2.options & 0x18400)) {
            SoundElement_PlayFlatSound(0x7BC);
        }
        ((SharedPlayer *)(player))->views122C.view122C_2.options |= 0x18400;
        ((SharedPlayer *)(player))->fxTime = 25.0f;
    }
}
