#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800E0D44.H"
#include "COMMON/LONE/D_800DCC68.H"
#include "COMMON/LONE/D_800D30BC.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"
#include "COMMON/PLAYERPROFILES.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("span_1000", func_802301F4_de);
#endif
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
/* Handles a player's attack trigger: nothing while cooling down past D_800C2EE0_de; the trigger is the
 * controller latch at 0x23C (cleared when read) for a flagged controlled player, else flag 0x2000; when it
 * fires and func_80230058_de accepts the attack, a ranged attack (type 2) that may fire takes action 8 and
 * returns 2, otherwise action 4 starts with the combo byte cleared and returns 1. Adapted from
 * Weapon_TryEnterAlternateStateEight with the fire check as the same static helper. */
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/EXTERNS_13.H"
#include "COMMON/OBJECTLINKS14C.H"
/* func_802301E4_S* are unresolved canonical player/actor/control/attack types. */







extern s32 Player_GetProfileAchievementFlag(void *, s16);
extern void Sky_PostTargetedScreenMessage(void *, void *, s32, s32, f32);










typedef struct AttackTriggerPlayer AttackTriggerPlayer;
typedef struct AttackTriggerActor AttackTriggerActor;
typedef struct AttackTriggerControl AttackTriggerControl;
typedef struct AttackTriggerAction AttackTriggerAction;
struct AttackTriggerPlayer {
    char pad0[0x5D4];
    s32 unk5D4;
    char pad5D4[0x5DC - 0x5D4 - sizeof(s32)];
    void* unk5DC;
    char pad5DC[0x62E - 0x5DC - sizeof(void*)];
    s16 unk62E;
    char pad62E[0x6AC - 0x62E - sizeof(s16)];
    s32 unk6AC;
    char pad6AC[0x11D8 - 0x6AC - sizeof(s32)];
    f32 unk11D8;
    char pad11D8[0x1450 - 0x11D8 - sizeof(f32)];
    s32 unk1450;
    char pad1450[0x1454 - 0x1450 - sizeof(s32)];
    char* unk1454;
};
struct AttackTriggerActor {
    char pad0[0x100];
    s32 unk100;
    char pad100[0x1D8 - 0x100 - sizeof(s32)];
    char* unk1D8;
};
struct AttackTriggerControl {
    char pad0[0x23C];
    s32 unk23C;
};
struct AttackTriggerAction {
    char pad0[0xCB];
    u8 unkCB;
    char padCB[0x13C - 0xCB - sizeof(u8)];
    s32 unk13C;
};


static inline s32 can_fire(char *player) {
    s32 ammo;

    if (((AttackTriggerPlayer *)(player))->unk11D8 > 0.0f) {
        return 0;
    }
    if (((AttackTriggerPlayer *)(player))->unk1450 != 0) {
        return 1;
    }
    if (D_801462C8.controllerMode != 1) {
        return 1;
    }
    ammo = Player_GetProfileAchievementFlag(&D_80102B00[((AttackTriggerPlayer *)(player))->unk5D4], ((AttackTriggerPlayer *)(player))->unk62E);
    if (ammo == 0) {
        SoundElement_PlayFlatSound(0xD4D);
        if (((AttackTriggerPlayer *)(player))->unk5DC != 0) {
            Sky_PostTargetedScreenMessage(&D_80145088, ((AttackTriggerPlayer *)(player))->unk5DC, D_800D30BC[0], Weapons_GetPlayerIndex(&D_80145040, player),
                          D_800C2EE4_de);
        }
    }
    return ammo;
}

s32 func_802301F4_de(void *actor, void *attack) {
    char *player;
    s32 trigger;
    char *control;

    player = ((AttackTriggerActor *)(actor))->unk1D8;
    if (((AttackTriggerPlayer *)(player))->unk11D8 > D_800C2EE0_de) {
        return 0;
    }
    if ((((AttackTriggerActor *)(actor))->unk100 & 0x300000) && ((AttackTriggerPlayer *)(player))->unk1450 != 0) {
        control = ((AttackTriggerPlayer *)(player))->unk1454;
        trigger = ((AttackTriggerControl *)(control))->unk23C;
        ((AttackTriggerControl *)(control))->unk23C = 0;
    } else {
        trigger = ((AttackTriggerPlayer *)(player))->unk6AC & 0x2000;
    }
    if (trigger != 0 && func_80230058_de(actor, attack) != 0) {
        if (((AttackTriggerAction *)(attack))->unk13C == 2 && can_fire(player)) {
            Weapons_RequestActorState(actor, attack, 8);
            return 2;
        }
        Weapons_RequestActorState(actor, attack, 4);
        ((AttackTriggerAction *)(attack))->unkCB = 0;
        return 1;
    }
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
extern s16 D_800CE8DC[];
extern void *D_800D052C[];
/* Updates alternate fire, falling back to another weapon when neither mode has
 * ammunition. Reports unavailable modes, preserves the selected action captured
 * on entry, then processes the attack trigger. */
#include "COMMON/AIPROFILE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
typedef struct AlternateModeInfo { u8 pad0[0x14]; u32 flags; } AlternateModeInfo;
#if defined(VERSION_EU)
#elif defined(VERSION_EU_X)
#endif
/* The adjacent exact can_fire supplies the same readiness check; this call site
 * owns its distinct message-duration literal and localized European strings. */
static inline s32 can_toggle_mode(Player *player) {
    s32 allowed;
    if (player->cooldown > 0.0f) return 0;
    if (player->computer != 0) return 1;
    if (D_801462C8.controllerMode != 1) return 1;
    allowed = Player_GetProfileAchievementFlag(&D_80102B00[player->slot], player->selectedAction);
    if (allowed == 0) {
        SoundElement_PlayFlatSound(0xD4D);
        if (player->camera) {
            Sky_PostTargetedScreenMessage(&D_80145088, player->camera, RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, g_languageIndex),
                                             Weapons_GetPlayerIndex(&D_80145040, player), 1.0f);
        }
    }
    return allowed;
}
void Weapons_UpdateAlternateFire(void *actor, void *attack) {
    Player *player = (Player *)((AttackTriggerActor *)actor)->unk1D8;
    s32 action = D_800CE8DC[player->pose * 12];
    AlternateModeInfo *info = (AlternateModeInfo *)D_800D052C[player->selectedAction];
    if (!Weapons_HasAmmoForMode(player, player->selectedAction)) {
        if (((AttackTriggerAction *)attack)->unk13C != 2) {
            player->weapon = Weapon_FindNextUsableWeapon(player);
            return;
        }
        ((AttackTriggerAction *)attack)->unk13C = 1;
        if (info->flags & 0x20) player->state7E8 = 0;
        if (!Weapons_HasAmmoForMode(player, player->selectedAction)) {
            player->weapon = Weapon_FindNextUsableWeapon(player);
            return;
        }
    }
    if ((player->actionFlags & 0x4000) && player->selectedAction < 18 && can_toggle_mode(player)) {
        if (((AttackTriggerAction *)attack)->unk13C == 1) {
            ((AttackTriggerAction *)attack)->unk13C = 2;
            if (!Weapons_HasAmmoForMode(player, player->selectedAction)) {
                SoundElement_PlayFlatSound(0xD4D);
                if (player->camera) {
                    Sky_PostTargetedScreenMessage((char *)&D_80145040 + 0x48, player->camera,
                                                     RW_LOCALIZED_TEXT(D_800D30BC[0], D_800E0D44, D_800DCC68, D_80145040.game.language),
                                                     Weapons_GetPlayerIndex(&D_80145040, player), 1.0f);
                }
                ((AttackTriggerAction *)attack)->unk13C = 1;
            } else if (info->flags & 0x20) {
                player->state7E8 = 1;
            }
        } else {
            ((AttackTriggerAction *)attack)->unk13C = 1;
            if (info->flags & 0x20) player->state7E8 = 0;
        }
    }
    if (func_802301F4_de(actor, attack) == 0 && !(((AttackTriggerActor *)actor)->unk100 & 0x400)) {
        Weapons_RequestActorState(actor, attack, action);
    }
}
#else
INCLUDE_ASM("span_1000", Weapons_UpdateAlternateFire);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#define Weapon_UpdateIdleWeaponSelection func_80230610_eu
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"


extern s16 Weapon_FindNextUsableWeapon(void *arg0);
extern s32 SoundElement_PlaySoundAtPosition(s16 arg0, CVector3 position, s32 arg4, s32 arg5);












void Weapon_UpdateIdleWeaponSelection(LevelActor *arg0, void *arg1) {
    s32 state;
    void *actor;
    CGameStatus *audio;
    s32 mode;

    actor = arg0->controller;
    state = *(s16 *)((char *)D_800CE8DC +
                     (((Shared_ActorView *)actor)->action * 0x18));
    if ((s8)((Dest *)arg1)->count != 0) {
        if (Weapons_HasAmmoForMode(actor, ((Shared_ActorView *)actor)->selectedAction) == 0) {
            if (((Dest *)arg1)->field13C == 2) {
                ((Dest *)arg1)->field13C = 1;
                if (Weapons_HasAmmoForMode(actor, ((Shared_ActorView *)actor)->selectedAction) == 0) {
                    ((Shared_ActorView *)actor)->nextWeapon = Weapon_FindNextUsableWeapon(actor);
                }
            }
        }
    }
    func_8022B9C4_de(actor);
    ((Shared_ActorView *)actor)->marker.word = 0;
    ((WeaponAnimationState *)((Shared_ActorView *)actor)->controller)->speed = 0;
    ((Dest *)arg1)->field138 = 0;

    audio = &D_801462C8.counters;
    if ((audio->m_bFragTagOn != 0) &&
        (((Shared_ActorView *)actor)->controls->transientFlag != 0)) {
        if (((Shared_ActorView *)actor)->unk_0x06B0 & 0x2000) {
            mode = audio->m_nFragTagSkin;
            switch (mode) {
            case 0:
                SoundElement_PlaySoundAtPosition(0x18A1,
                              ((Shared_ActorView *)actor)->position.vector,
                              (s32)&((Player *)actor)->pos, -1);
                break;
            case 1:
                SoundElement_PlaySoundAtPosition(0x1969,
                              ((Shared_ActorView *)actor)->position.vector,
                              (s32)&((Player *)actor)->pos, -1);
                break;
            case 2:
                SoundElement_PlaySoundAtPosition(0x1905,
                              ((Shared_ActorView *)actor)->position.vector,
                              (s32)&((Player *)actor)->pos, -1);
                break;
            }
        }
    } else if ((state != 1) && (state != 7) &&
               ((s8)((Dest *)arg1)->count != 0)) {
        Weapon_InitializeSwitchAndRequestIdle(arg0, arg1);
    }
}
#else
INCLUDE_ASM("span_1000", func_80230610_eu);
#endif
#endif
