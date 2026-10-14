#include "span_1000/code_802A208C.h"
#include "types.h"

extern s32 D_800CDA24;
extern void func_8029AA34_de(s32 *arg0);

void func_802A2360_de(void) {
    s32 *p;

    p = &D_800CDA24;
    if (*p != 1) {
        *p = 1;
        func_8029AA34_de(p);
    }
}
