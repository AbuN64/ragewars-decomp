#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

extern void __osPackRequestData(s32 cmd);


s32 osContStartQuery(s32 completionQueue) {
    s32 result;
    u8 *p;

    __osSiGetAccess();
    p = &g_controllerLastCommand;
    if (*p != 0) {
        __osPackRequestData(0);
        __osSiRawStartDma(1, &g_controllerQueryPifBuffer);
        osRecvMesg(completionQueue, 0, 1);
    }
    result = __osSiRawStartDma(0, &g_controllerQueryPifBuffer);
    *p = 0;
    __osSiRelAccess();
    return result;
}

s32 __osContGetInitData(s32 *, s32);
void osContGetQuery(s32 controllerStatus) {
    s32 validControllerMask;
    __osContGetInitData(&validControllerMask, controllerStatus);
}
