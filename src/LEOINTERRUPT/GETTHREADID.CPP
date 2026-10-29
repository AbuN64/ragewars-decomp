#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OSTHREAD_S.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "AUDIO/GETTHREADID.H"

/** Return the global word at g_audioInterruptMask. */

int Audio_GetInterruptMask(void) {
    return g_audioInterruptMask;
}

extern void *g_osRunningThread;




/** Return offset 0x14 from the supplied object or the default global object. */
unsigned int Audio_GetThreadIdentifier(void *object) {
    ThreadIdentifierView *object_record;
    if (object == 0) {
        object = g_osRunningThread;
    }
    object_record = object;
    return object_record->threadId;
}
