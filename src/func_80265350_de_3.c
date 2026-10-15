#include "span_1000/code_80265370.h"
#include "types.h"
extern s32 D_800CBC80;
extern s32 D_8010C4A0;
void func_80265DD0_de(void) {
    D_8010C4A0 = D_800CBC80;
    if (D_800CBC80 == 0) {
        D_800CBC80 = 0x20;
        return;
    }
    D_800CBC80 = 0;
}
