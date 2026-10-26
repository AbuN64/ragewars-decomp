#include "include_asm.h"
#include "COMMON/LONE/D_80103FD0.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/INTEGERSTATE2C.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"

extern void func_8022B144_de(void *, f32 *);

extern void Nav_ResetPlayerState(s32 *state);

f32 GraphU64_GetPointDistance(f32 *, f32 *);

extern void *Nav_GetGraphPoint(void *, s32);

extern CNavData D_8013B364;


extern void **D_80103FCC;

extern s32 func_802444A4_de(void *arg0, CVector3 arg1, CVector3 arg2, void *arg3);

/* Revives a player whose down timer at 0x1340 has run past its limit (30 ticks, or 900 in
   control modes 12 and 15 while D_80146938 asks): clears the timer and calls func_8044972C_de
   unless the session at 0x98 is running and the player's team membership at 0x94 and control
   mode disagree, or it is teamless and active outside session mode 3. */









extern void func_8044972C_de(SharedPlayer *);

void Nav_UpdateTargetPitch(Brain *object) {
    void *memory = object;
    PitchBrain *brain = memory;
    CVector3 origin, delta;
    f32 ownHeight, targetHeight, correction, vertical, horizontal, zero;
    PitchPlayer *target;
    if (brain->target) {
        origin = brain->player->position;
        func_8022B144_de(brain->player, &delta.x);
        ownHeight = delta.y - brain->player->position.y;
        target = brain->target->player;
        if (target->transformed) {
            func_8022B144_de(target, &delta.x);
            targetHeight = delta.y - target->position.y;
        } else targetHeight = target->model->height - target->position.y;
        targetHeight *= D_800C1C74_de;
        if (D_801462C8.counters.m_bFragTagOn && target->profile->scaled) targetHeight *= D_800C1C78_de;
        delta = brain->targetPosition;
        delta.x -= origin.x;
        delta.y -= origin.y;
        delta.z -= origin.z;
        correction = targetHeight - ownHeight;
        brain->distance = Math_Sqrtf(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);
        vertical = delta.y;
        delta.y = 0.0f;
        vertical += correction;
        zero = delta.y;
        horizontal = Math_Sqrtf(delta.x*delta.x + delta.z*delta.z);
        if (horizontal == zero) {
            if (vertical < zero) brain->angle = D_800C1C7C_de;
            else brain->angle = D_800C1C80_de;
        } else brain->angle = XMath_EvaluateArcTangentTwo(vertical, horizontal) * D_800C1C84_de;
    } else brain->angle = 0.0f;
    brain->previousAngle = brain->angle;
}

/* Stores the player, then resets its AI state using the same pointer. */
void Nav_InitPlayerState(int *state, int player) {
    *state = player;
    Nav_ResetPlayerState(state);
}

void Nav_ClearNodeQueue(AiController *arg0)
{
    s32 i;
    s32 empty;
    empty = -1;
    i = 3;
    do {
        arg0->queue[i] = empty;
        i -= 1;
    } while (i >= 0);
}

/* Pops the front of a four-entry queue at offset 0x14 of a record: shifts the entries down one,
   marks the last empty with -1 and returns whether an entry remains at the front. */

s32 Nav_AdvanceNodeQueue(AiController *queue) {
    s32 i;

    for (i = 1; i < 4; i++) {
        queue->queue[i - 1] = queue->queue[i];
    }
    queue->queue[3] = -1;
    return queue->queue[0] != -1;
}

/** Store the second argument at byte offset 0x214 in the first argument. */
void Nav_SetBehaviorTable(AiController *object, AiBehaviourTable *value) {
    object->table = value;
}

s32 Nav_SetBehaviourState(AiController *controller, s32 behaviourId) {
    AiBehaviourTable *node;
    AiBehaviourEntry *entry;
    AiBehaviourEntry *found;
    void (*callback)(Player *, s32);

    node = controller->table;
    found = 0;
    controller->state = behaviourId;
    while (node != 0) {
        entry = node->entries;
        if (entry->id != -1) {
            while (entry->id != -1) {
                if (entry->id == behaviourId) {
                    found = entry;
                    node = 0;
                    break;
                }
                entry++;
            }
        }
        if (node != 0) node = node->next;
    }
    if (found == 0) return 0;
    controller->behaviour = found;
    callback = found->enter;
    if (callback != 0) callback(controller->player, 0);
    return 1;
}

void Nav_SetPitchFromAngle(AiController *controller, float amount) {
    float result = amount * D_800C1C88_de;
    if (controller != 0) {
        controller->player->pitch = -result;
    }
}

CVector3 *Nav_GetControllerPosition(AiController *controller) {
    return &controller->player->pos;
}

f32 Nav_DistanceToNode(AiController *controller, s32 nodeId) {
    return GraphU64_GetPointDistance(&controller->player->pos.x, Nav_GetGraphPoint(&D_8013B364, nodeId));
}

/** Reset three state words and set the final state to one. */
void Nav_ResetBehaviorState(void *object) {
    AiController *controller = object;
    controller->unk2F4 = 0;
    controller->unk2F8 = 0;
    controller->unk2FC = 1;
}

/** Clear five consecutive object words beginning at offset 0x300. */
void Nav_ClearAuxiliaryBehaviorState(AiController *controller) {
    controller->unk300 = 0;
    controller->unk304 = 0;
    controller->unk308 = 0;
    controller->unk30C = 0;
    controller->unk310 = 0;
}

s32 Nav_HasLineOfSight(Player **fromRef, Player *target) {
    CVector3 first;
    CVector3 second;

    if (fromRef == 0 || target == 0) {
        return 0;
    }

    first = (*fromRef)->pos;
    second = target->pos;
    first.y += D_800C1C8C_de;
    second.y += D_800C1C8C_de;
    if (func_802444A4_de(*fromRef, first, second, &D_80103FD0) != 0) {
        return *D_80103FCC == target;
    }
    return 1;
}

s32 Nav_MatchesBehaviorStateFilter(AiController *controller) {
    s32 state;

    state = controller->state;
    if (state >= 8) {
        goto ge_8;
    }
    if (state >= 3) {
        goto ret1;
    }
    if (state == 1) {
        goto ret1;
    }
    goto ret0;
ge_8:
    if (state != 0xD) {
        goto ret0;
    }
ret1:
    return 1;
ret0:
    return 0;
}

/** Report whether the state word at offset 0x21C equals eight. */
int func_80209AD8_de(AiController *object) {
    return object->state == 8;
}

f32 Nav_GetDifficultyEngagementAdjustment(AiController *arg0)
{
  Player *object;
    AiCharacterDefinition *definition;
  u8 state;
  f32 var_f0;
  f32 var_f1;
  object = arg0->player;
    definition = object->definition;
  state = object->profile->difficulty;
  var_f1 = definition->unk2C;
  var_f1 = var_f1 * D_800C1C90_de;
  switch (state)
  {
    case 1:
      goto done;

    default:
      arg0->player->profile->difficulty = 0;

    case 0:
      var_f0 = D_800C1C94_de;
      break;

    case 2:
      var_f0 = D_800C1C98_de;
      break;

  }

  var_f1 *= var_f0;
  done:
  return var_f1;

}

f32 Nav_GetScaledAggression(AiController *controller) {
    f32 value;
    u8 difficulty;
    Player *player;
    AiCharacterDefinition *definition;

    player = controller->player;
    definition = player->definition;
    difficulty = player->profile->difficulty;
    value = definition->unk28;
    value *= D_800C1C9C_de;
    switch (difficulty) {
    case 1:
        break;
    default:
        controller->player->profile->difficulty = 0;
    case 0:
        value *= D_800C1CA0_de;
        break;
    case 2:
        value *= D_800C1CA4_de;
        break;
    }
    return value;
}

f32 Nav_ScaleCharacterSettingByDifficulty(AiController *controller) {
    f32 difficultyScale;
    f32 value;
    u8 difficulty;
    Player *player;
    AiCharacterDefinition *definition;

    player = controller->player;
    definition = player->definition;
    difficulty = player->profile->difficulty;
    value = definition->unk34;
    value *= D_800C1CA8_de;
    switch (difficulty) {
    case 1:
        goto done;
    default:
        controller->player->profile->difficulty = 0;
    case 0:
        difficultyScale = D_800C1CAC_de;
        goto multiply;
    case 2:
        difficultyScale = D_800C1CB0_de;
    }
multiply:
    value *= difficultyScale;
done:
    return value;
}

f32 Nav_GetScaledAttackRange(AiController *controller) {
    f32 difficultyScale;
    f32 value;
    u8 difficulty;
    Player *player;
    AiCharacterDefinition *definition;

    player = controller->player;
    definition = player->definition;
    difficulty = player->profile->difficulty;
    value = definition->unk30;
    value *= D_800C1CB4_de;
    switch (difficulty) {
    case 1:
        break;
    default:
        controller->player->profile->difficulty = 0;
    case 0:
        difficultyScale = D_800C1CB8_de;
        goto multiply;
    case 2:
        difficultyScale = D_800C1CBC_de;
multiply:
        value *= difficultyScale;
        break;
    }
    return value;
}

void Nav_HandlePlayerTimeout(SharedPlayer **brain) {
    s32 limit;
    Controls *controls;
    CGameStatus *session;
    s8 mode;

    if (D_801462C8.counters.enabled != 0) {
        mode = (*brain)->views5D8.view5D8_2.controls->mode;
        if (mode == 0xC || mode == 0xF) {
            limit = 0x384;
        } else {
            limit = 0x1E;
        }
    } else {
        limit = 0x1E;
    }
    if (limit < (*brain)->views1340.view1340_2.timer) {
        session = &D_801462C8.counters;
        do {
            (*brain)->views1340.view1340_2.timer = 0;
        } while (0);
        if (session->enabled != 0) {
            controls = (*brain)->views5D8.view5D8_2.controls;
            if (controls->team == 0) {
                if (controls->active == 0 || session->m_nTalsetLives == 3) {
                    func_8044972C_de(*brain);
                }
            } else {
                mode = controls->mode;
                if (mode == 0xC || mode == 0xF) {
                    func_8044972C_de(*brain);
                }
            }
        } else {
            func_8044972C_de(*brain);
        }
    }
}

f32 Nav_UpdateDifficultyAimJitter(void *aiController) {
    AiController *brain = aiController;
    f32 aim;
    f32 aimLimit;
    u8 difficulty;

    difficulty = brain->player->profile->difficulty;
    switch (difficulty) {
    default:
        brain->player->profile->difficulty = 0;
    case 0:
        aimLimit = (1.2217305898666382f);
        break;
    case 1:
        aimLimit = (0.8726646900177002f);
        break;
    case 2:
        aimLimit = (0.523598849773407f);
        break;
    }
    aim = brain->aim;
    if (aim < GraphU64_RandomBetween(-aimLimit, aimLimit)) {
        aim += D_800C1CC0_de;
    } else {
        aim -= D_800C1CC4_de;
    }
    brain->aim = aim;
    return aim;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C870C[1] = {
    0x0B000000,
};
#endif
