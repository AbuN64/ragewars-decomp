#include "span_1000/code_802A25C4.h"
#include "types.h"

extern u32 D_800D297C;




/** Reset the object and compute its trailing-data end pointer. */
void func_802A56FC_de(void *object) {
    struct RibbonVertexPool *pool = object;
    u32 index = D_800D297C;
    pool->state = 0;
    pool->remaining = 0x12C;
    pool->next = pool->vertices[index];
}
