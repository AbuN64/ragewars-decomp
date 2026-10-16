#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80213ED4.h"
#include "TYPES.H"
#include "shared/func_8021E2A0_de_closed.h"







extern void func_80214DD4_de(void *, void *, s32, void *);
extern void func_80215410_de(void *, void *, s32, void *);






void func_80216D3C_de(Input80216D3C *arg0, void *arg1, Output80216D3C *arg2, s32 arg3, s32 arg4) {
    Tracker *tracker = arg1;
    Triple first;
    Triple second;
    f32 temp_f0;
    f32 temp_f1;

    temp_f1 = tracker->targetTimer;
    if (temp_f1 > 0.0f) {
        temp_f0 = temp_f1 - D_800D2988;
        tracker->targetTimer = temp_f0;
        if (temp_f0 <= 0.0f) {
            tracker->unk78 = 0;
            tracker->targetTimer = 0.0f;
        }
    }
    if (arg3 != 0) {
        func_80214DD4_de(arg0, tracker, (s32)tracker->target, &arg2[1]);
    } else {
        Output80216D3C *out = &arg2[1];
        first = arg0->vec;
        second.x = 0;
        second.y = 0;
        second.z = 0;
        out->type = 3;
        out->unk4 = 0;
        out->unk8 = 0;
        out->first = first;
        out->second = second;
        out->unk24 = 0;
        second.y = 0;
        first.y = 0;
        out->third = first;
        out->fourth = second;
        out->unk40 = 0;
    }
    if (arg4 != 0) {
        func_80215410_de(arg0, tracker, (s32)tracker->anchor, arg2);
        return;
    }
    first = arg0->vec;
    second.x = 0;
    second.y = 0;
    second.z = 0;
    arg2->type = 3;
    arg2->unk4 = 0;
    arg2->unk8 = 0;
    arg2->first = first;
    arg2->second = second;
    arg2->unk24 = 0;
    second.y = 0;
    first.y = 0;
    arg2->third = first;
    arg2->fourth = second;
    arg2->unk40 = 0;
}
