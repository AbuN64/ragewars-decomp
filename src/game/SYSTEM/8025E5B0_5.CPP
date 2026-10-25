#include "include_asm.h"
#include "COMMON/LONE/D_8010AC80.H"
#include "COMMON/STREAM.H"
#include "SYSTEM/8025E5B0.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "SYSTEM/8025E5B0_9.H"

static __inline__ f32 unsignedFloat(u32 value,const f64 *bias) {
    f64 result=(f64)(s32)value;
    if((s32)value<0) result+=*bias;
    return (f32)result;
}

#if defined(NON_MATCHING) || defined(VERSION_US_REV1)
#include "TYPES.H"
#include "SYSTEM/802609CC_3.H"
#include "RENDER_4/8028FD2C_6.H"

extern f32 D_800C4090_de;

/* Fills a three-float sample for an animation track: either the stored constant vector or a linear blend
 * of the two keys around the time. */
extern f64 D_800C4040_de, D_800C4048_de, D_800C4050_de, D_800C4058_de, D_800C4060_de, D_800C4068_de, D_800C4070_de, D_800C4078_de, D_800C4080_de, D_800C4088_de;


void System_SampleVectorTrack(AnimRef *anim, s32 index, f32 time, CVector3 *out) {
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
    tracks = Render_GetPackSection(root, 5);
    track = Render_GetPackSection(tracks, 0);
    { AnimKeyTable *keys=Render_GetPackSection(root,1); key=keys->entries[index].position; }
    rate = track->rate;
    length = track->length;
    position = time * rate;
    if (key == -1) {
        u8 *table = Render_GetPackSection(root, 2);

        s32 offset = index * *(s32 *)table + 8;
        void *sample=table+offset;
        CVector3 *vec=sample;

        *out=*vec;
    } else {
        frames = Render_GetPackSection(Render_GetPackSection(tracks, 1), key);
        frac = (position >= 0.0f) ? position-(s32)position : (f32)(s32)position==position ? position-(s32)position : position-((s32)position-1);
        dest=&out->x;
        span = anim->span;
        if (span == 0xFFFF) {
            span = 0;
        }
        first = position >= 0.0f ? (s32)position : (s32)position - ((f32)(s32)position != position);
        if (length <= (f32)first) {
            if (unsignedFloat(span,&D_800C4040_de)*rate <= 0.0f) {
            first = (s32)(unsignedFloat(span,&D_800C4048_de)*rate);
        } else {
            f32 integer = (f32)(s32)(unsignedFloat(span,&D_800C4050_de)*rate);
            f32 value = unsignedFloat(span,&D_800C4058_de)*rate;
            first = (integer != value);
            first += (s32)(unsignedFloat(span,&D_800C4060_de)*rate);
        }
            }
        second=first+1;
        if (length <= (f32)second) {
            if (unsignedFloat(span,&D_800C4068_de)*rate <= 0.0f) {
            second = (s32)(unsignedFloat(span,&D_800C4070_de)*rate);
        } else {
            f32 integer = (f32)(s32)(unsignedFloat(span,&D_800C4078_de)*rate);
            f32 value = unsignedFloat(span,&D_800C4080_de)*rate;
            second = (integer != value);
            second += (s32)(unsignedFloat(span,&D_800C4088_de)*rate);
        }
        }
        for (i = 0; i < 3; i++) {
            dest[i] = (D_800C4090_de - frac) * frames[first * 4 + i] + frac * frames[second * 4 + i];
        }
    }
}
#else
#if !(defined(VERSION_EU))
INCLUDE_ASM("span_1000", System_SampleVectorTrack);
#endif
#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_8025E574);
#endif
#endif

extern void func_80270AAC_de(CQuatern *out, f32 t, CQuatern *from, CQuatern *to);



extern s32 D_8010AC78;



extern f32 func_80260B80_de(u32 *stream, s32 bits, f32 base, f32 range);

/* Fills a four-float keyframe sample for an animation track: either the stored constant pose or an
 * interpolation between the two keys around the time. */
void func_8025EA1C_de(AnimRef *anim, s32 index, f32 time, CQuatern *out) {
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
    tracks = Render_GetPackSection((s32 *)root, 5);
    track = (AnimTrack *)Render_GetPackSection((s32 *)tracks, 0);
     { u8 *keys = (u8 *)Render_GetPackSection((s32 *)root, 1); base = index * 4; keys += base; key = ((KeyIndex *)keys)->rotation; }
    rate = track->rate;
    length = track->length;
    time *= rate;
    if (key == -1) {
        u8 *table = (u8 *)Render_GetPackSection((s32 *)root, 2);
        s32 offset = index * *(s32 *)table + 8;
        s16 *entry = (s16 *)(table + offset);
        f32 scale = D_800C4094_de;

        out->x = entry[6] * scale;
        out->y = entry[7] * scale;
        out->z = entry[8] * scale;
        out->w = entry[9] * scale;
    } else {
        frames = (CQuatern *)Render_GetPackSection((s32 *)Render_GetPackSection((s32 *)tracks, 2), key);
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
            if (length - D_800C4098_de <= (f32)first) {
                if ((unsignedFloat(anim->span,&D_800C40A0_de)*rate) <= 0.0f) first = (s32)(unsignedFloat(anim->span,&D_800C40A8_de)*rate);
                else {
                    f32 integer = (f32)(s32)(unsignedFloat(anim->span,&D_800C40B0_de)*rate);
                    f32 value = unsignedFloat(anim->span,&D_800C40B8_de)*rate;
                    first = (integer != value);
                    first += (s32)(unsignedFloat(anim->span,&D_800C40C0_de)*rate);
                }
            }
            second = first + 1;
            if (length - D_800C40C8_de <= (f32)second) {
                if ((unsignedFloat(anim->span,&D_800C40D0_de)*rate) <= 0.0f) second = (s32)(unsignedFloat(anim->span,&D_800C40D8_de)*rate);
                else {
                    f32 integer = (f32)(s32)(unsignedFloat(anim->span,&D_800C40E0_de)*rate);
                    f32 value = unsignedFloat(anim->span,&D_800C40E8_de)*rate;
                    second = (integer != value);
                    second += (s32)(unsignedFloat(anim->span,&D_800C40F0_de)*rate);
                }
            }
        }
        func_80270AAC_de(out, time - (f32)(time >= 0.0f ? (s32)time : (s32)time - ((f32)(s32)time != time)), frames + first, frames + second);
    }
}

void func_8025EF34_de(u32 *stream, Output8025EF54 *out, s32 count) {
    Decode8025EF54 decode;
    f32 first;
    f32 second;
    s32 i;
    f64 converted;

    decode.stream = *stream;
    if (D_8010AC78 != 0) {
        decode.first_bits = func_802607B8_de(&decode.stream, 0x20);
        decode.second_bits = func_802607B8_de(&decode.stream, 0x20);
        first = *(f32 *)&decode.first_bits;
        second = *(f32 *)&decode.second_bits;
    } else {
        decode.first_bits = func_802607B8_de(&decode.stream, 6);
        decode.second_bits = func_802607B8_de(&decode.stream, 6);
        converted = (f64)decode.first_bits;
        if (decode.first_bits < 0) {
            converted += D_800C40F8_de;
        }
        first = System_UnpackUnitValue((f32)converted, 6);
        converted = (f64)decode.second_bits;
        if (decode.second_bits < 0) {
            converted += D_800C4100_de;
        }
        second = System_UnpackUnitValue((f32)converted, 6);
        first = System_ScaleToRange(first, D_8010AC7C, D_8010AC80);
        second = System_ScaleToRange(second, D_8010AC7C, D_8010AC80);
    }
    decode.base = first;
    decode.range = second - first;
    decode.bits = func_802607B8_de(&decode.stream, 6);
    i = 0;
    if (count > 0) {
        do {
            out->value = func_80260B80_de(&decode.stream, decode.bits,
                                       decode.base, decode.range);
            i++;
            out++;
        } while (i < count);
    }
    *stream = decode.stream;
}

#if defined(VERSION_US) || (defined(NON_MATCHING) && (defined(VERSION_EU) || defined(VERSION_EU_X)))
#if defined(VERSION_EU)
#define func_8025F074_us func_8025F094_eu
#endif
#if defined(VERSION_EU_X)
#define func_8025F074_us func_8025F0C4_eu_x
#endif
#ifdef NON_MATCHING
extern s32 D_8010AC88, D_8010AC84;
extern f32 D_800C91F8;
extern char D_00261180_de[], D_0025EF34_de[], D_00261238_de[];
/* Builds the table arg1 of arg2 rows (a count word, a byte size word and DEADBEEF-marked slots carved from the free list) and fills each row with arg3 channels of values from the generator picked by arg5 (0, 1 or 2 selects the callback); with 4 channels and a radius arg4 the columns are smoothed over a wrap-around window, and 4-channel rows are finished through func_802741A4_de. */
void func_8025F074_us(s32 unused0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void (*callback)(void *, void *, s32) = 0;
    s32 i, j, k, a, slot;
    s32 state[2];
    f32 *row;
    f32 sum, count;
    s32 *p;
    slot = 1;
    switch (arg5) {
    case 0:
        callback = (void (*)(void *, void *, s32))D_00261180_de;
        break;
    case 1:
        callback = (void (*)(void *, void *, s32))D_0025EF34_de;
        break;
    case 2:
        callback = (void (*)(void *, void *, s32))D_00261238_de;
        break;
    }
    arg1[0] = arg2;
    arg1[1] = (arg2 * 4 + 15) & ~7;
    for (i = 1; i <= arg2; i++) {
        arg1[i + 1] = 0xDEADBEEF;
    }
    for (i = 0; i < arg2; i++) {
        for (a = 0; a <= arg1[0] && (u32)arg1[a + 1] != 0xDEADBEEF; a++) {
        }
        a--;
        arg1[a + 2] = arg1[a + 1] + D_8010AC88 * 16;
    }
    state[0] = func_80260664_de(0);
    for (i = 0; i < arg2; i++) {
        row = (f32 *)Render_GetPackSection(arg1, i);
        for (j = 0; j < arg3; j++) {
            func_802607B8_de((u32 *)state, 0x1F);
            callback(state, row, D_8010AC84);
            row += 1;
        }
    }
    for (i = 0; i < arg2; i++) {
        row = (f32 *)Render_GetPackSection(arg1, i);
        if (arg3 == 4 && arg4 != 0) {
            for (j = 0; j < arg3; j++) {
                for (k = 0; k < D_8010AC88; k++) {
                    sum = 0;
                    count = 0;
                    for (a = -arg4; a <= arg4; a++) {
                        sum += row[((k + a + D_8010AC88) % D_8010AC88) * 4 + j];
                        count += D_800C91F8;
                    }
                    row[k * 4 + j] = sum / count;
                }
            }
        }
    }
    if (arg3 == 4) {
        for (i = 0; i < arg2; i++) {
            row = (f32 *)Render_GetPackSection(arg1, i);
            for (k = 0; k < D_8010AC88; k++) {
                func_802741A4_de(row);
                row += 4;
            }
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_8025F074_us);
#endif
#endif

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("span_1000", func_8025F0C4_eu_x);
#endif
#endif

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* Drafted from the other version's body in its unit. */
#else
INCLUDE_ASM("span_1000", func_8025F094_eu);
#endif
#endif

#if defined(VERSION_DE)
#ifdef NON_MATCHING
extern s32 D_8010AC88, D_8010AC84;
extern f32 D_800C91F8;
extern char D_00261180_de[], D_0025EF34_de[], D_00261238_de[];
/* Builds the table arg1 of arg2 rows (a count word, a byte size word and DEADBEEF-marked slots carved from the free list) and fills each row with arg3 channels of values from the generator picked by arg5 (0, 1 or 2 selects the callback); with 4 channels and a radius arg4 the columns are smoothed over a wrap-around window, and 4-channel rows are finished through func_802741A4_de. */
void func_8025F0D4_de(s32 unused0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void (*callback)(void *, void *, s32) = 0;
    s32 i, j, k, a, slot;
    s32 state[2];
    f32 *row;
    f32 sum, count;
    s32 *p;
    slot = 1;
    switch (arg5) {
    case 0:
        callback = (void (*)(void *, void *, s32))D_00261180_de;
        break;
    case 1:
        callback = (void (*)(void *, void *, s32))D_0025EF34_de;
        break;
    case 2:
        callback = (void (*)(void *, void *, s32))D_00261238_de;
        break;
    }
    arg1[0] = arg2;
    arg1[1] = (arg2 * 4 + 15) & ~7;
    for (i = 1; i <= arg2; i++) {
        arg1[i + 1] = 0xDEADBEEF;
    }
    for (i = 0; i < arg2; i++) {
        for (a = 0; a <= arg1[0] && (u32)arg1[a + 1] != 0xDEADBEEF; a++) {
        }
        a--;
        arg1[a + 2] = arg1[a + 1] + D_8010AC88 * 16;
    }
    state[0] = func_80260664_de(0);
    for (i = 0; i < arg2; i++) {
        row = (f32 *)Render_GetPackSection(arg1, i);
        for (j = 0; j < arg3; j++) {
            func_802607B8_de((u32 *)state, 0x1F);
            callback(state, row, D_8010AC84);
            row += 1;
        }
    }
    for (i = 0; i < arg2; i++) {
        row = (f32 *)Render_GetPackSection(arg1, i);
        if (arg3 == 4 && arg4 != 0) {
            for (j = 0; j < arg3; j++) {
                for (k = 0; k < D_8010AC88; k++) {
                    sum = 0;
                    count = 0;
                    for (a = -arg4; a <= arg4; a++) {
                        sum += row[((k + a + D_8010AC88) % D_8010AC88) * 4 + j];
                        count += D_800C91F8;
                    }
                    row[k * 4 + j] = sum / count;
                }
            }
        }
    }
    if (arg3 == 4) {
        for (i = 0; i < arg2; i++) {
            row = (f32 *)Render_GetPackSection(arg1, i);
            for (k = 0; k < D_8010AC88; k++) {
                func_802741A4_de(row);
                row += 4;
            }
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_8025F0D4_de);
#endif
#endif

#if defined(VERSION_US_REV1)
#include "TYPES.H"

#include "COMMON/STREAM.H"
#include "SYSTEM/802609CC_3.H"
extern f32 D_800C91F8;

/* Expand each encoded track, optionally smooth its four channels in place,
 * then normalize quaternion samples. */
extern s32 D_8010AC88, D_8010AC84;
extern char D_002611A0_us_rev1[], D_0025EF54_us_rev1[], D_00261258_us_rev1[];
typedef struct {
    s32 count;
    s32 offsets[1];
} AnimationSampleTable;

s32 System_ExpandAnimationTracks(s32 source, AnimationSampleTable *buffer, s32 tracks, s32 channels, s32 radius, s32 encoding) {
    void (*decode)(void *, void *, s32) = 0;
    s32 stream[2];
    s32 *cursor;
    s32 i, index, j, offset, frames;
    f32 *out;
    f32 total, weight;
    switch (encoding) {
    case 0:
        decode = (void (*)(void *, void *, s32))D_002611A0_us_rev1;
        break;
    case 1:
        decode = (void (*)(void *, void *, s32))D_0025EF54_us_rev1;
        break;
    case 2:
        decode = (void (*)(void *, void *, s32))D_00261258_us_rev1;
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
        buffer->offsets[index + 1] = buffer->offsets[index] + D_8010AC88 * 16;
    }
    stream[0] = func_80260664_de(source);
    i = 0;
    if (tracks > 0) {
        cursor = stream;
        do {
            f32 *values = (f32 *)Render_GetPackSection(buffer, i);
            j = 0;
            if (channels > 0) {
                out = values;
                do {
                    func_802607B8_de((u32 *)cursor, 0x1F);
                    decode(cursor, out, D_8010AC84);
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
        values = (f32 *)Render_GetPackSection(buffer, i);
        if (channels == 4 && radius != 0) {
            for (component = 0; component < channels; component++) {
                frames = D_8010AC88;
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
            f32 *values = (f32 *)Render_GetPackSection(buffer, j);
            i = 0;
            if (D_8010AC88 > 0) {
                out = values;
                do {
                    func_802741A4_de(out);
                    out += 4;
                } while (++i < D_8010AC88);
            }
        }
    }
    return 1;
}
#endif
