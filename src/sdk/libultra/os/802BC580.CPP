#include "COMMON/EXTERNS_18.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

extern void __osPackRequestData(s32 arg0);


s32 osContStartQuery(s32 completionQueue) {
    s32 result;
    u8 *p;

    func_802B9C14_de();
    p = &D_8014D4B0;
    if (*p != 0) {
        __osPackRequestData(0);
        __osSiRawStartDma(1, &D_8014D470);
        osRecvMesg(completionQueue, 0, 1);
    }
    result = __osSiRawStartDma(0, &D_8014D470);
    *p = 0;
    func_802B9C80_de();
    return result;
}

s32 __osContGetInitData(s32 *, s32);
void osContGetQuery(s32 controllerStatus) {
    s32 validControllerMask;
    __osContGetInitData(&validControllerMask, controllerStatus);
}
