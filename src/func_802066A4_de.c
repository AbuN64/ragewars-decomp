#include "common/unused.h"
#include "shared/level_actor.h"
#include "span_1000/code_8021CD70.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80206258.h"
#include "types.h"
#include "shared/func_80206724_de_closed.h"

extern s32 func_80214178_de(void *, void *, s32);
extern s32 func_80285F58_de(void *, void *);










void func_802066A4_de(void *arg0, void *arg1) {
    ((Dest *)arg1)->field124 = ((ActorHealthDefinition *)((Actor_func_8024A7A0_de *)arg0)->definition)->health;
    func_80214178_de(arg0, arg1, 0);
    ((Dest *)arg1)->charge = D_800C1AE0_de;
    ((Dest *)arg1)->field12C = D_800C1AE0_de;
    if (func_80285F58_de(&D_8011FE88, arg0) == 1) {
        ((Actor_func_8024A7A0_de *)arg0)->flags &= ~0x2000;
        ((Actor_func_8024A7A0_de *)arg0)->flags &= ~0x100;
    }
}

void func_80206724_de(void *arg0, void *arg1) {
    Shared_CallbackHook *obj = ((Shared_CallbackOwner *)arg1)->hook;
    if (obj != 0) {
        Shared_VoidCallback fn = obj->callback;
        if (fn != 0) {
            fn();
        }
    }
}

int func_80206758_de(void *arg0, void *arg1) {
    return ((Dest *)arg1)->field124;
}

void func_80206764_de(void) {
}
