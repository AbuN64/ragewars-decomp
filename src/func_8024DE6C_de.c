#include "common/types_8fd754e1e915.h"
#include "shared/actor_header.h"
#include "span_1000/code_8024D018.h"
#include "types.h"

s32 func_8024DE6C_de(void *arg0)
{
    struct Object *object = arg0;
    struct Model *model;
    s32 kind;

    model = (struct Model *)object->owner;
    kind = model->kind;
    if ((kind == 1) || (kind == 4)) {
        if (model) {
            return model->flags & 0x10;
        } else {
            return model->flags & 0x10;
        }
    }
    return 0;
}
