#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8029EB74.h"
#include "types.h"





void func_8029E654_de(Vec3 *arg0, Vec3 *arg1, f32 arg2) {
    Vec3 tmp;
    f32 sp20;
    f32 sp24;

    func_8029BBB0_de(arg2, &sp20, &sp24);
    tmp.x = (sp24 * arg1->x) + (sp20 * arg1->z);
    tmp.y = arg1->y;
    tmp.z = (sp24 * arg1->z) - (sp20 * arg1->x);
    *arg0 = tmp;
}
