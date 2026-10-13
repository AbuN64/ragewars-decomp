#include "span_1000/code_802393F4.h"
#include "types.h"

extern void *func_8025343C_de(int a, int b, int c, void *d);
extern void *func_802A001C_de(void *, s32, u32);

extern int D_800C32D0_de;




void func_8023A114_de(void *arg0, s32 arg1) {
    MessageBuffer *buffer = arg0;
    s32 *ret;
    s32 scaled;
    s32 first;

    scaled = arg1 * 0xED8;
    buffer->count = arg1;
    ret = func_8025343C_de(0, scaled, 0x23, (char *)&D_800C32D0_de + 4);
    buffer->allocation = ret;
    first = *ret;
    buffer->first = first;
    func_802A001C_de(first, 0, scaled);
}
