#include "shared/level_actor.h"
#include "shared/gameplay_transition.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802106E0.h"









/** Reset the inner record via func_80209988_de, then override two of its fields. */
void func_8021290C_de(void *arg0) {
    Shared_ActorView *level1 = ((Actor_func_8024A7A0_de *)arg0)->controller;
    CloseAttackBrain *inner = level1->owner;
    inner->state = 0;
    func_80209988_de(inner);
    inner->reset2FC = 0;
    inner->destination = -1;
}
