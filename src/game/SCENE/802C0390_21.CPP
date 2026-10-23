#include "COMMON/EXTERNS_18.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "sdk/os.h"

extern struct IntPair D_80149B10[];

void func_802BB550_de(s32 arg0, s32 arg1, s32 arg2) {
    extern u32 func_802BCF30_de(void);
    u32 mask;
    struct IntPair *e;

    mask = func_802BCF30_de();
    ;
    (&D_80149B10[arg0])->field_0 = arg1;
    (*(&D_80149B10[arg0])).field_4 = arg2;
    __osRestoreInt(mask);
}
