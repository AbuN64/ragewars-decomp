#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025C544.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"







void func_8025C8D8_de(void *arg0, void *arg1, s32 arg2) {
    s32 i;

    func_80255CA0_de(arg0, 0, 4);
    func_80255CA0_de(&((SoundVoicePool *)arg0)->playing, 0, 4);
    i = 0;
    if (arg2 > 0) {
        do {
            func_80255D14_de(arg0, arg1);
            i += 1;
            arg1 = (Node_func_8025CBEC_de *)arg1 + 1;
        } while (i < arg2);
    }
    ((SoundVoicePool *)arg0)->state = 0;
}
