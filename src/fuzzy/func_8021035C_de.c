#include "TYPES.H"

typedef struct { f32 x, y, z; } AttackPosition;
typedef struct { char pad0[0x80]; s8 kind; char pad81[0xE]; u8 bonus; char pad90[4]; u8 enabled; } AttackState;
typedef struct { s32 unk0; s32 route; } AttackRoute;
typedef struct AttackActor { char pad0[8]; AttackPosition position; char pad14[0x1C4]; struct AttackActor *actor; char pad1DC[0x3FC]; AttackState *state; char pad5DC[0xC50]; u32 flags; char pad1230[0x220]; s32 active; AttackRoute *route; } AttackActor;
typedef struct { AttackActor *actor; s32 route; char pad8[0x34]; AttackActor *targets[22]; s32 weights[22]; char padEC[0x238]; s32 timer; AttackActor *last; } AttackBrain;
extern f32 D_800C1F50_de, D_800C1F54_de, D_800C1F58_de, D_800C1F5C_de, D_800C1F60_de, D_800C1F64_de, D_800C1F68_de, D_800C1F6C_de, D_800C1F70_de, D_800C1F74_de, D_800C1F78_de, D_800C1F7C_de, D_800C1F80_de;
extern s32 D_80146938, D_801468F4;
extern char D_8013B364[];
extern f32 func_80209C5C_de(AttackBrain *);
extern f32 func_80209B64_de(AttackBrain *);
extern f32 func_80216F44_de(AttackActor *, AttackPosition);
extern s32 func_8020D1CC_de(void *, s32, s32);

s32 func_8021035C_de(AttackBrain *brain, s32 index) {
    AttackActor *target = brain->targets[index]->actor;
    s32 accept = 0;
    s32 nearLimit, middleLimit, farLimit, band;
    f32 speed, angle, scale;
    if (target->flags & 0x20) return 0;
    speed = func_80209C5C_de(brain);
    nearLimit = (s32)(speed * D_800C1F50_de);
    middleLimit = (s32)(speed * D_800C1F54_de);
    farLimit = (s32)(speed * D_800C1F58_de);
    if (func_80216F44_de(brain->actor, target->position) < 0.0f)
        angle = -func_80216F44_de(brain->actor, target->position);
    else
        angle = func_80216F44_de(brain->actor, target->position);
    if (angle <= D_800C1F5C_de) {
        if (brain->weights[index] < nearLimit) accept = 1;
        band = 0;
    } else if (D_800C1F5C_de < angle && angle <= D_800C1F60_de) {
        band = 1;
        if (brain->weights[index] < middleLimit) {
            brain->weights[index] = (s32)((f32)brain->weights[index] * D_800C1F64_de);
            accept = 1;
        }
    } else {
        band = 2;
        if (brain->weights[index] < farLimit) {
            accept = 1;
            brain->weights[index] = (s32)((f32)brain->weights[index] * D_800C1F68_de);
        }
    }
    if (D_80146938 && brain->actor->state->enabled && brain->actor->state->kind == 12) accept = 1;
    if (accept) {
        if (D_801468F4 && target->state->bonus)
            brain->weights[index] = (s32)((f32)brain->weights[index] * D_800C1F6C_de);
        if (target->active == 0)
            brain->weights[index] = (s32)((f32)brain->weights[index] * D_800C1F70_de);
        if (func_8020D1CC_de(D_8013B364, brain->route, target->route->route)) return 1;
    }
    if (brain->last != target || brain->timer < 451) return 0;
    if (brain->weights[index] < (nearLimit << 1)) {
        switch (band) {
        case 1: scale = D_800C1F74_de; goto rescale;
        case 2: scale = D_800C1F78_de;
rescale: brain->weights[index] = (s32)((f32)brain->weights[index] * scale); break;
        }
        speed = func_80209B64_de(brain);
        brain->weights[index] = (s32)((f32)brain->weights[index] * ((D_800C1F7C_de - speed) * D_800C1F80_de + D_800C1F80_de));
        return 1;
    }
    return 0;
}
