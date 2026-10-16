#include "span_1000/code_80299DB4.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "TYPES.H"

extern s32 func_8025305C_de(s32 arg0);

extern s32 func_802A0724_de(s32 arg0, s32 unused1, s32 arg2);

void func_80299B3C_de(int arg0) {
    extern func_80204468_S3 *D_8014D080;
    D_8014D080->unk14 = arg0;
}

/** Return the word at offset 0x14 of the current global object. */
unsigned int func_80299B4C_de(void) {
    extern func_80205494_S3 *D_8014D080;
    return D_8014D080->unk14;
}

/** Copy the same global float to two destinations. */
void func_80299B60_de(float *arg0, float *arg1) {
    float value = D_800C5688_de;
    *arg0 = value;
    *arg1 = value;
}

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
