#include "shared/world.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802022E0.h"
#include "types.h"

extern s32 func_80285F58_de(void *, void *);





void func_80203C40_de(Shared_Actor *arg0) {
    if (func_80285F58_de(&D_8011FE88, arg0) == 0) {
        arg0->weaponFlags |= 0x2100;
    }
}
