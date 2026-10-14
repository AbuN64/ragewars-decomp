#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041B020.h"
#include "types.h"

/* Copies record arg0 unless it already carries tag 0xB61: allocates and zeroes a 0x44-byte record, copies arg0's header and five-word block into it, tags it 0xB61, and registers it through func_8040EEA4_de and func_8040EF84_de. Adapted from func_8041B110_de with the source record passed in and the early return for a record already tagged 0xB61 added. */









extern s32 func_80299958_de(void);
extern s32 func_80411DCC_de(s32 arg0);
extern Record_func_8041B22C_de *func_8025305C_de(s32);
extern void func_802A0748_de(Record_func_8041B22C_de *, s32, s32);
extern void func_8040EEA4_de(Record_func_8041B22C_de *arg0, Record_func_8041B22C_de *arg1);
extern void func_8040EF84_de(s32 arg0, Record_func_8041B22C_de *arg1, Record_func_8041B22C_de *arg2);

void func_8041B22C_de(Record_func_8041B22C_de *source) {
    s32 context;
    Record_func_8041B22C_de *result;

    if (source->field_0E == 0xB61) {
        return;
    }
    context = func_80411DCC_de(func_80299958_de());
    result = func_8025305C_de(0x44);
    func_802A0748_de(result, 0, 0x44);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB61;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    func_8040EEA4_de(source, result);
    source->field_0C = -1;
    func_8040EF84_de(context, source, result);
}
