#include "include_asm.h"
#include "sdk/libgultra.h"
#include "COMMON/SHAREDRECV4.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"





s32 func_802B3130_de(void *arg0, void **arg1, s16 arg2) {
    s16 var_a2;
    s32 var_s2;
    s32 var_v0;
    void *var_s0;

    var_a2 = arg2;
    var_s0 = ((ALSynth_func_802B3000_de *)arg0)->pLameList.next;
    var_s2 = 0;
    if ((var_s0 != 0) || (var_s0 = ((ALSynth_func_802B3000_de *)arg0)->pFreeList.next, (var_s0 != 0))) {
        *arg1 = var_s0;
        func_802B2450_de(var_s0);
        func_802B2480_de(var_s0, &((ALSynth_func_802B3000_de *)arg0)->pAllocList.next);
    } else {
        var_s0 = ((ALSynth_func_802B3000_de *)arg0)->pAllocList.next;
        var_v0 = var_s2;
        if (var_s0 != 0) {
            do {
                if ((var_a2 >= ((Node_func_802B3130_de *)var_s0)->limit->limit) &&
                    (((Node_func_802B3130_de *)var_s0)->flags == 0)) {
                    *arg1 = var_s0;
                    var_s2 = 1;
                    var_a2 = (s16)(u16)((Node_func_802B3130_de *)var_s0)->limit->limit;
                }
                var_s0 = ((Node_func_802B3130_de *)var_s0)->next;
                var_v0 = var_s2;
            } while (var_s0 != 0);
        }
    }
    return var_s2;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B3118[2] = {
    0x00000066, 0x00000004,
};
#endif
