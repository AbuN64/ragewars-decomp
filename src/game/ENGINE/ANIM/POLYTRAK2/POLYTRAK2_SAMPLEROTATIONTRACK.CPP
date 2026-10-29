#include "include_asm.h"
#include "COMMON/LONE/MOTION_TRACK_DECODE_RANGE_END.H"
#include "COMMON/STREAM.H"
#include "GAME/SOUNDINFO.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PPDECOM_UNPACKRESOURCE.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "SYSTEM/POLYTRAK2_INTERPOLATEJOINTQUATERNION.H"

static __inline__ f32 unsignedFloat(u32 value,const f64 *bias) {
    f64 result=(f64)(s32)value;
    if((s32)value<0) result+=*bias;
    return (f32)result;
}

#include "TYPES.H"
#include "SYSTEM/BITARRAY_SAMPLE_EVALUATION.H"
#include "RENDER/SETN64_GETPACKSECTION.H"


/* Fills a three-float sample for an animation track: either the stored constant vector or a linear blend
 * of the two keys around the time. */


void Polytrak2_SampleVectorTrack(AnimRef *anim, s32 index, f32 time, CVector3 *out) {
    void *root;
    void *tracks;
    AnimTrack *track;
    f32 length;
    f32 rate;
    f32 position;
    f32 frac;
    f32 *frames;
    f32 *dest;
    s32 key;
    s32 first;
    s32 second;
    u32 span;
    s32 i;

    root = *anim->data;
    tracks = SetN64_GetPackSection(root, 5);
    track = SetN64_GetPackSection(tracks, 0);
    { AnimKeyTable *keys=SetN64_GetPackSection(root,1); key=keys->entries[index].position; }
    rate = track->rate;
    length = track->length;
    position = time * rate;
    if (key == -1) {
        u8 *table = SetN64_GetPackSection(root, 2);

        s32 offset = index * *(s32 *)table + 8;
        void *sample=table+offset;
        CVector3 *vec=sample;

        *out=*vec;
    } else {
        frames = SetN64_GetPackSection(SetN64_GetPackSection(tracks, 1), key);
        frac = (position >= 0.0f) ? position-(s32)position : (f32)(s32)position==position ? position-(s32)position : position-((s32)position-1);
        dest=&out->x;
        span = anim->span;
        if (span == 0xFFFF) {
            span = 0;
        }
        first = position >= 0.0f ? (s32)position : (s32)position - ((f32)(s32)position != position);
        if (length <= (f32)first) {
            if (unsignedFloat(span,&g_rotationTrackFirstSpanTestBias)*rate <= 0.0f) {
            first = (s32)(unsignedFloat(span,&g_rotationTrackFirstSpanIndexBias)*rate);
        } else {
            f32 integer = (f32)(s32)(unsignedFloat(span,&D_800C4050_de)*rate);
            f32 value = unsignedFloat(span,&D_800C4058_de)*rate;
            first = (integer != value);
            first += (s32)(unsignedFloat(span,&g_rotationTrackFirstWrappedSpanBias)*rate);
        }
            }
        second=first+1;
        if (length <= (f32)second) {
            if (unsignedFloat(span,&g_rotationTrackSecondSpanTestBias)*rate <= 0.0f) {
            second = (s32)(unsignedFloat(span,&g_rotationTrackSecondSpanIndexBias)*rate);
        } else {
            f32 integer = (f32)(s32)(unsignedFloat(span,&D_800C4078_de)*rate);
            f32 value = unsignedFloat(span,&D_800C4080_de)*rate;
            second = (integer != value);
            second += (s32)(unsignedFloat(span,&g_rotationTrackSecondWrappedSpanBias)*rate);
        }
        }
        for (i = 0; i < 3; i++) {
            dest[i] = (g_rotationTrackInterpolationUnit - frac) * frames[first * 4 + i] + frac * frames[second * 4 + i];
        }
    }
}

extern void Graphu64_InterpolateQuaternionArc(CQuatern *out, f32 t, CQuatern *from, CQuatern *to);






extern f32 Polytrak2_ReadQuantizedFloatAndAdvance(u32 *stream, s32 bits, f32 base, f32 range);

/* Fills a four-float keyframe sample for an animation track: either the stored constant pose or an
 * interpolation between the two keys around the time. */
void Polytrak2_SampleRotationTrack(AnimRef *anim, s32 index, f32 time, CQuatern *out) {
    void *root;
    void *tracks;
    AnimTrack *track;
    f32 length;
    f32 rate;
    s32 key;
    s32 first;
    s32 second;
    CQuatern *frames;
    s32 base;
    PoseTable *pose;

    root = *anim->data;
    tracks = SetN64_GetPackSection((s32 *)root, 5);
    track = (AnimTrack *)SetN64_GetPackSection((s32 *)tracks, 0);
     { u8 *keys = (u8 *)SetN64_GetPackSection((s32 *)root, 1); base = index * 4; keys += base; key = ((KeyIndex *)keys)->rotation; }
    rate = track->rate;
    length = track->length;
    time *= rate;
    if (key == -1) {
        u8 *table = (u8 *)SetN64_GetPackSection((s32 *)root, 2);
        s32 offset = index * *(s32 *)table + 8;
        s16 *entry = (s16 *)(table + offset);
        f32 scale = D_800C4094_de;

        out->x = entry[6] * scale;
        out->y = entry[7] * scale;
        out->z = entry[8] * scale;
        out->w = entry[9] * scale;
    } else {
        frames = (CQuatern *)SetN64_GetPackSection((s32 *)SetN64_GetPackSection((s32 *)tracks, 2), key);
        if (anim->span == 0xFFFF) {
            first = (time >= 0.0f ? (s32)time : (s32)time - ((f32)(s32)time != time));
            if (length <= (f32)first) {
                first = 0;
            }
            second = first + 1;
            if (length <= (f32)second) {
                second = 0;
            }
        } else {
            first = (time >= 0.0f ? (s32)time : (s32)time - ((f32)(s32)time != time));
            if (length - g_rotationTrackFirstFrameEndBias <= (f32)first) {
                if ((unsignedFloat(anim->span,&g_rotationTrackFirstEndSpanTestBias)*rate) <= 0.0f) first = (s32)(unsignedFloat(anim->span,&g_rotationTrackFirstEndSpanIndexBias)*rate);
                else {
                    f32 integer = (f32)(s32)(unsignedFloat(anim->span,&D_800C40B0_de)*rate);
                    f32 value = unsignedFloat(anim->span,&D_800C40B8_de)*rate;
                    first = (integer != value);
                    first += (s32)(unsignedFloat(anim->span,&g_rotationTrackFirstEndWrappedSpanBias)*rate);
                }
            }
            second = first + 1;
            if (length - g_rotationTrackSecondFrameEndBias <= (f32)second) {
                if ((unsignedFloat(anim->span,&g_rotationTrackSecondEndSpanTestBias)*rate) <= 0.0f) second = (s32)(unsignedFloat(anim->span,&g_rotationTrackSecondEndSpanIndexBias)*rate);
                else {
                    f32 integer = (f32)(s32)(unsignedFloat(anim->span,&D_800C40E0_de)*rate);
                    f32 value = unsignedFloat(anim->span,&D_800C40E8_de)*rate;
                    second = (integer != value);
                    second += (s32)(unsignedFloat(anim->span,&g_rotationTrackSecondEndWrappedSpanBias)*rate);
                }
            }
        }
        Graphu64_InterpolateQuaternionArc(out, time - (f32)(time >= 0.0f ? (s32)time : (s32)time - ((f32)(s32)time != time)), frames + first, frames + second);
    }
}

void Polytrak2_DecodeScalarSamples(u32 *stream, Output8025EF54 *out, s32 count) {
    Decode8025EF54 decode;
    f32 first;
    f32 second;
    s32 i;
    f64 converted;

    decode.stream = *stream;
    if (g_motionTrackDecodeTranslation != 0) {
        decode.first_bits = Polytrak2_ReadBitsAndAdvance(&decode.stream, 0x20);
        decode.second_bits = Polytrak2_ReadBitsAndAdvance(&decode.stream, 0x20);
        first = *(f32 *)&decode.first_bits;
        second = *(f32 *)&decode.second_bits;
    } else {
        decode.first_bits = Polytrak2_ReadBitsAndAdvance(&decode.stream, 6);
        decode.second_bits = Polytrak2_ReadBitsAndAdvance(&decode.stream, 6);
        converted = (f64)decode.first_bits;
        if (decode.first_bits < 0) {
            converted += g_sampleTrackUnsignedConversionBias;
        }
        first = Polytrak2_UnpackUnitValue((f32)converted, 6);
        converted = (f64)decode.second_bits;
        if (decode.second_bits < 0) {
            converted += g_trackSectionUnsignedConversionBias;
        }
        second = Polytrak2_UnpackUnitValue((f32)converted, 6);
        first = Polytrak2_ScaleToRange(first, g_motionTrackDecodeRangeStart, g_motionTrackDecodeRangeEnd);
        second = Polytrak2_ScaleToRange(second, g_motionTrackDecodeRangeStart, g_motionTrackDecodeRangeEnd);
    }
    decode.base = first;
    decode.range = second - first;
    decode.bits = Polytrak2_ReadBitsAndAdvance(&decode.stream, 6);
    i = 0;
    if (count > 0) {
        do {
            out->value = Polytrak2_ReadQuantizedFloatAndAdvance(&decode.stream, decode.bits,
                                       decode.base, decode.range);
            i++;
            out++;
        } while (i < count);
    }
    *stream = decode.stream;
}

#if defined(VERSION_US)
#ifdef NON_MATCHING
extern char Bitarray_ExpandCurveSamples_Address[], Polytrak2_DecodeScalarSamples_Address[], Bitarray_ReadStridedFloatSamples_Address[];
/* Builds the table arg1 of arg2 rows (a count word, a byte size word and DEADBEEF-marked slots carved from the free list) and fills each row with arg3 channels of values from the generator picked by arg5 (0, 1 or 2 selects the callback); with 4 channels and a radius arg4 the columns are smoothed over a wrap-around window, and 4-channel rows are finished through Graphu64_NormalizeQuaternion. */
void Polytrak2_DecodeAndSmoothSampleTracks(s32 unused0, s32 *table, s32 trackCount, s32 componentCount, s32 smoothingRadius, s32 sampleEncoding) {
    void (*callback)(void *, void *, s32) = 0;
    s32 i, j, k, a, slot;
    s32 state[2];
    f32 *row;
    f32 sum, count;
    s32 *p;
    slot = 1;
    switch (sampleEncoding) {
    case 0:
        callback = (void (*)(void *, void *, s32))Bitarray_ExpandCurveSamples_Address;
        break;
    case 1:
        callback = (void (*)(void *, void *, s32))Polytrak2_DecodeScalarSamples_Address;
        break;
    case 2:
        callback = (void (*)(void *, void *, s32))Bitarray_ReadStridedFloatSamples_Address;
        break;
    }
    table[0] = trackCount;
    table[1] = (trackCount * 4 + 15) & ~7;
    for (i = 1; i <= trackCount; i++) {
        table[i + 1] = 0xDEADBEEF;
    }
    for (i = 0; i < trackCount; i++) {
        for (a = 0; a <= table[0] && (u32)table[a + 1] != 0xDEADBEEF; a++) {
        }
        a--;
        table[a + 2] = table[a + 1] + g_motionTrackRotationFrameCount * 16;
    }
    state[0] = Polytrak2_ByteAddressToBitAddress(0);
    for (i = 0; i < trackCount; i++) {
        row = (f32 *)SetN64_GetPackSection(table, i);
        for (j = 0; j < componentCount; j++) {
            Polytrak2_ReadBitsAndAdvance((u32 *)state, 0x1F);
            callback(state, row, g_motionTrackSourceFrameCount);
            row += 1;
        }
    }
    for (i = 0; i < trackCount; i++) {
        row = (f32 *)SetN64_GetPackSection(table, i);
        if (componentCount == 4 && smoothingRadius != 0) {
            for (j = 0; j < componentCount; j++) {
                for (k = 0; k < g_motionTrackRotationFrameCount; k++) {
                    sum = 0;
                    count = 0;
                    for (a = -smoothingRadius; a <= smoothingRadius; a++) {
                        sum += row[((k + a + g_motionTrackRotationFrameCount) % g_motionTrackRotationFrameCount) * 4 + j];
                        count += 1.0f;
                    }
                    row[k * 4 + j] = sum / count;
                }
            }
        }
    }
    if (componentCount == 4) {
        for (i = 0; i < trackCount; i++) {
            row = (f32 *)SetN64_GetPackSection(table, i);
            for (k = 0; k < g_motionTrackRotationFrameCount; k++) {
                Graphu64_NormalizeQuaternion(row);
                row += 4;
            }
        }
    }
}
#else
#if defined(VERSION_US)
INCLUDE_ASM("span_1000", Polytrak2_DecodeAndSmoothSampleTracks);
#endif
#endif
#endif

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("span_1000", Polytrak2_DecodeTrackSectionsEuX);
#endif
#endif

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("span_1000", Polytrak2_DecodeTrackSectionsEu);
#endif
#endif

#if defined(VERSION_DE)
#ifdef NON_MATCHING
extern char Bitarray_ExpandCurveSamples_Address[], Polytrak2_DecodeScalarSamples_Address[], Bitarray_ReadStridedFloatSamples_Address[];
/* Builds the table arg1 of arg2 rows (a count word, a byte size word and DEADBEEF-marked slots carved from the free list) and fills each row with arg3 channels of values from the generator picked by arg5 (0, 1 or 2 selects the callback); with 4 channels and a radius arg4 the columns are smoothed over a wrap-around window, and 4-channel rows are finished through Graphu64_NormalizeQuaternion. */
void Polytrak2_DecodeTrackSections(s32 unused0, s32 *table, s32 trackCount, s32 componentCount, s32 smoothingRadius, s32 sampleEncoding) {
    void (*callback)(void *, void *, s32) = 0;
    s32 i, j, k, a, slot;
    s32 state[2];
    f32 *row;
    f32 sum, count;
    s32 *p;
    slot = 1;
    switch (sampleEncoding) {
    case 0:
        callback = (void (*)(void *, void *, s32))Bitarray_ExpandCurveSamples_Address;
        break;
    case 1:
        callback = (void (*)(void *, void *, s32))Polytrak2_DecodeScalarSamples_Address;
        break;
    case 2:
        callback = (void (*)(void *, void *, s32))Bitarray_ReadStridedFloatSamples_Address;
        break;
    }
    table[0] = trackCount;
    table[1] = (trackCount * 4 + 15) & ~7;
    for (i = 1; i <= trackCount; i++) {
        table[i + 1] = 0xDEADBEEF;
    }
    for (i = 0; i < trackCount; i++) {
        for (a = 0; a <= table[0] && (u32)table[a + 1] != 0xDEADBEEF; a++) {
        }
        a--;
        table[a + 2] = table[a + 1] + g_motionTrackRotationFrameCount * 16;
    }
    state[0] = Polytrak2_ByteAddressToBitAddress(0);
    for (i = 0; i < trackCount; i++) {
        row = (f32 *)SetN64_GetPackSection(table, i);
        for (j = 0; j < componentCount; j++) {
            Polytrak2_ReadBitsAndAdvance((u32 *)state, 0x1F);
            callback(state, row, g_motionTrackSourceFrameCount);
            row += 1;
        }
    }
    for (i = 0; i < trackCount; i++) {
        row = (f32 *)SetN64_GetPackSection(table, i);
        if (componentCount == 4 && smoothingRadius != 0) {
            for (j = 0; j < componentCount; j++) {
                for (k = 0; k < g_motionTrackRotationFrameCount; k++) {
                    sum = 0;
                    count = 0;
                    for (a = -smoothingRadius; a <= smoothingRadius; a++) {
                        sum += row[((k + a + g_motionTrackRotationFrameCount) % g_motionTrackRotationFrameCount) * 4 + j];
                        count += 1.0f;
                    }
                    row[k * 4 + j] = sum / count;
                }
            }
        }
    }
    if (componentCount == 4) {
        for (i = 0; i < trackCount; i++) {
            row = (f32 *)SetN64_GetPackSection(table, i);
            for (k = 0; k < g_motionTrackRotationFrameCount; k++) {
                Graphu64_NormalizeQuaternion(row);
                row += 4;
            }
        }
    }
}
#else
INCLUDE_ASM("span_1000", Polytrak2_DecodeTrackSections);
#endif
#endif

#if defined(VERSION_US_REV1)
#include "TYPES.H"

#include "COMMON/STREAM.H"
#include "SYSTEM/BITARRAY_SAMPLE_EVALUATION.H"

/* Expand each encoded track, optionally smooth its four channels in place,
 * then normalize quaternion samples. */
extern char Bitarray_ExpandCurveSamples_AddressUsRev1[], Polytrak2_DecodeScalarSamples_AddressUsRev1[], Bitarray_ReadStridedFloatSamples_AddressUsRev1[];
typedef struct {
    s32 count;
    s32 offsets[1];
} AnimationSampleTable;

s32 Polytrak2_ExpandAnimationTracks(s32 source, AnimationSampleTable *buffer, s32 tracks, s32 channels, s32 radius, s32 encoding) {
    void (*decode)(void *, void *, s32) = 0;
    s32 stream[2];
    s32 *cursor;
    s32 i, index, j, offset, frames;
    f32 *out;
    f32 total, weight;
    switch (encoding) {
    case 0:
        decode = (void (*)(void *, void *, s32))Bitarray_ExpandCurveSamples_AddressUsRev1;
        break;
    case 1:
        decode = (void (*)(void *, void *, s32))Polytrak2_DecodeScalarSamples_AddressUsRev1;
        break;
    case 2:
        decode = (void (*)(void *, void *, s32))Bitarray_ReadStridedFloatSamples_AddressUsRev1;
        break;
    }
    buffer->count = tracks;
    buffer->offsets[0] = (tracks * 4 + 15) & ~7;
    for (index = 1; index <= tracks; index++) {
        buffer->offsets[index] = 0xDEADBEEF;
    }
    for (i = 0; i < tracks; i++) {
        for (index = 0; index <= buffer->count && (u32)buffer->offsets[index] != 0xDEADBEEF; index++) {
        }
        index--;
        buffer->offsets[index + 1] = buffer->offsets[index] + g_motionTrackRotationFrameCount * 16;
    }
    stream[0] = Polytrak2_ByteAddressToBitAddress(source);
    i = 0;
    if (tracks > 0) {
        cursor = stream;
        do {
            f32 *values = (f32 *)SetN64_GetPackSection(buffer, i);
            j = 0;
            if (channels > 0) {
                out = values;
                do {
                    Polytrak2_ReadBitsAndAdvance((u32 *)cursor, 0x1F);
                    decode(cursor, out, g_motionTrackSourceFrameCount);
                    out += 1;
                    j++;
                } while (j < channels);
            }
            i++;
        } while (i < tracks);
    }
    for (i = 0; i < tracks; i++) {
        s32 component;
        f32 *values;
        values = (f32 *)SetN64_GetPackSection(buffer, i);
        if (channels == 4 && radius != 0) {
            for (component = 0; component < channels; component++) {
                frames = g_motionTrackRotationFrameCount;
                for (j = 0; j < frames; j++) {
                    total = 0;
                    weight = 0;
                    for (offset = -radius; offset <= radius; offset++) {
                        total += values[((j + offset + frames) % frames) * 4 + component];
                        weight += 1.0f;
                    }
                    values[j * 4 + component] = total / weight;
                }
            }
        }
    }
    if (channels == 4) {
        for (j = 0; j < tracks; j++) {
            f32 *values = (f32 *)SetN64_GetPackSection(buffer, j);
            i = 0;
            if (g_motionTrackRotationFrameCount > 0) {
                out = values;
                do {
                    Graphu64_NormalizeQuaternion(out);
                    out += 4;
                } while (++i < g_motionTrackRotationFrameCount);
            }
        }
    }
    return 1;
}
#endif
