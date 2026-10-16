#include "TYPES.H"

extern s32 D_8010AC84, D_8010AC88;
extern f32 D_800C91F8;
extern u32 func_80260664_de(s32);
extern u32 func_802607B8_de(u32 *, u32);
extern void *func_8028FDB4_de(s32 *, s32);
extern void func_80261180_de(void *, void *, s32);
extern void func_8025EF34_de(void *, void *, s32);
extern void func_80261238_de(void *, void *, s32);

/* Expand each encoded track, optionally smooth its four channels in place,
 * then normalize quaternion samples. */
s32 func_8025F0F4_us_rev1(s32 source, s32 *buffer, s32 tracks,
                        s32 channels, s32 radius, s32 encoding) {
    void (*decode)(void *, void *, s32) = 0;
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
