#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8022AE90.h"
#include "types.h"
extern void func_80216488_de(void *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4, s32 arg5);
extern void func_80219A40_de(void *arg0, void *arg1, void *arg2);
extern f32 D_800D2988;
extern s32 D_801462C8;






void func_8022B8E0_de(void *arg0) {
    Slot sp18;
    f32 temp_f0;
    f32 temp_f1;

    temp_f1 = ((ObjectState13E4 *)(arg0))->unk_11E4;
    if (temp_f1 > 0.0f) {
        temp_f0 = temp_f1 - D_800D2988;
        ((ObjectState13E4 *)(arg0))->unk_11E4 = temp_f0;
        if ((temp_f0 <= 0.0f) && !(D_801462C8 & 1)) {
            func_80216488_de(&sp18,
                          ((ObjectState13E4 *)(arg0))->unk_13E0,
                          ((ObjectState13E4 *)(arg0))->unk_174 + 0x1900,
                          25.599998f, 0x4000, 0);
            func_80219A40_de(arg0, &((ObjectState13E4 *)(arg0))->unk_170, &sp18);
        }
    }
}
