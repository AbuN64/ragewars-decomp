#include "span_1000/code_802B2614.h"
#include "span_1000/code_802B7488.h"
#include "span_1000/code_802B0388.h"
#include "common/unused.h"

extern const f32 D_800C7544;

extern s32 func_802B3000_de(ALSynth_func_802B3000_de *, ALVoice_s *, ALVoiceConfig_s *); /* alSynAllocVoice */
extern void func_802B3540_de(ALSynth_func_802B3000_de *, ALVoice_s *, void *);         /* alSynStartVoice */
extern void func_802B3350_de(ALSynth_func_802B3000_de *, ALVoice_s *, u8);             /* alSynSetPan */
extern void func_802B3480_de(ALSynth_func_802B3000_de *, ALVoice_s *, s16, s32);       /* alSynSetVol */
extern void func_802B33E0_de(ALSynth_func_802B3000_de *, ALVoice_s *, f32);            /* alSynSetPitch */
extern void func_802B32A0_de(ALSynth_func_802B3000_de *, ALVoice_s *, u8);             /* alSynSetFXMix */
extern void func_802B36F0_de(ALSynth_func_802B3000_de *, ALVoice_s *);                 /* alSynStopVoice */
extern void func_802B3200_de(ALSynth_func_802B3000_de *, ALVoice_s *);                 /* alSynFreeVoice */
extern void func_802B00D4_de(ALEventQueue *, Message_func_802AF150_de *, s32);       /* alEvtqPostEvent */
extern void func_802B2C48_de(ALEventQueue *, ALSoundState *);       /* _removeEvents */

void func_802B2780_de(ALSndPlayer *sndp, ALSndpEvent *event)
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
    const ALSndpEvent_func_802B2780_de *event_view =
        (const ALSndpEvent_func_802B2780_de *)event;

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
            func_802B3000_de(sndp->drvr, voice, &vc);
            vol = (s16)((s32)snd->envelope->attackVolume * state->vol / 127);
            tmp = state->pan - 64 + ((const ALSound_s_func_802B2780_de *)snd)->samplePan;
            tmp = ((tmp) > (0) ? (tmp) : (0));
            pan = (u8)((tmp) < (127) ? (tmp) : (127));
            pitch = state->pitch;
            delta = snd->envelope->attackTime;
            func_802B3540_de(sndp->drvr, voice, snd->wavetable);
            state->state = 1;
            func_802B3350_de(sndp->drvr, voice, pan);
            func_802B3480_de(sndp->drvr, voice, vol, delta);
            func_802B33E0_de(sndp->drvr, voice, pitch);
            func_802B32A0_de(sndp->drvr, voice, state->fxMix);
            evt.common.type = 6; /* AL_SNDP_DECAY_EVT */
            evt.common.state = state;
            delta = (s32)func_802B2CF0_de(snd->envelope->attackTime, state->pitch);
            func_802B00D4_de(&sndp->evtq, (Message_func_802AF150_de *)&evt, delta);
            break;

        case 1: /* AL_SNDP_STOP_EVT */
            if (state->state != 1 || !snd)
                return;
            delta = (s32)func_802B2CF0_de(snd->envelope->releaseTime, state->pitch);
            func_802B3480_de(sndp->drvr, &state->voice, 0, delta);
            if (delta) {
                evt.common.type = 7; /* AL_SNDP_END_EVT */
                evt.common.state = state;
                func_802B00D4_de(&sndp->evtq, (Message_func_802AF150_de *)&evt, delta);
                state->state = 2;
            } else {
                func_802B36F0_de(sndp->drvr, &state->voice);
                func_802B3200_de(sndp->drvr, &state->voice);
                func_802B2C48_de(&sndp->evtq, state);
                state->state = 0;
            }
            break;

        case 2: /* AL_SNDP_PAN_EVT */
            state->pan = event_view->pan.pan;
            if (state->state == 1 && snd) {
                tmp = state->pan - 64 + ((const ALSound_s_func_802B2780_de *)snd)->samplePan;
                tmp = ((tmp) > (0) ? (tmp) : (0));
                pan = (u8)((tmp) < (127) ? (tmp) : (127));
                func_802B3350_de(sndp->drvr, &state->voice, pan);
            }
            break;

        case 4: /* AL_SNDP_PITCH_EVT */
            {
                f32 min = D_800C7544;
                if ((state->pitch = event_view->pitch.pitch) < min)
                    state->pitch = min;
            }
            if (state->state == 1) {
                func_802B33E0_de(sndp->drvr, &state->voice, state->pitch);
            }
            break;

        case 8: /* AL_SNDP_FX_EVT */
            state->fxMix = event_view->fx.mix;
            if (state->state == 1)
                func_802B32A0_de(sndp->drvr, &state->voice, state->fxMix);
            break;

        case 3: /* AL_SNDP_VOL_EVT */
            state->vol = event_view->vol.vol;
            if (state->state == 1 && snd) {
                vtmp = snd->envelope->decayVolume * state->vol / 127;
                func_802B3480_de(sndp->drvr, &state->voice, (s16)vtmp, 1000);
            }
            break;

        case 6: /* AL_SNDP_DECAY_EVT */
            if (snd->envelope->decayTime != -1) {
                vtmp = snd->envelope->decayVolume * state->vol / 127;
                delta = (s32)func_802B2CF0_de(snd->envelope->decayTime, state->pitch);
                func_802B3480_de(sndp->drvr, &state->voice, (s16)vtmp, delta);
                evt.common.type = 1; /* AL_SNDP_STOP_EVT */
                evt.common.state = state;
                func_802B00D4_de(&sndp->evtq, (Message_func_802AF150_de *)&evt, delta);
            }
            break;

        case 7: /* AL_SNDP_END_EVT */
            func_802B36F0_de(sndp->drvr, &state->voice);
            func_802B3200_de(sndp->drvr, &state->voice);
            func_802B2C48_de(&sndp->evtq, state);
            state->state = 0;
            break;

        default:
            break;
    }
}
