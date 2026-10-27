#include "COMMON/TRIPLE.H"
#include "COMMON/LONE/D_800C7444.H"
#include "COMMON/LONE/D_800C7440.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT18V1.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/seqplayer.h"
#include "sdk/libgultra/part_800C7F20/seqplayer_802B6BE4.h"
#include "AUDIO_3/802BFD40.H"

#include "COMMON/ALSEQUENCEPLAYER.H"


 /* 2147483648.0f */

extern void Audio_AdvanceSequenceEvent(ALSeqPlayer *);                        /* __handleNextSeqEvent */
extern void func_802B1E50_de(ALSeqPlayer *, f32);                   /* __setUsptFromTempo */
extern ALMicroTime alEvtqNextEvent(ALEventQueue *, ALEvent *);    /* alEvtqNextEvent */
extern void alEvtqFlushType(ALEventQueue *, s16);                 /* alEvtqFlushType */
extern void alSynStopVoice(struct Shape_typemap_71 *, ALVoice_s *);                   /* alSynStopVoice */
extern void alSynFreeVoice(void *, ALVoice_s *);                   /* alSynFreeVoice */
extern void func_802B3480_de(void *, ALVoice_s *, s16, ALMicroTime); /* alSynSetVol */
extern void alSynSetPitch(void *, ALVoice_s *, f32);              /* alSynSetPitch */
extern s16 __vsVol(ALVoiceState *, ALSeqPlayer *);        /* __vsVol */
extern ALMicroTime __vsDelta(ALVoiceState *, ALMicroTime);  /* __vsDelta */
extern void __seqpReleaseVoice(ALSeqPlayer *, ALVoice_s *, ALMicroTime); /* __seqpReleaseVoice */
extern void __initFromBank(ALSeqPlayer *, void *);               /* __initFromBank */
                 /* __assert */

ALMicroTime Audio_ProcessSequenceEvents(void *node)
{
    struct ALSequencePlayer *seqp = node;
    ALEvent evt;
    ALVoice_s *voice;
    ALMicroTime delta;
    ALVoiceState *vs;
    void *oscState;
    f32 oscValue;
    u8 chan;
    u32 tremelo;
    u8 *tremeloSlot;

    do {
        switch (seqp->base.nextEvent.type) {
        case 0: /* AL_SEQ_REF_EVT */
            Audio_AdvanceSequenceEvent(&seqp->base);
            break;
        case 9: /* AL_SEQP_API_EVT */
            evt.type = 9;
            func_802B00D4_de(&seqp->base.evtq, (ALEvent *)&evt, seqp->base.frameTime);
            break;
        case 5: /* AL_NOTE_END_EVT */
            voice = seqp->base.nextEvent.msg.note.voice;
            alSynStopVoice(seqp->base.drvr, voice);
            alSynFreeVoice(seqp->base.drvr, voice);
            vs = (ALVoiceState *)voice->clientPrivate;
            if (vs->flags)
                __seqpStopOsc(&seqp->base, vs);
            Audio_ReleaseSequenceVoice(&seqp->base, voice);
            break;
        case 6: /* AL_SEQP_ENV_EVT */
            voice = seqp->base.nextEvent.msg.vol.voice;
            vs = (ALVoiceState *)voice->clientPrivate;
            if (vs->envPhase == 0)
                vs->envPhase = 1;
            delta = seqp->base.nextEvent.msg.vol.delta;
            vs->envGain = seqp->base.nextEvent.msg.vol.vol;
            vs->envEndTime = seqp->base.curTime + delta;
            func_802B3480_de(seqp->base.drvr, voice, __vsVol(vs, &seqp->base), delta);
            break;
        case 22: /* AL_TREM_OSC_EVT */
            vs = seqp->base.nextEvent.msg.osc.vs;
            oscState = seqp->base.nextEvent.msg.osc.oscState;
            delta = (*seqp->base.updateOsc)(oscState, &oscValue);
            tremeloSlot = &vs->tremelo;
            tremelo = (u32)oscValue;
            *tremeloSlot = tremelo;
            func_802B3480_de(seqp->base.drvr, &vs->voice, __vsVol(vs, &seqp->base),
                          __vsDelta(vs, seqp->base.curTime));
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
            alSynSetPitch(seqp->base.drvr, &vs->voice,
                          vs->pitch * vs->vibrato * seqp->base.chanState[chan].pitchBend);
            evt.type = 23;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = oscState;
            evt.msg.osc.chan = chan;
            func_802B00D4_de(&seqp->base.evtq, &evt, delta);
            break;
        case 2: /* AL_SEQP_MIDI_EVT */
            Audio_HandleSequenceMidiEvent(&seqp->base, &seqp->base.nextEvent);
            break;
        case 7: /* AL_SEQP_META_EVT */
            __handleMetaMsg(&seqp->base, &seqp->base.nextEvent);
            break;
        case 15: /* AL_SEQP_PLAY_EVT */
            if (seqp->base.state != 1) {
                seqp->base.state = 1;
                __postNextSeqEvent(&seqp->base);
            }
            break;
        case 16: /* AL_SEQP_STOP_EVT */
            if (seqp->base.state == 2) {
                for (vs = seqp->base.vAllocHead; vs != 0; vs = seqp->base.vAllocHead) {
                    alSynStopVoice(seqp->base.drvr, &vs->voice);
                    alSynFreeVoice(seqp->base.drvr, &vs->voice);
                    if (vs->flags)
                        __seqpStopOsc(&seqp->base, vs);
                    Audio_ReleaseSequenceVoice(&seqp->base, &vs->voice);
                }
                seqp->base.curTime = 0;
                seqp->base.state = 0;
            }
            break;
        case 17: /* AL_SEQP_STOPPING_EVT */
            if (seqp->base.state == 1) {
                alEvtqFlushType(&seqp->base.evtq, 0);
                alEvtqFlushType(&seqp->base.evtq, 2);
                for (vs = seqp->base.vAllocHead; vs != 0; vs = vs->next) {
                    if ((u8)__voiceNeedsNoteKill(&seqp->base, &vs->voice, 50000))
                        __seqpReleaseVoice(&seqp->base, &vs->voice, 50000);
                }
                seqp->base.state = 2;
                evt.type = 16;
                func_802B00D4_de(&seqp->base.evtq, &evt, 0x7fffffff);
            }
            break;
        case 10: /* AL_SEQP_VOL_EVT */
            seqp->base.vol = seqp->base.nextEvent.msg.spvol.type;
            for (vs = seqp->base.vAllocHead; vs != 0; vs = vs->next) {
                func_802B3480_de(seqp->base.drvr, &vs->voice, __vsVol(vs, &seqp->base),
                              __vsDelta(vs, seqp->base.curTime));
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
                Audio_Assert(D_800C7440, g_audioSeqplayerText, 296);
            seqp->base.target = seqp->base.nextEvent.msg.spseq.unk0;
            func_802B1E50_de(&seqp->base, 500000.0f);
            if (seqp->base.bank)
                __initFromBank(&seqp->base, seqp->base.bank);
            break;
        case 14: /* AL_SEQP_BANK_EVT */
            if (seqp->base.state != 0)
                Audio_Assert(D_800C7440, g_audioSeqplayerText, 305);
            seqp->base.bank = seqp->base.nextEvent.msg.spbank.unk0;
            __initFromBank(&seqp->base, seqp->base.bank);
            break;
        case 4: /* AL_SEQ_END_EVT */
        case 3: /* AL_TEMPO_EVT */
        case 1: /* AL_SEQ_MIDI_EVT */
            Audio_Assert(D_800C7440, g_audioSeqplayerText, 315);
            break;
        }
        seqp->base.nextDelta = alEvtqNextEvent(&seqp->base.evtq, &seqp->base.nextEvent);
    } while (seqp->base.nextDelta == 0);
    seqp->base.curTime += seqp->base.nextDelta;
    return seqp->base.nextDelta;
}
