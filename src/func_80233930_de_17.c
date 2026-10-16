#include "span_1000/code_80233920.h"
#include "types.h"
extern s32 D_801462C8;


void func_802391F8_de(ThreeChannels *arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    if (D_801462C8 & 0x4000) {
        *arg1 = 0;
        *arg2 = 0;
        *arg3 = 0;
        return;
    }
    *arg1 = arg0->first & 0xF8;
    *arg2 = arg0->second & 0xF8;
    *arg3 = arg0->third & 0xF8;
}
