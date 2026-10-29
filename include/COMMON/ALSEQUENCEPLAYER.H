#ifndef COMMON_ALSEQUENCEPLAYER_H
#define COMMON_ALSEQUENCEPLAYER_H
#include "COMMON/LONE/SEQUENCE_PLAYER_ASSERT_TEXT.H"
#include "COMMON/LONE/G_AUDIOSEQPLAYERTEXT.H"
struct ALSeq_s;
#ifndef COMMON_SEQUENCE_PLAYER_EVENT_HELPERS_H
#define COMMON_SEQUENCE_PLAYER_EVENT_HELPERS_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/OBJRECAT18V1.H"
struct ALSequencePlayer {
    ALSeqPlayer base;
    ALSeqMarker *loopStart;
    ALSeqMarker *loopEnd;
    s32 loopCount;
};
struct ALSequenceLoopEvent {
    ALSeqMarker *start;
    ALSeqMarker *end;
    s32 count;
};


extern void alSeqNextEvent(struct ALSeq_s *, ALEvent *);                 /* alSeqNextEvent */
extern void Seqplayer_HandleSequenceMidiEvent(ALSeqPlayer *, ALEvent *);           /* __handleMIDIMsg */
#include "libultra/audio/seqp_events.h"
extern int alSeqGetTicks(struct ALSeq_s *sequence);                             /* alSeqGetTicks */
extern void alSeqSetLoc(struct ALSeq_s *, ALSeqMarker *);             /* alSeqSetLoc */
extern void alEvtqPostEvent(ALEventQueue *, ALEvent *, ALMicroTime);  /* alEvtqPostEvent */
                /* __assert */

static inline void postNextSeqEvent(struct ALSequencePlayer *seqp)
{
    ALEvent evt;
    s32 deltaTicks;
    struct ALSeq_s *seq = seqp->base.target;

    if ((seqp->base.state != 1) || (seq == 0))
        return;

    if (!__alSeqNextDelta(seq, &deltaTicks))
        return;

    if (seqp->loopCount) {
        if (alSeqGetTicks(seq) + deltaTicks >= seqp->loopEnd->curTicks) {
            alSeqSetLoc(seq, seqp->loopStart);
            if (seqp->loopCount != -1)
                seqp->loopCount--;
        }
    }

    evt.type = 0;   /* AL_SEQ_REF_EVT */
    alEvtqPostEvent(&seqp->base.evtq, &evt, deltaTicks * seqp->base.uspt);
}


#endif
#endif
