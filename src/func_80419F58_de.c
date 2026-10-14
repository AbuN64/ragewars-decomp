#include "span_16E000/code_804196C0.h"
#include "types.h"

/* Calls func_80419C84_de on an object, marks it busy at offset 0x44 and copies the low byte of the
   current entry of the word array at 0x4C, selected by the index at 0x74, into offset 0x10 of the
   object at 0x78. */




extern void func_80419C84_de(struct Object_func_80419F58_de *);

void func_80419F58_de(struct Object_func_80419F58_de *object) {
    func_80419C84_de(object);
    object->busy = 1;
    object->target->value = object->entries[object->index];
}
