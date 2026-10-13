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

    node = ((SoundVoicePool *)arg0)->available.head;
    if (node != 0) {
        func_80255ED8_de(arg0, node);
        func_80255D14_de(&((SoundVoicePool *)arg0)->playing, node);
        ((struct Node_func_8025CBEC_de *)node)->state = -1;
        ((struct Node_func_8025CBEC_de *)node)->value = -1;
        result = func_8025DE54_de((s16)arg1, ((Triple *)arg2)->x,
                                ((Triple *)arg2)->y,
                                ((Triple *)arg2)->z,
                                (s32)arg3, arg4);
        ((struct Node_func_8025CBEC_de *)node)->value = result;
        D_800CBB10 = result;
        ((struct Node_func_8025CBEC_de *)node)->state = arg1;
        ((struct Node_func_8025CBEC_de *)node)->position = *(Triple *)arg2;
        ((struct Node_func_8025CBEC_de *)node)->owner = arg3;
    }
    return node;
}
