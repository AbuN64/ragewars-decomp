#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/PACKED.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "TYPES.H"
#include "SYSTEM/80265370.H"
#include "COMMON/APPROACHLOCATION.H"
extern s32 SetN64_LocatePackSection(void *arg0, s32 arg1, s32 arg2, s32 *arg3);

extern void SetN64_SpawnModelEffect(s32, s32, s32, Triple, Triple, s32, f32);


extern f32 Region_GetPolygonHeight(void *, f32, f32);

extern f32 Graphu64_GetTrianglePlaneHeight(void *arg0, f32 arg1, f32 arg2);

extern s32 SetN64_GetDirectoryEntry(s32 *arg0, s32 arg1, s32 arg2);

extern void Link_ActivateTrigger(void *arg0);

void Scene_SpawnUnrotatedEffect(s32 worldAddress, s32 ownerId, Triple position, s32 modelId, f32 lifetime) {
    Triple zero;

    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    SetN64_SpawnModelEffect(worldAddress + 0x11778, 0, modelId, zero, position, ownerId, lifetime);
}

void *Scene_ResolveFloorPolygon(void *triangle, CVector3 *position) {
    f32 lower;
    f32 upper;
    f32 value;

    if (triangle != 0 &&
        Region_IsPointInTriangleXZ(triangle, position->x,
                          position->z) != 0) {
        if (!(((Triangle *)triangle)->flags & 0x40)) {
            return triangle;
        }
        lower = Region_GetPolygonHeight(triangle,
            position->x, position->z);
        upper = Graphu64_GetTrianglePlaneHeight(triangle,
            position->x, position->z);
        value = position->y;
        if (lower <= value && value <= upper) {
            return triangle;
        }
    }
    return Scene_FindFloorPolygon(&g_world, position);
}

/* Searches the counted pointer list at offset 0x1B620 of a world record for the first entry whose definition id at 0x18->0xC equals the given id, returning it or null. */







EntryRecAt18V4 *Scene_FindSwitchByDefinitionId(World *world, s32 id) {
    s32 i;
    EntryRecAt18V4 *found = 0;

    for (i = 0; i < world->count; i++) {
        if (world->list[i]->def->unkC == id) {
            found = world->list[i];
            break;
        }
    }
    return found;
}

void Scene_LocateTextureResource(void *arg0, s32 arg1, s32 *arg2, s32 *sectionSizeOut) {
    *arg2 = SetN64_LocatePackSection((((struct IntegerState54 *) ((s8 *) arg0))->unk_50), (((struct IntegerState54 *) ((s8 *) arg0))->unk_20), arg1, sectionSizeOut);
}

s32 Scene_GetIndexedModelResource(Shared_World *world, s32 type) {
    s32 *directory = world->indexedDirectory;

    if (type < *directory) {
        return SetN64_GetDirectoryEntry(directory, world->indexedBank, type);
    }
    return 0;
}

s32 Scene_FindAlternateTriggerRange(char *world, u16 *arg1, s32 *arg2, s32 *arg3) {
    s32 sp18;
    s32 sp1C;
    s32 matchCount;
    s32 field_cc;
    s32 field_c4;

    matchCount = Defs_FindSortedGroupRange(field_cc, field_c4, *arg1,
        (field_cc = (s32)((Shared_World *)world)->alternateRecordIndex,
         field_c4 = ((Shared_World *)world)->alternateRecordCount, &sp18), &sp1C);
    if (matchCount != 0) {
        *arg2 = (s32)((Shared_World *)world)->alternateRecordArray + (sp18 * 0x14);
        matchCount = (sp1C - sp18) + 1;
        *arg3 = matchCount;
    } else {
        *arg2 = 0;
        *arg3 = 0;
    }
    return matchCount;
}

void Scene_FindActorTriggerRange(char *world, void *levelActor, s32 *arg2, s32 *arg3) {
    s32 sp18;
    s32 last;
    s32 index;
    u32 first;
    s32 lastOffset;
    s32 temp_v0;
    s32 field_c8;
    s32 field_c0;

    if (!(((LevelActor *)levelActor)->flags & 0x80000)) {
        first = (u32)((Shared_World *)world)->actors;
        index = -1;
        if ((u32)levelActor >= first) {
            lastOffset = ((Shared_World *)world)->actorCount * 0x2E8;
            lastOffset -= 0x2E8;
            if (first + lastOffset >= (u32)levelActor) {
                index = ((u32)levelActor - first) / 0x2E8;
            }
        }
    } else {
        index = -1;
    }
    if (index == -1) {
        *arg3 = 0;
        return;
    }
    temp_v0 = Defs_FindSortedGroupRange(field_c8, field_c0, index,
        (field_c8 = (s32)((Shared_World *)world)->recordIndex,
         field_c0 = ((Shared_World *)world)->recordCount, &sp18), &last);
    if (temp_v0 != 0) {
        *arg2 = (s32)((Shared_World *)world)->recordArray + (sp18 * 0x14);
        *arg3 = (last - sp18) + 1;
    } else {
        *arg2 = 0;
        *arg3 = 0;
    }
}

void Scene_ActivateTriggersOfKind(Shared_World *world, s32 arg1) {
    s32 primaryRemaining;
    s32 alternateRemaining;
    Record14 *trigger;
    Record14 *alternateTrigger;

    primaryRemaining = world->recordCount;
    trigger = world->recordArray;
    primaryRemaining -= 1;
    if (primaryRemaining != -1) {
        do {
            if (trigger->kind == arg1) {
                Link_ActivateTrigger(trigger);
            }
            primaryRemaining -= 1;
            trigger = trigger + 1;
        } while (primaryRemaining != -1);
    }
    alternateTrigger = world->alternateRecordArray;
    alternateRemaining = world->alternateRecordCount;
    alternateRemaining -= 1;
    if (alternateRemaining != -1) {
        do {
            if (alternateTrigger->kind == arg1) {
                Link_ActivateTrigger(alternateTrigger);
            }
            alternateRemaining -= 1;
            alternateTrigger = alternateTrigger + 1;
        } while (alternateRemaining != -1);
    }
}

s32 Scene_TestTriggerKindFlags(char *object, s32 type) {
    s32 index;
    Record14 *record;
    u8 *flags;

    index = ((Shared_World *)object)->recordCount;
    record = ((Shared_World *)object)->recordArray;
    index--;
    if (index != -1) {
        flags = &record->flags;
        do {
            if (flags[1] == type &&
                (*flags & 0x40) == 0) {
                return 0;
            }
            index--;
            flags += sizeof(Record14);
        } while (index != -1);
    }

    index = ((Shared_World *)object)->alternateRecordCount;
    record = ((Shared_World *)object)->alternateRecordArray;
    index--;
    if (index != -1) {
        do {
            if (record->kind == type &&
                (record->flags & 0x40) == 0) {
                return 0;
            }
            index--;
            record++;
        } while (index != -1);
    }

    return 1;
}
