#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8025E280.h"
#include "types.h"


extern s32 D_80109E0C;


void func_8025E2D4_de(s32 a) {
    if (D_801427D0 == 0) {
        s32 *p = &D_80109E0C;
        if (*p != a) {
            *p = a;
            if (a == 0) {
                func_8025E318_de();
            }
        }
    }
}
