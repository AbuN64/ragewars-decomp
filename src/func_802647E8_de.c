#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802646F4.h"
#include "types.h"

s32 func_80264248_de();
void func_802647E8_de(ControllerProfile *arg0, s32 arg1) {
    arg0->mode = arg1;
    if (arg1 == 0) {
        func_80264248_de();
    }
}
