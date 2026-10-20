#include "include_asm.h"
#include "COMMON/ALPARAM_S.H"

void func_802B53E0_de(void *arg0, void *arg1, void *arg2, int arg3) {
    struct ALFilter_s *filter = arg0;
    filter->source = 0;
    filter->handler = arg1;
    filter->setParam = (s32 (*)(void *, s32, void *))arg2;
    filter->inp = 0;
    filter->outp = 0;
    filter->type = arg3;
}

#if defined(VERSION_EU_X)
INCLUDE_DATA("span_1000", func_802B56DC_eu_x_padding_B62DC);
#endif

#if defined(VERSION_EU)
INCLUDE_DATA("span_1000", func_802B569C_eu_padding_B629C);
#endif
