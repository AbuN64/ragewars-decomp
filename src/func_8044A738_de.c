#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8044ACCC.h"
/* Detaches the object at offset 0xC of an owner: when there is one, finalises it through
   func_8044A170_de and removes it from the lists at offsets 0xC and 0x20 through func_80255ED8_de and
   func_80255D14_de. Returns the object. */


extern void func_8044A170_de(void *);
extern void func_80255ED8_de(void *, void *);




void *func_8044A738_de(struct Draw *owner) {
    void *object = owner->model;

    if (object != 0) {
        func_8044A170_de(object);
        func_80255ED8_de(&owner->model, object);
        func_80255D14_de(&owner->recycled, object);
    }
    return object;
}
