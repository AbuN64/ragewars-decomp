#include "shared/gameplay_transition.h"
#include "shared/func_80425674_de_layout.h"
#include "shared/world.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"
#include "span_1000/code_8026AC38.h"
















void func_8022BB80_de(void *arg0) {
    s32 var_a2;
    Shared_Game *base;

    base = &D_801462C8;
    if (base->local == 0) {
        var_a2 = 0x66;
    } else if (base->unk62C != 0 && ((Shared_ActorView *)arg0)->controls->transientFlag != 0) {
        var_a2 = D_800CE47C;
    } else {
        var_a2 = D_800CE430[(s16)(((LevelActor *)arg0)->definition[3] >> 16)];
        ((Shared_ActorView *)arg0)->id = ((Shared_ActorView *)arg0)->controls->playerId;
    }
    ((void (*)(void *, void *, s32, s32))func_8028B274_de)(&D_8011FE88, arg0, var_a2, ((Shared_ActorView *)arg0)->effectId);
}
