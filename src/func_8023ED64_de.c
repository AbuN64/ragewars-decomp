#include "shared/box_contact.h"
#include "span_1000/code_8023D370.h"
#include "types.h"









s32 func_8023ED64_de(void *arg0, void *arg1) {
    f32 temp_f2;
    s32 var_v0;

    temp_f2 = ((BoxContactPolygon *)arg1)->t;
    if (temp_f2 <= 0.0f) {
        if (((BoxContactPolygon *)arg1)->kind == 7) {
            return 0;
        }
        if ((u32) (((BoxContactPolygon *)arg1)->type - 5) < 2) {
            return 0;
        }
        if ((temp_f2 * ((BoxContactRay *)arg0)->slack) < -(D_800D0648 * D_800C36D8_de)) {
            return 0;
        }
    }
    var_v0 = 0;
    {
        f32 b = ((BoxContactPolygon *)arg1)->t;
        if (!(((BoxContactRay *)arg0)->nearest.t <= b)) {
            var_v0 = 1;
        }
    }
    return var_v0;
}
