#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"

f32 func_80209C5C_de(AiController *arg0) {
    f32 var_f0;
    f32 var_f1;
    u8 state;
    Player *base;
    AiCharacterDefinition *definition;

    base = arg0->player;
    definition = base->definition;
    state = base->profile->difficulty;
    var_f1 = definition->unk30;
    var_f1 *= D_800C1CB4_de;
    switch (state) {
    case 1:
        break;
    default:
        arg0->player->profile->difficulty = 0;
    case 0:
        var_f0 = D_800C1CB8_de;
        goto multiply;
    case 2:
        var_f0 = D_800C1CBC_de;
multiply:
        var_f1 *= var_f0;
        break;
    }
    return var_f1;
}
