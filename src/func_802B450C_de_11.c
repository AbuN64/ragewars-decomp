#include "span_1000/code_802B4730.h"



void func_802B53E0_de(void *arg0, void *arg1, void *arg2, int arg3) {
    struct ALFilter_s *filter = arg0;
    filter->source = 0;
    filter->handler = arg1;
    filter->setParam = (s32 (*)(void *, s32, void *))arg2;
    filter->inp = 0;
    filter->outp = 0;
    filter->type = arg3;
}
