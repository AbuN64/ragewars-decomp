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

typedef union CollisionCommandWord {
    u32 word;
    struct {
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        u8 low, middleLow, middleHigh, high;
#else
        u8 high, middleHigh, middleLow, low;
#endif
    } bytes;
} CollisionCommandWord;

extern void func_802433DC_de(ContextB0 *, CollisionVertex **);

/* TRI2 visits its second triangle before falling through to TRI1. */
#define TRACE_TRIANGLE(command) \
    triangle[0] = &vertices[((command)->word & 0xFE0000) >> 17].canonical; \
    triangle[1] = &vertices[((command)->word & 0xFE00) >> 9].canonical; \
    triangle[2] = &vertices[(command)->bytes.low >> 1].canonical; \
    if ((((CollisionDisplayVertex *)triangle[0])->decoded.clipFlags & \
         ((CollisionDisplayVertex *)triangle[1])->decoded.clipFlags & \
         ((CollisionDisplayVertex *)triangle[2])->decoded.clipFlags) == 0) { \
        func_802433DC_de(context, triangle); \
        if (reverse) { \
            saved = triangle[0]; \
            triangle[0] = triangle[2]; \
            triangle[2] = saved; \
            func_802433DC_de(context, triangle); \
        } \
    }

/* 248/253 aligned words; remaining: setup scheduling, clip reload and shift.
 * Commands are logical words on both the ROM and native resource paths. */
void Anim_TraceMeshDisplayList(void *contextAddress, void *resource) {
    ContextB0 *context = contextAddress;
    CollisionDisplayVertex vertices[32];
    CollisionVertex *triangle[3];
    CVector3 point;
    CollisionVertex *saved;
    CollisionDisplayVertex *vertex;
    u32 *flags;
    CollisionCommandWord *commands = resource;
    CollisionCommandWord *second;
    u8 opcode;
    s32 reverse;
    s32 count;
    s16 *source;
    Ray180 *ray;

    flags = func_8028FDB4_de(commands, 0);
    ray = context->ray;
    context->flags = *flags;
    reverse = *flags & 4;
    switch (context->kind) {
    case 1:
    case 7:
    case 8:
        reverse = 1;
        break;
    }
    commands = func_8028FDB4_de(commands, 1);
    second = commands + 1;
    do {
        opcode = commands->bytes.high;
        switch (opcode) {
        case 6:
            TRACE_TRIANGLE(second);
            /* fall through */
        case 5:
            TRACE_TRIANGLE(commands);
            break;
        case 1:
            source = (s16 *)((second->word & 0xFFFFFF) + (u32)context->vertices);
            count = (commands[0].word >> 12) & 0xFF;
            vertex = &vertices[((commands[0].word & 0xFE) >> 1) - count];
            do {
                vertex->decoded.source = source;
                point.x = source[0];
                point.y = source[1];
                point.z = source[2];
                vertex->decoded.point.x = context->transform.m[0][0] * point.x +
                    context->transform.m[1][0] * point.y + context->transform.m[2][0] * point.z +
                    context->transform.m[3][0];
                {
                    u32 coordinate = *(u32 *)&vertex->decoded.point.x;
                    vertex->decoded.clipFlags =
                        ((*(u32 *)&ray->radius - (coordinate & 0x7FFFFFFF)) >> 31) << (coordinate >> 31);
                }
                vertex->decoded.point.y = context->transform.m[0][1] * point.x +
                    context->transform.m[1][1] * point.y + context->transform.m[2][1] * point.z +
                    context->transform.m[3][1];
                {
                    u32 coordinate = *(u32 *)&vertex->decoded.point.y;
                    vertex->decoded.clipFlags |=
                        ((*(u32 *)&ray->radius - (coordinate & 0x7FFFFFFF)) >> 31) << (2 + (coordinate >> 31));
                }
                vertex->decoded.point.z = context->transform.m[0][2] * point.x +
                    context->transform.m[1][2] * point.y + context->transform.m[2][2] * point.z +
                    context->transform.m[3][2];
                {
                    u32 coordinate = *(u32 *)&vertex->decoded.point.z;
                    u32 mask = vertex->decoded.clipFlags;
                    mask |=
                        (~(coordinate >> 31) & ((*(u32 *)&ray->radius - coordinate) >> 31)) << 4;
                    vertex->decoded.clipFlags = mask;
                    mask |=
                        ((((s32)coordinate >> 31) & 1) & ((*(u32 *)&context->reach - (coordinate & 0x7FFFFFFF)) >> 31)) << 5;
                    vertex->decoded.clipFlags = mask;
                }
                source += 8;
                vertex++;
                count--;
            } while (count != 0);
            break;
        }
        second += 2;
        commands += 2;
    } while (opcode != 0xDF);
}
#undef TRACE_TRIANGLE
#else
INCLUDE_ASM("span_1000", Anim_TraceMeshDisplayList);
#endif
