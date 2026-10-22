#include "COMMON/OBJB.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"

/* Detaches the object at offset 0xC of an owner: when there is one, finalises it through
   func_8044A170_de and removes it from the lists at offsets 0xC and 0x20 through func_80255ED8_de and
   func_80255D14_de. Returns the object. */


extern void func_8044A170_de(void *);

/* Calls func_80255ED8_de on offset 0x20 of an object and func_80255CB8_de on offset 0xC with the second
   argument. */



void *func_8044A738_de(struct Draw *owner) {
    void *object = owner->model;

    if (object != 0) {
        func_8044A170_de(object);
        func_80255ED8_de(&owner->model, object);
        func_80255D14_de(&owner->recycled, object);
    }
    return object;
}

void func_8044A790_de(char *object, void *value) {
    func_80255ED8_de(object + 0x20, value);
    func_80255CB8_de(object + 0xC, value);
}
