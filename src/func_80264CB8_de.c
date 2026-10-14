#include "span_1000/code_802646F4.h"
#include "types.h"

extern s32 D_8010BC40[3];

void func_80264CB8_de(void) {
    s32 *p = D_8010BC40;
    s32 v = p[2];
    if (v != 0) {
        v = v - 1;
        p[2] = v;
        if (v == 0) {
            p[1] = 0;
        }
    }
}
