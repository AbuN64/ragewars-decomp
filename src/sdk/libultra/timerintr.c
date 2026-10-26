
/* __osInsertTimer, drafted from ultralib src/os/timerintr.c. */
#include "TYPES.H"
#include "sdk/os.h"
#include "sdk/OS_TIMER.H"




extern OSTimer *D_800D5280;

u64 __osInsertTimer(OSTimer *t)
{
    OSTimer *timep;
    u64 tim;
    u32 savedMask = __osDisableInt();

    timep = D_800D5280->next;
    tim = t->value;
    for (; timep != D_800D5280 && tim > timep->value; timep = timep->next) {
        tim -= timep->value;
    }

    t->value = tim;

    if (timep != D_800D5280) {
        timep->value -= tim;
    }

    t->next = timep;
    t->prev = timep->prev;
    timep->prev->next = t;
    timep->prev = t;
    __osRestoreInt(savedMask);
    return tim;
}
