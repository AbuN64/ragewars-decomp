#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "SDK/OS_2/802BC630_2.H"
#include "sdk/os.h"

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
