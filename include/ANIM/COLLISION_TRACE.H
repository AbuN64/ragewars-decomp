#ifndef ANIM_COLLISION_TRACE_H
#define ANIM_COLLISION_TRACE_H
#include "TYPES.H"
#include "ANIM/RAY180.H"

/* Mesh display-list commands are logical words on both the ROM and native resource paths. */
#if defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define COMMAND_HIGH 3
#define COMMAND_LOW 0
#else
#define COMMAND_HIGH 0
#define COMMAND_LOW 3
#endif

extern void func_802433DC_de(ContextB0 *, CollisionVertex **);

/* TRI2 visits its second triangle before falling through to TRI1. */
#define TRACE_TRIANGLE(context, vertices, triangle, command, reverse, saved) \
    triangle[0] = &vertices[((*(command)) & 0xFE0000) >> 17]; \
    triangle[1] = &vertices[((*(command)) & 0xFE00) >> 9]; \
    triangle[2] = &vertices[((u8 *)(command))[COMMAND_LOW] >> 1]; \
    if ((triangle[0]->clipFlags & \
         triangle[1]->clipFlags & \
         triangle[2]->clipFlags) == 0) { \
        func_802433DC_de(context, triangle); \
        if (reverse) { \
            saved = triangle[0]; \
            triangle[0] = triangle[2]; \
            triangle[2] = saved; \
            func_802433DC_de(context, triangle); \
        } \
    }
#endif
