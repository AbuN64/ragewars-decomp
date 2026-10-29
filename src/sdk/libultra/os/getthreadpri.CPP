#include "TYPES.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OSTHREAD_S.H"

extern void *g_osRunningThread;




/** Return field 0x4 of arg0, falling back to a global record when arg0 is null. */
int osGetThreadPri(void *thread) {
    OSThread_s *p = thread;
    if (p == 0) {
        p = g_osRunningThread;
    }
    return p->priority;
}
