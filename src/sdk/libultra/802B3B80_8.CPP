#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
#include "TYPES.H"

extern s32 func_802B00D4_de(void *, s16 *, s32);

void func_802AFF30_de(s32 player, s32 sequence) {
    Buf16 sp10;

    sp10.value = sequence;
    sp10.count = 0xD;
    func_802B00D4_de(player + 0x48, &sp10, 0);
}


void func_802AFF60_de(s32 player, s16 arg1) {
    Buf16b volumeEvent;

    volumeEvent.value = arg1;
    volumeEvent.count = 0xA;
    func_802B00D4_de(player + 0x48, &volumeEvent, 0);
}


void func_802AFF90_de(s32 player) {
    s16 stopEvent[8];

    stopEvent[0] = 0x11;
    func_802B00D4_de(player + 0x48, stopEvent, 0);
}
