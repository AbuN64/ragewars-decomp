#include "MAIN/802B8DD0.H"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802BAC58.h"
extern void *D_800D5270;




/** Return field 0x4 of arg0, falling back to a global record when arg0 is null. */
int func_802BADA0_de(void *arg0) {
    OSThread_s *p = arg0;
    if (p == 0) {
        p = D_800D5270;
    }
    return p->priority;
}
