#ifndef FUNC_802BB8B0_DE_CLOSED_H
#define FUNC_802BB8B0_DE_CLOSED_H
/* __osTimerInterrupt, drafted from ultralib src/os/timerintr.c (_FINALROM: no profiler). */
#include "TYPES.H"
#include "common/unused.h"


extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32 mask);


extern u32 func_802BCF00_de(void);
extern void func_802BD150_de(u32 compare);
extern void func_802BBA4C_de(u64 tim);
extern s32 func_802BB420_de(Opaque_OSMesgQueue *mq, void * msg, s32 flag);
extern u64 __osInsertTimer(OSTimer_s *t);


#endif
