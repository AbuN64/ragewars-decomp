#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE028.h"
#include "types.h"
#include "audio_events.h"
/* alCSeqNewMarker, drafted from ultralib src/audio/cseq.c: fill a compressed-sequence marker
   with the track state of the first event at or after the given tick count, stepping a scratch
   copy of the sequence. The -O3 library inlined alCSeqNew and alCSeqNextEvent into it; they are
   static inline helpers here, with alCSeqNew's u32-to-float conversion written out against the
   cartridge constants and each deltaFlag store made through a pointer local, as the library's
   -fforce-addr kept it frame-relative. */
extern u32 func_802AEA2C_de(ALCSeq_s *, u32); /* __readVarLen */
extern u32 func_802AE030_de(ALCSeq_s *, u32, ALEvent_func_802B21A8_de *); /* __alCSeqGetTrackEvent */
extern const double D_800C72F0_de; /* 4294967296.0 */
extern const float D_800C72F8_de; /* 1.0f */
static inline void alCSeqNew(ALCSeq_s *seq, u8 *ptr)
{
    u32 i, tmpOff, flagTmp;
    f64 t;
    s32 division;
    u32 *deltaFlag;
    seq->base = (ALCMidiHdr *)ptr;
    seq->validTracks = 0;
    seq->lastDeltaTicks = 0;
    seq->lastTicks = 0;
    deltaFlag = &seq->deltaFlag;
    *deltaFlag = 1;
    for (i = 0; i < 16; i++) {
        seq->lastStatus[i] = 0;
        seq->curBUPtr[i] = 0;
        seq->curBULen[i] = 0;
        tmpOff = seq->base->trackOffset[i];
        if (tmpOff) {
            flagTmp = 1 << i;
            seq->validTracks |= flagTmp;
            seq->curLoc[i] = (u8 *)((u32)ptr + tmpOff);
            seq->evtDeltaTicks[i] = func_802AEA2C_de(seq, i);
        } else
            seq->curLoc[i] = 0;
    }
    division = seq->base->division;
    t = (f64)division;
    if (division < 0) {
        t += D_800C72F0_de;
    }
    seq->qnpt = D_800C72F8_de / (f32)t;
}
static inline void alCSeqNextEvent(ALCSeq_s *seq, ALEvent_func_802B21A8_de *evt)
{
    u32 i;
    u32 firstTime = 0xFFFFFFFF;
    u32 firstTrack;
    u32 lastTicks = seq->lastDeltaTicks;
    u32 *deltaFlag;
    for (i = 0; i < 16; i++) {
        if ((seq->validTracks >> i) & 1) {
            if (seq->deltaFlag)
                seq->evtDeltaTicks[i] -= lastTicks;
            if (seq->evtDeltaTicks[i] < firstTime) {
                firstTime = seq->evtDeltaTicks[i];
                firstTrack = i;
            }
        }
    }
    func_802AE030_de(seq, firstTrack, evt);
    evt->msg.midi.ticks = firstTime;
    seq->lastTicks += firstTime;
    seq->lastDeltaTicks = firstTime;
    if (evt->type != 0x12)
        seq->evtDeltaTicks[firstTrack] += func_802AEA2C_de(seq, firstTrack);
    deltaFlag = &seq->deltaFlag;
    *deltaFlag = 1;
}
void func_802AE290_de(ALCSeq_s *seq, ALCSeqMarker *m, u32 ticks)
{
    ALEvent_func_802B21A8_de evt;
    ALCSeq_s tempSeq;
    s32 i;
    alCSeqNew(&tempSeq, (u8 *)seq->base);
    do {
        m->validTracks = tempSeq.validTracks;
        m->lastTicks = tempSeq.lastTicks;
        m->lastDeltaTicks = tempSeq.lastDeltaTicks;
        for (i = 0; i < 16; i++) {
            m->curLoc[i] = tempSeq.curLoc[i];
            m->curBUPtr[i] = tempSeq.curBUPtr[i];
            m->curBULen[i] = tempSeq.curBULen[i];
            m->lastStatus[i] = tempSeq.lastStatus[i];
            m->evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
        }
        alCSeqNextEvent(&tempSeq, &evt);
        if (evt.type == AL_SEQ_END_EVT)
            break;
    } while (tempSeq.lastTicks < ticks);
}
