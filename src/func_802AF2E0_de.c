#include "span_1000/code_802AE028.h"
#include "common/unused.h"
#include "span_C76B0/data.h"
#include "span_1000/code_802B0388.h"
#include "types.h"

extern void *func_802B16E0_de(void *, s32, s32, s32);
extern void *func_802B151C_de(void *, u8, u8, u8);
extern ALVoiceState_s *func_802B1680_de(ALSeqPlayer *, u8, u8);
extern s32 func_802B3000_de(ALSynth_func_802B3000_de *, ALVoice_s_func_802B3000_de *, ALVoiceConfig_s *);

extern s32 func_802B18A4_de(void *, void *);
extern s16 func_802B1814_de(ALVoiceState_s_func_802B1814_de *, ALSeqPlayer_func_802B1814_de *);
extern s32 func_802B1888_de(void *, s32);
extern void func_802B35E0_de(ALSynth_func_802B3000_de *, ALVoice_s_func_802B3000_de *, void *, f32, s16, u8, u8, s32);
extern void func_802B00D4_de(ALEventQueue *, Message_func_802AF150_de *, s32);
extern void func_802B1B14_de(void *, void *, s32);
extern void func_802B3480_de(void *, void *, s16, s32);
extern void func_802B3350_de(void *, void *, u8);
extern void func_802B32A0_de(void *, void *, u8);
extern void func_802B33E0_de(void *, void *, f32);
extern void func_802B1AC0_de(void *, void *, s32);
extern void func_802BAC50_de(void *, void *, s32);

/* Apply one compact-sequence MIDI message. The existing event storage and
 * callee-specific voice/player views share their measured O32 prefixes. */
void func_802AF2E0_de(void *object, Message_func_802AF150_de *message)
{
    ALSeqPlayer_func_802B0C94_de *seqp = object;
    ALEvent10 *event = (ALEvent10 *)message;
    ALVoice_s *voice;
    ALVoiceState_s38 *vs;
    s32 status;
    u8 chan;
    u8 key;
    u8 vel;
    u8 byte1;
    u8 byte2;
    ALMIDIEvent *midi = &event->msg.midi;
    s16 vol;
    ALEvent10 evt;
    ALMicroTime deltaTime;
    ALVoiceState_s38 *vstate;
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
            vstate = func_802B151C_de(seqp, key, vel, chan);
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
                        func_802B00D4_de(&seqp->evtq, (Message_func_802AF150_de *)&evt, deltaTime);
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
                        func_802B00D4_de(&seqp->evtq, (Message_func_802AF150_de *)&evt, deltaTime);
                        vstate->flags |= 0x02;
                    }
                }
            }
            vstate->vibrato = oscValue;
            pitch = vstate->pitch * seqp->chanState[chan].pitchBend * vstate->vibrato;
            fxmix = seqp->chanState[chan].fxmix;
            pan = func_802B18A4_de(vstate, seqp);
            vol = func_802B1814_de((ALVoiceState_s_func_802B1814_de *)vstate, (ALSeqPlayer_func_802B1814_de *)seqp);
            deltaTime = sound->envelope->attackTime;
            func_802B35E0_de(seqp->drvr, (ALVoice_s_func_802B3000_de *)voice, sound->wavetable, pitch, vol, pan, fxmix, deltaTime);
            evt.type = 6; /* AL_SEQP_ENV_EVT */
            evt.msg.vol.voice = voice;
            evt.msg.vol.vol = sound->envelope->decayVolume;
            evt.msg.vol.delta = sound->envelope->decayTime;
            func_802B00D4_de(&seqp->evtq, (Message_func_802AF150_de *)&evt, deltaTime);
            if (midi->duration) {
                evt.type = 21; /* AL_CSP_NOTEOFF_EVT */
                evt.msg.midi.status = chan | 0x80;
                evt.msg.midi.byte1 = key;
                evt.msg.midi.byte2 = 0;
                deltaTime = seqp->uspt * midi->duration;
                func_802B00D4_de(&seqp->evtq, (Message_func_802AF150_de *)&evt, deltaTime);
            }
            break;
        }
    case 0x80: /* AL_MIDI_NoteOff */
        vstate = (ALVoiceState_s38 *)func_802B1680_de((ALSeqPlayer *)seqp, key, chan);
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
        vstate = (ALVoiceState_s38 *)func_802B1680_de((ALSeqPlayer *)seqp, key, chan);
        if (!vstate)
            return;
        vstate->velocity = byte2;
        func_802B3480_de(seqp->drvr, &vstate->voice, func_802B1814_de((ALVoiceState_s_func_802B1814_de *)vstate, (ALSeqPlayer_func_802B1814_de *)seqp),
                      func_802B1888_de(vstate, seqp->curTime));
        break;
    case 0xD0: /* AL_MIDI_ChannelPressure */
        for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
            if (vs->channel == chan) {
                vs->velocity = byte1;
                func_802B3480_de(seqp->drvr, &vs->voice, func_802B1814_de((ALVoiceState_s_func_802B1814_de *)vs, (ALSeqPlayer_func_802B1814_de *)seqp),
                              func_802B1888_de(vs, seqp->curTime));
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
                    vol = func_802B1814_de((ALVoiceState_s_func_802B1814_de *)vs, (ALSeqPlayer_func_802B1814_de *)seqp);
                    func_802B3480_de(seqp->drvr, &vs->voice, vol, func_802B1888_de(vs, seqp->curTime));
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
            func_802BAC50_de(D_800C7350_de, D_800C7354_de, 711);
        if (key < seqp->bank->instCount) {
            ALInstrument *inst = seqp->bank->instArray[key];
            func_802B1AC0_de(seqp, inst, chan);
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
