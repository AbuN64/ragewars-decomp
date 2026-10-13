#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_802BA23C.h"
#include "types.h"

extern s32 D_80142C30;
extern s32 D_80142C38;





void *func_8028F9AC_de(void *arg0) {
    s32 f1a;
    s32 f1b;
    void *v2;

    if (arg0 == 0) {
        return 0;
    }
    f1a = (s32)((struct OSScTask_s *)arg0)->framebuffer;
    if (f1a == D_80142C38) {
        return 0;
    }
    v2 = func_802BA310_de();
    f1b = (s32)((struct OSScTask_s *)arg0)->framebuffer;
    if (f1b == (s32)v2) {
        return 0;
    }
    if (f1b != D_80142C30) {
        return arg0;
    }
    return 0;
}
