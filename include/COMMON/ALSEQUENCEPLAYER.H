#ifndef COMMON_ALSEQUENCEPLAYER_H
#define COMMON_ALSEQUENCEPLAYER_H
struct ALSeq_s;
#ifndef FUNC_802B0A90_DE_CLOSED_H
#define FUNC_802B0A90_DE_CLOSED_H
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

extern char D_800C7440[];   /* "EX" */
extern char D_800C7444[];   /* "audio/seqplayer.c" */

extern void func_802B1E80_de(struct ALSeq_s *, ALEvent *);                 /* alSeqNextEvent */
extern void func_802B0C94_de(ALSeqPlayer *, ALEvent *);           /* __handleMIDIMsg */
extern void func_802B1DEC_de(ALSeqPlayer *, ALEvent *);           /* __handleMetaMsg */
extern u8 func_802B22F4_de(struct ALSeq_s *, s32 *);                       /* __alSeqNextDelta (char; unsigned in this build) */
extern int func_802B20C8_de(struct ALSeq_s *arg0);                             /* alSeqGetTicks */
extern void alSeqSetLoc(struct ALSeq_s *, ALSeqMarker *);             /* alSeqSetLoc */
extern void func_802B00D4_de(ALEventQueue *, ALEvent *, ALMicroTime);  /* alEvtqPostEvent */
                /* __assert */

static inline void postNextSeqEvent(struct ALSequencePlayer *seqp)
{
    ALEvent evt;
    s32 deltaTicks;
    struct ALSeq_s *seq = seqp->base.target;

    if ((seqp->base.state != 1) || (seq == 0))
        return;

    if (!func_802B22F4_de(seq, &deltaTicks))
        return;

    if (seqp->loopCount) {
        if (func_802B20C8_de(seq) + deltaTicks >= seqp->loopEnd->curTicks) {
            alSeqSetLoc(seq, seqp->loopStart);
            if (seqp->loopCount != -1)
                seqp->loopCount--;
        }
    }

    evt.type = 0;   /* AL_SEQ_REF_EVT */
    func_802B00D4_de(&seqp->base.evtq, &evt, deltaTicks * seqp->base.uspt);
}


#endif
#endif
