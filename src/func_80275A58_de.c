#include "span_1000/code_8027451C.h"
#include "types.h"



void func_80275A58_de(void *arg0) {
    s32 *ip = (s32 *)arg0;
    f32 *fp = (f32 *)arg0;
    f32 scale = D_800C49EC_de;
    fp[0] = (f32)ip[0] * scale;
    fp[1] = (f32)ip[1] * scale;
    fp[2] = (f32)ip[2] * scale;
    fp[3] = (f32)ip[3] * scale;
}
