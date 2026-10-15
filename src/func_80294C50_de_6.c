#include "shared/world.h"
#include "span_1000/code_80294C64.h"
#include "types.h"

/** Store two words into a two-word value. */
void func_80295E78_de(int *value, int first, int second) {
    value[0] = first;
    value[1] = second;
}

extern void func_8028C15C_de(void *arg0, s32 arg1, s32 *arg2, s32 *arg3);


void func_80295E84_de(s32 *arg0, s32 arg1) {
    func_8028C15C_de(&D_8011FE88, arg1, arg0, arg0 + 1);
}
