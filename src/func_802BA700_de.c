#include "span_1000/code_802BA23C.h"
#include "acmd.h"
#include "types.h"





extern State_func_802BA700_de *D_800D4414;
extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 arg0);

void func_802BA700_de(s32 arg0) {
    u32 token;

    token = func_802BCF30_de();
    if (arg0 & 1) {
        D_800D4414->flags |= 8;
    }
    if (arg0 & 2) {
        D_800D4414->flags &= ~8;
    }
    if (arg0 & 4) {
        D_800D4414->flags |= 4;
    }
    if (arg0 & 8) {
        D_800D4414->flags &= ~4;
    }
    if (arg0 & 0x10) {
        D_800D4414->flags |= 0x10;
    }
    if (arg0 & 0x20) {
        D_800D4414->flags &= ~0x10;
    }
    if (arg0 & 0x40) {
        D_800D4414->flags = (D_800D4414->flags | 0x10000) & ~0x300;
    }
    if (arg0 & 0x80) {
        D_800D4414->flags &= ~0x10000;
        D_800D4414->flags |= D_800D4414->inner->w1 & 0x300;
    }
    D_800D4414->status |= 8;
    func_802BCF50_de(token);
}
