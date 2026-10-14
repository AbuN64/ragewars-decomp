#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80206258.h"
#include "types.h"

extern void func_80402FB4_de(s32, s32);
extern void func_80285DB0_de(void *, void *, s32);





void func_802068C8_de(struct Shared_Actor *arg0, s32 arg1, s32 arg2) {
    func_80402FB4_de(arg0, arg2);
    arg0->weaponFlags |= 0x2100;
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}
