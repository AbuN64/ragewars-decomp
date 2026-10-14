#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802412C0.h"
#include "types.h"






s32 func_80241614_de(void *arg0, void *arg1, f32 arg2, void *arg3) {
    Vec3 *first = arg1;
    Vec3 *second = arg3;
    f32 dx = first->x - second->x;
    f32 dz = first->z - second->z;
    s32 result = 1;
    if (!((dx * dx + dz * dz) <= (arg2 * arg2))) {
        result = 0;
    }
    return result;
}
