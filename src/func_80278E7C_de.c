#include "span_1000/code_80277444.h"
#include "types.h"
#include "shared/world.h"

extern s32 func_8028BB1C_de(void *arg0, void *arg1, s32 arg2);
extern s32 func_8028C568_de(void *arg0, void *arg1);
extern s32 func_80278C10_de(void *arg0);





void func_80278E7C_de(void *arg0) {
    func_80278EEC_S1 *object = arg0;

    object->unkE |= 0x10;
    func_8028BB1C_de(&D_8011FE88, arg0, 1);
    if ((D_8011FE88.mode == 4) && (object->unkE & 2)) {
        func_8028C568_de(&D_8011FE88, arg0);
        return;
    }
    func_80278C10_de(arg0);
}
