#include "types.h"

typedef struct MoveVector461E8 {
    f32 x, y, z;
} MoveVector461E8;
typedef struct MoveActor461E8 {
    s32 unused0, unused4;
    MoveVector461E8 position;
    s32 ground;
    s32 unused18;
    MoveVector461E8 velocity;
} MoveActor461E8;
extern s32 D_801040D0;
extern f32 func_80275DD4_de(s32, f32, f32);
extern s32 func_80243A90_de(MoveActor461E8 *, MoveVector461E8, s32 *);

void func_802461E8_de(MoveActor461E8 *actor, f32 x, f32 z) {
    MoveVector461E8 saved;
    MoveVector461E8 position;
    s32 keep;
    s32 *mask;
    f32 height;
    mask = &D_801040D0;
    height = actor->position.y - func_80275DD4_de(actor->ground, actor->position.x, actor->position.z);
    saved = actor->velocity;
    actor->velocity.x = actor->velocity.y = actor->velocity.z = 0.0f;
    position.x = x;
    position.y = actor->position.y;
    position.z = z;
    keep = *mask;
    func_80243A90_de(actor, position, mask);
    *mask = keep;
    actor->velocity = saved;
    actor->position.y = func_80275DD4_de(actor->ground, actor->position.x, actor->position.z) + height;
}
