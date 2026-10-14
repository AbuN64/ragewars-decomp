#include "common/types_8fd754e1e915.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80206258.h"
#include "types.h"

extern char D_800C86A0_de;
extern char D_002079B0;
extern char D_00207910;
extern f32 D_800C1B9C_de;

void func_802077F4_de(void *object, void *state)
{
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    f32 k;
    f32 value;
    f32 scaled;
    ActorMotionResource *temp_v1;
    ActorMotionDefinition *temp_v0;

    temp_v1 = arg0->definition;
    k = D_800C1B9C_de;
    arg1->table = &D_800C86A0_de;
    arg1->update = &D_002079B0;
    arg1->transform = &D_00207910;
    arg1->yaw = 0;
    arg1->pitch = 0;
    temp_v0 = &temp_v1->motion;
    value = temp_v0->speed;
    arg1->unk124 = 0;
    arg1->unk128 = 0;
    arg1->unk12C = 0;
    arg1->unk130 = 0;
    arg1->speed = value;
    scaled = temp_v0->speed;
    arg1->unk140 = 0;
    arg1->unk144 = 0;
    scaled = scaled * k;
    arg1->unk148 = 0;
    arg1->unk14C = 0;
    arg1->unk168 = 0;
    arg1->unk16C = 0;
    arg1->progress = scaled;
    if (temp_v1->motion.flags & 4) {
        arg0->weaponFlags = arg0->weaponFlags & ~0x2000;
    }
}
