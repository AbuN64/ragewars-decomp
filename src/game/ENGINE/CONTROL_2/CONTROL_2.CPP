#include "include_asm.h"
#include "COMMON/LONE/D_8010EC90.H"
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

/* 80263760_8.CPP */
extern void Rumble_FreeAllPoolNodes(s32 *);

/* Advances the replay mode: when replays are possible (SetN64_IsModeThirteen, D_80145070 and the handle table) it
 * cycles the mode 0 -> 1 -> 2 -> 0, snapshots the actors and records the camera target, promoting mode 1
 * to 2 when the player's target changed or the player is in states 0x16 to 0x21 and recording the player's
 * target instead; otherwise the mode is cleared. An active mode arms the 240-frame timer. */

extern s32 D_8013B2BC;

extern void *Player_GetFirstPlayer(void *);

/** Return the global word at D_8010FC4C. */

/** Clear the global word at VRAM 0x8010FC40. */

/* Restores every actor from the global replay table: copies its 0x70-byte block back to 0x5E0 and, when
 * the table's mode is 1, also restores its position, its value at 0x6C and its identifier resolved from the
 * saved handle through Scene_GetModelSectionTwoRecord. Adapted from the snapshot writer Control_SaveActorSnapshot, reading both tables
 * through local pointers and re-taking the actor list address in the loop increment. */

extern s32 Scene_GetModelSectionTwoIndex(Shared_World *table, s32 id);

const unsigned int D_d0_0d3281030ce1b896[3] = {
    0x3F800000, 0x3F800000, 0x3B808081,
};
void Control_SetProfileMode(ControllerProfile *slot, s32 profileMode) {
    slot->mode = profileMode;
    if (profileMode == 0) {
        Control_ResetControllerPak(slot);
    }
}

void Control_ResetControllerProfiles(void) {
    ControllerProfile *slot;
    s32 i;

    i = 0;
    slot = D_8010F328;
    do {
        Control_ResetControllerPak(slot);
        i += 1;
        slot += 1;
    } while (i < 4);
}

void Control_SetControllerMode(s32 a) {
    ControllerProfile *slot;
    s32 i;

    i = 0;
    slot = D_8010F328;
    do {
        slot->mode = a;
        if (a == 0) {
            Control_ResetControllerPak(slot);
        }
        i += 1;
        slot += 1;
    } while (i < 4);
    if (a == 0) {
        Rumble_FreeAllPoolNodes(&D_8010EC90);
    }
}

void Control_SaveControllerSetup(void)
{
  s32 savedValueOffset;
  s32 profileValue;
  s32 profileIndex;
  s32 profileByteOffset;
  s32 profilesReset;
  ControllerProfile *profileCursor;
  profileIndex = 0;
  profileByteOffset = 0;
  do
  {
    profileValue = *((s32 *) ((&D_8010B3F4) + profileByteOffset));
 do { savedValueOffset = profileIndex * 4; profileIndex += 1; *((s32 *) (((u8 *) D_8010BC18) + savedValueOffset)) = profileValue; profileByteOffset += 0x224; } while (0);
  }
  while (profileIndex < 4);
  profilesReset = 0;
  Rumble_FreeAllPoolNodes(&D_8010EC90);
  profileCursor = D_8010F328;
  do
  {
    Control_ResetControllerPak(profileCursor);
    profilesReset += 1;
    profileCursor += 1;
  }
  while (profilesReset < 4);
  D_800CBC18 = 1;
}

void Control_RestoreControllerSetup(void) {
    ControllerProfile *slot;
    s32 i;
    s32 j;
    s32 profileByteOffset;
    s32 savedProfileValue;

    if (D_800CBC18 != 0) {
        i = 0;
        slot = D_8010F328;
        do {
            Control_ResetControllerPak(slot);
            i += 1;
            slot += 1;
        } while (i < 4);
        j = 0;
        profileByteOffset = 0;
        do {
            savedProfileValue = D_8010BC18[j];
            j += 1;
            *(s32 *)(&D_8010B3F4 + profileByteOffset) = savedProfileValue;
            profileByteOffset += 0x224;
        } while (j < 4);
        Rumble_FreeAllPoolNodes(&D_8010EC90);
        D_800CBC18 = 0;
    }
}

void func_802649FC_de(void) {
    D_800CBC20 = 0;
}

void func_80264A0C_de(void) {
    D_800CBC20 = 1;
}

void Control_CycleActorSnapshotMode(void) {
    Snapshot *snapshot;
    void *player;
    s32 enabled;
    Shared_Game *options;

    enabled = SetN64_IsModeThirteen() != 0;
    snapshot = &D_8010BC40;
    if (D_80145070 == 0) {
        enabled = 0;
    }
    if (&g_world.mode == 0) {
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
        Control_SaveActorSnapshot();
        snapshot->savedActorId = D_8013B2BC;
        options = &D_80145040.game;
        if (options->local == 0) {
            player = Player_GetFirstPlayer(&D_80145040);
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

void Control_ResetActorSnapshot(void) {
    D_8010BC40.active = 0;
    D_8010BC40.mode = 0;
    D_8010BC40.countdown = 0;
}

s32 Control_GetSnapshotActorId(void) {
    return D_8010BC40.savedActorId;
}

int Control_IsSnapshotActive(void) {
    return D_8010BC40.active;
}

void Control_DeactivateActorSnapshot(void) {
    D_8010BC40.active = 0;
}

void Control_RestoreActorSnapshot(void) {
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
            actor->id = Scene_GetModelSectionTwoRecord(&g_world, snapshot->handles[i]);
        }
    }
}

void Control_TickSnapshotCountdown(void) {
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

void Control_SaveActorSnapshot(void) {
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
        snapshot->handles[i] = Scene_GetModelSectionTwoIndex(&g_world, actor->id);
        list = (ActorList *)&D_80145040;
    }
}

/** Initialize a three-word record with a value and two zero words. */
void Control_InitializeCurvePlayer(unsigned int *record, unsigned int value) {
    record[0] = value;
    record[1] = 0;
    record[2] = 0;
}

s32 Control_AdvanceEffectCurve(void *arg0) {
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
            player->value = GraphU64_RandomBetween(
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

float Control_SampleEffectCurve(PlayerRecAt8 *p) {
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

/* 800C9400.CPP */
