/* __osInsertTimer, drafted from ultralib src/os/timerintr.c. */
#include "types.h"

typedef void *OSMesg;
typedef struct OSMesgQueue OSMesgQueue;

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
extern void func_802BCF50_de(u32 mask);

u64 func_802BBAAC_de(OSTimer *t)
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
    func_802BCF50_de(savedMask);
    return tim;
}
