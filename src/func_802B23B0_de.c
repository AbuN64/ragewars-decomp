#include "span_1000/code_802B243C.h"



/** Consume and return one byte from the stream pointer at offset 8. */
int func_802B23B0_de(struct ALSeq_s *stream) {
    unsigned char *cursor = stream->curPtr;
    int value = *cursor;
    stream->curPtr = cursor + 1;
    return value;
}
