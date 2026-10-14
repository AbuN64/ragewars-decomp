#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"



extern struct IntPair D_80149B10[];
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);

void func_802BB550_de(s32 arg0, s32 arg1, s32 arg2) {
    u32 temp_v0;
    struct IntPair *e;

    temp_v0 = func_802BCF30_de();
    ;
    (&D_80149B10[arg0])->field_0 = arg1;
    (*(&D_80149B10[arg0])).field_4 = arg2;
    func_802BCF50_de(temp_v0);
}
