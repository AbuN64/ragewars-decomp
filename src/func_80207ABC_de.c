#include "span_1000/code_80206258.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80207ABC.h"
#include "types.h"

extern s32 func_80214178_de(void *, void *, s32);

void func_80207ABC_de(void *object, void *state) {
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    s32 temp_a2;
    ActorMotionResource *resource;
    ActorMotionDefinition *temp_a3;
    s32 var_v1;
    s32 temp_v0;

    resource = arg0->definition;
    temp_a3 = &resource->motion;
    temp_a2 = temp_a3->transitionFlags;
    var_v1 = 1;
    if (temp_a2 & 0x10) {
        temp_v0 = arg1->flags & 0x10000;
        var_v1 = (u32)0 < (u32)temp_v0;
    }
    if ((temp_a2 & 0x100) && !(arg0->movementFlags & 0x40)) {
        var_v1 = 0;
    }
    if ((temp_a3->transitionFlags & 0x400) && (arg0->movementFlags & 0x40)) {
        var_v1 = 0;
    }
    if (var_v1 != 0) {
        if (arg1->timer >= temp_a3->openThreshold) {
            func_80214178_de(arg0, arg1, 1);
        }
    } else {
        arg1->timer = 0.0f;
    }
}
