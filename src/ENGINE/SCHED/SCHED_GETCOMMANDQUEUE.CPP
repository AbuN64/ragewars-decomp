#include "include_asm.h"
#include "COMMON/WORLDSORTENTRY.H"
#include "ENGINE/SCHED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/BOOT_TV_TYPE.H"
#include "../../../sdk/include/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "../../../sdk/include/SCHED/osscremoveclient.H"
#include "../../../sdk/include/libgultra/OSWRITEBACKDCACHEALL.H"
#include "../../../sdk/include/libgultra/sptaskyield.h"
#include "../../../sdk/include/os.h"
/** Return the address 0x78 bytes into the supplied object. */
void *Sched_GetCommandQueue(void *object) {
    SchedulerCommandQueueView *record = object;
    return &record->commandQueue;
}
