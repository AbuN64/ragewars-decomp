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
unsigned int func_802B56DC_eu_x_padding_B62DC[1] = {
    0x02002821,
};
#endif

#if defined(VERSION_EU)
unsigned int func_802B569C_eu_padding_B629C[1] = {
    0xA6020030,
};
#endif
