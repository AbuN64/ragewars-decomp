#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8024E130.h"
#include "span_1000/code_8024D018.h"





/** Return a nested float field when the nested record type is one, else zero. */
float func_8024E544_de(void *object) {
    Actor_u1 *actor = object;
    Resource_u1 *nested = actor->resource;
    if (nested->kind == 1) {
        return nested->value50;
    }
    return 0.0f;
}
