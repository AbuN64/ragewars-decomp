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

extern void func_80271F68_de(CVector3 *out, void *arg1, void *arg2);

extern s32 func_8028FE28_de(s32 *arg0, s32 arg1, s32 arg2);

extern s32 func_80254284_de(s32 arg0, s32 *arg1, s32 arg2, void *arg3);

extern void **func_80254408_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern void func_80253838_de(void *arg0, void *arg1);



extern void func_8028DA74_de(void *arg0);


extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);

extern s32 D_00285160;



extern void func_80253754_de(s32 arg0, s32 arg1);

s32 func_8029076C_de(s32, s32);

/* Advances the fractional animation clock and updates every active object with the resulting tick flag. */


extern void func_80250624_de(s32, s32);


/* Releases the resource of each of the owner's listed entries through func_80253754_de, then clears the counters at 0x944, 0xC4C and 0x10BC, and moves the entry count to 0x1500 and zeroes it. */





extern void func_80253754_de(s32, s32);



void *func_8028D244_de(void *a, s32 b, s32 c) {
    void *r1;
    ResidentDataChunk *r2;
    s32 field;

    r1 = func_8028FDB4_de(((Shared_World *)a)->routeCount, b);
    r2 = func_8028FDB4_de(r1, 1);
    field = r2->width;
    return r2->data + (c * field);
}

s32 func_8028D28C_de(void *arg0, s32 arg1, void *arg2) {
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
    list = func_8028FDB4_de(func_8028FDB4_de(world->routeCount, arg1), 1);
    count = list->count;
    item = list->frames;
    if (count > 0) {
        do {
            func_80271F68_de(&position, arg2, item);
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

void func_8028D380_de(Shared_World *world, s32 type, void *levelName, s32 arg3) {
    s32 specialTable;
    s32 tempv0;
    s32 temps2;
    CachedResource *node;
    s32 count;

    tempv0 = func_8028FE28_de(world->resourceDirectory, world->resourceBank, type);
    temps2 = func_80254284_de(0, &specialTable, tempv0, &D_800C5110_de);
    node = func_80254408_de(0, specialTable, 8, tempv0, (s32)world, 0, &D_800C5280_de + 4);
    count = node->unk04;
    if (arg3 < count) {
        count = arg3;
    }
    func_802BD3A0_de(levelName, node->data, count);
    func_80253838_de(0, (s32)node);
    if (world->level != type) {
        func_80253838_de(0, temps2);
    }
}

void *func_8028D474_de(void *world, s32 record) {
    s32 sp28;
    void **resource;
    s32 key;
    s32 size;
    s32 one;

    if (((struct MeasuredRecAt14V4 *)(world))->value == 0 || ((struct MeasuredCode8028B64C *)(world))->value != record) {
        func_8028DA74_de(world);
        if (((struct MeasuredRecAtCV4 *)(world))->value != 0) {
            size = 0x10;
            one = 1;
            resource = func_8025193C_de(0, ((struct MeasuredRecAtCV4 *)(world))->value,
                                     ((struct MeasuredRecAtCV4 *)(world))->value,
                                     ((struct MeasuredRecAt10V1 *)(world))->value, size, 0, 0,
                                     &D_800C5290_de, one);
            if (resource != 0) {
                key = func_8028FE3C_de((s32)*resource, ((struct MeasuredRecAtCV4 *)(world))->value,
                                    record, &sp28);
                func_80253838_de(0, resource);
                if ((((struct MeasuredRecAt14V1 *)(world))->value =
                     func_8025193C_de(0, key, key, sp28, size, 0,
                                   &D_00285160, &D_800C52BC, one)) != 0) {
                    ((struct MeasuredCode8028B64C *)(world))->value = record;
                } else {
                    return 0;
                }
            }
        }
    }
    if (((struct MeasuredRecAt14V1 *)(world))->value != 0) {
        return *((struct MeasuredRecAt14V5 *)(world))->value;
    }
    return 0;
}

void func_8028D59C_de(void *arg0) {
    Scene_func_80288EA8_de *object = arg0;
    s32 *list;
    s32 val;

    if (object->loaded != 0) {
        list = (s32 *) func_8028FDB4_de(object->model, 0);
        if (*list != 0) {
            do {
                val = *list;
                list += 1;
                func_80253754_de(0, val);
            } while (*list != 0);
        }
        func_80253838_de(0, object->loaded);
        object->loaded = 0;
        object->model = 0;
    }
}

void func_8028D61C_de(s32 arg0) {
    func_8029076C_de(arg0 + 0x11778, arg0);
}

/** Clear the object field at offset 0x10BC. */
void func_8028D644_de(void *object) {
    ObjRecAt10BC *record = object;
    record->unk10BC = 0;
}

/** Clear the scene counters and linked state fields. */
void func_8028D64C_de(void *object) {
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

void func_8028D67C_de(State_func_8028D67C_de *arg0)
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
      func_80250624_de(temp_a0, var_s3);
      var_s0 += 1;
    }
    while (var_s0 < arg0->unkC4C);
  }
}

s32 func_8028D74C_de(void *container, void *arg1) {
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

void func_8028D7C4_de(char *world, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4) {
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

void func_8028D888_de(Owner_func_8028D888_de *owner) {
    s32 i;
    s32 n;
    s32 count;
    Triple *entries;

    n = owner->count;
    entries = owner->entries;
    for (i = 0; i < n; i++) {
        func_80253754_de(0, entries[i].x);
    }
    count = owner->count;
    owner->unk944 = 0;
    owner->unkC4C = 0;
    owner->unk10BC = 0;
    owner->count = 0;
    owner->prevCount = count;
}

void func_8028D90C_de(void) {
    s32 var_a0;
    s32 var_a1;

    func_80245A20_de(0);
    func_80245A00_de(D_800C5338_de);
    var_a0 = 0x1E0;
    if (D_800E28D8 == 0) {
        var_a0 = 0x17C;
        var_a1 = 0xDC;
    } else {
        var_a1 = 0x168;
    }
    func_80245A5C_de(var_a0, var_a1, 0, 0);
}

void func_8028D964_de(void *world, s32 arg1) {
    s32 sp28;
    void **resource;
    s32 key;
    s32 size;
    s32 one;

    if (((struct MeasuredRecAt14V2 *)(world))->value == 0 || ((struct MeasuredCode8028B64C *)(world))->value != arg1) {
        func_8028DA74_de(world);
        if (((struct MeasuredRecAtCV3 *)(world))->value != 0) {
            size = 0x10;
            one = 1;
            resource = func_8025193C_de(0, ((struct MeasuredRecAtCV3 *)(world))->value,
                                     ((struct MeasuredRecAtCV3 *)(world))->value,
                                     ((struct MeasuredRecAt10V2 *)(world))->value, size, 0, 0,
                                     &D_800C5290_de, one);
            if (resource != 0) {
                key = func_8028FE3C_de((s32)*resource, ((struct MeasuredRecAtCV3 *)(world))->value,
                                    arg1, &sp28);
                func_80253838_de(0, resource);
                if ((((struct MeasuredRecAt14V6 *)(world))->value =
                     func_8025193C_de(0, key, key, sp28, size, 0,
                                   &D_00285160, &D_800C52BC, one)) != 0) {
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
