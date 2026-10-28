#include "include_asm.h"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"
#include "COMMON/PLAYERPROFILES.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "COMMON/MODEL_RENDER.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/SELF.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "RENDER_2/8022AE90_2.H"
#include "WEAPONS/80231F5C_10.H"
#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "WEAPONS/MEASUREDRECAT1D8V2.H"
#include "COMMON/EXTERNS_6.H"
#include "WEAPONS/80231F5C_11.H"
#include "COMMON/OBJB.H"
#include "WEAPONS/MEASUREDRECAT1D8V3.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/OBJ.H"
#include "COMMON/STATERECAT10.H"
#include "COMMON/ACTORRESOURCEHEADER.H"
#include "COMMON/MTX.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "GAME/CODE_8027302C.H"
#include "WEAPONS/80231F5C_12.H"

extern void Player_ReleaseObjectHandles(void *);
extern struct Shape_func_8020AF9C_de_2 D_80140FF8;

/* 80231F5C_5.CPP */
void Weapon_SpawnTargetPlayerFireEffect(void *aiTarget, s32 unused1, s32 arg2) {
    AiTarget *target = aiTarget;
    func_8021A9A4_de(target->player, arg2);
}

/** Return the value pointed to by the indexed pointer table entry. */
int Weapon_GetIndexedTableValue(int arg0) {
    return *D_800CB358_de[arg0];
}

s32 Weapon_IsPrimarySwitchGroup(s32 arg0) {
    if (arg0 < 7) {
        if (arg0 >= 3) {
            return 1;
        }
    }
    return 0;
}

/** Return whether the encoded type belongs to this caller's accepted set. */
s32 Weapon_IsSecondarySwitchGroup(s32 arg0) {
    {
        arg0 -= 2;
        if ((unsigned int)arg0 >= 14) {
            goto case_default;
        }
        switch (arg0) {
        case 0: goto case_2;
        case 1: goto case_default;
        case 2: goto case_default;
        case 3: goto case_default;
        case 4: goto case_default;
        case 5: goto case_2;
        case 6: goto case_2;
        case 7: goto case_2;
        case 8: goto case_default;
        case 9: goto case_default;
        case 10: goto case_default;
        case 11: goto case_2;
        case 12: goto case_2;
        case 13: goto case_2;
        }
    }
case_2:
case_7:
case_8:
case_9:
case_13:
case_14:
case_15:
    return 1;
case_default:
    return 0;
}

s32 Weapon_IsSpecialSwitchGroup(s32 arg0) {
    if (arg0 < 0xD) {
        if (arg0 >= 0xA) {
            return 1;
        }
    }
    return 0;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_WORLDFUNC.H"
extern char *D_800E0D44[];
extern char *D_800DCC68[];
extern s32 Player_GetProfileAchievementFlag(Profile *, s32);
extern s32 Player_GetPlayerIndex(Shared_MenuData *, PlayerRecAt1450V1 *);
extern void Sky_PostTargetedScreenMessage(Shared_MenuObject *, void *, char *, s32, f32);

s32 Weapon_CheckProfileFirePermission(PlayerRecAt1450V1 *pThis) {
    s32 result;
    Shared_Game *settings;
    if (pThis->shield > 0.0f) {
        return 0;
    }
    if (pThis->isBot != 0) {
        return 1;
    }
    settings = &D_80145040.game;
    if (settings->controllerMode != 1) {
        return 1;
    }
    result = Player_GetProfileAchievementFlag(&D_80102B00[pThis->character], pThis->weapon);
    if (result == 0) {
        SoundElement_PlayFlatSound(0xD4D);
        if (pThis->hud != 0) {
            s32 player = Player_GetPlayerIndex(&D_80145040, pThis);
            Sky_PostTargetedScreenMessage(&D_80145040.object, pThis->hud,

#if defined(VERSION_EU_X)
                            D_800DCC68[settings->language],
#else
                            D_800E0D44[settings->language],
#endif
                            player, D_800C8100);
        }
    }
    return result;
}
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)

void Weapon_ApplySwitchAndRequestIdle(void *arg0, void *arg1) {
    Weapon_ApplyWeaponSwitch(arg0, arg1);
    Nav_RequestActorState(arg0, arg1, 0);
}
#endif

/* 80231F5C_6.CPP */
#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/** Check whether a human player in mode 1 may select a weapon; when refused play the refusal sound and post a notice. */

extern int D_800D30BC;
extern int Player_GetProfileAchievementFlag(char *, int);
extern int Player_GetPlayerIndex(void *, PlayerRecAt1450V1 *);
extern void Sky_PostTargetedScreenMessage(void *, void *, int, int, float);

int Weapon_CheckSinglePlayerFirePermission(PlayerRecAt1450V1 *player) {
    SettingsE *rules;
    int result;

    if (player->shield > 0.0f) {
        return 0;
    }
    if (player->isBot != 0) {
        return 1;
    }
    rules = &D_801462C8;
    if (rules->players != 1) {
        return 1;
    }
    result = Player_GetProfileAchievementFlag((char *)&D_80102B00[player->character], player->weapon);
    if (result == 0) {
        SoundElement_PlayFlatSound(0xD4D);
        if (player->hud != 0) {
            Sky_PostTargetedScreenMessage((char *)rules - 0x1240, player->hud, D_800D30BC,
                          Player_GetPlayerIndex((char *)rules - 0x1288, player), D_800C8100);
        }
    }
    return result;
}
#endif

/* 80231F5C_7.CPP */
extern void func_8022AF74_de(Shared_ActorView *arg0, s32 arg1);

void Weapon_InitializeChargeForWeaponFive(Shared_ActorView *arg0, WeaponFireState *fireState) {
    Shared_ActorView *temp_a0;
    s16 idx;

    temp_a0 = arg0->self;
    idx = temp_a0->selectedAction;
    fireState->charge = ((WeaponInfo *)D_800D052C[idx])->chargeRate * D_800C3014_de;
    if ((temp_a0->selectedAction == 5) && (temp_a0->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0x46A);
    }
}

/* 80231F5C_8.CPP */
extern s32 Menu_CountLiveNodes(void *arg0);
extern s32 Playerai_GetWeaponAmmo(void *arg0, s16 arg1);

void Weapon_DrawWeaponLookupModel(void *arg0, Dest *arg1, Lookup *lookup) {
    void *actor;
    void *resource;
    s32 result;
    s32 one;
    s16 state;

    actor = ((LevelActor *)arg0)->controller;
    resource = ((Shared_ActorView *)actor)->message;
    result = -1;
    if (resource == 0) {
        return;
    }
    if (D_801462C8.local != 0) {
        if (Menu_CountLiveNodes((char *)resource + 0x554) != 0) {
            return;
        }
    }
    state = ((Shared_ActorView *)actor)->selectedAction;
    one = 1;
    if ((state == one) && (arg1->field144 == 0)) {
        return;
    }
    if ((state >= 0x12) && (Playerai_GetWeaponAmmo(actor, state) <= 0)) {
        return;
    }
    state = ((Shared_ActorView *)actor)->selectedAction;
    if ((state == 0xE) || (state == one) || (state == 0)) {
        result = ((Shared_ActorView *)actor)->unk_0x11F8;
    }
    Geometry_DrawModelResource(lookup->value,
                  ((LevelActor *)arg0)->fieldB4, 1,
                  (char *)arg0 + (D_800D297C * 0x18 + 0x140), 0, result);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void Weapon_ApplySwitchAndRequestIdle(void *arg0, void *arg1);
#else
#endif

void Weapon_InitializeFireStateCallbacks(void *arg0, void *arg1) {
    f32 k = D_800C3018_de;

    ((Dest *)arg1)->table = &D_800CA058;
    ((Dest *)arg1)->enter = &D_0022FC20;
    ((Dest *)arg1)->draw = &D_0023293C;
    ((Dest *)arg1)->field124 = 0;
    ((Dest *)arg1)->charge = 0;
    ((Dest *)arg1)->field130 = 0;
    ((Dest *)arg1)->field138 = 0;
    ((Dest *)arg1)->field13C = 1;
    ((Dest *)arg1)->field12C = k;
    ((LevelActor *)arg0)->team = 0;
    ((Dest *)arg1)->field148 = 0;
    ((Dest *)arg1)->field144 = 1;
    ((Dest *)arg1)->field14C = 0;
    ((Dest *)arg1)->field150 = 0;

#if defined(VERSION_EU) || defined(VERSION_EU_X)
Weapon_ApplySwitchAndRequestIdle
#else
Weaponai_InitializeSwitchAndRequestIdle
#endif
(arg0, arg1);
}

extern s32 Playerai_PlayerHasAmmoForWeapon(void *arg0, s32 arg1);

s32 Weapon_PickRandomArmedWeapon(void *player) {
    s32 weapon;
    s32 remainingArmedSteps;

    weapon = ((Shared_ActorView *)player)->selectedAction;
    remainingArmedSteps = GraphU64_NextRandom() % 22;
    if (remainingArmedSteps >= 0) {
        do {
            weapon += 1;
            if (weapon >= 0x10) {
                weapon = 0;
            }
            if (Playerai_PlayerHasAmmoForWeapon(player, weapon) != 0) {
                remainingArmedSteps -= 1;
            }
        } while (remainingArmedSteps >= 0);
    }
    return weapon;
}

/* 80231F5C_9.CPP */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
void Weapon_ApplySwitchAndSetSingleRound(void *arg0, func_80232A38_S1 *arg1) {
    Weapon_ApplyWeaponSwitch(arg0, arg1);
    arg1->unk13C = 1;
    arg1->unk144 = 1;
}
#endif

/* 80231F5C_10.CPP */
extern s32 func_802301F4_de(void *, void *);

void Weapon_ResetControllerAndSpin(LevelActor *actor, WeaponFireState *fireState) {
    void *controller;

    controller = actor->controller;
    ((Shared_ActorView *)controller)->controllerMode = 1;
    ((Shared_ActorView *)controller)->controllerOwner = 0;
    ((Player *)controller)->controllerTimer = 0;
    fireState->spinStep = 0;
    fireState->spin = 0;
    if ((fireState->triggerMode != 0) && (func_802301F4_de(actor, fireState) == 0)) {
        Nav_RequestActorState(actor, fireState, 2);
    }
}

s32 Weapon_IsTriggerReleasedOrBlocked(LevelActor *actor, void *arg1, Shared_ActorView *arg2) {
    s32 temp_v0;
    void *owner;

    {
        f32 field = arg2->stun;
        if (D_800C301C_de < field) {
            return 1;
        }
    }
    if ((actor->flags & 0x300000) && (arg2->remote != 0)) {
        owner = arg2->owner;
        temp_v0 = ((LevelActor *)owner)->actionReady;
        ((LevelActor *)owner)->actionReady = 0;
        return temp_v0 == 0;
    }
    if (arg2->actionFlags & 0x2000) {
        if (arg2->actionState != 0) {
            return 1;
        }
        return Player_HasAmmoForMode(arg2, arg2->selectedAction) == 0;
    }
    return 1;
}

void Weapon_ReleaseLinkedActorHandles(void *arg0) {
    Player_ReleaseObjectHandles((((struct ActorRecAt1D8V1 *) ((s8 *) arg0))->link));
}

void Weapon_InitializeChargeForWeaponEight(Shared_ActorView *arg0, WeaponFireState *fireState) {
    void *temp_a0;
    s16 idx;

    temp_a0 = arg0->self;
    idx = ((Shared_ActorView *)temp_a0)->selectedAction;
    fireState->charge = ((WeaponInfo *)D_800D052C[idx])->chargeRate * D_800C3020_de;
    if ((((Shared_ActorView *)temp_a0)->selectedAction == 8) && (((Shared_ActorView *)temp_a0)->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0xA3C);
    }
}

void Weapon_UpdateTriggerReleaseState(void *actor, void *attack) {
    Player *state;

    state = ((Shared_Actor *)actor)->entity;
    if (((WeaponFireState *)attack)->triggerMode != 0) {
        if (func_802301F4_de(actor, attack) != 0) {
            ((WeaponFireState *)attack)->triggerMode = 0;
            ((WeaponFireState *)attack)->queuedAction = -1;
        } else {
            switch (state->selectedAction) {
            case 8:
                SoundElement_PlaySoundAtPosition(0xA3E, state->pos,
                              (s32)&state->pos, -1);
            case 0:
            case 14:
                func_8022B00C_de(state);
                Nav_RequestActorState(actor, attack, 2);
                break;
            default:
                Nav_RequestActorState(actor, attack, 2);
                break;
            }
        }
        state->controllerMode = 1;
        state->controllerTimer = 0;
    } else if ((state->selectedAction == 12) &&
               ((state->inputFlags & 0x4000) != 0)) {
        func_8022B190_de((s32)state);
    }
}

/* 80231F5C_11.CPP */

/* Applies the negated, scaled speed of the event's source (float at 0x294, scaled by D_800C8130) to an
   object through YawMatrixLocal when the event side at 0x4 matches the mode: side 2 in mode 1, side 0
   otherwise. */

extern s16 Weapon_FindNextUsableWeapon(void *arg0);

extern WeaponActionRecord D_800CE8DC[];

void Weapon_ReleaseHandlesAndExitState39(void *arg0) {
    s32 temp_s0;
    temp_s0 = (((struct ActorRecAt1D8V1 *) ((s8 *) arg0))->link);
    Player_ReleaseObjectHandles(temp_s0);
    if ((((struct ObjRecAt650 *) ((s8 *) temp_s0))->unk650) == 0x27) {
        Player_SetPlayerState((void *) temp_s0, (void *) temp_s0, 2);
    }
}

void Weapon_PlayStartupCue9E2(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjRecAt1D8V1 *) ((s8 *) arg0))->unk1D8);
    if ((((struct IntegerState11C4 *) ((s8 *) temp_a0))->unk_11C0) == 0) {
        func_8022AF74_de(temp_a0, 0x9E2);
    }
}

void Weapon_AdvanceSpinAndTriggerMode(struct MeasuredRecAt1D8V2 *actor, void *attack) {
    f32 temp_f1;
    f32 temp_f2;
    void *value;
    void *temp_v0;

    value = actor->value;
    ((struct MeasuredRecAt124 *)(attack))->value += (((struct MeasuredRecAt128 *)(attack))->value * D_800D2988) * 2.0f;
    temp_f1 = ((struct MeasuredRecAt128 *)(attack))->value;
    temp_v0 = ((struct MeasuredRecAt698V2 *)(value))->value;
    if (!(temp_f1 < 0.0f
              ? D_800C3028_de < (-temp_f1 * *(&D_800C3020_de + 1))
              : D_800C3030_de[0] < (temp_f1 * D_800C302C_de))) {
        temp_f2 = ((struct MeasuredRecAt128 *)(attack))->value;
        if (temp_f2 < 0.0f) {
            ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) (-temp_f2 * D_800C3030_de[1]);
        } else {
            ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) (temp_f2 * D_800C3038_de);
        }
    } else {
        ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) D_800C303C_de;
    }

    if (((struct MeasuredRecAtCB *)(attack))->value != 0) {
        ((struct MeasuredRecAt13CV1 *)(attack))->value = 2;
        if (func_802301F4_de(actor, attack) != 0) {
            ((struct MeasuredRecAt13CV1 *)(attack))->value = 1;
            func_8022B00C_de(value);
        }
    }
}

void Weapon_ApplyScaledSideYaw(void *obj, Event *event) {
    float v = event->source->speed * D_800C8130;

    if (D_80140FF8.field_0 == 1) {
        if (event->side == 2) {
            YawMatrixLocal(obj, -v);
        }
    } else if (event->side == 0) {
        YawMatrixLocal(obj, -v);
    }
}

void Weapon_UpdateNormalFireAction(void *actor, ObjectState140 *attack) {
    char *o = (char *) actor;
    void *temp_s0;
    s16 idx;
    s32 action;

    temp_s0 = (void *)((Shared_ActorView *)o)->self;
    idx = ((Shared_ActorView *)temp_s0)->action;
    action = D_800CE8DC[idx].action;

    if (Player_HasAmmoForMode(temp_s0, ((Shared_ActorView *)temp_s0)->selectedAction) == 0) {
        ((Shared_ActorView *)temp_s0)->nextWeapon = Weapon_FindNextUsableWeapon(temp_s0);
    } else {
        attack->unk_13C = 1;
        if (func_802301F4_de(actor, attack) == 0 && !(((Shared_ActorView *)o)->flags & 0x400)) {
            Nav_RequestActorState(actor, attack, action);
        }
    }
}

void Weapon_InitializeChargeAndStartupCues(Shared_ActorView *arg0, WeaponFireState *fireState) {
    Shared_ActorView *temp_s0;
    Shared_ActorView *temp_a0;
    s16 index;

    temp_s0 = arg0->self;
    fireState->cueTimer = 0;
    if ((temp_s0->remote == 0) &&
        (D_80140FF8.field_0 == 1)) {
        func_8021A9A4_de(arg0->self, 0x3F9);
    } else {
        func_8021A9A4_de(arg0->self, 0x4CB);
    }
    func_8022AEA0_de(temp_s0, 0x78A);
    func_8022AF74_de(temp_s0, 0x780);

    temp_a0 = arg0->self;
    index = temp_a0->selectedAction;
    fireState->charge =
        ((WeaponInfo *)D_800D052C[index])->chargeRate *
        D_800C3044_de;
    if ((temp_a0->selectedAction == 8) &&
        (temp_a0->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0xA3C);
    }
}

void Weapon_ApplySideDependentYaw(void *object, Event *event) {
    f32 speed;
    s32 mode;

    speed = event->source->speed;
    mode = D_80140FF8.field_0;
    if (mode == 1) {
        switch (event->side) {
        case 1:
            YawMatrixLocal(object, -speed);
            break;
        case 2:
            YawMatrixLocal(object, speed * 2.0f);
            break;
        }
    } else if (event->side == 0) {
        YawMatrixLocal(object, -speed * 2.0f);
    }
}

/* 80231F5C_12.CPP */

extern s32 func_8022B184_de(void *arg0);

extern void func_8022B984_de(void *arg0);

extern s32 Particle_CountOwnerListOneEffects(void *, s32);

extern char D_8011D8D0;

extern f32 GraphU64_ApproachValue(f32, f32, s32);

void Weapon_EnterChargeStateWithCues(Shared_ActorView *arg0, WeaponFireState *fireState) {
    void *player;
    void *temp_a0;
    s16 index;

    player = arg0->self;
    if (fireState->mode == 2) {
        Player_SetPlayerState(player, player, 2);
    } else {
        fireState->cueTimer = D_800C3048_de[0];
        if ((((Shared_ActorView *)player)->remote == 0) &&
            (D_80140FF8.field_0 == 1)) {
            func_8021A9A4_de(arg0->self, 0x3FB);
        } else {
            func_8021A9A4_de(arg0->self, 0x4CD);
        }
        Nav_RequestActorState(arg0, fireState, 4);
        func_8022AEA0_de(player, 0x977);
        func_8022AF74_de(player, 0x974);

        temp_a0 = arg0->self;
        index = ((Shared_ActorView *)temp_a0)->selectedAction;
        fireState->charge =
            ((WeaponInfo *)D_800D052C[index])->chargeRate *
            D_800C3048_de[1];
        if ((((Shared_ActorView *)temp_a0)->selectedAction == 8) &&
            (((Shared_ActorView *)temp_a0)->field11C0 == 0)) {
            func_8022AF74_de(temp_a0, 0xA3C);
        }
    }
}

void func_80233314_de(void) {
}

void Weapon_SetDelayAndRequestStateEight(void *arg0, struct Shared_Particle *particle) {
    particle->unk148 = D_800C3050_de;
    Nav_RequestActorState(arg0, particle, 8);
}

/** Perform the no-op callback at VRAM 0x80233334. */
void func_80233344_de(void) {
}

void Weapon_UpdateHeldAlternateFire(void *arg0, void *attack) {
    void *actor;

    actor = ((LevelActor *)arg0)->controller;
    ((WeaponFireState *)attack)->mode = 2;
    if (Player_HasAmmoForMode(actor, ((Shared_ActorView *)actor)->selectedAction) == 0) {
        ((Shared_ActorView *)actor)->nextWeapon = Weapon_FindNextUsableWeapon(actor);
        return;
    }

    if (((LevelActor *)arg0)->animationTime >= D_800C3054_de) {
        if (func_8022B184_de(actor) == 0) {
            func_8022B984_de(actor);
        }
    }

    if (!((((Shared_ActorView *)actor)->actionFlags & 0x4000) &&
          (((Shared_ActorView *)actor)->health != 0))) {
        Nav_RequestActorState(arg0, attack, 2);
        func_8022B9C4_de(actor);
        ((WeaponFireState *)attack)->mode = 1;
    }

    if (func_802301F4_de(arg0, attack) != 0) {
        func_8022B9C4_de(actor);
    }
}

void Weapon_UpdateSpecialFireAndAmmo(void *arg0, void *attack) {
    void *actor;
    s16 idx;
    s32 value;

    actor = ((ObjectLinks1DC_3 *)arg0)->unk_1D8;
    idx = ((ObjectLinks11DC *)(actor))->unk_650;
    value = D_800CE8DC[idx].action;

    if (((ObjectLinks11DC *)(actor))->unk_11D8 <= 0.0f) {
        if ((((struct Ctrl *) ((ObjectLinks11DC *) actor)->unk_5D8)->flag == 0 ||
             D_801462C8.counters.m_bFragTagOn == 0) &&
            (((ObjectLinks11DC *)(actor))->unk_6AC & 0x4000)) {
            func_8022B190_de(actor);
        }
    }

    if (Player_HasAmmoForMode(actor, ((ObjectLinks11DC *)(actor))->unk_62E) == 0) {
        if (Particle_CountOwnerListOneEffects(&D_8011D8D0, actor) == 0) {
            ((ObjectLinks11DC *)(actor))->unk_770 = Weapon_FindNextUsableWeapon(actor);
        }
    } else if (func_802301F4_de(arg0, attack) == 0 &&
               !(((ObjectLinks1DC_3 *)arg0)->unk_100 & 0x400)) {
        Nav_RequestActorState(arg0, attack, value);
    }
}

void Weapon_RequestReleaseOnEnabledEvent(void *a, struct WeaponEventSource *b) {
    if (b->eventEnabled != 0) {
        Nav_RequestActorState(a, b, 2);
    }
}

void Weapon_PlayStartupCue80C(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjRecAt1D8V1 *) ((s8 *) arg0))->unk1D8);
    if ((((struct IntegerState11C4 *) ((s8 *) temp_a0))->unk_11C0) == 0) {
        func_8022AF74_de(temp_a0, 0x80C);
    }
}

void Weapon_UpdateAlternateTriggerCompletion(LevelActor *actor, WeaponFireState *fireState) {
    void *controller;

    controller = actor->controller;
    if (fireState->triggerMode != 0) {
        fireState->mode = 2;
        if (func_802301F4_de(actor, fireState) != 0) {
            fireState->mode = 1;
            func_8022B00C_de(controller);
        }
    }
}

void Weapon_EaseSpinForActionFive(struct MeasuredRecAt1D8V2 *arg0, void *arg1) {
    f32 temp_f1;
    f32 temp_f2;
    void *value;
    void *temp_v0;

    value = arg0->value;
    if (((struct MeasuredRecAt34 *)(arg1))->value == 5) {
        GraphU64_EaseValueToward(arg1 + 0x128, (f32) D_800CA2D8_de * D_800C3058_de, 0.4f);
    } else {
        GraphU64_EaseValueToward(arg1 + 0x128, 0.0f, 0.4f);
    }
    temp_f1 = ((struct MeasuredRecAt128 *)(arg1))->value;
    temp_v0 = ((struct MeasuredRecAt698V2 *)(value))->value;
    if (!(temp_f1 < 0.0f
              ? D_800C3060_de < (-temp_f1 * D_800C305C_de)
              : D_800C3068_de[0] < (temp_f1 * D_800C3064_de))) {
        temp_f2 = ((struct MeasuredRecAt128 *)(arg1))->value;
        if (temp_f2 < 0.0f) {
            ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) (-temp_f2 * D_800C3068_de[1]);
            return;
        }
        ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) (temp_f2 * D_800C3070_de);
        return;
    }
    ((struct MeasuredRecAt168V1 *)(temp_v0))->value = (f32) D_800C3074_de;
}

void Weapon_ApproachSpinPhaseAndRelease(void *arg0, struct WeaponFireState *fireState) {
    f32 temp_f0;
    f32 target;

    target = D_800C3078_de;
    temp_f0 = GraphU64_ApproachValue(fireState->spinStep, target, D_800CA7A0_de);
    fireState->spinStep = temp_f0;
    if (target <= temp_f0) {
        Nav_RequestActorState(arg0, fireState, 2);
    }
}

void Weapon_TranslateEventSixByPitch(void *matrix, void *arg1) {
    ObjRecAt8V1 *event = arg1;
    if (event->unk4 == 6) {
        LevelActor *actor = event->unk8;
        TranslateMatrixLocal(matrix, 0.0f, actor->pitch, 0.0f);
    }
}

/* 800C8100.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_802327F4_C8D00[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802327F4_C8D00_us_rev1.c */
const unsigned int D_blob_623dc1480292e3a80b8a[1] = {
    0x3F800000,
};
#endif

/* 800C8104.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_802328D8_C8D04[1] = {
    0x41700000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802328D8_C8D04_us_rev1.c */
const unsigned int D_blob_2389a648aef16664c94d[1] = {
    0x41700000,
};
#endif

/* 800C8108.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80232A48_C8D08[1] = {
    0x3F800000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80232A48_C8D08_us_rev1.c */
const unsigned int D_blob_ee0e31e93888967ca263[1] = {
    0x3F800000,
};
#endif

/* 800C810C.CPP */
/* ROM-grounded data: src/rw_pool_80232BD0_C8D0C_us_rev1.c */
const unsigned int D_blob_f7f44b23f073277f33ae[1] = {
    0x3DCCCCCD,
};

/* 800C8110.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_80232C88_C8D10[1] = {
    0x41700000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_80232C88_C8D10_us_rev1.c */
const unsigned int D_blob_8ff3ca9afe35ca23c56e[1] = {
    0x41700000,
};
#endif

/* 800C8114.CPP */
const unsigned int D_auto_src_rw_pool_80232E64_C8D14_us_rev1[7] = {
    0x3FE52EDF, 0x3F800000, 0x3FE52EDF, 0x3F800000, 0x3FE52EDF, 0x3FE52EDF, 0x3F800000,
};

/* 800C8130.CPP */
/* ROM-grounded data: src/rw_pool_80232F8C_C8D30_us_rev1.c */
const unsigned int D_blob_0fd23d14ffff3a7a287e[1] = {
    0x3FC00000,
};

/* 800C8134.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_802330AC_C8D34[1] = {
    0x41700000,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802330AC_C8D34_us_rev1.c */
const unsigned int D_blob_8cabd7ec07ecd852f532[1] = {
    0x41700000,
};
#endif

/* 800C8138.CPP */
/* ROM-grounded data: src/rw_pool_802331FC_C8D38_us_rev1.c */
const unsigned int D_blob_3c990c36019f9d2fdf72[2] = {
    0x40200000, 0x41700000,
};

/* 800C8140.CPP */
/* ROM-grounded data: src/rw_pool_8023331C_C8D40_us_rev1.c */
const unsigned int D_blob_820ef7fd0a7ce277e362[1] = {
    0x43960000,
};

/* 800C8144.CPP */
/* ROM-grounded data: src/rw_pool_8023334C_C8D44_us_rev1.c */
const unsigned int D_blob_5a75d5298ddd3c892ea1[1] = {
    0x40800000,
};

/* 800C8148.CPP */
const unsigned int D_auto_src_rw_pool_802335EC_C8D48_us_rev1[8] = {
    0x3C8EFA36, 0x3FE52EDF, 0x3F800000, 0x3FE52EDF, 0x3F800000, 0x3FE52EDF, 0x3FE52EDF, 0x3F800000,
};

/* 800C8168.CPP */
/* ROM-grounded data: src/rw_pool_8023371C_C8D68_us_rev1.c */
const unsigned int D_blob_9c143aa5516c0958c802[1] = {
    0x44160000,
};

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C2FAC[1] = {
    0x000B0000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C332C[1] = {
    0x02603821,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C307C[1] = {
    0x40C00000,
};
#endif
