#include "common/types_06e4f7ef1f9e.h"
#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Stores a mode at offset 0x58 of an object and plays sound 0xE77 for mode 1 or 0xE76 for mode 2
   through func_8025DF34_de. */


extern void func_8025DF34_de(s32);

void func_8041A430_de(struct func_8022FD9C_S4 *object, s32 mode) {
    object->unk58 = mode;
    switch (mode) {
    case 1:
        func_8025DF34_de(0xE77);
        break;
    case 2:
        func_8025DF34_de(0xE76);
        break;
    }
}
