#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802412C0.h"
#include "types.h"








f32 func_80241728_de(void *arg0, f32 arg1, f32 arg2) {
    Vec3 normal;
    Vec3 point;

    normal = ((Query_func_80241BAC_de *)arg0)->normal;
    if (normal.y == 0.0f) {
        return ((Query_func_80241BAC_de *)arg0)->point.y;
    }
    point = ((Query_func_80241BAC_de *)arg0)->point;
    return (((point.z - arg2) * normal.z) + ((point.x - arg1) * normal.x) + (point.y * normal.y)) / normal.y;
}
