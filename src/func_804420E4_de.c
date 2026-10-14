#include "span_16E000/code_8043F69C.h"
#include "types.h"




extern char *func_8043F290(Item_func_80441FE8_de *);


/* Forwards its four arguments to func_8043FE3C_de with what func_8043F290 returns for the object as the fifth and a one as the sixth. Adapted from func_8044208C_de with the fifth argument taken from func_8043F290 and a one as the sixth changed. */

extern void func_8043FE3C_de(Item_func_80441FE8_de *, s32, s32, s32, s32, s32);

void func_804420E4_de(Item_func_80441FE8_de *object, s32 second, s32 third, s32 fourth) {
#if defined(VERSION_DE)
    func_8043FE3C_de(object, second, third, fourth, (s32)func_8043F290(object), 1);
#else
    func_8043FE3C_de(object, second, third, fourth, (s32)
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_8043F290
#else
func_8043F114_de
#endif
(object), 1);
#endif
}
