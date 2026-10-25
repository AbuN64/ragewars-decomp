#include "include_asm.h"

#include "stddef.h"
#include "TYPES.H"
#include "COMMON/SHARED_WORLDFUNC.H"

typedef struct Team {
    char pad0[0x92];
    u8 id;
} Team;

typedef struct Racer {
    char pad0[0x8];
    f32 pos[3];
    char pad14[0x5D8 - 0x14];
    Team *team;
    char pad5DC[0x5E4 - 0x5DC];
    s32 stateBits;
} Racer;

typedef struct Rules {
    char pad0[0x24];
    s32 teamsEnabled;
} Rules;

typedef struct World {
    char pad0[0x1860];
    Rules rules;
} World;

typedef struct Chaser {
    Racer *self;
    char pad4[0x34];
    s32 count;
    Racer *target[12];
    s32 cost[10];
    s32 dist[10];
} Chaser;

Racer *func_8022A5F4_de(World *arg0, u32 arg1);
f32 func_802726F8_de(void *arg0, void *arg1);
struct AttackBrain;
s32 Nav_EvaluateAttackTarget(struct AttackBrain *brain, s32 index);

s32 func_80210248_eu(Chaser *self) {
    s32 i;
    s32 count;
    Racer *other;
    World *world;
    Rules *rules;

    for (i = 0; i < 10; i++) {
        self->target[i] = NULL;
        self->cost[i] = 0;
        self->dist[i] = -1;
    }
    count = 0;
    i = count;
    world = (World *)&D_80145040;
    rules = &world->rules;
    for (; i < 8; i++) {
        other = func_8022A5F4_de(world, i);
        if (other != NULL && other != self->self
            && (rules->teamsEnabled == 0 || other->team->id != self->self->team->id)
            && (other->stateBits >> 8) > 0) {
            self->target[count] = other;
            self->dist[count] = func_802726F8_de(&self->self->pos, &other->pos);
            self->cost[count] = Nav_EvaluateAttackTarget((struct AttackBrain *)self, count);
            count++;
        }
    }
    self->count = count;
    return 1;
}


typedef struct { f32 x, y, z; } AttackPosition;
typedef struct { char pad0[0x80]; s8 kind; char pad81[0xE]; u8 bonus; char pad90[4]; u8 enabled; } AttackState;
typedef struct { s32 unk0; s32 route; } AttackRoute;
typedef struct AttackActor { char pad0[8]; AttackPosition position; char pad14[0x1C4]; struct AttackActor *actor; char pad1DC[0x3FC]; AttackState *state; char pad5DC[0xC50]; u32 flags; char pad1230[0x220]; s32 active; AttackRoute *route; } AttackActor;
typedef struct AttackBrain { AttackActor *actor; s32 route; char pad8[0x34]; AttackActor *targets[22]; s32 weights[22]; char padEC[0x238]; s32 timer; AttackActor *last; } AttackBrain;
extern f32 D_800C1F50_de, D_800C1F54_de, D_800C1F58_de, D_800C1F5C_de, D_800C1F60_de, D_800C1F64_de, D_800C1F68_de, D_800C1F6C_de, D_800C1F70_de, D_800C1F74_de, D_800C1F78_de, D_800C1F7C_de, D_800C1F80_de;
extern s32 D_80146938, D_801468F4;
extern char D_8013B364[];
extern f32 func_80209C5C_de(AttackBrain *);
extern f32 func_80209B64_de(AttackBrain *);
extern f32 func_80216F44_de(AttackActor *, AttackPosition);
extern s32 func_8020D1CC_de(void *, s32, s32);

s32 Nav_EvaluateAttackTarget(AttackBrain *brain, s32 index) {
    AttackActor *target = brain->targets[index]->actor;
    s32 accept = 0;
    s32 nearLimit, middleLimit, farLimit;
    s32 range;
    f32 speed, angle, scale;

    if (target->flags & 0x20) return 0;
    speed = func_80209C5C_de(brain);
    nearLimit = speed * D_800C1F50_de;
    middleLimit = speed * D_800C1F54_de;
    farLimit = speed * D_800C1F58_de;
    angle = (func_80216F44_de(brain->actor, target->position) < 0.0f) ? -func_80216F44_de(brain->actor, target->position) : func_80216F44_de(brain->actor, target->position);
    if (angle <= D_800C1F5C_de) {
        if (brain->weights[index] < nearLimit) accept = 1;
        range = 0;
    } else if (D_800C1F5C_de < angle && angle <= D_800C1F60_de) {
        if (brain->weights[index] < middleLimit) {
            brain->weights[index] = brain->weights[index] * D_800C1F64_de;
            accept = 1;
        }
        range = 1;
    } else {
        if (brain->weights[index] < farLimit) {
            brain->weights[index] = brain->weights[index] * D_800C1F68_de;
            accept = 1;
        }
        range = 2;
    }
    if (D_80146938 && brain->actor->state->enabled && brain->actor->state->kind == 12) accept = 1;
    if (accept) {
        if (D_801468F4 && target->state->bonus)
            brain->weights[index] = brain->weights[index] * D_800C1F6C_de;
        if (target->active == 0)
            brain->weights[index] = brain->weights[index] * D_800C1F70_de;
        if (func_8020D1CC_de(D_8013B364, brain->route, target->route->route)) return 1;
    }
    if (brain->last != target || brain->timer < 451) return 0;
    if (brain->weights[index] < nearLimit * 2) {
        accept = 1;
        switch (range) {
        case 0:
            break;
        case 1:
            scale = D_800C1F74_de;
            brain->weights[index] = brain->weights[index] * scale;
            break;
        case 2:
            scale = D_800C1F78_de;
            brain->weights[index] = brain->weights[index] * scale;
            break;
        }
        brain->weights[index] = brain->weights[index] * ((D_800C1F7C_de - func_80209B64_de(brain)) * D_800C1F80_de + D_800C1F80_de);
        return 1;
    }
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802106DC[1] = {
    0x4F506571,
};
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_802106DC_de_padding_112DC[4] = { 0x32, 0xEC, 0x15, 0x93 };
#endif
