#include "shared/gameplay_transition.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023330C.h"
#include "types.h"






























extern s16 func_8022F96C_de(void *arg0);
extern s32 func_8022B184_de(void *arg0);
extern void func_8022B984_de(void *arg0);
extern s32 func_80214178_de(void *, void *, s32);
extern void func_8022B9C4_de(void *arg0);
extern s32 func_802301F4_de(void *, void *);










void func_8023334C_de(void *arg0, void *arg1) {
    void *actor;

    actor = ((Actor_func_8024A7A0_de *)arg0)->controller;
    ((WeaponFireState *)arg1)->mode = 2;
    if (func_80222AA4_de(actor, ((Shared_ActorView *)actor)->selectedAction) == 0) {
        ((Shared_ActorView *)actor)->nextWeapon = func_8022F96C_de(actor);
        return;
    }

    if (((Actor_func_8024A7A0_de *)arg0)->animationTime >= D_800C3054_de) {
        if (func_8022B184_de(actor) == 0) {
            func_8022B984_de(actor);
        }
    }

    if (!((((Shared_ActorView *)actor)->actionFlags & 0x4000) &&
          (((Shared_ActorView *)actor)->health != 0))) {
        func_80214178_de(arg0, arg1, 2);
        func_8022B9C4_de(actor);
        ((WeaponFireState *)arg1)->mode = 1;
    }

    if (func_802301F4_de(arg0, arg1) != 0) {
        func_8022B9C4_de(actor);
    }
}
