#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043962C.h"
#include "types.h"

/* Returns by value the three-word vector at offset 0x10 of an object. */




struct Triple func_80439CDC_de(struct ObjectRecAt10 *object) {
    return object->vector;
}
