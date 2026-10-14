#include "types.h"

extern f32 D_800C4090_de;
extern void *func_8028FDB4_de(void *, s32);

typedef struct AnimTrack {
    /* 0x00 */ char pad0[0x18];
    /* 0x18 */ f32 length;
    /* 0x1C */ f32 rate;
} AnimTrack;

typedef struct AnimRef {
    /* 0x00 */ char pad0[0xC];
    /* 0x0C */ u32 span;
    /* 0x10 */ void **data;
} AnimRef;

typedef struct KeyIndex {
    /* 0x00 */ char pad0[8];
    /* 0x08 */ s16 key;
    /* 0x0A */ char padA[2];
} KeyIndex;

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
    key = ((KeyIndex *)((u8 *)func_8028FDB4_de(root, 1) + index * 4))->key;
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

