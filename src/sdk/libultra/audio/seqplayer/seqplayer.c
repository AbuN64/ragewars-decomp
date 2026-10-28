#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "sdk/BUF16B.H"
#include "sdk/libgultra/part_800C7F20/__INITCHANSTATE.H"
#include "sdk/al_globals.h"
#include "COMMON/TRIPLE.H"
#include "COMMON/LONE/D_800C7444.H"
#include "COMMON/LONE/D_800C7440.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJRECAT18V1.H"
#include "sdk/libgultra/part_800C7F20/seqplayer.h"
#include "sdk/libgultra/part_800C7F20/__POSTNEXTSEQEVENT.H"
#include "AUDIO/AUDIO_ASSERT.H"
#include "COMMON/ALSEQUENCEPLAYER.H"
#include "COMMON/ALPARAM_S.H"
#include "COMMON/OBJRECAT4V6.H"
#include "sdk/libgultra.h"
#include "COMMON/ALDELAY28.H"

/* 802B3B80_2.CPP */
#if defined(VERSION_EU)
#include "TYPES.H"
#include "COMMON/ALSEQUENCEPLAYER.H"
#include "COMMON/OBJECTSTATE10_2.H"
#include "sdk/al_globals.h"
extern void *alHeapDBAlloc(s32, s32, void *, s32, s32);
extern void __initChanState(void *);
extern void alEvtqNew(void *, void *, s32);
extern void alSynAddPlayer(void *, void *);

void Seqplayer_CreateSequencePlayer(struct ALSequencePlayer *seqp, InitParams *c) {
    void *heap = c->context;
    void *drvr = D_800D4070;
    ALVoiceState *vs;
    ALVoiceState *voices;
    ALEventListItem *items;
    s32 i;
    seqp->base.chanMask = 0xFF;
    seqp->base.uspt = 0x1E8;
    seqp->base.bank = 0;
    seqp->base.target = 0;
    seqp->base.nextDelta = 0;
    seqp->base.state = 0;
    seqp->base.vol = 0x7FFF;
    seqp->base.drvr = drvr;
    seqp->base.debugFlags = c->debugFlags;
    seqp->base.frameTime = 0x3E80;
    seqp->base.curTime = 0;
    seqp->base.initOsc = c->value10;
    seqp->base.updateOsc = c->value14;
    seqp->base.stopOsc = c->value18;
    seqp->loopStart = 0;
    seqp->loopEnd = 0;
    seqp->loopCount = 0;
    seqp->base.nextEvent.type = 9;
    seqp->base.maxChannels = c->kind;
    seqp->base.chanState = alHeapDBAlloc(0, 0, heap, c->kind, sizeof(ALChanState));
    __initChanState(seqp);
    voices = alHeapDBAlloc(0, 0, heap, c->count38, sizeof(ALVoiceState));
    seqp->base.vFreeList = 0;
    for (i = 0; i < c->count38; i++) {
        vs = &voices[i];
        vs->next = seqp->base.vFreeList;
        seqp->base.vFreeList = vs;
    }
    seqp->base.vAllocHead = 0;
    seqp->base.vAllocTail = 0;
    items = alHeapDBAlloc(0, 0, heap, c->count1C, sizeof(ALEventListItem));
    alEvtqNew(&seqp->base.evtq, items, c->count1C);
    seqp->base.node.next = 0;
    seqp->base.node.handler = &D_002B0554;
    seqp->base.node.clientData = seqp;
    alSynAddPlayer(D_800D4070, seqp);
}
#endif

/* 802B54A0.CPP */
#if !(defined(VERSION_EU))
s32 alHeapDBAlloc(s32 a, s32 b, void *c, s32 d, s32 e);
extern void alEvtqNew(void *, void *, s32);
extern void alSynAddPlayer(void *, void *);

void alCSPNew(SeqInitPlayer *p, ALSeqpConfig *c) {
    void *heap = c->heap;
    void *driver = D_800D4070;
    SeqFreeVoice *voice;
    void *events;
    s32 i;
    p->mask = 255;
    p->uspt = 488;
    p->bank = 0;
    p->target = 0;
    p->delta = 0;
    p->state = 0;
    p->volume = 32767;
    p->driver = driver;
    p->debug = c->debug;
    p->frameTime = 16000;
    p->time = 0;
    p->initOsc = c->initOsc;
    p->updateOsc = c->updateOsc;
    p->stopOsc = c->stopOsc;
    p->loopStart = 0;
    p->loopEnd = 0;
    p->loopCount = 0;
    p->eventType = 9;
    p->channels = c->channels;
    p->channelState = alHeapDBAlloc(0, 0, heap, c->channels, 16);
    __initChanState(p);
    {
        SeqFreeVoice *base = alHeapDBAlloc(0, 0, heap, c->voices, 56);
        p->freeList = 0;
        i = 0;
        if (c->voices > 0) {
            voice = base;
            do {
                voice->next = p->freeList;
                p->freeList = voice;
                i++;
                voice++;
            } while (i < c->voices);
        }
    }
    p->allocHead = 0;
    p->allocTail = 0;
    events = alHeapDBAlloc(0, 0, heap, c->events, 28);
    alEvtqNew(p->queue, events, c->events);
    p->next = 0;
    p->callback = &D_002B0554;
    p->self = p;
    alSynAddPlayer(D_800D4070, p);
}
#endif

/* seqplayer_2.c */
 /* 2147483648.0f */

extern void Seqplayer_AdvanceSequenceEvent(struct ALSequencePlayer *);                        /* __handleNextSeqEvent */
extern void func_802B1E50_de(ALSeqPlayer *, f32);                   /* __setUsptFromTempo */
extern ALMicroTime alEvtqNextEvent(ALEventQueue *, ALEvent *);    /* alEvtqNextEvent */
extern void alEvtqFlushType(ALEventQueue *, s16);                 /* alEvtqFlushType */
extern void alSynStopVoice(struct Shape_typemap_71 *, ALVoice_s *);                   /* alSynStopVoice */
extern void alSynFreeVoice(void *, ALVoice_s *);                   /* alSynFreeVoice */
extern void alSynSetVol(void *, ALVoice_s *, s16, ALMicroTime); /* alSynSetVol */
extern void alSynSetPitch(void *, ALVoice_s *, f32);              /* alSynSetPitch */
extern s16 __vsVol(ALVoiceState *, ALSeqPlayer *);        /* __vsVol */
extern ALMicroTime __vsDelta(ALVoiceState *, ALMicroTime);  /* __vsDelta */
extern void __seqpReleaseVoice(ALSeqPlayer *, ALVoice_s *, ALMicroTime); /* __seqpReleaseVoice */
extern void __initFromBank(ALSeqPlayer *, void *);               /* __initFromBank */
                 /* __assert */

ALMicroTime Seqplayer_ProcessSequenceEvents(void *node)
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
            Seqplayer_AdvanceSequenceEvent(seqp);
            break;
        case 9: /* AL_SEQP_API_EVT */
            evt.type = 9;
            alEvtqPostEvent(&seqp->base.evtq, (ALEvent *)&evt, seqp->base.frameTime);
            break;
        case 5: /* AL_NOTE_END_EVT */
            voice = seqp->base.nextEvent.msg.note.voice;
            alSynStopVoice(seqp->base.drvr, voice);
            alSynFreeVoice(seqp->base.drvr, voice);
            vs = (ALVoiceState *)voice->clientPrivate;
            if (vs->flags)
                __seqpStopOsc(&seqp->base, vs);
            Seqplayer_ReleaseSequenceVoice(&seqp->base, voice);
            break;
        case 6: /* AL_SEQP_ENV_EVT */
            voice = seqp->base.nextEvent.msg.vol.voice;
            vs = (ALVoiceState *)voice->clientPrivate;
            if (vs->envPhase == 0)
                vs->envPhase = 1;
            delta = seqp->base.nextEvent.msg.vol.delta;
            vs->envGain = seqp->base.nextEvent.msg.vol.vol;
            vs->envEndTime = seqp->base.curTime + delta;
            alSynSetVol(seqp->base.drvr, voice, __vsVol(vs, &seqp->base), delta);
            break;
        case 22: /* AL_TREM_OSC_EVT */
            vs = seqp->base.nextEvent.msg.osc.vs;
            oscState = seqp->base.nextEvent.msg.osc.oscState;
            delta = (*seqp->base.updateOsc)(oscState, &oscValue);
            tremeloSlot = &vs->tremelo;
            tremelo = (u32)oscValue;
            *tremeloSlot = tremelo;
            alSynSetVol(seqp->base.drvr, &vs->voice, __vsVol(vs, &seqp->base),
                          __vsDelta(vs, seqp->base.curTime));
            evt.type = 22;
            evt.msg.osc.vs = vs;
            evt.msg.osc.oscState = oscState;
            alEvtqPostEvent(&seqp->base.evtq, &evt, delta);
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
            alEvtqPostEvent(&seqp->base.evtq, &evt, delta);
            break;
        case 2: /* AL_SEQP_MIDI_EVT */
            Seqplayer_HandleSequenceMidiEvent(&seqp->base, &seqp->base.nextEvent);
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
                    Seqplayer_ReleaseSequenceVoice(&seqp->base, &vs->voice);
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
                alEvtqPostEvent(&seqp->base.evtq, &evt, 0x7fffffff);
            }
            break;
        case 10: /* AL_SEQP_VOL_EVT */
            seqp->base.vol = seqp->base.nextEvent.msg.spvol.type;
            for (vs = seqp->base.vAllocHead; vs != 0; vs = vs->next) {
                alSynSetVol(seqp->base.drvr, &vs->voice, __vsVol(vs, &seqp->base),
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

/* seqplayer_3.c */
/* __handleMIDIMsg, drafted from ultralib src/audio/seqplayer.c: applies one MIDI channel message
   to the sequence player (note on with voice allocation, envelope and oscillator setup, note off,
   pressure, controllers, program change and pitch bend). Adapted from the matched csplayer twin:
   the status and data bytes are read through the event rather than the midi pointer, and the
   float to u8 tremolo conversion is written out against the cartridge's 2^31 constant with its
   store address taken first. */

 /* 127.0f, followed by 2^31 */

 /* 1.0f */

 /* "EX" */

 /* "audio/seqplayer.c" */
extern ALSound_s *__lookupSoundQuick(ALSeqPlayer *, u8, u8, u8);

 /* __lookupSoundQuick */
extern ALVoiceState *__mapVoice(ALSeqPlayer *, u8, u8, u8);

 /* __mapVoice */
extern ALVoiceState *__lookupVoice(ALSeqPlayer *, u8, u8);

 /* __lookupVoice */
extern s32 alSynAllocVoice(void *, ALVoice_s *, ALVoiceConfig_s *);

 /* alSynAllocVoice */
                                   /* alCents2Ratio */
extern u8 __vsPan(ALVoiceState *, ALSeqPlayer *);

 /* __vsPan */

 /* __vsVol */

 /* __vsDelta */
extern void alSynStartVoiceParams(void *, ALVoice_s *, void *, f32, s16, u8, u8, ALMicroTime);

 /* alSynStartVoiceParams */

 /* alEvtqPostEvent */

 /* __seqpReleaseVoice */

 /* alSynSetVol */
extern void alSynSetPan(void *, ALVoice_s *, u8);

 /* alSynSetPan */
extern void alSynSetFXMix(void *, ALVoice_s *, u8);

 /* alSynSetFXMix */

 /* alSynSetPitch */
extern void __setInstChanState(ALSeqPlayer *, ALInstrument *, s32);

 /* __setInstChanState */

void Seqplayer_AdvanceSequenceEvent(struct ALSequencePlayer *seqp)
{
    ALEvent evt;

    if (seqp->base.target == 0)
        return;

    alSeqNextEvent(seqp->base.target, &evt);

    switch (evt.type) {
    case 1:     /* AL_SEQ_MIDI_EVT */
        Seqplayer_HandleSequenceMidiEvent(&seqp->base, &evt);
        postNextSeqEvent(seqp);
        break;

    case 3:     /* AL_TEMPO_EVT */
        __handleMetaMsg(&seqp->base, &evt);
        postNextSeqEvent(seqp);
        break;

    case 4:     /* AL_SEQ_END_EVT */
        seqp->base.state = 2;
        evt.type = 16;  /* AL_SEQP_STOP_EVT */
        alEvtqPostEvent(&seqp->base.evtq, &evt, 0x7fffffff);
        break;

    default:
        Audio_Assert(D_800C7440, g_audioSeqplayerText, 412);
    }
}

 /* __assert */
void Seqplayer_HandleSequenceMidiEvent(ALSeqPlayer *seqp, ALEvent *event)
{
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
    if (!(event->type == 1 || event->type == 2)) /* AL_SEQ_MIDI_EVT, AL_SEQP_MIDI_EVT */
        Audio_Assert(D_800C7440, g_audioSeqplayerText, 436);
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
            sound = __lookupSoundQuick(seqp, key, vel, chan);
            if (!sound)
                return;
            config.priority = seqp->chanState[chan].priority;
            config.fxBus = 0;
            config.unityPitch = 0;
            vstate = __mapVoice(seqp, key, vel, chan);
            if (!vstate)
                return;
            voice = &vstate->voice;
            alSynAllocVoice(seqp->drvr, voice, &config);
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
                        alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
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
                        alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                        vstate->flags |= 0x02;
                    }
                }
            }
            vstate->vibrato = oscValue;
            pitch = vstate->pitch * seqp->chanState[chan].pitchBend * vstate->vibrato;
            fxmix = seqp->chanState[chan].fxmix;
            pan = __vsPan(vstate, seqp);
            vol = __vsVol(vstate, seqp);
            deltaTime = sound->envelope->attackTime;
            alSynStartVoiceParams(seqp->drvr, voice, sound->wavetable, pitch, vol, pan, fxmix, deltaTime);
            evt.type = 6; /* AL_SEQP_ENV_EVT */
            evt.msg.vol.voice = voice;
            evt.msg.vol.vol = sound->envelope->decayVolume;
            evt.msg.vol.delta = sound->envelope->decayTime;
            deltaTime = sound->envelope->attackTime;
            alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
            break;
        }
    case 0x80: /* AL_MIDI_NoteOff */
        vstate = __lookupVoice(seqp, key, chan);
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
        vstate = __lookupVoice(seqp, key, chan);
        if (!vstate)
            return;
        vstate->velocity = byte2;
        alSynSetVol(seqp->drvr, &vstate->voice, __vsVol(vstate, seqp),
                      __vsDelta(vstate, seqp->curTime));
        break;
    case 0xD0: /* AL_MIDI_ChannelPressure */
        for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
            if (vs->channel == chan) {
                vs->velocity = byte1;
                alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp),
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
                    alSynSetPan(seqp->drvr, &vs->voice, pan);
                }
            }
            break;
        case 0x07: /* AL_MIDI_VOLUME_CTRL */
            seqp->chanState[chan].vol = byte2;
            for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                if ((vs->channel == chan) && (vs->envPhase != 3)) {
                    vol = __vsVol(vs, seqp);
                    alSynSetVol(seqp->drvr, &vs->voice, vol, __vsDelta(vs, seqp->curTime));
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
                    alSynSetFXMix(seqp->drvr, &vs->voice, byte2);
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
            Audio_Assert(D_800C7440, g_audioSeqplayerText, 714);
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
                    alSynSetPitch(seqp->drvr, &vs->voice, vs->pitch * bendRatio * vs->vibrato);
        }
        break;
    default:
        break;
    }
}

/* seqplayer.c */
ALVoiceState *__mapVoice(ALSeqPlayer *sequencePlayer, u8 noteKey, u8 noteVelocity, u8 midiChannel) {
    ALVoiceState *node;
    ALSeqPlayer88 *player = (ALSeqPlayer88 *)sequencePlayer;
    ALVoiceState *next;
    ALVoiceState *tail;

    node = player->vFreeList;
    if (node != 0) {
        next = node->next;
        player->vFreeList = next;
        node->next = 0;
        if (player->vAllocHead == 0) {
            player->vAllocHead = node;
        } else {
            tail = player->vAllocTail;
            tail->next = node;
        }
        player->vAllocTail = node;
        node->channel = midiChannel;
        node->key = noteKey;
        node->velocity = noteVelocity;
        node->voice.clientPrivate = node;
    }
    return node;
}

void Seqplayer_ReleaseSequenceVoice(List802B663C *voicePool, void *voice) {
    NodeGskyActivateMessagePool *node;
    NodeGskyActivateMessagePool *prev;

    prev = 0;
    node = voicePool->head;
    while (node != 0) {
        if ((void *)(node + 1) == voice) {
            if (prev != 0) {
                prev->next = node->next;
            } else {
                voicePool->head = node->next;
            }
            if (node == voicePool->tail) {
                voicePool->tail = prev;
            }
            node->next = voicePool->free;
            voicePool->free = node;
            return;
        }
        prev = node;
        node = node->next;
    }
}
