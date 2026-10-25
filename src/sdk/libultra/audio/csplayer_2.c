#include "sdk/OBJECTSTATE2.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJECTSTATE10_2.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "sdk/libgultra_inferred/802B3B80_4.H"
#include "AUDIO_3/802BFD40.H"

extern void func_802AE6BC_de(s32 arg0, ALEvent *arg1);

extern s32 func_802AE9B0_de(s32 arg0, s32 *arg1);

extern void func_802AFB6C_de(void *arg0, ALEvent *arg1);

extern void func_802B00D4_de(ALEventQueue *, ALEvent *, s32);



extern void *func_802B16E0_de(void *, s32, s32, s32);

extern void *__mapVoice(void *, u8, u8, u8);

extern ALVoiceState *func_802B1680_de(ALSeqPlayer *, u8, u8);

extern s32 func_802B3000_de(ALSynth_func_802B3000_de *, ALVoice_s_func_802B3000_de *, ALVoiceConfig_s *);

extern s32 func_802B18A4_de(void *, void *);

extern s16 func_802B1814_de(ALVoiceState *, ALSeqPlayer *);

extern s32 __vsDelta(void *, s32);

extern void func_802B35E0_de(ALSynth_func_802B3000_de *, ALVoice_s_func_802B3000_de *, void *, f32, s16, u8, u8, s32);

extern void func_802B1B14_de(void *, void *, s32);

extern void func_802B3480_de(void *, void *, s16, s32);

extern void func_802B3350_de(void *, void *, u8);

extern void func_802B32A0_de(void *, void *, u8);

extern void func_802B33E0_de(void *, void *, f32);

extern void __setInstChanState(void *, void *, s32);

/** Dispatch the current object message and forward any resulting value. */
void func_802AF150_de(void *rawPlayer) {
    struct ALSeqPlayer *arg0 = rawPlayer;
    ALEvent message;
    ALEvent output;
    s32 value1;
    s32 value2;
    s32 value3;
    s32 field18;
    s32 value;

    field18 = (s32)arg0->target;
    if (field18 != 0) {
        func_802AE6BC_de(field18, &message);
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
            func_802AF2E0_de(arg0, &message);
            if (arg0->state == 1) {
                field18 = (s32)arg0->target;
                if (field18 != 0 && (func_802AE9B0_de(field18, &value1) & 0xFF)) {
                    output.type = 0;
                    value = value1;
                    goto send_value;
                }
            }
            break;
        sw_message_2:
            func_802AFB6C_de(arg0, &message);
            if (arg0->state == 1) {
                field18 = (s32)arg0->target;
                if (field18 != 0 && (func_802AE9B0_de(field18, &value2) & 0xFF)) {
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
                field18 = (s32)arg0->target;
                if (field18 != 0 && (func_802AE9B0_de(field18, &value3) & 0xFF)) {
                    output.type = 0;
                    value = value3;
send_value:
                    func_802B00D4_de(&arg0->evtq, &output,
                                  value * arg0->uspt);
                }
            }
            break;
        sw_message_default:
            Audio_Assert(D_800C7350_de, D_800C7354_de, 0x190);
            break;
        
    } while (0);
    }
}

/* Apply one compact-sequence MIDI message. The existing event storage and
 * callee-specific voice/player views share their measured O32 prefixes. */
void func_802AF2E0_de(void *object, ALEvent *message)
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
            func_802B3000_de(seqp->drvr, (ALVoice_s_func_802B3000_de *)voice, &config);
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
            pan = func_802B18A4_de(vstate, seqp);
            vol = func_802B1814_de((ALVoiceState *)vstate, (ALSeqPlayer *)seqp);
            deltaTime = sound->envelope->attackTime;
            func_802B35E0_de(seqp->drvr, (ALVoice_s_func_802B3000_de *)voice, sound->wavetable, pitch, vol, pan, fxmix, deltaTime);
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
        vstate = (ALVoiceState *)func_802B1680_de((ALSeqPlayer *)seqp, key, chan);
        if (!vstate)
            return;
        if (vstate->phase == 2)
            vstate->phase = 4;
        else {
            vstate->phase = 3;
            func_802B1B14_de(seqp, &vstate->voice, vstate->sound->envelope->releaseTime);
        }
        break;
    case 0xA0: /* AL_MIDI_PolyKeyPressure */
        vstate = (ALVoiceState *)func_802B1680_de((ALSeqPlayer *)seqp, key, chan);
        if (!vstate)
            return;
        vstate->velocity = byte2;
        func_802B3480_de(seqp->drvr, &vstate->voice, func_802B1814_de((ALVoiceState *)vstate, (ALSeqPlayer *)seqp),
                      __vsDelta(vstate, seqp->curTime));
        break;
    case 0xD0: /* AL_MIDI_ChannelPressure */
        for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
            if (vs->channel == chan) {
                vs->velocity = byte1;
                func_802B3480_de(seqp->drvr, &vs->voice, func_802B1814_de((ALVoiceState *)vs, (ALSeqPlayer *)seqp),
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
                    pan = func_802B18A4_de(vs, seqp);
                    func_802B3350_de(seqp->drvr, &vs->voice, pan);
                }
            }
            break;
        case 0x07: /* AL_MIDI_VOLUME_CTRL */
            seqp->chanState[chan].vol = byte2;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if ((vs->channel == chan) && (vs->envPhase != 3)) {
                    vol = func_802B1814_de((ALVoiceState *)vs, (ALSeqPlayer *)seqp);
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
                            func_802B1B14_de(seqp, &vs->voice, vs->sound->envelope->releaseTime);
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
            Audio_Assert(D_800C7350_de, D_800C7354_de, 711);
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
