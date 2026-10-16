/* __osInsertTimer, drafted from ultralib src/os/timerintr.c. */
#include "TYPES.H"

typedef void *OSMesg;

typedef struct OSTimer_s {
    struct OSTimer_s *next;
    struct OSTimer_s *prev;
    u64 interval;
    u64 value;
    OSMesgQueue *mq;
    OSMesg msg;
} OSTimer;

extern OSTimer *D_800D5280;
extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32 mask);

u64 __osInsertTimer(OSTimer *t)
{
    OSTimer *timep;
    u64 tim;
    u32 savedMask = func_802BCF30_de();

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
