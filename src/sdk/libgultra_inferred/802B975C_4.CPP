#include "span_1000/code_802B4730.h"
#include "abi.h"
#include "acmd.h"
#include "audio_callbacks.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/abi.h"
#include "span_1000/code_802B369C.h"
#include "TYPES.H"

unsigned char D_auto_func_802B5674_eu_padding_B6274[12] = { 0xAF, 0xB0, 0x00, 0x18, 0x00, 0x80, 0x80, 0x21, 0xAF, 0xB1, 0x00, 0x1C };

Acmd *func_802B56A0_eu(ALMainBus_s *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
    Acmd *ptr = p;
    ALMainBus_s *m = filter;
    ALFilter_s14 **sources = m->sources;
    s32 i;

    aClearBuffer(ptr++, 0x440, outCount << 1);
    aClearBuffer(ptr++, 0x580, outCount << 1);

    for (i = 0; i < m->sourceCount; i++) {
        ptr = sources[i]->handler(sources[i], outp, outCount, sampleOffset, ptr);
        aSetBuffer(ptr++, 0, 0, 0, outCount << 1);
        aMix(ptr++, 0, 0x7FFF, 0x6C0, 0x440);
        aMix(ptr++, 0, 0x7FFF, 0x800, 0x580);
    }
    return ptr;
}
