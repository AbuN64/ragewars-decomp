#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/UNUSED.H"
#include "sdk/OS/802B83EC_2.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

/* 802B83EC.CPP */
extern u32 __osPfsGetStatus(s32 arg0, s32 arg1);

u32 __osContRamRead(s32 completionQueue, s32 channel, u16 blockAddress, u8 *outputData) {
    Block40 saved;
    u8 *source;
    s32 i;
    s32 retries;
    u32 result;

    source = (u8 *)&D_80154110;
    retries = 2;
    __osSiGetAccess();
    D_8014D4B0 = 2;
    __osPackRamReadData(channel, blockAddress & 0xFFFF);
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
            if ((__osContDataCrc(&saved.bytes[6]) & 0xFF) != saved.bytes[0x26]) {
                result = __osPfsGetStatus(completionQueue, channel);
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
    __osSiRelAccess();
    return result;
}

/* 802B83EC_2.CPP */
/* Packs one controller-pak read command for a given address into the PIF RAM block D_80154110 after skipping one zero byte per preceding channel, with its data bytes set to 0xFF and the end marker after it (libultra __osPackRamReadData). Adapted from __osPackRamWriteData with the command bytes changed to a read and the data bytes filled with 0xFF instead of copied. */

extern u32 __osContAddressCrc(u32 arg0);

void __osPackRamReadData(s32 channel, s32 blockAddress) {
    Block40 packet;
    u8 *dst;
    s32 i;
    u8 tail;
    u32 checksum;
    s32 shifted;

    dst = (u8 *)&D_80154110;
    tail = 0xFF;
    D_80154110.pifstatus = 1;
    packet.bytes[0] = tail;
    packet.bytes[1] = 3;
    packet.bytes[2] = 0x21;
    packet.bytes[3] = 2;
    checksum = __osContAddressCrc(blockAddress & 0xFFFF);
    shifted = blockAddress << 5;
    *(u16 *)&packet.bytes[4] = (checksum & 0xFF) | shifted;
    packet.bytes[0x26] = tail;
    for (i = 0; i < 32; i++) {
        ((Block40 *)((u8 *)&packet + i))->bytes[6] = 0xFF;
    }
    if (channel != 0) {
        i = 0;
        if (channel > 0) {
            do {
                *dst++ = 0;
                i++;
            } while (i < channel);
        }
    }
    *(Block40 *)dst = packet;
    dst[0x28] = 0xFE;
}
