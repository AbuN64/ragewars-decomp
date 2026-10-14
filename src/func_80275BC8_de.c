#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8027451C.h"
#include "types.h"





extern f32 D_800C49F0_de;
extern Vec3 D_80115E10;
extern s32 D_800CD3E8;

extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);

Vec3 *func_80275BC8_de(Vec3 *out, Node75 *node) {
    Vec3 a;
    Vec3 b;
    Vec3 *b_ptr;

    if (node == 0) {
        D_80115E10.x = 0;
        D_80115E10.z = 0;
        D_80115E10.y = D_800C49F0_de;
    } else if ((s32)node != D_800CD3E8) {
        func_80271F68_de(&a, node->cur, node->prev);
        b_ptr = &b;
        func_80271F68_de(b_ptr, node->next, node->cur);
        func_80272018_de(&D_80115E10, &a, b_ptr);
    }
    *out = D_80115E10;
    D_800CD3E8 = (s32)node;
    return out;
}
