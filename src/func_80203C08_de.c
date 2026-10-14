#include "span_1000/code_80206258.h"
#include "shared/level_actor.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802022E0.h"
#include "types.h"

s32 func_80262C88_de();
void func_80203C08_de(LevelActor *arg0, ActorMotionState *arg1) {
    if ((arg1->actionPending != 0) && (arg0->flags & 0x80000)) {
        func_80262C88_de();
    }
}
