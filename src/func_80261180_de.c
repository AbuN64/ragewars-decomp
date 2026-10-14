#include "span_1000/code_802609CC.h"
#include "types.h"

/* Reads a sampled track from a stream: parses its header through func_8025FFB0_de, evaluates the track at each whole frame into the first float of consecutive 16-byte output records, and advances the stream cursor past the track's key data. */



extern void func_8025FFB0_de(Track_func_80261180_de *track, char **cursor);
extern f32 func_8026108C_de(Track_func_80261180_de *track, f32 time, s32 arg2, s32 arg3);

void func_80261180_de(char **stream, f32 *out, s32 frames)
{
    Track_func_80261180_de track;
    char *cursor;
    s32 i;

    cursor = *stream;
    func_8025FFB0_de(&track, &cursor);
    for (i = 0; i < frames; i++) {
        *out = func_8026108C_de(&track, i, 0, 0);
        out += 4;
    }
    cursor += track.stride * (track.keys * 4 + 6);
    *stream = cursor;
}
