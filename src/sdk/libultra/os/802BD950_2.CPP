#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "sdk/OS_2/802BD950_2.H"
#include "sdk/os_pif.h"

extern u32 __osContAddressCrc(u32 arg0);

void __osPackRamWriteData(s32 channel, s32 blockAddress, u8 *inputData) {
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
    packet.bytes[1] = 0x23;
    packet.bytes[2] = 1;
    packet.bytes[3] = 3;
    checksum = __osContAddressCrc(blockAddress & 0xFFFF);
    shifted = blockAddress << 5;
    *(u16 *)&packet.bytes[4] = (checksum & 0xFF) | shifted;
    packet.bytes[0x26] = tail;
    i = 0;
    do {
        ((Block40 *)((u8 *)&packet + i))->bytes[6] = *inputData++;
        i++;
    } while (i < 0x20);
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

#if defined(VERSION_US)
unsigned int func_802B8AA0_de_padding_B9768[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B8B6C[1] = {
    0x0011504C,
};
#endif
