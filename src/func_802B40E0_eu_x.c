#include "span_1000/code_802B369C.h"
#include "abi.h"
#include "types.h"
#include "acmd.h"
#include "abi.h"
#include "common/unused.h"

/* alAuxBusPull: clears the aux left and right output buffers, then pulls every source filter of the bus into the command list. */
Acmd *func_802B40E0_eu_x(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
    Acmd *ptr = p;
    ALAuxBus_s *m = (ALAuxBus_s *)filter;
    ALFilter_s14 **sources = m->sources;
    s32 i;

    aClearBuffer(ptr++, 0x6C0, outCount << 1);
    aClearBuffer(ptr++, 0x800, outCount << 1);

    for (i = 0; i < m->sourceCount; i++) {
        ptr = sources[i]->handler(sources[i], outp, outCount, sampleOffset, ptr);
    }
    return ptr;
}
