#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"
#include "TYPES.H"

#include "abi.h"
#include "acmd.h"

#if defined(VERSION_US)

Acmd *func_802B3D30_us(ALAuxBus_s *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
    Acmd *ptr = p;
    ALAuxBus_s *m = filter;
    ALFilter_s14 **sources = m->sources;
    s32 i;

    aClearBuffer(ptr++, 0x6C0, outCount << 1);
    aClearBuffer(ptr++, 0x800, outCount << 1);

    for (i = 0; i < m->sourceCount; i++) {
        ptr = sources[i]->handler(sources[i], outp, outCount, sampleOffset, ptr);
    }
    return ptr;
}
#endif

#if defined(VERSION_EU)
Acmd *func_802B40A0_eu(ALAuxBus_s *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) {
    Acmd *ptr = p;
    ALAuxBus_s *m = filter;
    ALFilter_s14 **sources = m->sources;
    s32 i;

    aClearBuffer(ptr++, 0x6C0, outCount << 1);
    aClearBuffer(ptr++, 0x800, outCount << 1);

    for (i = 0; i < m->sourceCount; i++) {
        ptr = sources[i]->handler(sources[i], outp, outCount, sampleOffset, ptr);
    }
    return ptr;
}
#endif

s32 func_802B3EDC_de(Obj_func_802B3EDC_de *bus, s32 operation, s32 source) {
    int new_var;
    s32 *base;
    s32 count;

    base = bus->base;
    if (operation == 2) {
        new_var = bus->count;
        count = new_var;
        base[count] = source;
        new_var = count + 1;
        bus->count = new_var;
    }
    return 0;
}
