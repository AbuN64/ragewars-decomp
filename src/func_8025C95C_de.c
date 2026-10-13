#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"



extern void func_80255ED8_de(void *arg0, void *arg1);
extern s32 func_8025DE54_de(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);









void *func_8025C95C_de(void *arg0, s32 arg1, void *arg2, void *arg3, s32 arg4) {
    void *node;
    s32 result;

    node = *(void **)arg0;
    if (node != 0) {
        func_80255ED8_de(arg0, node);
        func_80255D14_de(&((func_80203908_S2 *)(arg0))->unk14, node);
        ((func_8025C97C_S2 *)(node))->unkC = -1;
        ((func_8025C97C_S2 *)(node))->unk8 = -1;
        result = func_8025DE54_de((s16)arg1, ((func_8022ED94_S1 *)(arg2))->unk0,
                                ((func_8022ED94_S1 *)(arg2))->unk4,
                                ((func_8022ED94_S1 *)(arg2))->unk8,
                                (s32)arg3, arg4);
        ((func_8025C97C_S2 *)(node))->unk8 = result;
        D_800CBB10 = result;
        ((func_8025C97C_S2 *)(node))->unkC = arg1;
        ((func_8025C97C_S2 *)(node))->unk10 = *(Triple *)arg2;
        ((func_8025C97C_S2 *)(node))->unk1C = arg3;
    }
    return node;
}
