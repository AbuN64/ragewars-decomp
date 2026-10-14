#include "span_1000/code_8025C544.h"
#include "span_1000/code_8025D948.h"
#include "types.h"









void func_8025CAB0_de(void *arg0) {
    s32 temp_v0;
    SoundVoicePool *pool = arg0;
    Node_func_8025CBEC_de *var_s0;

    var_s0 = pool->playing.head;
    if (var_s0 != 0) {
        do {
            func_8025E174_de(var_s0->value);
            temp_v0 = var_s0->value;
            var_s0 = var_s0->next;
            D_800CBB18 = temp_v0;
        } while (var_s0 != 0);
    }
    pool->state = 1;
}
