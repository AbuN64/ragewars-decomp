#include "sdk/OBJECTSTATE2.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJECTSTATE10_2.H"
#include "sdk/libgultra_inferred/802AD870_8.H"
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
#include "COMMON/ALPARAM_S.H"
#include "COMMON/SHAREDPLAYER.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"
#include "include_asm.h"

extern s32 func_802B0340_de(s32, s32, void *, s32, s32);


extern void func_802AFFC0_de(void *, void *, s32);

extern void alSynAddPlayer(s32, void *);


void __CSPHandleMetaMsg(void *arg0, ObjectState10_2 *arg1);

extern void func_802B00D4_de(ALEventQueue *, ALEvent *, s32);

extern s32 alEvtqNextEvent(void *, s16 *);

extern void alEvtqFlushType(void *, s16);

extern void alSynStopVoice(struct Shape_typemap_71 *, void *);

extern void alSynFreeVoice(void *, void *);

extern void func_802B3480_de(void *, void *, s16, s32);

extern void func_802B33E0_de(void *, void *, f32);


extern s16 __vsVol(ALVoiceState *, ALSeqPlayer *);

extern s32 __vsDelta(void *, s32);

extern void __seqpReleaseVoice(void *, void *, s32);

extern void __initFromBank(void *, void *);

void func_802AEAB0_de(void *arg0, InitParams *config) {
    ALSeqPlayer *obj = arg0;
    InitParams *params = config;
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
    __initChanState(obj);

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
ALMicroTime __CSPVoiceHandler(ALSeqPlayer *node)
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
            __CSPHandleNextSeqEvent(seqp);
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
                __seqpStopOsc(seqp, vs);
            Audio_ReleaseSequenceVoice((List802B663C *)seqp, voice);
            break;
        case 6: /* AL_SEQP_ENV_EVT */
            voice = seqp->nextEvent.msg.vol.voice;
            vs = (ALVoiceState *)voice->clientPrivate;
            if (vs->envPhase == 0)
                vs->envPhase = 1;
            delta = seqp->nextEvent.msg.vol.delta;
            vs->envEndTime = seqp->curTime + delta;
            vs->envGain = seqp->nextEvent.msg.vol.vol;
            func_802B3480_de(seqp->drvr, voice, __vsVol((ALVoiceState *)vs, (ALSeqPlayer *)seqp), delta);
            break;
        case 22: /* AL_TREM_OSC_EVT */
            vs = seqp->nextEvent.msg.osc.vs;
            oscState = seqp->nextEvent.msg.osc.oscState;
            delta = (*seqp->updateOsc)(oscState, &oscValue);
            tremeloSlot = &vs->tremelo;
            tremelo = (u32)oscValue;
            *tremeloSlot = tremelo;
            func_802B3480_de(seqp->drvr, &vs->voice, __vsVol((ALVoiceState *)vs, (ALSeqPlayer *)seqp),
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
            __CSPHandleMIDIMsg(seqp, (ALEvent *)&seqp->nextEvent);
            break;
        case 7: /* AL_SEQP_META_EVT */
            __CSPHandleMetaMsg(seqp, (ObjectState10_2 *)&seqp->nextEvent);
            break;
        case 10: /* AL_SEQP_VOL_EVT */
            seqp->vol = seqp->nextEvent.msg.spvol.type;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                func_802B3480_de(seqp->drvr, &vs->voice, __vsVol((ALVoiceState *)vs, (ALSeqPlayer *)seqp),
                              __vsDelta(vs, seqp->curTime));
            }
            break;
        case 15: /* AL_SEQP_PLAY_EVT */
            if (seqp->state != 1) {
                seqp->state = 1;
                __CSPPostNextSeqEvent(seqp);
            }
            break;
        case 16: /* AL_SEQP_STOP_EVT */
            if (seqp->state == 2) {
                for (vs = seqp->vAllocHead; vs != 0; vs = seqp->vAllocHead) {
                    alSynStopVoice(seqp->drvr, &vs->voice);
                    alSynFreeVoice(seqp->drvr, &vs->voice);
                    if (vs->flags)
                        __seqpStopOsc(seqp, vs);
                    Audio_ReleaseSequenceVoice((List802B663C *)seqp, &vs->voice);
                }
                seqp->state = 0;
            }
            break;
        case 17: /* AL_SEQP_STOPPING_EVT */
            if (seqp->state == 1) {
                alEvtqFlushType(&seqp->evtq, 0);
                alEvtqFlushType(&seqp->evtq, 21);
                alEvtqFlushType(&seqp->evtq, 2);
                for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                    if ((u8)__voiceNeedsNoteKill(seqp, (s32)&vs->voice, 50000))
                        __seqpReleaseVoice(seqp, &vs->voice, 50000);
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
                Audio_Assert(D_800C7350_de, g_audioCsplayerText, 295);
            seqp->target = seqp->nextEvent.msg.spseq.unk0;
            __setUsptFromTempo(seqp, 500000.0f);
            if (seqp->bank)
                __initFromBank(seqp, seqp->bank);
            break;
        case 14: /* AL_SEQP_BANK_EVT */
            if (seqp->state != 0)
                Audio_Assert(D_800C7350_de, g_audioCsplayerText, 304);
            seqp->bank = seqp->nextEvent.msg.spbank.unk0;
            __initFromBank(seqp, seqp->bank);
            break;
        case 4: /* AL_SEQ_END_EVT */
        case 3: /* AL_TEMPO_EVT */
        case 1: /* AL_SEQ_MIDI_EVT */
            Audio_Assert(D_800C7350_de, g_audioCsplayerText, 314);
            break;
        }
        seqp->nextDelta = alEvtqNextEvent(&seqp->evtq, (s16 *)&seqp->nextEvent);
    } while (seqp->nextDelta == 0);
    seqp->curTime += seqp->nextDelta;
    return seqp->nextDelta;
}







extern void *func_802B16E0_de(void *, s32, s32, s32);

extern void *__mapVoice(void *, u8, u8, u8);

extern ALVoiceState *__lookupVoice(ALSeqPlayer *, u8, u8);

extern s32 func_802B3000_de(ALSynth_func_802B3000_de *, ALVoice_s *, ALVoiceConfig_s *);

extern s32 __vsPan(void *, void *);



extern void func_802B35E0_de(ALSynth_func_802B3000_de *, ALVoice_s *, void *, f32, s16, u8, u8, s32);



extern void func_802B3350_de(void *, void *, u8);

extern void func_802B32A0_de(void *, void *, u8);


extern void __setInstChanState(void *, void *, s32);

/** Dispatch the current object message and forward any resulting value. */
void __CSPHandleNextSeqEvent(void *rawPlayer) {
    struct ALSeqPlayer *arg0 = rawPlayer;
    ALEvent message;
    ALEvent output;
    s32 value1;
    s32 value2;
    s32 value3;
    ALCSeq_s *sequence;
    s32 value;
    sequence = arg0->target;
    if (sequence != 0) {
        func_802AE6BC_de(sequence, &message);
        {
        s32 sw_message_value = (s16)((u16)message.type - 1);
        if ((unsigned int)sw_message_value > 19) {
            goto sw_message_default;
        }
        switch (sw_message_value) {
        case 0: goto sw_message_0;
        case 1: goto sw_message_default;
        case 2: goto sw_message_2;
        case 3: goto sw_message_3;
        case 4: goto sw_message_default;
        case 5: goto sw_message_default;
        case 6: goto sw_message_default;
        case 7: goto sw_message_default;
        case 8: goto sw_message_default;
        case 9: goto sw_message_default;
        case 10: goto sw_message_default;
        case 11: goto sw_message_default;
        case 12: goto sw_message_default;
        case 13: goto sw_message_default;
        case 14: goto sw_message_default;
        case 15: goto sw_message_default;
        case 16: goto sw_message_default;
        case 17: goto sw_message_17;
        case 18: goto sw_message_17;
        case 19: goto sw_message_17;
        }
    }
    do {
        sw_message_0:
            __CSPHandleMIDIMsg(arg0, &message);
            if (arg0->state == 1) {
                sequence = arg0->target;
                if (sequence != 0 && (__alCSeqNextDelta(sequence, &value1) & 0xFF)) {
                    output.type = 0;
                    value = value1;
                    goto send_value;
                }
            }
            break;
        sw_message_2:
            __CSPHandleMetaMsg(arg0, &message);
            if (arg0->state == 1) {
                sequence = arg0->target;
                if (sequence != 0 && (__alCSeqNextDelta(sequence, &value2) & 0xFF)) {
                    output.type = 0;
                    value = value2;
                    goto send_value;
                }
            }
            break;
        sw_message_3:
            arg0->state = 2;
            message.type = 0x10;
            func_802B00D4_de(&arg0->evtq, &message, 0x7FFFFFFF);
            break;
        sw_message_17:
        sw_message_18:
        sw_message_19:
            if (arg0->state == 1) {
                sequence = arg0->target;
                if (sequence != 0 && (__alCSeqNextDelta(sequence, &value3) & 0xFF)) {
                    output.type = 0;
                    value = value3;
send_value:
                    func_802B00D4_de(&arg0->evtq, &output,
                                  value * arg0->uspt);
                }
            }
            break;
        sw_message_default:
            Audio_Assert(D_800C7350_de, g_audioCsplayerText, 0x190);
            break;
        
    } while (0);
    }
}

/* Apply one compact-sequence MIDI message. The existing event storage and
 * callee-specific voice/player views share their measured O32 prefixes. */
void __CSPHandleMIDIMsg(void *object, ALEvent *message)
{
    ALSeqPlayer *seqp = object;
    ALEvent *event = (ALEvent *)message;
    ALVoice_s *voice;
    ALVoiceState *vs;
    s32 status;
    u8 chan;
    u8 key;
    u8 vel;
    u8 byte1;
    u8 byte2;
    ALMIDIEvent *midi = &event->msg.midi;
    s16 vol;
    ALEvent evt;
    ALMicroTime deltaTime;
    ALVoiceState *vstate;
    u8 pan;

    status = event->msg.midi.status & 0xF0;
    chan = event->msg.midi.status & 0x0F;
    byte1 = key = event->msg.midi.byte1;
    byte2 = vel = event->msg.midi.byte2;

    switch (status) {
    case 0x90: /* AL_MIDI_NoteOn */
        if (vel != 0) {
            ALVoiceConfig_s config;
            ALSound_s *sound;
            s16 cents;
            f32 pitch, oscValue, initialOscValue;
            u8 fxmix;
            void *oscState;
            ALInstrument *inst;
            s32 tremelo;
            u8 *tremeloSlot;

            if (seqp->state != 1)
                break;
            sound = func_802B16E0_de(seqp, key, vel, chan);
            if (!sound)
                return;
            config.priority = seqp->chanState[chan].priority;
            config.fxBus = 0;
            config.unityPitch = 0;
            vstate = __mapVoice(seqp, key, vel, chan);
            if (!vstate)
                return;
            voice = &vstate->voice;
            func_802B3000_de(seqp->drvr, (ALVoice_s *)voice, &config);
            vstate->sound = sound;
            vstate->envPhase = 0;
            if (seqp->chanState[chan].sustain > 63)
                vstate->phase = 2;
            else
                vstate->phase = 0;
            cents = (key - sound->keyMap->keyBase) * 100 + sound->keyMap->detune;
            vstate->pitch = func_802AFE30_de(cents);
            initialOscValue = D_800C7420_de;
            vstate->envGain = sound->envelope->attackVolume;
            vstate->envEndTime = seqp->curTime + sound->envelope->attackTime;
            vstate->flags = 0;
            inst = seqp->chanState[chan].instrument;
            oscValue = initialOscValue;
            if (inst->tremType) {
                if (seqp->initOsc) {
                    deltaTime = (*seqp->initOsc)(&oscState, &oscValue, inst->tremType,
                                                 inst->tremRate, inst->tremDepth, inst->tremDelay);
                    if (deltaTime) {
                        evt.type = 22; /* AL_TREM_OSC_EVT */
                        evt.msg.osc.vs = vstate;
                        evt.msg.osc.oscState = oscState;
                        func_802B00D4_de(&seqp->evtq, (ALEvent *)&evt, deltaTime);
                        vstate->flags |= 0x01;
                    }
                }
            }
            tremeloSlot = &vstate->tremelo;
            if (!(oscValue >= D_800C7424_de)) {
                tremelo = (s32)oscValue;
            } else {
                tremelo = (s32)(oscValue - D_800C7424_de);
                tremelo |= 0x80000000;
            }
            initialOscValue = D_800C7428_de;
            *tremeloSlot = tremelo;
            oscValue = initialOscValue;
            if (inst->vibType) {
                if (seqp->initOsc) {
                    deltaTime = (*seqp->initOsc)(&oscState, &oscValue, inst->vibType,
                                                 inst->vibRate, inst->vibDepth, inst->vibDelay);
                    if (deltaTime) {
                        evt.type = 23; /* AL_VIB_OSC_EVT */
                        evt.msg.osc.vs = vstate;
                        evt.msg.osc.oscState = oscState;
                        evt.msg.osc.chan = chan;
                        func_802B00D4_de(&seqp->evtq, (ALEvent *)&evt, deltaTime);
                        vstate->flags |= 0x02;
                    }
                }
            }
            vstate->vibrato = oscValue;
            pitch = vstate->pitch * seqp->chanState[chan].pitchBend * vstate->vibrato;
            fxmix = seqp->chanState[chan].fxmix;
            pan = __vsPan(vstate, seqp);
            vol = __vsVol((ALVoiceState *)vstate, (ALSeqPlayer *)seqp);
            deltaTime = sound->envelope->attackTime;
            func_802B35E0_de(seqp->drvr, (ALVoice_s *)voice, sound->wavetable, pitch, vol, pan, fxmix, deltaTime);
            evt.type = 6; /* AL_SEQP_ENV_EVT */
            evt.msg.vol.voice = voice;
            evt.msg.vol.vol = sound->envelope->decayVolume;
            evt.msg.vol.delta = sound->envelope->decayTime;
            func_802B00D4_de(&seqp->evtq, (ALEvent *)&evt, deltaTime);
            if (midi->duration) {
                evt.type = 21; /* AL_CSP_NOTEOFF_EVT */
                evt.msg.midi.status = chan | 0x80;
                evt.msg.midi.byte1 = key;
                evt.msg.midi.byte2 = 0;
                deltaTime = seqp->uspt * midi->duration;
                func_802B00D4_de(&seqp->evtq, (ALEvent *)&evt, deltaTime);
            }
            break;
        }
    case 0x80: /* AL_MIDI_NoteOff */
        vstate = (ALVoiceState *)__lookupVoice((ALSeqPlayer *)seqp, key, chan);
        if (!vstate)
            return;
        if (vstate->phase == 2)
            vstate->phase = 4;
        else {
            vstate->phase = 3;
            __seqpReleaseVoice(seqp, &vstate->voice, vstate->sound->envelope->releaseTime);
        }
        break;
    case 0xA0: /* AL_MIDI_PolyKeyPressure */
        vstate = (ALVoiceState *)__lookupVoice((ALSeqPlayer *)seqp, key, chan);
        if (!vstate)
            return;
        vstate->velocity = byte2;
        func_802B3480_de(seqp->drvr, &vstate->voice, __vsVol((ALVoiceState *)vstate, (ALSeqPlayer *)seqp),
                      __vsDelta(vstate, seqp->curTime));
        break;
    case 0xD0: /* AL_MIDI_ChannelPressure */
        for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
            if (vs->channel == chan) {
                vs->velocity = byte1;
                func_802B3480_de(seqp->drvr, &vs->voice, __vsVol((ALVoiceState *)vs, (ALSeqPlayer *)seqp),
                              __vsDelta(vs, seqp->curTime));
            }
        }
        break;
    case 0xB0: /* AL_MIDI_ControlChange */
        switch (byte1) {
        case 0x0A: /* AL_MIDI_PAN_CTRL */
            seqp->chanState[chan].pan = byte2;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan) {
                    pan = __vsPan(vs, seqp);
                    func_802B3350_de(seqp->drvr, &vs->voice, pan);
                }
            }
            break;
        case 0x07: /* AL_MIDI_VOLUME_CTRL */
            seqp->chanState[chan].vol = byte2;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if ((vs->channel == chan) && (vs->envPhase != 3)) {
                    vol = __vsVol((ALVoiceState *)vs, (ALSeqPlayer *)seqp);
                    func_802B3480_de(seqp->drvr, &vs->voice, vol, __vsDelta(vs, seqp->curTime));
                }
            }
            break;
        case 0x10: /* AL_MIDI_PRIORITY_CTRL */
            seqp->chanState[chan].priority = byte2;
            break;
        case 0x40: /* AL_MIDI_SUSTAIN_CTRL */
            seqp->chanState[chan].sustain = byte2;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if ((vs->channel == chan) && (vs->phase != 3)) {
                    if (byte2 > 63) {
                        if (vs->phase == 0)
                            vs->phase = 2;
                    } else {
                        if (vs->phase == 2)
                            vs->phase = 0;
                        else if (vs->phase == 4) {
                            vs->phase = 3;
                            __seqpReleaseVoice(seqp, &vs->voice, vs->sound->envelope->releaseTime);
                        }
                    }
                }
            }
            break;
        case 0x5B: /* AL_MIDI_FX1_CTRL */
            seqp->chanState[chan].fxmix = byte2;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if (vs->channel == chan)
                    func_802B32A0_de(seqp->drvr, &vs->voice, byte2);
            }
            break;
        default:
            break;
        }
        break;
    case 0xC0: /* AL_MIDI_ProgramChange */
        if (seqp->bank == 0)
            Audio_Assert(D_800C7350_de, g_audioCsplayerText, 711);
        if (key < seqp->bank->instCount) {
            ALInstrument *inst = seqp->bank->instArray[key];
            __setInstChanState(seqp, inst, chan);
        }
        break;
    case 0xE0: /* AL_MIDI_PitchBendChange */
        {
            s32 bendVal;
            f32 bendRatio;
            s32 cents;

            bendVal = ((byte2 << 7) + byte1) - 8192;
            cents = (seqp->chanState[chan].bendRange * bendVal) / 8192;
            bendRatio = func_802AFE30_de(cents);
            seqp->chanState[chan].pitchBend = bendRatio;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
                if (vs->channel == chan)
                    func_802B33E0_de(seqp->drvr, &vs->voice, vs->pitch * bendRatio * vs->vibrato);
        }
        break;
    default:
        break;
    }
}

void __CSPRepostEvent(void *arg0, Node_func_802AFD6C_de *arg1);



extern s32 func_802BD170_de(s32);

void __CSPHandleMetaMsg(void *arg0, ObjectState10_2 *arg1) {
    s32 padding[4];
    s32 total = 0;
    Node_func_802AFD6C_de *head = 0;
    s32 scale;
    Node_func_802AFD6C_de *node;
    Node_func_802AFD6C_de *next;
    if (arg1->unk_8 == 0xFF) {
        if (arg1->unk_9 != 0x51) {
            return;
        }
        scale = ((ObjectState4C *)(arg0))->unk_24;
        __setUsptFromTempo(arg0,
                      (f32)((arg1->unk_B << 16) | (arg1->unk_C << 8) | arg1->unk_D));
        node = ((struct ObjectLinks54_2 *) ((char *) arg0))->link;
        while (node != 0) {
            next = ((struct ObjectLinks4_5 *) ((char *) node))->link;
            total += node->value;
            if (node->type == 0x15) {
                s32 node_total;
                alUnlink((ListLink *)node);
                if (head != 0) {
                    alLink(node, head);
                } else {
                    head = node;
                    node->prev = 0;
                    node->next = 0;
                }
                node_total = total;
                if (next != 0) {
                    total -= node->value;
                    next->value += node->value;
                }
                node->value = node_total;
            }
            node = next;
        }
        node = head;
        while (node != 0) {
            next = node->prev;
            node->value = (node->value / scale) * ((ObjectState4C *)(arg0))->unk_24;
            __CSPRepostEvent(&((ObjectState4C *)(arg0))->unk_48, node);
            node = next;
        }
    }
}

void __CSPPostNextSeqEvent(void *arg0) {
    struct ALSeqPlayer *player = arg0;
    ALEvent sp10;
    s32 sp20;
    ALCSeq_s *sequence;

    if (player->state == 1) {
        sequence = player->target;
        if (sequence != 0 && (__alCSeqNextDelta(sequence, &sp20) & 0xFF)) {
            sp10.type = 0;
            func_802B00D4_de(&player->evtq, &sp10, sp20 * player->uspt);
        }
    }
}

void __CSPRepostEvent(void *arg0, Node_func_802AFD6C_de *arg1) {
    ObjRecAt8V3 *object = arg0;
    s32 saved;
    Node_func_802AFD6C_de **link;
    Node_func_802AFD6C_de *node;
    s32 value;
    s32 node_value;

    saved = func_802BD170_de(1);
    link = &object->unk8;
    if (link != 0) {
loop:
        node = *link;
        if (node == 0) {
            goto insert;
        }
        value = arg1->value;
        node_value = node->value;
        if (value < node_value) {
            node->value = node_value - value;
insert:
            alLink(arg1, link);
            goto done;
        }
        arg1->value = value - node_value;
        link = (Node_func_802AFD6C_de **)*link;
        if (link != 0) {
            goto loop;
        }
    }
done:
    func_802BD170_de(saved);
}

void __setUsptFromTempo(void *arg0, f32 arg1) {
    ALSeqPlayer *player = arg0;
    ALCSeq_s *temp_v0;

    temp_v0 = player->target;
    if (temp_v0 != 0) {
        player->uspt = (s32)(arg1 * temp_v0->qnpt);
        return;
    }
    player->uspt = 0x1E8;
}

#if !(defined(VERSION_US_REV1))
const unsigned int D_802AF2E0_CD270[3] = {
    0x42FE0000, 0x4F000000, 0x3F800000,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800C734C[1] = {
    0x6174615F,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C89EC[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C801C[1] = {
    0x4275C28F,
};
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_800C742C[1] = {
    0xAFB60030,
};
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_802AF2E0_CD270_us_rev1.c */
const unsigned int D_blob_868e5463195d5f476023[3] = {
    0x42FE0000, 0x4F000000, 0x3F800000,
};
#endif
