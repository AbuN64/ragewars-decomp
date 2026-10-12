#include "types.h"

typedef struct {
    s32 kind;
    u8 pad4[0x14];
    union { f32 value; u16 mode; } at18;
    f32 value1C;
    f32 value20;
    u8 pad24[4];
    f32 value28;
    u8 pad2C[0xC0];
    f32 valueEC;
} Resource_u1;

typedef struct { u8 pad0[0x80C]; s32 active; } State_u1;
typedef struct {
    u8 kind;
    u8 pad1[0x17];
    Resource_u1 *resource;
    u8 pad1C[0xE4];
    u32 flags;
    u8 pad104[0xD4];
    State_u1 *state;
} Actor_u1;

extern f32 D_800C3C7C_de;
extern f32 D_800C3C80_de;

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
