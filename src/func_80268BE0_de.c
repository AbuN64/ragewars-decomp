#include "shared/world.h"
#include "span_1000/code_80268160.h"
#include "types.h"

extern void *func_8028B00C_de(void *object, int index);
extern void func_80268C1C_de(s32 arg0, void *arg1);


void *func_80268BE0_de(s32 arg0, s32 arg1) {
    func_80268C1C_de(arg0, func_8028B00C_de(&D_8011FE88, arg1));
}
