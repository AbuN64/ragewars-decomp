#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80206258.h"
#include "types.h"

extern int func_80245798_de(void);
extern void func_802472F0_de(Shared_Actor *arg0);
extern void func_80285DB0_de(void *, void *, s32);





void func_8020682C_de(Shared_Actor *arg0, s32 *arg1) {
    arg0->weaponFlags |= 0x2100;
    if (func_80245798_de() != 0) {
        *arg1 |= 0x200;
    }
    func_802472F0_de(arg0);
    func_80285DB0_de(&D_8011FE88, arg0, 0);
}
