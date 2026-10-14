#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8043962C.h"
#include "types.h"

/* Stores a three-word vector passed by value into offset 0x10 of an object. */




void func_80439D00_de(struct ObjectRecAt10 *object, struct Triple vector) {
    object->vector = vector;
}
