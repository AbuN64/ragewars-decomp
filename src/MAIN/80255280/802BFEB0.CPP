#include "MAIN/80255280.H"
#include "span_1000/code_802BAC58.h"
#include "TYPES.H"
#include "common/unused.h"
#include "shared/func_802BB8B0_de_closed.h"

extern void __osRestoreInt(u32);


u64 func_802BADC0_de(void) {
    u32 saved;
    u32 count;
    u32 elapsed;
    u64 time;

    saved = func_802BCF30_de();
    count = func_802BCF00_de();
    elapsed = count - D_80149B90;
    time = D_80149B98;
    __osRestoreInt(saved);
    return time + elapsed;
}
