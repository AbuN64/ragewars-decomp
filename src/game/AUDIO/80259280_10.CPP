#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LISTNODE.H"
#include "AUDIO/80259280_10.H"

void func_80259AF0_de(void **arg0, Field_void_4 *arg1) {
    *(void **)arg1 = *arg0;
    arg1->value = arg0;
    ((Field_void_4 *)((*arg0)))->value = arg1;
    *arg0 = arg1;
}
