#include "span_1000/code_802BA23C.h"
#include "types.h"

extern State_func_802BA700_de *D_800D4414;
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32);

void func_802BA8C0_de(s32 arg0) {
    u32 savedMask;

    savedMask = func_802BCF30_de();
    D_800D4414->word4 = arg0;
    D_800D4414->status |= 0x10;
    func_802BCF50_de(savedMask);
}
