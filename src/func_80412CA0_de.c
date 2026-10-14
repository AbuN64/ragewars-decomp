#include "span_16E000/code_80412270.h"
#include "types.h"

/* Releases an object through func_802547E4_de, first releasing the object it holds at offset 0x44
   when there is one, and returns zero. */


extern void func_802547E4_de(void *);

s32 func_80412CA0_de(struct Object_func_80412CA0_de *object) {
    struct Object_func_80412CA0_de *self = object;

    if (object->child != 0) {
        func_802547E4_de(object->child);
    }
    func_802547E4_de(self);
    return 0;
}
