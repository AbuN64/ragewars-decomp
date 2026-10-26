#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SCENERECAT10C0.H"
#include "SCENE/80286050.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/* Spawns an entity through Actors_DispatchTrigger when its bit is set in the current level's placement mask and it either names no flag or its flag in the global flag table D_8011FF08 is clear. */





extern s32 func_8028FDF8_de(void *table, s32 index);
extern void Actors_DispatchTrigger(Entity *entity);

void func_8028787C_de(World_func_8028787C_de *world, Entity *entity) {
    s32 index;
    s32 level;
    void *mask;
    unsigned char *bits;
    void *flags;
    s32 flag;
    s32 bit;

    index = entity->index;
    level = world->level;
    mask = Render_GetPackSection(Render_GetPackSection(Render_GetPackSection(world->levels, 0), level), 2);
    Render_GetPackSection(mask, 0);
    func_8028FDF8_de(mask, 1);
    bits = Render_GetPackSection(mask, 1);
    bit = 1 << (index & 7);
    if (bits[index / 8] & bit) {
        if (entity->flag != 0) {
            flag = entity->flag;
            flags = Render_GetPackSection(g_world.bitSections, 1);
            Render_GetPackSection(flags, 0);
            if (((unsigned char *)Render_GetPackSection(flags, 1))[flag] != 0) {
                return;
            }
        }
        Actors_DispatchTrigger(entity);
    }
}

#include "COMMON/WORLD.H"
#include "COMMON/OBJB.H"
#include "COMMON/PROPGEOMETRY.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/EXTERNS_14.H"

/* A resource's block set: the count of blocks and the byte offset of each from the set's start. */
typedef struct BlockSet {
    s32 count;
    s32 offsets[1];
} BlockSet;

/* A run of equal-sized records: record size, count, then the records. */
typedef struct RecordSet {
    s32 size;
    s32 count;
} RecordSet;

/* A simple (animated, unlit-by-grid) instance as the level resource stores it. */
typedef struct SimpleInstanceRecord {
    s32 visBits;
    CVector3 position;
    f32 maxRadius;
    u16 type;
    u16 region;
    u16 flags;
    u16 id;
    u16 variation;
    s8 rotY;
    u8 pad;
} SimpleInstanceRecord;

/* A simple instance in the game: the header's position, its flags and id, and the lighting baked from the level's
 * light volumes. */
typedef struct SimpleInstance {
    u8 header[8];
    CVector3 position;
    u8 pad14[0x19C - 0x14];
    u16 flags;
    u16 id;
    u8 pad1A0[0x1A8 - 0x1A0];
    Shared_ParticleLighting light;
    u8 pad1C0[0x1C8 - 0x1C0];
} SimpleInstance;

/* A light volume as the level resource stores it. */
typedef struct LightVolumeRecord {
    u8 data[0x4C];
} LightVolumeRecord;

extern s32 func_8028FDF8_de(void *table, s32 index);
extern s32 Render_GetPackSize(void *table);
extern s32 Render_GetDirectoryEntry(s32 *directory, s32 bank, s32 type);
extern void *Scene_AllocResourceBlock(s32 pool, void *handle, s32 size);
extern void Scene_ReplaceResourceBlock(s32 pool, void *handle, void *block);
extern void Render_TransposeRecords(void *src, void *dst, s32 arg2);
extern void func_802BD3A0_de(void *dst, void *src, s32 size);
extern void func_8024F960_eu(PlacedProp *prop, RecordRecAt1A *record, s32 owner, char *segments, f32 spacing);
extern void World_InitPlacedProp(PlacedProp *prop, PlacedPropRecord *record, s32 owner, char *segments);
extern void World_InitSimpleInstance(SimpleInstance *instance, SimpleInstanceRecord *record, s32 owner, char *segments);
extern void Anim_DecodeBoxTransform(ObjectRecAtBC *volume, LightVolumeRecord *record);
extern f32 Particle_GetActorHeight(void *);

#define ALIGN8(size) (((size) + 7) & ~7)

/* Whether the instance's bit is set in the current level's instance mask (section 1 of the level's bit sections).
 * The same body as func_8028B988_de; the ROM inlines it here. */
static inline s32 Engine_TestInstanceBit(Shared_World *world, SimpleInstance *instance) {
    s32 index;
    void *sections;
    s32 level;
    void *mask;
    u8 *bits;
    s32 bit;

    index = instance->id;
    sections = world->bitSections;
    level = world->level;
    mask = Render_GetPackSection(Render_GetPackSection(Render_GetPackSection(sections, 0), level), 1);
    Render_GetPackSection(mask, 0);
    func_8028FDF8_de(mask, 1);
    bits = Render_GetPackSection(mask, 1);
    bit = 1 << (index & 7);
    return (bits[index / 8] & bit) != 0;
}

/* Builds a level's placed instances into one pool block of five sections: props (efficient then static records),
 * simple instances (flagged when the level's instance mask has their bit), light volumes, and a copy of the bit set.
 * Each simple instance then takes its lighting from the volumes at half its actor height. */
void Engine_BuildPlacedInstances(Shared_World *world, void ***handle) {
    ObjectRecAtBC *volumeList[128];
    CVector3 position;
    BlockSet *bitSet;
    RecordSet *efficientSet;
    RecordSet *simpleSet;
    RecordSet *volumeSet;
    char *base;
    s32 staticCount;
    s32 simpleCount;
    s32 volumeCount;
    s32 staticSize;
    s32 simpleSize;
    s32 volumeSize;
    s32 bitSize;
    PlacedPropRecord *statics;
    SimpleInstance *simples;
    char *segments;
    void **block;
    BlockSet *source;
    RecordSet *staticSet;
    s32 efficientCount;
    BlockSet *blocks;
    char *dst;
    s32 offset;
    s32 n;
    s32 i;
    s32 j;
    s32 k;
    PlacedProp *props;
    RecordRecAt1A *efficient;
    SimpleInstanceRecord *simpleRecords;
    LightVolumeRecord *volumeRecords;
    ObjectRecAtBC *volumes;
    void *objects;

    if (Render_UnpackResource(handle, 1) != 0) {
        source = **handle;
        efficientSet = Render_GetPackSection(source, 0);
        efficientCount = efficientSet->count;
        staticSet = Render_GetPackSection(source, 1);
        staticCount = staticSet->count;
        staticSize = ALIGN8((efficientCount + staticCount) * sizeof(PlacedProp) + sizeof(RecordSet));
        simpleSet = Render_GetPackSection(source, 2);
        simpleCount = simpleSet->count;
        simpleSize = ALIGN8(simpleCount * sizeof(SimpleInstance) + sizeof(RecordSet));
        volumeSet = Render_GetPackSection(source, 3);
        volumeCount = volumeSet->count;
        volumeSize = ALIGN8(volumeCount * sizeof(ObjectRecAtBC) + sizeof(RecordSet));
        bitSet = Render_GetPackSection(source, 4);
        bitSize = ALIGN8(bitSet->count * sizeof(s32) + sizeof(RecordSet));
        block = Scene_AllocResourceBlock(0, handle, staticSize + 0x18 + simpleSize + volumeSize + bitSize);
        if (block != 0) {
            n = 0;
            offset = 0x18;
            blocks = *block;
            dst = (char *)blocks + offset;
            blocks->count = n++;
            blocks->offsets[blocks->count] = offset;
            Render_TransposeRecords(efficientSet, dst, 1);
            Render_TransposeRecords(staticSet, dst, 1);
            ((RecordSet *)dst)->size = sizeof(PlacedProp);
            ((RecordSet *)dst)->count = efficientCount + staticCount;
            efficient = (RecordRecAt1A *)(efficientSet + 1);
            objects = Render_GetPackSection(world->modelSections, 2);
            statics = (PlacedPropRecord *)(staticSet + 1);
            props = (PlacedProp *)(dst + 8);
            base = (char *)blocks;
            segments = (char *)objects + 8;
            for (i = 0; i < efficientCount; i++) {
                func_8024F960_eu(&props[i], &efficient[i],
                                 Render_GetDirectoryEntry(world->indexedDirectory, world->indexedBank, efficient[i].id),
                                 segments, world->levelInfo->m_GridDistance);
            }
            for (j = 0; j < staticCount; j++) {
                World_InitPlacedProp(&props[j + efficientCount], &statics[j],
                                 Render_GetDirectoryEntry(world->indexedDirectory, world->indexedBank, statics[j].id),
                                 segments);
            }

            offset += staticSize;
            blocks->count = n++;
            blocks->offsets[blocks->count] = offset;
            Render_TransposeRecords(simpleSet, base + offset, 1);
            ((RecordSet *)(base + offset))->size = sizeof(SimpleInstance);
            ((RecordSet *)(base + offset))->count = simpleCount;
            simpleRecords = (SimpleInstanceRecord *)(simpleSet + 1);
            simples = (SimpleInstance *)(base + offset + 8);
            for (k = 0; k < simpleCount; k++) {
                World_InitSimpleInstance(&simples[k], &simpleRecords[k],
                                 Render_GetDirectoryEntry(world->indexedDirectory, world->indexedBank, simpleRecords[k].type),
                                 segments);
                if (Engine_TestInstanceBit(world, &simples[k])) {
                    simples[k].flags |= 1;
                }
            }

            offset += simpleSize;
            blocks->count = n++;
            blocks->offsets[blocks->count] = offset;
            Render_TransposeRecords(volumeSet, base + offset, 1);
            ((RecordSet *)(base + offset))->size = sizeof(ObjectRecAtBC);
            ((RecordSet *)(base + offset))->count = volumeCount;
            volumeRecords = (LightVolumeRecord *)(volumeSet + 1);
            volumes = (ObjectRecAtBC *)(base + offset + 8);
            for (i = 0; i < volumeCount; i++) {
                Anim_DecodeBoxTransform(&volumes[i], &volumeRecords[i]);
            }

            offset += volumeSize;
            blocks->count = n++;
            blocks->offsets[blocks->count] = offset;
            func_802BD3A0_de(base + offset, bitSet, Render_GetPackSize(bitSet));

            blocks->count = n++;
            offset += bitSize;
            blocks->offsets[blocks->count] = offset;

            for (i = 0; i < volumeCount; i++) {
                volumeList[i] = &volumes[i];
            }
            for (k = 0; k < simpleCount; k++) {
                position.x = simples[k].position.x;
                position.y = simples[k].position.y + Particle_GetActorHeight(&simples[k]) * 0.5f;
                position.z = simples[k].position.z;
                Engine_SampleVolumeLighting(volumeList, volumeCount, &position, &simples[k].light);
            }
        }
        Scene_ReplaceResourceBlock(0, handle, block);
    }
}

#include "COMMON/WORLD.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/OBJRECAT5F14.H"

extern Shared_MenuData D_80145040;
extern Box D_801031F0;
extern s32 D_800CD6E0_de;
extern f32 D_800C520C;
extern s32 Camera_IsSequenceInWindow(void);
extern void func_8022A1FC_de(void *pool, void *world);
extern s32 func_8024D160_de(void *actor);
extern s32 func_8024E1B4_de(void *actor);
extern void func_8024B8C4_de(void *actor);
extern f32 Camera_GetDistanceTo(void *camera, CVector3 *position);
extern s32 func_80296B74_de(void *planes, void *bounds);
extern void AnimPool_UpdateSceneEffects(struct SceneEffectPool *scene, void *world);

typedef struct SceneVisibilitySettings {
    u32 mask;
    u8 reserved04[0x11];
    u8 local;
} SceneVisibilitySettings;

/* Whether the actor's bounding box overlaps the box. */
#define ACTOR_OVERLAPS(actor, box) ((box)->x > (actor)->bounds.min.x && \
    ((Box *)((u8 *)(box) - 12))->min.x < (actor)->bounds.max.x && \
    (box)->z > (actor)->bounds.min.z && \
    ((Box *)((u8 *)(box) - 12))->min.z < (actor)->bounds.max.z && \
    (box)->y > (actor)->bounds.min.y && \
    ((Box *)((u8 *)(box) - 12))->min.y < (actor)->bounds.max.y)

/* Per-frame visibility scan over the world's actors. Rebuilds the lists of registered, interactive, mover, flagged and
 * per-model actors from the actors that are visible this frame (inside the clip box and the camera frustum, or within
 * range for kind 14), copies each actor's visible bit into bit 15 of its flags, then culls the scene's effects. */

void Engine_UpdateActorVisibility(Shared_World *world) {
    SceneVisibilitySettings *settings;
    LevelActor *actors;
    LevelActor *actor;
    GameplayCamera *camera;
    ActorDefinitionHeader *definition;
    CVector3 *clipBox;
    CVector3 *rangeBox;
    s32 end;
    u32 mask;
    s32 i;
    s32 visible;
    s32 cull;

    settings = (SceneVisibilitySettings *)&D_80145040.game.sceneMask;
    mask = settings->mask;
    world->registeredCount = 0;
    world->kind1Count = 0;
    world->flaggedCount = 0;
    func_8022A1FC_de((u8 *)settings - 0x1290, world);
    camera = 0;
    if (settings->local == 0) {
        camera = *(GameplayCamera **)((u8 *)settings - 0x1228);
    }
    cull = 0;
    if (Camera_IsSequenceInWindow() == 0) {
        cull = world->visibilityEnabled == 0;
    }
    i = world->actorCapacity;
    end = world->actorCount;
    actors = (LevelActor *)world->actors;
    for (; i < end; i++) {
        clipBox = &D_800FF208.max;
        rangeBox = &D_801031F0.max;
        actor = &actors[i];
        if (!(actor->flags & 0x100)) {
            continue;
        }
        definition = actor->definition;
        visible = 0;
        if (definition->gate & mask) {
            if (cull && !(actor->flags & 2) && actor->animationChanged == 0 &&
                !(actor->flags & 0x400) && definition->kind != 3) {
                if (definition->kind == 14) {
                    goto distance_visible;
                }
                if (!func_8024D160_de(actor)) {
                    if (ACTOR_OVERLAPS(actor, clipBox)) {
                        if (camera != 0) {
                            visible = func_80296B74_de(camera->clipPlanes, &actor->bounds);
                        } else {
                            visible = 1;
                        }
                    }
                    goto visibility_ready;
                }
            }
            if (definition->kind == 14) {
            distance_visible:
                if (Camera_GetDistanceTo(camera, &actor->position0) < D_800C520C) {
                    visible = 1;
                }
            } else {
                visible = ACTOR_OVERLAPS(actor, rangeBox);
            }
        }
    visibility_ready:
        if (Camera_IsSequenceInWindow() && D_800CD6E0_de) {
            if (!(definition->gate & 0x200)) {
                visible = 0;
            }
        } else if (!(definition->gate & 0x100) && definition->kind != 11 && definition->kind != 14) {
            visible = 0;
        }
        if (actor->flags < 0) {
            actor->flags |= 0x8000;
        } else {
            actor->flags &= ~0x8000;
        }
        if (visible) {
            actor->flags |= 0x80000000;
            if (definition->kind == 14) {
                continue;
            }
            func_8024B8C4_de(actor);
            if (func_8024D160_de(actor) && world->interactiveCount != 0x200) {
                world->interactive[world->interactiveCount++] = actor;
            }
            if (func_8024E1B4_de(actor) && world->moverCount != 0x80) {
                world->movers[world->moverCount++] = actor;
            }
            if (world->registeredCount < 0x80) {
                world->registered[world->registeredCount++] = actor;
            }
            if (world->kind1Count < 0x40 && actor->definition->kind == 1) {
                world->kind1[world->kind1Count] = actor;
                /* byte 0x23E of the word actionReady holds the slot */
                ((u8 *)&actor->actionReady)[2] = world->kind1Count++;
            }
            if (world->flaggedCount < 0x20 && (actor->flags & 2)) {
                world->flagged[world->flaggedCount++] = actor;
            }
            if (world->kind5Count < 0x10 && actor->definition->kind == 5) {
                world->kind5[world->kind5Count++] = actor;
            }
            if (world->model64FCount < 0x20 && actor->type == 0x64F) {
                world->model64F[world->model64FCount++] = actor;
            }
            if (actor->type == 0x64D && world->model64DCount < 4) {
                world->model64D[world->model64DCount++] = actor;
            }
        } else {
            actor->flags &= 0x7FFFFFFF;
            actor->flags &= ~0x200;
        }
    }
    AnimPool_UpdateSceneEffects((struct SceneEffectPool *)world->effectPool, world);
    world->kind1Cursor++;
    if (world->kind1Cursor >= world->kind1Count) {
        world->kind1Cursor = 0;
    }
}
#undef ACTOR_OVERLAPS
