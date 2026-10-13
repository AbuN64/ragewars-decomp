#include "span_1000/code_802A25C4.h"
#include "types.h"

s32 func_802A56C4_de(void *arg0, s32 arg1)
{
    struct RibbonVertexPool *pool = arg0;
    s32 avail;
    s32 head;

    avail = pool->remaining;
    if (avail < arg1) {
        return 0;
    }
    head = (s32)pool->next;
    pool->remaining = avail - arg1;
    pool->next += arg1;
    return head;
}
