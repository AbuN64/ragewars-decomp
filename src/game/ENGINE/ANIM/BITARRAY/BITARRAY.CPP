#include "include_asm.h"
#include "COMMON/LOCALDECODERANGE.H"
#include "COMMON/LONE/D_8010AC80.H"
#include "SYSTEM/POLYTRAK2_DECODESCALARSAMPLES_DATA.H"
#include "GAME/SOUNDINFO.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "SYSTEM/802609CC_3.H"
#include "SYSTEM/POLYTRAK2_INTERPOLATEJOINTQUATERNION.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
#include "SYSTEM/BITARRAY.H"

/* ROM-grounded data: src/rw_pool_802612A8_C9E88_us_rev1.c */
const unsigned int D_blob_d39bcb9851fad48bdbd2[1] = {
    0xC4FA0000,
};

/* Reads a sampled track from a stream: parses its header through Polytrak2_InitializePackedCurve, evaluates the track at each whole frame into the first float of consecutive 16-byte output records, and advances the stream cursor past the track's key data. */

extern void Polytrak2_InitializePackedCurve(TrackBitarrayExpandCurveSamples *track, char **cursor);

extern f32 Polytrak2_SampleAnimationCurve(TrackBitarrayExpandCurveSamples *track, f32 time, s32 unusedFirst, s32 unusedSecond);

#if defined(VERSION_EU)
extern s32 func_8025F094_eu(void *, void *, s32, s32, s32, s32);
#elif defined(VERSION_EU_X)
extern s32 func_8025F0C4_eu_x(void *, void *, s32, s32, s32, s32);
#elif defined(VERSION_US)
extern s32 Polytrak2_DecodeAndSmoothSampleTracks(void *, void *, s32, s32, s32, s32);
#elif defined(VERSION_US_REV1)
extern s32 Polytrak2_ExpandAnimationTracks(void *, void *, s32, s32, s32, s32);
#else
extern s32 Polytrak2_DecodeTrackSections(void *, void *, s32, s32, s32, s32);
#endif

extern s32 D_8010AC78;

extern s32 D_8010AC74;

/* Seeks the containing frame in a variable-length stream and reloads it when the frame changes. */

extern void Polytrak2_DecodeCubicSegment(Curve *arg0);

extern u32 Polytrak2_ReadBitsAtAddress(s32,s32);

extern f32 D_800C41A8_de[2];

void Bitarray_ExpandCurveSamples(char **stream, f32 *out, s32 frames)
{
    TrackBitarrayExpandCurveSamples track;
    char *cursor;
    s32 i;

    cursor = *stream;
    Polytrak2_InitializePackedCurve(&track, &cursor);
    for (i = 0; i < frames; i++) {
        *out = Polytrak2_SampleAnimationCurve(&track, i, 0, 0);
        out += 4;
    }
    cursor += track.stride * (track.keys * 4 + 6);
    *stream = cursor;
}

void Bitarray_ReadStridedFloatSamples(s32 bitCursor, void *arg1, s32 arg2)
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
      sp10 = Polytrak2_ReadBitsAndAdvance(bitCursor, 0x20);
      *((f32 *) var_s1) = *((f32 *) (&sp10));
      var_s1 += 0x10;
    }
    while (var_s0 < arg2);
  }
}

s32 Bitarray_ExpandMotionPack(void *sourceMotionPack, void *destinationMotionPack) {
    Entry802612C8 *first;
    void *a;
    void *b;
    void *c;
    void *d;
    s32 one;

    first = SetN64_GetPackSection(sourceMotionPack, 0);
    a = SetN64_GetPackSection(sourceMotionPack, 1);
    b = SetN64_GetPackSection(sourceMotionPack, 2);
    c = SetN64_GetPackSection(destinationMotionPack, 1);
    d = SetN64_GetPackSection(destinationMotionPack, 2);

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
Polytrak2_DecodeAndSmoothSampleTracks
#elif defined(VERSION_US_REV1)
Polytrak2_ExpandAnimationTracks
#else
Polytrak2_DecodeTrackSections
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
Polytrak2_DecodeAndSmoothSampleTracks
#elif defined(VERSION_US_REV1)
Polytrak2_ExpandAnimationTracks
#else
Polytrak2_DecodeTrackSections
#endif
(b, d, first->n10, 4, first->x, first->z) != 0;
}

/** Return the word at offset twelve. */
int func_8026140C_de(char *object) {
    Stream *stream = (void *)object;
    return stream->unkC;
}

void Bitarray_SeekCurveSegment(Stream *arg0, u32 sampleIndex) {
    u32 segmentSampleCounts[64];
    s32 temp_a0;
    s32 temp_lo;
    s32 firstSegmentBitAddress;
    s32 temp_s6;
    s32 segmentBitCursor;
    s32 segmentIndex;
    u32 *var_s3;
    u32 temp_v0;
    u32 activeSegmentStart;
    u32 segmentEndSample;
    u32 segmentStartSample;

    temp_s6 = (arg0->unk0 * 4) + 6;
    activeSegmentStart = arg0->unk24;
    if (sampleIndex < activeSegmentStart || sampleIndex >= activeSegmentStart + arg0->unk20) {
        segmentIndex = arg0->unk28;
        segmentStartSample = activeSegmentStart;
        segmentEndSample = segmentStartSample + arg0->unk20;
        segmentBitCursor = arg0->unkC;
        firstSegmentBitAddress=segmentBitCursor;
        segmentBitCursor += segmentIndex * temp_s6;
        if(sampleIndex < activeSegmentStart) {
            segmentBitCursor=firstSegmentBitAddress;segmentIndex=0;segmentStartSample=0;
            segmentEndSample=Polytrak2_ReadBitsAtAddress(segmentBitCursor,6);
        }
        for (;;) {
            segmentBitCursor += temp_s6;
            if(sampleIndex>=segmentStartSample && sampleIndex<segmentEndSample) {
                if(segmentIndex!=arg0->unk28) {
                    arg0->unk24=segmentStartSample;arg0->unk28=segmentIndex;Polytrak2_DecodeCubicSegment(arg0);
                }
                break;
            }
            segmentIndex++;
            segmentStartSample=segmentEndSample;
            segmentSampleCounts[segmentIndex]=Polytrak2_ReadBitsAtAddress(segmentBitCursor,6);
            segmentEndSample+=segmentSampleCounts[segmentIndex];
        }
    }
}

s32 Bitarray_GetQuantizationBitCount(f32 arg0)
{
  unsigned long long new_var;
  f32 temp_f1;
  s32 bitCount;
  bitCount = 0;
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
      bitCount += 1;
    }
    while (((f32) (1 << bitCount)) < temp_f1);
  }
  return bitCount;
}

f32 Bitarray_EvaluateCubicPolynomial(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 unused4, f32 arg5) {
    f32 bits = *(f32 *)&arg0;
    f32 v1 = *(f32 *)&arg1;
    f32 v2 = *(f32 *)&arg2;
    f32 v3 = *(f32 *)&arg3;
    return bits + (v1 * arg5) + (v2 * arg5 * arg5) + (v3 * arg5 * arg5 * arg5);
}

/** Return the low five bits of the supplied value. */
unsigned int Bitarray_GetWordBitOffset(unsigned int value) {
    return value & 0x1F;
}

u32 Bitarray_GetRequiredBitCount(s32 arg0) {
    u32 var_a1;
    u32 highestSetBit;
    u32 var_v1;

    var_a1 = 0;
    highestSetBit = 0;
    var_v1 = 0;
    do {
        if (arg0 & (u32)(1 << var_v1)) {
            var_a1 += 1;
            highestSetBit = var_v1;
        }
        var_v1 += 1;
    } while (var_v1 < 0x20U);
    if (var_a1 >= 2U) {
        return highestSetBit + 1;
    }
    return highestSetBit;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_80261608[2] = {
    0x04000000, 0x01000400,
};
#endif

/* ROM-grounded data: rodata/unresolved/800C9290 */
const unsigned int D_blob_5472735a2d60c7e3f0e5[2] = {
    0xBF800000, 0x3F800000,
};

/* ROM-grounded data: src/rw_pool_8026154C_C9E98_us_rev1.c */
const unsigned int D_blob_30a83c3cc53f2e58e087[2] = {
    0x3F000000, 0x3F800000,
};
