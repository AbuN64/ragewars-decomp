#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "ANIM/RAY180.H"
#include "RENDER_4/8028FD2C_6.H"

typedef union CollisionDisplayVertex {
    CollisionVertex canonical;
    struct {
        CVector3 point;
        u8 reserved[0xC];
        u32 clipFlags;
        s16 *source;
    } decoded;
} CollisionDisplayVertex;

typedef union CollisionFloatWord {
    f32 value;
    u32 bits;
} CollisionFloatWord;

extern void func_802433DC_de(ContextB0 *, CollisionVertex **);

/* Hand C from the 0x3F4-byte MIPS body. Resource commands are logical words:
 * the opcode and vertex indices come from their value, independent of host
 * byte order. Thirty-two transformed slots retain the original 0x20 stride. */
void Anim_TraceMeshDisplayList(void *contextAddress, void *resource) {
    ContextB0 *context = contextAddress;
    CollisionDisplayVertex vertices[32];
    CollisionVertex *triangle[3];
    CollisionVertex *saved;
    CollisionFloatWord coordinate;
    CollisionFloatWord limit;
    CollisionFloatWord reach;
    u32 *flags;
    u32 *commands;
    u32 opcode;
    u32 reverse;
    u32 count;
    u32 end;
    u32 slot;
    u32 word;
    u32 first;
    u32 second;
    u32 third;
    s32 wordIndex;
    s16 *source;
    struct Ray180 *ray;
    f32 x;
    f32 y;
    f32 z;

    flags = func_8028FDB4_de(resource, 0);
    ray = context->ray;
    context->flags = *flags;
    reverse = *flags & 4;
    if (context->kind == 1 || context->kind == 7 || context->kind == 8) {
        reverse = 1;
    }
    commands = func_8028FDB4_de(resource, 1);
    for (;;) {
        opcode = commands[0] >> 24;
        switch (opcode) {
        case 1:
            source = (s16 *)((u8 *)context->vertices + (commands[1] & 0xFFFFFF));
            count = (commands[0] >> 12) & 0xFF;
            end = (commands[0] & 0xFE) >> 1;
            slot = end - count;
            limit.value = ray->radius;
            reach.value = context->reach;
            do {
                vertices[slot].decoded.source = source;
                x = source[0];
                y = source[1];
                z = source[2];
                coordinate.value = context->transform.m[0][0] * x +
                    context->transform.m[1][0] * y + context->transform.m[2][0] * z +
                    context->transform.m[3][0];
                vertices[slot].decoded.point.x = coordinate.value;
                vertices[slot].decoded.clipFlags =
                    ((limit.bits - (coordinate.bits & 0x7FFFFFFF)) >> 31) <<
                    (coordinate.bits >> 31);
                coordinate.value = context->transform.m[0][1] * x +
                    context->transform.m[1][1] * y + context->transform.m[2][1] * z +
                    context->transform.m[3][1];
                vertices[slot].decoded.point.y = coordinate.value;
                vertices[slot].decoded.clipFlags |=
                    ((limit.bits - (coordinate.bits & 0x7FFFFFFF)) >> 31) <<
                    (2 + (coordinate.bits >> 31));
                coordinate.value = context->transform.m[0][2] * x +
                    context->transform.m[1][2] * y + context->transform.m[2][2] * z +
                    context->transform.m[3][2];
                vertices[slot].decoded.point.z = coordinate.value;
                vertices[slot].decoded.clipFlags |=
                    ((~(coordinate.bits >> 31) & ((limit.bits - coordinate.bits) >> 31)) << 4) |
                    (((coordinate.bits >> 31) &
                      ((reach.bits - (coordinate.bits & 0x7FFFFFFF)) >> 31)) << 5);
                source += 8;
                slot++;
                count--;
            } while (count != 0);
            break;
        case 5:
        case 6:
            wordIndex = opcode == 6 ? 1 : 0;
            do {
                word = commands[wordIndex];
                first = (word >> 17) & 0x7F;
                second = (word >> 9) & 0x7F;
                third = (word >> 1) & 0x7F;
                triangle[0] = &vertices[first].canonical;
                triangle[1] = &vertices[second].canonical;
                triangle[2] = &vertices[third].canonical;
                if ((vertices[first].decoded.clipFlags & vertices[second].decoded.clipFlags &
                     vertices[third].decoded.clipFlags) == 0) {
                    func_802433DC_de(context, triangle);
                    if (reverse != 0) {
                        saved = triangle[0];
                        triangle[0] = triangle[2];
                        triangle[2] = saved;
                        func_802433DC_de(context, triangle);
                    }
                }
                wordIndex--;
            } while (wordIndex >= 0);
            break;
        case 0xDF:
            return;
        default:
            break;
        }
        commands += 2;
    }
}
#else
INCLUDE_ASM("span_1000", Anim_TraceMeshDisplayList);
#endif
