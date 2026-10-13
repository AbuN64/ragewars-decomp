#include "shared/level_actor.h"
#include "span_1000/code_80206258.h"
#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802022E0.h"
#include "types.h"

extern s32 func_802170A0_de(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_80285DB0_de(void *, void *, s32);
extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);










void func_80203B60_de(void *arg0, void *arg1) {
    Actor_func_8024A7A0_de *o0 = arg0;
    ActorMotionState *o1 = arg1;
    ActorMotionDefinition *tmp;
    s32 masked;
    Shared_World *pFlag;

    tmp = &((ActorMotionResource *)o0->definition)->motion;
    func_802170A0_de(arg0, arg1, 4, tmp->eventMask, tmp->secondaryEventMask);
    pFlag = &D_8011FE88;
    o1->event = 0;
    func_80285DB0_de(pFlag, arg0, 1);
    func_80278D78_de(arg0, 1, arg0);
    masked = o0->flags & 0xFFFEFFFF;
    o0->flags = masked;
    if (pFlag->mode != 4) {
        o0->flags = masked | 0x08000000;
    }
}
