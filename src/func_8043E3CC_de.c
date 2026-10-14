#include "span_16E000/code_8043DF84.h"
#include "types.h"
#include "shared/func_8043E444_de_closed.h"

extern s8 func_804423BC_de(Outer8043E458 *arg0, s8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

/** Runs a target's animation/state transition through func_804423BC_de and stores the new state. */
s32 func_8043E3CC_de(void *arg0, Outer8043E458 *arg1) {
    Target8043E458 *temp_s0;

    temp_s0 = arg1->unk1C->unk5D8;
    temp_s0->unk7B = func_804423BC_de(arg1, temp_s0->unk7B, 1, 0, 1, 1);
    return 0;
}

extern void func_804427C4_de(void *arg0, void *arg1, void *arg2);

/** Forwards arg1 through and arg2 as the first parameter, adding the D_452834 record. */
s32 func_8043E418_de(void *arg0, void *arg1, void *arg2) {
    func_804427C4_de(arg2, arg1, &D_004518A4);
    return 1;
}

s32 func_8043E444_de(Shared_DebugWidget *widget, Shared_MenuHandle *handle) {
    widget->field = D_800E1CC0[handle->selection->index];
    return 0;
}

extern void func_804427C4_de(void *arg0, void *arg1, void *arg2);

/* Forwards arg1 through and arg2 as the first parameter, adding the D_4505C0 record. */
s32 func_8043E468_de(void *arg0, void *arg1, void *arg2) {
    func_804427C4_de(arg2, arg1, &D_0044F994_de);
    return 1;
}
