#include "shared/world.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"

extern char *func_8028FDB4_de(s32 *, s32);




void *func_8028D244_de(void *a, s32 b, s32 c) {
    void *r1;
    ResidentDataChunk *r2;
    s32 field;

    r1 = func_8028FDB4_de(((Shared_World *)a)->routeCount, b);
    r2 = func_8028FDB4_de(r1, 1);
    field = r2->width;
    return r2->data + (c * field);
}
