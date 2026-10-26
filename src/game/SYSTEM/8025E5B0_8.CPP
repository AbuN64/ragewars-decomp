#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/STREAM.H"
#include "GAME_2/8025E520.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "SYSTEM/8025E5B0_9.H"

/* Reads one envelope segment from a bitstream, either as raw floats or as scaled table values. */





extern s32 D_8010AC80;


extern void func_8025FD74_de(Curve *arg0);

extern u32 func_802606C4_de(s32,s32);

static inline void seek(Stream *arg0, u32 arg1) {
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
            if(arg1>=var_s4 && arg1<var_s0) {
                if(var_s2!=arg0->unk28) {
                    arg0->unk24=var_s4;arg0->unk28=var_s2;func_8025FD74_de(arg0);
                }
                break;
            }
            var_s1 += temp_s6;
            var_s2++;
            var_s4=var_s0;
            sp10[var_s2]=func_802606C4_de(var_s1,6);
            var_s0+=sp10[var_s2];
        }
    }
}

static inline float evaluate(Poly p,float t) { return p.a + p.b*t + p.c*t*t + p.d*t*t*t; }

void func_8025FFB0_de(Segment8025FFD0 *arg0, u32 *arg1) {
    u32 bits;
    u32 first;
    u32 second;
    f32 lo;
    f32 hi;

    bits = *arg1;
    arg0->unk2C = func_802607B8_de(&bits, 6);
    if (D_8010AC78 != 0) {
        first = func_802607B8_de(&bits, 0x20);
        second = func_802607B8_de(&bits, 0x20);
        lo = *(f32 *)&first;
        hi = *(f32 *)&second;
    } else {
        first = func_802607B8_de(&bits, 6);
        second = func_802607B8_de(&bits, 6);
        lo = System_UnpackUnitValue((f32)first, 6);
        hi = System_UnpackUnitValue((f32)second, 6);
        lo = ((f32 (*)(f32, f32, s32))System_ScaleToRange)(lo, D_8010AC7C, D_8010AC80);
        hi = ((f32 (*)(f32, f32, s32))System_ScaleToRange)(hi, D_8010AC7C, D_8010AC80);
    }
    arg0->unk4 = lo;
    arg0->unk8 = hi - lo;
    do {
        arg0->unk0 = func_802607B8_de(&bits, 6);
        arg0->unk28 = 0;
        arg0->unk24 = 0;
        arg0->unkC = bits;
        func_8025FD74_de(arg0);
    } while (0);
    *arg1 = bits;
}

float System_EvaluateAnimationCurve(Stream *stream, float time) {
    seek(stream, (u32)time);
    return evaluate(*(Poly *)&stream->coeff[0], time - stream->unk24);
}

#include "SYSTEM/PACKED_BIT_WORDS.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
inline static void write_bits(u32 value, u32 bitAddress, u32 width)
{
  u32 address;
  s32 shift;
  s32 remaining;
  u32 highMask;
  u32 offset;
  u32 high;
  u32 low;
  u32 lowMask;
  PackedBitWords *words;
  highMask = (1 << width) - 1;
  lowMask = highMask;
  shift = bitAddress & 0x1F;
  offset = shift;
  value &= highMask;
  if (shift == 0)
  {
    low = value;
    highMask = 0;
    high = 0;
  }
  else
  {
    lowMask = highMask << offset;
    remaining = 0x20 - offset;
    highMask >>= remaining;
    low = value << offset;
    high = value >> remaining;
  }
  address = (bitAddress & 0xF0000000) | (((u32) (bitAddress & 0x0FFFFFE0)) >> 3);
  words = (PackedBitWords *) address;
  words->low = (words->low & (~lowMask)) | low;
  words->high = (words->high & (~highMask)) | high;
}
static inline void writeQuantized(u32 bitAddress, Func802608ECResult range, f32 value) {
    f32 scaled;
    s32 integral;
    s32 quantized;

    scaled = (((value - range.start) / range.delta) * (f32) ((1 << range.value) - 1)) + D_800C4168_de;
    if (scaled >= 0.0f) {
        quantized = (s32) scaled;
    } else {
        integral = (s32) scaled;
        quantized = 1;
        if ((f32) integral == scaled) {
            quantized = 0;
        }
        quantized = integral - quantized;
    }
    write_bits(quantized, bitAddress, range.value);
}

void func_8026033C_de(u32 *stream, Func802608ECResult range, f32 value) {
    writeQuantized(*stream, range, value);
    *stream += range.value;
}
