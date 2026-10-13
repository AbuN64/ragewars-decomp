#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802393F4.h"
#include "types.h"












/** Zero the object's vector fields and reset the scale field to the default. */
void func_80239D90_de(void *arg0) {
    struct Record_func_80239DE8_de *o = arg0;
    struct Channel *v0;
    struct Channel *v1;
    struct Channel *v2;
    f32 diag;

    diag = D_800C3570_de;
    v0 = &o->channels[0];
    o->triple.x = 0;
    o->triple.y = 0;
    o->triple.z = 0;
    o->value = diag;
    v0->level = 0;
    v0->state[0] = 0;
    v0->state[1] = 0;
    v0->state[2] = 0;
    v1 = &o->channels[1];
    v2 = &o->channels[2];
    v1->level = 0;
    v1->state[0] = 0;
    v1->state[1] = 0;
    v1->state[2] = 0;
    v2->level = 0;
    v2->state[0] = 0;
    v2->state[1] = 0;
    v2->state[2] = 0;
}
