#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8023EEF0.h"
#include "types.h"



extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);




s32 func_80241260_de(void *arg0, Vec3 *arg1) {
    Plane *object = arg0;
    Vec3 sp10;
    s32 var_v0;

    func_80271F68_de(&sp10, arg1, &object->pos);
    var_v0 = 0;
    if (!((object->normal.x * sp10.x) + (object->normal.y * sp10.y) + (object->normal.z * sp10.z) >= 0.0f)) {
        var_v0 = 1;
    }
    return var_v0;
}
