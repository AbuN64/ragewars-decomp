#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "../../../sdk/include/os.h"

void Sched_SendSchedulerTask(s32 schedulerAddress, s32 taskMessage) {
    osSendMesg((char *)&((struct OSSched *)schedulerAddress)->commandQueue, taskMessage, 1);
    osSendMesg((char *)&((struct OSSched *)schedulerAddress)->interruptQueue, 6, 1);
}
