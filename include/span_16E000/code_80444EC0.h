#ifndef UNBAKE_SPAN_16E000_CODE_80444EC0_H
#define UNBAKE_SPAN_16E000_CODE_80444EC0_H
#include "TYPES.H"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043F69C.h"
#include "common/types_8a8189af7b05.h"
extern void func_80444E70_de(s16 *record);

struct Options_func_80444D50_de;
struct Options_func_80444D50_de {
    s32 flags;
    s32 pad4[3];
    s32 value;
};

struct OptionEditState;
struct OptionEditState {
    char p[20];
    s32 *unk_14;
    char q[4];
    struct OptionEditState *unk_1C;
    s32 unk_20;
    char r[52];
    s32 unk_58;
    char a[1408];
    struct OptionEditState *unk_5DC;
};

struct OptionEditContext;
struct Shape_typemap_13;
struct OptionEditContext {
    char pad0[0x8];
    struct Shape_typemap_13 unk_8;
};

extern s32 func_80444EB4_de(void);

struct OptionEditContext;
typedef struct OptionEditContext OptionEditContext;

struct OptionEditState;
typedef struct OptionEditState OptionEditState;

extern s32 func_80444E7C_de(void);

extern int func_80444E30_de(void);

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_804451D0_de(struct LayeredText *field);
#endif


#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_80445ECC(struct LayeredText *field);
#endif


#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_80445AB8(struct LayeredText *field);
#endif

extern u8 *D_800D3D8C;
extern u8 *D_800D3D90;
extern u8 *D_800D3D94;
extern u8 *D_800E4084[];
extern u8 *D_800E4094[];
extern u8 *D_800E40A4[];
extern char D_800EEE10[];
extern char D_800EEE18[];
extern char D_800E27E0[];
extern char D_800E27E8[];

extern char *D_800D7DC8;
extern char *D_800D7DCC;
extern char *D_800D7DD0;

extern u8 *D_800D3DBC;
extern char D_800DE7B0_de[];

extern void func_8025E29C_de(s32);

extern u32 D_80142218;
extern u8 *D_800D3624;

extern u8 *D_800D7DD8;
extern u8 *D_800D3DB0;
extern u8 *D_800D3DB4;

s32 func_8026435C_de(Shared_Effect *);

#endif
