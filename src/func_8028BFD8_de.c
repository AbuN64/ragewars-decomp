#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"



extern void func_8028FFD0_de(s32, s32, s32, Triple, Triple, s32, f32);

void func_8028BFD8_de(s32 arg0, s32 arg1, Triple arg2, s32 arg5, f32 arg6) {
    Triple zero;

    zero.x = 0;
    zero.y = 0;
    zero.z = 0;
    func_8028FFD0_de(arg0 + 0x11778, 0, arg5, zero, arg2, arg1, arg6);
}
