#include "include_asm.h"
#include "COMMON/ALPARAM_S.H"

void alFilterNew(void *filterStorage, void *pullHandler, void *parameterHandler, int filterType) {
    struct ALFilter_s *filter = filterStorage;
    filter->source = 0;
    filter->handler = pullHandler;
    filter->setParam = (s32 (*)(void *, s32, void *))parameterHandler;
    filter->inp = 0;
    filter->outp = 0;
    filter->type = filterType;
}

#if defined(VERSION_EU_X)
unsigned int func_802B56DC_eu_x_padding_B62DC[1] = {
    0x02002821,
};
#endif

#if defined(VERSION_EU)
unsigned int func_802B569C_eu_padding_B629C[1] = {
    0xA6020030,
};
#endif
