#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802536F4.h"
#include "types.h"



extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 arg0);
extern void func_802BB2A0_de(s32 arg0, s32 arg1, s32 arg2);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);



extern s32 D_80101134[];
extern s32 D_80101140;


void func_80253BBC_de(s32 arg0, func_80205628_S3 *arg1) {
    s32 index;
    s32 mask;
    s32 flags;
    s32 counter;
    s32 counter2;
    s32 *base;
    u32 token;
    u32 token2;

    base = &D_801005A8;
    index = *base;
    token = func_802BCF30_de();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        func_802BCF50_de(token);
        func_802BB2A0_de((s32)((char *)base + 0xB98), 0, 1);
    } else {
        func_802BCF50_de(token);
    }

    if (D_80100598[index] != 0) {
        mask = 0x200;
        if (index != 0) {
            mask = 0x400;
        }
        flags = arg1->unkC;
        if (!(flags & mask)) {
            arg1->unkC = flags | mask;
            D_80101134[index]++;
        }
    }

    token2 = func_802BCF30_de();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        func_802BCF50_de(token2);
        func_802BB420_de(&D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(token2);
}
