#include "span_16E000/code_8042F988.h"
#include "types.h"

/* Receives player p's 0x648-byte packet through func_80404F58_de into the buffer at 0x2E28 of the
   records D_800E54A4 points to and, when func_804057F8_de checksums its first 0x640 bytes to the
   word stored after them, copies those bytes to the data at 0x18 of the player's 2920-byte record
   at 0x58 and the trailing word at 0x640 to the record's last word, returning 1; otherwise it reports the failure through
   func_80404858_de, marks both of the record's states at 0x0 and 0x14 as 2 and returns 0. Written
   from the assembly with nested tests each reporting the failure, which GCC cross-jumps into one
   call. */







extern struct Block_func_80434638_de *D_800E54A4;
extern s32 func_80404F58_de(s32, s32, struct Packet *, s32);
extern s32 func_804057F8_de(struct Packet *, s32, s32);
extern void func_802A0724_de(void *, void *, s32);
extern void func_80404858_de(s32, s32);

s32 func_80434638_de(s32 player, s32 channel) {
    struct Packet *packet;
    s32 received;

    received = 0;
    packet = &D_800E54A4->packet;
    if (func_80404F58_de(player, channel, packet, 0x648) == 0) {
        if (func_804057F8_de(packet, 0x640, 7) == packet->checksum) {
            func_802A0724_de(D_800E54A4->players[player].data, &D_800E54A4->packet, 0x640);
            received = 1;
            D_800E54A4->players[player].tail = D_800E54A4->packet.tail;
        } else {
            func_80404858_de(player, channel);
        }
    } else {
        func_80404858_de(player, channel);
    }
    if (received == 0) {
        D_800E54A4->players[player].second = 2;
        D_800E54A4->players[player].first = 2;
    }
    return received;
}
