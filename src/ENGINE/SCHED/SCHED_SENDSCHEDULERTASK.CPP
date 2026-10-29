#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "../../../sdk/include/os.h"

void Sched_SendSchedulerTask(s32 schedulerAddress, s32 taskMessage) {
    osSendMesg(schedulerAddress + 0x78, taskMessage, 1);
    osSendMesg(schedulerAddress + 0x40, 6, 1);
}
