#include "include_asm.h"
#include "COMMON/STREAM.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "SYSTEM/8025E5B0_9.H"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "SYSTEM/802609CC_3.H"
#include "RENDER_4/8028FD2C_6.H"

extern f32 D_800C4090_de;

/* Fills a three-float sample for an animation track: either the stored constant vector or a linear blend
 * of the two keys around the time. */
void func_8025E5B0_de(AnimRef *anim, s32 index, f32 time, f32 *out) {
    void *root;
    void *tracks;
    AnimTrack *track;
    f32 length;
    f32 rate;
    f32 position;
    f32 frac;
    f32 *frames;
    s32 key;
    s32 first;
    s32 second;
    u32 span;
    s32 i;

    root = *anim->data;
    tracks = func_8028FDB4_de(root, 5);
    track = func_8028FDB4_de(tracks, 0);
    key = ((KeyIndex *)((u8 *)func_8028FDB4_de(root, 1) + index * 4))->position;
    rate = track->rate;
    length = track->length;
    position = time * rate;
    if (key == -1) {
        u8 *table = func_8028FDB4_de(root, 2);

        s32 *vec = (s32 *)(table + index * *(s32 *)table + 8);

        ((s32 *)out)[0] = vec[0];
        ((s32 *)out)[1] = vec[1];
        ((s32 *)out)[2] = vec[2];
    } else {
        frames = func_8028FDB4_de(func_8028FDB4_de(tracks, 1), key);
        frac = position - (position >= 0.0f ? (s32)position : (s32)position - ((f32)(s32)position != position));
        span = anim->span;
        if (span == 0xFFFF) {
            span = 0;
        }
        first = position >= 0.0f ? (s32)position : (s32)position - ((f32)(s32)position != position);
        second = first + 1;
        if (length <= (f32)first) {
            first = (f32)span * rate <= 0.0f ? (s32)((f32)span * rate)
                                             : (s32)((f32)span * rate) + ((f32)(s32)((f32)span * rate) != (f32)span * rate);
            second = first + 1;
        }
        if (length <= (f32)second) {
            second = (f32)span * rate <= 0.0f ? (s32)((f32)span * rate)
                                              : (s32)((f32)span * rate) + ((f32)(s32)((f32)span * rate) != (f32)span * rate);
        }
        for (i = 0; i < 3; i++) {
            out[i] = (D_800C4090_de - frac) * frames[first * 4 + i] + frac * frames[second * 4 + i];
        }
    }
}
#else
#if !(defined(VERSION_EU))
INCLUDE_ASM("span_1000", func_8025E5B0_de);
#endif
#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_8025E574);
#endif
#endif

extern void func_80270AAC_de(CQuatern *out, f32 t, CQuatern *from, CQuatern *to);

static __inline__ f32 unsignedFloat(u32 value,const f64 *bias) {
    f64 result=(f64)(s32)value;
    if((s32)value<0) result+=*bias;
    return (f32)result;
}

extern s32 D_8010AC78;

extern f32 D_8010AC80;


extern f32 func_80260650_de(f32 value, f32 lower, f32 upper);

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
    tracks = func_8028FDB4_de((s32 *)root, 5);
    track = (AnimTrack *)func_8028FDB4_de((s32 *)tracks, 0);
     { u8 *keys = (u8 *)func_8028FDB4_de((s32 *)root, 1); base = index * 4; keys += base; key = ((KeyIndex *)keys)->rotation; }
    rate = track->rate;
    length = track->length;
    time *= rate;
    if (key == -1) {
        u8 *table = (u8 *)func_8028FDB4_de((s32 *)root, 2);
        s32 offset = index * *(s32 *)table + 8;
        s16 *entry = (s16 *)(table + offset);
        f32 scale = D_800C4094_de;

        out->x = entry[6] * scale;
        out->y = entry[7] * scale;
        out->z = entry[8] * scale;
        out->w = entry[9] * scale;
    } else {
        frames = (CQuatern *)func_8028FDB4_de((s32 *)func_8028FDB4_de((s32 *)tracks, 2), key);
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
        first = func_80260634_de((f32)converted, 6);
        converted = (f64)decode.second_bits;
        if (decode.second_bits < 0) {
            converted += D_800C4100_de;
        }
        second = func_80260634_de((f32)converted, 6);
        first = func_80260650_de(first, D_8010AC7C, D_8010AC80);
        second = func_80260650_de(second, D_8010AC7C, D_8010AC80);
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

#if defined(VERSION_US)
INCLUDE_ASM("span_1000", func_8025F074_us);
#endif

#if defined(VERSION_EU_X)
INCLUDE_ASM("span_1000", func_8025F0C4_eu_x);
#endif

#if defined(VERSION_EU)
INCLUDE_ASM("span_1000", func_8025F094_eu);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_8025F0D4_de);
#endif

#if defined(VERSION_US_REV1)
#ifdef NON_MATCHING
#include "TYPES.H"

#include "COMMON/STREAM.H"
#include "SYSTEM/802609CC_3.H"
extern f32 D_800C91F8;

/* Expand each encoded track, optionally smooth its four channels in place,
 * then normalize quaternion samples. */
s32 func_8025F0F4_us_rev1(s32 source, s32 *buffer, s32 tracks,
                        s32 channels, s32 radius, s32 encoding) {
    void (*decode)() = 0;
    u32 stream[2];
    s32 track, index, channel, sample, offset, frames;
    f32 *out;
    f32 total, weight;

    if (encoding == 0) decode = func_80261180_de;
    else if (encoding == 1) decode = func_8025EF34_de;
    else if (encoding == 2) decode = func_80261238_de;
    buffer[0] = tracks;
    buffer[1] = (tracks * 4 + 15) & ~7;
    for (index = 1; index <= tracks; index++) buffer[index + 1] = 0xDEADBEEF;
    for (track = 0; track < tracks; track++) {
        for (index = 0; index <= buffer[0]; index++) {
            if (buffer[index + 1] == (s32)0xDEADBEEF) break;
        }
        buffer[index + 1] = buffer[index] + D_8010AC88 * 16;
    }
    stream[0] = func_80260664_de(source);
    for (track = 0; track < tracks; track++) {
        out = func_8028FDB4_de(buffer, track);
        for (channel = 0; channel < channels; channel++) {
            func_802607B8_de(stream, 31);
            decode(stream, out++, D_8010AC84);
        }
    }
    for (track = 0; track < tracks; track++) {
        out = func_8028FDB4_de(buffer, track);
        frames = D_8010AC88;
        if (channels == 4 && radius != 0) {
            for (channel = 0; channel < 4; channel++) {
                for (sample = 0; sample < frames; sample++) {
                    total = 0.0f;
                    weight = 0.0f;
                    for (offset = -radius; offset <= radius; offset++) {
                        total += out[((sample + offset + frames) % frames) * 4 + channel];
                        weight += D_800C91F8;
                    }
                    out[sample * 4 + channel] = total / weight;
                }
            }
        }
    }
    if (channels == 4) {
        for (track = 0; track < tracks; track++) {
            out = func_8028FDB4_de(buffer, track);
            for (sample = 0; sample < D_8010AC88; sample++) {
                func_802741A4_de(out);
                out += 4;
            }
        }
    }
    return 1;
}
#else
INCLUDE_ASM("span_1000", func_8025F0F4_us_rev1);
#endif
#endif
