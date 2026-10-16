#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802106E0.h"
#include "TYPES.H"









void func_802123FC_eu(void *arg0) {
    CloseAttackActor *actor = arg0;
    CloseAttackActor *level1 = actor->self;
    CloseAttackBrain *inner = level1->brain;
    s32 r1, r2;

    inner->state = 0;
    func_80209988_de(inner);

    r1 = func_802744D4_de();
    inner->timer = r1 % 4 + 0xC;

    r2 = func_802744D4_de();
    inner->pattern = r2 % 2;
}
