#include "COMMON/EXTERNS.H"
#include "COMMON/OSTHREAD_S.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_11.H"
#include "sdk/os.h"



u64 func_802BADC0_de(void) {
    u32 saved;
    u32 count;
    u32 elapsed;
    u64 time;

    saved = __osDisableInt();
    count = func_802BCF00_de();
    elapsed = count - D_80149B90;
    time = D_80149B98;
    __osRestoreInt(saved);
    return time + elapsed;
}
