#include "span_1000/code_802393F4.h"
void *func_8025343C_de(int a, int b, int c, void *d);
void func_802A001C_de(int a, int b, int c);

extern int D_800C32DC_de;




void func_8023A190_de(void *arg0, int arg1) {
    struct ScreenMessageOwner *owner = arg0;
    int *ret;
    int scaled;
    int first;
    scaled = arg1 << 6;
    owner->storage.count = arg1;
    ret = func_8025343C_de(0, scaled, 0x23, &D_800C32DC_de);
    owner->storage.allocation = ret;
    first = *ret;
    owner->storage.first = first;
    func_802A001C_de(first, 0, scaled);
}
