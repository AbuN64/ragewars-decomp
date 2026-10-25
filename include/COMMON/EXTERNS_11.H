#ifndef COMMON_EXTERNS_11_H
#define COMMON_EXTERNS_11_H
/* __osTimerInterrupt, drafted from ultralib src/os/timerintr.c (_FINALROM: no profiler). */
#include "TYPES.H"
#include "COMMON/UNUSED.H"


extern u32 __osDisableInt(void);


extern u32 func_802BCF00_de(void);
extern void func_802BBA4C_de(u64 tim);
extern u64 __osInsertTimer(OSTimer_s *t);
#endif
