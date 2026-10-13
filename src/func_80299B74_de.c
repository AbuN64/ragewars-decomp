#include "span_1000/code_80299DB4.h"
#include "types.h"

extern s32 func_8025305C_de(s32 arg0);
extern s32 func_802A0724_de(s32 arg0, s32 unused1, s32 arg2);




void func_80299B74_de(StreamBuffer *arg0, s32 arg1, s32 arg2) {
    if ((arg0->data) == 0) {
        arg0->data = func_8025305C_de(arg2);
        arg0->writePosition = 0;
        arg0->capacity = arg2;
    }
    {
        s32 t_c = arg0->writePosition;
        s32 t_0 = arg0->data;
        func_802A0724_de(t_0 + t_c, arg1, arg2);
    }
    arg0->writePosition = (arg0->writePosition) + arg2;
}
