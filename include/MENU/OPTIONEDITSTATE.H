#ifndef MENU_OPTIONEDITSTATE_H
#define MENU_OPTIONEDITSTATE_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/SHAREDPLAYER.H"

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


struct OptionEditContext;
typedef struct OptionEditContext OptionEditContext;

struct OptionEditState;
typedef struct OptionEditState OptionEditState;



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
extern char g_pakFormatSpacedInt2[];
extern char g_pakFormatSpacedInt3[];

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *D_800D7DC8[];
extern char *D_800D7DCC[];
extern char *D_800D7DD0[];
#else
extern char *D_800D7DC8;
extern char *D_800D7DCC;
extern char *D_800D7DD0;
#endif

extern u8 *D_800D3DBC;
extern char D_800DE7B0_de[];


extern u8 *D_800D3624;

extern u8 *D_800D7DD8;
extern u8 *D_800D3DB0;
extern u8 *D_800D3DB4;

s32 func_8026435C_de(Shared_Effect *);
#endif
