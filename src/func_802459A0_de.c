#include "span_1000/code_80245980.h"
#include "shared/func_804235A8_eu_layout.h"
#include "types.h"

extern f32 func_8040184C_de(f32 arg0);
extern void *D_800E2830;






f32 func_802459A0_de(void) {
    void *record = D_800E2830;
    f32 temp_f1;

    if (((Shared_MenuContext *)record)->active == 0) {
        return D_800C37D4_de;
    }
    temp_f1 = ((Shared_MenuContext *)record)->response;
    if (!(D_800C37D8_de < temp_f1)) {
        return func_8040184C_de(((Shared_MenuContext *)record)->time);
    }
    return temp_f1;
}
