#include "sdk/libgultra.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520_6.h"
#include "include_asm.h"
#include "sdk/EXTERNS.H"
#include "COMMON/TRIPLE.H"
#include "sdk/libgultra/part_800C7F20/alunlink.h"
#include "AUDIO/802BFD40.H"

/* alSndpNew, drafted from ultralib src/audio/sndplayer.c: sets up a sound player from its config,
   allocating the sound states and event items from the heap, registers its voice handler with the
   global synthesizer and posts the first frame API event. */

























extern ALGlobalsalSndpNew *D_800D4070;

 /* alGlobals */

extern void *alHeapDBAlloc(u8 *, s32, ALHeap *, s32, s32);

          /* alHeapDBAlloc */
extern void alEvtqNew(ALEventQueue *, ALEventListItem *, s32);

  /* alEvtqNew */
extern void alSynAddPlayer(ALSynthalSndpNew *, ALPlayer_s14 *);

                   /* alSynAddPlayer */

          /* alEvtqPostEvent */
extern s32 alEvtqNextEvent(ALEventQueue *, ALEvent *);

                /* alEvtqNextEvent */
/* _sndpVoiceHandler (_sndpVoiceHandler); the cartridge stores the handler by its 0x002B7C8C address. */


extern s32 alSynAllocVoice(ALSynthalSynAllocVoice *, ALVoice_s *, ALVoiceConfig_s *);

 /* alSynAllocVoice */
extern void alSynStartVoice(ALSynthalSynAllocVoice *, ALVoice_s *, void *);

         /* alSynStartVoice */
extern void alSynSetPan(ALSynthalSynAllocVoice *, ALVoice_s *, u8);

             /* alSynSetPan */
extern void alSynSetVol(ALSynthalSynAllocVoice *, ALVoice_s *, s16, s32);

       /* alSynSetVol */
extern void alSynSetPitch(ALSynthalSynAllocVoice *, ALVoice_s *, f32);

            /* alSynSetPitch */
extern void alSynSetFXMix(ALSynthalSynAllocVoice *, ALVoice_s *, u8);

             /* alSynSetFXMix */
extern void alSynStopVoice(ALSynthalSynAllocVoice *, ALVoice_s *);

                 /* alSynStopVoice */
extern void alSynFreeVoice(ALSynthalSynAllocVoice *, ALVoice_s *);

       /* alEvtqPostEvent */
void _removeEvents(ALEventQueue *arg0, void *arg1);

void alSndpNew(ALSndPlayeralSndpNew *sndp, ALSndpConfig *c)
{
    u8 *ptr;
    ALEvent evt;
    ALSoundState *sState;
    u32 i;

    sndp->maxSounds = c->maxSounds;
    sndp->target = -1;
    sndp->frameTime = 16000;
    sState = (ALSoundState *)alHeapDBAlloc(0, 0, c->heap, 1, c->maxSounds * sizeof(ALSoundState));
    sndp->sndState = sState;

    for (i = 0; i < c->maxSounds; i++)
        sState[i].sound = 0;

    ptr = alHeapDBAlloc(0, 0, c->heap, 1, c->maxEvents * sizeof(ALEventListItem));
    alEvtqNew(&sndp->evtq, (ALEventListItem *)ptr, c->maxEvents);

    sndp->drvr = &D_800D4070->drvr;

    sndp->node.next = 0;
    sndp->node.handler = D_002B2BBC;
    sndp->node.clientData = sndp;
    alSynAddPlayer(sndp->drvr, &sndp->node);

    evt.type = 5; /* AL_SNDP_API_EVT */
    alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, sndp->frameTime);
    sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
}

       /* _removeEvents */

void _handleEvent(ALSndPlayer *sndp, ALSndpEvent *event)
{
    ALVoiceConfig_s vc;
    ALSound_s *snd;
    ALVoice_s *voice;
    u8 pan;
    f32 pitch;
    ALSndpEvent evt;
    s32 delta;
    s16 vol;
    s16 tmp;
    s32 vtmp;
    ALSoundState *state;
    const ALSndpEventhandleEvent *event_view =
        (const ALSndpEventhandleEvent *)event;

    state = event->common.state;
    snd = state->sound;

    switch (event->msg.type) {
        case 0: /* AL_SNDP_PLAY_EVT */
            if (state->state != 0 || !snd)
                return;
            vc.fxBus = 0;
            vc.priority = state->priority;
            vc.unityPitch = 0;
            voice = &state->voice;
            alSynAllocVoice(sndp->drvr, voice, &vc);
            vol = (s16)((s32)snd->envelope->attackVolume * state->vol / 127);
            tmp = state->pan - 64 + ((const struct ALSound *)snd)->samplePan;
            tmp = ((tmp) > (0) ? (tmp) : (0));
            pan = (u8)((tmp) < (127) ? (tmp) : (127));
            pitch = state->pitch;
            delta = snd->envelope->attackTime;
            alSynStartVoice(sndp->drvr, voice, snd->wavetable);
            state->state = 1;
            alSynSetPan(sndp->drvr, voice, pan);
            alSynSetVol(sndp->drvr, voice, vol, delta);
            alSynSetPitch(sndp->drvr, voice, pitch);
            alSynSetFXMix(sndp->drvr, voice, state->fxMix);
            evt.common.type = 6; /* AL_SNDP_DECAY_EVT */
            evt.common.state = state;
            delta = (s32)_DivS32ByF32(snd->envelope->attackTime, state->pitch);
            alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);
            break;

        case 1: /* AL_SNDP_STOP_EVT */
            if (state->state != 1 || !snd)
                return;
            delta = (s32)_DivS32ByF32(snd->envelope->releaseTime, state->pitch);
            alSynSetVol(sndp->drvr, &state->voice, 0, delta);
            if (delta) {
                evt.common.type = 7; /* AL_SNDP_END_EVT */
                evt.common.state = state;
                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);
                state->state = 2;
            } else {
                alSynStopVoice(sndp->drvr, &state->voice);
                alSynFreeVoice(sndp->drvr, &state->voice);
                _removeEvents(&sndp->evtq, state);
                state->state = 0;
            }
            break;

        case 2: /* AL_SNDP_PAN_EVT */
            state->pan = event_view->pan.pan;
            if (state->state == 1 && snd) {
                tmp = state->pan - 64 + ((const struct ALSound *)snd)->samplePan;
                tmp = ((tmp) > (0) ? (tmp) : (0));
                pan = (u8)((tmp) < (127) ? (tmp) : (127));
                alSynSetPan(sndp->drvr, &state->voice, pan);
            }
            break;

        case 4: /* AL_SNDP_PITCH_EVT */
            {
                f32 min = D_800C7544;
                if ((state->pitch = event_view->pitch.pitch) < min)
                    state->pitch = min;
            }
            if (state->state == 1) {
                alSynSetPitch(sndp->drvr, &state->voice, state->pitch);
            }
            break;

        case 8: /* AL_SNDP_FX_EVT */
            state->fxMix = event_view->fx.mix;
            if (state->state == 1)
                alSynSetFXMix(sndp->drvr, &state->voice, state->fxMix);
            break;

        case 3: /* AL_SNDP_VOL_EVT */
            state->vol = event_view->vol.vol;
            if (state->state == 1 && snd) {
                vtmp = snd->envelope->decayVolume * state->vol / 127;
                alSynSetVol(sndp->drvr, &state->voice, (s16)vtmp, 1000);
            }
            break;

        case 6: /* AL_SNDP_DECAY_EVT */
            if (snd->envelope->decayTime != -1) {
                vtmp = snd->envelope->decayVolume * state->vol / 127;
                delta = (s32)_DivS32ByF32(snd->envelope->decayTime, state->pitch);
                alSynSetVol(sndp->drvr, &state->voice, (s16)vtmp, delta);
                evt.common.type = 1; /* AL_SNDP_STOP_EVT */
                evt.common.state = state;
                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);
            }
            break;

        case 7: /* AL_SNDP_END_EVT */
            alSynStopVoice(sndp->drvr, &state->voice);
            alSynFreeVoice(sndp->drvr, &state->voice);
            _removeEvents(&sndp->evtq, state);
            state->state = 0;
            break;

        default:
            break;
    }
}

/* _sndpVoiceHandler, drafted from ultralib src/audio/sndplayer.c: the sound player's synthesizer
   callback; reposts the frame API event or handles the pending event until the next one is in
   the future, then advances the player's time by that delta. The pointer to the pending event
   is held in a local, standing in for the address register -fforce-addr kept for it. */













   /* _handleEvent */
       /* alEvtqNextEvent */

s32 _sndpVoiceHandler(void *node)
{
    ALSndPlayer *sndp = (ALSndPlayer *)node;
    ALSndpEvent evt;
    ALSndpEvent *next = (ALSndpEvent *)&sndp->nextEvent;

    do {
        switch (sndp->nextEvent.type) {
            case 5: /* AL_SNDP_API_EVT */
                evt.common.type = 5;
                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, sndp->frameTime);
                break;
            default:
                _handleEvent(sndp, next);
                break;
        }
        sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
    } while (sndp->nextDelta == 0);

    sndp->curTime += sndp->nextDelta;
    return sndp->nextDelta;
}

extern s32 func_802BD170_de(s32);








void _removeEvents(ALEventQueue *arg0, void *arg1) {
    s32 saved;
    ALEventListItem *cur;
    ALEventListItem *next;

    saved = func_802BD170_de(1);
    cur = (ALEventListItem *)arg0->allocList.next;
    if (cur != 0) {
        do {
            next = (ALEventListItem *)cur->node.next;
            if (((ALSndpEvent *)&cur->evt)->common.state == arg1) {
                if (next != 0) {
                    next->delta = next->delta + cur->delta;
                }
                alUnlink(cur);
                alLink(cur, arg0);
            }
            cur = next;
        } while (cur != 0);
    }
    func_802BD170_de(saved);
}

s32 _DivS32ByF32(s32 val, f32 div) {
    f32 fval;
    f64 dresult;
    s32 result;

    if (div == 0.0f) {
        Audio_Assert(D_800C7548, s_audioSndplayerText, 0x11D);
    }

    result = 0x7FFFFFFF;
    fval = (f32)val / div;
    dresult = (f64)fval;
    if (!(D_800C7560 < dresult)) {
        result = (s32)dresult;
    }
    return result;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802B2CA8[2] = {
    0x73540000, 0x02000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_802B2CF0_de_padding_B3C58[1] = {
    0x00000000,
};
#endif
