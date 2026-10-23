#include "include_asm.h"
#include "COMMON/ALPARAM_S.H"
#include "abi.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "SDK/OSINT/802C0CB0.H"
#include "AUDIO_3/802BFD40.H"

#if defined(VERSION_DE)
#define ENVPULL_NAME func_802B4730_de
#define ENVPULL_FILE D_800C7600
extern char D_800C7600[];
#elif defined(VERSION_EU)
#define ENVPULL_NAME func_802B49D0_eu
#define ENVPULL_FILE D_800CC850
#else
#define ENVPULL_NAME func_802B4A10_eu_x
#define ENVPULL_FILE D_800CC850
#endif
#ifdef NON_MATCHING
/* 94/339 words aligned (same size); remaining: register allocation (127 hoisted into a saved reg, env/count/offset regs permuted) and the jump table stays in rodata */
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
extern void _freePVoice(void *, DraftAudioVoice *);
extern void __freeParam(void *);
extern Acmd *func_802B4C7C_de(void *, s16 *, s16 *, s32, s32, Acmd *);
extern f32 func_802B5288_de(f32, s32, s32, s32);

Acmd *ENVPULL_NAME(DraftEnv *env, s16 *unused, s32 count, s32 sampleOffset, Acmd *commands) {
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
        if (elapsed < 0) func_802BAC50_de(ENVPULL_FILE, D_800C7604, 0x67);
        if (elapsed > 160) func_802BAC50_de(ENVPULL_FILE, D_800C7604, 0x68);
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
                env->rtgt = (env->volume * D_800D4210[128 - env->pan - 1]) >> 15;
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
                env->wetamt = D_800D4210[128 - event->data.word - 1];
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
            env->wetamt = D_800D4210[128 - event->data.start.fx - 1];
            if (event->data.start.duration == 0) {
                env->cvolL = (env->volume * D_800D4210[env->pan]) >> 15;
                env->cvolR = (env->volume * D_800D4210[128 - env->pan - 1]) >> 15;
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
#else
#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_802B4730_de);
#elif defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_802B49D0_eu);
#else
INCLUDE_ASM("span_1000", func_802B4A10_eu_x);
#endif
#endif

/* _pullSubFrame, drafted from ultralib src/audio/env.c: when the envelope mixer is playing, pull
   its source and append the buffer, volume and envelope-mixer commands for one subframe,
   recomputing the ramp targets and rates on the first pull after a change. */
extern s16 D_800D4210[128]; /* eqpower */
extern char D_800CC850[]; /* Resident "EX" assertion expression. */
extern char D_800C7604[]; /* "audio/env.c" */

 /* __assert */
  /* _getRate */

Acmd *func_802B4C7C_de(void *filter, s16 *inp, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p)
{
    Acmd *ptr = p;
    struct ALEnvMixer_s *e = (struct ALEnvMixer_s *)filter;
    ALFilter_s14_2 *source = e->filter.source;

    if (e->motion != 1 || !outCount)
        return ptr;

    ((source) ? ((void)0) : func_802BAC50_de(D_800CC850, D_800C7604, 366));

    ptr = (*source->handler)(source, inp, outCount, sampleOffset, p);

    aSetBuffer(ptr++, 0x00, *inp, 1088 + *outp, outCount << 1);
    aSetBuffer(ptr++, 0x08, 1408 + *outp, 1728 + *outp, 2048 + *outp);

    if (e->first) {
        e->first = 0;

        e->ltgt = (e->volume * D_800D4210[e->pan]) >> 15;
        e->lratm = func_802B4F68_de((f64)e->cvolL, (f64)e->ltgt, e->segEnd, &(e->lratl));
        e->rtgt = (e->volume * D_800D4210[128 - e->pan - 1]) >> 15;
        e->rratm = func_802B4F68_de((f64)e->cvolR, (f64)e->rtgt, e->segEnd, &(e->rratl));

        aSetVolume(ptr++, 0x02 | 0x04, e->cvolL, 0, 0);
        aSetVolume(ptr++, 0x00 | 0x04, e->cvolR, 0, 0);
        aSetVolume(ptr++, 0x02 | 0x00, e->ltgt, e->lratm, e->lratl);
        aSetVolume(ptr++, 0x00 | 0x00, e->rtgt, e->rratm, e->rratl);
        aSetVolume(ptr++, 0x08, e->dryamt, 0, e->wetamt);
        aEnvMixer(ptr++, 0x01 | 0x08, func_802BBBC0_de(e->state));
    }
    else
        aEnvMixer(ptr++, 0x00 | 0x08, func_802BBBC0_de(e->state));

    *inp += (outCount << 1);
    e->delta += outCount;

    return ptr;
}

/* _getRate: approximate per-step volume scaling using the public ultralib log table and repeated squaring. */

s16 func_802B4F68_de(f64 vol, f64 tgt, s32 count, u16 *ratel)
{
  s16 s;
  f64 invn = (1.0f) / ((f32) count);
  f64 eps;
  f64 a;
  f64 fs;
  f64 new_var;
  f64 mant;
  s32 i_invn;
  s32 ex;
  s32 indx;
  if (count == 0)
  {
    if (tgt >= vol)
    {
      *ratel = 0xffff;
      return 0x7fff;
    }
    else
    {
      *ratel = 0;
      return 0;
    }
  }
  if (tgt < (1.0))
  {
    tgt = (1.0);
  }
  if (vol <= (0.0))
  {
    vol = (1.0);
  }
  {
    LogTab logtab = { { -0.91253697872161865, -0.75207197666168213, -0.60768300294876099, -0.47643798589706421, -0.3561440110206604, -0.24511200189590454, -0.14201900362968445, -4.580400139093399e-2 } };
    f64 absvalue;
    s32 *eptr;
    i_invn = (s32) (invn * (1073741824.0));
    tgt = tgt / vol;
    eptr = &ex;
    *eptr = 0;
    if (tgt == (0.0))
    {
      vol = tgt;
    }
    else
    {
      absvalue = __builtin_fabs(tgt);
      if (absvalue >= (1.0))
      {
        do
        {
          absvalue *= (0.5);
          ++(*eptr);
        }
        while (absvalue >= (1.0));
      }
      if (absvalue < (0.5))
      {
        do
        {
          absvalue += absvalue;
          --(*eptr);
        }
        while (absvalue < (0.5));
      }
      vol = absvalue;
      if (!(tgt > (0.0)))
      {
        vol = -vol;
      }
    }
    indx = (s32) (vol * (16.0));
    absvalue = (0.69314718246459961);
    eps = ((new_var = logtab.v[indx - 8]) + ex) * absvalue;
    mant = (1073741824.0); eps /= mant; fs = eps + (1.0); a = (1.0);
    while (i_invn)
    {
      if (i_invn & 1)
      {
        a = a * fs;
      }
      fs *= fs;
      i_invn >>= 1;
    }

  }
  if (vol)
  {
    a *= (a *= (a *= a));
    s = (s16) a;
    *ratel = (s16) ((a - ((f32) s)) * (65535.0));
    return (s16) a;
  }
  else
  {
    a *= (a *= (a *= a));
    s = (s16) a;
    *ratel = (s16) ((a - ((f32) s)) * (65535.0));
    return (s16) a;
  }
}

/* alEnvmixerParam, drafted from ultralib src/audio/env.c: apply one parameter to the envelope
   mixer, appending an update to the control list, resetting or starting the filter, setting its
   source, and otherwise passing the parameter down to the source. The parameter identifiers are
   the cartridge's own 1, 3, 4 and 9. */
s32 func_802B51B8_de(void *filter, s32 paramID, void *param)
{
    ALFilter_s *f = (ALFilter_s *)filter;
    ALEnvMixer *e = (ALEnvMixer *)filter;

    switch (paramID) {

      case (3):
          if (e->ctrlTail) {
              e->ctrlTail->next = (ALParam_s *)param;
          } else {
              e->ctrlList = (ALParam_s *)param;
          }
          e->ctrlTail = (ALParam_s *)param;

          break;

      case (4):
          e->first = 1;
          e->motion = 0;
          e->volume = 1;
          if (f->source)
              (*f->source->setParam)(f->source, 4, param);
          break;

      case (9):
          e->motion = 1;
          if (f->source)
              (*f->source->setParam)(f->source, 9, param);
          break;

      case (1):
          f->source = (ALFilter_s *)param;
          break;

      default:
          if (f->source)
              (*f->source->setParam)(f->source, paramID, param);
    }
    return 0;
}

f32 func_802B5288_de(f32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    f32 base;
    f32 result;
    s32 n;
    s32 i;

    n = arg1 >> 3;
    i = 0;
    if (n == 0) {
        return arg0;
    }

    base = (f32)(arg2 << 16);
    base += (f32)(arg3 & 0xFFFF);
    base *= D_800C7708_de;
    result = D_800C770C_de;
    do {
        if (n & 1) {
            result *= base;
        }
        n >>= 1;
        i++;
        if (n == 0) {
            break;
        }
        base *= base;
    } while (i < 0x20);

    return arg0 * result;
}


f64 frexp(f64 arg0, s32 *arg2) {
    f64 value;

    *arg2 = 0;
    if (arg0 == D_800C7710_de) {
        return arg0;
    }
    value = __builtin_fabs(arg0);
    if (D_800C7718_de <= value) {
        do {
            value *= D_800C7720_de;
            *arg2 += 1;
        } while (D_800C7718_de <= value);
    }
    if (value < D_800C7728_de) {
        do {
            value += value;
            *arg2 -= 1;
        } while (value < D_800C7728_de);
    }
    if (!(D_800C7730_de < arg0)) {
        value = -value;
    }
    return value;
}

f64 func_802B53B4_de(f64 arg0, s32 arg1) {
    if (arg1 != 0) {
        arg0 = arg0 * (f64)(1 << arg1);
    }
    return arg0;
}

#if defined(VERSION_US)
unsigned int func_802B53B4_de_padding_B5F04[1] = {
    0x00000000,
};
#endif

#if defined(VERSION_US)
char rodata_unresolved_802B5308[8] =
    "\000\013Target";
#endif
