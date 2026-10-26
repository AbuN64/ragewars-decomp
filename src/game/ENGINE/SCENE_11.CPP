#include "include_asm.h"
#include "COMMON/TRIPLE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_10.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/SCENERECAT10C0.H"
#include "COMMON/OBJB.H"
#include "COMMON/EXTERNS_6.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "RENDER_4/8028FD2C_6.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "ENGINE/SCENE_11.H"
#include "COMMON/GAMEPLAY_REACTIONS.H"

extern void func_80278F00_de(Rec_func_8024C92C_de *arg0);








void Scene_DispatchSecondaryTriggersOfKind(void *world, s32 arg1) {
    Rec_func_8024C92C_de *trigger;
    Rec_func_8024C92C_de *var_s1_2;
    s32 var_s0;
    s32 var_s0_2;

    var_s0 = ((WorldRecAt1B40C *)(world))->nfaces;
    trigger = ((WorldRecAt1B40C *)(world))->faces;
    var_s0 -= 1;
    if (var_s0 != -1) {
        do {
            if (((Record14 *)(trigger))->kind == arg1) {
                func_80278F00_de(trigger);
            }
            var_s0 -= 1;
            trigger += 1;
        } while (var_s0 != -1);
    }

    var_s0_2 = ((WorldRecAt1B40C *)(world))->nedges;
    var_s1_2 = ((WorldRecAt1B40C *)(world))->edges;
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

s32 Scene_QueueTriggerTimer(WorldRecAt1B40C *arg0, Record14 *arg1) {
    void *rec;
    f32 val;
    s32 flag;

    rec = arg0->listB.head;
    if (rec != 0) {
        func_80255ED8_de(&arg0->listB, rec);
        func_80255CB8_de(&arg0->listA, rec);
        ((Bucket *)(rec))->object = arg1;
    } else {
        rec = arg0->listA.tail;
        Link_DispatchTrigger(((Bucket *)(rec))->object);
        ((Bucket *)(rec))->object = arg1;
    }
    val = recordValue((s32) arg1->lifetime);
    ((Bucket *)(rec))->remaining = val;
    flag = arg1->flags & 2;
    if (flag != 0) {
        ((Bucket *)(rec))->remaining = val * D_800C52E8_de;
    }
    return flag;
}










void Scene_UpdateTriggerTimers(void *arg0) {
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
                Link_DispatchTrigger(object);
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

/* Lights a point: blends the light volumes around it when the world's sectors hold any and lighting is on (D_800D2850), else copies the default lights D_800CBC90. */












extern void Scene_FindLightVolumes(Shared_World *world, CVector3 *point, ObjectRecAtBC **volumes, s32 *total);
static inline s32 worldHasLightVolumes(Shared_World *world) {
    s32 i;
    for (i = 0; i < world->sectorCount; i++) {
        if (((LightVolumeList *)SetN64_GetPackSection(world->sectors[i].resource->pack, 2))->count != 0) {
            return 1;
        }
    }
    return 0;
}
void Scene_SampleWorldLighting(Shared_World *world, CVector3 *position, Shared_ParticleLighting *out) {
    ObjectRecAtBC *volumes[10];
    s32 count;
    if (!worldHasLightVolumes(world) || D_800D2850 == 0) {
        *out = D_800CBC90[0];
    } else {
        Scene_FindLightVolumes(world, position, volumes, &count);
        Scene_SampleVolumeLighting(volumes, count, position, out);
    }
}

/* Searches the counted pointer list at offset 0x1B664 of a world record for the first entry whose definition id at 0x18->0xC equals the given id, returning it or null. Adapted from Scene_FindSwitchByDefinitionId with the list offset changed to 0x1B664. */







EntryRecAt18V4 *Scene_FindTypeFourteenActorByDefinitionId(WorldCode8028B64C *world, s32 id) {
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







extern Player *Player_GetFirstPlayer(void *list);
#ifdef VERSION_EU
extern Player *Player_GetFirstPlayer(void *list);
#endif

Player *Scene_FindNearestObjectToFirstPlayer(WorldRecAt1B6A4 *world) {
    CVector3 delta;
    Player *player;
    Player *object;
    Player *nearest;
    s32 best;
    s32 distance;
    s32 i;

#ifdef VERSION_EU
    player = Player_GetFirstPlayer(&D_80145040);
#else
    player = Player_GetFirstPlayer(&D_80145040);
#endif
    best = 9999999;
    nearest = 0;
    for (i = 0; i < world->count; i++) {
        object = world->objects[i];
        GraphU64_SubtractVectors(&delta, &object->pos, &player->pos);
        distance = Math_Sqrtf(delta.x * delta.x + delta.y * delta.y + delta.z * delta.z);
        if (distance <= best) {
            nearest = object;
            best = distance;
        }
    }
    return nearest;
}

/* Registers an object with a world after preparing it with func_8024B8C4_de: adds it to the lists of objects accepted by func_8024D160_de and func_8024E1B4_de, to the list of all objects, to the type 1 list (storing its slot in the object), to the list of objects flagged 2, to the type 5 list, and to the lists of model 0x64F and model 0x64D objects, each while that list has room. */







extern void func_8024B8C4_de(ObjectSceneRegisterActorInSceneLists *object);
extern s32 func_8024D160_de(ObjectSceneRegisterActorInSceneLists *object);
extern s32 func_8024E1B4_de(ObjectSceneRegisterActorInSceneLists *object);

void Scene_RegisterActorInSceneLists(WorldRecAt10B8 *world, ObjectSceneRegisterActorInSceneLists *object) {
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
ObjectRecAt1A4 *Scene_FindNearestMatchingActor(WorldSceneFindNearestMatchingActor *world, ObjectRecAt1A4 *self, s32 team, s32 kind, s32 activeOnly) {
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

/* Returns the entry in an object's pointer list at 0x1024, counted at 0x10A4, whose position lies nearest a given position, or null when none lies closer than D_800CA3E0. Adapted from Player_FindNearestPlayer with the linked list walk replaced by a do-while loop, guarded by the zero index against the count, over a counted array of entry pointers read before the guard, the position read from a record at offset 8, and the differences taken from the position. */





struct EntryRecAt10 *Scene_FindNearestListedEntry(struct OwnerCode8028B64C *owner, struct EntryRecAt10 *pos) {
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




ActorRecAt1D8V1 *Scene_ResolveActorLinkGroup(ObjCode8028B64C *obj, int id) {
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

void Scene_ClearActorLinksById(void *arg0, s32 arg1) {
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

extern void Barrel_FillDamagePacket(CDamageInfo *event, void *target, s32 damage, f32 radius, s32 flags, Shield *shield);
extern void Barrel_RunDamageHook(LevelActor *actor, s32 *behavior, CDamageInfo *event);
void Scene_ApplyDamageToTypeOneActors(Shared_World *world, s32 damage, s32 flags) {
    CDamageInfo event;
    LevelActor **actors;
    s32 count;
    s32 i;

    Barrel_FillDamagePacket(&event, 0, damage, 102.399994f, flags, 0);
    count = world->kind1Count;
    actors = world->kind1;
    for (i = 0; i < count; i++) {
        Barrel_RunDamageHook(actors[i], &actors[i]->behaviorFlags, &event);
    }
}
