#include "include_asm.h"
#include "TYPES.H"
#include "ANIM/RAY180.H"
#include "RENDER_4/8028FD2C_6.H"
#include "ANIM/COLLISION_TRACE.H"

/* Walks one mesh display list of the element being traced: VTX commands transform their model vertices
 * into the trace space and record per-vertex clip bits, TRI1/TRI2 commands trace every triangle whose
 * vertices are not all outside one clip plane, ENDDL stops. Section 0 of the resource holds the mesh
 * flags, section 1 the commands. */
void Anim_TraceMeshDisplayList(ContextB0 *context, void *resource) {
    CollisionVertex vertices[32];
    CollisionVertex *triangle[3];
    CVector3 point;
    CollisionVertex *saved;
    CollisionVertex *vertex;
    u32 *flags;
    u32 *commands = resource;
    u8 opcode;
    s32 reverse;
    s32 count;
    s16 *source;
    Ray180 *ray;
    flags = Render_GetPackSection(commands, 0);
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
    do {
        opcode = ((u8 *)commands)[COMMAND_HIGH];
        switch (opcode) {
        case MESH_CMD_TRI2:
            TRACE_TRIANGLE(context, vertices, triangle, commands + 1, reverse, saved);
            /* fall through */
        case MESH_CMD_TRI1:
            TRACE_TRIANGLE(context, vertices, triangle, commands, reverse, saved);
            break;
        case MESH_CMD_VTX:
            /* Segmented address of the first 16-byte model vertex, count, and the last slot it loads. */
            source = (s16 *)((commands[1] & 0xFFFFFF) + (u32)context->vertices);
            count = (commands[0] >> 12) & 0xFF;
            vertex = &vertices[((commands[0] & 0xFE) >> 1) - count];
            do {
                vertex->position = source;
                point.x = source[0];
                point.y = source[1];
                point.z = source[2];
                vertex->x = context->transform.m[0][0] * point.x + context->transform.m[1][0] * point.y +
                    context->transform.m[2][0] * point.z + context->transform.m[3][0];
                vertex->clipFlags = Clip_AxisOutside(&vertex->x, &ray->radius, 0);
                vertex->y = context->transform.m[0][1] * point.x + context->transform.m[1][1] * point.y +
                    context->transform.m[2][1] * point.z + context->transform.m[3][1];
                vertex->clipFlags |= Clip_AxisOutside(&vertex->y, &ray->radius, 2);
                vertex->z = context->transform.m[0][2] * point.x + context->transform.m[1][2] * point.y +
                    context->transform.m[2][2] * point.z + context->transform.m[3][2];
                vertex->clipFlags |= Clip_BeyondPositive(&vertex->z, &ray->radius) << 4;
                vertex->clipFlags |= Clip_BeyondNegative(&vertex->z, &context->reach) << 5;
                source += 8;
                vertex++;
                count--;
            } while (count != 0);
            break;
        }
        commands += 2;
    } while (opcode != MESH_CMD_ENDDL);
}
