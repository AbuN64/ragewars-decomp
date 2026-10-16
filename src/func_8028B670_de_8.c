#include "span_1000/code_8028B64C.h"
#include "common/draft_fields_func_8028D474_de.h"
#include "common/draft_fields_func_8028D964_de.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/level_actor.h"
#include "shared/world.h"
#include "span_1000/code_802508E0.h"
#include "span_1000/code_80277444.h"
#include "span_1000/code_80286050.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"
#include "common/unused.h"

extern void func_80271F68_de(Vec3 *out, void *arg1, void *arg2);

extern s32 func_8028FE28_de(s32 *arg0, s32 arg1, s32 arg2);

extern s32 func_80254284_de(s32 arg0, s32 *arg1, s32 arg2, void *arg3);

extern void **func_80254408_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void *arg6);

extern void *func_802BD3A0_de(void *destination, const void *source, int count);

extern void func_80253838_de(void *arg0, void *arg1);



extern void func_8028DA74_de(void *arg0);

extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);

extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);

extern s32 D_00285160;



extern void func_80253754_de(s32 arg0, s32 arg1);

s32 func_8029076C_de(s32, s32);

/* Advances the fractional animation clock and updates every active object with the resulting tick flag. */


extern void func_80250624_de(s32, s32);

extern s32 func_80265550_de(s32, s32, s32, s32 *, s32 *);

/* Releases the resource of each of the owner's listed entries through func_80253754_de, then clears the counters at 0x944, 0xC4C and 0x10BC, and moves the entry count to 0x1500 and zeroes it. */





extern void func_80253754_de(s32, s32);



void *func_8028D244_de(void *a, s32 b, s32 c) {
    extern char *func_8028FDB4_de(s32 *, s32);
    void *r1;
    ResidentDataChunk *r2;
    s32 field;

    r1 = func_8028FDB4_de(((Shared_World *)a)->routeCount, b);
    r2 = func_8028FDB4_de(r1, 1);
    field = r2->width;
    return r2->data + (c * field);
}

s32 func_8028D28C_de(void *arg0, s32 arg1, void *arg2) {
    extern void *func_8028FDB4_de(void *arg0, s32 arg1);
    Vec3 position;
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

void func_8028D380_de(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 sp20;
    s32 tempv0;
    s32 temps2;
    CachedResource *node;
    s32 count;

    tempv0 = func_8028FE28_de(((Shared_World *)arg0)->resourceDirectory, ((Shared_World *)arg0)->resourceBank, arg1);
    temps2 = func_80254284_de(0, &sp20, tempv0, &D_800C5110_de);
    node = func_80254408_de(0, sp20, 8, tempv0, (s32)arg0, 0, &D_800C5280_de + 4);
    count = node->unk04;
    if (arg3 < count) {
        count = arg3;
    }
    func_802BD3A0_de(arg2, node->data, count);
    func_80253838_de(0, (s32)node);
    if (((Shared_World *)arg0)->level != arg1) {
        func_80253838_de(0, temps2);
    }
}

void *func_8028D474_de(void *arg0, s32 arg1) {
    s32 sp28;
    void **resource;
    s32 key;
    s32 size;
    s32 one;

    if (((struct MeasuredRecAt14V4 *)(arg0))->value == 0 || ((struct Measured_func_8028D474_de_7705078627e3 *)(arg0))->value != arg1) {
        func_8028DA74_de(arg0);
        if (((struct MeasuredRecAtCV4 *)(arg0))->value != 0) {
            size = 0x10;
            one = 1;
            resource = func_8025193C_de(0, ((struct MeasuredRecAtCV4 *)(arg0))->value,
                                     ((struct MeasuredRecAtCV4 *)(arg0))->value,
                                     ((struct MeasuredRecAt10V1 *)(arg0))->value, size, 0, 0,
                                     &D_800C5290_de, one);
            if (resource != 0) {
                key = func_8028FE3C_de((s32)*resource, ((struct MeasuredRecAtCV4 *)(arg0))->value,
                                    arg1, &sp28);
                func_80253838_de(0, resource);
                if ((((struct MeasuredRecAt14V1 *)(arg0))->value =
                     func_8025193C_de(0, key, key, sp28, size, 0,
                                   &D_00285160, &D_800C52BC, one)) != 0) {
                    ((struct Measured_func_8028D474_de_7705078627e3 *)(arg0))->value = arg1;
                } else {
                    return 0;
                }
            }
        }
    }
    if (((struct MeasuredRecAt14V1 *)(arg0))->value != 0) {
        return *((struct MeasuredRecAt14V5 *)(arg0))->value;
    }
    return 0;
}

void func_8028D59C_de(void *arg0) {
    extern void *func_8028FDB4_de(void *arg0, s32 arg1);
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
    ((Shared_World *)object)->counter944 = 0;
    ((Shared_World *)object)->counterB48 = 0;
    ((Shared_World *)object)->counterC4C = 0;
    ((Shared_World *)object)->counterE50 = 0;
    ((Shared_World *)object)->counterF54 = 0;
    ((Shared_World *)object)->counterFDC = 0;
    ((Shared_World *)object)->counter1020 = 0;
    ((Shared_World *)object)->counter10A4 = 0;
    ((Shared_World *)object)->counter10B8 = 0;
    ((Shared_World *)object)->counter10BC = 0;
    ((Shared_World *)object)->counter1504 = 0;
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

s32 func_8028D74C_de(void *arg0, void *arg1) {
    Container *scene = arg0;
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

void func_8028D7C4_de(char *arg0, s32 arg1, s32 arg2, s32 *arg3, s32 *arg4) {
    s32 sp18;
    s32 sp1C;
    s32 field0;
    s32 field1;
    s32 offset;

    if (arg1 != 0) {
        field0 = (s32)((Shared_World *)arg0)->alternateRecordIndex;
        field1 = ((Shared_World *)arg0)->alternateRecordCount;
    } else {
        field0 = (s32)((Shared_World *)arg0)->recordIndex;
        field1 = ((Shared_World *)arg0)->recordCount;
    }
    if (func_80265550_de(field0, field1, arg2, &sp18, &sp1C) != 0) {
        offset = sp18 * 0x14;
        if (arg1 != 0) {
            *arg3 = (s32)((Shared_World *)arg0)->alternateRecordArray + offset;
        } else {
            *arg3 = (s32)((Shared_World *)arg0)->recordArray + offset;
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

void func_8028D964_de(void *arg0, s32 arg1) {
    s32 sp28;
    void **resource;
    s32 key;
    s32 size;
    s32 one;

    if (((struct MeasuredRecAt14V2 *)(arg0))->value == 0 || ((struct MeasuredCode8028B64C *)(arg0))->value != arg1) {
        func_8028DA74_de(arg0);
        if (((struct MeasuredRecAtCV3 *)(arg0))->value != 0) {
            size = 0x10;
            one = 1;
            resource = func_8025193C_de(0, ((struct MeasuredRecAtCV3 *)(arg0))->value,
                                     ((struct MeasuredRecAtCV3 *)(arg0))->value,
                                     ((struct MeasuredRecAt10V2 *)(arg0))->value, size, 0, 0,
                                     &D_800C5290_de, one);
            if (resource != 0) {
                key = func_8028FE3C_de((s32)*resource, ((struct MeasuredRecAtCV3 *)(arg0))->value,
                                    arg1, &sp28);
                func_80253838_de(0, resource);
                if ((((struct MeasuredRecAt14V6 *)(arg0))->value =
                     func_8025193C_de(0, key, key, sp28, size, 0,
                                   &D_00285160, &D_800C52BC, one)) != 0) {
                    ((struct MeasuredCode8028B64C *)(arg0))->value = arg1;
                }
            }
        }
    }
}
