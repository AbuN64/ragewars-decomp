#include "span_1000/code_80206258.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80207ABC.h"
#include "types.h"

extern s32 func_80214178_de(void *, void *, s32);
extern f32 D_800D2988;

void func_80207D90_de(void *object, void *state) {
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    ActorMotionResource *resource;
    ActorMotionDefinition *temp_a3;
    s32 temp_a2;
    s32 var_v1;

    resource = arg0->definition;
    temp_a3 = &resource->motion;
    temp_a2 = temp_a3->transitionFlags;
    var_v1 = 1;
    if (temp_a2 & 0x20000) {
        var_v1 = (u32)(arg0->movementFlags & 0x40) < (u32)var_v1;
    }
    if ((temp_a2 & 0x8000) && !(arg0->movementFlags & 0x40)) {
        var_v1 = 0;
    }
    if (arg0->movementFlags & 8) {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        arg1->speed = arg1->speed - (D_800D2988 / temp_a3->transitionTime);
    }
    if (arg1->speed <= 0.0f) {
        func_80214178_de(arg0, arg1, 0);
    }
}
