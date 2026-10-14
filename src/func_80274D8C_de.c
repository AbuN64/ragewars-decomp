#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027451C.h"
#include "types.h"








/** Half-plane test: is arg1 on the positive side of arg0's normal (at +0x30)? */
s32 func_80274D8C_de(void *arg0, void *arg1) {
    GeometryEdge *edge = arg0;
    Vec3 *point = arg1;
    Vec3 normal;
    Vec3 delta;
    s32 result;

    normal = edge->normal;
    delta.x = point->x - edge->start.x;
    delta.z = point->z - edge->start.z;
    result = 0;
    if (!(((normal.x * delta.x) + (normal.z * delta.z)) <= 0.0f)) {
        result = 1;
    }
    return result;
}
