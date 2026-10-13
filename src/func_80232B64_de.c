#include "shared/gameplay_transition.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80231F5C.h"
#include "types.h"

extern s32 func_802301F4_de(void);
extern s32 func_80214178_de(void *, void *, s32);








void func_80232B64_de(void *arg0, void *arg1) {
    void *temp_v0;

    temp_v0 = ((Actor_func_8024A7A0_de *)arg0)->controller;
    ((Shared_ActorView *)temp_v0)->controllerMode = 1;
    ((Shared_ActorView *)temp_v0)->controllerOwner = 0;
    ((Player *)temp_v0)->controllerTimer = 0;
    ((WeaponFireState *)arg1)->spinStep = 0;
    ((WeaponFireState *)arg1)->spin = 0;
    if ((((WeaponFireState *)arg1)->triggerMode != 0) && (func_802301F4_de() == 0)) {
        func_80214178_de(arg0, arg1, 2);
    }
}
