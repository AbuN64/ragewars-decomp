#include "include_asm.h"
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

extern void func_80208000_de(void);

f32 func_802726F8_de(f32 *, f32 *);

extern void *func_8020C994_de(void *, s32);

extern NavigationGraph D_8013B364;

extern char D_80103FD0;

extern void **D_80103FCC;

extern s32 func_802444A4_de(void *arg0, CVector3 arg1, CVector3 arg2, void *arg3);

/* Revives a player whose down timer at 0x1340 has run past its limit (30 ticks, or 900 in
   control modes 12 and 15 while D_80146938 asks): clears the timer and calls func_8044972C_de
   unless the session at 0x98 is running and the player's team membership at 0x94 and control
   mode disagree, or it is teamless and active outside session mode 3. */









extern void func_8044972C_de(SharedPlayer *);

void func_802095F8_de(Brain *object) {
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
        if (D_801468F4 && target->profile->scaled) targetHeight *= D_800C1C78_de;
        delta = brain->targetPosition;
        delta.x -= origin.x;
        delta.y -= origin.y;
        delta.z -= origin.z;
        correction = targetHeight - ownHeight;
        brain->distance = func_802B72B0_de(delta.x*delta.x + delta.y*delta.y + delta.z*delta.z);
        vertical = delta.y;
        delta.y = 0.0f;
        vertical += correction;
        zero = delta.y;
        horizontal = func_802B72B0_de(delta.x*delta.x + delta.z*delta.z);
        if (horizontal == zero) {
            if (vertical < zero) brain->angle = D_800C1C7C_de;
            else brain->angle = D_800C1C80_de;
        } else brain->angle = func_8029C044_de(vertical, horizontal) * D_800C1C84_de;
    } else brain->angle = 0.0f;
    brain->previousAngle = brain->angle;
}

void func_802097E8_de(int *arg0, int arg1) {
    *arg0 = arg1;
    func_80208000_de();
}

void func_80209804_de(AiController *arg0)
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

s32 func_80209828_de(AiController *queue) {
    s32 i;

    for (i = 1; i < 4; i++) {
        queue->queue[i - 1] = queue->queue[i];
    }
    queue->queue[3] = -1;
    return queue->queue[0] != -1;
}

/** Store the second argument at byte offset 0x214 in the first argument. */
void func_8020986C_de(AiController *object, AiBehaviourTable *value) {
    object->table = value;
}

s32 func_80209874_de(AiController *arg0, s32 arg1) {
    AiBehaviourTable *node;
    AiBehaviourEntry *entry;
    AiBehaviourEntry *found;
    void (*callback)(Player *, s32);

    node = arg0->table;
    found = 0;
    arg0->state = arg1;
    while (node != 0) {
        entry = node->entries;
        if (entry->id != -1) {
            while (entry->id != -1) {
                if (entry->id == arg1) {
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
    arg0->behaviour = found;
    callback = found->enter;
    if (callback != 0) callback(arg0->player, 0);
    return 1;
}

void func_80209910_de(AiController *arg0, float arg1) {
    float result = arg1 * D_800C1C88_de;
    if (arg0 != 0) {
        arg0->player->pitch = -result;
    }
}

CVector3 *func_8020993C_de(AiController *arg0) {
    return &arg0->player->pos;
}

void func_80209948_de(AiController *arg0, s32 arg1) {
    func_802726F8_de(&arg0->player->pos.x, func_8020C994_de(&D_8013B364, arg1));
}

/** Reset three state words and set the final state to one. */
void func_80209988_de(void *object) {
    AiController *arg0 = object;
    arg0->unk2F4 = 0;
    arg0->unk2F8 = 0;
    arg0->unk2FC = 1;
}

/** Clear five consecutive object words beginning at offset 0x300. */
void func_8020999C_de(AiController *arg0) {
    arg0->unk300 = 0;
    arg0->unk304 = 0;
    arg0->unk308 = 0;
    arg0->unk30C = 0;
    arg0->unk310 = 0;
}

s32 func_802099B4_de(Player **arg0, Player *arg1) {
    CVector3 first;
    CVector3 second;

    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }

    first = (*arg0)->pos;
    second = arg1->pos;
    first.y += D_800C1C8C_de;
    second.y += D_800C1C8C_de;
    if (func_802444A4_de(*arg0, first, second, &D_80103FD0) != 0) {
        return *D_80103FCC == arg1;
    }
    return 1;
}

s32 func_80209A94_de(AiController *arg0) {
    s32 val;

    val = arg0->state;
    if (val >= 8) {
        goto ge_8;
    }
    if (val >= 3) {
        goto ret1;
    }
    if (val == 1) {
        goto ret1;
    }
    goto ret0;
ge_8:
    if (val != 0xD) {
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

f32 func_80209AE8_de(AiController *arg0)
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

f32 func_80209B64_de(AiController *arg0) {
    f32 value;
    u8 state;
    Player *base;
    AiCharacterDefinition *definition;

    base = arg0->player;
    definition = base->definition;
    state = base->profile->difficulty;
    value = definition->unk28;
    value *= D_800C1C9C_de;
    switch (state) {
    case 1:
        break;
    default:
        arg0->player->profile->difficulty = 0;
    case 0:
        value *= D_800C1CA0_de;
        break;
    case 2:
        value *= D_800C1CA4_de;
        break;
    }
    return value;
}

f32 func_80209BE0_de(AiController *arg0) {
    f32 var_f0;
    f32 var_f1;
    u8 state;
    Player *base;
    AiCharacterDefinition *definition;

    base = arg0->player;
    definition = base->definition;
    state = base->profile->difficulty;
    var_f1 = definition->unk34;
    var_f1 *= D_800C1CA8_de;
    switch (state) {
    case 1:
        goto done;
    default:
        arg0->player->profile->difficulty = 0;
    case 0:
        var_f0 = D_800C1CAC_de;
        goto multiply;
    case 2:
        var_f0 = D_800C1CB0_de;
    }
multiply:
    var_f1 *= var_f0;
done:
    return var_f1;
}

f32 func_80209C5C_de(AiController *arg0) {
    f32 var_f0;
    f32 var_f1;
    u8 state;
    Player *base;
    AiCharacterDefinition *definition;

    base = arg0->player;
    definition = base->definition;
    state = base->profile->difficulty;
    var_f1 = definition->unk30;
    var_f1 *= D_800C1CB4_de;
    switch (state) {
    case 1:
        break;
    default:
        arg0->player->profile->difficulty = 0;
    case 0:
        var_f0 = D_800C1CB8_de;
        goto multiply;
    case 2:
        var_f0 = D_800C1CBC_de;
multiply:
        var_f1 *= var_f0;
        break;
    }
    return var_f1;
}

void func_80209CD8_de(SharedPlayer **arg0) {
    s32 limit;
    Controls *controls;
    RenderCounters *session;
    s8 mode;

    if (D_80146938 != 0) {
        mode = (*arg0)->views5D8.view5D8_2.controls->mode;
        if (mode == 0xC || mode == 0xF) {
            limit = 0x384;
        } else {
            limit = 0x1E;
        }
    } else {
        limit = 0x1E;
    }
    if (limit < (*arg0)->views1340.view1340_2.timer) {
        session = &D_801462C8.counters;
        do {
            (*arg0)->views1340.view1340_2.timer = 0;
        } while (0);
        if (session->enabled != 0) {
            controls = (*arg0)->views5D8.view5D8_2.controls;
            if (controls->team == 0) {
                if (controls->active == 0 || session->unk9C == 3) {
                    func_8044972C_de(*arg0);
                }
            } else {
                mode = controls->mode;
                if (mode == 0xC || mode == 0xF) {
                    func_8044972C_de(*arg0);
                }
            }
        } else {
            func_8044972C_de(*arg0);
        }
    }
}

f32 func_80209DAC_de(void *arg0) {
    AiController *brain = arg0;
    f32 temp_f20;
    f32 var_f14;
    u8 state;

    state = brain->player->profile->difficulty;
    switch (state) {
    default:
        brain->player->profile->difficulty = 0;
    case 0:
        var_f14 = (1.2217305898666382f);
        break;
    case 1:
        var_f14 = (0.8726646900177002f);
        break;
    case 2:
        var_f14 = (0.523598849773407f);
        break;
    }
    temp_f20 = brain->aim;
    if (temp_f20 < func_80274A90_de(-var_f14, var_f14)) {
        temp_f20 += D_800C1CC0_de;
    } else {
        temp_f20 -= D_800C1CC4_de;
    }
    brain->aim = temp_f20;
    return temp_f20;
}

#if defined(VERSION_US)
INCLUDE_DATA("data_800C", rodata_unresolved_800C870C);
#endif
