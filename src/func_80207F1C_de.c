#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80207ABC.h"
#include "types.h"

extern void func_80285DB0_de(void *, void *, s32);





void func_80207F1C_de(struct Shared_Actor *arg0) {
    func_80285DB0_de(&D_8011FE88, arg0, 0);
    arg0->weaponFlags &= ~0x100;
}
