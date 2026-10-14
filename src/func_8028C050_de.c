#include "span_1000/code_8027451C.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028B64C.h"
#include "types.h"

extern s32 func_80275B10_de(void *arg0, f32 arg1, f32 arg2);
extern f32 func_80275DD4_de(void *, f32, f32);
extern f32 func_8027525C_de(void *arg0, f32 arg1, f32 arg2);










void *func_8028C050_de(void *arg0, void *arg1) {
    f32 lower;
    f32 upper;
    f32 value;

    if (arg0 != 0 &&
        func_80275B10_de(arg0, ((Vec3 *)arg1)->x,
                          ((Vec3 *)arg1)->z) != 0) {
        if (!(((Polygon_func_80275410_de *)arg0)->flags & 0x40)) {
            return arg0;
        }
        lower = func_80275DD4_de(arg0,
            ((Vec3 *)arg1)->x, ((Vec3 *)arg1)->z);
        upper = func_8027525C_de(arg0,
            ((Vec3 *)arg1)->x, ((Vec3 *)arg1)->z);
        value = ((Vec3 *)arg1)->y;
        if (lower <= value && value <= upper) {
            return arg0;
        }
    }
    return func_80286728_de(&D_8011FE88, arg1);
}
