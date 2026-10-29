#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"

#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "TYPES.H"
#include "stddef.h"
s32 Scaled_SetBehaviourState(void *, s32);
s32 Scaled_MatchesBehaviorStateFilter(void *);
s32 Scaled_IsBehaviorStateEight(void *);
f32 Scaled_GetScaledAggression(void *);
s32 Nav_ShouldSeekUnclaimedTeamMarker(void *);
s32 Nav_GetWeaponPickupGoalClass(void *);
s32 Playerai_GetWeaponClassId(void *, s16);
s32 Playerai_GetWeaponAmmo(void *, s16);
s32 Player_GetMaxHealth(void *);
s32 Player_GetAmmoCapacity(void *, s32, s32);
extern CGameStatus g_matchRoundCounters;

/* Choose the next AI state from game objectives, supplies and the current target. */
s32 Nav_SelectPlayerState(AiController *controller) {
    s32 nextState;
    s32 health;
    s32 maxHealth;
    s32 ammoCount;
    s32 capacity;
    s32 ammoType;
    s32 healthThreshold;
    s32 state;
    f32 healthPercent;
    f32 ammoPercent;
    s32 ammo0;
    s32 ammo1;
    s32 ammo2;
    Player *carrier;
    CGameStatus *gameStatus;

    health = controller->player->health >> 8;
    maxHealth = Player_GetMaxHealth(controller->player) >> 8;
    healthPercent = (f32)health / (f32)maxHealth * 100.0f;
    ammoCount = Playerai_GetWeaponAmmo(controller->player, controller->player->selectedAction);
    ammoType = Playerai_GetWeaponClassId(controller->player, controller->player->selectedAction);
    capacity = Player_GetAmmoCapacity(controller->player, ammoType, 1);
    if (capacity != 0 && ammoCount != -1) {
        ammoPercent = (f32)ammoCount / (f32)capacity * 100.0f;
    } else {
        ammoPercent = 100.0f;
    }
    ammo0 = controller->player->ammo[0];
    ammo1 = controller->player->ammo[1];
    ammo2 = controller->player->ammo[2];
    carrier = Playerai_FindPlayerWithMarker((char *)&g_playerViewRenderContext);
    if (carrier != 0 && g_playerViewRenderContext.game.counters.m_bCTFOn != 0) {
        if (carrier == controller->player) {
            nextState = 10;
            Scaled_SetBehaviourState(controller, nextState);
            return 1;
        }
        if (controller->target != 0) {
            nextState = 1;
            Scaled_SetBehaviourState(controller, nextState);
            return 1;
        }
    }
    gameStatus = &g_matchRoundCounters;
    if (gameStatus->m_bFragTagOn != 0 && controller->player->profile->bonus != 0) {
        if (gameStatus->m_FragTagFlipTimer > 0) {
            if (controller->state != 2) {
                Scaled_SetBehaviourState(controller, 2);
                return controller->unk2F8 = controller->unk2F4 = 1;
            }
            return 1;
        }
        nextState = 11;
        Scaled_SetBehaviourState(controller, nextState);
        return 1;
    }
    healthThreshold = (s32)((1.0f - Scaled_GetScaledAggression(controller)) * 80.0f);
    if (g_gameSettings.counters.enabled != 0 && controller->player->profile->enabled != 0) {
        healthThreshold = 0;
    }
    if (Scaled_IsBehaviorStateEight(controller) == 0 && healthPercent < (f32)healthThreshold) {
        controller->routeState = 1;
        nextState = 8;
        Scaled_SetBehaviourState(controller, nextState);
        return 1;
    }
    if (Scaled_IsBehaviorStateEight(controller) == 0 && ammoPercent < 10.0f) {
        controller->routeState = Nav_GetWeaponPickupGoalClass(controller);
        nextState = 8;
        Scaled_SetBehaviourState(controller, nextState);
        return 1;
    }
    state = controller->state;
    if ((state == 3 || state == 4 || state == 13) && ammo0 < 10 && ammo1 < 10 && ammo2 <= 0) {
        controller->routeState = 4;
        nextState = 8;
        Scaled_SetBehaviourState(controller, nextState);
        return 1;
    }
    if (Scaled_MatchesBehaviorStateFilter(controller) != 0 && controller->target == 0) {
        nextState = 2;
        Scaled_SetBehaviourState(controller, nextState);
        return 1;
    }
    if (Nav_ShouldSeekUnclaimedTeamMarker(controller) != 0 && (state = controller->state) != 9) {
        if (state == 1 || state == 2) {
            nextState = 9;
            Scaled_SetBehaviourState(controller, nextState);
            return 1;
        }
    } else if (Scaled_IsBehaviorStateEight(controller) != 0 && (f32)healthThreshold < healthPercent && 10.0f < ammoPercent) {
        nextState = 2;
        Scaled_SetBehaviourState(controller, nextState);
        return 1;
    } else if (Scaled_MatchesBehaviorStateFilter(controller) == 0 && Scaled_IsBehaviorStateEight(controller) == 0 && controller->target != 0) {
        if (controller->player->profile->enabled != 0) {
            if (controller->player->profile->character == 12) {
                Scaled_SetBehaviourState(controller, 13);
                return 1;
            }
        }
        Scaled_SetBehaviourState(controller, 1);
        return 1;
    }
    return 1;

}
