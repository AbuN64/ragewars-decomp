#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802661FC.h"
#include "types.h"





extern s32 func_802394BC_de(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5, Triple arg6);
extern char D_80145088;
extern f32 D_800C4450_de[2];

void func_80267DB4_de(s32 arg0, s32 arg1, s32 arg2, Triple t, Vec4s v) {
    func_802394BC_de(&D_80145088, (f32) v.x, (f32) v.y, (f32) v.z, (f32) v.w * D_800C4450_de[1], 1, t);
}
