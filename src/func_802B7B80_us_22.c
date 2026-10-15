#include "span_1000/code_802BB15C.h"
#include "span_1000/code_802B7B80.h"
#include "span_1000/code_802B9BB4.h"
#include "types.h"



extern u8 D_8014D4B0;
extern u8 D_80154110[];


extern void func_802B86F0_de(s32 arg0, s32 arg1);
extern s32 __osSiRawStartDma(s32, s32);
extern u32 func_802B8C88_de(void *arg0);
extern u32 func_80446D80_de(s32 arg0, s32 arg1);


u32 func_802B84C0_de(s32 arg0, s32 arg1, u16 arg2, u8 *arg3) {
    Block40 saved;
    u8 *source;
    s32 i;
    s32 retries;
    u32 result;

    source = D_80154110;
    retries = 2;
    func_802B9C14_de();
    D_8014D4B0 = 2;
    func_802B86F0_de(arg1, arg2 & 0xFFFF);
    __osSiRawStartDma(1, D_80154110);
    func_802BB2A0_de(arg0, 0, 1);
    do {
        __osSiRawStartDma(0, D_80154110);
        func_802BB2A0_de(arg0, 0, 1);
        source = D_80154110;
        if (arg1 != 0) {
            i = 0;
            if (arg1 > 0) {
                do {
                    i++;
                    source++;
                } while (i < arg1);
            }
        }
        saved = *(Block40 *)source;
        result = (saved.bytes[2] & 0xC0) >> 4;
        if (result == 0) {
            if ((func_802B8C88_de(&saved.bytes[6]) & 0xFF) != saved.bytes[0x26]) {
                result = func_80446D80_de(arg0, arg1);
                if (result != 0) {
                    break;
                }
                result = 4;
            } else {
                i = 0;
                do {
                    *arg3++ = ((Block40 *)((u8 *)&saved + i))->bytes[6];
                    i++;
                } while (i < 0x20);
            }
        } else {
            result = 1;
        }
        if (result != 4) {
            break;
        }
    } while (retries-- >= 0);
    func_802B9C80_de();
    return result;
}
