#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028567C.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);






void func_80285AC4_de(void *arg0, void *arg1, s32 arg2) {
    s32 i;
    Node_func_80285B64_de *p;
    u32 saved;

    p = arg1;
    saved = func_802BCF30_de();
    func_80255CA0_de(arg0, 0, 4);
    func_80255CA0_de(&((PoolRecAt28V1 *)arg0)->active, 0, 4);
    i = 0;
    if (arg2 > 0) {
        do {
            func_80255D14_de(arg0, p);
            i += 1;
            p++;
        } while (i < arg2);
    }
    ((PoolRecAt28V1 *)arg0)->baseLevel = 0;
    func_802BCF50_de(saved);
}
