#include "span_1000/code_80203F04.h"
#include "shared/level_actor.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80204E78.h"







/** Clear two flags when the controlling byte and nested flag are set. */
void func_802055EC_de(void *arg0, void *arg1) {
    LevelActor *object = arg0;
    BreakableDefinition *nested = (void *)object->definition;
    ObjectStateCC *state = arg1;
    if (state->unk_CB != 0 &&
        (nested->flags & 0x20) != 0) {
        unsigned int flags = object->flags;
        flags &= ~0x2000;
        flags &= ~0x100;
        object->flags = flags;
    }
}
