#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80203F04.h"
#include "types.h"
#include "span_1000/code_80206258.h"

extern void func_80285DB0_de(void *, void *, s32);
extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);





void func_802045CC_de(void *arg0, void *arg1) {
    ActorMotionState *state = arg1;
    func_80285DB0_de(&D_8011FE88, arg0, 0);
    func_80278D78_de(arg0, 0x200000, arg0);
    state->unk12C = 0;
}
