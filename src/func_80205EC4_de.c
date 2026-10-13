#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80204E78.h"
#include "types.h"
#include "span_1000/code_80206258.h"
#include "span_1000/code_80203F04.h"
#include "shared/level_actor.h"

extern int D_00206018;
extern int D_800C854C;








void func_80205EC4_de(void *arg0, void *arg1) {
    Actor_func_8024A7A0_de *actor = arg0;
    ActorMotionState *state = arg1;
    BreakableDefinition *inner = (BreakableDefinition *)actor->definition;

    state->table = &D_800C854C;
    state->update = &D_00206018;
    if ((actor->type == 0x644) ||
        (inner->flags & 8)) {
        actor->flags &= ~0x2000;
    }
}
