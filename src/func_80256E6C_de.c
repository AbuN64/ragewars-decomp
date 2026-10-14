#include "span_1000/code_80256220.h"
#include "types.h"

extern s32 D_002571F0;
extern s32 D_80107928;
extern s32 D_80107DF0;
s32 *func_80256E6C_de(s32 **arg0) {
    if ((((struct ObjectLinksC *) ((s8 *) (&D_80107DF0)))->unk_0) == 0) {
        (((struct ObjectLinksC *) ((s8 *) (&D_80107DF0)))->unk_8) = &D_80107928;
        (((struct ObjectLinksC *) ((s8 *) (&D_80107DF0)))->unk_4) = 0;
        (((struct ObjectLinksC *) ((s8 *) (&D_80107DF0)))->unk_0) = 1U;
    }
    *arg0 = &D_80107DF0;
    return &D_002571F0;
}
