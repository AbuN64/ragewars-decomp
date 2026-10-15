#include "span_1000/code_8025E568.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "shared/func_8044DA54_de_closed.h"
#include "span_C76B0/data.h"
#include "types.h"

extern void func_80270AAC_de(Vector4f *out, f32 t, Vector4f *from, Vector4f *to);

static __inline__ f32 unsignedFloat(u32 value,const f64 *bias) {
    f64 result=(f64)(s32)value;
    if((s32)value<0) result+=*bias;
    return (f32)result;
}

extern s32 D_8010AC78;

extern f32 D_8010AC80;

extern u32 func_802607B8_de(u32 *, u32);

extern f32 func_80260650_de(f32 value, f32 lower, f32 upper);

extern f32 func_80260B80_de(u32 *stream, s32 bits, f32 base, f32 range);

/* Fills a four-float keyframe sample for an animation track: either the stored constant pose or an
 * interpolation between the two keys around the time. */
void func_8025EA1C_de(AnimRef *anim, s32 index, f32 time, Vector4f *out) {
    void *root;
    void *tracks;
    AnimTrack *track;
    f32 length;
    f32 rate;
    s32 key;
    s32 first;
    s32 second;
    Vector4f *frames;
    s32 base;
    PoseTable *pose;

    root = *anim->data;
    tracks = func_8028FDB4_de((s32 *)root, 5);
    track = (AnimTrack *)func_8028FDB4_de((s32 *)tracks, 0);
     { u8 *keys = (u8 *)func_8028FDB4_de((s32 *)root, 1); base = index * 4; keys += base; key = ((KeyIndex *)keys)->key; }
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
        frames = (Vector4f *)func_8028FDB4_de((s32 *)func_8028FDB4_de((s32 *)tracks, 2), key);
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
