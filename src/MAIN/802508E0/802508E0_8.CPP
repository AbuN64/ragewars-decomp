#include "TYPES.H"
#include "gfx.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BB15C.h"
#include "shared/func_802B80B4_eu_closed.h"
#include "shared/func_802BB8B0_de_closed.h"
#include "span_1000/code_802508E0.h"



extern OSMesgQueue D_80101140;
extern State802532E4 D_8010117C;


void func_80253344_de(s32 unused) {
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_a0;
    u32 temp_v0;
    s32 var_s0;
    State802532E4 *temp_s1;
    void *queueAddress;
    OSMesgQueue *receive;
    OSMesgQueue *send;

    temp_s1 = &D_8010117C;
    var_s0 = 1;
    temp_s1->active = var_s0;
    temp_s1->count += var_s0;
    temp_a0 = func_802BCF30_de();
    temp_v1 = D_8010515C + var_s0;
    D_8010515C = temp_v1;
    if (temp_v1 != var_s0) {
        __osRestoreInt(temp_a0);
        queueAddress = (char *)temp_s1 - 0x3C;
        receive = queueAddress;
        func_802BB2A0_de(receive, 0, var_s0);
        var_s0 = 0;
    } else {
        __osRestoreInt(temp_a0);
        var_s0 = 0;
    }
    do {
        func_802515F0_de(0, 0);
        var_s0++;
    } while (var_s0 < 10);
    temp_v0 = func_802BCF30_de();
    temp_v1_2 = D_8010515C - 1;
    D_8010515C = temp_v1_2;
    if (temp_v1_2 != 0) {
        __osRestoreInt(temp_v0);
        queueAddress = &D_80101140;
        send = queueAddress;
        func_802BB420_de(send, 0, 1);
    } else {
        __osRestoreInt(temp_v0);
    }
}

