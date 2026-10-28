#include "COMMON/EXTERNS_3.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "sdk/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "sdk/os.h"

extern Field_void_4 *D_800D8440;

void *osViGetCurrentFramebuffer(void) {
    void *result = __osDisableInt();
    void *saved = D_800D8440->value;
    __osRestoreInt(result);
    return saved;
}
