#include "types.h"

typedef struct ThrowDefinition { s32 kind; } ThrowDefinition;
typedef struct ThrowState { u32 flags; s32 active; char pad08[0x2C]; s8 kind, timer; } ThrowState;
typedef struct ThrowActor {
    u8 category; char pad01[0x17]; ThrowDefinition *definition;
    f32 vx, vy, vz; char pad28[0x148]; ThrowState state;
} ThrowActor;
typedef struct ThrowPlayer {
    char pad00[0x5DC]; void *effect;
    char pad5E0[0x84]; u32 flags;
    char pad668[0x58]; f32 speed;
    char pad6C4[0x148]; ThrowActor *selected;
} ThrowPlayer;
typedef struct ThrowPosition {
    char pad00[8]; s32 x, y, z; char pad14[0x58]; f32 angle;
} ThrowPosition;
extern ThrowActor *D_801041F0;
extern f32 D_800C2860_de, D_800C2864_de, D_800C2868_de, D_800C286C_de;
extern f32 D_800C2870_de, D_800C2874_de, D_800C2878_de;
extern void func_80239324_de(void *, f32, f32, f32, f32, s32, s32, s32, s32);
extern void func_80214178_de(void *, void *, s32);

s32 func_80222FE0_de(ThrowPlayer *player, ThrowPosition *position) {
    ThrowActor *actor, *selected;
    s32 kind;
    actor = D_801041F0;
    if (!(player->flags & 0x8000) || !actor) return 0;
    selected = player->selected;
    if (actor == selected || actor->category != 1) return 0;
    kind = actor->definition->kind;
    if (kind != 1 || !selected) return 0;
    if (actor->state.active) {
        actor->vx = player->speed * func_802B7130_de(position->angle + D_800C2860_de) * D_800C2864_de;
        actor->vy = player->speed * D_800C2868_de;
        actor->vz = player->speed * func_802B6560_de(position->angle + D_800C2860_de) * D_800C2864_de;
        if (player->effect)
            func_80239324_de(player->effect, D_800C2870_de, 100.0f, D_800C2870_de, D_800C286C_de, kind, position->x, position->y, position->z);
        if (selected->state.kind == 0x2E) actor->state.flags |= 0x200;
        actor->state.timer = -1;
        func_80214178_de(actor, &actor->state, 0x34);
        return 1;
    }
    if (player->effect)
        func_80239324_de(player->effect, D_800C2878_de, 60.0f, D_800C2878_de, D_800C2874_de, kind, position->x, position->y, position->z);
    return 1;
}
