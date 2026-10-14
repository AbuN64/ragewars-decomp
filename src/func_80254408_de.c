#include "span_1000/code_802536F4.h"
#include "types.h"

extern s32 func_8028FE3C_de(void *arg0, s32 arg1, s32 arg2, s32 *arg3);
extern void * *func_8025193C_de(s32, s32, s32, s32, s32, void *, void *, void *, s32);

void **func_80254408_de(s32 arg0, void *arg1, s32 arg2, s32 arg3, void *arg4, void *arg5, void *arg6) {
    s32 sp28;
    s32 temp_v0;

    temp_v0 = func_8028FE3C_de(arg1, arg3, arg2, &sp28);
    func_8025193C_de(0, temp_v0, temp_v0, sp28, 0x1B, arg4, arg5, arg6, 1);
}
