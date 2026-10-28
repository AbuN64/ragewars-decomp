#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/NAME.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/AIPROFILE.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "RENDER/8022AE90_2.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER/8025DE50_5.H"

/* Runs a player's aiming action: refreshes the idle state when the action is not allowed; while the aim
 * flag 0x4000 is held and the weapon may fire (as in Weaponai_TryEnterAlternateStateEight) the attack enters aiming and, for scoped
 * weapons, zooms in through func_8022B1A8; when aiming stops it zooms back out unless the zoom was already
 * cancelled; then the default action for the player's state starts unless func_802301F4_de handled the
 * request or the actor is flagged 0x400. Adapted from Weaponai_TryEnterAlternateStateEight with the aiming state.
 */

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 *D_800E0D44[];
extern u8 *D_800DCC68[];

#else
#endif
extern WeaponActionRecord D_800CE8DC[];
extern MatchRewardsRecord D_80102B00[];

extern u8 *D_800D30BC[];


extern s32 Weaponai_FindNextUsableWeapon(void *);
extern s32 Player_GetProfileAchievementFlag(void *, s32);
extern s32 Player_GetPlayerIndex(void *, void *);
extern CCameraText *Gsky_PostTargetedScreenMessage(void *, void *, u8 *, s32, f32);
extern s32 func_802301F4_de(void *, void *);

#if defined(VERSION_EU_X)
extern void func_80228E60_eu(void *, s32);

#else
#endif
static inline s32 can_fire(char *player, f32 *scale) {
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
            Gsky_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, ((D_800E0D44)[g_languageIndex]), Player_GetPlayerIndex(&D_80145040, player),
#elif defined(VERSION_EU_X)
            Gsky_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, ((D_800DCC68)[g_languageIndex]), Player_GetPlayerIndex(&D_80145040, player),
#else
            Gsky_PostTargetedScreenMessage(&D_80145088, ((SharedPlayer *)(player))->views5DC.view5DC_0.unk5DC, D_800D30BC[0], Player_GetPlayerIndex(&D_80145040, player),
#endif
                          *scale);
        }
    }
    return ammo;
}

void Weaponai_UpdateForceMarkerTrigger(Shared_Actor *actor, WeaponFireState *attack) {
    char *player;
    s32 action;

    player = (char *)actor->entity;
    action = D_800CE8DC[((SharedPlayer *)(player))->views5E8.view650_15.unk650].action;
    if (Player_HasAmmoForMode(player, ((SharedPlayer *)(player))->views5E8.view62E_13.unk62E) == 0) {
        ((SharedPlayer *)(player))->views5E8.view770_91.unk770 = Weaponai_FindNextUsableWeapon(player);
    }
    if ((((SharedPlayer *)(player))->views5E8.view6AC_45.unk6AC & 0x4000) && can_fire(player, &D_800C2FCC_de)) {
        attack->triggered = 1;
        if (((SharedPlayer *)(player))->views5E8.view6B0_46.unk6B0 & 0x2000) {

#if defined(VERSION_EU_X)
            func_80228E60_eu(player, 0);
#else
            Playerai_ToggleForceMarker(player, 0);
#endif

            attack->alternate = 1;
        }
    } else if (attack->triggered != 0) {
        if (attack->alternate == 0) {

#if defined(VERSION_EU_X)
            func_80228E60_eu(player, 1);
#else
            Playerai_ToggleForceMarker(player, 1);
#endif

        } else {
            attack->alternate = 0;
        }
        attack->triggered = 0;
    }
    if (func_802301F4_de(actor, attack) == 0 && !(actor->weaponFlags & 0x400)) {
        Actor_RequestActorState(actor, attack, action);
    }
}
/* D_800C2FCC_de and D_800C2FD0_de are the two message-duration floats of this unit's literal pool. */
typedef struct HeldPlayerState {
    u8 pad0[8];
    CVector3 position;
    u8 pad14[0x594 - 0x14];
    s32 mode594;
    u8 pad598[0x5F4 - 0x598];
    s16 window5F4;
    s16 window5F6;
    s16 charge5F8;
    u8 pad5FA[0x62E - 0x5FA];
    s16 mode;
    u8 pad630[0x6AC - 0x630];
    s32 buttons;
    u8 pad6B0[0x788 - 0x6B0];
    s32 handled788;
    s32 handled78C;
} HeldPlayerState;

void Weaponai_UpdateHeldFire(Shared_Actor *actor, WeaponFireState *attack) {
    HeldPlayerState *state;
    s32 finished;
    state = actor->entity;
    if (attack->triggerMode != 0) {
        if (state->mode == 4 || state->mode == 14 || state->mode == 15) {
            goto no;
        }
        if (state->mode == 10) {
            if (!(state->buttons & 0x4000)) goto no;
            if (state->charge5F8 == 0) goto no;
            goto yes;
        } else if (state->mode == 3) {
            if ((state->buttons & 0x6000) != 0x6000) goto no;
            if (state->window5F4 == 0) goto no;
            if (state->window5F6 != 0) goto yes;
        no:
            finished = 0;
            goto done;
        yes:
            finished = 1;
        done:;
        } else {
            finished = func_802301F4_de(actor, attack);
        }
        if (finished != 0) {
            attack->triggerMode = 0;
            attack->queuedAction = -1;
        } else {
            if (state->mode == 5) {
                func_8022B00C_de(state);
                SoundElement_PlaySoundAtPosition(0x460, state->position, &state->position, -1);
            }
            if (state->mode == 3 && can_fire((char *)state, &D_800C2FD0_de) != 0 && state->mode594 == 2) {
                Actor_RequestActorState(actor, attack, 0xB);
                func_8022B984_de(state);
            } else {
                Actor_RequestActorState(actor, attack, 2);
            }
        }
        state->handled788 = 1;
        state->handled78C = 0;
    }
}
