#include "include_asm.h"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/WORLD.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "RENDER/80263760.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "RENDER/80291054_9.H"
#include "RENDER/80263760_8.H"


extern void func_80285D30_de(s32 *);

extern s32 D_8010EC90;





/* Advances the replay mode: when replays are possible (func_802934F8_de, D_80145070 and the handle table) it
 * cycles the mode 0 -> 1 -> 2 -> 0, snapshots the actors and records the camera target, promoting mode 1
 * to 2 when the player's target changed or the player is in states 0x16 to 0x21 and recording the player's
 * target instead; otherwise the mode is cleared. An active mode arms the 240-frame timer. */







extern s32 D_8013B2BC;

extern ObjectState1E_2 D_801462C8;

extern s32 func_802934F8_de(void);

extern void *func_8022A414_de(void *);

/** Return the global word at D_8010FC4C. */

/** Clear the global word at VRAM 0x8010FC40. */


/* Restores every actor from the global replay table: copies its 0x70-byte block back to 0x5E0 and, when
 * the table's mode is 1, also restores its position, its value at 0x6C and its identifier resolved from the
 * saved handle through func_8028B394_de. Adapted from the snapshot writer func_80264CE0_de, reading both tables
 * through local pointers and re-taking the actor list address in the loop increment. */











extern s32 func_8028B350_de(Shared_World *table, s32 id);





void func_802647E8_de(ControllerProfile *slot, s32 arg1) {
    slot->mode = arg1;
    if (arg1 == 0) {
        func_80264248_de(slot);
    }
}

void Render_ResetControllerProfiles(void) {
    ControllerProfile *slot;
    s32 i;

    i = 0;
    slot = D_8010F328;
    do {
        func_80264248_de(slot);
        i += 1;
        slot += 1;
    } while (i < 4);
}

void Render_SetControllerMode(s32 a) {
    ControllerProfile *slot;
    s32 i;

    i = 0;
    slot = D_8010F328;
    do {
        slot->mode = a;
        if (a == 0) {
            func_80264248_de(slot);
        }
        i += 1;
        slot += 1;
    } while (i < 4);
    if (a == 0) {
        func_80285D30_de(&D_8010EC90);
    }
}

void func_802648C8_de(void)
{
  s32 temp_v0;
  s32 temp_v1;
  s32 var_a0;
  s32 var_a1;
  s32 var_s1;
  ControllerProfile *var_s0;
  var_a0 = 0;
  var_a1 = 0;
  do
  {
    temp_v1 = *((s32 *) ((&D_8010B3F4) + var_a1));
 do { temp_v0 = var_a0 * 4; var_a0 += 1; *((s32 *) (((u8 *) D_8010BC18) + temp_v0)) = temp_v1; var_a1 += 0x224; } while (0);
  }
  while (var_a0 < 4);
  var_s1 = 0;
  func_80285D30_de(&D_8010EC90);
  var_s0 = D_8010F328;
  do
  {
    func_80264248_de(var_s0);
    var_s1 += 1;
    var_s0 += 1;
  }
  while (var_s1 < 4);
  D_800CBC18 = 1;
}

void func_8026495C_de(void) {
    ControllerProfile *slot;
    s32 i;
    s32 j;
    s32 var_a0;
    s32 temp_v0;

    if (D_800CBC18 != 0) {
        i = 0;
        slot = D_8010F328;
        do {
            func_80264248_de(slot);
            i += 1;
            slot += 1;
        } while (i < 4);
        j = 0;
        var_a0 = 0;
        do {
            temp_v0 = D_8010BC18[j];
            j += 1;
            *(s32 *)(&D_8010B3F4 + var_a0) = temp_v0;
            var_a0 += 0x224;
        } while (j < 4);
        func_80285D30_de(&D_8010EC90);
        D_800CBC18 = 0;
    }
}

void func_802649FC_de(void) {
    D_800CBC20 = 0;
}

void func_80264A0C_de(void) {
    D_800CBC20 = 1;
}

void func_80264A20_de(void) {
    Snapshot *snapshot;
    void *player;
    s32 enabled;
    ObjectState1E_2 *options;

    enabled = func_802934F8_de() != 0;
    snapshot = &D_8010BC40;
    if (D_80145070 == 0) {
        enabled = 0;
    }
    if (&D_8011FE88.mode == 0) {
        enabled = 0;
    }
    if (enabled) {
        switch (snapshot->mode) {
        case 0:
            snapshot->mode = 1;
            break;
        case 1:
            snapshot->mode = 2;
            break;
        case 2:
        default:
            snapshot->mode = 0;
            break;
        }
        func_80264CE0_de();
        snapshot->savedActorId = D_8013B2BC;
        options = &D_801462C8;
        if (options->unk_1D == 0) {
            player = func_8022A414_de((char *)options - 0x1288);
            if (player != 0) {
                if (snapshot->mode == 1 &&
                    (D_8013B2BC != ((Shared_ActorView *)player)->spawn ||
                     (u16)(((Shared_ActorView *)player)->action - 0x16) < 12)) {
                    snapshot->mode = 2;
                }
                snapshot->savedActorId = ((Shared_ActorView *)player)->spawn;
            }
        }
    } else {
        snapshot->mode = 0;
    }
    if (snapshot->mode != 0) {
        snapshot->countdown = 0xF0;
        snapshot->active = 1;
    } else {
        snapshot->countdown = 0;
        snapshot->active = 0;
    }
}

void func_80264B44_de(void) {
    D_8010BC40.active = 0;
    D_8010BC40.mode = 0;
    D_8010BC40.countdown = 0;
}

s32 func_80264B5C_de(void) {
    return D_8010BC40.savedActorId;
}

int func_80264B6C_de(void) {
    return D_8010BC40.active;
}

void func_80264B7C_de(void) {
    D_8010BC40.active = 0;
}

void func_80264B8C_de(void) {
    s32 i;
    ActorRecAt5E0 *actor;
    Snapshot *snapshot;
    ActorList *list;

    list = (ActorList *)&D_80145040;
    snapshot = &D_8010BC40;
    for (i = 0; i < list->count; i++, list = (ActorList *)&D_80145040) {
        actor = &list->actors[i];
        actor->block = snapshot->blocks[i];
        if (snapshot->mode == 1) {
            actor->position = snapshot->positions[i];
            actor->field6C = snapshot->values[i];
            actor->id = func_8028B394_de(&D_8011FE88, snapshot->handles[i]);
        }
    }
}

void func_80264CB8_de(void) {
    Snapshot *p = &D_8010BC40;
    s32 v = p->countdown;
    if (v != 0) {
        v = v - 1;
        p->countdown = v;
        if (v == 0) {
            p->mode = 0;
        }
    }
}

void func_80264CE0_de(void) {
    s32 i;
    ActorRecAt5E0 *actor;
    Snapshot *snapshot;
    ActorList *list;

    list = (ActorList *)&D_80145040;
    snapshot = &D_8010BC40;
    for (i = 0; i < list->count; i++) {
        actor = &list->actors[i];
        snapshot->blocks[i] = actor->block;
        snapshot->positions[i] = actor->position;
        snapshot->values[i] = actor->field6C;
        snapshot->handles[i] = func_8028B350_de(&D_8011FE88, actor->id);
        list = (ActorList *)&D_80145040;
    }
}

/** Initialize a three-word record with a value and two zero words. */
void func_80264DE0_de(unsigned int *record, unsigned int value) {
    record[0] = value;
    record[1] = 0;
    record[2] = 0;
}

s32 func_80264DF0_de(void *arg0) {
    PlayerRecAt8 *player = arg0;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 type;
    SampledCurve *curve;

    curve = player->curve;
    type = curve->type;
    switch (type) {
    case 0: {
        f32 divisor = D_80142C38[1];
        temp_f1 = player->time + (D_800C4310_de.unk0 / divisor);
        player->time = temp_f1;
        if (curve->length <= temp_f1) {
            return 1;
        }
        goto block_7;
    }
    case 1: {
        RandomCurve *random = (void *)curve;
        f32 divisor = D_80142C38[1];
        temp_f1_2 = player->time - (D_800C4314_de.unk0 / divisor);
        player->time = temp_f1_2;
        if (temp_f1_2 <= 0.0f) {
            player->time =
                temp_f1_2 + random->period;
            player->value = func_80274A90_de(
                (f32)random->minimum * D_800C4318_de.unk0,
                (f32)random->maximum * D_800C4318_de.unk0);
        }
        goto block_7;
    }
    default:
block_7:
        return 0;
    }
}

/* Samples a curve at the player's time: a byte-sample curve (type 0) indexes its samples by time times 16 over the curve length and scales the byte to 0..1, a constant curve (type 1) returns the player's value, and any other type yields zero. */





float func_80264EE0_de(PlayerRecAt8 *p) {
    SampledCurve *c = p->curve;

    switch (c->type) {
    case 0:
        return c->samples[(int)(p->time * 16.0f / c->length)] * (1.0f / 255.0f);
    case 1:
        return p->value;
    }
    return 0.0f;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_80264EFC[1] = {
    0x00009666,
};
#endif

#if defined(VERSION_EU)
unsigned int func_80264EE0_de_padding_65B1C[1] = {
    0x00000000,
};
#endif
