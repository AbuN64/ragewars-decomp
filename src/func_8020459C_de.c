#include "shared/level_actor.h"
#include "span_1000/code_80203F04.h"

/* The kind-10 actor initializer installs the state table containing this callback. */
s32 func_8020459C_de(Actor_func_8024A7A0_de *actor) {
    void *resource = actor->definition;
    BreakableDefinition *definition = resource;
    s32 val;

    val = definition->triggerValue;
    if (val != 0) {
        actor->flags = actor->flags | 0x2000;
    } else {
        actor->flags = actor->flags & ~0x2000;
    }
    return val;
}
