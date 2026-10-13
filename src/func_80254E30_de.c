#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80254CE4.h"
#include "types.h"
#include "span_1000/code_802508E0.h"

extern s32 D_801010F8;
extern void func_80255ED8_de(void *, s32);
extern s32 func_80255CB8_de(void *, s32);






void *func_80254E30_de(void) {
    void **p = &D_801010F8;
    void *temp_s0 = *p;
    if (temp_s0 != 0) {
        func_80255ED8_de(p, (s32) temp_s0);
        ((Request_func_80251F6C_de *)temp_s0)->flags = 1;
        func_80255CB8_de(((char *)p + sizeof(IntrusiveList)), (s32) temp_s0);
    }
    return temp_s0;
}
