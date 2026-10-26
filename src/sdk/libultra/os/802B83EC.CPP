#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/UNUSED.H"
#include "sdk/OS_2/802B83EC_2.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

extern u32 func_80446D80_de(s32 arg0, s32 arg1);


u32 func_802B84C0_de(s32 completionQueue, s32 channel, u16 blockAddress, u8 *outputData) {
    Block40 saved;
    u8 *source;
    s32 i;
    s32 retries;
    u32 result;

    source = (u8 *)&D_80154110;
    retries = 2;
    func_802B9C14_de();
    D_8014D4B0 = 2;
    func_802B86F0_de(channel, blockAddress & 0xFFFF);
    __osSiRawStartDma(1, (u8 *)&D_80154110);
    osRecvMesg(completionQueue, 0, 1);
    do {
        __osSiRawStartDma(0, (u8 *)&D_80154110);
        osRecvMesg(completionQueue, 0, 1);
        source = (u8 *)&D_80154110;
        if (channel != 0) {
            i = 0;
            if (channel > 0) {
                do {
                    i++;
                    source++;
                } while (i < channel);
            }
        }
        saved = *(Block40 *)source;
        result = (saved.bytes[2] & 0xC0) >> 4;
        if (result == 0) {
            if ((func_802B8C88_de(&saved.bytes[6]) & 0xFF) != saved.bytes[0x26]) {
                result = func_80446D80_de(completionQueue, channel);
                if (result != 0) {
                    break;
                }
                result = 4;
            } else {
                i = 0;
                do {
                    *outputData++ = ((Block40 *)((u8 *)&saved + i))->bytes[6];
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
