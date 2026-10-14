#include "span_16E000/code_8044ACCC.h"
/* Calls func_80255ED8_de on offset 0x20 of an object and func_80255CB8_de on offset 0xC with the second
   argument. */
extern void func_80255ED8_de(void *);
extern void func_80255CB8_de(void *, void *);

void func_8044A790_de(char *object, void *value) {
    func_80255ED8_de(object + 0x20);
    func_80255CB8_de(object + 0xC, value);
}
