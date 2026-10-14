#include "span_1000/code_8028CCB8.h"
#include "types.h"

extern f32 D_800C5338_de;
extern s32 D_800E28D8;





void func_8028D90C_de(void) {
    s32 var_a0;
    s32 var_a1;

    func_80245A20_de(0);
    func_80245A00_de(D_800C5338_de);
    var_a0 = 0x1E0;
    if (D_800E28D8 == 0) {
        var_a0 = 0x17C;
        var_a1 = 0xDC;
    } else {
        var_a1 = 0x168;
    }
    func_80245A5C_de(var_a0, var_a1, 0, 0);
}
