#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SCENERECAT10C0.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"

/* Spawns an entity through func_80278C10_de when its bit is set in the current level's placement mask and it either names no flag or its flag in the global flag table D_8011FF08 is clear. */





extern void *D_8011FF08;
extern s32 func_8028FDF8_de(void *table, s32 index);
extern void func_80278C10_de(Entity *entity);

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
    mask = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(world->levels, 0), level), 2);
    func_8028FDB4_de(mask, 0);
    func_8028FDF8_de(mask, 1);
    bits = func_8028FDB4_de(mask, 1);
    bit = 1 << (index & 7);
    if (bits[index / 8] & bit) {
        if (entity->flag != 0) {
            flag = entity->flag;
            flags = func_8028FDB4_de(D_8011FF08, 1);
            func_8028FDB4_de(flags, 0);
            if (((unsigned char *)func_8028FDB4_de(flags, 1))[flag] != 0) {
                return;
            }
        }
        func_80278C10_de(entity);
    }
}

#ifdef NON_MATCHING
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C5208;
extern s32 func_80285180_de(void *, s32);
extern void *func_80254480_de(s32, void *, s32);
extern void func_80253D10_de(s32, void *, void *);
extern void func_8028FF0C_de(void *, void *, s32);
extern s32 func_8028FD90_de(void *);
extern s32 func_8028FDF8_de(void *, s32);
extern void func_802BD3A0_de(void *, void *, s32);
extern void func_8024F960_eu(void *, void *, s32, void *, f32);
extern void func_8024FD6C_eu(void *, void *, s32, void *);
extern void func_8024E990_de(void *, void *, s32, void *);
extern void func_80276CB0_de(void *, void *);
/* Packs a loaded scene's five resource tables into one buffer: header (a count word and offset words), then
 * the placed props (0xE8 bytes each, from tables 0 and 1), the placed actors (0x1C8 each, table 2, with a
 * visibility bit looked up per entry), the 0xC0-byte records of table 3 and the raw bytes of table 4, and
 * finally lets func_80289970_de position every actor against the packed records. */
void func_8028798C_de(void *scene, void *owner) {
    void *root;
    void *table0;
    void *table1;
    void *table2;
    void *table3;
    void *table4;
    s32 count0;
    s32 count1;
    s32 count2;
    s32 count3;
    s32 size0;
    s32 size2;
    s32 size3;
    s32 size4;
    s32 offset;
    s32 sections;
    s32 i;
    s32 j;
    u32 *buffer;
    u8 *header;
    u8 *props;
    u8 *actors;
    u8 *records;
    void *segments;
    void *pointers[0x80];
    CVector3 position;
    u8 *source;
    u8 *dest;
    if (func_80285180_de(owner, 1) == 0) {
        return;
    }
    root = **(void ***)owner;
    table0 = func_8028FDB4_de(root, 0);
    count0 = FIELD(s32, table0, 4);
    table1 = func_8028FDB4_de(root, 1);
    count1 = FIELD(s32, table1, 4);
    size0 = (count0 + count1) * 0xE8 + 8;
    table2 = func_8028FDB4_de(root, 2);
    count2 = FIELD(s32, table2, 4);
    size2 = count2 * 0x1C8 + 8;
    table3 = func_8028FDB4_de(root, 3);
    count3 = FIELD(s32, table3, 4);
    size3 = count3 * 0xC0 | 8;
    table4 = func_8028FDB4_de(root, 4);
    size4 = (*(s32 *)table4 * 4 + 0xF) & ~7;
    buffer = func_80254480_de(0, owner, 0x18 + size2 + size0 + size3 + size4);
    if (buffer != 0) {
        header = (u8 *)*(u32 **)buffer;
        offset = 0x18;
        sections = 1;
        *(s32 *)header = 0;
        FIELD(s32, header, 4) = 0x18;
        func_8028FF0C_de(table0, header + offset, 1);
        func_8028FF0C_de(table1, header + offset, 1);
        FIELD(s32, header, 0x18) = 0xE8;
        FIELD(s32, header + offset, 4) = count0 + count1;
        segments = (char *)func_8028FDB4_de(FIELD(void *, scene, 0x6C), 2) + 8;
        props = header + 0x20;
        for (i = 0; i < count0; i++) {
            func_8024F960_eu(props + i * 0xE8, (char *)table0 + 8 + i * 0x1C,
                             func_8028FE28_de(FIELD(void *, scene, 0x54), FIELD(void *, scene, 0x24), FIELD(u16, (char *)table0 + 8 + i * 0x1C, 8)),
                             segments, **(f32 **)((char *)scene + 0x20000 - 0x4D50));
        }
#if !defined(VERSION_DE)
        for (j = 0; j < count1; j++) {
            func_8024FD6C_eu(props + (j + count0) * 0xE8, (char *)table1 + 8 + j * 0x34,
                             func_8028FE28_de(FIELD(void *, scene, 0x54), FIELD(void *, scene, 0x24), FIELD(u16, (char *)table1 + 8 + j * 0x34, 0x28)),
                             segments);
        }
#endif
        offset += size0;
        *(s32 *)header = sections;
        FIELD(s32, header, 4 + *(s32 *)header * 4) = offset;
        func_8028FF0C_de(table2, header + offset, 1);
        sections++;
        FIELD(s32, header + offset, 0) = 0x1C8;
        FIELD(s32, header + offset, 4) = count2;
        actors = header + offset + 8;
        for (i = 0; i < count2; i++) {
            u8 *entry = actors + i * 0x1C8;
            s32 bit;
            u8 *bits;
            void *mask;
            func_8024E990_de(entry, (char *)table2 + 8 + i * 0x20,
                             func_8028FE28_de(FIELD(void *, scene, 0x54), FIELD(void *, scene, 0x24), FIELD(u16, (char *)table2 + 8 + i * 0x20, 0x14)),
                             segments);
            bit = FIELD(u16, entry, 0x19E);
            mask = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(FIELD(void *, scene, 0x80), 0), FIELD(s32, scene, 0x20000 - 0x4BF4)), 1);
            func_8028FDB4_de(mask, 0);
            func_8028FDF8_de(mask, 1);
            bits = func_8028FDB4_de(mask, 1);
            if (bits[bit / 8] & (1 << (bit & 7))) {
                FIELD(u16, entry, 0x19C) |= 1;
            }
        }
        offset += size2;
        *(s32 *)header = sections;
        sections++;
        FIELD(s32, header, 4 + *(s32 *)header * 4) = offset;
        func_8028FF0C_de(table3, header + offset, 1);
        FIELD(s32, header + offset, 0) = 0xC0;
        FIELD(s32, header + offset, 4) = count3;
        records = header + offset + 8;
        for (i = 0; i < count3; i++) {
            func_80276CB0_de(records + i * 0xC0, (char *)table3 + 8 + i * 0x4C);
        }
        offset += size3;
        *(s32 *)header = sections;
        sections++;
        FIELD(s32, header, 4 + *(s32 *)header * 4) = offset;
        func_802BD3A0_de(header + offset, table4, func_8028FD90_de(table4));
        *(s32 *)header = sections;
        FIELD(s32, header, 4 + sections * 4) = offset + size4;
        for (i = 0; i < count3; i++) {
            pointers[i] = records + i * 0xC0;
        }
        for (i = 0; i < count2; i++) {
            u8 *entry = actors + i * 0x1C8;
            position.x = FIELD(f32, entry, 0x8);
            position.y = FIELD(f32, entry, 0xC) + Particle_GetActorHeight((Actor_func_80214310_de *)entry) * D_800C5208;
            position.z = FIELD(f32, entry, 0x10);
            func_80289970_de((ObjectRecAtBC **)pointers, count3, &position, (Shared_ParticleLighting *)(entry + 0x1A8));
        }
    }
    func_80253D10_de(0, owner, buffer);
}
#else
INCLUDE_ASM("span_1000", func_8028798C_de);
#endif

#ifndef NON_MATCHING
INCLUDE_ASM("span_1000", func_80287F18_de);
#endif

#ifdef NON_MATCHING
#include "COMMON/WORLD.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/OBJRECAT5F14.H"

extern char D_80145040[];
extern Shared_Game D_801462C8;
extern Box D_800FF208;
extern Box D_801031F0;
extern s32 D_800CD6E0_de;
extern f32 D_800C520C;
extern s32 func_80245798_de(void);
extern void func_8022A1FC_de(void *pool, void *world);
extern s32 func_8024D160_de(void *actor);
extern s32 func_8024E1B4_de(void *actor);
extern void func_8024B8C4_de(void *actor);
extern f32 func_8023946C_de(void *camera, CVector3 *position);
extern s32 func_80296B74_de(void *planes, void *bounds);
extern void func_80262E88_de(struct SceneEffectPool *scene, void *world);

/* Whether the actor's bounding box overlaps the box. */
static inline s32 overlaps(LevelActor *actor, Box *box) {
    return actor->bounds.min.x < box->max.x && box->min.x < actor->bounds.max.x &&
           actor->bounds.min.z < box->max.z && box->min.z < actor->bounds.max.z &&
           actor->bounds.min.y < box->max.y && box->min.y < actor->bounds.max.y;
}

/* Per-frame visibility scan over the world's actors. Rebuilds the lists of registered, interactive, mover, flagged and
 * per-model actors from the actors that are visible this frame (inside the clip box and the camera frustum, or within
 * range for kind 14), copies each actor's visible bit into bit 15 of its flags, then culls the scene's effects. */
void func_80287F18_de(Shared_World *world) {
    LevelActor *actors;
    LevelActor *actor;
    GameplayCamera *camera;
    ActorDefinitionHeader *definition;
    u32 mask;
    s32 limit;
    s32 end;
    s32 i;
    s32 visible;
    s32 cull;

    mask = D_801462C8.sceneMask;
    world->registeredCount = 0;
    world->kind1Count = 0;
    world->flaggedCount = 0;
    func_8022A1FC_de(D_80145040, world);
    camera = 0;
    if (D_801462C8.local == 0) {
        camera = *(GameplayCamera **)(D_80145040 + 0x68);
    }
    cull = 0;
    if (func_80245798_de() == 0) {
        cull = world->visibilityEnabled == 0;
    }
    i = world->actorCapacity;
    end = world->actorCount;
    actors = (LevelActor *)world->actors;
    for (; i < end; i++) {
        actor = &actors[i];
        if (!(actor->flags & 0x100)) {
            continue;
        }
        definition = actor->definition;
        visible = 0;
        if (definition->gate & mask) {
            if (cull && !(actor->flags & 2) && actor->animationChanged == 0 && !(actor->flags & 0x400) &&
                definition->kind != 3 && (definition->kind == 14 || !func_8024D160_de(actor))) {
                if (definition->kind != 14 && !overlaps(actor, &D_800FF208)) {
                    visible = 0;
                } else if (definition->kind == 14) {
                    visible = func_8023946C_de(camera, &actor->position0) < D_800C520C;
                } else if (camera != 0) {
                    visible = func_80296B74_de(camera->clipPlanes, &actor->bounds);
                } else {
                    visible = 1;
                }
            } else if (definition->kind == 14) {
                visible = func_8023946C_de(camera, &actor->position0) < D_800C520C;
            } else {
                visible = overlaps(actor, &D_801031F0);
            }
        }
        if (func_80245798_de() && D_800CD6E0_de) {
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
        if (!visible) {
            actor->flags &= 0x7FFFFFFF;
            actor->flags &= ~0x200;
            continue;
        }
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
            ((u8 *)&actor->actionReady)[2] = world->kind1Count;
            world->kind1Count++;
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
    }
    func_80262E88_de((struct SceneEffectPool *)world->effectPool, world);
    world->kind1Cursor++;
    if (world->kind1Cursor >= world->kind1Count) {
        world->kind1Cursor = 0;
    }
}
#endif
