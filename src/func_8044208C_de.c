#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043F69C.h"
#include "types.h"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif
#include "types.h"

/* Forwards its four arguments to func_8043FE3C_de, adding the word the object's pointer at offset
   0x14 addresses and a zero as the fifth and sixth. func_80442064_de and func_8044208C_de are the
   same function. */


extern void func_8043FE3C_de(struct Object_func_80442064_de *, s32, s32, s32, s32, s32);

void func_8044208C_de(struct Object_func_80442064_de *object, s32 second, s32 third, s32 fourth) {
    
#if defined(VERSION_EU) || defined(VERSION_EU_X)
func_8043FE3C_de(object, second, third, fourth, object->source[D_80152789], 0);
#else
func_8043FE3C_de(object, second, third, fourth, *object->source, 0);
#endif

}
