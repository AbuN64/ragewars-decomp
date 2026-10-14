#include "span_1000/code_80246E34.h"
#include "types.h"
#include "stddef.h"
/* Update or blend object rotation when the movement state permits it. */
void func_8024D870_de(f32 *, void *); /* extern */
s32 func_8024E29C_de(void *); /* extern */
s32 func_8024E62C_de(); /* extern */
void func_80270CD0_de(void *, f32, void *, f32 *); /* extern */
void func_80274380_de(void *, f32 *); /* extern */
extern f32 D_800C3928_de[], D_800C3930_de[], D_800D2988[];
void func_80247004_de(Obj_func_80247004_de *arg0) {
    f32 vec[4];
    f32 var_f0;
    f32 var_f1;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0;
    s32 flags;
    void *temp_a0;
    void *var_a0;
    temp_v0 = arg0->unk100;
    flags = temp_v0 & 0x300000;
    if (!(temp_v0 & 1) && (temp_s2 = func_8024E62C_de(), (arg0->unk14 != NULL)) && (func_8024D870_de(vec, arg0), temp_s1 = arg0->unk14->unk2 & 1, (func_8024E29C_de(arg0) != 0))) {
        if (temp_s1 != 0) {
            vec[0] = vec[1] = vec[2] = 0.0f;
            vec[3] = D_800C3924_de;
        }
        if (flags) {
            if ((!(arg0->unk100 & 0x1000) && (var_a0 = arg0->rotation, (temp_s2 != 0))) || (var_a0 = arg0->rotation, (temp_s1 != 0))) {
                func_80274380_de(var_a0, vec);
            }
        } else {
            if ((temp_s2 != 0) && !(arg0->unk100 & 0x1000)) {
                var_f0 = D_800D2988[0]; var_f1 = D_800C3928_de[0];
            } else {
                var_f0 = D_800D2988[0]; var_f1 = D_800C3928_de[1];
            }
            var_f0 = var_f0 * var_f1;
            temp_a0 = arg0->rotation;
            if (var_f0 > D_800C3930_de[0]) {
                var_f0 = D_800C3930_de[0];
            }
            func_80270CD0_de(temp_a0, var_f0, temp_a0, vec);
        }
    }
}
