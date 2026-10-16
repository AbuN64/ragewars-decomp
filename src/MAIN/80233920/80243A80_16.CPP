#include "span_1000/code_80243A80.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "shared/level_actor.h"
#include "shared/particle_lighting.h"
#include "span_1000/code_80245980.h"
#include "span_1000/code_80279208.h"
#include "TYPES.H"

/* Returns the collisions an object would meet moving to a position, without committing the move: picks the collision set for the object
 * (D_801040D0 for flagged players; otherwise by func_8024DF5C_de and then func_8024DFA0_de or func_8024DEE0_de among
 * D_80103FF0, D_80104070, D_80104050 and D_801040D0), reports it through the optional out pointer, runs
 * the collision mover func_80243A90_de and restores the object's 0x50-byte header. Adapted from
 * func_8024643C_de. */





extern char D_80103FF0;

extern char D_80104050;

extern char D_80104070;

extern char D_801040D0;

extern s32 func_8024DEE0_de(Instance8020CD74 *);

extern s32 func_8024DF5C_de(Instance8020CD74 *);

extern s32 func_8024DFA0_de(Instance8020CD74 *);

typedef struct CollisionInfo CollisionInfo;

extern char D_80103FD0;

extern f32 func_8024D284_de(Instance8020CD74 *);

extern CollisionState D_801041F0;

extern int func_8024E968_de(void *record);

/* Spawns and initializes an actor with model, transforms, collision body, effects and default bounds. */









extern World_func_802466A0_de D_8011FE88;

extern char *D_80140F84;

extern void *D_800CB440_de[];

extern char D_800CA8C4_de;

extern void D_0024A7A0();

struct Shared_World;
extern s32 func_8028B21C_de(struct Shared_World *, s32);

extern void func_80246184_de(char *);

extern Vector4f func_8024D870_de(char *);

extern void func_80262480_de(char *);

extern void func_8024B65C_de(char *, s32);

extern void func_802727D8_de(char *);

#if defined(VERSION_EU)
extern void func_80213ACC_eu(char *, char *, void *);
#elif defined(VERSION_EU_X)
extern void func_80213ACC_eu_x(char *, char *, void *);
#elif defined(VERSION_US)
extern void func_80213AAC_us(char *, char *, void *);
#elif defined(VERSION_US_REV1)
extern void func_80213AAC_us_rev1(char *, char *, void *);
#else
extern void func_80213AAC_de(char *, char *, void *);
#endif

extern void func_802193C8_de(char *, s32, char *);

extern void func_80246BE8_de(char *, s32, s32, s32);

extern s32 func_80250BF0_de(void);

static inline void *body_setup(char *obj) {
    u32 kind;
    s32 i;
    char *player;

    kind = *((LevelActor *)obj)->definition;
    if (kind >= 15) {
        return 0;
    }
    if (kind == 11) {
        for (i = 0; i < D_80145048; i++) {
            player = D_80140F84 + i * 0x16E8;
            if (player == obj) {
                return 0;
            }
            if (player + 0x2E8 == obj) {
                return &D_800CA8C4_de;
            }
        }
    }
    return D_800CB440_de[kind];
}

extern s32 D_800C3864_de[];

extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);

extern void *func_8028FDB4_de(void *, s32);

extern s32 func_802654E8_de(void *, s32, s32);

extern void func_8027985C_de(WeightedTable *);

extern s32 func_80279864_de(WeightedTable *, s16, s16);

extern s16 func_802798A8_de(WeightedTable *);

extern void func_80253754_de(s32, void *);

s32 func_802462E8_de(Instance8020CD74 *arg0, Vec3 position, char **out) {
    extern s32 func_80243A90_de(Instance8020CD74 *, Vec3, char *);
    Instance8020CD74 saved;
    char *set;
    s32 grounded;
    s32 collisions;
    struct Actor_func_80214DD4_de *actor = (struct Actor_func_80214DD4_de *)arg0;

    if (actor->type == 1 && (actor->flags100 & 0x300000) != 0) {
        set = &D_801040D0;
    } else {
        grounded = func_8024DEE0_de(arg0);
        if (func_8024DF5C_de(arg0) == 0) {
            set = &D_801040D0;
            if (grounded != 0) {
                set = &D_80104050;
            }
        } else if (func_8024DFA0_de(arg0) == 0) {
            set = &D_80104070;
        } else {
            set = &D_80103FF0;
        }
    }
    if (out != 0) {
        *out = set;
    }
    saved = *arg0;
    collisions = func_80243A90_de(arg0, position, set);
    *arg0 = saved;
    return collisions;
}

s32 func_8024643C_de(Instance8020CD74 *arg0, Instance8020CD74 *arg1) {
    extern s32 func_80243A90_de(Instance8020CD74 *, Vec3, CollisionInfo *);
    Instance8020CD74 saved;
    Vec3 desired;
    f32 scale;
    s32 collisions;

    saved = *arg0;
    scale = D_800C3828_de;
    ((struct Actor_func_80214DD4_de *)arg0)->pos.y += func_8024D284_de(arg0) * scale;
    desired = ((struct Actor_func_80214DD4_de *)arg1)->pos;
    desired.y += func_8024D284_de(arg1) * scale;
    collisions = func_80243A90_de(arg0, desired, &D_80103FD0);
    *arg0 = saved;

    return collisions == 0;
}

s32 func_80246558_de(Instance8020CD74 *arg0, Vec3Words arg1, CollisionInfoCode80243A80 *arg2) {
    extern s32 func_80243A90_de(Instance8020CD74 *, Vec3Words, CollisionInfoCode80243A80 *);
    Instance8020CD74 saved;
    CollisionInfoCode80243A80 collision_info;
    s32 collisions;

    saved = *arg0;
    collision_info = *arg2;
    collision_info.ground_behavior = 0;
    collision_info.instance_behavior = 1;
    func_80243A90_de(arg0, arg1, &collision_info);
    *arg0 = saved;

    collisions = D_801041F0.active0 || D_801041F0.active9c;
    return !collisions;
}

/** Thin wrapper around func_8024E968_de, discarding its result. */
void func_80246684_de(void *arg0) {
    func_8024E968_de(arg0);
}

void func_802466A0_de(char *obj, s32 model, s32 kind, s32 unused, u32 *info, s32 effect, s32 owner, f32 heading,
                   Vec3 pos, s32 flags, Vec3 extent, Vec3 offset) {
    s32 lean;
    s32 delay;
    World_func_802466A0_de *world;

    ((LevelActor *)obj)->flags &= ~0x40000;
    if (model == -1) {
        model = func_8028B21C_de(&D_8011FE88, kind);
        if (model == -1) {
            return;
        }
    }
    func_80246184_de(obj);
    *(u8 *)obj = 1;
    ((LevelActor *)obj)->modelIndex = model;
    ((LevelActor *)obj)->definition = info;
    ((LevelActor *)obj)->model = owner;
    ((LevelActor *)obj)->yaw = heading;
    ((LevelActor *)obj)->position0 = pos;
    ((LevelActor *)obj)->flags = flags;
    ((LevelActor *)obj)->scale = extent;
    ((LevelActor *)obj)->position1 = offset;
    ((LevelActor *)obj)->type = kind;
    ((LevelActor *)obj)->rotation = func_8024D870_de(obj);
    ((LevelActor *)obj)->eyeHeight = 0;
    ((LevelActor *)obj)->stateE6 = 0;
    ((LevelActor *)obj)->stateE7 = 0;
    ((LevelActor *)obj)->state139 = 0;
    ((LevelActor *)obj)->state138 = 0;
    ((LevelActor *)obj)->renderFlags = 0x17800074;
    func_80262480_de((char *)obj + 0x104);
    func_80262480_de((char *)obj + 0x118);
    func_8024B65C_de(obj, 0);
    ((LevelActor *)obj)->flags = (((LevelActor *)obj)->flags & ~0x400) | 0x2100;
    func_802727D8_de((char *)obj + 0x74);
    ((LevelActor *)obj)->fieldB4 = 0;
    ((LevelActor *)obj)->fieldB8 = 0;
    ((LevelActor *)obj)->shadow = 0;
    ((LevelActor *)obj)->state13B = 0;
    ((LevelActor *)obj)->flags |= 0x10000;
    ((LevelActor *)obj)->flags |= 0x20000;
    if (*((LevelActor *)obj)->definition == 0 || (((LevelActor *)obj)->flags & 1)) {
        ((LevelActor *)obj)->flags &= ~0x20000;
    }
    lean = 0;
    delay = 0;
    
#if defined(VERSION_EU)
func_80213ACC_eu
#elif defined(VERSION_EU_X)
func_80213ACC_eu_x
#elif defined(VERSION_US)
func_80213AAC_us
#elif defined(VERSION_US_REV1)
func_80213AAC_us_rev1
#else
func_80213AAC_de
#endif
(obj, obj + 0x170, body_setup(obj));
    if (((LevelActor *)obj)->collisionEnabled != 0) {
        lean = -((LevelActor *)obj)->lean;
    }
    ((LevelActor *)obj)->controller = 0;
    if (effect != -1) {
        func_802193C8_de(obj + 0x204, effect, (char *)obj + 0x8);
    }
    world = &D_8011FE88;
    func_80246BE8_de(obj, world->gravity, world->radius, lean);
    if (delay != 0) {
        ((LevelActor *)obj)->animationTime = delay;
        ((LevelActor *)obj)->flags &= ~0x400;
    }
    ((LevelActor *)obj)->flags2E4 = func_80250BF0_de() << 10;
    if (((LevelActor *)obj)->flags & 8) {
        ((LevelActor *)obj)->update = D_0024A7A0;
        ((LevelActor *)obj)->lighting[0] = D_800D0EF8;
        ((LevelActor *)obj)->lighting[1] = D_800D0EF8;
    }
}

s32 func_80246A08_de(LevelActor *arg0, s32 arg1, s32 arg2) {
    WeightedTable table;
    void **resource;
    s32 *entries;
    void *data;
    s32 count;
    s32 total;
    s32 original;

    if (!(arg0->flags & 0x40000)) {
        goto fail;
    }
    resource = func_8025193C_de(0, ((struct Access_s32_C4 *)(arg0))->field,
                             ((struct Access_s32_C4 *)(arg0))->field, ((struct Access_s32_D0 *)(arg0))->field,
                             0, 0, 0, D_800C3864_de, 1);
    if (resource == 0) {
        goto fail;
    }
    data = func_8028FDB4_de(*resource, 1);
    entries = &((struct func_80254D70_S2 *)(data))->unk8;
    total = ((struct func_80203E78_S1 *)(data))->unk4;
    count = func_802654E8_de(entries, ((struct Access_s8_E6 *)(arg0))->field, arg1);
    if (count != -1) {
        original = count;
        while (count > 0) {
            if (entries[count - 1] != arg1) {
                break;
            }
            count--;
        }

        func_8027985C_de(&table);
        if (arg2 == -1) {
            while (count < total && entries[count] == arg1) {
                func_80279864_de(&table, count++, 10);
            }
        } else {
            while (count < total && entries[count] == arg1) {
                if (arg2 != count) {
                    func_80279864_de(&table, count, 10);
                }
                count++;
            }
        }
        if (table.count == 0) {
            func_80279864_de(&table, original, 10);
        }
        count = func_802798A8_de(&table);
    }
    func_80253754_de(0, resource);
    return count;

fail:
    return -1;
}
