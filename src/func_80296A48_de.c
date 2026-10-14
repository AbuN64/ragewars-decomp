#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80296014.h"
#include "types.h"
/* Returns 1 when each of the six planes has at least one of the n points on or inside it (normal dot point <= plane distance), else 0. */





s32 func_80296A48_de(Vector4f *planes, s32 n, Vec3 *points) {
    s32 i;
    s32 j;
    s32 inside;

    for (i = 0; i < 6; i++) {
        inside = 0;
        for (j = 0; j < n; j++) {
            if (planes[i].x * points[j].x + planes[i].y * points[j].y + planes[i].z * points[j].z <= planes[i].w) {
                inside = 1;
                break;
            }
        }
        if (!inside) {
            return 0;
        }
    }
    return 1;
}
