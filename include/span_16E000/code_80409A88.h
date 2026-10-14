#ifndef UNBAKE_SPAN_16E000_CODE_80409A88_H
#define UNBAKE_SPAN_16E000_CODE_80409A88_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
extern s32 func_8040A1B0_de(s32 arg0);

extern void func_8040A47C_de(void);

extern void func_8040A748_de(void);

extern void func_8040A764_de(void);

struct Target_func_8040A77C_de;
struct Target_func_8040A77C_de {
    char pad0[0xA8];
    s32 first;
    char padAC[0xD0 - 0xAC];
    s32 second;
};
struct RecordRecAtCV1;
struct Target_func_8040A77C_de;
struct RecordRecAtCV1 {
    char pad[0xC];
    struct Target_func_8040A77C_de *target;
};

struct RecordRecAtCV1;
extern void func_8040A77C_de(struct RecordRecAtCV1 *record);

struct Display_func_8040A4D4_de;
typedef struct Display_func_8040A4D4_de Display_func_8040A4D4_de;

extern void func_8040A490_de(void);

struct RecordRecAt20V2;
struct func_80242278_S1;
struct RecordRecAt20V2 {
    char pad[0x1C];
    s32 result;
    struct func_80242278_S1 *inner;
};

struct Display_func_8040A4D4_de;
struct Display_func_8040A4D4_de {
    char pad[0x90];
    unsigned int depth;
};

extern char *func_8040A038_de(int unused, int kind);

struct RecordRecAt24;
struct RecordRecAt24 {
    char pad[0x1C];
    s32 first;
    s32 second;
    void *resource;
};

struct RecordRecAt24;
extern s32 func_8040A6DC_de(void *unused, struct RecordRecAt24 *record);

struct OwnerRecAt5D8V1;
extern void func_80409A5C_de(struct OwnerRecAt5D8V1 *owner);

struct Record_func_80409BDC_de;
extern void func_80409F2C_de(struct Record_func_80409BDC_de *record);

struct RecordRecAt20V2;
extern s32 func_80409EF4_de(struct RecordRecAt20V2 *record, s32 *out);

struct Record_func_80409BDC_de;
extern char *func_8040A09C_de(struct Record_func_80409BDC_de *menu);


struct Item_func_80441FE8_de;
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8040A300_de(struct Item_func_80441FE8_de *field, struct Record_func_80409BDC_de *holder);
#endif

#endif
