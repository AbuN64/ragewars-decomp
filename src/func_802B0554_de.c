#include "span_C76B0/data.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802B0388.h"
#include "common/unused.h"
struct ALSequencePlayer {
    ALSeqPlayer_func_802B0C94_de base;
    ALSeqMarker *loopStart;
    ALSeqMarker *loopEnd;
    s32 loopCount;
};
struct ALSequenceLoopEvent {
    ALSeqMarker *start;
    ALSeqMarker *end;
    s32 count;
};

 /* 2147483648.0f */
extern char D_800C7440[];      /* "EX" */
extern char D_800C7444[];      /* "audio/seqplayer.c" */

extern void func_802B0A90_de(ALSeqPlayer_func_802B0C94_de *);                        /* __handleNextSeqEvent */
extern void func_802B0C94_de(ALSeqPlayer_func_802B0C94_de *, ALEvent10 *);             /* __handleMIDIMsg */
extern void func_802B1DEC_de(ALSeqPlayer_func_802B0C94_de *, ALEvent10 *);             /* __handleMetaMsg */
extern void func_802B1E50_de(ALSeqPlayer_func_802B0C94_de *, f32);                   /* __setUsptFromTempo */
extern void func_802B00D4_de(ALEventQueue *, ALEvent10 *, ALMicroTime); /* alEvtqPostEvent */
extern ALMicroTime func_802B003C_de(ALEventQueue *, ALEvent10 *);    /* alEvtqNextEvent */
extern void func_802B0258_de(ALEventQueue *, s16);                 /* alEvtqFlushType */
extern void func_802B36F0_de(void *, ALVoice_s *);                   /* alSynStopVoice */
extern void func_802B3200_de(void *, ALVoice_s *);                   /* alSynFreeVoice */
extern void func_802B3480_de(void *, ALVoice_s *, s16, ALMicroTime); /* alSynSetVol */
extern void func_802B33E0_de(void *, ALVoice_s *, f32);              /* alSynSetPitch */
extern s16 func_802B1814_de(ALVoiceState_s38 *, ALSeqPlayer_func_802B0C94_de *);        /* __vsVol */
extern ALMicroTime func_802B1888_de(ALVoiceState_s38 *, ALMicroTime);  /* __vsDelta */
extern void func_802B1B14_de(ALSeqPlayer_func_802B0C94_de *, ALVoice_s *, ALMicroTime); /* __seqpReleaseVoice */
extern void func_802B18E4_de(ALSeqPlayer_func_802B0C94_de *, void *);               /* __initFromBank */
extern void func_802BAC50_de(char *, char *, s32);                 /* __assert */

ALMicroTime func_802B0554_de(void *node)
{
    struct ALSequencePlayer *seqp = node;
    ALEvent10 evt;
    ALVoice_s *voice;
    ALMicroTime delta;
    ALVoiceState_s38 *vs;
    void *oscState;
    f32 oscValue;
    u8 chan;
    u32 tremelo;
    u8 *tremeloSlot;

    do {
        switch (seqp->base.nextEvent.type) {
        case 0: /* AL_SEQ_REF_EVT */
            func_802B0A90_de(&seqp->base);
            break;
        case 9: /* AL_SEQP_API_EVT */
            evt.type = 9;
            func_802B00D4_de(&seqp->base.evtq, (ALEvent10 *)&evt, seqp->base.frameTime);
            break;
        case 5: /* AL_NOTE_END_EVT */
            voice = seqp->base.nextEvent.msg.note.voice;
            func_802B36F0_de(seqp->base.drvr, voice);
            func_802B3200_de(seqp->base.drvr, voice);
            vs = (ALVoiceState_s38 *)voice->clientPrivate;
            if (vs->flags)
                func_802B1C34_de(&seqp->base, vs);
            func_802B156C_de(&seqp->base, voice);
            break;
        case 6: /* AL_SEQP_ENV_EVT */
            voice = seqp->base.nextEvent.msg.vol.voice;
            vs = (ALVoiceState_s38 *)voice->clientPrivate;
            if (vs->envPhase == 0)
                vs->envPhase = 1;
            delta = seqp->base.nextEvent.msg.vol.delta;
            vs->envGain = seqp->base.nextEvent.msg.vol.vol;
            vs->envEndTime = seqp->base.curTime + delta;
            func_802B3480_de(seqp->base.drvr, voice, func_802B1814_de(vs, &seqp->base), delta);
            break;
        case 22: /* AL_TREM_OSC_EVT */
            vs = seqp->base.nextEvent.msg.osc.vs;
            oscState = seqp->base.nextEvent.msg.osc.oscState;
            delta = (*seqp->base.updateOsc)(oscState, &oscValue);
            tremeloSlot = &vs->tremelo;
            tremelo = (u32)oscValue;
            *tremeloSlot = tremelo;
            func_802B3480_de(seqp->base.drvr, &vs->voice, func_802B1814_de(vs, &seqp->base),
                          func_802B1888_de(vs, seqp->base.curTime));
            evt.type = 22;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = oscState;
            func_802B00D4_de(&seqp->base.evtq, &evt, delta);
            break;
        case 23: /* AL_VIB_OSC_EVT */
            vs = seqp->base.nextEvent.msg.osc.vs;
            oscState = seqp->base.nextEvent.msg.osc.oscState;
            chan = seqp->base.nextEvent.msg.osc.chan;
            delta = (*seqp->base.updateOsc)(oscState, &oscValue);
            vs->vibrato = oscValue;
            func_802B33E0_de(seqp->base.drvr, &vs->voice,
                          vs->pitch * vs->vibrato * seqp->base.chanState[chan].pitchBend);
            evt.type = 23;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = oscState;
            evt.msg.osc.chan = chan;
            func_802B00D4_de(&seqp->base.evtq, &evt, delta);
            break;
        case 2: /* AL_SEQP_MIDI_EVT */
            func_802B0C94_de(&seqp->base, &seqp->base.nextEvent);
            break;
        case 7: /* AL_SEQP_META_EVT */
            func_802B1DEC_de(&seqp->base, &seqp->base.nextEvent);
            break;
        case 15: /* AL_SEQP_PLAY_EVT */
            if (seqp->base.state != 1) {
                seqp->base.state = 1;
                func_802B1D24_de(&seqp->base);
            }
            break;
        case 16: /* AL_SEQP_STOP_EVT */
            if (seqp->base.state == 2) {
                for (vs = seqp->base.vAllocHead; vs != 0; vs = seqp->base.vAllocHead) {
                    func_802B36F0_de(seqp->base.drvr, &vs->voice);
                    func_802B3200_de(seqp->base.drvr, &vs->voice);
                    if (vs->flags)
                        func_802B1C34_de(&seqp->base, vs);
                    func_802B156C_de(&seqp->base, &vs->voice);
                }
                seqp->base.curTime = 0;
                seqp->base.state = 0;
            }
            break;
        case 17: /* AL_SEQP_STOPPING_EVT */
            if (seqp->base.state == 1) {
                func_802B0258_de(&seqp->base.evtq, 0);
                func_802B0258_de(&seqp->base.evtq, 2);
                for (vs = seqp->base.vAllocHead; vs != 0; vs = vs->next) {
                    if ((u8)func_802B15D0_de(&seqp->base, &vs->voice, 50000))
                        func_802B1B14_de(&seqp->base, &vs->voice, 50000);
                }
                seqp->base.state = 2;
                evt.type = 16;
                func_802B00D4_de(&seqp->base.evtq, &evt, 0x7fffffff);
            }
            break;
        case 10: /* AL_SEQP_VOL_EVT */
            seqp->base.vol = seqp->base.nextEvent.msg.spvol.type;
            for (vs = seqp->base.vAllocHead; vs != 0; vs = vs->next) {
                func_802B3480_de(seqp->base.drvr, &vs->voice, func_802B1814_de(vs, &seqp->base),
                              func_802B1888_de(vs, seqp->base.curTime));
            }
            break;
        case 11: /* AL_SEQP_LOOP_EVT */
            seqp->loopStart = ((struct ALSequenceLoopEvent *)&seqp->base.nextEvent.msg)->start;
            seqp->loopEnd = ((struct ALSequenceLoopEvent *)&seqp->base.nextEvent.msg)->end;
            seqp->loopCount = ((struct ALSequenceLoopEvent *)&seqp->base.nextEvent.msg)->count;
            break;
        case 12: /* AL_SEQP_PRIORITY_EVT */
            chan = seqp->base.nextEvent.msg.sppriority.available;
            seqp->base.chanState[chan].priority = seqp->base.nextEvent.msg.sppriority.slot;
            break;
        case 13: /* AL_SEQP_SEQ_EVT */
            if (seqp->base.state == 1)
                func_802BAC50_de(D_800C7440, D_800C7444, 296);
            seqp->base.target = seqp->base.nextEvent.msg.spseq.unk0;
            func_802B1E50_de(&seqp->base, 500000.0f);
            if (seqp->base.bank)
                func_802B18E4_de(&seqp->base, seqp->base.bank);
            break;
        case 14: /* AL_SEQP_BANK_EVT */
            if (seqp->base.state != 0)
                func_802BAC50_de(D_800C7440, D_800C7444, 305);
            seqp->base.bank = seqp->base.nextEvent.msg.spbank.unk0;
            func_802B18E4_de(&seqp->base, seqp->base.bank);
            break;
        case 4: /* AL_SEQ_END_EVT */
        case 3: /* AL_TEMPO_EVT */
        case 1: /* AL_SEQ_MIDI_EVT */
            func_802BAC50_de(D_800C7440, D_800C7444, 315);
            break;
        }
        seqp->base.nextDelta = func_802B003C_de(&seqp->base.evtq, &seqp->base.nextEvent);
    } while (seqp->base.nextDelta == 0);
    seqp->base.curTime += seqp->base.nextDelta;
    return seqp->base.nextDelta;
}
