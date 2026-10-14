#include "span_1000/code_802508E0.h"
#include "types.h"
s32 func_80250274_de();
s32 func_802504B0_de();
extern u8 D_801462E5;
void func_80250A9C_de(void) {
    if (D_801462E5 != 0) {
        func_802504B0_de();
        return;
    }
    func_80250274_de();
}
