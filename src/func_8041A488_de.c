#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Clears the flag word at offset 0x5C that func_8041A47C_de sets to one. func_80423A40_de calls it on
   the object func_8041A280_de has just returned. */


void func_8041A488_de(struct Access_s32_5C *object) {
    object->field = 0;
}
