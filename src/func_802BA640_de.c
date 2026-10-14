#include "span_1000/code_802BA23C.h"
#include "types.h"

/** Returns D_800D8440. */
extern void *D_800D8440;

void *func_802BA640_de(void) {
    return D_800D8440;
}

extern void *D_800D4414;
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);

void func_802BA650_de(s32 arg0, s32 arg1, s16 arg2) {
    u32 temp_v0;
    Rec_func_802BA650_de *rec;

    temp_v0 = func_802BCF30_de();
    rec = D_800D4414;
    rec->f10 = arg0;
    rec->f14 = arg1;
    rec->f2 = arg2;
    func_802BCF50_de(temp_v0);
}
