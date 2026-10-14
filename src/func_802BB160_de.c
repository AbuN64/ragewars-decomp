#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"



extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 arg0);
extern void func_802BC36C_de(void *arg0);
extern s32 func_802BC558_de(Queue_func_802517B4_de *arg0);
extern void func_802BB750_de(s32 arg0);



extern func_8025E58C_S1 *D_800D5270;

s32 func_802BB160_de(Queue_func_802517B4_de *arg0, void *arg1, s32 arg2) {
    u32 saved;
    s32 index;

    saved = func_802BCF30_de();
    while (arg0->count >= arg0->capacity) {
        if (arg2 != 1) {
            func_802BCF50_de(saved);
            return -1;
        }
        D_800D5270->unk10 = 8;
        func_802BC36C_de(&arg0->unk04);
    }

    index = (arg0->index + arg0->capacity - 1) % arg0->capacity;
    arg0->index = index;
    arg0->entries[index] = arg1;
    arg0->count++;
    if (*arg0->head != 0) {
        func_802BB750_de(func_802BC558_de(arg0));
    }
    func_802BCF50_de(saved);
    return 0;
}
