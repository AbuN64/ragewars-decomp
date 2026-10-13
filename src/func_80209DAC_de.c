#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"













f32 func_80209DAC_de(void *arg0) {
    AiController *brain = arg0;
    f32 temp_f20;
    f32 var_f14;
    u8 state;

    state = brain->player->profile->difficulty;
    switch (state) {
    default:
        brain->player->profile->difficulty = 0;
    case 0:
        var_f14 = (1.2217305898666382f);
        break;
    case 1:
        var_f14 = (0.8726646900177002f);
        break;
    case 2:
        var_f14 = (0.523598849773407f);
        break;
    }
    temp_f20 = brain->aim;
    if (temp_f20 < func_80274A90_de(-var_f14, var_f14)) {
        temp_f20 += D_800C1CC0_de;
    } else {
        temp_f20 -= D_800C1CC4_de;
    }
    brain->aim = temp_f20;
    return temp_f20;
}
