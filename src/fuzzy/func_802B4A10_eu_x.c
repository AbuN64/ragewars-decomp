#include "TYPES.H"
#include "acmd.h"

typedef struct DraftAudioVoice { char pad0[0xD8]; s32 offset; } DraftAudioVoice;
typedef struct DraftAudioEvent {
    struct DraftAudioEvent *next;
    s32 delta;
    s16 type, flag;
    union {
        s32 word;
        DraftAudioVoice *voice;
        struct { s16 unused, pan; } panChange;
        struct { s32 pitch; s16 volume; u8 pan, fx; s32 duration; s32 sound; } start;
        struct { s32 value, duration; } volume;
    } data;
} DraftAudioEvent;
typedef struct DraftEnv {
    struct DraftEnv *source;
    void *handler;
    s32 (*setParam)(void *, s32, s32);
    s16 inp, outp;
    s32 type;
    void *state;
    s16 pan, volume, cvolL, cvolR, dryamt, wetamt;
    u16 lratl;
    s16 lratm, ltgt;
    u16 rratl;
    s16 rratm, rtgt;
    s32 delta, segEnd, first;
    DraftAudioEvent *ctrlList, *ctrlTail;
} DraftEnv;
extern s16 D_800D4210[128];
extern char D_800CC850[], D_800C7604[];
extern void *D_800D4070;
extern void func_802BAC50_de(const char *, const char *, s32);
extern void _freePVoice(void *, DraftAudioVoice *);
extern void __freeParam(void *);
extern Acmd *func_802B4C7C_de(void *, s16 *, s16 *, s32, s32, Acmd *);
extern f32 func_802B5288_de(f32, s32, s32, s32);

Acmd *func_802B4A10_eu_x(DraftEnv *env, s16 *unused, s32 count, s32 sampleOffset, Acmd *commands) {
    s16 input, output;
    DraftAudioEvent *event;
    DraftEnv *parent;
    s32 nextOffset, elapsed, previous;
    input = 0;
    output = 0;
    previous = sampleOffset;
    while (env->ctrlList) {
        nextOffset = env->ctrlList->delta;
        elapsed = nextOffset - previous;
        if (count < elapsed) break;
        if (elapsed < 0) func_802BAC50_de(D_800CC850, D_800C7604, 0x67);
        if (elapsed > 160) func_802BAC50_de(D_800CC850, D_800C7604, 0x68);
        switch (env->ctrlList->type) {
        case 0:
            event = env->ctrlList;
            event->data.voice->offset = 0;
            count -= elapsed;
            _freePVoice(D_800D4070, event->data.voice);
            goto remove;
        case 11:
        case 12:
        case 16:
            commands = func_802B4C7C_de(env, &input, &output, elapsed, sampleOffset, commands);
            if (env->delta < env->segEnd) {
                env->cvolL = (s32)func_802B5288_de(env->cvolL, env->delta, env->lratm, env->lratl);
                env->cvolR = (s32)func_802B5288_de(env->cvolR, env->delta, env->rratm, env->rratl);
            } else {
                env->ltgt = (env->volume * D_800D4210[env->pan]) >> 15;
                env->rtgt = (env->volume * D_800D4210[127 - env->pan]) >> 15;
                env->cvolL = env->ltgt;
                env->delta = env->segEnd;
                env->cvolR = env->rtgt;
            }
            if (env->cvolL == 0) env->cvolL = 1;
            if (env->cvolR == 0) env->cvolR = 1;
            if (env->ctrlList->type == 12) env->pan = env->ctrlList->data.panChange.pan;
            if (env->ctrlList->type == 11) {
                env->delta = 0;
                env->volume = (env->ctrlList->data.volume.value * env->ctrlList->data.volume.value) >> 15;
                env->segEnd = env->ctrlList->data.volume.duration;
            }
            event = env->ctrlList;
            if (event->type == 16) {
                env->dryamt = D_800D4210[event->data.word];
                env->wetamt = D_800D4210[127 - event->data.word];
            }
            env->first = 1;
            break;
        case 13:
            event = env->ctrlList;
            parent = env;
            if (event->flag) env->setParam(env, 8, 0);
            env->setParam(env, 5, event->data.start.sound);
            env->setParam(env, 9, 0);
            env->first = 1;
            env->delta = 0;
            env->segEnd = event->data.start.duration;
            env->volume = (event->data.start.volume * event->data.start.volume) >> 15;
            env->pan = event->data.start.pan;
            env->dryamt = D_800D4210[event->data.start.fx];
            env->wetamt = D_800D4210[127 - event->data.start.fx];
            if (event->data.start.duration == 0) {
                env->cvolL = (env->volume * D_800D4210[env->pan]) >> 15;
                env->cvolR = (env->volume * D_800D4210[127 - env->pan]) >> 15;
            } else { env->cvolL = 1; env->cvolR = 1; }
            parent = parent->source;
            if (parent) parent->setParam(parent, 7, event->data.start.pitch);
            break;
        case 14:
            event = env->ctrlList;
            if (event->flag) env->setParam(env, 8, 0);
            env->setParam(env, 5, event->data.word);
            env->setParam(env, 9, 0);
            break;
        case 15:
            commands = func_802B4C7C_de(env, &input, &output, elapsed, sampleOffset, commands);
            env->setParam(env, 4, 0);
            break;
        default:
            commands = func_802B4C7C_de(env, &input, &output, elapsed, sampleOffset, commands);
            env->setParam(env, env->ctrlList->type, env->ctrlList->data.word);
            break;
        }
        count -= elapsed;
remove:
        event = env->ctrlList;
        output += elapsed << 1;
        env->ctrlList = event->next;
        if (!env->ctrlList) env->ctrlTail = 0;
        __freeParam(event);
        previous = nextOffset;
    }
    commands = func_802B4C7C_de(env, &input, &output, count, sampleOffset, commands);
    if (env->segEnd < env->delta) env->delta = env->segEnd;
    return commands;
}
