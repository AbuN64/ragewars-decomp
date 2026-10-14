#include "span_1000/code_8025A3EC.h"
#include "common/unused.h"
#include "span_1000/code_802B0388.h"
#include "shared/func_802B0A90_de_closed.h"

void func_802B0A90_de(struct ALSequencePlayer *seqp)
{
    Message_func_802AF150_de evt;

    if (seqp->base.target == 0)
        return;

    func_802B1E80_de(seqp->base.target, &evt);

    switch (evt.type) {
    case 1:     /* AL_SEQ_MIDI_EVT */
        func_802B0C94_de(&seqp->base, &evt);
        postNextSeqEvent(seqp);
        break;

    case 3:     /* AL_TEMPO_EVT */
        func_802B1DEC_de(&seqp->base, &evt);
        postNextSeqEvent(seqp);
        break;

    case 4:     /* AL_SEQ_END_EVT */
        seqp->base.state = 2;
        evt.type = 16;  /* AL_SEQP_STOP_EVT */
        func_802B00D4_de(&seqp->base.evtq, &evt, 0x7fffffff);
        break;

    default:
        func_802BAC50_de(D_800C7440, D_800C7444, 412);
    }
}
