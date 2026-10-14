#include "span_1000/code_80206258.h"
#include "shared/level_actor.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80207ABC.h"
#include "types.h"





void func_80207FA0_de(LevelActor *arg0, ActorMotionState *arg1) {
    arg1->flags = (s32) (arg1->flags | 0x10000);
    arg0->flags = (s32) (arg0->flags | 0x2100);
    arg1->unk16C = 0;
}
