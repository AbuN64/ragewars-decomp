#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"



extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 arg0);
extern void func_802BC36C_de(void *arg0);
extern s32 func_802BC558_de(OSMesgQueue *arg0);
extern void func_802BB750_de(s32 arg0);



extern func_8025E58C_S1 *D_800D5270;

s32 func_802BB160_de(OSMesgQueue *arg0, void *arg1, s32 arg2) {
    u32 saved;
    s32 index;

    saved = func_802BCF30_de();
    while (arg0->validCount >= arg0->msgCount) {
        if (arg2 != 1) {
            func_802BCF50_de(saved);
            return -1;
        }
        D_800D5270->unk10 = 8;
        func_802BC36C_de(&arg0->fullqueue);
    }

    index = (arg0->first + arg0->msgCount - 1) % arg0->msgCount;
    arg0->first = index;
    arg0->msg[index] = arg1;
    arg0->validCount++;
    if (*arg0->mtqueue != 0) {
        func_802BB750_de(func_802BC558_de(arg0));
    }
    func_802BCF50_de(saved);
    return 0;
}
