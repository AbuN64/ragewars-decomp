#include "TYPES.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OSTHREAD_S.H"

extern void *D_800D5270;




/** Return field 0x4 of arg0, falling back to a global record when arg0 is null. */
int func_802BADA0_de(void *arg0) {
    OSThread_s *p = arg0;
    if (p == 0) {
        p = D_800D5270;
    }
    return p->priority;
}
