#include "span_1000/code_802508E0.h"
#include "shared/level_actor.h"





/** Select one of two signed bytes according to a doubled nested count. */
int func_80250DE0_de(void *object) {
    Actor_func_8024A7A0_de *actor = object;
    struct ResourceFadeDefinition *nested = (struct ResourceFadeDefinition *)actor->definition;
    if ((u32)actor->resourceState <
        nested->threshold * 2) {
        return nested->nearValue;
    }
    return nested->farValue;
}
