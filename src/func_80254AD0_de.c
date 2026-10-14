#include "span_1000/code_802508E0.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_802536F4.h"
#include "types.h"

extern struct { void **value; } D_80100564;
extern s32 D_80100570;
extern struct { s32 value; } D_8010513C;

extern void func_80255ED8_de(void *, s32);






void func_80254AD0_de(s32 arg0, s32 arg1) {
    func_80255ED8_de((void *)&D_80100570, arg1);
    if (((Node_func_80252774_de *)arg1)->flags & 0x1000) {
        func_80255ED8_de(&((IntrusiveList *)&D_80100570)[1], arg1);
    }
    if (*(&D_80100570 - 2) == arg1) {
        *(&D_80100570 - 2) = 0;
    }
    ((Node_func_80252774_de *)arg1)->flags = 0;
    D_80100564.value[D_8010513C.value] = (void *)arg1;
    *(&D_80100570 + 0x2F3) += 1;
}
