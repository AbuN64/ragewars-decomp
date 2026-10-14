#include "span_16E000/code_8043F69C.h"
#include "types.h"

/* Forwards its four arguments to func_8043FE3C_de with, as the fifth, a one-character string made
   of the byte at offset 0x17 of the object, and a zero as the sixth. */


extern void func_8043FE3C_de(struct Object_func_804420B4_de *, s32, s32, s32, u8 *, s32);

void func_804420B4_de(struct Object_func_804420B4_de *object, s32 second, s32 third, s32 fourth) {
    u8 text[2];

    text[0] = object->character;
    text[1] = 0;
    func_8043FE3C_de(object, second, third, fourth, text, 0);
}
