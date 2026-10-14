#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B243C.h"
#include "types.h"
#include "audio_events.h"
/* alSeqNewMarker, drafted from ultralib src/audio/seq.c: fill a marker with the sequence position
   of the first event at or after the given tick count (the track start for zero), stepping a
   scratch pass with alSeqNextEvent and restoring the sequence's own position afterwards. */
extern void func_802B1E80_de(ALSeq_s *, ALEvent_func_802B21A8_de *); /* alSeqNextEvent */
void func_802B21A8_de(ALSeq_s *seq, ALSeqMarker *m, u32 ticks)
{
    ALEvent_func_802B21A8_de evt;
    u8 *savePtr, *lastPtr;
    s32 saveTicks, lastTicks;
    s16 saveStatus, lastStatus;
    if (ticks == 0) {
        m->curPtr = seq->trackStart;
        m->lastStatus = 0;
        m->lastTicks = 0;
        m->curTicks = 0;
        return;
    } else {
        savePtr = seq->curPtr;
        saveStatus = seq->lastStatus;
        saveTicks = seq->lastTicks;
        seq->curPtr = seq->trackStart;
        seq->lastStatus = 0;
        seq->lastTicks = 0;
        do {
            lastPtr = seq->curPtr;
            lastStatus = seq->lastStatus;
            lastTicks = seq->lastTicks;
            func_802B1E80_de(seq, &evt);
            if (evt.type == AL_SEQ_END_EVT) {
                lastPtr = seq->curPtr;
                lastStatus = seq->lastStatus;
                lastTicks = seq->lastTicks;
                break;
            }
        } while (seq->lastTicks < ticks);
        m->curPtr = lastPtr;
        m->lastStatus = lastStatus;
        m->lastTicks = lastTicks;
        m->curTicks = seq->lastTicks;
        seq->curPtr = savePtr;
        seq->lastStatus = saveStatus;
        seq->lastTicks = saveTicks;
    }
}
