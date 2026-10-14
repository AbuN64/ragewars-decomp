#include "span_1000/code_802646F4.h"
#include "types.h"
extern s8 D_8010B30B;
void func_802647C4_de(void) {
    s32 var_v1;
    s8 *var_v0;
    var_v1 = 3;
    var_v0 = &D_8010B30B;
    do {
        *var_v0 = 0;
        var_v1 -= 1;
        var_v0 -= 1;
    } while (var_v1 >= 0);
}
