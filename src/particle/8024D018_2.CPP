#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/PROBE.H"

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
        return actor->resource->radius;
    case 1: case 4:
        return actor->resource->value28;
    case 2:
        resource = actor->resource;
        if (((CollisionShapeResource *)resource)->mode == 2) {
            a = ((CollisionShapeResource *)resource)->width;
            b = ((CollisionShapeResource *)resource)->height;
            if (!(b <= a)) a = b;
            b = ((CollisionShapeResource *)resource)->depth;
            if (!(a <= b)) b = a;
            return b * D_800C3C80_de;
        }
        return ((CollisionShapeResource *)resource)->height;
    case 7:
        return actor->resource->value1C;
    default:
        return 0.0f;
    }
}

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_unresolved_800C3C7C);
#endif
