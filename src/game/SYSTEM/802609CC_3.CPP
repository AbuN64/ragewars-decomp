#include "COMMON/LOCALDECODERANGE.H"
#include "SYSTEM/802609CC.H"
#include "SYSTEM/8025E5B0.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "SYSTEM/802609CC_3.H"
#include "SYSTEM/8025E5B0_9.H"
#include "RENDER_4/8028FD2C_6.H"

/* Reads a sampled track from a stream: parses its header through func_8025FFB0_de, evaluates the track at each whole frame into the first float of consecutive 16-byte output records, and advances the stream cursor past the track's key data. */



extern void func_8025FFB0_de(Track_func_80261180_de *track, char **cursor);

extern f32 System_SampleAnimationCurve(Track_func_80261180_de *track, f32 time, s32 unusedFirst, s32 unusedSecond);



#if defined(VERSION_EU)
extern s32 func_8025F094_eu(void *, void *, s32, s32, s32, s32);
#elif defined(VERSION_EU_X)
extern s32 func_8025F0C4_eu_x(void *, void *, s32, s32, s32, s32);
#elif defined(VERSION_US)
extern s32 func_8025F074_us(void *, void *, s32, s32, s32, s32);
#elif defined(VERSION_US_REV1)
extern s32 System_ExpandAnimationTracks(void *, void *, s32, s32, s32, s32);
#else
extern s32 func_8025F0D4_de(void *, void *, s32, s32, s32, s32);
#endif

extern f32 D_8010AC80;

extern s32 D_8010AC78;

extern s32 D_8010AC74;

/* Seeks the containing frame in a variable-length stream and reloads it when the frame changes. */

extern void func_8025FD74_de(Curve *arg0);

extern u32 func_802606C4_de(s32,s32);

extern f32 D_800C41A8_de[2];

void func_80261180_de(char **stream, f32 *out, s32 frames)
{
    Track_func_80261180_de track;
    char *cursor;
    s32 i;

    cursor = *stream;
    func_8025FFB0_de(&track, &cursor);
    for (i = 0; i < frames; i++) {
        *out = System_SampleAnimationCurve(&track, i, 0, 0);
        out += 4;
    }
    cursor += track.stride * (track.keys * 4 + 6);
    *stream = cursor;
}

void func_80261238_de(s32 arg0, void *arg1, s32 arg2)
{
  int new_var;
  s32 sp10;
  s32 var_s0;
  u8 *var_s1;
  new_var = 0;
  var_s0 = new_var;
  if (arg2 > new_var)
  {
    var_s1 = (u8 *) arg1;
    do
    {
      var_s0 += 1;
      sp10 = func_802607B8_de(arg0, 0x20);
      *((f32 *) var_s1) = *((f32 *) (&sp10));
      var_s1 += 0x10;
    }
    while (var_s0 < arg2);
  }
}

s32 func_802612A8_de(void *arg0, void *arg1) {
    Entry802612C8 *first;
    void *a;
    void *b;
    void *c;
    void *d;
    s32 one;

    first = func_8028FDB4_de(arg0, 0);
    a = func_8028FDB4_de(arg0, 1);
    b = func_8028FDB4_de(arg0, 2);
    c = func_8028FDB4_de(arg1, 1);
    d = func_8028FDB4_de(arg1, 2);

    one = 1;
    D_8010AC78 = one;
    D_8010AC74 = 0;
    D_8010AC7C = D_800C4198_de;
    D_8010AC80 = (2000.0f);
    D_8010AC70 = first->f0C;
    if (
#if defined(VERSION_EU)
func_8025F094_eu
#elif defined(VERSION_EU_X)
func_8025F0C4_eu_x
#elif defined(VERSION_US)
func_8025F074_us
#elif defined(VERSION_US_REV1)
System_ExpandAnimationTracks
#else
func_8025F0D4_de
#endif
(a, c, first->n14, 3, first->x, first->z) == 0) {
        return 0;
    }
    D_8010AC78 = 0;
    D_8010AC74 = one;
    D_8010AC7C = D_800C41A0_de;
    D_8010AC80 = D_800C41A4_de;
    D_8010AC70 = first->f0C;
    return 
#if defined(VERSION_EU)
func_8025F094_eu
#elif defined(VERSION_EU_X)
func_8025F0C4_eu_x
#elif defined(VERSION_US)
func_8025F074_us
#elif defined(VERSION_US_REV1)
System_ExpandAnimationTracks
#else
func_8025F0D4_de
#endif
(b, d, first->n10, 4, first->x, first->z) != 0;
}

/** Return the word at offset twelve. */
int func_8026140C_de(char *object) {
    Stream *stream = (void *)object;
    return stream->unkC;
}

void func_80261418_de(Stream *arg0, u32 arg1) {
    u32 sp10[64];
    s32 temp_a0;
    s32 temp_lo;
    s32 temp_s1;
    s32 temp_s6;
    s32 var_s1;
    s32 var_s2;
    u32 *var_s3;
    u32 temp_v0;
    u32 temp_v1;
    u32 var_s0;
    u32 var_s4;

    temp_s6 = (arg0->unk0 * 4) + 6;
    temp_v1 = arg0->unk24;
    if (arg1 < temp_v1 || arg1 >= temp_v1 + arg0->unk20) {
        var_s2 = arg0->unk28;
        var_s4 = temp_v1;
        var_s0 = var_s4 + arg0->unk20;
        var_s1 = arg0->unkC;
        temp_s1=var_s1;
        var_s1 += var_s2 * temp_s6;
        if(arg1 < temp_v1) {
            var_s1=temp_s1;var_s2=0;var_s4=0;
            var_s0=func_802606C4_de(var_s1,6);
        }
        for (;;) {
            var_s1 += temp_s6;
            if(arg1>=var_s4 && arg1<var_s0) {
                if(var_s2!=arg0->unk28) {
                    arg0->unk24=var_s4;arg0->unk28=var_s2;func_8025FD74_de(arg0);
                }
                break;
            }
            var_s2++;
            var_s4=var_s0;
            sp10[var_s2]=func_802606C4_de(var_s1,6);
            var_s0+=sp10[var_s2];
        }
    }
}

s32 func_8026154C_de(f32 arg0)
{
  unsigned long long new_var;
  f32 temp_f1;
  s32 var_v1;
  var_v1 = 0;
  new_var = 1;
  temp_f1 = arg0;
  temp_f1 = (D_800C41A8_de[new_var] / (2.0f * temp_f1)) + D_800C41A8_de[new_var];
  if (D_800C41A8_de[0] <= arg0)
  {
    return 0;
  }
  if (D_800C41A8_de[new_var] < temp_f1)
  {
    do
    {
      var_v1 += 1;
    }
    while (((f32) (1 << var_v1)) < temp_f1);
  }
  return var_v1;
}

f32 func_802615B4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 unused4, f32 arg5) {
    f32 bits = *(f32 *)&arg0;
    f32 v1 = *(f32 *)&arg1;
    f32 v2 = *(f32 *)&arg2;
    f32 v3 = *(f32 *)&arg3;
    return bits + (v1 * arg5) + (v2 * arg5 * arg5) + (v3 * arg5 * arg5 * arg5);
}
