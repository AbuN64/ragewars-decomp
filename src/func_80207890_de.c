#include "common/types_8fd754e1e915.h"
#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80206258.h"
#include "types.h"

extern s32 func_80214178_de(void *, void *, s32);
extern s32 func_80285F58_de(void *, void *);

void func_80207890_de(void *object, void *state) {
    Player *arg0 = object;
    ActorMotionState *arg1 = state;
    arg1->state = 0;
    func_80214178_de(arg0, arg1, 0);
    if (arg1->routeMode == 1) {
        arg1->destination = arg1->start;
        func_80214178_de(arg0, arg1, 4);
    }
    if (func_80285F58_de(&D_8011FE88, arg0) == 0) {
        arg0->weaponFlags &= ~0x100;
    }
}
