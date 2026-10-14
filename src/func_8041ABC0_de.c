#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041A4B0.h"
#include "types.h"

/* Allocates and zeroes a 0x118-byte record, copies the header and five-word block of the record func_8040EC30_de finds for the low half of the first argument, links the record func_8040EC30_de finds for the second into it, clears the words at 0x110 and 0x114, and registers it through func_8040EEA4_de and func_8040EF84_de. Adapted from func_8041A580_de with the record size 0x118, the tag 0xB64 and the tail fields changed. */









extern s32 func_80299958_de(void);
extern s32 func_80411DCC_de(s32 arg0);
extern Record_func_8041ABC0_de *func_8040EC30_de(s32 arg0, s32 arg1);
extern Record_func_8041ABC0_de *func_8025305C_de(s32);
extern void func_802A0748_de(Record_func_8041ABC0_de *, s32, s32);
extern void func_8040EEA4_de(Record_func_8041ABC0_de *arg0, Record_func_8041ABC0_de *arg1);
extern void func_8040EF84_de(s32 arg0, Record_func_8041ABC0_de *arg1, Record_func_8041ABC0_de *arg2);

Record_func_8041ABC0_de *func_8041ABC0_de(s32 arg0, s32 arg1) {
    Record_func_8041ABC0_de *source;
    s32 context;
    Record_func_8041ABC0_de *result;
    Record_func_8041ABC0_de *child;

    source = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 0xFFFF);
    context = func_80411DCC_de(func_80299958_de());
    result = func_8025305C_de(0x118);
    func_802A0748_de(result, 0, 0x118);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB64;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    child = func_8040EC30_de(context, arg1 & 0xFFFF);
    result->field_44 = child;
    result->field_110 = 0;
    result->field_114 = 0;
    func_8040EEA4_de(source, result);
    source->field_0C = -1;
    func_8040EF84_de(context, source, result);
    return result;
}
