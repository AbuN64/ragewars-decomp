#include "span_1000/code_802B243C.h"



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
