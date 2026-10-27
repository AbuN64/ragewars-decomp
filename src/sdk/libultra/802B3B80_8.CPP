#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
#include "TYPES.H"
#include "sdk/libgultra_inferred/802AD870_8.H"
struct SeqpSetSeqEvent {
    s16 count;
    s16 _pad2;
    ALCSeq_s *sequence;
    s32 _pad8;
    s32 _padC;
};

extern void func_802B00D4_de(void *, s16 *, s32);

void alCSPSetSeq(s32 player, ALCSeq_s *sequence) {
    struct SeqpSetSeqEvent sp10;

    sp10.sequence = sequence;
    sp10.count = 0xD;
    func_802B00D4_de(player + 0x48, &sp10, 0);
}


void alCSPSetVol(s32 player, s16 arg1) {
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
