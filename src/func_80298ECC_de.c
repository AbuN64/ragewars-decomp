#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_80299DB4.h"
#include "types.h"





extern Manager_func_80298ECC_de *D_8014D080;
extern void func_80297EA4_de(s32 arg0);

extern void func_80411E18_de(s16 arg0);




void func_80298ECC_de(void) {
    s32 index;

    if (D_8014D080->entries[D_8014D080->index].object != 0) {
        func_80297EA4_de(D_8014D080->entries[D_8014D080->index - 1].field4);
        func_80299C80_de(&D_8014D080->entries[D_8014D080->index].fieldC);
        {
            Element *element = D_8014D080->entries[D_8014D080->index].object;
            func_80411E18_de(element->id);
        }
    }
    D_8014D080->entries[D_8014D080->index].object = 0;
    D_8014D080->entries[D_8014D080->index].field4 = 0;
    D_8014D080->entries[D_8014D080->index].field8 = 0;
    index = D_8014D080->index - 1;
    D_8014D080->index = index;
    if (index < D_8014D080->lowIndex) {
        D_8014D080->lowIndex = index;
    }
}
