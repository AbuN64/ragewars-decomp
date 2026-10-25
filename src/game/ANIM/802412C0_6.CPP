#include "include_asm.h"
#ifdef NON_MATCHING
#include "TYPES.H"
#include "ANIM/RAY180.H"
#include "RENDER_4/8028FD2C_6.H"
#include "ANIM/COLLISION_TRACE.H"

/* 4/253 aligned edits remain: second-word setup (the ROM's commands+1 is a loop giv) and the z clip-mask reload.
 * Commands are logical words on both the ROM and native resource paths. */
void Anim_TraceMeshDisplayList(void *contextAddress, void *resource) {
    ContextB0 *context;
    CollisionVertex vertices[32];
    CollisionVertex *triangle[3];
    CVector3 point;
    CollisionVertex *saved;
    CollisionVertex *vertex;
    u32 *flags;
    u32 *commands = resource;
    u32 *second;
    u8 opcode;
    s32 reverse;
    s32 count;
    s16 *source;
    Ray180 *ray;

    flags = Render_GetPackSection(commands, 0);
    context = contextAddress;
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
    commands = Render_GetPackSection(commands, 1);
    second = commands + 1;
    do {
        opcode = ((u8 *)commands)[COMMAND_HIGH];
        switch (opcode) {
        case 6:
            TRACE_TRIANGLE(context, vertices, triangle, second, reverse, saved);
            /* fall through */
        case 5:
            TRACE_TRIANGLE(context, vertices, triangle, commands, reverse, saved);
            break;
        case 1:
            source = (s16 *)((*second & 0xFFFFFF) + (u32)context->vertices);
            count = (commands[0] >> 12) & 0xFF;
            vertex = &vertices[((commands[0] & 0xFE) >> 1) - count];
            do {
                vertex->position = source;
                point.x = source[0];
                point.y = source[1];
                point.z = source[2];
                vertex->x = context->transform.m[0][0] * point.x +
                    context->transform.m[1][0] * point.y + context->transform.m[2][0] * point.z +
                    context->transform.m[3][0];
                {
                    u32 coordinate = *(u32 *)&vertex->x;
                    vertex->clipFlags =
                        ((*(u32 *)&ray->radius - (coordinate & 0x7FFFFFFF)) >> 31) << (coordinate >> 31);
                }
                vertex->y = context->transform.m[0][1] * point.x +
                    context->transform.m[1][1] * point.y + context->transform.m[2][1] * point.z +
                    context->transform.m[3][1];
                {
                    u32 coordinate = *(u32 *)&vertex->y;
                    vertex->clipFlags |=
                        ((*(u32 *)&ray->radius - (coordinate & 0x7FFFFFFF)) >> 31) << (2 + (coordinate >> 31));
                }
                vertex->z = context->transform.m[0][2] * point.x +
                    context->transform.m[1][2] * point.y + context->transform.m[2][2] * point.z +
                    context->transform.m[3][2];
                {
                    u32 coordinate = *(u32 *)&vertex->z;
                    u32 mask = vertex->clipFlags;
                    vertex->clipFlags = mask |=
                        (~(coordinate >> 31) & ((*(u32 *)&ray->radius - coordinate) >> 31)) << 4;
                    vertex->clipFlags = mask |=
                        (-((s32)coordinate >> 31) & ((*(u32 *)&context->reach - (coordinate & 0x7FFFFFFF)) >> 31)) << 5;
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
#else
INCLUDE_ASM("span_1000", Anim_TraceMeshDisplayList);
#endif
