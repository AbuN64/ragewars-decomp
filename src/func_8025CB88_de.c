#include "span_1000/code_8025C544.h"
#include "types.h"

extern s32 func_8025E0F4_de(s32 arg0);






void func_8025CB88_de(void *arg0) {
    SoundVoicePool *pool = arg0;
    Node_func_8025CBEC_de *var_s0;

    if (pool->state == 0) {
        var_s0 = pool->playing.head;
        if (var_s0 != 0) {
            do {
                if (func_8025E0F4_de(var_s0->value) == 0) {
                    var_s0->state = -1;
                    var_s0->value = -1;
                }
                var_s0 = var_s0->next;
            } while (var_s0 != 0);
        }
    }
}
