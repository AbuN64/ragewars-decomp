#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80268160.h"
#include "types.h"







extern void func_8027207C_de(f32 *);
extern void func_80271F9C_de(void *, void *, f32);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);

void func_80268A40_de(RangeNode **arg0, u32 arg1, u32 arg2, u32 arg3,
                   Vec3 *arg4, f32 *arg5) {
    Vec3 delta;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f3;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    RangeNode *node;
    u16 *radius_ptr;

    node = *arg0;
    if (node != 0) {
        do {
            if (node->active != 0) {
                var_f2 = *(f32 *)&arg1 - (f32)node->x;
                radius_ptr = node->radius;
                if (var_f2 < 0.0f) {
                    var_f2 = -var_f2;
                }
                temp_f1 = *(f32 *)&arg2 - (f32)node->y;
                if (temp_f1 < 0.0f) {
                    var_f2_2 = var_f2 - temp_f1;
                } else {
                    var_f2_2 = var_f2 + temp_f1;
                }
                temp_f0 = *(f32 *)&arg3 - (f32)node->z;
                if (temp_f0 < 0.0f) {
                    var_f2_3 = var_f2_2 - temp_f0;
                } else {
                    var_f2_3 = var_f2_2 + temp_f0;
                }
                temp_f3 = (f32)*radius_ptr;
                if (var_f2_3 < temp_f3) {
                    delta.x = (f32)node->x - *(f32 *)&arg1;
                    delta.y = (f32)node->y - *(f32 *)&arg2;
                    delta.z = (f32)node->z - *(f32 *)&arg3;
                    temp_f20 = D_800C4490_de - (var_f2_3 / temp_f3);
                    func_8027207C_de(&delta);
                    temp_f20_2 = temp_f20 * D_800C4494_de;
                    func_80271F9C_de(&delta, &delta, temp_f20_2);
                    func_80271F34_de(arg4, arg4, &delta);
                    *arg5 -= temp_f20_2;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}
