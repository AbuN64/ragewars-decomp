#include "TYPES.H"
#include "shared/func_8021E2A0_de_closed.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
typedef struct ParticleEvents {
    struct IntPair params[14];
    u16 models[14],effects[14],sounds[14];
} ParticleEvents;
typedef struct ParticleConfig { char pad0[0x18]; ParticleEvents *events; } ParticleConfig;
typedef struct ParticleSprite { char pad0[0xc]; f32 scale; s16 x,y,z,active; } ParticleSprite;
typedef struct StepParticle {
    char pad0[4]; u16 type; char pad6[2]; Vec3 pos; char pad14[0x48]; u32 flags;
    char pad60[0xb8]; ParticleConfig *config; char pad11C[0x14]; s32 *references;
    char pad134[4]; ParticleSprite *sprite; char pad13C[4]; f32 time; char pad144[8]; s16 life;
    char pad14E[0x4a]; f32 alpha; char pad19C[0x34]; s8 bone; char pad1D1[8]; u8 render;
    char pad1DA[0xa]; void *list; char pad1E8[4]; struct StepParticle *next;
} StepParticle;
typedef struct ParticleList { StepParticle *head; char pad4[0x10]; } ParticleList;
typedef struct ParticleWorld { char pad0[0xfc00]; IntrusiveList free,render; ParticleList lists[3]; } ParticleWorld;
extern const f32 D_800C4E4C_de,D_800C4E50_de;
extern s32 D_80146894,D_801371DC;
extern Box D_801031F0;
extern IntrusiveList D_801379C0,D_8013B1A8;
extern void func_8027B720_de(void *),func_80279A00_de(void *),func_80284178_de(void *);
extern void func_802A42F4_de(void *,void *),func_80268C7C_de(void *,s32);
extern void func_80255ED8_de(void *,void *),func_80255CB8_de(void *,void *);
extern void func_80265E10_de(void *,void *,u16,s32,Vec3,struct IntPair);
extern void func_80279B40_de(void *,s32,s32,s32);
extern void func_8025DE54_de(s16,Vec3,s32,s32);
extern void func_80281A9C_de(s32,void *,void *,s32);
extern void func_80271F68_de(Vec3 *,Vec3 *,Vec3 *);


void func_80281CA0_de(ParticleWorld *world) {
    StepParticle *selected[128];
    StepParticle *actors[128];
    struct IntPair params;
    Vec3 delta;
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
