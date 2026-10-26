#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/UNUSED.H"
#include "sdk/OS_2/802BD950_2.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

/* Writes a 32-byte block to a controller pak address through the PIF RAM, re-reading the reply up to three times until the data CRC matches, and returns 0, 1 for no pak, 4 for a CRC failure or the pak status error (libultra __osContRamWrite). Adapted from func_802B84C0_de with the read command 2 changed to the write command 3 packed by func_802B8AA0_de, a guard returning 0 for label-area addresses below 7 unless forced, the CRC taken over the caller's buffer with no copy back, and the DMA results assigned to the result as libultra does. */





extern u32 __osPfsGetStatus(s32 arg0, s32 arg1);


u32 func_802B8880_de(s32 completionQueue, s32 channel, u16 blockAddress, u8 *inputData, s32 forceWrite) {
    Block40 saved;
    u8 *source;
    s32 i;
    s32 retries;
    u32 result;

    retries = 2;
    if (forceWrite != 1 && blockAddress < 7 && blockAddress != 0) {
        return 0;
    }
    func_802B9C14_de();
    D_8014D4B0 = 3;
    func_802B8AA0_de(channel, blockAddress & 0xFFFF, inputData);
    result = __osSiRawStartDma(1, (u8 *)&D_80154110);
    osRecvMesg(completionQueue, 0, 1);
    do {
        result = __osSiRawStartDma(0, (u8 *)&D_80154110);
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
            if ((func_802B8C88_de(inputData) & 0xFF) != saved.bytes[0x26]) {
                result = __osPfsGetStatus(completionQueue, channel);
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
