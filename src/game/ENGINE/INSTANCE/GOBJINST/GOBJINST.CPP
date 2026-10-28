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
#include "SCENE/CACHE_ALLOCATERESOURCEAT.H"
#include "COMMON/LISTHEADER.H"
#include "CAMERA/80243A80.H"
#include "TYPES.H"
#include "SCENE/CACHE_REQUESTRESOURCE.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
#include "LISTS/LISTS.H"

/* Returns the collisions an object would meet moving to a position, without committing the move: picks the collision set for the object
 * (D_801040D0 for flagged players; otherwise by Insthdr_IsInactiveOrCollisionOption4 and then Insthdr_GetModelCollisionFlag8 or Insthdr_GetModelCollisionFlag1 among
 * D_80103FF0, D_80104070, D_80104050 and D_801040D0), reports it through the optional out pointer, runs
 * the collision mover func_80243A90_de and restores the object's 0x50-byte header. Adapted from
 * Gobjinst_HasClearPathToActor. */





extern char D_80103FF0;

extern char D_80104050;

extern char D_80104070;

extern char D_801040D0;

extern s32 Insthdr_GetModelCollisionFlag1(Instance8020CD74 *);

extern s32 Insthdr_IsInactiveOrCollisionOption4(Instance8020CD74 *);

extern s32 Insthdr_GetModelCollisionFlag8(Instance8020CD74 *);


extern f32 Gobjinst_GetActorHeight(Instance8020CD74 *);

extern CollisionState D_801041F0;

extern int InstHdr_GetActorMotionIndex(void *record);

/* Spawns and initializes an actor with model, transforms, collision body, effects and default bounds. */










extern char *D_80140F84;

extern void *D_800CB440_de[];

extern char D_800CA8C4_de;

extern void D_0024A7A0();

struct Shared_World;
extern s32 Scene_FindModelIdIndex(struct Shared_World *, s32);

extern void GameObject_ResetActorMotion(char *);

extern CQuatern Insthdr_BuildActorGroundRotation(char *);

extern void func_80262480_de(char *);

extern void Gobjinst_QueueAnimation(char *, s32);

extern void Graphu64_IdentityMatrix(char *);

extern void Actor_InitSpawnedActor(char *, char *, void *);

extern void func_802193C8_de(char *, s32, char *);

extern void Gobjinst_LoadModel(char *, s32, s32, s32);


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

extern s32 g_lookupAIAnimTypeAnimObjectInfoText[];



extern s32 Defs_FindSortedValue(void *, s32, s32);

extern void Lists_ClearWeightedTable(WeightedTable *);


s32 Gobjinst_ProbeActorMovement(Instance8020CD74 *actorState, CVector3 position, char **out) {

    Instance8020CD74 saved;
    char *set;
    s32 grounded;
    s32 collisions;
    struct Actor_func_80214DD4_de *actor = (struct Actor_func_80214DD4_de *)actorState;

    if (actor->type == 1 && (actor->flags100 & 0x300000) != 0) {
        set = &D_801040D0;
    } else {
        grounded = Insthdr_GetModelCollisionFlag1(actorState);
        if (Insthdr_IsInactiveOrCollisionOption4(actorState) == 0) {
            set = &D_801040D0;
            if (grounded != 0) {
                set = &D_80104050;
            }
        } else if (Insthdr_GetModelCollisionFlag8(actorState) == 0) {
            set = &D_80104070;
        } else {
            set = &D_80103FF0;
        }
    }
    if (out != 0) {
        *out = set;
    }
    saved = *actorState;
    collisions = Unicol_MoveActorWithCollision(actorState, position, set);
    *actorState = saved;
    return collisions;
}

s32 Gobjinst_HasClearPathToActor(Instance8020CD74 *from, Instance8020CD74 *to) {

    Instance8020CD74 savedFrom;
    CVector3 desired;
    f32 scale;
    s32 collisions;

    savedFrom = *from;
    scale = D_800C3828_de;
    ((struct Actor_func_80214DD4_de *)from)->pos.y += Gobjinst_GetActorHeight(from) * scale;
    desired = ((struct Actor_func_80214DD4_de *)to)->pos;
    desired.y += Gobjinst_GetActorHeight(to) * scale;
    collisions = Unicol_MoveActorWithCollision(from, desired, &D_80103FD0);
    *from = savedFrom;

    return collisions == 0;
}

s32 Gobjinst_HasClearInstancePath(Instance8020CD74 *actorState, CVector3 position, CollisionInfoCode80243A80 *collisionSettings) {
    Instance8020CD74 saved;
    CollisionInfoCode80243A80 collision_info;
    s32 collisions;

    saved = *actorState;
    collision_info = *collisionSettings;
    collision_info.ground_behavior = 0;
    collision_info.instance_behavior = 1;
    Unicol_MoveActorWithCollision(actorState, position, &collision_info);
    *actorState = saved;

    collisions = D_801041F0.active0 || D_801041F0.active9c;
    return !collisions;
}

/** Thin wrapper around InstHdr_GetActorMotionIndex, discarding its result. */
void Gobjinst_ReadActorMotionIndex(void *record) {
    InstHdr_GetActorMotionIndex(record);
}

void Gobjinst_InitializeActor(char *obj, s32 model, s32 kind, s32 unused, void *info, s32 effect, s32 owner, f32 heading,
                   CVector3 pos, s32 flags, CVector3 extent, CVector3 offset) {
    s32 lean;
    s32 delay;
    Shared_World *world;

    ((LevelActor *)obj)->flags &= ~0x40000;
    if (model == -1) {
        model = Scene_FindModelIdIndex(&g_world, kind);
        if (model == -1) {
            return;
        }
    }
    GameObject_ResetActorMotion(obj);
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
    ((LevelActor *)obj)->rotation = Insthdr_BuildActorGroundRotation(obj);
    ((LevelActor *)obj)->eyeHeight = 0;
    ((LevelActor *)obj)->stateE6 = 0;
    ((LevelActor *)obj)->stateE7 = 0;
    ((LevelActor *)obj)->state139 = 0;
    ((LevelActor *)obj)->state138 = 0;
    ((LevelActor *)obj)->renderFlags = 0x17800074;
    func_80262480_de((char *)obj + 0x104);
    func_80262480_de((char *)obj + 0x118);
    Gobjinst_QueueAnimation(obj, 0);
    ((LevelActor *)obj)->flags = (((LevelActor *)obj)->flags & ~0x400) | 0x2100;
    Graphu64_IdentityMatrix((char *)obj + 0x74);
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
    
Actor_InitSpawnedActor
(obj, obj + 0x170, body_setup(obj));
    if (((LevelActor *)obj)->collisionEnabled != 0) {
        lean = -((LevelActor *)obj)->lean;
    }
    ((LevelActor *)obj)->controller = 0;
    if (effect != -1) {
        func_802193C8_de(obj + 0x204, effect, (char *)obj + 0x8);
    }
    world = &g_world;
    Gobjinst_LoadModel(obj, (s32)world->indexedDirectory, world->indexedBank, lean);
    if (delay != 0) {
        ((LevelActor *)obj)->animationTime = delay;
        ((LevelActor *)obj)->flags &= ~0x400;
    }
    ((LevelActor *)obj)->flags2E4 = Statinst_AdvanceResourceKey() << 10;
    if (((LevelActor *)obj)->flags & 8) {
        ((LevelActor *)obj)->update = D_0024A7A0;
        ((LevelActor *)obj)->lighting[0] = D_800D0EF8;
        ((LevelActor *)obj)->lighting[1] = D_800D0EF8;
    }
}

s32 Gobjinst_ChooseAnimationVariant(LevelActor *owner, s32 animationKind, s32 excludedEntry) {
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
    resource = Cache_RequestResource(0, ((struct Access_s32_C4 *)(owner))->field,
                             ((struct Access_s32_C4 *)(owner))->field, ((struct Access_s32_D0 *)(owner))->field,
                             0, 0, 0, g_lookupAIAnimTypeAnimObjectInfoText, 1);
    if (resource == 0) {
        goto fail;
    }
    data = SetN64_GetPackSection(*resource, 1);
    entries = &((struct func_80254D70_S2 *)(data))->unk8;
    total = ((struct func_80203E78_S1 *)(data))->unk4;
    count = Defs_FindSortedValue(entries, ((struct Access_s8_E6 *)(owner))->field, animationKind);
    if (count != -1) {
        original = count;
        while (count > 0) {
            if (entries[count - 1] != animationKind) {
                break;
            }
            count--;
        }

        Lists_ClearWeightedTable(&table);
        if (excludedEntry == -1) {
            while (count < total && entries[count] == animationKind) {
                Lists_AppendWeightedEntry(&table, count++, 10);
            }
        } else {
            while (count < total && entries[count] == animationKind) {
                if (excludedEntry != count) {
                    Lists_AppendWeightedEntry(&table, count, 10);
                }
                count++;
            }
        }
        if (table.count == 0) {
            Lists_AppendWeightedEntry(&table, original, 10);
        }
        count = Lists_ChooseWeightedTableEntry(&table);
    }
    Cache_UnlockResource(0, resource);
    return count;

fail:
    return -1;
}
