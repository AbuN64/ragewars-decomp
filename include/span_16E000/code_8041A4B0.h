#ifndef UNBAKE_SPAN_16E000_CODE_8041A4B0_H
#define UNBAKE_SPAN_16E000_CODE_8041A4B0_H
#include "types.h"
#include "common/types_1dc8418c21db.h"



extern void func_8041A520_de(void *target, const char *format, ...);

struct Key;
struct Menu_func_8041AD10_de;
struct OwnerRecAt38;
struct Menu_func_8041AD10_de {
    char pad0[0x44];
    struct OwnerRecAt38 *owner;
    struct Key entries[(0x110 - 0x48) / 20];
    s32 index;
};

extern s32 func_8041A724_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);




struct Key;
struct Menu_func_8041AD34_de;
struct Menu_func_8041AD34_de {
    char pad0[0x48];
    struct Key entries[(0x110 - 0x48) / 20];
    s32 index;
    s32 count;
};

struct Record_func_8041ABC0_de;
struct Record_func_8041ABC0_de {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
    struct Record_func_8041ABC0_de *field_44;
    s32 words_48[(0x110 - 0x48) / 4];
    s32 field_110;
    s32 field_114;
};

extern void func_8041AB90_de();

extern s32 func_8041AD7C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct ObjRecAt18V1;
struct Scroll;
struct Scroll {
    char pad[0x44];
    struct ObjRecAt18V1 *bar;
    s32 length;
    s32 count;
    s32 item;
};

struct Record_func_8041A580_de;
struct Record_func_8041A580_de {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
    struct Record_func_8041A580_de *field_44;
    s32 field_48;
    s32 field_4C;
    s32 field_50;
    s32 field_54;
};

struct Record_func_8041ABC0_de;
typedef struct Record_func_8041ABC0_de Record_func_8041ABC0_de;

extern void func_8041A550_de();

struct Scroll_func_8041A8E8_de;
struct Scroll_func_8041A8E8_de {
    char pad[0x48];
    s32 length;
    s32 count;
    s32 item;
};

struct Record_func_8041A580_de;
typedef struct Record_func_8041A580_de Record_func_8041A580_de;

extern s32 func_8041A490_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

#endif
