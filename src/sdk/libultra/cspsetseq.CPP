#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
#include "TYPES.H"
#include "sdk/libgultra_inferred/cseq.H"
struct SeqpSetSeqEvent {
    s16 count;
    s16 _pad2;
    ALCSeq_s *sequence;
    s32 _pad8;
    s32 _padC;
};

extern void alEvtqPostEvent(void *, s16 *, s32);

void alCSPSetSeq(s32 player, ALCSeq_s *sequence) {
    struct SeqpSetSeqEvent sp10;

    sp10.sequence = sequence;
    sp10.count = 0xD;
    alEvtqPostEvent(player + 0x48, &sp10, 0);
}


void alCSPSetVol(s32 player, s16 volume) {
    Buf16b volumeEvent;

    volumeEvent.value = volume;
    volumeEvent.count = 0xA;
    alEvtqPostEvent(player + 0x48, &volumeEvent, 0);
}


void alCSPStop(s32 player) {
    s16 stopEvent[8];

    stopEvent[0] = 0x11;
    alEvtqPostEvent(player + 0x48, stopEvent, 0);
}
