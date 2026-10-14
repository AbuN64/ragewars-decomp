#include "span_1000/code_80297CD0.h"
#include "types.h"





extern s32 D_8014D080;
void func_8029958C_de(s32 arg0) {
    if (arg0 != 0) {
        (((struct IntegerState530 *) ((s8 *) D_8014D080))->unk_52C) = (s32) ((((struct IntegerState530 *) ((s8 *) D_8014D080))->unk_52C) | 1);
        return;
    }
    (((struct IntegerState530 *) ((s8 *) D_8014D080))->unk_52C) = (s32) ((((struct IntegerState530 *) ((s8 *) D_8014D080))->unk_52C) & ~1);
}
