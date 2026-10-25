#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_11.H"
#include "sdk/os.h"

extern void func_802BC36C_de(void *arg0);
extern s32 __osPopThread(OSMesgQueue *arg0);
extern void func_802BB750_de(s32 arg0);



extern OSThread_s *D_800D5270;

s32 func_802BB160_de(OSMesgQueue *arg0, void *arg1, s32 arg2) {
    u32 saved;
    s32 index;

    saved = __osDisableInt();
    while (arg0->validCount >= arg0->msgCount) {
        if (arg2 != 1) {
            __osRestoreInt(saved);
            return -1;
        }
        D_800D5270->state = 8;
        func_802BC36C_de(&arg0->fullqueue);
    }

    index = (arg0->first + arg0->msgCount - 1) % arg0->msgCount;
    arg0->first = index;
    arg0->msg[index] = arg1;
    arg0->validCount++;
    if (*arg0->mtqueue != 0) {
        func_802BB750_de(__osPopThread(arg0));
    }
    __osRestoreInt(saved);
    return 0;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802BB1C4[3] = {
    0x00010008, 0x00000009, 0x43506C61,
};
#endif
