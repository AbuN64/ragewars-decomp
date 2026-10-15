#include "span_16E000/code_8043962C.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "stddef.h"
#include "types.h"

/* Initializes the six object parameters and clears its transient state. */
void func_80439C80_de();

 /* extern */
void func_80439CD4_de(void *, s32);

 /* extern */
s32 func_80439B5C_de(State_func_80439B5C_de *arg0, s32 arg1, Triple first, Triple second) {
    arg0->second = second;
    arg0->first = first;
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk24 = 0;
    arg0->unk28 = 0;
    arg0->unk2C = 0;
    arg0->unk30 = 0;
    func_80439C80_de();
    func_80439CD4_de(arg0, 0);
    return arg0->unk34;
}

/* Stores a three-word vector passed by value into offset 0x1C of an object. */




void func_80439BE0_de(struct ObjRecAt1CV3 *object, struct Triple vector) {
    object->unk1C = vector;
}

/* Returns by value the three-word vector at offset 0x1C of an object. */




struct Triple func_80439C0C_de(struct ObjRecAt1CV3 *object) {
    return object->unk1C;
}

/* Stores a three-word vector passed by value into offset 0x28 of an object. */




void func_80439C30_de(struct ObjectRecAt28 *object, struct Triple vector) {
    object->vector = vector;
}

/* Returns by value the three-word vector at offset 0x28 of an object. */




struct Triple func_80439C5C_de(struct ObjectRecAt28 *object) {
    return object->vector;
}
