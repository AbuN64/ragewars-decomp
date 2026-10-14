#include "span_16E000/code_80412270.h"
/* Releases a resource object's buffers through func_802547E4_de (the one at 0x18 when flag 1 is set, the
   one at 0x14 when flag 2 is set and its size at 0x10 is positive) and clears its 32 bytes. */


extern void func_802547E4_de(void *);
extern void func_802A0748_de(void *, int, int);

void func_80413404_de(Resource_func_80413404_de *res) {
    if (res->flags & 1) {
        func_802547E4_de(res->handle);
    }
    if ((res->flags & 2) && res->size > 0) {
        func_802547E4_de(res->data);
    }
    func_802A0748_de(res, 0, 32);
}
