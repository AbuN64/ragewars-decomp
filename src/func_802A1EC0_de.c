#include "span_1000/code_802A1264.h"
#include "span_1000/code_8029BBA0.h"
#include "span_1000/code_802A208C.h"
#include "types.h"


extern unsigned int func_80299B4C_de(void);
extern void func_802A1D7C_de(void *arg0);
extern s32 func_8025DF34_de(s32);




s32 func_802A1EC0_de(void *arg0, s32 unused1, s32 unused2, s32 arg3, s32 arg4) {
    Record_func_802A1990_de *object = arg0;
    s32 temp_s0;

    temp_s0 = func_8029DB58_de(arg4);
    if (temp_s0 < (s32)func_80299B4C_de()) {
        object->field_5C = 2;
        object->field_48 = 0;
    }
    if (arg3 != 1) {
        return 0;
    }
    object->field_5C = arg3;
    func_802A1D7C_de(object);
    func_8025DF34_de(0xE81);
    return 0;
}
