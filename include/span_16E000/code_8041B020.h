#ifndef UNBAKE_SPAN_16E000_CODE_8041B020_H
#define UNBAKE_SPAN_16E000_CODE_8041B020_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
struct OwnerRecAt8V1;
typedef struct OwnerRecAt8V1 OwnerRecAt8V1;

struct Node_func_8041B610_de;
typedef struct Node_func_8041B610_de Node_func_8041B610_de;

extern s32 func_8041B970_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Record_func_8041B22C_de;
struct Record_func_8041B22C_de {
    s32 words_00[3];
    s16 field_0C;
    u16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
};

struct Mixer;
typedef struct Mixer Mixer;

struct Context_func_8041B6E8_de;
typedef struct Context_func_8041B6E8_de Context_func_8041B6E8_de;

struct Node_func_8041B610_de;
struct OwnerRecAt44;
struct Node_func_8041B610_de {
    s32 words_00[3];
    s16 tag;
    s16 kind;
    s8 alpha; /* 0x10 */
    u8 reserved11;
    s16 flags;
    s32 words_14[12];
    struct OwnerRecAt44 *owner;
    s32 value;
    s32 words_4C[8];
    s32 field_6C;
};

struct OwnerRecAt44 {
    s32 words_00[2];
    struct Node_func_8041B610_de *root;
    s32 words_0C[14];
    struct Node_func_8041B610_de *overlay;
};

struct SlotsRecAt5CV2;
struct SlotsRecAt5CV2 {
    char pad0[0x48];
    s32 count;
    char pad4C[0x5C - 0x4C];
    s32 values[1];
};

struct ChildRecAt38;
struct ChildRecAt38 {
    char pad[0x12];
    u16 flags;
    char pad14[0x38 - 0x14];
    void *target;
};

struct ChildRecAt38;

extern void func_8041B110_de(s32 arg0);

struct SlotsRecAt5CV1;
struct SlotsRecAt5CV1 {
    char pad[0x5C];
    s32 values[1];
};

extern void func_8041B0E0_de();

struct Node_func_8041B6E8_de;
typedef struct Node_func_8041B6E8_de Node_func_8041B6E8_de;

struct Child;
struct Child {
    char pad[0x12];
    u16 flags;
    char pad14[0x34 - 0x14];
    void *target;
};

struct SlotsRecAt5CV2;
extern s32 func_8041B7C4_de(struct SlotsRecAt5CV2 *object);

struct OwnerRecAt44;
typedef struct OwnerRecAt44 OwnerRecAt44;

struct SlotsRecAt4C;
struct ObjRecAtCV1;
struct SlotsRecAt4C {
    char pad[0x4C];
    struct ObjRecAtCV1 *entries[1];
};

struct ChildRecAt2C;
struct ChildRecAt2C {
    char pad[0x12];
    u16 flags;
    char pad14[0x2C - 0x14];
    void *target;
};

struct Node_func_8041B6E8_de;
struct Node_func_8041B6E8_de {
    s32 words_00[3];
    s16 id;
};

struct Context_func_8041B6E8_de;
struct Context_func_8041B6E8_de {
    s32 words_00[17];
    void *root;
    s32 words_48;
    Node_func_8041B6E8_de *shown[4];
    s32 locked[4];
    s32 shared;
};

struct Context_func_8041B6E8_de;
struct OwnerRecAt8V1;
struct OwnerRecAt8V1 {
    s32 words_00[2];
    struct Context_func_8041B6E8_de *context;
};

struct Record_func_8041B110_de;
struct Record_func_8041B110_de {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
};

extern s32 func_8041B340_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct ChildRecAt2C;

struct Record_func_8041B110_de;
typedef struct Record_func_8041B110_de Record_func_8041B110_de;

extern void func_8041B5E0_de();

struct Mixer;
struct Mixer {
    char pad[0x4C];
    ObjRecAtCV1 *handlers[4];
    int muted[4];
};

extern void func_8041B828_de(Context_func_8041B6E8_de *context, s32 index, s32 id);

struct Record_func_8041B22C_de;
typedef struct Record_func_8041B22C_de Record_func_8041B22C_de;

struct Key;
struct MenuRecAt114;
struct OwnerRecAt38;
struct MenuRecAt114 {
    char pad0[0x44];
    struct OwnerRecAt38 *owner;
    struct Key entries[(0x110 - 0x48) / 20];
    s32 index;
    s32 count;
};

struct ChildRecAt30;
struct ChildRecAt30 {
    char pad[0x12];
    u16 flags;
    char pad14[0x30 - 0x14];
    void *target;
};

struct ChildRecAt30;

struct Child;

#endif
