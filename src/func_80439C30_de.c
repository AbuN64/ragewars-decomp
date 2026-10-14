#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043962C.h"
#include "types.h"

/* Stores a three-word vector passed by value into offset 0x28 of an object. */




void func_80439C30_de(struct ObjectRecAt28 *object, struct Triple vector) {
    object->vector = vector;
}
