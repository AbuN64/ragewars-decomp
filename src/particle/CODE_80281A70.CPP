#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "TYPES.H"
#include "particle/8027A0F4_5.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "RENDER_2/8025DE50_5.H"
#include "particle/80271B18_3.H"
#include "SYSTEM_3/80265370_6.H"
extern char D_801379C0, D_8013B1A8;

/* Sets an actor's field 0x14C to 1 when something is near it: a world object from D_8011FE88 whose field 0x174 is positive within 256 units, a player from the D_80145060 list other than the actor's owner whose field 0x5E4 is positive within 256 units, or another actor of type 0xC or 0x22 from the given list within 512 units (all compared as squared distances). */








extern SharedPlayer *D_80145060;
extern void func_80271F68_de(CVector3 *out, CVector3 *a, CVector3 *b);

void func_80281A9C_de(s32 unused, Actor_func_80281A9C_de *actor, Actor_func_80281A9C_de **others, s32 count) {
    CVector3 delta;
    Shared_World *world;
    SharedPlayer *player;
    s32 i;
    s32 objectCount;

    world = &D_8011FE88;
    objectCount = world->kind1Count;
    for (i = 0; i < objectCount; i++) {
        if (world->kind1[i]->active > 0) {
            func_80271F68_de(&delta, &world->kind1[i]->position0, &actor->position);
            if (delta.x * delta.x + delta.y * delta.y + delta.z * delta.z <= 65536.0f) {
                actor->crowded = 1;
                return;
            }
        }
    }
    for (player = D_80145060; player != 0; player = player->views16E0.view16E0_1.next) {
        if (actor->owner != player && player->views5E4.view5E4_2.health > 0) {
            func_80271F68_de(&delta, &player->views0.view8_4.position, &actor->position);
            if (delta.x * delta.x + delta.y * delta.y + delta.z * delta.z <= 65536.0f) {
                actor->crowded = 1;
                return;
            }
        }
    }
    for (i = 0; i < count; i++) {
        if (others[i] != actor && (others[i]->type == 0xC || others[i]->type == 0x22)) {
            func_80271F68_de(&delta, &others[i]->position, &actor->position);
            if (delta.x * delta.x + delta.y * delta.y + delta.z * delta.z <= 262144.0f) {
                actor->crowded = 1;
                return;
            }
        }
    }
}

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
typedef struct ParticleEvents {
    struct IntPair params[14];
    u16 models[14],effects[14],sounds[14];
} ParticleEvents;
typedef struct ParticleConfig { char pad0[0x18]; ParticleEvents *events; } ParticleConfig;
typedef struct ParticleSprite { char pad0[0xc]; f32 scale; s16 x,y,z,active; } ParticleSprite;
typedef struct StepParticle {
    char pad0[4]; u16 type; char pad6[2]; CVector3 pos; char pad14[0x48]; u32 flags;
    char pad60[0xb8]; ParticleConfig *config; char pad11C[0x14]; s32 *references;
    char pad134[4]; ParticleSprite *sprite; char pad13C[4]; f32 time; char pad144[8]; s16 life;
    char pad14E[0x4a]; f32 alpha; char pad19C[0x34]; s8 bone; char pad1D1[8]; u8 render;
    char pad1DA[0xa]; void *list; char pad1E8[4]; struct StepParticle *next;
} StepParticle;
typedef struct ParticleList { StepParticle *head; char pad4[0x10]; } ParticleList;
typedef struct ParticleWorld { char pad0[0xfc00]; IntrusiveList free,render; ParticleList lists[3]; } ParticleWorld;
extern const f32 D_800C4E4C_de,D_800C4E50_de;
extern s32 D_801371DC;
extern Box D_801031F0;
extern void func_8027B720_de(void *),func_80279A00_de(void *),func_80284178_de(void *);
extern void func_802A42F4_de(void *,void *),func_80268C7C_de(void *,s32);
extern void func_80279B40_de(void *,s32,s32,s32);
extern void func_8025DE54_de(s16,CVector3,s32,s32);
extern void func_80271F68_de(CVector3 *,CVector3 *,CVector3 *);


void func_80281CA0_de(ParticleWorld *world) {
    StepParticle *selected[128];
    StepParticle *actors[128];
    struct IntPair params;
    CVector3 delta;
    ParticleList *list;
    StepParticle *p,*other,*node,*focus;
    StepParticle **out,**scan,**pairs,**begin;
    ParticleConfig *config;
    ParticleSprite *sprite;
    s32 count,idx,pairCount,total,i,j,event;
    s32 one;
    u32 model,effect,sound;
    f32 savedStep,range;
    f32 x,y,z;
    count = 0;
    idx = 0;
    savedStep = D_800D2988;
    list = world->lists;
    do {
        node = world->lists[idx].head;
        if (node != 0) {
            out = actors + count;
            do {
                ++count;
                node->flags = (node->flags & 0xFFEFFFFF) | 0x02000000;
                *out++ = node;
                node = node->next;
            } while (node != 0);
        }
        ++idx;
    } while (idx < 3);
    if (D_80146894 == 0 && D_801371DC == 0) {
        D_800D2988 = savedStep;
        D_800D2988 = savedStep * D_800CD740_de;
        one = 1;
        pairCount = 0;
        for (idx = 0; idx < count; ++idx) {
            p = actors[idx];
            if ((p->flags & 0x02000100) == 0x02000100) {
                p->flags &= 0xFFEFFF87;
                if (p->sprite) p->sprite->active = 0;
                if (p->time < (f32)p->life && p->life != one && !(p->flags & 0x1000)) {
                    x = p->pos.x;
                    if ((x < D_801031F0.max.x && (y=p->pos.y) < D_801031F0.max.y &&
                         (z=p->pos.z) < D_801031F0.max.z && D_801031F0.min.x <= x &&
                         D_801031F0.min.y <= y && D_801031F0.min.z <= z) || p->type == 0x41E) {
                        func_8027B720_de(p);
                        sprite = p->sprite;
                        if (sprite) {
                            sprite->active = one;
                            sprite->x = (s16)(s32)p->pos.x;
                            sprite->y = (s16)(s32)p->pos.y;
                            sprite->z = (s16)(s32)p->pos.z;
                            sprite->scale = p->alpha * D_800C4E4C_de;
                        }
                        p->time += D_800D2988;
                        goto collect;
                    }
                    if (!(p->flags & 0x100)) continue;
                    if (!(p->flags & 0x800)) {
    func_80279A00_de(p);
    if (p->render) {
        func_80284178_de(p);
        func_802A42F4_de(&D_801379C0,p);
    }
    if (p->sprite) {
        func_80268C7C_de(&D_8013B1A8,(s32)p->sprite);
        p->sprite = 0;
    }
    if (p->references) --*p->references;
    p->flags &= 0xFDFFFEFF;
    func_80255ED8_de(p->list,p);
    p->list = 0;
    func_80255CB8_de(&world->free,p);
    if (p->flags & 0x01000000) func_80255ED8_de(&world->render,p);
                    }
                } else {
                    config = p->config;
                    event = func_80284068_de(p) ? 12 : 10;
                    model = config->events->models[event];
                    effect = config->events->effects[event];
                    params = config->events->params[event];
                    sound = config->events->sounds[event];
                    if (effect != 65535) func_80265E10_de(p,p,effect,-1,p->pos,params);
                    if (model != 65535) func_80279B40_de(p,model,p->bone,1);
                    if (sound != 65535) func_8025DE54_de((s16)sound,p->pos,0,-1);
                    if (!(p->flags & 0x100)) continue;
                    if (!(p->flags & 0x800)) {
    func_80279A00_de(p);
    if (p->render) {
        func_80284178_de(p);
        func_802A42F4_de(&D_801379C0,p);
    }
    if (p->sprite) {
        func_80268C7C_de(&D_8013B1A8,(s32)p->sprite);
        p->sprite = 0;
    }
    if (p->references) --*p->references;
    p->flags &= 0xFDFFFEFF;
    func_80255ED8_de(p->list,p);
    p->list = 0;
    func_80255CB8_de(&world->free,p);
    if (p->flags & 0x01000000) func_80255ED8_de(&world->render,p);
                    }
                }
collect:
                if (p->flags & 0x100) {
                    switch (p->type) {
                    case 12: case 34: case 87:
                        selected[pairCount++] = p;
                        break;
                    }
                }
            }
        }
        i = 0;
        if (pairCount != 0 && pairCount > 0) {
            range = D_800C4E50_de;
            begin = selected;
            scan = begin;
            for (i = 0; i < pairCount; ++i) {
                focus = *scan;
                switch (focus->type) {
                case 34:
                    func_80281A9C_de((s32)world,focus,begin,pairCount);
                    ++scan;
                    break;
                case 87:
                    j = 0;
                    if (pairCount > 0) {
                        pairs = begin;
                        do {
                            p = *pairs;
                            if (p->type == 87) ++j;
                            else {
                                func_80271F68_de(&delta,&p->pos,&focus->pos);
                                ++j;
                                if (delta.x*delta.x + delta.y*delta.y + delta.z*delta.z <= range) p->life = 1;
                            }
                            ++pairs;
                        } while (j < pairCount);
                    }
                default: case 12:
                    ++scan;
                    break;
                }
            }
        }
        D_800D2988 = savedStep;
    }
}
#else
INCLUDE_ASM("span_1000", func_80281CA0_de);
#endif

#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "gbi.h"
/* A particle on the world's render list; the list links through next. */
typedef struct DrawParticle {
    Shared_Particle particle;
    char reserved1DC[0x18];
    struct DrawParticle *next;
} DrawParticle;
/* The particle world as the draw pass sees it: the free list, then the render list. */
typedef struct ParticleDrawWorld {
    char reserved[0xFC00];
    IntrusiveList free;
    IntrusiveList render;
} ParticleDrawWorld;
struct Shared_ParticleView;
extern Gfx *D_80110634;
extern Globals_func_804220A8_de D_80140FE8_de;
extern s32 D_80140FF8, D_800D297C;
extern float D_800C4E54_de;
extern void func_8026D914_de(s32 arg0);
extern void Particle_BuildMatrix(Shared_Particle *particle, void *matrix, void *camera, f32 depth);
extern s32 func_80296B74_de(f32 (*planes)[4], Box *box);
extern void Particle_DrawModel(void *arg0, struct Shared_ParticleView *arg1);
extern void Particle_DrawSprite(Shared_Particle *particle, struct Shared_ParticleView *view);
extern void func_802A58B0_de(ObjRecAt7528 *arg0, Shared_Particle *arg1, PackedMatrixWords *matrix);
void Particle_DrawRenderList(ParticleDrawWorld *world, struct Shared_ParticleView *view) {
    Box box;
    CVector3 transformed;
    DrawParticle *node;
    s32 visible, built;
    f32 zScale, xyScale, xScale, maximum, height, radius;
    f32 minX, maxX, minY, maxY, minZ, maxZ;
    f32 depth;
    ParticleView *camera;
    u32 skipAttached;
    if (world->render.head != 0) {
        gDPPipeSync(D_80110634++);
        gDPSetAlphaDither(D_80110634++, G_AD_NOISE);
        func_8026D914_de(0x80);
        gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
        gSPGeometryMode(D_80110634++, 0x60400, 0);
        for (node = world->render.head; node != 0; node = node->next) {
            visible = 0;
            built = node->particle.flags & 0x100000;
            if (node->particle.inst.unk14 == 0) {
                if (!(node->particle.flags & 0x400000) && node->particle.desc->renderModel == 0) {
                    zScale = node->particle.size.z;
                    xyScale = node->particle.size.y * zScale;
                    xScale = node->particle.size.x * zScale;
                    if (!(xScale <= xyScale)) xyScale = xScale;
                    maximum = zScale;
                    if (!(xyScale <= maximum)) maximum = xyScale;
                    height = maximum * D_800C4E54_de;
                    radius = height * D_800C4E58_de[0];
                    minX = node->particle.inst.pos.x - radius;
                    box.min.x = minX;
                    maxX = node->particle.inst.pos.x + radius;
                    box.max.x = maxX;
                    minY = node->particle.inst.pos.y - radius;
                    box.min.y = minY;
                    maxY = node->particle.inst.pos.y + height;
                    box.max.y = maxY;
                    minZ = node->particle.inst.pos.z - radius;
                    box.min.z = minZ;
                    maxZ = node->particle.inst.pos.z + radius;
                    box.max.z = maxZ;
                    if (minX < view->clipMax.x && view->clipMin.x < maxX &&
                        minZ < view->clipMax.z && view->clipMin.z < maxZ &&
                        minY < view->clipMax.y && view->clipMin.y < maxY &&
                        func_80296B74_de(view->clipMatrix, &box)) {
                        visible = 1;
                    }
                } else visible = 1;
            }
            do {
                if (visible) {
                    if (!built) {
                        if (D_80140FF8 == 1) {
                            camera = D_80140FE8_de.object;
                            func_80272898_de(&camera->particleViewMatrix, &node->particle.inst.pos, &transformed);
                            depth = transformed.z;
                            if (depth < 0.0f) depth = -depth;
                            Particle_BuildMatrix(&node->particle, &node->particle.mtx[D_800D297C], camera, depth);
                        } else {
                            Particle_BuildMatrix(&node->particle, &node->particle.mtx[D_800D297C], 0, 0.0f);
                        }
                        node->particle.flags |= 0x100000;
                    }
                    if (node->particle.desc->renderModel != 0) Particle_DrawModel(node, view);
                    else Particle_DrawSprite(&node->particle, view);
                    if (node->particle.desc->flags & 0x100000) {
                        func_8027E784_de(&node->particle, view);
                    }
                    if (!node->particle.drawWhenHidden || built) break;
                    skipAttached = node->particle.desc->flags & 0x10000;
                } else {
                    if (!node->particle.drawWhenHidden || built) break;
                    if (D_80140FF8 == 1) {
                        camera = D_80140FE8_de.object;
                        func_80272898_de(&camera->particleViewMatrix, &node->particle.inst.pos, &transformed);
                        depth = transformed.z;
                        if (depth < 0.0f) depth = -depth;
                        Particle_BuildMatrix(&node->particle, &node->particle.mtx[D_800D297C], camera, depth);
                    } else {
                        Particle_BuildMatrix(&node->particle, &node->particle.mtx[D_800D297C], 0, 0.0f);
                    }
                    node->particle.flags |= 0x100000;
                    skipAttached = node->particle.desc->flags & 0x10000;
                }
                if (!skipAttached) {
                    func_802A58B0_de(&D_801379C0, &node->particle, &node->particle.mtx[D_800D297C]);
                }
            } while (0);
        }
        gDPPipeSync(D_80110634++);
        gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
        func_8026D914_de(0);
        gDPSetAlphaDither(D_80110634++, G_AD_NOTPATTERN);
    }
}

#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
typedef struct DraftActions827C8 {
    struct IntPair params[14]; u16 animation[14], effect[14], sound[14];
} DraftActions827C8;
typedef struct DraftModel827C8 { u8 pad[0x18]; DraftActions827C8 *actions; } DraftModel827C8;
typedef struct DraftActor827C8 {
    u8 pad[4]; u16 type; u8 pad6[2]; CVector3 position;
    u8 pad14[0x48]; u32 flags; u8 pad60[0xB8]; DraftModel827C8 *model;
    u8 pad11C[0x10]; s32 owner; s32 *refs; u8 pad134[4]; s32 effect;
    u8 pad13C[0x94]; s8 animation; u8 pad1D1[8]; u8 linked;
    u8 pad1DA[0xA]; void *list; u8 pad1E8[4]; struct DraftActor827C8 *next;
} DraftActor827C8;
typedef struct DraftWorld827C8 { u8 pad[0xFC00]; u8 freeList[0x14], activeList[0x14], padFC28[0x14]; DraftActor827C8 *actors; } DraftWorld827C8;
extern void func_80279B40_de(void *, s32, s32, s32), func_80279A00_de(void *), func_80284178_de(void *);
extern void func_802A42F4_de(void *, void *);
void Particle_ReleaseOwnerEmitters(DraftWorld827C8 *world, s32 owner)
{
  DraftActor827C8 *actor;
  DraftActor827C8 *next;
  DraftActions827C8 *actions;
  DraftModel827C8 *model;
  struct IntPair params;
  s32 animation;
  s32 effect;
  s32 sound;
  s32 count = 0;
  s32 index;
  actor = world->actors;
  while (actor)
  {
    next = actor->next;
    if (((actor->type == 0x41E) && (actor->flags & 0x100)) && (actor->owner == owner))
    {
      model = actor->model;
      actor->flags &= ~0x100;
      index = (func_80284068_de(actor)) ? (12) : (10);
      actions = model->actions;
      animation = actions->animation[index];
      effect = actions->effect[index];
      params = actions->params[index];
      sound = model->actions->sound[index];
      if (effect != 0xFFFF)
      {
        func_80265E10_de(actor, actor, effect, -1, actor->position, params);
      }
      if (animation != 0xFFFF)
      {
        func_80279B40_de(actor, animation, actor->animation, 1);
      }
      if (sound != 0xFFFF)
      {
        func_8025DE54_de((s16) sound, actor->position, 0, -1);
      }
      actor->flags |= 0x100;
      if (actor->flags & 0x100)
      {
      if (!(actor->flags & 0x800))
      {
        func_80279A00_de(actor);
        if (actor->linked)
        {
          func_80284178_de(actor);
          func_802A42F4_de(&D_801379C0, actor);
        }
        if (actor->effect)
        {
          func_80268C7C_de(&D_8013B1A8, actor->effect);
          actor->effect = 0;
        }
        if (actor->refs)
        {
          --(*actor->refs);
        }
        actor->flags &= 0xFDFFFEFF;
        func_80255ED8_de(actor->list, actor);
        actor->list = 0;
        func_80255CB8_de(world->freeList, actor);
        if (actor->flags & 0x1000000)
        {
          func_80255ED8_de(world->activeList, actor);
        }
      }
      }
      count++;
    }
    actor = next;
  }

  if (count)
  {
    func_8025DF34_de(0x91A);
    func_8025DF34_de(0x91A);
  }
}

#include "TYPES.H"

typedef struct EffectTable {
    struct IntPair pairs[14];
    u16 animations[14], effects[14], sounds[14];
} EffectTable;
typedef struct ActorDefinition {
    u32 flags;
    char pad04[0x14];
    EffectTable *effects;
} ActorDefinition;
typedef struct Actor {
    char pad00[4]; u16 kind; char pad06[2];
    CVector3 position;
    char pad14[0x48]; u32 flags;
    char pad60[0xB8]; ActorDefinition *definition;
    char pad11C[0x14]; s32 *counter; void *owner; s32 handle;
    char pad13C[0x94]; s8 channel; char pad1D1[8]; u8 linked;
    char pad1DA[0xA]; void *list;
    char pad1E8[4]; struct Actor *next;
} Actor;
typedef struct ActorWorld {
    char pad00[0xFC00]; IntrusiveList active, secondary;
    char padFC28[0x14]; Actor *head;
} ActorWorld;
extern void func_80279B40_de(void *, s32, s32, s32);
extern void func_80279A00_de(void *);
extern void func_80284178_de(void *);
extern void func_802A42F4_de(void *, void *);

void Particle_RetireOwnedActors(ActorWorld *world, void *owner) {
    Actor *actor, *next;
    ActorDefinition *definition;
    s32 index;
    s32 animation, effect, sound;
    struct IntPair pair;
    actor = world->head;
    while (actor != 0) {
        next = actor->next;
        if ((actor->kind == 0x41E || actor->kind == 0x3EF) &&
            (actor->flags & 0x100) && actor->owner == owner) {
            definition = actor->definition;
            index = func_80284068_de(actor) ? 12 : 10;
            animation = definition->effects->animations[index];
            effect = definition->effects->effects[index];
            pair = definition->effects->pairs[index];
            sound = definition->effects->sounds[index];
            if (effect != 0xFFFF)
                func_80265E10_de(actor, actor, effect, -1, actor->position, pair);
            if (animation != 0xFFFF)
                func_80279B40_de(actor, animation, actor->channel, 1);
            if (sound != 0xFFFF)
                func_8025DE54_de((s16)sound, actor->position, 0, -1);
            if (actor->flags & 0x100) {
                if (!(actor->flags & 0x800)) {
                    func_80279A00_de(actor);
                    if (actor->linked) {
                        func_80284178_de(actor);
                        func_802A42F4_de(&D_801379C0, actor);
                    }
                    if (actor->handle) {
                        func_80268C7C_de(&D_8013B1A8, actor->handle);
                        actor->handle = 0;
                    }
                    if (actor->counter) --*actor->counter;
                    actor->flags &= 0xFDFFFEFF;
                    func_80255ED8_de(actor->list, actor);
                    actor->list = 0;
                    func_80255CB8_de(&world->active, actor);
                    if (actor->flags & 0x1000000)
                        func_80255ED8_de(&world->secondary, actor);
                }
            }
        }
        actor = next;
    }
}
