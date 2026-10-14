#include "span_1000/code_802624A0.h"


unsigned int func_8026049C_de(void *object);
void *func_8028FDB4_de(void *arg0, int arg1);

void func_80262504_de(void *arg0, void *arg1) {
    Six *result = (Six *)func_8028FDB4_de((void *)func_8026049C_de(arg0), 6);

    *(Six *)arg1 = *result;
}
