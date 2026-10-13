#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80209AE8.h"
#include "types.h"

f32 func_80209B64_de(AiController *arg0) {
    f32 value;
    u8 state;
    Player *base;
    AiCharacterDefinition *definition;

    base = arg0->player;
    definition = base->definition;
    state = base->profile->difficulty;
    value = definition->unk28;
    value *= D_800C1C9C_de;
    switch (state) {
    case 1:
        break;
    default:
        arg0->player->profile->difficulty = 0;
    case 0:
        value *= D_800C1CA0_de;
        break;
    case 2:
        value *= D_800C1CA4_de;
        break;
    }
    return value;
}
