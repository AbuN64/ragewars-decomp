#include "common/unused.h"
#include "span_C76B0/data.h"
#include "span_1000/code_802B0388.h"
#include "span_1000/code_802AE028.h"
#include "types.h"


extern void func_802AF2E0_de(void *, Message_func_802AF150_de *);
extern void func_802AFB6C_de(void *, ObjectState10_2 *);


extern void func_802B00D4_de(ALEventQueue *, Message_func_802AF150_de *, s32);
extern s32 func_802B003C_de(void *, s16 *);
extern void func_802B0258_de(void *, s16);
extern void func_802B36F0_de(void *, void *);
extern void func_802B3200_de(void *, void *);
extern void func_802B3480_de(void *, void *, s16, s32);
extern void func_802B33E0_de(void *, void *, f32);

extern void func_802B156C_de(List802B663C *, void *);
extern s16 func_802B1814_de(ALVoiceState_s_func_802B1814_de *, ALSeqPlayer_func_802B1814_de *);
extern s32 func_802B1888_de(void *, s32);

extern void func_802B1B14_de(void *, void *, s32);
extern void func_802B18E4_de(void *, void *);
extern void func_802BAC50_de(void *, void *, s32);

/* Drain due compact-sequence events and advance to the next event time.
 * Event-kind10 reads the shared short carrier; kind12 uses its two byte
 * carriers for channel and priority. Existing message/voice views are reused. */
ALMicroTime func_802AEC20_de(void *node)
{
    ALSeqPlayer_func_802B0C94_de *seqp = (ALSeqPlayer_func_802B0C94_de *)node;
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
        switch (seqp->nextEvent.type) {
        case 0: /* AL_SEQ_REF_EVT */
            func_802AF150_de(seqp);
            break;
        case 9: /* AL_SEQP_API_EVT */
            evt.type = 9;
            func_802B00D4_de(&seqp->evtq, (Message_func_802AF150_de *)&evt, seqp->frameTime);
            break;
        case 5: /* AL_NOTE_END_EVT */
            voice = seqp->nextEvent.msg.note.voice;
            func_802B36F0_de(seqp->drvr, voice);
            func_802B3200_de(seqp->drvr, voice);
            vs = (ALVoiceState_s38 *)voice->clientPrivate;
            if (vs->flags)
                func_802B1C34_de(seqp, vs);
            func_802B156C_de((List802B663C *)seqp, voice);
            break;
        case 6: /* AL_SEQP_ENV_EVT */
            voice = seqp->nextEvent.msg.vol.voice;
            vs = (ALVoiceState_s38 *)voice->clientPrivate;
            if (vs->envPhase == 0)
                vs->envPhase = 1;
            delta = seqp->nextEvent.msg.vol.delta;
            vs->envEndTime = seqp->curTime + delta;
            vs->envGain = seqp->nextEvent.msg.vol.vol;
            func_802B3480_de(seqp->drvr, voice, func_802B1814_de((ALVoiceState_s_func_802B1814_de *)vs, (ALSeqPlayer_func_802B1814_de *)seqp), delta);
            break;
        case 22: /* AL_TREM_OSC_EVT */
            vs = seqp->nextEvent.msg.osc.vs;
            oscState = seqp->nextEvent.msg.osc.oscState;
            delta = (*seqp->updateOsc)(oscState, &oscValue);
            tremeloSlot = &vs->tremelo;
            tremelo = (u32)oscValue;
            *tremeloSlot = tremelo;
            func_802B3480_de(seqp->drvr, &vs->voice, func_802B1814_de((ALVoiceState_s_func_802B1814_de *)vs, (ALSeqPlayer_func_802B1814_de *)seqp),
                          func_802B1888_de(vs, seqp->curTime));
            evt.type = 22;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = oscState;
            func_802B00D4_de(&seqp->evtq, (Message_func_802AF150_de *)&evt, delta);
            break;
        case 23: /* AL_VIB_OSC_EVT */
            vs = seqp->nextEvent.msg.osc.vs;
            oscState = seqp->nextEvent.msg.osc.oscState;
            chan = seqp->nextEvent.msg.osc.chan;
            delta = (*seqp->updateOsc)(oscState, &oscValue);
            vs->vibrato = oscValue;
            func_802B33E0_de(seqp->drvr, &vs->voice,
                          vs->pitch * vs->vibrato * seqp->chanState[chan].pitchBend);
            evt.type = 23;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = oscState;
            evt.msg.osc.chan = chan;
            func_802B00D4_de(&seqp->evtq, (Message_func_802AF150_de *)&evt, delta);
            break;
        case 2:  /* AL_SEQP_MIDI_EVT */
        case 21: /* AL_CSP_NOTEOFF_EVT */
            func_802AF2E0_de(seqp, (Message_func_802AF150_de *)&seqp->nextEvent);
            break;
        case 7: /* AL_SEQP_META_EVT */
            func_802AFB6C_de(seqp, (ObjectState10_2 *)&seqp->nextEvent);
            break;
        case 10: /* AL_SEQP_VOL_EVT */
            seqp->vol = seqp->nextEvent.msg.spvol.type;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                func_802B3480_de(seqp->drvr, &vs->voice, func_802B1814_de((ALVoiceState_s_func_802B1814_de *)vs, (ALSeqPlayer_func_802B1814_de *)seqp),
                              func_802B1888_de(vs, seqp->curTime));
            }
            break;
        case 15: /* AL_SEQP_PLAY_EVT */
            if (seqp->state != 1) {
                seqp->state = 1;
                func_802AFD00_de(seqp);
            }
            break;
        case 16: /* AL_SEQP_STOP_EVT */
            if (seqp->state == 2) {
                for (vs = seqp->vAllocHead; vs != 0; vs = seqp->vAllocHead) {
                    func_802B36F0_de(seqp->drvr, &vs->voice);
                    func_802B3200_de(seqp->drvr, &vs->voice);
                    if (vs->flags)
                        func_802B1C34_de(seqp, vs);
                    func_802B156C_de((List802B663C *)seqp, &vs->voice);
                }
                seqp->state = 0;
            }
            break;
        case 17: /* AL_SEQP_STOPPING_EVT */
            if (seqp->state == 1) {
                func_802B0258_de(&seqp->evtq, 0);
                func_802B0258_de(&seqp->evtq, 21);
                func_802B0258_de(&seqp->evtq, 2);
                for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                    if ((u8)func_802B15D0_de(seqp, (s32)&vs->voice, 50000))
                        func_802B1B14_de(seqp, &vs->voice, 50000);
                }
                seqp->state = 2;
                evt.type = 16;
                func_802B00D4_de(&seqp->evtq, (Message_func_802AF150_de *)&evt, 0x7fffffff);
            }
            break;
        case 12: /* AL_SEQP_PRIORITY_EVT */
            chan = seqp->nextEvent.msg.sppriority.available;
            seqp->chanState[chan].priority = seqp->nextEvent.msg.sppriority.slot;
            break;
        case 13: /* AL_SEQP_SEQ_EVT */
            if (seqp->state == 1)
                func_802BAC50_de(D_800C7350_de, D_800C7354_de, 295);
            seqp->target = seqp->nextEvent.msg.spseq.unk0;
            func_802AFDFC_de(seqp, 500000.0f);
            if (seqp->bank)
                func_802B18E4_de(seqp, seqp->bank);
            break;
        case 14: /* AL_SEQP_BANK_EVT */
            if (seqp->state != 0)
                func_802BAC50_de(D_800C7350_de, D_800C7354_de, 304);
            seqp->bank = seqp->nextEvent.msg.spbank.unk0;
            func_802B18E4_de(seqp, seqp->bank);
            break;
        case 4: /* AL_SEQ_END_EVT */
        case 3: /* AL_TEMPO_EVT */
        case 1: /* AL_SEQ_MIDI_EVT */
            func_802BAC50_de(D_800C7350_de, D_800C7354_de, 314);
            break;
        }
        seqp->nextDelta = func_802B003C_de(&seqp->evtq, (s16 *)&seqp->nextEvent);
    } while (seqp->nextDelta == 0);
    seqp->curTime += seqp->nextDelta;
    return seqp->nextDelta;
}
