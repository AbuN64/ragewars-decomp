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

INCLUDE_ASM("span_1000", func_8028798C_de);

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
