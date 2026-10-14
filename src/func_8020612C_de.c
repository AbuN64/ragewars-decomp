#include "shared/level_actor.h"
#include "span_1000/code_80206258.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80204E78.h"
#include "types.h"

extern s32 func_80214178_de(void *, void *, s32);










void func_8020612C_de(void *arg0, void *arg1) {
    AnimationTriggerResource *temp_v0;
    AnimationTriggerDefinition *temp_a2;
    s32 temp_v1;
    s32 var_v0;

    temp_v0 = (void *)((LevelActor *)arg0)->definition;
    temp_a2 = &temp_v0->trigger;
    if (temp_a2->enabled == 0) {
        if (temp_a2->firstAnimation == -1) {
            ((ActorMotionState *)arg1)->timer = 0.0f;
            return;
        }
        if (temp_a2->secondAnimation == -1) {
            ((ActorMotionState *)arg1)->timer = 0.0f;
            return;
        }
    }
    if (((ActorMotionState *)arg1)->unk124 == temp_a2->animation) {
        ((ActorMotionState *)arg1)->timer = 0.0f;
        return;
    }
    temp_v1 = temp_a2->flags;
    if (!(temp_v1 & 1)) {
        if (((ActorMotionState *)arg1)->unk128 <= 0) {
            return;
        }
    }
    var_v0 = temp_v1 & 2;
    if (var_v0 != 0) {
        if (((LevelActor *)arg0)->flags & 0x200) {
            ((ActorMotionState *)arg1)->timer = 0.0f;
            return;
        }
    }
    if (((ActorMotionState *)arg1)->timer >= ((ActorMotionState *)arg1)->speed) {
        func_80214178_de(arg0, arg1, 1);
    }
}
