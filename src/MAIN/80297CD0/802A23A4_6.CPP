#include "span_1000/code_802A1264.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80297CD0.h"
#include "span_16E000/code_804143D8.h"
#include "TYPES.H"
#include "shared/func_802453D4_de_closed.h"
#include "OVL_80400000/80414330.H"

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
extern f64 func_804147F0_eu_x(void);
#else
extern f64 func_804143B0_de(void);
#endif





extern Record_func_802A1990_de *func_8040EC30_de(s32 arg0, s32 arg1);

extern Record_func_802A1990_de *func_8025305C_de(s32);

extern void func_802A0748_de(s32, s32, s32);

extern void func_802A1B24_de(void *arg0, s32 arg1);

extern void func_8040EEA4_de(Record_func_802A1990_de *arg0, Record_func_802A1990_de *arg1);

extern void func_8040EF84_de(s32 arg0, Record_func_802A1990_de *arg1, Record_func_802A1990_de *arg2);

/** Store four arguments in the adjacent global state words. */
void func_802A1870_de(unsigned int a0, unsigned int a1, unsigned int a2, unsigned int a3) {
    extern unsigned int D_800CD99C;
    extern unsigned int D_800CD998;
    extern unsigned int D_800CD994;
    extern unsigned int D_800CD990_de;
    D_800CD990_de = a0;
    D_800CD994 = a1;
    D_800CD998 = a2;
    D_800CD99C = a3;
}

void func_802A1898_de(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    extern s32 D_800CD99C;
    extern s32 D_800CD998;
    extern s32 D_800CD994;
    extern s32 D_800CD990_de;
    *arg0 = D_800CD990_de;
    *arg1 = D_800CD994;
    *arg2 = D_800CD998;
    *arg3 = D_800CD99C;
}

f64 func_802A18CC_de(void) {
    return 
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
func_804147F0_eu_x
#else
func_804143B0_de
#endif
() - (0.0);
}

/** Perform no operation. */
void func_802A18F4_de(void) {
}

void func_802A18FC_de(void) { func_80418F8C_de(); }

/** Copy the global two-word record into the two output pointers. */
void func_802A1918_de(int *arg0, int *arg1) {
    *arg0 = D_800E28D0;
    *arg1 = D_800E28D4;
}

int func_802A1934_de(void) {
    return D_800D2C18;
}

/** Increment the global counter D_800D2C18. */
void func_802A1944_de(void) {
    D_800D2C18 += 1;
}

void func_802A1960_de(void) {
    func_802982C4_de(0xB65, D_002A1B50, D_002A1BE0, 3);
}

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

/** Return the word at offset 0x58 in the supplied object. */
int func_802A1B18_de(void *object) {
    Record_func_802A1990_de *record = object;
    return record->field_58;
}
