#include "MAIN/802B748C.H"
#include "TYPES.H"
#include "span_1000/code_802B9BB4.h"
#include "span_1000/code_802BB15C.h"
#include "common/unused.h"
/* Writes a 32-byte block to a controller pak address through the PIF RAM, re-reading the reply up to three times until the data CRC matches, and returns 0, 1 for no pak, 4 for a CRC failure or the pak status error (libultra __osContRamWrite). Adapted from func_802B84C0_de with the read command 2 changed to the write command 3 packed by func_802B8AA0_de, a guard returning 0 for label-area addresses below 7 unless forced, the CRC taken over the caller's buffer with no copy back, and the DMA results assigned to the result as libultra does. */





extern u32 func_80446D80_de(s32 arg0, s32 arg1);


u32 func_802B8880_de(s32 arg0, s32 arg1, u16 arg2, u8 *arg3, s32 arg4) {
    Block40 saved;
    u8 *source;
    s32 i;
    s32 retries;
    u32 result;

    retries = 2;
    if (arg4 != 1 && arg2 < 7 && arg2 != 0) {
        return 0;
    }
    func_802B9C14_de();
    D_8014D4B0 = 3;
    func_802B8AA0_de(arg1, arg2 & 0xFFFF, arg3);
    result = __osSiRawStartDma(1, D_80154110);
    func_802BB2A0_de(arg0, 0, 1);
    do {
        result = __osSiRawStartDma(0, D_80154110);
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
            if ((func_802B8C88_de(arg3) & 0xFF) != saved.bytes[0x26]) {
                result = func_80446D80_de(arg0, arg1);
                if (result != 0) {
                    break;
                }
                result = 4;
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
