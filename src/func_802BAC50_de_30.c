#include "span_1000/code_802BAC58.h"
#include "types.h"

extern u32 func_802BCF30_de(void);
extern u32 func_802BCF00_de(void);
extern void func_802BCF50_de(u32);

extern s32 D_80149B90;
extern u64 D_80149B98;

u64 func_802BADC0_de(void) {
    u32 saved;
    u32 count;
    u32 elapsed;
    u64 time;

    saved = func_802BCF30_de();
    count = func_802BCF00_de();
    elapsed = count - D_80149B90;
    time = D_80149B98;
    func_802BCF50_de(saved);
    return time + elapsed;
}
