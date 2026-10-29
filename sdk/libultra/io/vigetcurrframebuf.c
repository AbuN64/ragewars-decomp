#include "COMMON/BOOT_TV_TYPE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "../../include/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "../../include/os.h"

extern Field_void_4 *__osViCurr;

void *osViGetCurrentFramebuffer(void) {
    void *result = __osDisableInt();
    void *saved = __osViCurr->value;
    __osRestoreInt(result);
    return saved;
}
