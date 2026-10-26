#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "sdk/os.h"

void Sched_SendSchedulerTask(s32 arg0, s32 arg1) {
    osSendMesg(arg0 + 0x78, arg1, 1);
    osSendMesg(arg0 + 0x40, 6, 1);
}
