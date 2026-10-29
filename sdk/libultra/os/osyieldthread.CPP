#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/LONE/OS_RUNNABLE_THREAD_QUEUE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/NODERECAT1C.H"
#include "TYPES.H"
#include "../../include/OSINT/osyieldthread.H"
#include "../../include/os.h"

extern s32 __osProbeTLB(void);

s32 osVirtualToPhysical(s32 virtualAddress) {
    if (virtualAddress < 0 && (u32)virtualAddress <= 0x9FFFFFFFU) {
        return virtualAddress & 0x1FFFFFFF;
    }
    if ((u32)(virtualAddress + 0x60000000) > 0x1FFFFFFFU) {
        return __osProbeTLB();
    }
    return virtualAddress & 0x1FFFFFFF;
}

s32 __osEnqueueAndYield(s32 *, s32);
extern void *__osRunningThread;


void osYieldThread(void)
{
  void *savedInterruptMask;
  s32 *runnableQueue;
  s8 *runningThreadBytes;
  int runnableState;
  savedInterruptMask = __osDisableInt();
  ((OSThread_s *)(runningThreadBytes = (s8 *) __osRunningThread))->state = (runnableState = 2);
  runnableQueue = &__osRunQueue;
  __osEnqueueAndYield(runnableQueue, runnableState);
  __osRestoreInt(savedInterruptMask);
}
