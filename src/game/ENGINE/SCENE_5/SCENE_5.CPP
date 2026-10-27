#include "include_asm.h"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "COMMON/MANAGER.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/SCENERECAT10C0.H"
#include "COMMON/COLORENTRY.H"
#include "ENGINE/SCENE_7.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "ENGINE/SCENE_14.H"
#include "SCENE/802508E0_4.H"
#include "SYSTEM_3/80265370.H"
#include "RENDER_4/8028FD2C_6.H"
#include "COMMON/EXTERNS_8.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "sdk/SCHED/world_actorscan.H"

/* SCENE_14.CPP */

extern s32 SetN64_GetDirectoryEntry(s32 *arg0, s32 arg1, s32 arg2);

extern s32 func_80254284_de(s32 arg0, s32 *arg1, s32 arg2, void *arg3);

extern void **func_80254408_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern void Scene_ReleaseCachedLevelData(Shared_World *arg0);

extern s32 SetN64_LocatePackSection(s32, s32, s32, s32 *);

extern s32 D_00285160;

extern void Cache_UnlockResource(s32 arg0, s32 arg1);

s32 SetN64_CollectVisibleEffectNodes(s32, s32);

/* Advances the fractional animation clock and updates every active object with the resulting tick flag. */

extern void StaticInstance_DispatchAttachmentEvents(s32, s32);

/* Releases the resource of each of the owner's listed entries through Cache_UnlockResource, then clears the counters at 0x944, 0xC4C and 0x10BC, and moves the entry count to 0x1500 and zeroes it. */

void *Scene_GetPlatformRoutePoint(void *a, s32 b, s32 c) {
    void *r1;
    ResidentDataChunk *r2;
    s32 field;

    r1 = SetN64_GetPackSection(((Shared_World *)a)->routeCount, b);
    r2 = SetN64_GetPackSection(r1, 1);
    field = r2->width;
    return r2->data + (c * field);
}

s32 Scene_FindNearestRouteFrame(void *arg0, s32 arg1, void *arg2) {
    CVector3 position;
    AnimationPoseFrameSet *list;
    Shared_World *world = arg0;
    AnimationPoseFrame *item;
    f32 distSq;
    f32 bestDist;
    f32 bestIndex;
    s32 count;
    s32 index;

    bestIndex = D_800C5300_de;
    bestDist = 0.0f;
    index = 0;
    list = SetN64_GetPackSection(SetN64_GetPackSection(world->routeCount, arg1), 1);
    count = list->count;
    item = list->frames;
    if (count > 0) {
        do {
            GraphU64_SubtractVectors(&position, arg2, item);
            distSq = (position.x * position.x) +
                     (position.y * position.y) +
                     (position.z * position.z);
            if ((bestIndex < 0.0f) || (distSq < bestDist)) {
                bestIndex = (f32)index;
                bestDist = distSq;
            }
            index += 1;
            item++;
        } while (index < count);
    }
    return (s32)bestIndex;
}

void Scene_CopyLevelName(Shared_World *world, s32 type, void *levelName, s32 arg3) {
    s32 specialTable;
    s32 tempv0;
    s32 temps2;
    CachedResource *node;
    s32 count;

    tempv0 = SetN64_GetDirectoryEntry(world->resourceDirectory, world->resourceBank, type);
    temps2 = func_80254284_de(0, &specialTable, tempv0, g_levelIndexText);
    node = func_80254408_de(0, specialTable, 8, tempv0, (s32)world, 0, &D_800C5280_de + 4);
    count = node->unk04;
    if (arg3 < count) {
        count = arg3;
    }
    func_802BD3A0_de(levelName, node->data, count);
    Cache_ReleaseResource(0, (s32)node);
    if (world->level != type) {
        Cache_ReleaseResource(0, temps2);
    }
}

void *Scene_GetBlLevelData(void *world, s32 record) {
    s32 sp28;
    void **resource;
    s32 key;
    s32 size;
    s32 one;

    if (((struct MeasuredRecAt14V2 *)(world))->value == 0 || ((struct MeasuredCode8028B64C *)(world))->value != record) {
        Scene_ReleaseCachedLevelData(world);
        if (((struct MeasuredRecAtCV3 *)(world))->value != 0) {
            size = 0x10;
            one = 1;
            resource = Cache_RequestResource(0, ((struct MeasuredRecAtCV3 *)(world))->value,
                                     ((struct MeasuredRecAtCV3 *)(world))->value,
                                     ((struct MeasuredRecAt10V2 *)(world))->value, size, 0, 0,
                                     D_800C5290_de, one);
            if (resource != 0) {
                key = SetN64_LocatePackSection((s32)*resource, ((struct MeasuredRecAtCV3 *)(world))->value,
                                    record, &sp28);
                Cache_ReleaseResource(0, resource);
                if ((((struct MeasuredRecAt14V6 *)(world))->value =
                     Cache_RequestResource(0, key, key, sp28, size, 0,
                                   &D_00285160, D_800C52BC, one)) != 0) {
                    ((struct MeasuredCode8028B64C *)(world))->value = record;
                } else {
                    return 0;
                }
            }
        }
    }
    if (((struct MeasuredRecAt14V6 *)(world))->value != 0) {
        return *((struct MeasuredRecAt14V5 *)(world))->value;
    }
    return 0;
}

void Scene_ReleaseCachedGeometry(void *arg0) {
    SceneSceneDrawCachedOpaqueGeometry *object = arg0;
    s32 *list;
    s32 val;

    if (object->loaded != 0) {
        list = (s32 *) SetN64_GetPackSection(object->model, 0);
        if (*list != 0) {
            do {
                val = *list;
                list += 1;
                Cache_UnlockResource(0, val);
            } while (*list != 0);
        }
        Cache_ReleaseResource(0, object->loaded);
        object->loaded = 0;
        object->model = 0;
    }
}

void Scene_CollectVisibleEffects(s32 arg0) {
    SetN64_CollectVisibleEffectNodes(arg0 + 0x11778, arg0);
}

/** Clear the object field at offset 0x10BC. */
void Scene_ClearTransparentInstanceCount(void *object) {
    ObjRecAt10BC *record = object;
    record->unk10BC = 0;
}

/** Clear the scene counters and linked state fields. */
void Scene_ClearSceneObjectCounts(void *object) {
    ((Shared_World *)object)->interactiveCount = 0;
    ((Shared_World *)object)->moverCount = 0;
    ((Shared_World *)object)->queuedCount = 0;
    ((Shared_World *)object)->registeredCount = 0;
    ((Shared_World *)object)->kind1Count = 0;
    ((Shared_World *)object)->flaggedCount = 0;
    ((Shared_World *)object)->kind5Count = 0;
    ((Shared_World *)object)->model64FCount = 0;
    ((Shared_World *)object)->model64DCount = 0;
    ((Shared_World *)object)->drawableCount = 0;
    ((Shared_World *)object)->sectorCount = 0;
}

void Scene_UpdateStaticEventInstances(StateSceneUpdateStaticEventInstances *arg0)
{
  f32 temp_f1;
  s32 temp_a0;
  int first_index;
  s32 var_s0;
  s32 var_s3;

  temp_f1 = arg0->unk1B31C + 1.0f;
  arg0->unk1B31C = temp_f1;
  var_s3 = 1;
  if (!(temp_f1 > 0.0f))
  {
    var_s3 = 0;
  }
  if (var_s3 != 0)
  {
    arg0->unk1B31C = (f32) (temp_f1 - ((f32) (((s32) temp_f1) + 1)));
  }
  var_s0 = (first_index = 0);
  if (arg0->unkC4C > first_index)
  {
    do
    {
      temp_a0 = arg0->values[var_s0];
      StaticInstance_DispatchAttachmentEvents(temp_a0, var_s3);
      var_s0 += 1;
    }
    while (var_s0 < arg0->unkC4C);
  }
}

s32 Scene_GetLevelActorIndex(void *container, void *arg1) {
    Container *scene = container;
    LevelActor *actor = arg1;
    void *base;

    if (actor->flags & 0x80000) {
        return -1;
    }
    base = scene->unk138;
    if (arg1 >= base &&
        (char *)arg1 <= (char *)base + ((u32)scene->unk140 * 0x2E8 - 0x2E8)) {
        return ((u32)arg1 - (u32)base) / 0x2E8;
    }
    return -1;
}

void Scene_FindSelectedTriggerRange(char *world, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4) {
    s32 sp18;
    s32 sp1C;
    s32 field0;
    s32 field1;
    s32 offset;

    if (arg1 != 0) {
        field0 = (s32)((Shared_World *)world)->alternateRecordIndex;
        field1 = ((Shared_World *)world)->alternateRecordCount;
    } else {
        field0 = (s32)((Shared_World *)world)->recordIndex;
        field1 = ((Shared_World *)world)->recordCount;
    }
    if (func_80265550_de(field0, field1, arg2, &sp18, &sp1C) != 0) {
        offset = sp18 * 0x14;
        if (arg1 != 0) {
            *arg3 = (s32)((Shared_World *)world)->alternateRecordArray + offset;
        } else {
            *arg3 = (s32)((Shared_World *)world)->recordArray + offset;
        }
        *arg4 = (sp1C - sp18) + 1;
    } else {
        *arg3 = 0;
        *arg4 = 0;
    }
}

void Scene_UnlockActiveSectionResources(OwnerSceneUnlockActiveSectionResources *owner) {
    s32 i;
    s32 n;
    s32 count;
    Triple *entries;

    n = owner->count;
    entries = owner->entries;
    for (i = 0; i < n; i++) {
        Cache_UnlockResource(0, entries[i].x);
    }
    count = owner->count;
    owner->unk944 = 0;
    owner->unkC4C = 0;
    owner->unk10BC = 0;
    owner->count = 0;
    owner->prevCount = count;
}

void Scene_ResetTransitionViewport(void) {
    s32 var_a0;
    s32 var_a1;

    func_80245A20_de(0);
    Cinema_SetResponse(D_800C5338_de);
    var_a0 = 0x1E0;
    if (D_800E28D8 == 0) {
        var_a0 = 0x17C;
        var_a1 = 0xDC;
    } else {
        var_a1 = 0x168;
    }
    func_80245A5C_de(var_a0, var_a1, 0, 0);
}

void Scene_CacheBlLevelData(void *world, s32 arg1) {
    s32 sp28;
    void **resource;
    s32 key;
    s32 size;
    s32 one;

    if (((struct MeasuredRecAt14V2 *)(world))->value == 0 || ((struct MeasuredCode8028B64C *)(world))->value != arg1) {
        Scene_ReleaseCachedLevelData(world);
        if (((struct MeasuredRecAtCV3 *)(world))->value != 0) {
            size = 0x10;
            one = 1;
            resource = Cache_RequestResource(0, ((struct MeasuredRecAtCV3 *)(world))->value,
                                     ((struct MeasuredRecAtCV3 *)(world))->value,
                                     ((struct MeasuredRecAt10V2 *)(world))->value, size, 0, 0,
                                     D_800C5290_de, one);
            if (resource != 0) {
                key = SetN64_LocatePackSection((s32)*resource, ((struct MeasuredRecAtCV3 *)(world))->value,
                                    arg1, &sp28);
                Cache_ReleaseResource(0, resource);
                if ((((struct MeasuredRecAt14V6 *)(world))->value =
                     Cache_RequestResource(0, key, key, sp28, size, 0,
                                   &D_00285160, D_800C52BC, one)) != 0) {
                    ((struct MeasuredCode8028B64C *)(world))->value = arg1;
                }
            }
        }
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_800CD64C[3] = {
    0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800CD658[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800CECEC[3] = {
    0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800CECF8[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800CE31C[3] = {
    0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800CE328[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800CD73C[3] = {
    0x3F800000, 0x3F800000, 0x3F800000,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800CD748[1] = {
    0x00000000,
};
#endif

/* 8028B64C_9.CPP */
extern void SetN64_GetPackSectionSize(s32 arg0, s32 arg1);

void Scene_ReleaseCachedLevelData(Shared_World *world) {
    void *handle;

    handle = world->resourceHandle;
    if (handle != 0) {
        Cache_ReleaseResource(0, handle);
        world->resourceHandle = 0;
        world->resourceKey = -1;
    }
}

void Scene_AccessLevelStateSection(struct WorldSceneDispatchEnabledEntityTrigger *arg0, s32 arg1, s32 index, s32 arg3) {
    void *base;
    void *table;

    if (arg1 != 0) {
        base = arg0->levels;
    } else {
        base = arg0->secondaryLevels;
    }
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(base, 0), arg3), index);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    SetN64_GetPackSection(table, 1);
}

void Scene_SetSelectedLevelStateBit(struct WorldSceneDispatchEnabledEntityTrigger *arg0, s32 arg1, s32 index, s32 arg3, s32 arg4, s32 arg5) {
    void *base;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 mask;
    s32 idx;
    s32 idx2;

    if (arg1 != 0) {
        base = arg0->levels;
    } else {
        base = arg0->secondaryLevels;
    }
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(base, 0), arg3), index);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (arg4 & 7);
    if (arg5 != 0) {
        idx = arg4;
        if (arg4 < 0) {
            idx = arg4 + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = arg4;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

s32 Scene_TestSelectedLevelStateBit(struct WorldSceneDispatchEnabledEntityTrigger *arg0, s32 arg1, s32 index, s32 arg3, s32 arg4) {
    void *base;
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    if (arg1 != 0) {
        base = arg0->levels;
    } else {
        base = arg0->secondaryLevels;
    }
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(base, 0), arg3), index);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg4 & 7);
    i = arg4;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 Scene_TestSecondaryLevelBit(void *arg0, s32 index, s32 arg2) {
    Shared_World *world = arg0;
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(world->secondaryLevels, 0), index), 0);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 Scene_TestActorBitForLevel(Field_void_80 *arg0, s32 index, s32 arg2) {
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(arg0->value, 0), index), 0);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 Scene_TestRecordBitForLevel(Field_void_80 *arg0, s32 index, s32 arg2) {
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(arg0->value, 0), index), 1);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

s32 Scene_TestTriggerBitForLevel(Field_void_80 *arg0, s32 index, s32 arg2) {
    void *table;
    u8 *temp_a0;
    s32 mask;
    s32 i;

    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(arg0->value, 0), index), 2);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32)table, 1);
    temp_a0 = (u8 *)SetN64_GetPackSection(table, 1);
    mask = 1 << (arg2 & 7);
    i = arg2;
    if (i < 0) {
        i += 7;
    }
    return (temp_a0[i >> 3] & mask) != 0;
}

/* world_actorscan.CPP */
s32 Scene_GetTriggerCounterAddress(Shared_World *world, s32 arg1) {
    void *temp_v0;
    temp_v0 = SetN64_GetPackSection(world->bitSections, 1);
    SetN64_GetPackSection(temp_v0, 0);
    return SetN64_GetPackSection(temp_v0, 1) + arg1;
}

void Scene_SwapDistanceSortEntries(WorldSortEntry *arg0, WorldSortEntry *arg1) {
    WorldSortEntry tmp;

    tmp = *arg0;
    *arg0 = *arg1;
    *arg1 = tmp;
}

s32 Scene_CompareDistanceAscending(WorldSortEntry *arg0, WorldSortEntry *arg1) {
    s32 result;
    result = 1;
    if ((arg0->distance) < (arg1->distance)) {
        result = -1;
    }
    return result;
}

s32 Scene_CompareDistanceDescending(WorldSortEntry *arg0, WorldSortEntry *arg1)
{
  f32 new_var;
  s32 var_v0;
  new_var = arg0->distance;
  var_v0 = 1;
  if ((arg1->distance) < new_var)
  {
    var_v0 = -1;
  }
  return var_v0;
}

void Scene_CollectTypeFourteenActors(Shared_World *world) {
    s32 found;
    s32 clear_index;
    LevelActor *record;
    struct Shared_Pickup **clear_ptr;
    struct Shared_Pickup **out;
    s32 wanted_type;

    found = 0;
    clear_index = 15;
    record = world->actors;
    world->specialActorCount = 0;
    do {
        world->specialActors[clear_index] = 0;
        clear_index--;
    } while (clear_index >= 0);

    if (world->actorCount > 0) {
        clear_index = 0;
        wanted_type = 14;
        do {
            if (((struct Def *)record->definition)->type == wanted_type) {
                world->specialActors[found] = record;
                found++;
            }
            if (found >= 16) {
                break;
            }
            clear_index++;
            if (clear_index >= world->actorCount) {
                break;
            }
            record++;
        } while (1);
    }
    world->specialActorCount = found;
}

extern LevelActor *D_800F3CF8[4];
extern LevelActor *D_800F3D08;
extern s32 Scene_GetModelIdAtIndex(Shared_World *world, s32 id);
void Scene_FindTrackedActors(Shared_World *world) {
    LevelActor *actor = world->actors;
    s32 i;
    D_800F3D08 = 0;
    for (i = 0; i < 4; i++) {
        D_800F3CF8[i] = 0;
    }
    for (i = 0; i < world->actorCount; actor++, i++) {
        struct Def *def = (struct Def *)actor->definition;
        if (def->type == 3) {
            if (Scene_GetModelIdAtIndex(&g_world, def->id) == 0xBD7) {
                D_800F3D08 = actor;
                return;
            }
        } else if (def->type == 10) {
            switch (actor->type) {
            case 0x653:
                D_800F3CF8[0] = actor;
                break;
            case 0x654:
                D_800F3CF8[1] = actor;
                break;
            case 0x655:
                D_800F3CF8[2] = actor;
                break;
            case 0x656:
                D_800F3CF8[3] = actor;
                break;
            }
        }
    }
}
