#include "span_1000/code_802B369C.h"
#include "span_1000/code_802B53FC.h"
#include "abi.h"
#include "acmd.h"
#include "types.h"

Acmd *func_802B53FC_de(ALMainBus_s *m, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
    Acmd *ptr = p;
    ALFilter_s14_2 **sources;
    s32 i;

    aClearBuffer(ptr++, 0x440, outCount << 1);
    aClearBuffer(ptr++, 0x580, outCount << 1);

    sources = m->sources;
    for (i = 0; i < m->sourceCount; i++) {
        ptr = (*sources[i]->handler)(sources[i], outp, outCount, sampleOffset, ptr);
        aSetBuffer(ptr++, 0, 0, 0, outCount << 1);
        aMix(ptr++, 0, 0x7FFF, 0x6C0, 0x440);
        aMix(ptr++, 0, 0x7FFF, 0x800, 0x580);
    }
    return ptr;
}
