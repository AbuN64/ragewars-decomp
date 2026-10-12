#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022AE90.h"
#include "types.h"

extern void func_802227F4_de(void *, void *, s32);




void func_8022B984_de(struct SharedPlayer *arg0) {
    if (arg0->views5E8.view1210_152.unk1210 == 0) {
        func_802227F4_de(arg0, arg0, 0x27);
        arg0->views5E8.view1210_152.unk1210 = 1;
        arg0->views5E8.view1214_154.unk1214 = 0;
    }
}
