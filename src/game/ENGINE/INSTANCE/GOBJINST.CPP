#include "COMMON/WORLD.H"
#include "COMMON/LONE/D_80103FD0.H"
#include "COMMON/GROUP.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "SCENE/802508E0_9.H"
#include "COMMON/LISTHEADER.H"
#include "CAMERA/80243A80.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "RENDER_4/8028FD2C_6.H"
#include "LISTS/80279520.H"

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


extern f32 Particle_GetActorHeight(Instance8020CD74 *);

extern CollisionState D_801041F0;

extern int func_8024E968_de(void *record);

/* Spawns and initializes an actor with model, transforms, collision body, effects and default bounds. */










extern char *D_80140F84;

extern void *D_800CB440_de[];

extern char D_800CA8C4_de;

extern void D_0024A7A0();

struct Shared_World;
extern s32 func_8028B21C_de(struct Shared_World *, s32);

extern void Camera_ResetActorMotion(char *);

extern CQuatern func_8024D870_de(char *);

extern void func_80262480_de(char *);

extern void func_8024B65C_de(char *, s32);

extern void Particle_IdentityMatrix(char *);

extern void Nav_InitSpawnedActor(char *, char *, void *);

extern void func_802193C8_de(char *, s32, char *);

extern void Instance_LoadModel(char *, s32, s32, s32);

extern s32 func_80250BF0_de(void);

static inline void *body_setup(char *obj) {
    u32 kind;
    s32 i;
    char *player;

    kind = ((LevelActor *)obj)->definition->kind;
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



extern s32 func_802654E8_de(void *, s32, s32);

extern void func_8027985C_de(WeightedTable *);


s32 func_802462E8_de(Instance8020CD74 *actorState, CVector3 position, char **out) {

    Instance8020CD74 saved;
    char *set;
    s32 grounded;
    s32 collisions;
    struct Actor_func_80214DD4_de *actor = (struct Actor_func_80214DD4_de *)actorState;

    if (actor->type == 1 && (actor->flags100 & 0x300000) != 0) {
        set = &D_801040D0;
    } else {
        grounded = func_8024DEE0_de(actorState);
        if (func_8024DF5C_de(actorState) == 0) {
            set = &D_801040D0;
            if (grounded != 0) {
                set = &D_80104050;
            }
        } else if (func_8024DFA0_de(actorState) == 0) {
            set = &D_80104070;
        } else {
            set = &D_80103FF0;
        }
    }
    if (out != 0) {
        *out = set;
    }
    saved = *actorState;
    collisions = Camera_MoveActorWithCollision(actorState, position, set);
    *actorState = saved;
    return collisions;
}

s32 func_8024643C_de(Instance8020CD74 *from, Instance8020CD74 *to) {

    Instance8020CD74 savedFrom;
    CVector3 desired;
    f32 scale;
    s32 collisions;

    savedFrom = *from;
    scale = D_800C3828_de;
    ((struct Actor_func_80214DD4_de *)from)->pos.y += Particle_GetActorHeight(from) * scale;
    desired = ((struct Actor_func_80214DD4_de *)to)->pos;
    desired.y += Particle_GetActorHeight(to) * scale;
    collisions = Camera_MoveActorWithCollision(from, desired, &D_80103FD0);
    *from = savedFrom;

    return collisions == 0;
}

s32 func_80246558_de(Instance8020CD74 *actorState, CVector3 position, CollisionInfoCode80243A80 *collisionSettings) {
    Instance8020CD74 saved;
    CollisionInfoCode80243A80 collision_info;
    s32 collisions;

    saved = *actorState;
    collision_info = *collisionSettings;
    collision_info.ground_behavior = 0;
    collision_info.instance_behavior = 1;
    Camera_MoveActorWithCollision(actorState, position, &collision_info);
    *actorState = saved;

    collisions = D_801041F0.active0 || D_801041F0.active9c;
    return !collisions;
}

/** Thin wrapper around func_8024E968_de, discarding its result. */
void func_80246684_de(void *record) {
    func_8024E968_de(record);
}

void func_802466A0_de(char *obj, s32 model, s32 kind, s32 unused, void *info, s32 effect, s32 owner, f32 heading,
                   CVector3 pos, s32 flags, CVector3 extent, CVector3 offset) {
    s32 lean;
    s32 delay;
    Shared_World *world;

    ((LevelActor *)obj)->flags &= ~0x40000;
    if (model == -1) {
        model = func_8028B21C_de(&g_world, kind);
        if (model == -1) {
            return;
        }
    }
    Camera_ResetActorMotion(obj);
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
    Particle_IdentityMatrix((char *)obj + 0x74);
    ((LevelActor *)obj)->fieldB4 = 0;
    ((LevelActor *)obj)->fieldB8 = 0;
    ((LevelActor *)obj)->shadow = 0;
    ((LevelActor *)obj)->state13B = 0;
    ((LevelActor *)obj)->flags |= 0x10000;
    ((LevelActor *)obj)->flags |= 0x20000;
    if (((LevelActor *)obj)->definition->kind == 0 || (((LevelActor *)obj)->flags & 1)) {
        ((LevelActor *)obj)->flags &= ~0x20000;
    }
    lean = 0;
    delay = 0;
    
Nav_InitSpawnedActor
(obj, obj + 0x170, body_setup(obj));
    if (((LevelActor *)obj)->collisionEnabled != 0) {
        lean = -((LevelActor *)obj)->lean;
    }
    ((LevelActor *)obj)->controller = 0;
    if (effect != -1) {
        func_802193C8_de(obj + 0x204, effect, (char *)obj + 0x8);
    }
    world = &g_world;
    Instance_LoadModel(obj, (s32)world->indexedDirectory, world->indexedBank, lean);
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

s32 func_80246A08_de(LevelActor *owner, s32 animationKind, s32 excludedEntry) {
    WeightedTable table;
    void **resource;
    s32 *entries;
    void *data;
    s32 count;
    s32 total;
    s32 original;

    if (!(owner->flags & 0x40000)) {
        goto fail;
    }
    resource = Scene_RequestResource(0, ((struct Access_s32_C4 *)(owner))->field,
                             ((struct Access_s32_C4 *)(owner))->field, ((struct Access_s32_D0 *)(owner))->field,
                             0, 0, 0, D_800C3864_de, 1);
    if (resource == 0) {
        goto fail;
    }
    data = Render_GetPackSection(*resource, 1);
    entries = &((struct func_80254D70_S2 *)(data))->unk8;
    total = ((struct func_80203E78_S1 *)(data))->unk4;
    count = func_802654E8_de(entries, ((struct Access_s8_E6 *)(owner))->field, animationKind);
    if (count != -1) {
        original = count;
        while (count > 0) {
            if (entries[count - 1] != animationKind) {
                break;
            }
            count--;
        }

        func_8027985C_de(&table);
        if (excludedEntry == -1) {
            while (count < total && entries[count] == animationKind) {
                func_80279864_de(&table, count++, 10);
            }
        } else {
            while (count < total && entries[count] == animationKind) {
                if (excludedEntry != count) {
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
    Scene_UnlockResource(0, resource);
    return count;

fail:
    return -1;
}
