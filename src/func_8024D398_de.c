#include "types.h"
#include "span_1000/code_8024D018.h"




f32 func_8024D398_de(Actor_u1 *actor)
{
    Resource_u1 *resource;
    f32 a;
    f32 b;
    switch (actor->resource->kind) {
    case 11:
        if (actor->kind == 1 && (actor->flags & 0x300000) && actor->state->active) {
            return D_800C3C7C_de;
        }
        return actor->resource->valueEC;
    case 0: case 5: case 8: case 10: case 12: case 13: case 14:
        return actor->resource->at18.value;
    case 1: case 4:
        return actor->resource->value28;
    case 2:
        resource = actor->resource;
        if (resource->at18.mode == 2) {
            a = resource->value20;
            b = resource->value1C;
            if (!(b <= a)) a = b;
            b = resource->value28;
            if (!(a <= b)) b = a;
            return b * D_800C3C80_de;
        }
        return resource->value1C;
    case 7:
        return actor->resource->value1C;
    default:
        return 0.0f;
    }
}
