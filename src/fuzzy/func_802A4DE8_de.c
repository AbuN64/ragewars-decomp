#include "types.h"

typedef struct { s32 mode; f32 red, green, blue; } FadeColor;
typedef struct { f32 current, target; } FadeAlpha;
extern FadeColor D_800D15E0;
extern FadeAlpha D_800D15F0;
extern f32 D_800C5E64_de, D_800C5E68_de, D_800C5E6C_de;
extern f32 D_800C5E70_de, D_800C5E74_de, D_800C5E78_de;
extern f32 D_800C5E7C_de, D_800C5E80_de, D_800C5E84_de;

void func_802A4DE8_de(void) {
    f32 limit;
    s32 equal;
    limit = 0.0f;
    if (D_800D15E0.red < 0.0f || (limit = D_800C5E64_de, limit < D_800D15E0.red)) D_800D15E0.red = limit;
    limit = 0.0f;
    if (D_800D15E0.green < 0.0f || (limit = D_800C5E68_de, limit < D_800D15E0.green)) D_800D15E0.green = limit;
    limit = 0.0f;
    if (D_800D15E0.blue < 0.0f || (limit = D_800C5E6C_de, limit < D_800D15E0.blue)) D_800D15E0.blue = limit;
    limit = 0.0f;
    if (D_800D15F0.current < 0.0f || (limit = D_800C5E70_de, limit < D_800D15F0.current)) D_800D15F0.current = limit;
    limit = 0.0f;
    if (D_800D15F0.target < 0.0f || (limit = D_800C5E74_de, limit < D_800D15F0.target)) D_800D15F0.target = limit;
    equal = 0;
    if (D_800D15F0.target == D_800C5E78_de) {
        if (D_800D15F0.current == 0.0f) {
            D_800D15E0.mode = 0;
            return;
        }
        equal = D_800D15F0.target == D_800C5E7C_de;
    }
    if (!equal && D_800D15F0.current == 0.0f) {
        D_800D15E0.mode = 1;
        D_800D15F0.current = D_800D15F0.target;
        return;
    }
    equal = 0;
    if (D_800D15F0.target == D_800C5E80_de) {
        if (D_800D15F0.current != 0.0f) {
            D_800D15E0.mode = 3;
            return;
        }
        equal = D_800D15F0.target == D_800C5E84_de;
    }
    if (!equal && D_800D15F0.current != 0.0f) D_800D15E0.mode = 6;
}
