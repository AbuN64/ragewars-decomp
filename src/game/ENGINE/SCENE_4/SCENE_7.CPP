#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "ENGINE/SCENE_7.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

extern void SetN64_GetPackSectionSize(s32 arg0, s32 arg1);

void Scene_SetLevelActorStateBit(void *arg0, s32 index, s32 arg2, s32 arg3) {
    void *entry;
    struct Def *cond;
    void *field80;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    if (((Shared_World *)arg0)->mode == 2) {
        return;
    }
    if (((Shared_World *)arg0)->level == index) {
        entry = (char *)((SceneRecAt140 *)arg0)->actors + (s32) arg2 * 0x2E8;
        cond = (struct Def *)((LevelActor *)entry)->definition;
        if ((u32) (cond->type - 9) < 2) {
            if (cond->flags & 0x200) {
                return;
            }
        }
    }
    field80 = ((Shared_World *)arg0)->bitSections;
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(field80, 0), (s32) index), 0);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (arg2 & 7);
    if (arg3 != 0) {
        idx = arg2;
        if ((s32) arg2 < 0) {
            idx = arg2 + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = arg2;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

void Scene_SetRecordBitForLevel(Field_void_80 *worldState, s32 index, s32 recordBitIndex, s32 enabled) {
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(worldState->value, 0), index), 1);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (recordBitIndex & 7);
    if (enabled != 0) {
        idx = recordBitIndex;
        if (recordBitIndex < 0) {
            idx = recordBitIndex + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = recordBitIndex;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

void Scene_SetLevelRecordStateBit(void *arg0, struct LevelBitRecord *levelBitRecord, s32 arg2) {
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    bitIndex = levelBitRecord->bitIndex;
    field80 = ((WorldSceneDispatchEnabledEntityTrigger *)(arg0))->levels;
    field1B40C = ((WorldSceneDispatchEnabledEntityTrigger *)(arg0))->level;
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(field80, 0), field1B40C), 1);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (bitIndex & 7);
    if (arg2 != 0) {
        idx = bitIndex;
        if (bitIndex < 0) {
            idx = bitIndex + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = bitIndex;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

s32 Scene_TestLevelRecordStateBit(void *world, struct LevelBitRecord *levelBitRecord) {
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *table;
    u8 *recordBits;
    s32 mask;

    bitIndex = levelBitRecord->bitIndex;
    field80 = ((WorldSceneDispatchEnabledEntityTrigger *)(world))->levels;
    field1B40C = ((WorldSceneDispatchEnabledEntityTrigger *)(world))->level;
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(field80, 0), field1B40C), 1);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    recordBits = (u8 *) SetN64_GetPackSection(table, 1);
    mask = 1 << (bitIndex & 7);
    if (bitIndex < 0) {
        bitIndex += 7;
    }
    return (recordBits[bitIndex >> 3] & mask) != 0;
}

void Scene_SetTriggerBitForLevel(Field_void_80 *worldState, s32 index, s32 triggerBitIndex, s32 enabled) {
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(worldState->value, 0), index), 2);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (triggerBitIndex & 7);
    if (enabled != 0) {
        idx = triggerBitIndex;
        if (triggerBitIndex < 0) {
            idx = triggerBitIndex + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = triggerBitIndex;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

void Scene_SetTriggerStateBit(void *world, void *trigger, s32 arg2) {
    struct ItemRecAt12 *item = trigger;
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    bitIndex = item->bitIndex;
    field80 = ((WorldSceneDispatchEnabledEntityTrigger *)(world))->levels;
    field1B40C = ((WorldSceneDispatchEnabledEntityTrigger *)(world))->level;
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(field80, 0), field1B40C), 2);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (bitIndex & 7);
    if (arg2 != 0) {
        idx = bitIndex;
        if (bitIndex < 0) {
            idx = bitIndex + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = bitIndex;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

s32 Scene_TestTriggerStateBit(Shared_World *world, void *trigger) {
    s32 bitIndex;
    void *field80;
    s32 field1B40C;
    void *table;
    u8 *temp_a0;
    s32 mask;

    bitIndex = ((Record14 *)trigger)->reserved13;
    field80 = world->bitSections;
    field1B40C = world->level;
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(field80, 0), field1B40C), 2);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    temp_a0 = (u8 *) SetN64_GetPackSection(table, 1);
    mask = 1 << (bitIndex & 7);
    if (bitIndex < 0) {
        bitIndex += 7;
    }
    return (temp_a0[bitIndex >> 3] & mask) != 0;
}

/* Finds an identifier in the object's list and returns its mapped byte from the resource record, or -1 when absent. */
s32 Scene_GetTriggerCounterById(ObjectRecAtB0 *counterOwner, s32 counterId) {
    s32 i;
    void *record;
    Table *list = counterOwner->list;
    s32 count = list->unk4;
    s32 *ids = list->deltas;

    for (i = 0; i < count; i++) {
        if (ids[i] == counterId) {
            record = SetN64_GetPackSection(counterOwner->resource, 1);
            SetN64_GetPackSection(record, 0);
            return ((u8 *)SetN64_GetPackSection(record, 1))[i];
        }
    }
    return -1;
}
