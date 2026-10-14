#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802508E0.h"
#include "types.h"
/* Allocates a node from the free pool D_8010513C (as func_80254A28_de does: pops it, resets its fields,
 * stamps the current frame and links it through func_80255CB8_de with the caller's 0xC flags); when the pool
 * is empty it runs the collector func_80251328_de (keeping the 0x10-flagged kind) and retries once, returning
 * 0 when nothing could be freed. Adapted by inlining func_80254A28_de as a static helper. */



extern Pool D_8010513C;
extern void **D_80100564;

extern s32 func_80255CB8_de(void *arg0, s32 arg1);





static inline void *pool_alloc(s32 arg1) {
    struct Node_func_80251328_de *temp_s0;

    if (D_8010513C.count == 0) {
        return 0;
    }
    D_8010513C.count -= 1;
    temp_s0 = D_80100564[D_8010513C.count];
    temp_s0->flags = 0x800;
    temp_s0->references = 0;
    temp_s0->resource = 0;
    temp_s0->callback = 0;
    temp_s0->pending = 0;
    temp_s0->owner = 0;
    temp_s0->lastUsed = D_8010513C.field44;
    func_80255CB8_de((char *)&D_8010513C - 0xBCC, (s32)temp_s0);
    temp_s0->flags |= (arg1 & 0xC);
    return temp_s0;
}

void *func_802514A8_de(s32 unused0, s32 flags) {
    void *node;

    node = pool_alloc(flags);
    if (node == 0) {
        s32 keep = flags & 0x10;

        if (func_80251328_de(0, 2, keep == 0) != 0) {
            node = pool_alloc(flags);
        }
    }
    return node;
}
