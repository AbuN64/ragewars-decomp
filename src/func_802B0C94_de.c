#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AFEAC.h"
#include "span_1000/code_802B0388.h"
#include "types.h"
/* __handleMIDIMsg, drafted from ultralib src/audio/seqplayer.c: applies one MIDI channel message
   to the sequence player (note on with voice allocation, envelope and oscillator setup, note off,
   pressure, controllers, program change and pitch bend). Adapted from the matched csplayer twin:
   the status and data bytes are read through the event rather than the midi pointer, and the
   float to u8 tremolo conversion is written out against the cartridge's 2^31 constant with its
   store address taken first. */
extern const float D_800C74C0_de; /* 127.0f, followed by 2^31 */
extern const float D_800C74C8_de; /* 1.0f */
extern char D_800C7440[]; /* "EX" */
extern char D_800C7444[]; /* "audio/seqplayer.c" */
extern ALSound_s *func_802B16E0_de(ALSeqPlayer_func_802B0C94_de *, u8, u8, u8); /* __lookupSoundQuick */
extern ALVoiceState_s38 *func_802B151C_de(ALSeqPlayer_func_802B0C94_de *, u8, u8, u8); /* __mapVoice */
extern ALVoiceState_s38 *func_802B1680_de(ALSeqPlayer_func_802B0C94_de *, u8, u8); /* __lookupVoice */
extern s32 func_802B3000_de(void *, ALVoice_s *, ALVoiceConfig_s *); /* alSynAllocVoice */
                                   /* alCents2Ratio */
extern u8 func_802B18A4_de(ALVoiceState_s38 *, ALSeqPlayer_func_802B0C94_de *); /* __vsPan */
extern s16 func_802B1814_de(ALVoiceState_s38 *, ALSeqPlayer_func_802B0C94_de *); /* __vsVol */
extern ALMicroTime func_802B1888_de(ALVoiceState_s38 *, ALMicroTime); /* __vsDelta */
extern void func_802B35E0_de(void *, ALVoice_s *, void *, f32, s16, u8, u8, ALMicroTime); /* alSynStartVoiceParams */
extern void func_802B00D4_de(ALEventQueue *, ALEvent10 *, ALMicroTime); /* alEvtqPostEvent */
extern void func_802B1B14_de(ALSeqPlayer_func_802B0C94_de *, ALVoice_s *, ALMicroTime); /* __seqpReleaseVoice */
extern void func_802B3480_de(void *, ALVoice_s *, s16, ALMicroTime); /* alSynSetVol */
extern void func_802B3350_de(void *, ALVoice_s *, u8); /* alSynSetPan */
extern void func_802B32A0_de(void *, ALVoice_s *, u8); /* alSynSetFXMix */
extern void func_802B33E0_de(void *, ALVoice_s *, f32); /* alSynSetPitch */
extern void func_802B1AC0_de(ALSeqPlayer_func_802B0C94_de *, ALInstrument *, s32); /* __setInstChanState */
extern void func_802BAC50_de(char *, char *, s32); /* __assert */
void func_802B0C94_de(ALSeqPlayer_func_802B0C94_de *seqp, ALEvent10 *event)
{
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
    if (!(event->type == 1 || event->type == 2)) /* AL_SEQ_MIDI_EVT, AL_SEQP_MIDI_EVT */
        func_802BAC50_de(D_800C7440, D_800C7444, 436);
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
            f32 pitch, oscValue;
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
            func_802B3000_de(seqp->drvr, voice, &config);
            vstate->sound = sound;
            vstate->envPhase = 0;
            if (seqp->chanState[chan].sustain > 63)
                vstate->phase = 2;
            else
                vstate->phase = 0;
            cents = (key - sound->keyMap->keyBase) * 100 + sound->keyMap->detune;
            vstate->pitch = func_802AFE30_de(cents);
            vstate->envGain = sound->envelope->attackVolume;
            vstate->envEndTime = seqp->curTime + sound->envelope->attackTime;
            vstate->flags = 0;
            inst = seqp->chanState[chan].instrument;
            oscValue = D_800C74C0_de;
            if (inst->tremType) {
                if (seqp->initOsc) {
                    deltaTime = (*seqp->initOsc)(&oscState, &oscValue, inst->tremType,
                                                 inst->tremRate, inst->tremDepth, inst->tremDelay);
                    if (deltaTime) {
                        evt.type = 22; /* AL_TREM_OSC_EVT */
                        evt.msg.osc.vs = vstate;
                        evt.msg.osc.oscState = oscState;
                        func_802B00D4_de(&seqp->evtq, &evt, deltaTime);
                        vstate->flags |= 0x01;
                    }
                }
            }
            tremeloSlot = &vstate->tremelo;
            if (!(oscValue >= (*(&D_800C74C0_de + 1)))) {
                tremelo = (s32)oscValue;
            } else {
                tremelo = (s32)(oscValue - (*(&D_800C74C0_de + 1)));
                tremelo |= 0x80000000;
            }
            *tremeloSlot = tremelo;
            oscValue = D_800C74C8_de;
            if (inst->vibType) {
                if (seqp->initOsc) {
                    deltaTime = (*seqp->initOsc)(&oscState, &oscValue, inst->vibType,
                                                 inst->vibRate, inst->vibDepth, inst->vibDelay);
                    if (deltaTime) {
                        evt.type = 23; /* AL_VIB_OSC_EVT */
                        evt.msg.osc.vs = vstate;
                        evt.msg.osc.oscState = oscState;
                        evt.msg.osc.chan = chan;
                        func_802B00D4_de(&seqp->evtq, &evt, deltaTime);
                        vstate->flags |= 0x02;
                    }
                }
            }
            vstate->vibrato = oscValue;
            pitch = vstate->pitch * seqp->chanState[chan].pitchBend * vstate->vibrato;
            fxmix = seqp->chanState[chan].fxmix;
            pan = func_802B18A4_de(vstate, seqp);
            vol = func_802B1814_de(vstate, seqp);
            deltaTime = sound->envelope->attackTime;
            func_802B35E0_de(seqp->drvr, voice, sound->wavetable, pitch, vol, pan, fxmix, deltaTime);
            evt.type = 6; /* AL_SEQP_ENV_EVT */
            evt.msg.vol.voice = voice;
            evt.msg.vol.vol = sound->envelope->decayVolume;
            evt.msg.vol.delta = sound->envelope->decayTime;
            deltaTime = sound->envelope->attackTime;
            func_802B00D4_de(&seqp->evtq, &evt, deltaTime);
            break;
        }
    case 0x80: /* AL_MIDI_NoteOff */
        vstate = func_802B1680_de(seqp, key, chan);
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
        vstate = func_802B1680_de(seqp, key, chan);
        if (!vstate)
            return;
        vstate->velocity = byte2;
        func_802B3480_de(seqp->drvr, &vstate->voice, func_802B1814_de(vstate, seqp),
                      func_802B1888_de(vstate, seqp->curTime));
        break;
    case 0xD0: /* AL_MIDI_ChannelPressure */
        for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
            if (vs->channel == chan) {
                vs->velocity = byte1;
                func_802B3480_de(seqp->drvr, &vs->voice, func_802B1814_de(vs, seqp),
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
                    vol = func_802B1814_de(vs, seqp);
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
        case 0x14: /* AL_MIDI_FX_CTRL_0 */
        case 0x15: /* AL_MIDI_FX_CTRL_1 */
        case 0x16: /* AL_MIDI_FX_CTRL_2 */
        case 0x17: /* AL_MIDI_FX_CTRL_3 */
        case 0x18: /* AL_MIDI_FX_CTRL_4 */
        case 0x19: /* AL_MIDI_FX_CTRL_5 */
        case 0x1A: /* AL_MIDI_FX_CTRL_6 */
        case 0x1B: /* AL_MIDI_FX_CTRL_7 */
        case 0x5D: /* AL_MIDI_FX3_CTRL */
        default:
            break;
        }
        break;
    case 0xC0: /* AL_MIDI_ProgramChange */
        if (seqp->bank == 0)
            func_802BAC50_de(D_800C7440, D_800C7444, 714);
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
