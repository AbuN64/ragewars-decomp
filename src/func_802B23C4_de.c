#include "span_1000/code_802B243C.h"
#include "types.h"




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
