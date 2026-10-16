#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_802B7488.h"
#include "span_1000/code_802B9BB4.h"
#include "span_1000/code_802BB15C.h"
#include "TYPES.H"
#include "MAIN/802B748C.H"

extern void func_802B768C_de(void);

s32 func_802B7560_de(s32 arg0) {
    extern char D_8014D470;
    s32 result;
    u8 *p;

    func_802B9C14_de();
    p = &D_8014D4B0;
    if (*p != 1) {
        func_802B768C_de();
        __osSiRawStartDma(1, &D_8014D470);
        func_802BB2A0_de(arg0, 0, 1);
    }
    result = __osSiRawStartDma(0, &D_8014D470);
    *p = 1;
    func_802B9C80_de();
    return result;
}
