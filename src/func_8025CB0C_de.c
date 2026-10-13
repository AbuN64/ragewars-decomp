#include "span_1000/code_8025C544.h"
#include "types.h"

extern s32 func_8025DE54_de(s16 arg0, Vec3 position, s32 arg4, s32 arg5);







void func_8025CB0C_de(void *arg0) {
    s32 temp_v0;
    Node_func_8025CBEC_de *var_s0;

    var_s0 = ((SoundVoicePool *)arg0)->playing.head;
    if (var_s0 != 0) {
        do {
            temp_v0 = func_8025DE54_de((s16)var_s0->state,
                                     var_s0->position,
                                     (s32)var_s0->owner,
                                     -1);
            var_s0->value = temp_v0;
            var_s0 = var_s0->next;
            D_800CBB1C = temp_v0;
        } while (var_s0 != 0);
    }
    ((SoundVoicePool *)arg0)->state = 0;
}
