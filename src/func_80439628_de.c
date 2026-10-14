#include "span_16E000/code_8043962C.h"
#include "types.h"





extern s32 D_800E28E0;
extern Pulse *D_800E5950;

extern void func_802A2360_de(void);


/* Advances a sine-driven pulse phase and writes the resulting display intensity byte. */
s32 func_80439628_de(s32 arg0, s32 arg1, s32 arg2) {
    if (D_800E28E0 >= 2) {
        return 0;
    }
    func_802A2360_de();
    D_800E5950->phase += arg2;
    D_800E5950->light->field_10 = (u32)(func_802B6560_de(D_800E5950->phase * 0.005f) * 100.0f + 150.0f);
    return 0;
}
