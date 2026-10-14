#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802A1264.h"
#include "types.h"









extern s32 func_80299958_de(void);
extern s32 func_80411DCC_de(s32 arg0);
extern Record_func_802A1990_de *func_8040EC30_de(s32 arg0, s32 arg1);
extern Record_func_802A1990_de *func_8025305C_de(s32);
extern void func_802A0748_de(s32, s32, s32);
extern void func_802A1B24_de(void *arg0, s32 arg1);
extern void func_8040EEA4_de(Record_func_802A1990_de *arg0, Record_func_802A1990_de *arg1);
extern void func_8040EF84_de(s32 arg0, Record_func_802A1990_de *arg1, Record_func_802A1990_de *arg2);

Record_func_802A1990_de *func_802A1990_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Record_func_802A1990_de *source;
    s32 context;
    Record_func_802A1990_de *result;
    Record_func_802A1990_de *child;

    source = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 0xFFFF);
    context = func_80411DCC_de(func_80299958_de());
    result = func_8025305C_de(0x6C);
    func_802A0748_de(result, 0, 0x6C);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB65;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    child = func_8040EC30_de(context, arg1 & 0xFFFF);
    result->field_44 = child;
    child->fields_2C[3] = (s32)&result->field_60;
    result->field_4C = arg3;
    result->field_50 = arg2;
    result->field_58 = 0;
    result->field_48 = 0;
    result->field_54 = arg4;
    func_802A1B24_de(result, arg2);
    result->field_5C = 2;
    func_8040EEA4_de(source, result);
    source->field_0C = -1;
    func_8040EF84_de(context, source, result);
    return result;
}
