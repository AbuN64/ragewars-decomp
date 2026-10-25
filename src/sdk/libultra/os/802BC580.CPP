#include "COMMON/EXTERNS_18.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

extern void func_802B7A20_de(s32 arg0);


s32 func_802B74B0_de(s32 arg0) {
    s32 result;
    u8 *p;

    func_802B9C14_de();
    p = &D_8014D4B0;
    if (*p != 0) {
        func_802B7A20_de(0);
        __osSiRawStartDma(1, &D_8014D470);
        osRecvMesg(arg0, 0, 1);
    }
    result = __osSiRawStartDma(0, &D_8014D470);
    *p = 0;
    func_802B9C80_de();
    return result;
}

s32 func_802B7AD8_de(s32 *, s32);
void func_802B7538_de(s32 arg0) {
    s32 sp10;
    func_802B7AD8_de(&sp10, arg0);
}
