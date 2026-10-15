#include "sdk/libgultra.h"
#include "span_1000/code_802B243C.h"
#include "types.h"

/** Consume and return one byte from the stream pointer at offset 8. */
int func_802B23B0_de(struct ALSeq_s *stream) {
    unsigned char *cursor = stream->curPtr;
    int value = *cursor;
    stream->curPtr = cursor + 1;
    return value;
}

/** Consume and return two big-endian bytes from the stream pointer at offset 8. */
s16 func_802B23C4_de(void *arg0) {
    struct ALSeq_s *stream = arg0;
    unsigned char *p;
    u32 b0;
    u32 b1;

    p = stream->curPtr;
    b0 = p[0];
    p = p + 1;
    stream->curPtr = p;
    b1 = p[0];
    stream->curPtr = p + 1;
    return (s16)((b0 << 8) | b1);
}

int func_802B23F4_de(void *arg0) {
    struct ALSeq_s *stream = arg0;
    unsigned char *p;
    unsigned int b0, b1, b2, b3;

    p = stream->curPtr;
    b0 = p[0];
    p = p + 1;
    stream->curPtr = p;
    b1 = p[0];
    stream->curPtr = p + 1;
    b2 = p[1];
    stream->curPtr = p + 2;
    b3 = p[2];
    stream->curPtr = p + 3;
    return (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
}
