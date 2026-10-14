#include "span_1000/code_802A1264.h"
#include "types.h"
extern const char D_800CAF20[];
extern s32 func_802A0C08_de(void *, const char *, ...);
/* Format the stream count into its existing inline state buffer. */
void func_802A1B24_de(Record_func_802A1990_de *arg0, s32 arg1) {
    arg0->field_58 = arg1;
    func_802A0C08_de(arg0->field_60, D_800CAF20, arg1);
}
