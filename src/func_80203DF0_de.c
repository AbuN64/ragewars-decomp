#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802022E0.h"
#include "types.h"

extern void func_802738C0_de(void *arg0, f32 arg1);
extern void func_80273C68_de(void *arg0, f32 arg1);










void func_80203DF0_de(void *arg0, ObjRecAt8V1 *event) {
    ObjRecAt294 *temp_a0;
    SegmentRecAt71 *temp_s1;
    ObjRecAt294 *temp_v0;

    struct NavigationTrack *track;

    temp_a0 = event->unk8;
    track = (void *)temp_a0->unk18;
    temp_s1 = &track->segment;
    if (event->unk4 == temp_s1->yawEvent) {
        func_802738C0_de(arg0, temp_a0->unk294);
    }
    if (event->unk4 == temp_s1->orientationMode) {
        temp_v0 = event->unk8;
        func_80273C68_de(arg0,
                      temp_v0->targetHeading -
                          temp_v0->heading);
    }
}
