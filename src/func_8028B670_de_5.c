#include "span_C76B0/data.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"
#include "shared/func_8028C568_de_closed.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80277444.h"
#include "span_1000/code_80286050.h"
#include "span_16E000/code_8044ACCC.h"
#include "shared/func_8021E2A0_de_closed.h"

extern void func_80278F00_de(Rec_func_8024C92C_de *arg0);








void func_8028C4B4_de(void *arg0, s32 arg1) {
    Rec_func_8024C92C_de *var_s1;
    Rec_func_8024C92C_de *var_s1_2;
    s32 var_s0;
    s32 var_s0_2;

    var_s0 = ((WorldRecAt1B40C *)(arg0))->nfaces;
    var_s1 = ((WorldRecAt1B40C *)(arg0))->faces;
    var_s0 -= 1;
    if (var_s0 != -1) {
        do {
            if (((Record14 *)(var_s1))->kind == arg1) {
                func_80278F00_de(var_s1);
            }
            var_s0 -= 1;
            var_s1 += 1;
        } while (var_s0 != -1);
    }

    var_s0_2 = ((WorldRecAt1B40C *)(arg0))->nedges;
    var_s1_2 = ((WorldRecAt1B40C *)(arg0))->edges;
    var_s0_2 -= 1;
    if (var_s0_2 != -1) {
        do {
            if (((Record14 *)(var_s1_2))->kind == arg1) {
                func_80278F00_de(var_s1_2);
            }
            var_s0_2 -= 1;
            var_s1_2 += 1;
        } while (var_s0_2 != -1);
    }
}

s32 func_8028C568_de(void *arg0, void *arg1) {
    void *rec;
    f32 val;
    s32 flag;

    rec = ((WorldRecAt1B40C *)(arg0))->listB.head;
    if (rec != 0) {
        func_80255ED8_de(&((WorldRecAt1B40C *)(arg0))->listB, rec);
        func_80255CB8_de(&((WorldRecAt1B40C *)(arg0))->listA, rec);
        ((Bucket *)(rec))->object = arg1;
    } else {
        rec = ((WorldRecAt1B40C *)(arg0))->listA.tail;
        func_80278C10_de(((Bucket *)(rec))->object);
        ((Bucket *)(rec))->object = arg1;
    }
    val = recordValue((s32) ((Record14 *)(arg1))->lifetime);
    ((Bucket *)(rec))->remaining = val;
    flag = ((Record14 *)(arg1))->flags & 2;
    if (flag != 0) {
        ((Bucket *)(rec))->remaining = val * D_800C52E8_de;
    }
    return flag;
}










void func_8028C60C_de(void *arg0) {
    void *node;
    void *next;
    void *object;
    s32 remove;
    s32 expired;
    f32 zero;
    f32 value;

    node = ((WorldRecAt1B40C *)(arg0))->listA.head;
    remove = 0;
    if (node != 0) {
        zero = 0.0f;
        do {
            object = ((Bucket *)(node))->object;
            next = ((Bucket *)(node))->next;
            expired = remove;
            if (((Record14 *)(object))->flags & 2) {
                value = ((Bucket *)(node))->remaining - D_800D2988;
                ((Bucket *)(node))->remaining = value;
                if (value <= zero) {
                    expired = 1;
                    remove = 1;
                }
            }
            if (expired != 0) {
                func_80278C10_de(object);
            }
            if (remove != 0) {
                func_80255ED8_de(&((WorldRecAt1B40C *)(arg0))->listA, node);
                func_80255CB8_de(&((WorldRecAt1B40C *)(arg0))->listB, node);
            }
            node = next;
            remove = 0;
        } while (node != 0);
    }
}

/* Produces an object's placement: when one of its tracks has an active second node and D_800D2850 is set, it samples the track through func_802897B4_de and resolves the placement with func_80289970_de, and otherwise copies the default placement D_800CBC90. */












extern struct IntPair *func_8028FDB4_de(void *table, s32 index);
extern void func_802897B4_de(Owner_func_8028C6D4_de *owner, s32 time, Sample *sample, s32 *segment);
extern void func_80289970_de(Sample *sample, s32 segment, s32 time, Block24 *out);

static inline s32 has_active(Owner_func_8028C6D4_de *owner) {
    s32 i;

    for (i = 0; i < owner->count; i++) {
        if (func_8028FDB4_de(*owner->tracks[i].nodes, 2)->field_4 != 0) {
            return 1;
        }
    }
    return 0;
}

void func_8028C6D4_de(Owner_func_8028C6D4_de *owner, s32 time, Block24 *out) {
    Sample sample;
    s32 segment;

    if (!has_active(owner) || D_800D2850 == 0) {
        *out = *(Block24 *)D_800CBC90;
    } else {
        func_802897B4_de(owner, time, &sample, &segment);
        func_80289970_de(&sample, segment, time, out);
    }
}

/* Searches the counted pointer list at offset 0x1B664 of a world record for the first entry whose definition id at 0x18->0xC equals the given id, returning it or null. Adapted from func_8028C108_de with the list offset changed to 0x1B664. */







EntryRecAt18V4 *func_8028C7E0_de(World_func_8028C7E0_de *world, s32 id) {
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

/* Returns the object in the world's object list nearest to the current player actor, comparing whole-unit distances and starting from a bound of 9999999. */







extern Player *func_8022A414_de(void *list);
#ifdef VERSION_EU
extern Player *func_8022A414_de(void *list);
#endif

Player *func_8028C834_de(WorldRecAt1B6A4 *world) {
    Vec3 delta;
    Player *player;
    Player *object;
    Player *nearest;
    s32 best;
    s32 distance;
    s32 i;

#ifdef VERSION_EU
    player = func_8022A414_de(&D_80145040);
#else
    player = func_8022A414_de(&D_80145040);
#endif
    best = 9999999;
    nearest = 0;
    for (i = 0; i < world->count; i++) {
        object = world->objects[i];
        func_80271F68_de(&delta, &object->pos, &player->pos);
        distance = func_802B72B0_de(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
        if (distance <= best) {
            nearest = object;
            best = distance;
        }
    }
    return nearest;
}

/* Registers an object with a world after preparing it with func_8024B8C4_de: adds it to the lists of objects accepted by func_8024D160_de and func_8024E1B4_de, to the list of all objects, to the type 1 list (storing its slot in the object), to the list of objects flagged 2, to the type 5 list, and to the lists of model 0x64F and model 0x64D objects, each while that list has room. */







extern void func_8024B8C4_de(Object_func_8028C934_de *object);
extern s32 func_8024D160_de(Object_func_8028C934_de *object);
extern s32 func_8024E1B4_de(Object_func_8028C934_de *object);

void func_8028C934_de(WorldRecAt10B8 *world, Object_func_8028C934_de *object) {
    func_8024B8C4_de(object);
    if (func_8024D160_de(object) != 0) {
        s32 n = world->countA;
        if (n != 512) {
            world->listA[n] = object;
            world->countA = n + 1;
        }
    }
    if (func_8024E1B4_de(object) != 0) {
        s32 n = world->countB;
        if (n != 128) {
            world->listB[n] = object;
            world->countB = n + 1;
        }
    }
    {
        s32 n = world->countAll;
        if (n < 128) {
            world->all[n] = object;
            world->countAll = n + 1;
        }
    }
    {
        s32 n = world->countType1;
        if (n < 64 && object->descriptor->field_0 == 1) {
            world->type1[n] = object;
            object->slot = world->countType1++;
        }
    }
    {
        s32 n = world->countFlagged;
        if (n < 32 && (object->flags & 2)) {
            world->flagged[n] = object;
            world->countFlagged = n + 1;
        }
    }
    {
        s32 n = world->countType5;
        if (n < 16 && object->descriptor->field_0 == 5) {
            world->type5[n] = object;
            world->countType5 = n + 1;
        }
    }
    {
        s32 n = world->count64F;
        if (n < 32 && object->model == 0x64F) {
            world->model64F[n] = object;
            world->count64F = n + 1;
        }
    }
    if (object->model == 0x64D) {
        s32 n = world->count64D;
        if (n < 4) {
            world->model64D[n] = object;
            world->count64D = n + 1;
        }
    }
}

/* Returns the nearest other object matching the optional team, kind and active filters, by squared distance. */
ObjectRecAt1A4 *func_8028CAE0_de(World_func_8028CAE0_de *world, ObjectRecAt1A4 *self, s32 team, s32 kind, s32 activeOnly) {
    s32 i;
    ObjectRecAt1A4 *obj;
    ObjectRecAt1A4 *best;
    f32 min;
    f32 dx, dy, dz, distSq;

    s32 count;

    i = 0;
    min = 3.4028235e38f;
    count = world->count;
    best = 0;
    for (; i < count; i++) {
        obj = &world->objects[i];
        if (obj == self) {
            continue;
        }
        if (team != -1 && obj->team != team) {
            continue;
        }
        if (kind != -1 && *obj->kind != kind) {
            continue;
        }
        if (activeOnly && obj->active == 0) {
            continue;
        }
        dx = self->x - obj->x;
        dy = self->y - obj->y;
        dz = self->z - obj->z;
        distSq = dx * dx + dy * dy + dz * dz;
        if (distSq < min) {
            min = distSq;
            best = obj;
        }
    }
    return best;
}

/* Returns the entry in an object's pointer list at 0x1024, counted at 0x10A4, whose position lies nearest a given position, or null when none lies closer than D_800CA3E0. Adapted from func_8022A480_de with the linked list walk replaced by a do-while loop, guarded by the zero index against the count, over a counted array of entry pointers read before the guard, the position read from a record at offset 8, and the differences taken from the position. */





struct EntryRecAt10 *func_8028CBB0_de(struct Owner_func_8028CBB0_de *owner, struct EntryRecAt10 *pos) {
    s32 i;
    struct EntryRecAt10 *best;
    f32 min;
    struct EntryRecAt10 **entries;
    f32 dx, dy, dz, distSq;
    struct EntryRecAt10 *e;
    s32 n;
    struct EntryRecAt10 **p;

    i = 0;
    best = 0;
    min = (3.4028234663852886e+38f);
    n = owner->count;
    entries = owner->entries;
    if (i < n) {
        p = entries;
        do {
            e = *p;
            dx = pos->x - e->x;
            dx = dx * dx;
            dy = pos->y - e->y;
            dy = dy * dy;
            dz = pos->z - e->z;
            dz = dz * dz;
            distSq = (dx + dy) + dz;
            if (distSq < min) {
                min = distSq;
                best = e;
            }
            i++;
            p++;
        } while (i < n);
    }
    return best;
}

/* Finds the first of the object's listed actors (count at 0xE50, pointers from 0xC50) linked to an id
   at 0x1D8, clears that actor's link and relinks every other actor with that id to it; returns the
   actor, or 0. */




ActorRecAt1D8V1 *func_8028CC34_de(Obj_func_8028CC34_de *obj, int id) {
    int i;
    ActorRecAt1D8V1 *found;
    int count;
    ActorRecAt1D8V1 **list;

    i = 0;
    found = 0;
    count = obj->count;
    list = obj->actors;
    for (; i < count; i++) {
        if (list[i]->link == id) {
            found = list[i];
            found->link = 0;
            break;
        }
    }
    for (i = 0; i < count; i++) {
        if (list[i]->link == id) {
            list[i]->link = (int)found;
        }
    }
    return found;
}

void func_8028CCA4_de(void *arg0, s32 arg1) {
    s32 count;
    s32 i;
    void **arr;
    void *entry;

    i = 0;
    count = ((SceneRecAt10C0 *)((arg0)))->count;
    arr = &((SceneRecAt10C0 *)((arg0)))->objects[0];
    if (count > 0) {
        do {
            entry = *arr;
            if (((ActorRecAt1D8V1 *)((entry)))->link == arg1) {
                ((ActorRecAt1D8V1 *)((entry)))->link = 0;
            }
            i += 1;
            arr += 1;
        } while (i < count);
    }
}
