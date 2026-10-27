#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "sdk/OS_2/802B83EC_2.H"
#include "sdk/os_pif.h"

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
