#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80412270.h"
#include "types.h"

/* Allocates and zeroes a 0x60-byte record, copies the header of the record func_8040EC30_de finds for the low half of the first argument, tags it 0xB, stores four byte arguments and three alternating pairs of the last two, allocates and zeroes a width-by-height table of eight-byte cells at 0x44, and registers the record through func_8040ED38_de.
   Adapted from func_8041A580_de with the record size, tag 0xB, the byte fields, the cell table and the func_8040ED38_de registration changed. */







extern s32 func_80299958_de(void);
extern s32 func_80411DCC_de(s32 arg0);
extern Record_func_80412710_de *func_8040EC30_de(s32 arg0, s32 arg1);
extern void *func_8025305C_de(s32);
extern void func_802A0748_de(void *, s32, s32);
extern void func_8040ED38_de(s32 arg0, s32 arg1, Record_func_80412710_de *arg2, Record_func_80412710_de *arg3);

s32 func_80412710_de(s32 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6) {
    Record_func_80412710_de *source;
    s32 context;
    Record_func_80412710_de *result;
    s32 size;
    void *cells;

    source = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), arg0 & 0xFFFF);
    context = func_80411DCC_de(func_80299958_de());
    result = func_8025305C_de(0x60);
    func_802A0748_de(result, 0, 0x60);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB;
    result->field_4B = arg4;
    result->field_4A = arg3;
    result->field_49 = arg2;
    result->field_48 = arg1;
    result->field_51 = arg6;
    result->field_50 = arg5;
    result->field_4F = arg6;
    result->field_4E = arg5;
    result->field_4D = arg6;
    result->field_4C = arg5;
    size = arg3 * arg4 * 8;
    cells = func_8025305C_de(size);
    result->field_44 = cells;
    func_802A0748_de(cells, 0, size);
    func_8040ED38_de(context, 0, source, result);
    return 1;
}
