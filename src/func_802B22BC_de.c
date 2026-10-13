#include "span_1000/code_802B243C.h"





/** Copy selected fields from the compact source record. */
void func_802B22BC_de(ALSeq_s *arg0, ALSeqMarker *arg1) {
    arg0->curPtr = arg1->curPtr;
    arg0->lastStatus = arg1->lastStatus;
    arg0->lastTicks = arg1->lastTicks;
}
