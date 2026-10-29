#include "COMMON/BOOT_TV_TYPE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OSVISCALE.H"
#include "TYPES.H"
#include "COMMON/OS_TIMER_INTERRUPT_INTERNALS.H"
#include "sdk/AUDIO/OSVIGETCURRENTFRAMEBUFFER.H"
#include "sdk/os.h"

extern Field_void_4 *g_currentVideoInterfaceContext;

void *osViGetCurrentFramebuffer(void) {
    void *result = __osDisableInt();
    void *saved = g_currentVideoInterfaceContext->value;
    __osRestoreInt(result);
    return saved;
}
