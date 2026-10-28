#include "include_asm.h"
#include "COMMON/WORLDSORTENTRY.H"
#include "SCENE/SCHED_GETCOMMANDQUEUE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_3.H"
#include "sdk/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "sdk/SCHED/osscremoveclient.H"
#include "sdk/libgultra/OSWRITEBACKDCACHEALL.H"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"
/** Return the address 0x78 bytes into the supplied object. */
void *Sched_GetCommandQueue(void *object) {
    ObjRecAt78V2 *record = object;
    return &record->unk78;
}
