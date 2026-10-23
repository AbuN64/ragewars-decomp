#include "sdk/OBJECTSTATE2.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJECTSTATE10_2.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/BUF16B.H"
#include "sdk/libgultra/part_800C7F20/code_802B66A0_3.h"
#include "sdk/libgultra/part_800C7F20/seqplayer.h"
#include "sdk/libgultra_inferred/802B3B80_4.H"
#include "AUDIO_3/802BFD40.H"
#include "sdk/al_globals.h"



extern s32 func_802B0340_de(s32, s32, void *, s32, s32);


extern void func_802AFFC0_de(void *, void *, s32);

extern void alSynAddPlayer(s32, void *);


extern void func_802AFB6C_de(void *, ObjectState10_2 *);

extern void func_802B00D4_de(ALEventQueue *, ALEvent *, s32);

extern s32 func_802B003C_de(void *, s16 *);

extern void func_802B0258_de(void *, s16);

extern void alSynStopVoice(struct Shape_typemap_71 *, void *);

extern void alSynFreeVoice(void *, void *);

extern void func_802B3480_de(void *, void *, s16, s32);

extern void func_802B33E0_de(void *, void *, f32);


extern s16 func_802B1814_de(ALVoiceState *, ALSeqPlayer *);

extern s32 __vsDelta(void *, s32);

extern void func_802B1B14_de(void *, void *, s32);

extern void func_802B18E4_de(void *, void *);

void func_802AEAB0_de(void *arg0, InitParams *arg1) {
    ALSeqPlayer *obj = arg0;
    InitParams *params = arg1;
    s32 context = params->context;
    s32 global = (s32)D_800D4070;
    s32 allocation;
    s32 i;

    obj->chanMask = 0xFF;
    obj->uspt = 0x1E8;
    obj->vol = 0x7FFF;
    obj->bank = 0;
    obj->target = 0;
    obj->nextDelta = 0;
    obj->state = 0;
    obj->frameTime = 0x3E80;
    obj->curTime = 0;
    obj->drvr = global;
    obj->initOsc = params->value10;
    obj->updateOsc = params->value14;
    obj->stopOsc = params->value18;
    obj->nextEvent.type = 9;
    obj->maxChannels = params->kind;
    obj->chanState = func_802B0340_de(0, 0, (void *)context, params->kind, 0x10);
    func_802B1990_de(obj);

    allocation = func_802B0340_de(0, 0, (void *)context, params->count38, 0x38);
    obj->vFreeList = 0;
    i = 0;
    if (params->count38 > 0) {
        {
            ALVoiceState *records = (ALVoiceState *)allocation;
            do {
                records->next = obj->vFreeList;
                obj->vFreeList = records;
                i++;
                records++;
            } while (i < params->count38);
        }
    }

    obj->vAllocHead = 0;
    obj->vAllocTail = 0;
    allocation = func_802B0340_de(0, 0, (void *)context, params->count1C, 0x1C);
    func_802AFFC0_de(&obj->evtq, (void *)allocation, params->count1C);
    {
        ALPlayer_s *node = &obj->node;
        node->next = 0;
        node->handler = &D_002AEC20;
        node->clientData = node;
        alSynAddPlayer(D_800D4070, node);
    }
}

/* Drain due compact-sequence events and advance to the next event time.
 * Event-kind10 reads the shared short carrier; kind12 uses its two byte
 * carriers for channel and priority. Existing message/voice views are reused. */
ALMicroTime func_802AEC20_de(ALSeqPlayer *node)
{
    ALSeqPlayer *seqp = node;
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
        switch (seqp->nextEvent.type) {
        case 0: /* AL_SEQ_REF_EVT */
            func_802AF150_de(seqp);
            break;
        case 9: /* AL_SEQP_API_EVT */
            evt.type = 9;
            func_802B00D4_de(&seqp->evtq, (ALEvent *)&evt, seqp->frameTime);
            break;
        case 5: /* AL_NOTE_END_EVT */
            voice = seqp->nextEvent.msg.note.voice;
            alSynStopVoice(seqp->drvr, voice);
            alSynFreeVoice(seqp->drvr, voice);
            vs = (ALVoiceState *)voice->clientPrivate;
            if (vs->flags)
                func_802B1C34_de(seqp, vs);
            func_802B156C_de((List802B663C *)seqp, voice);
            break;
        case 6: /* AL_SEQP_ENV_EVT */
            voice = seqp->nextEvent.msg.vol.voice;
            vs = (ALVoiceState *)voice->clientPrivate;
            if (vs->envPhase == 0)
                vs->envPhase = 1;
            delta = seqp->nextEvent.msg.vol.delta;
            vs->envEndTime = seqp->curTime + delta;
            vs->envGain = seqp->nextEvent.msg.vol.vol;
            func_802B3480_de(seqp->drvr, voice, func_802B1814_de((ALVoiceState *)vs, (ALSeqPlayer *)seqp), delta);
            break;
        case 22: /* AL_TREM_OSC_EVT */
            vs = seqp->nextEvent.msg.osc.vs;
            oscState = seqp->nextEvent.msg.osc.oscState;
            delta = (*seqp->updateOsc)(oscState, &oscValue);
            tremeloSlot = &vs->tremelo;
            tremelo = (u32)oscValue;
            *tremeloSlot = tremelo;
            func_802B3480_de(seqp->drvr, &vs->voice, func_802B1814_de((ALVoiceState *)vs, (ALSeqPlayer *)seqp),
                          __vsDelta(vs, seqp->curTime));
            evt.type = 22;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = oscState;
            func_802B00D4_de(&seqp->evtq, (ALEvent *)&evt, delta);
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
            func_802B00D4_de(&seqp->evtq, (ALEvent *)&evt, delta);
            break;
        case 2:  /* AL_SEQP_MIDI_EVT */
        case 21: /* AL_CSP_NOTEOFF_EVT */
            func_802AF2E0_de(seqp, (ALEvent *)&seqp->nextEvent);
            break;
        case 7: /* AL_SEQP_META_EVT */
            func_802AFB6C_de(seqp, (ObjectState10_2 *)&seqp->nextEvent);
            break;
        case 10: /* AL_SEQP_VOL_EVT */
            seqp->vol = seqp->nextEvent.msg.spvol.type;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                func_802B3480_de(seqp->drvr, &vs->voice, func_802B1814_de((ALVoiceState *)vs, (ALSeqPlayer *)seqp),
                              __vsDelta(vs, seqp->curTime));
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
                    alSynStopVoice(seqp->drvr, &vs->voice);
                    alSynFreeVoice(seqp->drvr, &vs->voice);
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
                func_802B00D4_de(&seqp->evtq, (ALEvent *)&evt, 0x7fffffff);
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
            __setUsptFromTempo(seqp, 500000.0f);
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
