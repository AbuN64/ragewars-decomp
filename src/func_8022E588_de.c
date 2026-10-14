#include "span_1000/code_80225D10.h"
#include "span_1000/code_8022C894.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022D944.h"
#include "types.h"

extern f32 func_802726F8_de(f32 *a, f32 *b);






f32 func_8022E588_de(void *arg0, f32 *arg1) {
    f32 var_f20;
    Round *round = arg0;
    Actor_func_8022D290_de *var_s0;

    var_s0 = round->players;
    var_f20 = 0.0f;
    if (var_s0 != 0) {
        do {
            if (var_s0->unk_0x05DC != 0) {
                var_f20 += func_802726F8_de(arg1, &var_s0->posX);
            }
            var_s0 = (Actor_func_8022D290_de *)var_s0->unk_0x16E0;
        } while (var_s0 != 0);
    }
    return var_f20;
}
