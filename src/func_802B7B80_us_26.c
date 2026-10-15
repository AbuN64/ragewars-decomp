#include "span_1000/code_802B7B80.h"
#include "types.h"



extern u32 D_80154110[];
extern u32 func_802B8C40_de(u32 arg0);

void func_802B8AA0_de(s32 arg0, s32 arg1, u8 *arg2) {
    Block40 packet;
    u8 *dst;
    s32 i;
    u8 tail;
    u32 checksum;
    s32 shifted;

    dst = (u8 *)D_80154110;
    tail = 0xFF;
    D_80154110[0xF] = 1;
    packet.bytes[0] = tail;
    packet.bytes[1] = 0x23;
    packet.bytes[2] = 1;
    packet.bytes[3] = 3;
    checksum = func_802B8C40_de(arg1 & 0xFFFF);
    shifted = arg1 << 5;
    *(u16 *)&packet.bytes[4] = (checksum & 0xFF) | shifted;
    packet.bytes[0x26] = tail;
    i = 0;
    do {
        ((Block40 *)((u8 *)&packet + i))->bytes[6] = *arg2++;
        i++;
    } while (i < 0x20);
    if (arg0 != 0) {
        i = 0;
        if (arg0 > 0) {
            do {
                *dst++ = 0;
                i++;
            } while (i < arg0);
        }
    }
    *(Block40 *)dst = packet;
    dst[0x28] = 0xFE;
}
