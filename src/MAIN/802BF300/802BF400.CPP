#include "MAIN/802BF300.H"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BA23C.h"
#include "TYPES.H"
#include "shared/func_802BB8B0_de_closed.h"

extern void __osRestoreInt(u32);



extern Field_void_4 *D_800D8440;

void *func_802BA310_de(void) {
    void *result = func_802BCF30_de();
    void *saved = D_800D8440->value;
    __osRestoreInt(result);
    return saved;
}
