#include "span_1000/code_802624A0.h"
#include "types.h"

extern s32 D_8013B290;
extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);




void *func_80262FF8_de(s32 arg0, s32 *arg1) {
    void *temp_s0;

    if ((D_8013B290 != 0) || ((u32)((struct ObjectLinks5F28 *) arg0)->unk_5F24 < 3)) {
        temp_s0 = ((struct ObjectLinks5F28 *) arg0)->unk_5F00;
        if (temp_s0 != 0) {
            func_80255ED8_de((void *)(arg0 + 0x5F00), (s32)temp_s0);
            func_80255CB8_de((void *)(arg0 + 0x5F14), (s32)temp_s0);
            ((Effect_func_80262A9C_de *)(temp_s0))->ref = arg1;
            if (arg1 != 0) {
                *arg1 += 1;
            }
        }
        return temp_s0;
    }
    return 0;
}
