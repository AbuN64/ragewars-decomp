#include "span_1000/code_802B243C.h"





/** Copy selected fields into the compact destination record. */
void func_802B22D8_de(void *arg0, void *arg1) {
    struct ALSeq_s *sequence = arg0;
    struct ALSeqMarker *marker = arg1;
    marker->curPtr = sequence->curPtr;
    marker->lastStatus = sequence->lastStatus;
    marker->lastTicks = sequence->lastTicks;
}
