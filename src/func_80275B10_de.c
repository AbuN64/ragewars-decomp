#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027451C.h"
#include "types.h"






s32 func_80275B10_de(void **arg0, f32 arg1, f32 arg2) {
    s32 i;
    Vec3 *point1;
    Vec3 *point2;

    if (arg0 == 0) {
        return 1;
    }

    for (i = 0; i < 3; i++) {
        point1 = ((Polygon_func_80275410_de *)arg0)->vertices[i];
        point2 = ((Polygon_func_80275410_de *)arg0)->vertices[(i + 1) % 3];
        if (((point2->z -
              point1->z) *
             (arg1 - point1->x)) +
                ((point1->x - point2->x) *
                 (arg2 - point1->z)) <
            0.0f) {
            return 0;
        }
    }

    return 1;
}
