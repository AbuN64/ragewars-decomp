#include "include_asm.h"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/UNUSED.H"
#include "AUDIO/8025A3EC.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "AUDIO/EXTERNS.H"
#include "COMMON/AUDIO_CONTEXT.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/SHAREDRECV4.H"
#include "COMMON/TRIPLE.H"
#include "stddef.h"
int Camera_IsSequenceActive(void);
f32 Nav_ApproachValue(f32 arg0, f32 arg1, f32 arg2);
void func_802B2F10_de(void *arg0, s16 arg1);
/* Spatial mix and runtime envelope controls embedded in a sound voice. */
typedef struct AudioVolumeMix {
    s32 frame, reserved4;
    s32 left, right;
    u8 reserved10[0xC];
    f32 attenuation, baseAttenuation, field24;
    s16 priority, channel;
    u8 reserved2C[8];
    CVector3 position;
    void *tracked;
    s8 curve;
    u8 reserved45[0x1F];
} AudioVolumeMix;

typedef struct AudioVolumeControl {
    u16 levels[3];
    s16 frames;
    s16 delay;
    u16 reservedA;
} AudioVolumeControl;

typedef struct AudioVolumeVoice {
    s32 unk0, sound, unk8, unkC;
    AudioVolumeMix mix;
    AudioVolumeControl control;
    f32 envelopeValue, envelopeStep;
    u8 reserved88[0x18];
    s32 pending, flags, soundId, fieldAC;
    ContextRecAt2BC0 *context;
    s32 fieldB4;
    f32 fieldB8;
    s32 fieldBC, fieldC0, fieldC4;
    f32 volumeScale;
} AudioVolumeVoice;

/* Converts the attenuated level to a volume and applies it, scaled, to the voice sound. */
static inline void apply_volume(AudioVolumeVoice *voice, f32 level) {
    ContextRecAt2BC0 *outputContext;
    ALSndPlayer *outputSound;
    s32 volume;

    outputContext = voice->context;
    outputSound = outputContext->list;
    volume = (s32)level;
    func_802B2F00_de(outputSound, outputContext->handles[voice->unk0]);
    func_802B2F10_de(outputSound, (s16)(s32)((f32)volume * voice->volumeScale));
}

/* Updates spatial attenuation and the volume envelope, then applies the scaled level. */
void Audio_UpdateVoiceVolume(AudioVolumeVoice *voice) {
    AudioVolumeMix *mix;
    u16 *envelope;
    ContextRecAt2BC0 *context;
    GameplayCamera *listener;
    CVector3 *position;
    CVector3 *ear;
    f32 distance, radius, squared;
    f32 dx, dy, dz;
    f32 masterGain, falloff, level;
    s32 increasing;
    s32 value;

    listener = voice->context->field2B98;
    radius = listener->unk528;
    squared = radius < 3072.0f ? 3072.0f : radius;
    squared *= radius < 3072.0f ? 3072.0f : radius;
    D_800D0D10 = squared;
    switch (voice->mix.curve) {
    case 0:
        break;
    case 2:
        D_800D0D10 = squared + squared * 0.5f;
        break;
    case 1:
        D_800D0D10 = squared + squared * 0.25f;
        break;
    }
    mix = &voice->mix;
    envelope = voice->control.levels;
    context = voice->context;
    if (voice->flags & 0x200) {
        masterGain = context->blue;
    } else {
        masterGain = context->red;
        if (voice->fieldC4 && context->field2BB8) {
            masterGain *= 0.5f;
        }
    }
    if ((voice->flags & 0x400) && voice->fieldC0 == 0 && !(voice->flags & 0x800)) {
        listener = voice->context->field2B98;
        position = &mix->position;
        ear = &listener->position;
        dx = position->x - ear->x;
        dy = position->y - ear->y;
        dz = position->z - ear->z;
        distance = dx * dx + dy * dy + dz * dz;
        if (D_800D0D10 <= distance) {
            falloff = 0.0f;
        } else {
            falloff = 1.0f - distance / D_800D0D10;
        }
        switch (mix->curve) {
        case 2:
            level = falloff;
            break;
        case 0:
            falloff *= falloff;
            falloff *= falloff;
            /* Fall through to the final square. */
        case 1:
            falloff *= falloff;
            level = falloff;
            break;
        default:
            level = 0.0f;
            break;
        }
        if (Camera_IsSequenceActive() != 0) {
            mix->attenuation = Nav_ApproachValue(mix->attenuation, level, 0.017f);
        } else {
            mix->attenuation = level;
        }
    } else {
        mix->attenuation = 1.0f;
    }
    if (voice->flags & 4) {
        if (voice->control.delay > 0) {
            voice->control.delay--;
        } else {
            increasing = 0;
            if (voice->envelopeStep < 0.0f) {
                increasing = 1;
            }
            if (increasing ? voice->envelopeValue < func_802B2350(envelope[2]) :
                             func_802B2350(envelope[2]) < voice->envelopeValue) {
                voice->envelopeValue -= voice->envelopeStep;
                if (increasing) {
                    if (func_802B2350(envelope[2]) < voice->envelopeValue) {
                        voice->envelopeValue = func_802B2350(envelope[2]);
                    }
                } else if (voice->envelopeValue < func_802B2350(envelope[2])) {
                    voice->envelopeValue = func_802B2350(envelope[2]);
                    if (voice->envelopeValue == 0.0f) {
                        ALSndPlayer *stoppedSound;
                        ContextRecAt2BC0 *stopContext;

                        stopContext = voice->context;
                        voice->fieldAC = 1;
                        voice->mix.tracked = 0;
                        stoppedSound = stopContext->list;
                        if (voice->mix.frame != stopContext->frame) {
                            func_802B2F00_de(stoppedSound, stopContext->handles[voice->unk0]);
                            if (func_802B2620_de(stoppedSound)) {
                                alSndpStop(stoppedSound);
                            }
                            voice->sound = -1;
                        }
                    }
                }
            }
        }
        value = (s32)(func_802B2350(voice->control.levels[0]) * voice->envelopeValue);
        mix->left = value;
        apply_volume(voice, (f32)value * mix->attenuation * masterGain);
    } else {
        f32 attenuation;

        if (voice->flags & 0x400) {
            attenuation = mix->attenuation;
        } else {
            attenuation = mix->baseAttenuation;
        }
        apply_volume(voice, (f32)mix->left * attenuation * masterGain);
    }
}

/* Updates a voice pan from its sweep, position or centered fallback and applies it to the owner sound. */

extern s32 func_80258D2C_de(OwnerCode8025A3EC *);
extern s16 func_80259B10_de(void *, GameplayCamera *);

extern void func_802B2F00_de(void *, s16);
extern void alSndpSetPan(void *, s32);

static inline void apply_pan(Voice_func_8025A844_de *voice, u8 pan) {
    OwnerCode8025A3EC *owner = voice->owner;
    char *sound = owner->sound;

    func_802B2F00_de(sound, owner->samples[voice->index]);
    alSndpSetPan(sound, pan);
}

void func_8025A844_de(Voice_func_8025A844_de *voice) {
    s32 rising;
    ParamsRecAt18 *params;

    params = &voice->params;
    if (func_80258D2C_de(voice->owner) == 0) {
        apply_pan(voice, 0x40);
        return;
    }
    if (voice->sweeping != 0) {
        if (voice->delay > 0) {
            voice->delay--;
        } else {
            rising = 0;
            if (voice->step < 0.0f) {
                rising = 1;
            }
            if (rising ? voice->value < RW_BITS_TO_FLOAT(voice->target) : RW_BITS_TO_FLOAT(voice->target) < voice->value) {
                voice->value -= voice->step;
                if (rising) {
                    if (!(RW_BITS_TO_FLOAT(voice->target) < voice->value)) goto clamp_done;
                } else {
                    if (!(voice->value < RW_BITS_TO_FLOAT(voice->target))) goto clamp_done;
                }
                voice->value = RW_BITS_TO_FLOAT(voice->target);
clamp_done:
                ;
            }
        }
        params->pan = voice->value;
        goto apply;
    }
    if ((voice->flags & 0x400) && voice->fixed == 0) {
        params->pan = func_80259B10_de(voice->position, voice->owner->listener);
    apply:
        apply_pan(voice, params->pan);
        return;
    }
    params->pan = 0x40;
}

/* Fades emitter 0x8AC with the listener's distance: optionally resets its level, stores the squared
 * distance to the listener, lowers the level by a step while the distance grows and raises it while it
 * shrinks (clamped to the D_800C9048 range, remembering the distance), and otherwise eases the level one
 * step toward the rest level D_800C9044. */
void func_8025AA2C_de(Emitter *emitter) {
    char *listener;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 distance;
    f32 level;
    f32 current;

    if (emitter->id != 0x8AC) {
        return;
    }
    if (emitter->reset != 0) {
        emitter->level = D_800C3F50_de;
    }
    listener = ((OwnerCode8025A3EC *)emitter->scene)->listener;
    dx = emitter->x - ((GameplayCamera *)listener)->position.x;
    dy = emitter->y - ((GameplayCamera *)listener)->position.y;
    dz = emitter->z - ((GameplayCamera *)listener)->position.z;
    distance = dx * dx + dy * dy + dz * dz;
    emitter->distance = distance;
    if (emitter->lastDistance < distance) {
        emitter->level -= D_800CB8E8;
    } else if (distance < emitter->lastDistance) {
        emitter->level += D_800CB8E8;
    } else {
        current = emitter->level;
        if (D_800C9044 < current) {
            level = current - D_800CB8E8;
            if (level < D_800C9044) {
                level = D_800C9044;
            }
            emitter->level = level;
        } else if (current < D_800C9044) {
            level = current + D_800CB8E8;
            if (D_800C9044 < level) {
                level = D_800C9044;
            }
            emitter->level = level;
        }
        return;
    }
    level = emitter->level;
    if (D_800C9048 < level) {
        emitter->level = D_800C9048;
    } else if (level < (&D_800C9048)[1]) {
        emitter->level = (&D_800C9048)[1];
    }
    emitter->lastDistance = emitter->distance;
}
