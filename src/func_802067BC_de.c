#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80206258.h"
#include "types.h"


extern void func_80285DB0_de(void *, void *, s32);




void func_802067BC_de(Shared_Actor *arg0) {
    s32 v = arg0->weaponFlags;
    v &= ~0x2000;
    v &= ~0x100;
    arg0->weaponFlags = v;
    func_80285DB0_de(&D_8011FE88, arg0, 1);
}
