#include "include_asm.h"

#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "stddef.h"
s32 func_80209874_de(void *, s32);
s32 func_80209A94_de(void *);
s32 func_80209AD8_de(void *);
f32 func_80209B64_de(void *);
s32 func_8020EA10_de(void *);
s32 func_8020F5A4_de(void *);
s32 func_8022AAD4_de(void *, s16);
s32 func_8022AB20_de(void *, s16);
s32 func_8022AC00_de(void *);
s32 func_8022ACB8_de(void *, s32, s32);
extern CGameStatus D_801468A0;

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
    maxHealth = func_8022AC00_de(controller->player) >> 8;
    healthPercent = (f32)health / (f32)maxHealth * 100.0f;
    ammoCount = func_8022AB20_de(controller->player, controller->player->selectedAction);
    ammoType = func_8022AAD4_de(controller->player, controller->player->selectedAction);
    capacity = func_8022ACB8_de(controller->player, ammoType, 1);
    if (capacity != 0 && ammoCount != -1) {
        ammoPercent = (f32)ammoCount / (f32)capacity * 100.0f;
    } else {
        ammoPercent = 100.0f;
    }
    ammo0 = controller->player->ammo[0];
    ammo1 = controller->player->ammo[1];
    ammo2 = controller->player->ammo[2];
    carrier = func_8022A83C_de((char *)&D_80145040);
    if (carrier != 0 && D_80145040.game.counters.m_bCTFOn != 0) {
        if (carrier == controller->player) {
            nextState = 10;
            func_80209874_de(controller, nextState);
            return 1;
        }
        if (controller->target != 0) {
            nextState = 1;
            func_80209874_de(controller, nextState);
            return 1;
        }
    }
    gameStatus = &D_801468A0;
    if (gameStatus->m_bFragTagOn != 0 && controller->player->profile->bonus != 0) {
        if (gameStatus->restrictionActive > 0) {
            if (controller->state != 2) {
                func_80209874_de(controller, 2);
                return controller->unk2F8 = controller->unk2F4 = 1;
            }
            return 1;
        }
        nextState = 11;
        func_80209874_de(controller, nextState);
        return 1;
    }
    healthThreshold = (s32)((1.0f - func_80209B64_de(controller)) * 80.0f);
    if (D_80146938 != 0 && controller->player->profile->enabled != 0) {
        healthThreshold = 0;
    }
    if (func_80209AD8_de(controller) == 0 && healthPercent < (f32)healthThreshold) {
        controller->routeState = 1;
        nextState = 8;
        func_80209874_de(controller, nextState);
        return 1;
    }
    if (func_80209AD8_de(controller) == 0 && ammoPercent < 10.0f) {
        controller->routeState = func_8020F5A4_de(controller);
        nextState = 8;
        func_80209874_de(controller, nextState);
        return 1;
    }
    state = controller->state;
    if ((state == 3 || state == 4 || state == 13) && ammo0 < 10 && ammo1 < 10 && ammo2 <= 0) {
        controller->routeState = 4;
        nextState = 8;
        func_80209874_de(controller, nextState);
        return 1;
    }
    if (func_80209A94_de(controller) != 0 && controller->target == 0) {
        nextState = 2;
        func_80209874_de(controller, nextState);
        return 1;
    }
    if (func_8020EA10_de(controller) != 0 && (state = controller->state) != 9) {
        if (state == 1 || state == 2) {
            nextState = 9;
            func_80209874_de(controller, nextState);
            return 1;
        }
    } else if (func_80209AD8_de(controller) != 0 && (f32)healthThreshold < healthPercent && 10.0f < ammoPercent) {
        nextState = 2;
        func_80209874_de(controller, nextState);
        return 1;
    } else if (func_80209A94_de(controller) == 0 && func_80209AD8_de(controller) == 0 && controller->target != 0) {
        if (controller->player->profile->enabled != 0) {
            if (controller->player->profile->character == 12) {
                func_80209874_de(controller, 13);
                return 1;
            }
        }
        func_80209874_de(controller, 1);
        return 1;
    }
    return 1;

}
