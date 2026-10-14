#include "shared/world.h"
#include "span_1000/code_80204E78.h"
#include "types.h"

extern s32 func_80214178_de(void *, void *, s32);
extern void func_80285DB0_de(void *, void *, s32);


void func_80205694_de(void *arg0, void *arg1) {
    func_80214178_de(arg0, arg1, 1);
    func_80285DB0_de(&D_8011FE88, arg0, 1);
}
